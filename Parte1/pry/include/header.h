#ifndef _HEADER_H
#define _HEADER_H

/*constantes generales*/
#define TRUE 1
#define FALSE 0

/*variables externas definidas en el AL*/
extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */

/*funciones y variables externas definidas en el Programa principal*/
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */

#endif  /* _HEADER_H */
