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
    MAS_ = 258,
    INCR_ = 259,
    MASIG_ = 260,
    MENOS_ = 261,
    DECR_ = 262,
    MENIG_ = 263,
    EXCL_ = 264,
    POR_ = 265,
    PORIG_ = 266,
    DIV_ = 267,
    DIVIG_ = 268,
    RESTO_ = 269,
    IGU_ = 270,
    APAR_ = 271,
    CPAR_ = 272,
    ACOR_ = 273,
    CCOR_ = 274,
    ALLAV_ = 275,
    CLLAV_ = 276,
    PUNTO_ = 277,
    PYC_ = 278,
    MENOR_ = 279,
    MAYOR_ = 280,
    MEIG_ = 281,
    MAIG_ = 282,
    IGUALC_ = 283,
    DIF_ = 284,
    AND_ = 285,
    OR_ = 286,
    INT_ = 287,
    FLOAT_ = 288,
    VARIABLE_ = 289,
    ID_ = 290,
    CTE_ = 291,
    STRUCT_ = 292,
    BOOL_ = 293,
    READ_ = 294,
    PRINT_ = 295,
    IF_ = 296,
    ELSE_ = 297,
    WHILE_ = 298,
    TRUE_ = 299,
    FALSE_ = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */