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
%type <cent> tipoSimple constante operadorLogico operadorUnario
%type <exp> expresion expresionAditiva expresionIgualdad expresionLogica expresionMultiplicativa expresionRelaiconal expresionSufija expresionUnaria
  
%%
programa                    :  {dvar = 0; si = 0;}
                              ACOR_ secuenciaSentencias CCOR_
                                { if (verTDS) verTdS(); }
                                emite(FIN, crArgNul(),crArgNul(),crArgNul());
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
                                    yyerror("Variable ya definida");
                                  else 
                                    dvar += TALLA_TIPO_SIMPLE;
                                }desp

                            | tipoSimple ID_ IGU_ constante PYC_
                                {
                                  if( ! ($1 == $4))
                                    yyerror("No se pudo realizar la asignación, tipos incompatibles");
                                  else
                                    if( ! insTdS($2, $1, dvar, -1) )
                                      yyerror("Variable ya definida");
                                    else
                                      dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ ALLAV_ CTE_ CLLAV_ PYC_
                                {
                                  int numelem = $4;
                                  if ($4 <=0){
                                    yyerror("Talla inapropiada del array");
                                    numelem = 0;
                                  } else{
                                    int refe = insTdA($1,numelem);
                                    if( !insTdS($2, T_ARRAY, dvar, refe) ){
                                      yyerror("Identificador repetido");
                                    }
                                    else{ dvar += numelem * TALLA_TIPO_SIMPLE;}
                                  }
                                 }

                            | STRUCT_ ACOR_ listaCampos CCOR_ ID_ PYC_
                                {
                                  if(! insTdS($5, T_RECORD, $3.talla, $3.ref))
                                    yyerror("Identificador repetido");
                                  else
                                }
                            ;

/*********************************

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
                                { $$.ref=$1.ref; $$.talla=$1.talla;
                                  int ref = insTdR($1.ref, $3, $2, $1.talla);
                                  if (ref == -1)
                                    yyerror("Campo ya declarado");
                                  else{ 
                                    $$.talla = $1.talla + TALLA_TIPO_SIMPLE;
                                    $$.ref = ref;
                                  }
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
                            | listaInstrucciones instrucciondesp
                            ;
/*****************************************************************************/
instruccionesEntradaSalida  : READ_ APAR_ ID_ CPAR_ PYC_
                              { SIMB simb = obtTdS($3);
                                if(simb.tipo != T_ENTERO)
                                  yyerror("No se pueden leer valores no enteros");
                                emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.desp));
                              }
                            | PRINT_ APAR_ expresion CPAR_ PYC_
                              { if($3.tipo != T_ERROR)
                                  if ($3.tipo != T_ENTERO)
                                    yyerror("No se pueden imprimir valores de tipo no entero");
                                emite(EWRITE, crArgNul(), crArgNul(), crArgPos($3.desp));
                              }
                            ;

instruccionSeleccion        : IF_ APAR_ expresion CPAR_
                              { if($3.tipo != T_ERROR)
                                  if($3.tipo != T_LOGICO)
                                    yyerror("La condición debe ser de tipo lógico");
                                $<cent>$ = creaLans(si);
                                emite(EIGUAL, crArgPos($3.desp), crArgEnt(0), crArgEtq(-1));
                              }
                              instruccion 
                              {
                                $<cent>$ = creaLans(si);
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
                                completaLans($<cent>5, crArgEnt(si));
                              }
                              ELSE_ instruccion
                              {
                                completaLans($<cent>7, crArgEnt(si));
                              }
                            ;

instruccionIteracion        : WHILE_ 
                              {
                                $<cent>$ = si;
                              }
                              APAR_ expresion CPAR_ 
                                { if($3.tipo != T_ERROR)
                                    if($3.tipo != T_LOGICO)
                                      yyerror("La condición debe ser de tipo lógico");
                                  $<cent>$ = creaLans(si);
                                  emite(EIGUAL, crArgPos($3.desp), crArgEnt(0), crArgEtq(-1));
                                } 
                              instruccion
                              {
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>2));
                                completaLans($<cent>6, crArgEnt(si));
                              }
                            ;

instruccionExpresion        : expresion PYC_
                              {}
                            | PYC_
                              {}
                            ;

/*****************************************************************************/

expresion                   : expresionLogica
                              {
                                $$.tipo = $1.tipo; $$.desp = $1.desp;
                              }
                            | ID_ operadorAsignacion expresion
                              { if($3.tipo != T_ERROR){
                                  $$.tipo = T_ERROR;
                                  SIMB simb = obtTdS($1); 
                                  if(simb.tipo == T_ERROR) yyerror("Objeto no declarado");
                                  else{

                                    if ($3.tipo != T_ERROR){
                                      if (! ((simb.tipo  == T_ENTERO && $3.tipo == T_ENTERO) || 
                                                (simb.tipo  == T_LOGICO && $3.tipo == T_LOGICO))) 
                                          yyerror("Error de tipos en la 'instruccion de asignación'");
                                      else $$.tipo = simb.tipo;
                                    }
                                  }
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
                                          yyerror("Tipo incompatible con los tipos del array");
                                        else{
                                          $$.tipo = dim.telem; 
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
                                    yyerror("Identificador no declarado");
                                  else{
                                    if(simb.tipo != T_RECORD)
                                      yyerror("No se puede acceder a un campo de un no-registro");
                                    else{
                                      CAMP camp = obtTdR(simb.ref, $3);
                                      if(camp.tipo == T_ERROR)
                                        yyerror("Campo no definido");
                                      else{
                                        if(camp.tipo != $5.tipo)
                                          yyerror("Tipo de campo y de elemento incompatibles");
                                        else{
                                          $$.tipo = camp.tipo; 
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
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                                  if($1.tipo != T_LOGICO || $3.tipo != T_LOGICO){
                                    yyerror("Ambos operadores deben ser de tipo logico");
                                  }
                                  else{
                                    $$.tipo = T_LOGICO;
                                  }
                                }
                              }
                            ;

expresionIgualdad           : expresionRelaiconal
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionIgualdad operadorIgualdad expresionRelaiconal
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                                  if(!(($1.tipo == T_LOGICO && $3.tipo == T_LOGICO)||($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))){
                                    yyerror("Ambos operadores deben ser del mismo tipo");
                                  }
                                  else{
                                    $$.tipo = T_LOGICO;
                                  }
                                }
                              }
                            ;

expresionRelaiconal         : expresionAditiva
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionRelaiconal operadorRelacional expresionAditiva
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    $$.tipo = T_LOGICO;
                                  }
                                }
                              }
                            ;

expresionAditiva            : expresionMultiplicativa
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionAditiva operadorAditivo expresionMultiplicativa
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO){
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    $$.tipo = $1.tipo;
                                    $$.desp = creaVarTemp();
                                    emite($2,crArgPos($1.desp),crArgPos($3.desp),crArgPos($$.desp));
                                  }
                                }
                              }
                            ;

expresionMultiplicativa     : expresionUnaria
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                              { $$.tipo = T_ERROR;
                                if($1.tipo != T_ERROR && $3.tipo != T_ERROR){
                                  if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO){
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    $$.tipo = $1.tipo;
                                  }
                                }
                              }
                            ;

expresionUnaria             : expresionSufija
                              {
                                $$.desp = $1.desp;
                                $$.tipo = $1.tipo;
                              }
                            | operadorUnario expresionUnaria
                              { $$.tipo = T_ERROR;
                                if ($2.tipo != T_ERROR){
                                  if($1 == NOT && $2.tipo == T_ENTERO){
                                    yyerror("Error de tipos en la aplicación del NOT");
                                  }
                                  else{
                                    $$.tipo = $2.tipo;
                                  }
                                }
                              }
                            | operadorIncremento ID_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($2);
                                if(simb.tipo == T_ERROR)
                                  yyerror("Variable no definida");
                                else {
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("No se puede realizar una operación incremental sobre un no entero");
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
                                  yyerror("Variable no definida");
                                else
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("No se puede incrementar una variable no entera");
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
                                      emite(EMULT, crArgEnt($3.desp), crArgEnt(TALLA_TIPO_SIMPLE,crArgPos($3.desp)));
                                      $3.desp = creaVarTemp();
                                      emite(EAV, crArgPos(simb.desp), crArgEnt($3.desp),crArgPos($$.desp));
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
                                  $$.desp = creaVarTemp();
                                  emite(EASIG, crArgPos(simb.desp), crArgNul(), crArgPos($$.desp));
                              }
                            | ID_ PUNTO_ ID_
                              { $$.tipo = T_ERROR;
                                SIMB simb = obtTdS($1);
                                if(simb.tipo == T_ERROR)
                                  yyerror("Identificador no declarado");
                                else{
                                  if(simb.tipo != T_RECORD)
                                    yyerror("No se puede acceder a un campo de un no-registro");
                                  else{
                                    CAMP camp = obtTdR(simb.ref, $3);
                                    if(camp.tipo == T_ERROR)
                                      yyerror("Campo no definido");
                                    else{
                                      $$.tipo = camp.tipo;
                                      int desp = simb.desp + camp.desp;
                                      $$.desp = creaVarTemp();
                                      emite(EASIG, crArgEnt(desp), crArgNul(), crArgPos($$.desp));
                                    }
                                  }
                                }
                              }
                            | constante
                              {
                                $$.tipo = $1;
                                $$.desp = creaVarTemp();
                                emite(EASIG, crArgPos($1), crArgNul(), crArgPos($$.desp));
                              }
                            ;

/*****************************************************************************/

constante                   : CTE_
                                {
                                  $$ = T_ENTERO;
                                  $$.desp = creaVarTemp();
                                  emite(EASIG, crArgEnt($1), crArgNul(), crArgPos($$.desp));
                                }

                            | TRUE_
                                {
                                  $$ = T_LOGICO;
                                  $$.desp = creaVarTemp();
                                  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.desp));
                                }

                            | FALSE_
                                {
                                  $$ = T_LOGICO;
                                  $$.desp = creaVarTemp();
                                  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.desp));
                                }
                            ;

/*****************************************************************************/

operadorAsignacion          : IGU_
                              {
                                $$ = EASIG;
                              }
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
                              {
                                $$ = EIGUAL;
                              }
                            | DIF_
                              {
                                $$ = EDIF;
                              }
                            ;

operadorRelacional          : MAYOR_ 
                              {
                                $$ = EMAY;
                              }
                            | MENOR_
                              {
                                $$ = EMEN;
                              }
                            | MAIG_
                              {
                                $$ = EMAYEQ;
                              }
                            | MEIG_
                              {
                                $$ = EMENEQ
                              }
                            ;

operadorAditivo             : MAS_
                              {
                                $$ = ESUM;
                              }
                            | MENOS_
                              {
                                $$ = EDIF;
                              }
                            ;

operadorMultiplicativo      : POR_
                              {
                                $$ = EMULT;
                              }
                            | DIV_
                              {
                                $$ = EDIVI;
                              }
                            | RESTO_
                              {
                                $$ = RESTO;
                              }
                            ;

operadorUnario              : MAS_ 
                              {
                                $$ = ESUM;
                              }
                            | MENOS_ 
                              {
                                $$ = EDIF;
                              }
                            | EXCL_
                              {
                                $$ = NOT;
                              }
                            ;

operadorIncremento          : INCR_
                            | DECR_
                            ;

%%
