/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "src/asin.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "libtds.h"
#include "header.h"
#include "libgci.h"


#line 75 "asin.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "asin.h".  */
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
#line 13 "src/asin.y" /* yacc.c:355  */

    int cent;
    char *ident;
    EXP exp;
    REGISTRO registro;

#line 166 "asin.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "asin.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    35,    42,    44,    48,    50,    54,    62,
      75,    90,   101,   105,   111,   117,   130,   131,   132,   133,
     134,   135,   138,   139,   142,   148,   157,   164,   156,   176,
     180,   175,   193,   195,   201,   205,   234,   264,   299,   304,
     325,   330,   347,   352,   370,   375,   390,   395,   411,   416,
     434,   453,   457,   474,   492,   502,   524,   534,   541,   548,
     558,   562,   566,   570,   574,   580,   584,   590,   594,   600,
     604,   608,   612,   618,   622,   628,   632,   636,   642,   646,
     650,   656,   660
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCR_", "MASIG_", "DECR_", "MENIG_",
  "PORIG_", "DIVIG_", "IGU_", "APAR_", "CPAR_", "ACOR_", "CCOR_", "ALLAV_",
  "CLLAV_", "PUNTO_", "PYC_", "AND_", "OR_", "EXCL_", "MENOR_", "MAYOR_",
  "MEIG_", "MAIG_", "IGUALC_", "DIF_", "MAS_", "MENOS_", "POR_", "DIV_",
  "RESTO_", "CTE_", "ID_", "INT_", "STRUCT_", "BOOL_", "READ_", "PRINT_",
  "IF_", "ELSE_", "WHILE_", "TRUE_", "FALSE_", "$accept", "programa",
  "$@1", "secuenciaSentencias", "sentencia", "declaracion", "tipoSimple",
  "listaCampos", "instruccion", "listaInstrucciones",
  "instruccionesEntradaSalida", "instruccionSeleccion", "@2", "@3",
  "instruccionIteracion", "@4", "@5", "instruccionExpresion", "expresion",
  "expresionLogica", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "constante", "operadorAsignacion", "operadorLogico",
  "operadorIgualdad", "operadorRelacional", "operadorAditivo",
  "operadorMultiplicativo", "operadorUnario", "operadorIncremento", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,    22,    19,   -87,    90,   -87,   -87,   217,   132,   -87,
     -87,   -87,   -87,   -87,     4,   -87,    26,   -87,    24,    42,
      53,   -87,   -87,   -87,    23,   -87,   -87,    48,   -87,   -87,
     -87,   -87,   -87,    68,    59,    54,    46,    55,   -14,   -87,
     -87,   -87,   258,    51,    75,   -87,   -87,   173,   -87,   -87,
     -87,   -87,   -87,   217,    56,   217,   -87,    12,    57,   217,
     217,    77,   -87,   -87,    28,   -87,   -87,   -87,   258,   -87,
     -87,   258,   -87,   -87,   -87,   -87,   258,   -87,   -87,   258,
     -87,   -87,   -87,   258,    16,   -87,   -87,   -87,   -87,   -87,
      73,    67,   -87,    58,    -7,    83,    85,    86,   217,   -18,
      66,   -87,    54,    46,    55,   -14,   -87,   217,    70,    67,
     217,    82,    72,    76,    89,    91,   -87,   100,    95,    98,
      99,   -87,   217,   -87,   -87,   102,   103,   -87,   -87,   214,
     -87,   -87,   119,   -87,   -87,   -87,   -87,   -87,   214,   -87,
     101,   -87,   214,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    81,    82,     0,     0,    33,
      80,    78,    79,    57,    54,    12,     0,    13,     0,     0,
       0,    29,    58,    59,     0,     4,     6,     0,     7,    18,
      19,    20,    21,     0,    34,    38,    40,    42,    44,    46,
      48,    56,     0,     0,     0,    16,    22,     0,    61,    62,
      63,    64,    60,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     3,     5,     0,    32,    65,    66,     0,    67,
      68,     0,    70,    69,    72,    71,     0,    73,    74,     0,
      75,    76,    77,     0,    54,    49,    50,    51,    17,    23,
       0,    55,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     8,    39,    41,    43,    45,    47,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,    55,     0,    37,    14,     0,     0,    24,    25,     0,
      30,     9,     0,    53,    36,    11,    15,    27,     0,    10,
       0,    31,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,   -87,   114,   -87,   -53,   -87,    -8,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    -6,   -87,
      47,    69,    63,    64,   -39,   -87,    49,   -86,   -87,   -87,
     -87,   -87,   -87,   -87,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    24,    25,    26,    27,    94,    28,    47,
      29,    30,   129,   140,    31,    61,   138,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    55,    68,    71,
      76,    79,    83,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    44,    56,    85,    93,   110,   112,     5,    48,     6,
      49,    50,    51,    52,    13,    80,    81,    82,    53,     5,
      54,     6,     3,   122,    22,    23,     5,    15,     6,    17,
     107,     4,   108,     7,    58,     8,    62,    99,    57,    89,
       9,   113,   100,    10,   106,   101,    15,    90,    17,    92,
      11,    12,    59,    96,    97,    13,    14,    15,    16,    17,
      18,    19,    20,    60,    21,    22,    23,    72,    73,    74,
      75,    48,    56,    49,    50,    51,    52,    66,    67,    69,
      70,    64,    77,    78,    86,    65,    87,    98,   109,    91,
      95,   111,   117,     5,   114,     6,   115,   116,   119,   124,
       7,   120,     8,   121,   123,   125,   127,     9,   128,   126,
      10,   130,   131,   132,   133,   102,   134,    11,    12,   135,
     136,   137,    13,    14,    15,    16,    17,    18,    19,    20,
     141,    21,    22,    23,   143,     5,   139,     6,    63,   104,
     103,   142,     7,   105,     8,    45,     0,     0,   118,     9,
       0,     0,    10,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,    13,    14,     0,     0,     0,    18,
      19,    20,     0,    21,    22,    23,     5,     0,     6,     0,
       0,     0,     0,     7,     0,     8,    88,     0,     0,     0,
       9,     0,     0,    10,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,    13,    14,     0,     0,     0,
      18,    19,    20,     0,    21,    22,    23,     5,     0,     6,
       5,     0,     6,     0,     7,     0,     8,     7,     0,     0,
       0,     9,     0,     0,    10,     0,     0,    10,     0,     0,
       0,    11,    12,     0,    11,    12,    13,    14,     0,    13,
      14,    18,    19,    20,     0,    21,    22,    23,     0,    22,
      23,     5,     0,     6,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
      13,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23
};

static const yytype_int16 yycheck[] =
{
       8,     7,    14,    42,    57,    91,    13,     3,     4,     5,
       6,     7,     8,     9,    32,    29,    30,    31,    14,     3,
      16,     5,     0,   109,    42,    43,     3,    34,     5,    36,
      14,    12,    16,    10,    10,    12,    13,     9,    12,    47,
      17,    94,    14,    20,    83,    17,    34,    53,    36,    55,
      27,    28,    10,    59,    60,    32,    33,    34,    35,    36,
      37,    38,    39,    10,    41,    42,    43,    21,    22,    23,
      24,     4,    84,     6,     7,     8,     9,    18,    19,    25,
      26,    33,    27,    28,    33,    17,    11,    10,    15,    33,
      33,    33,    98,     3,    11,     5,    11,    11,    32,    17,
      10,   107,    12,    33,   110,    33,    17,    17,    17,    33,
      20,    11,    17,    15,    15,    68,   122,    27,    28,    17,
      17,   129,    32,    33,    34,    35,    36,    37,    38,    39,
     138,    41,    42,    43,   142,     3,    17,     5,    24,    76,
      71,    40,    10,    79,    12,    13,    -1,    -1,    99,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    42,    43,     3,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    12,    13,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    43,     3,    -1,     5,
       3,    -1,     5,    -1,    10,    -1,    12,    10,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    -1,    20,    -1,    -1,
      -1,    27,    28,    -1,    27,    28,    32,    33,    -1,    32,
      33,    37,    38,    39,    -1,    41,    42,    43,    -1,    42,
      43,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,    12,     3,     5,    10,    12,    17,
      20,    27,    28,    32,    33,    34,    35,    36,    37,    38,
      39,    41,    42,    43,    47,    48,    49,    50,    52,    54,
      55,    58,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    77,    78,    62,    13,    52,    53,     4,     6,
       7,     8,     9,    14,    16,    71,    78,    12,    10,    10,
      10,    59,    13,    48,    33,    17,    18,    19,    72,    25,
      26,    73,    21,    22,    23,    24,    74,    27,    28,    75,
      29,    30,    31,    76,    33,    68,    33,    11,    13,    52,
      62,    33,    62,    50,    51,    33,    62,    62,    10,     9,
      14,    17,    64,    65,    66,    67,    68,    14,    16,    15,
      71,    33,    13,    50,    11,    11,    11,    62,    70,    32,
      62,    33,    71,    62,    17,    33,    33,    17,    17,    56,
      11,    17,    15,    15,    62,    17,    17,    52,    60,    17,
      57,    52,    40,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    56,    57,    55,    59,
      60,    58,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     1,     2,     1,     1,     3,     5,
       6,     6,     1,     1,     3,     4,     2,     3,     1,     1,
       1,     1,     1,     2,     5,     5,     0,     0,     9,     0,
       0,     7,     2,     1,     1,     3,     6,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     3,     2,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 35 "src/asin.y" /* yacc.c:1646  */
    {dvar = 0; si = 0;}
#line 1401 "asin.c" /* yacc.c:1646  */
    break;

  case 3:
#line 37 "src/asin.y" /* yacc.c:1646  */
    { if (verTDS) verTdS(); 
                                emite(FIN, crArgNul(),crArgNul(),crArgNul());
                                }
#line 1409 "asin.c" /* yacc.c:1646  */
    break;

  case 4:
#line 43 "src/asin.y" /* yacc.c:1646  */
    {  }
#line 1415 "asin.c" /* yacc.c:1646  */
    break;

  case 5:
#line 45 "src/asin.y" /* yacc.c:1646  */
    {  }
#line 1421 "asin.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "src/asin.y" /* yacc.c:1646  */
    {  }
#line 1427 "asin.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "src/asin.y" /* yacc.c:1646  */
    {  }
#line 1433 "asin.c" /* yacc.c:1646  */
    break;

  case 8:
#line 55 "src/asin.y" /* yacc.c:1646  */
    {
                                  if( !insTdS((yyvsp[-1].ident), (yyvsp[-2].cent), dvar , -1) )
                                    yyerror("Variable ya definida");
                                  else 
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
#line 1444 "asin.c" /* yacc.c:1646  */
    break;

  case 9:
#line 63 "src/asin.y" /* yacc.c:1646  */
    {
                                  if( ! ((yyvsp[-4].cent) == (yyvsp[-1].exp).tipo))
                                    yyerror("No se pudo realizar la asignación, tipos incompatibles");
                                  else
                                    if( ! insTdS((yyvsp[-3].ident), (yyvsp[-4].cent), dvar, -1) )
                                      yyerror("Variable ya definida");
                                    else
                                      dvar += TALLA_TIPO_SIMPLE;
                                      SIMB simb = obtTdS((yyvsp[-3].ident));
                                      emite(EASIG,crArgPos((yyvsp[-1].exp).desp) ,crArgNul(),crArgPos(simb.desp));
                                }
#line 1460 "asin.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "src/asin.y" /* yacc.c:1646  */
    {
                                  int numelem = (yyvsp[-2].cent);
                                  if ((yyvsp[-2].cent) <=0){
                                    yyerror("Talla inapropiada del array");
                                    numelem = 0;
                                  } else{
                                    int refe = insTdA((yyvsp[-5].cent),numelem);
                                    if( !insTdS((yyvsp[-4].ident), T_ARRAY, dvar, refe) ){
                                      yyerror("Identificador repetido");
                                    }
                                    else{ dvar += numelem * TALLA_TIPO_SIMPLE;}
                                  }
                                 }
#line 1478 "asin.c" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "src/asin.y" /* yacc.c:1646  */
    {
                                  if(! insTdS((yyvsp[-1].ident), T_RECORD, (yyvsp[-3].registro).talla, (yyvsp[-3].registro).ref))
                                    yyerror("Identificador repetido");
                                    else
                                      dvar += (yyvsp[-3].registro).talla;
                                }
#line 1489 "asin.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.cent) = T_ENTERO;
                                }
#line 1497 "asin.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.cent) = T_LOGICO;
                                }
#line 1505 "asin.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.registro).ref = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0);
                                  (yyval.registro).talla = TALLA_TIPO_SIMPLE;
                                }
#line 1514 "asin.c" /* yacc.c:1646  */
    break;

  case 15:
#line 118 "src/asin.y" /* yacc.c:1646  */
    { (yyval.registro).ref=(yyvsp[-3].registro).ref; (yyval.registro).talla=(yyvsp[-3].registro).talla;
                                  int ref = insTdR((yyvsp[-3].registro).ref, (yyvsp[-1].ident), (yyvsp[-2].cent), (yyvsp[-3].registro).talla);
                                  if (ref == -1)
                                    yyerror("Campo ya declarado");
                                  else{ 
                                    (yyval.registro).talla = (yyvsp[-3].registro).talla + TALLA_TIPO_SIMPLE;
                                    (yyval.registro).ref = ref;
                                  }
                                }
#line 1528 "asin.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "src/asin.y" /* yacc.c:1646  */
    { SIMB simb = obtTdS((yyvsp[-2].ident));
                                if(simb.tipo != T_ENTERO)
                                  yyerror("No se pueden leer valores no enteros");
                                emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.desp));
                              }
#line 1538 "asin.c" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "src/asin.y" /* yacc.c:1646  */
    { if((yyvsp[-2].exp).tipo != T_ERROR)
                                  if ((yyvsp[-2].exp).tipo != T_ENTERO)
                                    yyerror("No se pueden imprimir valores de tipo no entero");
                                emite(EWRITE, crArgNul(), crArgNul(), crArgPos((yyvsp[-2].exp).desp));
                              }
#line 1548 "asin.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "src/asin.y" /* yacc.c:1646  */
    { if((yyvsp[-1].exp).tipo != T_ERROR)
                                  if((yyvsp[-1].exp).tipo != T_LOGICO)
                                    yyerror("La condición debe ser de tipo lógico");
                                (yyval.cent) = creaLans(si);
                                emite(EIGUAL, crArgPos((yyvsp[-1].exp).desp), crArgEnt(0), crArgEtq(-1));
                              }
#line 1559 "asin.c" /* yacc.c:1646  */
    break;

  case 27:
#line 164 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = creaLans(si);
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
                                completaLans((yyvsp[-1].cent), crArgEnt(si));
                              }
#line 1569 "asin.c" /* yacc.c:1646  */
    break;

  case 28:
#line 170 "src/asin.y" /* yacc.c:1646  */
    {
                                completaLans((yyvsp[-2].cent), crArgEnt(si));
                              }
#line 1577 "asin.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = si;
                              }
#line 1585 "asin.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "src/asin.y" /* yacc.c:1646  */
    { if((yyvsp[-1].exp).tipo != T_ERROR)
                                    if((yyvsp[-1].exp).tipo != T_LOGICO)
                                      yyerror("La condición debe ser de tipo lógico");
                                  (yyval.cent) = creaLans(si);
                                  emite(EIGUAL, crArgPos((yyvsp[-1].exp).desp), crArgEnt(0), crArgEtq(-1));
                                }
#line 1596 "asin.c" /* yacc.c:1646  */
    break;

  case 31:
#line 187 "src/asin.y" /* yacc.c:1646  */
    {
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].cent)));
                                completaLans((yyvsp[-1].cent), crArgEnt(si));
                              }
#line 1605 "asin.c" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "src/asin.y" /* yacc.c:1646  */
    {}
#line 1611 "asin.c" /* yacc.c:1646  */
    break;

  case 33:
#line 196 "src/asin.y" /* yacc.c:1646  */
    {}
#line 1617 "asin.c" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo; (yyval.exp).desp = (yyvsp[0].exp).desp;
                              }
#line 1625 "asin.c" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "src/asin.y" /* yacc.c:1646  */
    { if((yyvsp[0].exp).tipo != T_ERROR){
                                  (yyval.exp).tipo = T_ERROR;
                                  SIMB simb = obtTdS((yyvsp[-2].ident)); 
                                  if(simb.tipo == T_ERROR) yyerror("Objeto no declarado");
                                  else{

                                    if ((yyvsp[0].exp).tipo != T_ERROR){
                                      if (! ((simb.tipo  == T_ENTERO && (yyvsp[0].exp).tipo == T_ENTERO) || 
                                                (simb.tipo  == T_LOGICO && (yyvsp[0].exp).tipo == T_LOGICO))) 
                                          yyerror("Error de tipos en la 'instruccion de asignación'");
                                      else{
                                       (yyval.exp).tipo = simb.tipo;

                                        (yyval.exp).desp = creaVarTemp();
                                        if ((yyvsp[-1].cent) == EASIG){
                                          
                                          emite(EASIG, crArgPos((yyvsp[0].exp).desp), crArgNul(),crArgPos(simb.desp));
                                          emite(EASIG, crArgPos(simb.desp), crArgNul(),crArgPos((yyval.exp).desp));
                                        }else{
                                          emite((yyvsp[-1].cent), crArgPos(simb.desp),crArgPos((yyvsp[0].exp).desp),crArgPos(simb.desp));
                                          emite(EASIG, crArgPos(simb.desp), crArgNul(),crArgPos((yyval.exp).desp));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
#line 1657 "asin.c" /* yacc.c:1646  */
    break;

  case 36:
#line 235 "src/asin.y" /* yacc.c:1646  */
    { if ((yyvsp[0].exp).tipo != T_ERROR){
                                  (yyval.exp).tipo = T_ERROR;
                                  SIMB simb = obtTdS((yyvsp[-5].ident));
                                  if (simb.tipo == T_ERROR) yyerror("Array no declarado");
                                  else{
                                    if (simb.tipo != T_ARRAY) yyerror("La variable a la que se intentó acceder no es un array");
                                    else{
                                      if((yyvsp[-3].exp).tipo != T_ENTERO) yyerror("Tipo incorrecto de indice de Array");
                                      else{
                                        DIM dim = obtTdA(simb.ref);
                                        if (dim.telem != (yyvsp[0].exp).tipo)
                                          yyerror("Tipo incompatible con los tipos del array");
                                        else{
                                          (yyval.exp).tipo = dim.telem; 

                                          (yyval.exp).desp = creaVarTemp();
                                          if((yyvsp[-1].cent) == EASIG){
                                            emite(EVA,crArgPos(simb.desp) ,crArgPos((yyvsp[-3].exp).desp), crArgPos((yyvsp[0].exp).desp));
                                          }else{
                                            emite(EAV, crArgPos(simb.desp), crArgPos((yyvsp[-3].exp).desp), crArgPos((yyval.exp).desp));
                                            emite((yyvsp[-1].cent), crArgPos((yyval.exp).desp), crArgPos((yyvsp[0].exp).desp), crArgPos((yyval.exp).desp));
                                            emite(EVA,crArgPos(simb.desp) ,crArgPos((yyvsp[-3].exp).desp), crArgPos((yyval.exp).desp));
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
#line 1691 "asin.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "src/asin.y" /* yacc.c:1646  */
    { if((yyvsp[0].exp).tipo != T_ERROR){
                                  (yyval.exp).tipo = T_ERROR;
                                  SIMB simb = obtTdS((yyvsp[-4].ident));
                                  if(simb.tipo == T_ERROR)
                                    yyerror("Identificador no declarado");
                                  else{
                                    if(simb.tipo != T_RECORD)
                                      yyerror("No se puede acceder a un campo de un no-registro");
                                    else{
                                      CAMP camp = obtTdR(simb.ref, (yyvsp[-2].ident));
                                      if(camp.tipo == T_ERROR)
                                        yyerror("Campo no definido");
                                      else{
                                        if(camp.tipo != (yyvsp[0].exp).tipo)
                                          yyerror("Tipo de campo y de elemento incompatibles");
                                        else{
                                          (yyval.exp).tipo = camp.tipo; 

                                          (yyval.exp).desp = creaVarTemp();
                                          int pos = camp.desp + simb.desp;
                                          if((yyvsp[-1].cent) == EASIG){
                                            emite(EASIG, crArgPos((yyvsp[0].exp).desp), crArgNul(), crArgPos(pos));
                                          }else{
                                            emite((yyvsp[-1].cent), crArgPos(pos), crArgPos((yyvsp[0].exp).desp), crArgPos(pos));
                                          }
                                          emite(EASIG,crArgPos(pos) ,crArgNul(), crArgPos((yyval.exp).desp));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
#line 1728 "asin.c" /* yacc.c:1646  */
    break;

  case 38:
#line 300 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1737 "asin.c" /* yacc.c:1646  */
    break;

  case 39:
#line 305 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if((yyvsp[-2].exp).tipo != T_ERROR && (yyvsp[0].exp).tipo != T_ERROR){
                                  if((yyvsp[-2].exp).tipo != T_LOGICO || (yyvsp[0].exp).tipo != T_LOGICO){
                                    yyerror("Ambos operadores deben ser de tipo logico");
                                  }
                                  else{
                                    (yyval.exp).tipo = T_LOGICO;
                                    (yyval.exp).desp = creaVarTemp();
                                    if((yyvsp[-1].cent) == AND){
                                      emite(EMULT, crArgPos((yyvsp[-2].exp).desp), crArgPos((yyvsp[0].exp).desp), crArgPos((yyval.exp).desp));
                                    }else{
                                      emite(ESUM, crArgPos((yyvsp[-2].exp).desp), crArgPos((yyvsp[0].exp).desp), crArgPos((yyval.exp).desp));
                                      emite(EMENEQ, crArgPos((yyval.exp).desp), crArgEnt(1), crArgEtq(si + 2));
                                      emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.exp).desp));
                                    }
                                  }
                                }
                              }
#line 1760 "asin.c" /* yacc.c:1646  */
    break;

  case 40:
#line 326 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1769 "asin.c" /* yacc.c:1646  */
    break;

  case 41:
#line 331 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if((yyvsp[-2].exp).tipo != T_ERROR && (yyvsp[0].exp).tipo != T_ERROR){
                                  if(!(((yyvsp[-2].exp).tipo == T_LOGICO && (yyvsp[0].exp).tipo == T_LOGICO)||((yyvsp[-2].exp).tipo == T_ENTERO && (yyvsp[0].exp).tipo == T_ENTERO))){
                                    yyerror("Ambos operadores deben ser del mismo tipo");
                                  }
                                  else{
                                    (yyval.exp).tipo = T_LOGICO;
                                    (yyval.exp).desp = creaVarTemp();
                                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.exp).desp));
                                    emite((yyvsp[-1].cent), crArgPos((yyvsp[-2].exp).desp),crArgPos((yyvsp[0].exp).desp),crArgEtq(si + 2));
                                    emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.exp).desp));
                                  }
                                }
                              }
#line 1788 "asin.c" /* yacc.c:1646  */
    break;

  case 42:
#line 348 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1797 "asin.c" /* yacc.c:1646  */
    break;

  case 43:
#line 353 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if((yyvsp[-2].exp).tipo != T_ERROR && (yyvsp[0].exp).tipo != T_ERROR){
                                  if((yyvsp[-2].exp).tipo != T_ENTERO || (yyvsp[0].exp).tipo != T_ENTERO) {
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    (yyval.exp).tipo = T_LOGICO;
                                    
                                    (yyval.exp).desp = creaVarTemp();
                                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.exp).desp));
                                    emite((yyvsp[-1].cent), crArgPos((yyvsp[-2].exp).desp),crArgPos((yyvsp[0].exp).desp),crArgEtq(si + 2));
                                    emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.exp).desp));
                                  }
                                }
                              }
#line 1817 "asin.c" /* yacc.c:1646  */
    break;

  case 44:
#line 371 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1826 "asin.c" /* yacc.c:1646  */
    break;

  case 45:
#line 376 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if((yyvsp[-2].exp).tipo != T_ERROR && (yyvsp[0].exp).tipo != T_ERROR){
                                  if((yyvsp[-2].exp).tipo != T_ENTERO || (yyvsp[0].exp).tipo != T_ENTERO){
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    (yyval.exp).tipo = (yyvsp[-2].exp).tipo;
                                    (yyval.exp).desp = creaVarTemp();
                                    emite((yyvsp[-1].cent),crArgPos((yyvsp[-2].exp).desp),crArgPos((yyvsp[0].exp).desp),crArgPos((yyval.exp).desp));
                                  }
                                }
                              }
#line 1843 "asin.c" /* yacc.c:1646  */
    break;

  case 46:
#line 391 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1852 "asin.c" /* yacc.c:1646  */
    break;

  case 47:
#line 396 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if((yyvsp[-2].exp).tipo != T_ERROR && (yyvsp[0].exp).tipo != T_ERROR){
                                  if((yyvsp[-2].exp).tipo != T_ENTERO || (yyvsp[0].exp).tipo != T_ENTERO){
                                    yyerror("Ambos operadores deben ser de tipo entero");
                                  }
                                  else{
                                    (yyval.exp).tipo = (yyvsp[-2].exp).tipo;
                                    
                                    (yyval.exp).desp = creaVarTemp();
                                    emite((yyvsp[-1].cent), crArgPos((yyvsp[-2].exp).desp),crArgPos((yyvsp[0].exp).desp),crArgPos((yyval.exp).desp));
                                  }
                                }
                              }
#line 1870 "asin.c" /* yacc.c:1646  */
    break;

  case 48:
#line 412 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).desp = (yyvsp[0].exp).desp;
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                              }
#line 1879 "asin.c" /* yacc.c:1646  */
    break;

  case 49:
#line 417 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                if ((yyvsp[0].exp).tipo != T_ERROR){
                                  if((yyvsp[-1].cent) == NOT && (yyvsp[0].exp).tipo == T_ENTERO){
                                    yyerror("Error de tipos en la aplicación del NOT");
                                  }
                                  else{
                                    (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                                    (yyval.exp).desp = creaVarTemp();
                                    if((yyvsp[-1].cent) == NOT){
                                      emite(EDIF, crArgEnt(1),crArgPos((yyvsp[0].exp).desp),crArgPos((yyval.exp).desp));
                                    }
                                    if((yyvsp[-1].cent) == MENOS){
                                      emite(ESIG, crArgPos((yyvsp[0].exp).desp), crArgNul(),crArgPos((yyval.exp).desp));
                                    }
                                  }
                                }
                              }
#line 1901 "asin.c" /* yacc.c:1646  */
    break;

  case 50:
#line 435 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                SIMB simb = obtTdS((yyvsp[0].ident));
                                if(simb.tipo == T_ERROR)
                                  yyerror("Variable no definida");
                                else {
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("No se puede realizar una operación incremental sobre un no entero");
                                  else {
                                    (yyval.exp).tipo = simb.tipo;

                                    (yyval.exp).desp = creaVarTemp();
                                    emite((yyvsp[-1].cent),crArgPos(simb.desp), crArgEnt(1),crArgPos(simb.desp));
                                    emite(EASIG,crArgPos(simb.desp),crArgNul(),crArgPos((yyval.exp).desp));
                                  }
                                }
                              }
#line 1922 "asin.c" /* yacc.c:1646  */
    break;

  case 51:
#line 454 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).tipo = (yyvsp[-1].exp).tipo; (yyval.exp).desp = (yyvsp[-1].exp).desp;
                              }
#line 1930 "asin.c" /* yacc.c:1646  */
    break;

  case 52:
#line 458 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                SIMB simb = obtTdS((yyvsp[-1].ident));
                                if(simb.tipo == T_ERROR)
                                  yyerror("Variable no definida");
                                else
                                  if(simb.tipo != T_ENTERO)
                                    yyerror("No se puede incrementar una variable no entera");
                                  else{
                                    (yyval.exp).tipo = simb.tipo;

                                    (yyval.exp).desp = creaVarTemp();
                                    emite(EASIG,crArgPos(simb.desp),crArgNul(),crArgPos((yyval.exp).desp));
                                    emite((yyvsp[0].cent),crArgPos(simb.desp), crArgEnt(1),crArgPos(simb.desp));
                                  }

                              }
#line 1951 "asin.c" /* yacc.c:1646  */
    break;

  case 53:
#line 475 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                SIMB simb = obtTdS((yyvsp[-3].ident));
                                if (simb.tipo == T_ERROR) yyerror("Array no declarado");
                                else{
                                  if (simb.tipo != T_ARRAY) yyerror("La variable a la que se intentó acceder no es un array");
                                  else{
                                    if((yyvsp[-1].exp).tipo != T_ENTERO) yyerror("Tipo incorrecto de indice de Array");
                                    else{
                                      DIM dim = obtTdA(simb.ref);
                                      (yyval.exp).tipo = dim.telem;

                                      (yyval.exp).desp = creaVarTemp();
                                      emite(EAV, crArgPos(simb.desp), crArgEnt((yyvsp[-1].exp).desp),crArgPos((yyval.exp).desp));
                                    }
                                  }
                                }
                              }
#line 1973 "asin.c" /* yacc.c:1646  */
    break;

  case 54:
#line 493 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                SIMB simb = obtTdS((yyvsp[0].ident));
                                if (simb.tipo == T_ERROR) yyerror("Variable no declarada");
                                else{
                                  (yyval.exp).tipo = simb.tipo;
                                  (yyval.exp).desp = creaVarTemp();
                                  emite(EASIG, crArgPos(simb.desp), crArgNul(), crArgPos((yyval.exp).desp));
                                }
                              }
#line 1987 "asin.c" /* yacc.c:1646  */
    break;

  case 55:
#line 503 "src/asin.y" /* yacc.c:1646  */
    { (yyval.exp).tipo = T_ERROR;
                                SIMB simb = obtTdS((yyvsp[-2].ident));
                                if(simb.tipo == T_ERROR)
                                  yyerror("Identificador no declarado");
                                else{
                                  if(simb.tipo != T_RECORD)
                                    yyerror("No se puede acceder a un campo de un no-registro");
                                  else{
                                    CAMP camp = obtTdR(simb.ref, (yyvsp[0].ident));
                                    if(camp.tipo == T_ERROR)
                                      yyerror("Campo no definido");
                                    else{
                                      (yyval.exp).tipo = camp.tipo;

                                      int desp = simb.desp + camp.desp;
                                      (yyval.exp).desp = creaVarTemp();
                                      emite(EASIG, crArgPos(desp), crArgNul(), crArgPos((yyval.exp).desp));
                                    }
                                  }
                                }
                              }
#line 2013 "asin.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                                (yyval.exp).desp = creaVarTemp();
                                emite(EASIG, crArgPos((yyvsp[0].exp).desp), crArgNul(), crArgPos((yyval.exp).desp));
                              }
#line 2023 "asin.c" /* yacc.c:1646  */
    break;

  case 57:
#line 535 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.exp).tipo = T_ENTERO;
                                  (yyval.exp).desp = creaVarTemp();
                                  emite(EASIG, crArgEnt((yyvsp[0].cent)), crArgNul(), crArgPos((yyval.exp).desp));
                                }
#line 2033 "asin.c" /* yacc.c:1646  */
    break;

  case 58:
#line 542 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.exp).tipo = T_LOGICO;
                                  (yyval.exp).desp = creaVarTemp();
                                  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.exp).desp));
                                }
#line 2043 "asin.c" /* yacc.c:1646  */
    break;

  case 59:
#line 549 "src/asin.y" /* yacc.c:1646  */
    {
                                  (yyval.exp).tipo = T_LOGICO;
                                  (yyval.exp).desp = creaVarTemp();
                                  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.exp).desp));
                                }
#line 2053 "asin.c" /* yacc.c:1646  */
    break;

  case 60:
#line 559 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EASIG;
                              }
#line 2061 "asin.c" /* yacc.c:1646  */
    break;

  case 61:
#line 563 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = ESUM;
                              }
#line 2069 "asin.c" /* yacc.c:1646  */
    break;

  case 62:
#line 567 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIF;
                              }
#line 2077 "asin.c" /* yacc.c:1646  */
    break;

  case 63:
#line 571 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMULT;
                              }
#line 2085 "asin.c" /* yacc.c:1646  */
    break;

  case 64:
#line 575 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIVI;
                              }
#line 2093 "asin.c" /* yacc.c:1646  */
    break;

  case 65:
#line 581 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = AND;
                              }
#line 2101 "asin.c" /* yacc.c:1646  */
    break;

  case 66:
#line 585 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = OR;
                              }
#line 2109 "asin.c" /* yacc.c:1646  */
    break;

  case 67:
#line 591 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EIGUAL;
                              }
#line 2117 "asin.c" /* yacc.c:1646  */
    break;

  case 68:
#line 595 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIST;
                              }
#line 2125 "asin.c" /* yacc.c:1646  */
    break;

  case 69:
#line 601 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMAY;
                              }
#line 2133 "asin.c" /* yacc.c:1646  */
    break;

  case 70:
#line 605 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMEN;
                              }
#line 2141 "asin.c" /* yacc.c:1646  */
    break;

  case 71:
#line 609 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMAYEQ;
                              }
#line 2149 "asin.c" /* yacc.c:1646  */
    break;

  case 72:
#line 613 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMENEQ;
                              }
#line 2157 "asin.c" /* yacc.c:1646  */
    break;

  case 73:
#line 619 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = ESUM;
                              }
#line 2165 "asin.c" /* yacc.c:1646  */
    break;

  case 74:
#line 623 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIF;
                              }
#line 2173 "asin.c" /* yacc.c:1646  */
    break;

  case 75:
#line 629 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EMULT;
                              }
#line 2181 "asin.c" /* yacc.c:1646  */
    break;

  case 76:
#line 633 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIVI;
                              }
#line 2189 "asin.c" /* yacc.c:1646  */
    break;

  case 77:
#line 637 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = RESTO;
                              }
#line 2197 "asin.c" /* yacc.c:1646  */
    break;

  case 78:
#line 643 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = MAS;
                              }
#line 2205 "asin.c" /* yacc.c:1646  */
    break;

  case 79:
#line 647 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = MENOS;
                              }
#line 2213 "asin.c" /* yacc.c:1646  */
    break;

  case 80:
#line 651 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = NOT;
                              }
#line 2221 "asin.c" /* yacc.c:1646  */
    break;

  case 81:
#line 657 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = ESUM;
                              }
#line 2229 "asin.c" /* yacc.c:1646  */
    break;

  case 82:
#line 661 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.cent) = EDIF; 
                              }
#line 2237 "asin.c" /* yacc.c:1646  */
    break;


#line 2241 "asin.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 666 "src/asin.y" /* yacc.c:1906  */

