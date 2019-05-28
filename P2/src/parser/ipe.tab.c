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
#line 6 "ipe.y" /* yacc.c:339  */

	#include <iostream>
	#include <string>
	#include <setjmp.h>
	#include <signal.h>
	#include <cmath>

	/* Error recovery functions */
	#include "../error/error.hpp"

	/* Macros for the screen */
	#include "../includes/macros.hpp"

	#include "../ast/ast.hpp"

	/* Table of symbol */
	#include "../table/table.hpp"
	#include "../table/numericVariable.hpp"
	#include "../table/stringVariable.hpp"
	#include "../table/logicalVariable.hpp"

	#include "../table/numericConstant.hpp"
	#include "../table/logicalConstant.hpp"
	#include "../table/builtinParameter1.hpp"
	#include "../table/builtinParameter0.hpp"
	#include "../table/builtinParameter2.hpp"

	#include "../table/init.hpp"

	/**
		@brief  Lexical or scanner function
		@return int
		@note   C++ requires that yylex returns an int value
		@sa     yyparser
	*/
	int yylex();

	extern int lineNumber; //!< External line counter

	extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

	extern int manageInteractiveMode;

	extern std::string progname; //!<  Program name
	/*
	jhmp_buf
	This is an array type capable of storing the information of a calling environment to be restored later.
	This information is filled by calling macro setjmp and can be restored by calling function longjmp.
	*/
	jmp_buf begin; //!<  It enables recovery of runtime errors

	extern lp::Table table; //!< Extern Table of Symbols

	extern lp::AST *root; //!< External root of the abstract syntax tree AST

#line 122 "ipe.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ipe.tab.h".  */
#ifndef YY_YY_IPE_TAB_H_INCLUDED
# define YY_YY_IPE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    COLON = 259,
    KILL = 260,
    ERASE = 261,
    PLACE = 262,
    REPETITION = 263,
    UNTIL = 264,
    FOR = 265,
    FROM = 266,
    STEP = 267,
    DO = 268,
    END_FOR = 269,
    WHILE = 270,
    END_WHILE = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    END_IF = 275,
    READ = 276,
    READ_STRING = 277,
    WRITE = 278,
    WRITE_STRING = 279,
    SWITCH = 280,
    END_SWITCH = 281,
    VALUE = 282,
    BREAK = 283,
    DEFAULT = 284,
    EXECUTE = 285,
    ASSIGNMENT = 286,
    COMMA = 287,
    NUMBER = 288,
    BOOL = 289,
    STRINGS = 290,
    VARIABLE = 291,
    CONSTANT = 292,
    BUILTIN = 293,
    OR = 294,
    AND = 295,
    LESS_THAN = 296,
    LESS_OR_EQUAL = 297,
    GREATER_THAN = 298,
    GREATER_OR_EQUAL = 299,
    EQUAL = 300,
    NOT_EQUAL = 301,
    NOT = 302,
    CONCATENATE = 303,
    SUM_VARIABLE = 304,
    SUBSTRACT_VARIABLE = 305,
    PRODUCT_VARIABLE = 306,
    DIVIDE_VARIABLE = 307,
    PLUS = 308,
    MINUS = 309,
    PLUS_PLUS = 310,
    MINUS_MINUS = 311,
    PRODUCT = 312,
    DIVISION = 313,
    MODULUS = 314,
    INTEGER_DIVISION = 315,
    LEFTPARENTHESIS = 316,
    RIGHTPARENTHESIS = 317,
    UNARY = 318,
    POWER_OF = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "ipe.y" /* yacc.c:355  */

	char * identifier;
	char * strings;
	double number;
	bool logic;
	lp::ExpNode *expNode;
	std::list<lp::ExpNode *>  *parameters;
	std::list<lp::Statement *> *stmts;
	std::list<lp::CasesStmt *> *cases;
	lp::Statement *st;
	lp::AST *prog;

#line 240 "ipe.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_IPE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "ipe.tab.c" /* yacc.c:358  */

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
#define YYLAST   1021

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   142,   146,   159,   167,   172,   177,   182,
     187,   192,   197,   202,   207,   212,   217,   222,   227,   233,
     239,   244,   249,   255,   261,   267,   273,   278,   284,   290,
     296,   302,   308,   314,   321,   327,   333,   339,   345,   351,
     357,   363,   369,   375,   380,   420,   425,   430,   435,   440,
     445,   450,   455,   460,   465,   470,   475,   481,   486,   491,
     496,   502,   508,   514,   519,   525,   530,   536,   541,   546,
     551,   557,   563,   569,   575,   582,   586,   592,   598,   603,
     609,   615,   619,   628,   632
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COLON", "KILL", "ERASE",
  "PLACE", "REPETITION", "UNTIL", "FOR", "FROM", "STEP", "DO", "END_FOR",
  "WHILE", "END_WHILE", "IF", "THEN", "ELSE", "END_IF", "READ",
  "READ_STRING", "WRITE", "WRITE_STRING", "SWITCH", "END_SWITCH", "VALUE",
  "BREAK", "DEFAULT", "EXECUTE", "ASSIGNMENT", "COMMA", "NUMBER", "BOOL",
  "STRINGS", "VARIABLE", "CONSTANT", "BUILTIN", "OR", "AND", "LESS_THAN",
  "LESS_OR_EQUAL", "GREATER_THAN", "GREATER_OR_EQUAL", "EQUAL",
  "NOT_EQUAL", "NOT", "CONCATENATE", "SUM_VARIABLE", "SUBSTRACT_VARIABLE",
  "PRODUCT_VARIABLE", "DIVIDE_VARIABLE", "PLUS", "MINUS", "PLUS_PLUS",
  "MINUS_MINUS", "PRODUCT", "DIVISION", "MODULUS", "INTEGER_DIVISION",
  "LEFTPARENTHESIS", "RIGHTPARENTHESIS", "UNARY", "POWER_OF", "$accept",
  "program", "stmtlist", "stmt", "exp", "asgn", "para", "repetir",
  "mientras", "si", "print", "read", "borrar", "lugar", "terminar", "cond",
  "blocks", "segun", "ejecutar", "listOfExp", "restOfListOfExp", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-77)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -45,    11,   126,   -45,   -45,   -45,   -45,   -45,   -35,   -45,
     -34,   -31,   -31,   -30,   -19,   -17,   -12,   -31,    -2,   -27,
      -4,     0,    27,   -45,    47,    61,    64,    65,    70,    72,
      91,    93,   104,   105,   110,   111,    86,   262,   109,   112,
     757,   108,   106,   -29,   -18,   757,   757,   -45,    90,   728,
     757,   757,   757,   757,   -45,   -45,   728,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,    96,   -31,   757,   757,   -45,   -45,   -45,   -45,   -45,
      69,   757,   757,   757,   757,   780,   -45,   -45,    73,    75,
      77,    78,   806,   832,    14,    80,   -27,    -4,   884,   -45,
     884,   884,   884,   884,   884,   -45,   119,   -45,    12,   525,
     757,   533,    81,    81,   858,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     -45,   757,   299,   225,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   757,   149,   -45,    92,   757,   757,   696,    95,   -45,
     909,   933,   957,   957,   957,   957,   957,   957,   200,   -25,
     -25,    81,    81,    81,    81,    81,   -45,   -45,   -45,    58,
     -45,   -45,   562,   599,   757,   -45,   -45,   336,   -45,   373,
     757,   -45,   757,   -45,   696,   -45,   183,   -45,   633,   410,
     667,   447,   -45,   152,   -45,   -45,   -45,   -45,   -45,   484,
     521,   -45,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     5,     6,    73,    71,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,    51,    53,     0,    52,    54,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    18,    16,
      17,     0,     0,     0,     0,    19,    21,    20,    32,    33,
       0,     0,     0,     0,     0,     0,     3,     3,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    45,    46,
      47,    48,    49,    50,    55,    56,     0,    61,     0,     0,
      81,    42,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,    67,    69,    68,    70,    65,    66,
      79,     0,     0,    80,     0,     0,     0,    83,     0,    27,
      41,    40,    36,    37,    34,    35,    38,    39,    43,    22,
      23,    24,    25,    30,    26,    31,    62,     3,    63,     0,
       3,    72,     0,     0,     0,    82,    44,     0,     3,     0,
       0,     3,     0,     3,    83,    64,     0,    78,     0,     0,
       0,     0,    84,     0,     3,    57,     3,    59,    77,     0,
       0,    58,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,    -9,   -45,   -36,   -44,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -11,   -45,   -45,   -45,   -45,
     -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    23,    85,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    41,    94,    34,    35,   148,
     175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    42,    38,    39,    49,    99,    47,    88,    89,    92,
      93,     3,   105,    98,   100,   101,   102,   103,    90,    91,
     104,   145,    50,    51,    52,    53,    36,    56,    54,    55,
      40,    43,   126,   127,   128,   129,    57,   108,   109,   131,
     140,   141,    44,   142,    45,   111,   112,   113,   114,    46,
      59,   115,   116,   117,   118,   119,   120,   121,   122,    48,
     123,   107,   178,    58,    60,   124,   125,    61,    62,   126,
     127,   128,   129,    63,   147,    64,   131,   132,   133,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    65,   165,    66,   115,   116,   117,
     118,   119,   120,   121,   122,   169,   123,    67,    68,   172,
     173,   124,   125,    69,    70,   126,   127,   128,   129,    71,
      73,    86,   131,    74,    87,    95,    -2,     4,   106,     5,
     110,     6,     7,     8,     9,   134,    10,   135,   184,   136,
     137,    11,   143,    12,   188,   131,   190,    13,    14,    15,
      16,    17,   144,   170,   171,   198,    18,   176,   177,     0,
     192,   179,    19,    20,     0,     0,     0,     0,     0,   186,
       0,     0,   189,     0,   191,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     4,   199,     5,   200,     6,     7,
       8,     9,     0,    10,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,    13,    14,    15,    16,    17,   -76,
     -76,   193,   -76,    18,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,     4,     0,     5,     0,
       6,     7,     8,     9,     0,    10,     0,     0,    21,    22,
      11,     0,    12,     0,   167,   168,    13,    14,    15,    16,
      17,     0,     0,   124,   125,    18,     0,   126,   127,   128,
     129,    19,    20,     4,   131,     5,     0,     6,     7,     8,
       9,    72,    10,     0,     0,     0,     0,    11,     0,    12,
      21,    22,     0,    13,    14,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,    20,
       4,     0,     5,     0,     6,     7,     8,     9,     0,    10,
       0,     0,     0,     0,    11,   166,    12,    21,    22,     0,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,    20,     4,     0,     5,
       0,     6,     7,     8,     9,     0,    10,     0,     0,     0,
       0,    11,     0,    12,    21,    22,   185,    13,    14,    15,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,    20,     4,     0,     5,     0,     6,     7,
       8,     9,     0,    10,     0,     0,     0,     0,    11,     0,
      12,    21,    22,     0,    13,    14,    15,    16,    17,   187,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
      20,     4,     0,     5,     0,     6,     7,     8,     9,     0,
      10,     0,     0,     0,   195,    11,     0,    12,    21,    22,
       0,    13,    14,    15,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,    20,     4,     0,
       5,     0,     6,     7,     8,     9,     0,    10,     0,     0,
       0,   197,    11,     0,    12,    21,    22,     0,    13,    14,
      15,    16,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,    20,     4,     0,     5,     0,     6,
       7,     8,     9,     0,    10,     0,     0,     0,   201,    11,
       0,    12,    21,    22,     0,    13,    14,    15,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,    20,     4,     0,     5,     0,     6,     7,     8,     9,
       0,    10,     0,     0,   146,   202,    11,     0,    12,    21,
      22,     0,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   180,   181,    21,    22,   124,   125,
       0,   123,   126,   127,   128,   129,   124,   125,     0,   131,
     126,   127,   128,   129,     0,     0,     0,   131,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   182,   183,     0,     0,   124,   125,     0,     0,   126,
     127,   128,   129,     0,     0,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   194,   123,     0,     0,
       0,     0,   124,   125,     0,     0,   126,   127,   128,   129,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     196,   123,     0,     0,     0,     0,   124,   125,     0,     0,
     126,   127,   128,   129,     0,     0,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,     0,     0,     0,
     124,   125,     0,     0,   126,   127,   128,   129,   174,     0,
       0,   131,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,   124,
     125,     0,     0,   126,   127,   128,   129,     0,     0,     0,
     131,    75,    76,    77,    96,    97,    80,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    82,    83,    21,    22,     0,     0,     0,     0,    84,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,    84,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,   124,   125,     0,     0,   126,   127,   128,
     129,     0,   130,     0,   131,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,   124,
     125,     0,     0,   126,   127,   128,   129,     0,   138,     0,
     131,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,     0,     0,     0,   124,   125,     0,     0,   126,
     127,   128,   129,     0,   139,     0,   131,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,   124,   125,     0,     0,   126,   127,   128,   129,     0,
     149,     0,   131,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,   124,   125,     0,
       0,   126,   127,   128,   129,     0,     0,     0,   131,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,     0,
       0,     0,   124,   125,     0,     0,   126,   127,   128,   129,
       0,     0,     0,   131,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,   124,   125,     0,     0,
     126,   127,   128,   129,     0,     0,     0,   131,   -77,   -77,
     -77,   -77,   -77,   -77,     0,   123,     0,     0,     0,     0,
     124,   125,     0,     0,   126,   127,   128,   129,     0,     0,
       0,   131
};

static const yytype_int16 yycheck[] =
{
       9,    12,    36,    37,    31,    49,    17,    36,    37,    45,
      46,     0,    56,    49,    50,    51,    52,    53,    36,    37,
      56,     9,    49,    50,    51,    52,    61,    31,    55,    56,
      61,    61,    57,    58,    59,    60,    36,    73,    74,    64,
      26,    27,    61,    29,    61,    81,    82,    83,    84,    61,
       3,    39,    40,    41,    42,    43,    44,    45,    46,    61,
      48,    72,     4,    36,     3,    53,    54,     3,     3,    57,
      58,    59,    60,     3,   110,     3,    64,    86,    87,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     3,   131,     3,    39,    40,    41,
      42,    43,    44,    45,    46,   141,    48,     3,     3,   145,
     146,    53,    54,     3,     3,    57,    58,    59,    60,    33,
      11,    13,    64,    11,    18,    35,     0,     1,    32,     3,
      61,     5,     6,     7,     8,    62,    10,    62,   174,    62,
      62,    15,    62,    17,   180,    64,   182,    21,    22,    23,
      24,    25,    33,     4,    62,     3,    30,    62,   167,    -1,
     184,   170,    36,    37,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,     1,   194,     3,   196,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    -1,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    55,    56,
      15,    -1,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    53,    54,    30,    -1,    57,    58,    59,
      60,    36,    37,     1,    64,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    15,    -1,    17,
      55,    56,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    55,    56,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,     1,    -1,     3,
      -1,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    17,    55,    56,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,     1,    -1,     3,    -1,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      17,    55,    56,    -1,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,    -1,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,    -1,    17,    55,    56,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    14,    15,    -1,    17,    55,    56,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,    -1,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,    15,
      -1,    17,    55,    56,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    10,    -1,    -1,     9,    14,    15,    -1,    17,    55,
      56,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    12,    13,    55,    56,    53,    54,
      -1,    48,    57,    58,    59,    60,    53,    54,    -1,    64,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    12,    13,    -1,    -1,    53,    54,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    13,    48,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      13,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    57,    58,    59,    60,    32,    -1,
      -1,    64,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    64,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    57,    58,    59,    60,    -1,    62,    -1,
      64,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,
      58,    59,    60,    -1,    62,    -1,    64,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    -1,    64,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    64,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     1,     3,     5,     6,     7,     8,
      10,    15,    17,    21,    22,    23,    24,    25,    30,    36,
      37,    55,    56,    68,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    83,    61,    67,    36,    37,
      61,    80,    80,    61,    61,    61,    61,    80,    61,    31,
      49,    50,    51,    52,    55,    56,    31,    36,    36,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,    33,     9,    11,    11,    33,    34,    35,    36,    37,
      38,    47,    53,    54,    61,    69,    13,    18,    36,    37,
      36,    37,    69,    69,    81,    35,    36,    37,    69,    70,
      69,    69,    69,    69,    69,    70,    32,    80,    69,    69,
      61,    69,    69,    69,    69,    39,    40,    41,    42,    43,
      44,    45,    46,    48,    53,    54,    57,    58,    59,    60,
      62,    64,    67,    67,    62,    62,    62,    62,    62,    62,
      26,    27,    29,    62,    33,     9,     9,    69,    84,    62,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    16,    19,    20,    69,
       4,    62,    69,    69,    32,    85,    62,    67,     4,    67,
      12,    13,    12,    13,    69,    20,    67,    26,    69,    67,
      69,    67,    85,    28,    13,    14,    13,    14,     3,    67,
      67,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    78,    79,    80,    81,    81,    81,    82,    82,
      83,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     4,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     9,    11,     9,
      11,     4,     5,     5,     7,     4,     4,     4,     4,     4,
       4,     1,     6,     1,     3,     0,     5,     7,     7,     4,
       4,     0,     2,     0,     3
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
#line 135 "ipe.y" /* yacc.c:1646  */
    {
				(yyval.prog) = new lp::AST((yyvsp[0].stmts));
				root = (yyval.prog);
			}
#line 1641 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 142 "ipe.y" /* yacc.c:1646  */
    {
				(yyval.stmts) = new std::list<lp::Statement *>();
			}
#line 1649 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 147 "ipe.y" /* yacc.c:1646  */
    {
				(yyval.stmts) = (yyvsp[-1].stmts);
				(yyval.stmts)->push_back((yyvsp[0].st));

				if(interactiveMode){
					if(manageInteractiveMode == 0){
						(yyvsp[0].st)->evaluate();
						std::cout << std::endl << BIYELLOW << " > " << RESET;
					}
				}
			}
#line 1665 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 160 "ipe.y" /* yacc.c:1646  */
    {
				(yyval.stmts) = (yyvsp[-1].stmts);

				yyclearin;
			}
#line 1675 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 168 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = new lp::EmptyStmt();
		}
#line 1683 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1691 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 178 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1699 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 183 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1707 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1715 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 193 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1723 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 198 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1731 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 203 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1739 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 208 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1747 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1755 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1763 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1771 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 228 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = (yyvsp[-1].st);
		}
#line 1779 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 234 "ipe.y" /* yacc.c:1646  */
    {
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 1788 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 240 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.expNode) = new lp::StringsNode((yyvsp[0].strings));
		}
#line 1796 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.expNode) = new lp::BoolNode((yyvsp[0].logic));
		}
#line 1804 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 250 "ipe.y" /* yacc.c:1646  */
    {
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 1813 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 256 "ipe.y" /* yacc.c:1646  */
    {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 1822 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 262 "ipe.y" /* yacc.c:1646  */
    {
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 1831 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 268 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new division node
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 1840 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 274 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.expNode) = new lp::IntegerDivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 1848 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 279 "ipe.y" /* yacc.c:1646  */
    {
		    // just copy up the expression node
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 1857 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 285 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new unary plus node
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 1866 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new unary minus node
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 1875 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 297 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new modulo node
		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 1884 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 303 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new power node
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 1893 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 309 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new variable node
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].identifier));
		}
#line 1902 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 315 "ipe.y" /* yacc.c:1646  */
    {
			// Create a new Constant node

			(yyval.expNode) = new lp::ConstantNode((yyvsp[0].identifier));
		}
#line 1912 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 322 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "greater than" node
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1921 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 328 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "greater or equal" node
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1930 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 334 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "less than" node
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1939 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 340 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "less or equal" node
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1948 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 346 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "equal" node
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1957 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 352 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "not equal" node
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1966 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 358 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "logic and" node
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1975 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 364 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "logic or" node
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 1984 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 370 "ipe.y" /* yacc.c:1646  */
    {
		  // Create a new "logic negation" node
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 1993 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 376 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.expNode) = new lp::ConcatenateNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2001 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 381 "ipe.y" /* yacc.c:1646  */
    {
			lp::Builtin *f = (lp::Builtin *) table.getSymbol((yyvsp[-3].identifier));

			if(f->getNParameters() == (int) (yyvsp[-1].parameters)->size()){
				switch(f->getNParameters()){
					case 0:
						{
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].identifier));
						}
						break;

					case 1:
						{
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].identifier), e);
						}
						break;

					case 2:
						{
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].identifier), e1, e2);
						}
						break;

					default:
						execerror("Syntax error: too many parameters for function ", (yyvsp[-3].identifier));
				}
			}
			else{
				execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].identifier));
			}
		}
#line 2043 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 421 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
	}
#line 2051 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 426 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].identifier), (lp::AssignmentStmt *) (yyvsp[0].st));
	}
#line 2059 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 431 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::SumVariableStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
	}
#line 2067 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 436 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::SubstractVariableStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
	}
#line 2075 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 441 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ProductVariableStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
	}
#line 2083 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 446 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::DivideVariableStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
	}
#line 2091 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 451 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::PlusPlusStmt((yyvsp[-1].identifier));
	}
#line 2099 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 456 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::PlusPlusStmt((yyvsp[0].identifier));
	}
#line 2107 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 461 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::MinusMinusStmt((yyvsp[-1].identifier));
	}
#line 2115 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 466 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::MinusMinusStmt((yyvsp[0].identifier));
	}
#line 2123 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 471 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].identifier));
	}
#line 2131 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 476 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].identifier));
	}
#line 2139 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 482 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ForStmt((yyvsp[-7].identifier), (yyvsp[-1].stmts), (yyvsp[-5].expNode), (yyvsp[-3].expNode));
	}
#line 2147 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 487 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ForStmt((yyvsp[-9].identifier), (yyvsp[-1].stmts), (yyvsp[-7].expNode), (yyvsp[-5].expNode), (yyvsp[-3].expNode));
	}
#line 2155 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 492 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in for statement: it is not allowed to modify a constant ", (yyvsp[-7].identifier));
	}
#line 2163 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 497 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in for statement: it is not allowed to modify a constant ", (yyvsp[-9].identifier));
	}
#line 2171 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 503 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = new lp::RepeatStmt((yyvsp[-2].stmts), (yyvsp[0].expNode));
		}
#line 2179 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 509 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));
		}
#line 2187 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 515 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));
	}
#line 2195 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 520 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));
	}
#line 2203 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 526 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::PrintStmt((yyvsp[-1].expNode));
	}
#line 2211 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 531 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::PrintStringStmt((yyvsp[-1].expNode));
	}
#line 2219 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 537 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ReadStmt((yyvsp[-1].identifier));
	}
#line 2227 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 542 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ReadStringStmt((yyvsp[-1].identifier));
	}
#line 2235 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 547 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in for statement: it is not allowed to modify a constant ", (yyvsp[-1].identifier));
	}
#line 2243 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 552 "ipe.y" /* yacc.c:1646  */
    {
		execerror("Semantic error in for statement: it is not allowed to modify a constant ", (yyvsp[-1].identifier));
	}
#line 2251 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 558 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::EraseStmt();
	}
#line 2259 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 564 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::PlaceStmt((yyvsp[-3].number), (yyvsp[-1].number));
	}
#line 2267 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 570 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ExitStmt();
	}
#line 2275 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 576 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.expNode) = (yyvsp[-1].expNode);
	}
#line 2283 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 582 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.cases) = new std::list<lp::CasesStmt *>();
		}
#line 2291 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 587 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.cases) = (yyvsp[-4].cases);
			(yyval.cases)->push_back(new lp::CasesStmt((yyvsp[-2].expNode), (yyvsp[0].stmts), false));
		}
#line 2300 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 593 "ipe.y" /* yacc.c:1646  */
    {
			(yyval.cases) = (yyvsp[-6].cases);
			(yyval.cases)->push_back(new lp::CasesStmt((yyvsp[-4].expNode), (yyvsp[-2].stmts), true));
		}
#line 2309 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 599 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::SwitchStmt((yyvsp[-5].expNode), (yyvsp[-4].cases), (yyvsp[-1].stmts));
	}
#line 2317 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 604 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::SwitchStmt((yyvsp[-2].expNode), (yyvsp[-1].cases));
	}
#line 2325 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 610 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.st) = new lp::ExecutionStmt((yyvsp[-1].strings));
	}
#line 2333 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 615 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.parameters) = new std::list<lp::ExpNode *>();
	}
#line 2341 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 620 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.parameters) = (yyvsp[0].parameters);

		(yyval.parameters)->push_front((yyvsp[-1].expNode));
	}
#line 2351 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 628 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.parameters) = new std::list<lp::ExpNode *>();
	}
#line 2359 "ipe.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 633 "ipe.y" /* yacc.c:1646  */
    {
		(yyval.parameters) = (yyvsp[0].parameters);

		(yyval.parameters)->push_front((yyvsp[-1].expNode));
	}
#line 2369 "ipe.tab.c" /* yacc.c:1646  */
    break;


#line 2373 "ipe.tab.c" /* yacc.c:1646  */
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
