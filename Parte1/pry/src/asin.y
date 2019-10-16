/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          2019-2020 <migarbo1@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
%}

%token MAS_ INCR_ MASIG_ MENOS_ DECR_ MENIG_ EXCL_ POR_ PORIG_ DIV_ DIVIG_ RESTO_ IGU_
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ PUNTO_ PYC_
%token MENOR_ MAYOR_ MEIG_ MAIG_ IGUALC_ DIF_ AND_ OR_
%token INT_
%token ID_ CTE_ STRUCT_ BOOL_ READ_ PRINT_ IF_ ELSE_ WHILE_ TRUE_ FALSE_

%%
programa                    : ACOR_ secuenciaSentencias CCOR_
                            ;

secuenciaSentencias         : sentencia
                            | secuenciaSentencias sentencia
                            ;

sentencia                   : declaracion
                            | instruccion
                            ;

declaracion                 : tipoSimple ID_ PYC_
                            | tipoSimple ID_ IGU_ constante PYC_
                            | tipoSimple ID_ ALLAV_ CTE_ CLLAV_ PYC_
                            | STRUCT_ ACOR_ listaCampos CCOR_ ID_ PYC_
                            ;

/*****************************************************************************/

tipoSimple                  : INT_
                            | BOOL_
                            ;

listaCampos                 : tipoSimple ID_ PYC_
                            | listaCampos tipoSimple ID_ PYC_
                            ;

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
                            | TRUE_
                            | FALSE_
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
