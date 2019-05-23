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
    ERASE = 260,
    PLACE = 261,
    REPETITION = 262,
    UNTIL = 263,
    FOR = 264,
    FROM = 265,
    STEP = 266,
    DO = 267,
    END_FOR = 268,
    WHILE = 269,
    END_WHILE = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    END_IF = 274,
    READ = 275,
    READ_STRING = 276,
    WRITE = 277,
    WRITE_STRING = 278,
    SWITCH = 279,
    END_SWITCH = 280,
    VALUE = 281,
    BREAK = 282,
    DEFAULT = 283,
    EXECUTE = 284,
    ASSIGNMENT = 285,
    COMMA = 286,
    NUMBER = 287,
    BOOL = 288,
    STRINGS = 289,
    VARIABLE = 290,
    UNDEFINED = 291,
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

#line 132 "interpreter.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
