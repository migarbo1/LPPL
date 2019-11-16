/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          2019-2020 <migarbo1@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "libtds.h"
#include "header.h"

%}

%union{
    int cent;
    char *ident;
    EXP exp;
    REGISTRO registro;
}

%token INCR_ MASIG_  DECR_ MENIG_  PORIG_  DIVIG_ IGU_
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ PUNTO_ PYC_
%left AND_ OR_ EXCL_ MENOR_ MAYOR_ MEIG_ MAIG_ IGUALC_ DIF_
%left MAS_ MENOS_
%left POR_ DIV_ RESTO_
%token <cent>  CTE_
%token <ident> ID_
%token INT_ STRUCT_ BOOL_ READ_ PRINT_ IF_ ELSE_ WHILE_ TRUE_ FALSE_

%type <registro> listaCampos
%type <cent> tipoSimple constante

%%
programa                    :  {dvar = 0;}
                              ACOR_ secuenciaSentencias CCOR_
                                { if (verTDS) verTdS(); }
                            ;

secuenciaSentencias         : sentencia
                                {  }
                            | secuenciaSentencias sentencia
                                {  }
                            ;

sentencia                   : declaracion
                                {  }
                            | instruccion
                                {  }
                            ;

declaracion                 : tipoSimple ID_ PYC_
                                {
                                  if( ! insTdS($2, $1, dvar, -1) )
                                    yyerror("variable ya definida");
                                  else 
                                    dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ IGU_ constante PYC_
                                {
                                  if( ! $1 == $4){
                                    yyerror("No se pudo realizar la asignación tipos incompatibles");
                                  }
                                  if( ! insTdS($2, $1, dvar, -1) )
                                    yyerror("variable ya definida");
                                  else
                                    dvar += TALLA_TIPO_SIMPLE;
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
                                 }

                            | STRUCT_ ACOR_ listaCampos CCOR_ ID_ PYC_
                                {
                                  if(! insTdS($5, T_RECORD, $3.talla, $3.ref))
                                    yyerror("identificador repetido");
                                  else
                                    dvar += $3.talla;
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
                                  $$.ref = insTdR(-1, $2, $1, 0);
                                  $$.talla = TALLA_TIPO_SIMPLE;
                                }

                            | listaCampos tipoSimple ID_ PYC_
                                {
                                  $$.ref = insTdR($1.ref, $3, $2, $1.talla);
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
                              { $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1); 
                                if(sim.tipo == T_ERROR) yyerror("Objeto no declarado");
                                else if (! ((sim.tipo == $3 == T_ENTERO) ||
                                            (sim.tipo == $3 == T_LOGICO)))
                                      yyerror("Error de tipos en la 'instruccion de asignación'");
                                else $$.tipo = sim.tipo;
                                /*¿desplazamiento?*/
                              }

                            | ID_ ALLAV_ expresion CLLAV_ operadorAsignacion expresion
                              { SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) yyerror("Array no declarado");
                                else
                                  if (sim.tipo != T_ARRAY) yyerror("La variable a la que se intentó acceder no es un array");
                                  else
                                    if($3.tipo != T_ENTERO) yyerror("Tipo incorrecto de indice de Array");
                                    else
                                      DIM dim = obtTdA(sim.ref);
                                      if (dim.telem != $5.tipo)
                                        yyerror("tipo incompatible con los tipos del array");
                                      else
                                        $$.tipo = sim.tipo;
                                        /*¿desplazamiento?*/
                              }
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
                                  $$ = T_ENTERO;
                                }

                            | TRUE_
                                {
                                  $$ = T_LOGICO;
                                }

                            | FALSE_
                                {
                                  $$ = T_LOGICO;
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
