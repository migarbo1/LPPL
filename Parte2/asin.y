/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          2019-2020 <migarbo1@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
%}

%union{
    int cent;
    char *ident;

    /*typedef struct{
      int valor;
      char *ident;
    }Aid*/
}

%token INCR_ MASIG_  DECR_ MENIG_  PORIG_  DIVIG_ IGU_
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ PUNTO_ PYC_
%left AND_ OR_ EXCL_ MENOR_ MAYOR_ MEIG_ MAIG_ IGUALC_ DIF_
%left MAS_ MENOS_
%left POR_ DIV_ RESTO_
%token <cent> INT_
%token <ident> ID_ /*Aid*/
%token CTE_ STRUCT_ BOOL_ READ_ PRINT_ IF_ ELSE_ WHILE_ TRUE_ FALSE_

%type<cent> constante
%type <Acampos> listaCampos
%%
programa                    : { dvar=0; }
                              ACOR_ secuenciaSentencias CCOR_
                              { if (verTDS)  verTdS(); }
                            ;

secuenciaSentencias         : sentencia
                                
                            | secuenciaSentencias sentencia
                                
                            ;

sentencia                   : declaracion
                                {
                                  if(insTdS($1.ident, $1.tipo, $1.talla, $1.ref))
                                  {
                                    dvar += $1.talla;
                                  }
                                  else 
                                  {
                                    yyerror("Error en declaracion");
                                  }
                                }
                            | instruccion
                                
                            ;

declaracion                 : tipoSimple ID_ PYC_
                                {  if (insTdS($2, $1, dvar, -1)) {}
                                  /*if*/
                                  dvar+=TALLA_TIPO_SIMPLE;
                                  
                                }

                            | tipoSimple ID_ IGU_ constante PYC_
                                {
                                  if( ! $1.tipo == $4.tipo){
                                    yyerror("No se pudo realizar la asignacion : Tipos incompatibles");
                                  }
                                  $$.tipo = $1;
                                  $$.ident = $2; /*.ident*/
                                  $$.talla = TALLA_TIPO_SIMPLE;
                                  $$.ref = -1;
                                  /*$2.valor = constante.valor;*/
                                }

                            | tipoSimple ID_ ALLAV_ CTE_ CLLAV_ PYC_
                                {
                                  int numelem = $4;
                                  if ($4 <=0){
                                    yyerror("Talla inapropiada del array");
                                    numelem = 0;
                                  }
                                  int refe = insTdA($1,numelem);
                                  if( !insTdS($2, T_ARRAY, dvar, refe) ){ /*$2.ident*/
                                    yyerror("identificador repetido");
                                  }
                                  else dvar += numelem * TALLA_TIPO_SIMPLE;
                                  $$.ident = $2; /*.ident*/
                                  $$.tipo = T_ARRAY;
                                  $$.talla = dvar;
                                  $$.ref = refe;
                                 }

                            | STRUCT_ ACOR_ listaCampos CCOR_ ID_ PYC_
                                {
                                  $$.tipo = T_RECORD;
                                  $$.talla = $3.talla;
                                  $$.ident = $5; /*.ident*/
                                  $$.ref = $3.ref;
                                { 
                                  
                                  int ncamp = listaCampos.talla /* no se como hacer esto, pero se que es +- asi*/
                                  int refe = insTdR(-1, $5, T_RECORD, dvar);
                                  if (refe == -1){
                                    yyerror("repetición de un campo en el registro");
                                  }
                                  else
                                    if( !insTdS($5, T_RECORD, dvar, refe) ){
                                      yyerror("identificador repetido");
                                    }
                                    else dvar += ncamp * TALLA_TIPO_SIMPLE;
                                }
                            ;

/*****************************************************************************/

tipoSimple                  : INT_
                                {
                                  $$ = T_ENTERO;
                                }
                            | BOOL_
                                {
                                  $$ = T_LOGICO;
                                }
                            
              
                            ;

listaCampos                 : tipoSimple ID_ PYC_
                                {
                                  $$.ref = insTdR(-1, $2, $1, 0); /*ident*/
                                  $$.talla = TALLA_TIPO_SIMPLE;
                                }

                            | listaCampos tipoSimple ID_ PYC_
                                {
                                  $$.ref = insTdR($1.ref, $3, $2, $1.talla); /*$3.ident*/
                                  $$.talla = $1.talla + TALLA_TIPO_SIMPLE;
                                }

/*****************************************************************************/

instruccion                 : ACOR_ CCOR_
                            | ACOR_ listaInstrucciones CCOR_
                            | instruccionesEntradaSalida
                            | instruccionSeleccion
                            | instruccionIteracion
                            | instruccionExpresion
                            ;

listaInstrucciones          : instruccion
                            | listaInstrucciones instruccion
                            ;

instruccionesEntradaSalida  : READ_ APAR_ ID_ CPAR_ PYC_
                              {
                                /*SIMB var = obtTdS($3.ident);
                                if(var.tipo == T_ERROR) yyerror("Variable no declarada");
                                  
                                if(var.tipo != T_ENTERO || var.tipo != T_LOGICO) 
                                    yyerror("Tipo de variable incompatible");*/
                              }
                            | PRINT_ APAR_ expresion CPAR_ PYC_
                            ;

instruccionSeleccion        : IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion
                            ;

instruccionIteracion        : WHILE_ APAR_ expresion CPAR_ instruccion
                            ;

instruccionExpresion        : expresion PYC_
                            | PYC_
                            ;

/*****************************************************************************/

expresion                   : expresionLogica
                            | ID_ operadorAsignacion expresion
                              /*{ $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1); /*ident*/
                                if(sim.tipo == T_ERROR) yyerror("Objeto no declarado");
                                else if (! ((sim.tipo == $3 == T_ENTERO) ||
                                            (sim.tipo == $3 == T_LOGICO)))
                                      yyerror("Error de tipos en la 'instruccion de asignación'");
                                else $$.tipo = sim.tipo;
                              }*/

                            | ID_ ALLAV_ expresion CLLAV_ operadorAsignacion expresion
                            | ID_ PUNTO_ ID_ operadorAsignacion expresion
                            ;

expresionLogica             : expresionIgualdad
                            | expresionLogica operadorLogico expresionIgualdad
                            ;

expresionIgualdad           : expresionRelaiconal
                            | expresionIgualdad operadorIgualdad expresionRelaiconal
                            ;

expresionRelaiconal         : expresionAditiva
                            | expresionRelaiconal operadorRelacional expresionAditiva
                            ;

expresionAditiva            : expresionMultiplicativa
                            | expresionAditiva operadorAditivo expresionMultiplicativa
                            ;

expresionMultiplicativa     : expresionUnaria
                            | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                            ;

expresionUnaria             : expresionSufija
                            | operadorUnario expresionUnaria
                            | operadorIncremento ID_
                            ;

expresionSufija             : APAR_ expresion CPAR_
                            | ID_ operadorIncremento
                            | ID_ ALLAV_ expresion CLLAV_
                            | ID_
                            | ID_ PUNTO_ ID_
                            | constante
                            ;

/*****************************************************************************/

constante                   : CTE_
                                {
                                  $$.tipo = T_ENTERO;
                                }

                            | TRUE_
                                {
                                  $$.tipo = T_LOGICO;
                                }

                            | FALSE_
                                {
                                  $$.tipo = T_LOGICO;
                                }
                            ;

/*****************************************************************************/

operadorAsignacion          : IGU_
                            | MASIG_
                            | MENIG_
                            | PORIG_
                            | DIVIG_
                            ;

operadorLogico              : AND_
                            | OR_
                            ;

operadorIgualdad            : IGUALC_
                            | DIF_
                            ;

operadorRelacional          : MAYOR_
                            | MENOR_
                            | MAIG_
                            | MEIG_
                            ;

operadorAditivo             : MAS_
                            | MENOS_
                            ;

operadorMultiplicativo      : POR_
                            | DIV_
                            |RESTO_
                            ;

operadorUnario              : MAS_
                            | MENOS_
                            | EXCL_
                            ;

operadorIncremento          : INCR_
                            | DECR_
                            ;

%%
