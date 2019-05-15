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
    ERASE = 259,
    PLACE = 260,
    REPETITION = 261,
    UNTIL = 262,
    FOR = 263,
    FROM = 264,
    STEP = 265,
    DO = 266,
    END_FOR = 267,
    WHILE = 268,
    END_WHILE = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    END_IF = 273,
    READ = 274,
    READ_STRING = 275,
    WRITE = 276,
    WRITE_STRING = 277,
    ASSIGNMENT = 278,
    COMMA = 279,
    NUMBER = 280,
    BOOL = 281,
    STRINGS = 282,
    VARIABLE = 283,
    UNDEFINED = 284,
    CONSTANT = 285,
    OR = 286,
    AND = 287,
    LESS_THAN = 288,
    LESS_OR_EQUAL = 289,
    GREATER_THAN = 290,
    GREATER_OR_EQUAL = 291,
    EQUAL = 292,
    NOT_EQUAL = 293,
    NOT = 294,
    CONCATENATE = 295,
    SUM_VARIABLE = 296,
    SUBSTRACT_VARIABLE = 297,
    PRODUCT_VARIABLE = 298,
    DIVIDE_VARIABLE = 299,
    PLUS = 300,
    MINUS = 301,
    PRODUCT = 302,
    DIVISION = 303,
    MODULUS = 304,
    INTEGER_DIVISION = 305,
    LEFTPARENTHESIS = 306,
    RIGHTPARENTHESIS = 307,
    UNARY = 308,
    POWER_OF = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "interpreter.y" /* yacc.c:1909  */

	char * identifier;
	char * strings;
	double number;
	bool logic;
	lp::ExpNode *expNode;
	std::list<lp::ExpNode *>  *parameters;
	std::list<lp::Statement *> *stmts;
	lp::Statement *st;
	lp::AST *prog;

#line 121 "interpreter.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
