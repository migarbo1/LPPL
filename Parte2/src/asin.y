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
%type <exp> expresion expresionAditiva expresionIgualdad expresionLogica expresionMultiplicativa expresionRelaiconal expresionSufija expresionUnaria
%type <cent> operadorLogico operadorUnario

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
                                  if( !insTdS($2, $1, dvar, -1) )
                                    yyerror("variable ya definida");
                                  else 
                                    dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ IGU_ constante PYC_
                                {
                                  if( ! $1 == $4)
                                    yyerror("No se pudo realizar la asignación tipos incompatibles");
                                  else
                                    if( ! insTdS($2, $1, dvar, -1) )
                                      yyerror("variable ya definida");
                                    else
                                      dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ ALLAV_ CTE_ CLLAV_ PYC_
                                {
                                  int numelem = $4;
                                  if ($4 <=0)
                                    yyerror("Talla inapropiada del array");
                                    numelem = 0;
                                  int refe = insTdA($1,numelem);
                                  if( !insTdS($2, T_ARRAY, dvar, refe) )
                                    yyerror("identificador repetido");
                                  
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
                                  int ref = insTdR($1.ref, $3, $2, $1.talla);
                                  if (ref == -1)
                                    yyerror("campo ya declarado");
                                  else 
                                    $$.talla = $1.talla + TALLA_TIPO_SIMPLE;
                                    $$.ref = ref;
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
/*****************************************************************************/
instruccionesEntradaSalida  : READ_ APAR_ ID_ CPAR_ PYC_
                              { SIMB simb = obtTdS($3);
                                if(simb.tipo != T_ENTERO)
                                  yyerror("no se pueden leer valores no enteros");
                              }
                            | PRINT_ APAR_ expresion CPAR_ PYC_
                              { if($3.tipo != T_ERROR)
                                  if ($3.tipo != T_ENTERO)
                                    yyerror("no se pueden imprimir valores de tipo no entero");
                              }
                            ;

instruccionSeleccion        : IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion
                              { if($3.tipo != T_ERROR)
                                  if($3.tipo != T_LOGICO)
                                    yyerror("la condición debe ser de tipo lógico");
                              }
                            ;

instruccionIteracion        : WHILE_ APAR_ expresion CPAR_ 
                                { if($3.tipo != T_ERROR)
                                  if($3.tipo != T_LOGICO)
                                    yyerror("la condición debe ser de tipo lógico");
                                } 
                              instruccion
                            ;

instruccionExpresion        : expresion PYC_
                              {
                                /* ¿$$.tipo $$.desp?*/
                              }
                            | PYC_
                              { /* ¿$$.tipo = T_VACIO?*/ }
                            ;

/*****************************************************************************/

/* tiene expresion desplazamiento?*/
expresion                   : expresionLogica
                              {
                                $$.tipo = $1.tipo; $$.desp = $1.desp;
                              }
                            | ID_ operadorAsignacion expresion
                              { if($3.tipo != T_ERROR){
                                  $$.tipo = T_ERROR;
                                  SIMB simb = obtTdS($1); 
                                  if(simb.tipo == T_ERROR) yyerror("Objeto no declarado");
                                  else
                                    if (! ((simb.tipo == $3.tipo == T_ENTERO) || /* si no tiene desplazamiento, $3 solo*/
                                              (simb.tipo == $3.tipo == T_LOGICO)))  /* si no tiene desplazamiento, $3 solo*/
                                        yyerror("Error de tipos en la 'instruccion de asignación'");
                                    else $$.tipo = simb.tipo;
                                }
                              }

                            | ID_ ALLAV_ expresion CLLAV_ operadorAsignacion expresion
                              { if ($6.tipo != T_ERROR){
                                  $$.tipo = T_ERROR;
                                  SIMB simb = obtTdS($1);
                                  if (simb.tipo == T_ERROR) yyerror("Array no declarado");
                                  else{
                                    if (simb.tipo != T_ARRAY) yyerror("La variable a la que se intentó acceder no es un array");
                                    else{
                                      if($3.tipo != T_ENTERO) yyerror("Tipo incorrecto de indice de Array");
                                      else{
                                        DIM dim = obtTdA(simb.ref);
                                        if (dim.telem != $6.tipo)
                                          yyerror("tipo incompatible con los tipos del array");
                                        else{
                                          $$.tipo = dim.telem; /* o simb.tipo, duda*/
                                          /* ¿desplazamiento? $$.desp = simb.desp*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            | ID_ PUNTO_ ID_ operadorAsignacion expresion
                              { if($5.tipo != T_ERROR){
                                  $$.tipo = T_ERROR;
                                  SIMB simb = obtTdS($1);
                                  if(simb.tipo == T_ERROR)
                                    yyerror("identificador no declarado");
                                  else{
                                    if(simb.tipo != T_RECORD)
                                      yyerror("no se puede acceder a un campo de un no-registro");
                                    else{
                                      CAMP camp = obtTdR(simb.ref, $3);
                                      if(camp.tipo == T_ERROR)
                                        yyerror("campo no definido");
                                      else{
                                        if(camp.tipo != $5.tipo)
                                          yyerror("tipo de campo y de elemento incompatibles");
                                        else{
                                          $$.tipo = camp.tipo; /* o simb.tipo, duda*/
                                          /* $$.desp = camp.desp*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            ;

expresionLogica             : expresionIgualdad
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionLogica operadorLogico expresionIgualdad
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR)
                                  if($1.tipo != T_LOGICO || $3.tipo != T_LOGICO)
                                    yyerror("ambos operadores deben ser de tipo logico");
                                  else
                                    $$.tipo = T_LOGICO;
                              }
                            ;

expresionIgualdad           : expresionRelaiconal
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionIgualdad operadorIgualdad expresionRelaiconal
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR)
                                  if(!(($1.tipo == T_LOGICO && $3.tipo == T_LOGICO)||($1.tipo == T_ENTERO && $3.tipo == T_ENTERO)))
                                    yyerror("ambos operadores deben ser del mismo tipo");
                                  else
                                    $$.tipo = T_LOGICO;
                              }
                            ;

expresionRelaiconal         : expresionAditiva
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionRelaiconal operadorRelacional expresionAditiva
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR)
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) /* ¿tener en cuenta los booleanos? */
                                    yyerror("ambos operadores deben ser de tipo entero");
                                  else
                                    $$.tipo = T_LOGICO;
                              }
                            ;

expresionAditiva            : expresionMultiplicativa
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionAditiva operadorAditivo expresionMultiplicativa
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR)
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO)
                                    yyerror("ambos operadores deben ser de tipo entero");
                                  else
                                    $$.tipo = $1.tipo;
                              }
                            ;

expresionMultiplicativa     : expresionUnaria
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR)
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO)
                                    yyerror("ambos operadores deben ser de tipo entero");
                                  else
                                    $$.tipo = $1.tipo;
                              }
                            ;

expresionUnaria             : expresionSufija
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | operadorUnario expresionUnaria
                              { $$.tipo = T_ERROR;
                                if ($2.tipo != T_ERROR)
                                  if($1 == NOT && $2.tipo == T_ENTERO)
                                    yyerror("error de tipos en la aplicación del NOT");
                                  else
                                    $$.tipo = $2.tipo;

                              }
                            | operadorIncremento ID_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($2);
                                if(simb.tipo == T_ERROR)
                                  yyerror("variable no definida");
                                else {
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("no se puede realizar una operación incremental sobre un no entero");
                                  else {
                                    $$.tipo = simb.tipo;
                                  }
                                }
                              }
                            ;

expresionSufija             : APAR_ expresion CPAR_
                              {
                                $$.tipo = $2.tipo; $$.desp = $2.desp;
                              }
                            | ID_ operadorIncremento
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($1);
                                if(simb.tipo == T_ERROR)
                                  yyerror("variable no definida");
                                else
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("no se puede incrementar una variable no entera");
                                  else
                                    $$.tipo = simb.tipo;

                              }
                            | ID_ ALLAV_ expresion CLLAV_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($1);
                                if (simb.tipo == T_ERROR) yyerror("Array no declarado");
                                else{
                                  if (simb.tipo != T_ARRAY) yyerror("La variable a la que se intentó acceder no es un array");
                                  else{
                                    if($3.tipo != T_ENTERO) yyerror("Tipo incorrecto de indice de Array");
                                    else{
                                      DIM dim = obtTdA(simb.ref);
                                      $$.tipo = dim.telem;
                                      /* $$.desp = simb.desp; */
                                    }
                                  }
                                }
                              }
                            | ID_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($1);
                                if (simb.tipo == T_ERROR) yyerror("Variable no declarada");
                                else
                                  $$.tipo = simb.tipo;
                                  /* $$.desp = simb.desp; */
                              }
                            | ID_ PUNTO_ ID_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($1);
                                if(simb.tipo == T_ERROR)
                                  yyerror("identificador no declarado");
                                else{
                                  if(simb.tipo != T_RECORD)
                                    yyerror("no se puede acceder a un campo de un no-registro");
                                  else{
                                    CAMP camp = obtTdR(simb.ref, $3);
                                    if(camp.tipo == T_ERROR)
                                      yyerror("campo no definido");
                                    else{
                                      $$.tipo = camp.tipo;
                                      /* $$.desp = camp.desp*/
                                    }
                                  }
                                }
                              }
                            | constante
                              {
                                $$.tipo = $1;
                                /* ¿$$.desp = TALLA_TIPO_SIMPLE?*/
                              }
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
                              {
                                $$ = AND;
                              }
                            | OR_
                              {
                                $$ = OR;
                              }
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
                            | RESTO_
                            ;

operadorUnario              : MAS_
                            | MENOS_
                            | EXCL_
                              {
                                $$ = NOT;
                              }
                            ;

operadorIncremento          : INCR_
                            | DECR_
                            ;

%%
