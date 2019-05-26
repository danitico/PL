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

#ifndef YY_YY_INTERPRETER_TAB_H_INCLUDED
# define YY_YY_INTERPRETER_TAB_H_INCLUDED
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
    UNDEFINED = 292,
    CONSTANT = 293,
    BUILTIN = 294,
    OR = 295,
    AND = 296,
    LESS_THAN = 297,
    LESS_OR_EQUAL = 298,
    GREATER_THAN = 299,
    GREATER_OR_EQUAL = 300,
    EQUAL = 301,
    NOT_EQUAL = 302,
    NOT = 303,
    CONCATENATE = 304,
    SUM_VARIABLE = 305,
    SUBSTRACT_VARIABLE = 306,
    PRODUCT_VARIABLE = 307,
    DIVIDE_VARIABLE = 308,
    PLUS = 309,
    MINUS = 310,
    PLUS_PLUS = 311,
    MINUS_MINUS = 312,
    PRODUCT = 313,
    DIVISION = 314,
    MODULUS = 315,
    INTEGER_DIVISION = 316,
    LEFTPARENTHESIS = 317,
    RIGHTPARENTHESIS = 318,
    UNARY = 319,
    POWER_OF = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "interpreter.y" /* yacc.c:1909  */

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

#line 133 "interpreter.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
