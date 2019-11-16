/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCR_ = 258,
    MASIG_ = 259,
    DECR_ = 260,
    MENIG_ = 261,
    PORIG_ = 262,
    DIVIG_ = 263,
    IGU_ = 264,
    APAR_ = 265,
    CPAR_ = 266,
    ACOR_ = 267,
    CCOR_ = 268,
    ALLAV_ = 269,
    CLLAV_ = 270,
    PUNTO_ = 271,
    PYC_ = 272,
    AND_ = 273,
    OR_ = 274,
    EXCL_ = 275,
    MENOR_ = 276,
    MAYOR_ = 277,
    MEIG_ = 278,
    MAIG_ = 279,
    IGUALC_ = 280,
    DIF_ = 281,
    MAS_ = 282,
    MENOS_ = 283,
    POR_ = 284,
    DIV_ = 285,
    RESTO_ = 286,
    CTE_ = 287,
    ID_ = 288,
    INT_ = 289,
    STRUCT_ = 290,
    BOOL_ = 291,
    READ_ = 292,
    PRINT_ = 293,
    IF_ = 294,
    ELSE_ = 295,
    WHILE_ = 296,
    TRUE_ = 297,
    FALSE_ = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "src/asin.y" /* yacc.c:1909  */

    int cent;
    char *ident;
    EXP exp;
    REGISTRO registro;

#line 105 "asin.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
