/*****************************************************************************/
/**  analizador lexico                      2019-2020 <migarbo1@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad) ECHO; return (x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput
%option nounput
%option yylineno

delimitador    [ \t\n]+
digito         [0-9]
entero         {digito}+
flotante       {entero}*[.]{entero}+|{entero}+[.]{entero}*
letra          [a-zA-Z]
variable       {letra}({letra}|{digito}|[_])*
comentario     \/\/.*$

%%
{delimitador}   { if (verbosidad) ECHO; }
{comentario}	  { if (verbosidad) ECHO; } /*preguntar*/
"."             { retornar (PUNTO_);    }
"+"	            { retornar (MAS_);      }
"++"	        	{ retornar (INCR_);     }
"+="            { retornar (MASIG_);    }
"-"             { retornar (MENOS_);    }
"--"	          { retornar (DECR_);     }
"-="            { retornar (MENIG_);    }
"!"		          { retornar (EXCL_);     }
"*"             { retornar (POR_);      }
"*="            { retornar (PORIG_);    }
"/"             { retornar (DIV_);      }
"/="            { retornar (DIVIG_);    }
"%"		          { retornar (RESTO_);    }
"("             { retornar (APAR_);     }
")"             { retornar (CPAR_);     }
"{"             { retornar (ACOR_);     }
"}"             { retornar (CCOR_);     }
";"             { retornar (PYC_);      }
"["             { retornar (ALLAV_);    }
"]"             { retornar (CLLAV_);    }
"<"		          { retornar (MENOR_);    }
">"		          { retornar (MAYOR_);    }
"<="		        { retornar (MEIG_);     }
">="		        { retornar (MAIG_);     }
"="             { retornar (IGU_);      }
"=="		        { retornar (IGUALC_);   }
"!="		        { retornar (DIF_);      }
"&&"		        { retornar (AND_);      }
"||"		        { retornar (OR_);       }
{entero}        { yylval.cent = atoi(yytext); retornar (CTE_);      }
{flotante}	    { yylval.cent = atoi(yytext); retornar (CTE_);      } /* aunque aceptas enteros y flotantes los tratas todos como enteros. hay que hacer la diferenciacion y truncarlos */
struct	        { retornar (STRUCT_);   }
int		          { retornar (INT_);      }
bool		        { retornar (BOOL_);     }
read		        { retornar (READ_);     }
print		        { retornar (PRINT_);    }
if  	          { retornar (IF_);       }
else		        { retornar (ELSE_);     }
while		        { retornar (WHILE_);    }
true		        { retornar (TRUE_);     }
false		        { retornar (FALSE_);    }
{variable}		  { yyval.ident = strdup(yytext);retornar (ID_);       }
.	       { yyerror("Caracter desconocido"); }

%%
