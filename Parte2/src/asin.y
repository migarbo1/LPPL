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
}

%token MAS_ INCR_ MASIG_ MENOS_ DECR_ MENIG_ EXCL_ POR_ PORIG_ DIV_ DIVIG_ RESTO_ IGU_
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ PUNTO_ PYC_
%token MENOR_ MAYOR_ MEIG_ MAIG_ IGUALC_ DIF_ AND_ OR_
%token <cent> INT_
%token ID_ CTE_ STRUCT_ BOOL_ READ_ PRINT_ IF_ ELSE_ WHILE_ TRUE_ FALSE_

%%
programa                    : ACOR_ secuenciaSentencias CCOR_
                                { $$ = $1; }
                            ;

secuenciaSentencias         : sentencia
                                { $$ = $1; }
                            | secuenciaSentencias sentencia
                                {  }
                            ;

sentencia                   : declaracion
                                {  }
                            | instruccion
                                {  }
                            ;

declaracion                 : tipoSimple ID_ PYC_
                                { if( !insTdS($2, $1, dvar, refe) ){
                                  yyerror("identificador repetido");
                                 }
                                 else dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ IGU_ constante PYC_
                                { if( !(insTdS($2, $1,dvar, -1))) {
                                    yyerror("identificador repetido");
                                  }
                                  else if ($4.tipo == $1){
                                    yyerror("error de asignación de tipos");
                                  }
                                  else dvar += TALLA_TIPO_SIMPLE;
                                }

                            | tipoSimple ID_ ALLAV_ CTE_ CLLAV_ PYC_
                                { int numelem = $4;
                                  if ($4 <=0){
                                    yyerror("Talla inapropiada del array");
                                    numelem = 0;
                                  }
                                  int refe = insTdA($1,numelem);
                                  if( !insTdS($2, T_ARRAY, dvar, refe) ){
                                    yyerror("identificador repetido");
                                  }
                                  else dvar += numelem * TALLA_TIPO_SIMPLE;
                                 }

                            | STRUCT_ ACOR_ listaCampos CCOR_ ID_ PYC_
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
                                { $$ = T_ENTERO; }
                            | BOOL_
                            
                                { $$ = T_LOGICO; }
                            ;

listaCampos                 : tipoSimple ID_ PYC_
                                /*{ $$.tipo = $1.tipo (*) $1.ident;  }*/
                                {$$.tipo = T_ERROR;
                                 obtTdS($2.ident)
                                 if($2.tipo == T_ERROR){ $$.tipo = $1.tipo (*) $1.ident; }
                                }
                            | listaCampos tipoSimple ID_ PYC_
                                {  }


instruccion                 : ACOR_ CCOR_
                            | ACOR_ listaInstrucciones CCOR_
                            | instruccionesEntradaSalida
                            | instruccionSeleccion
                            | instruccionIteracion
                            | instruccionExpresion
                            ;

/*****************************************************************************/

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
                              }

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
                                { $$ = $1;
                                  $$.tipo = T_ENTERO;
                                }
                            | TRUE_
                                { $$ = 1;
                                  $$.tipo = T_LOGICO;
                                }
                            | FALSE_
                                { $$ = 0;
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
