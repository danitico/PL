/**
	@file interpreter.y
	@brief Grammar file
*/

%{
	#include <iostream>
	#include <string>
	#include <setjmp.h>
	#include <signal.h>

	/* Error recovery functions */
	#include "../error/error.hpp"

	/* Macros for the screen */
	#include "../includes/macros.hpp"

	#include "../ast/ast.hpp"

	/* Table of symbol */
	#include "../table/table.hpp"
	#include "../table/numericVariable.hpp"
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

	extern std::string progname; //!<  Program name
	/*
	jhmp_buf
	This is an array type capable of storing the information of a calling environment to be restored later.
	This information is filled by calling macro setjmp and can be restored by calling function longjmp.
	*/
	jmp_buf begin; //!<  It enables recovery of runtime errors

	extern lp::Table table; //!< Extern Table of Symbols

	extern lp::AST *root; //!< External root of the abstract syntax tree AST
%}

%error-verbose

%start program

%union {
	char * identifier;
	char * strings;
	double number;
	bool logic;
	lp::ExpNode *expNode;
	std::list<lp::ExpNode *>  *parameters;
	std::list<lp::Statement *> *stmts;
	lp::Statement *st;
	lp::AST *prog;
}

/* Type of the non-terminal symbols */
// New in example 17: cond
%type <expNode> exp cond

/* New in example 14 */
%type <parameters> listOfExp restOfListOfExp

%type <stmts> stmtlist

// New in example 17: if, while, block
%type <st> stmt asgn print read if while for repeat

%type <prog> program

/////////////////////////////////

%token AT HASHTAG

%token SEMICOLON

%token ERASE PLACE REPETITION UNTIL FOR FROM STEP DO END_FOR WHILE END_WHILE IF THEN ELSE END_IF READ READ_STRING WRITE WRITE_STRING

%right ASSIGNMENT

%token COMMA

%token <number> NUMBER

%token <logic> BOOL

%token <strings> STRINGS

%token <identifier> VARIABLE UNDEFINED

%left OR
%left AND
%nonassoc LESS_THAN LESS_OR_EQUAL GREATER_THAN GREATER_OR_EQUAL EQUAL NOT_EQUAL
%left NOT

%left CONCATENATE

%left PLUS MINUS
%left PRODUCT DIVISION MODULUS INTEGER_DIVISION

%left LEFTPARENTHESIS RIGHTPARENTESIS

%nonassoc UNARY

%right POWER_OF


%%

//! @name Grammar rules

program: stmtlist
			{
				$$ = new lp::AST($1);
				root = $$;
			}
;

stmtlist:
			{
				$$ = new std::list<lp::Statement *>();
			}

			| stmtlist stmt
			{
				$$ = $1;
				$$->push_back($2);

				if(interactiveMode){
					$2->evaluate();
				}
			}

			| stmtlist error
			{
				$$ = $1;

				yyclearin;
			}
;

stmt: SEMICOLON
		{
			$$ = new lp::EmptyStmt();
		}

		| asgn SEMICOLON
		{
			$$ = $1;
		}

		| para SEMICOLON
		{
			$$ = $1;
		}

		| repetir SEMICOLON
		{
			$$ = $1;
		}

		| mientras SEMICOLON
		{
			$$ = $1;
		}

		| si SEMICOLON
		{
			$$ = $1;
		}

		| print SEMICOLON
		{
			$$ = $1;
		}

		| read SEMICOLON
		{
			$$ = $1;
		}

		| borrar SEMICOLON
		{
			$$ = $1;
		}

		| lugar SEMICOLON
		{
			$$ = $1
		}
;

exp:	NUMBER
		{
			// Create a new number node
			$$ = new lp::NumberNode($1);
		}

	|	STRINGS
		{
			$$ = new lp::StringsNode($1);
		}

	| 	exp PLUS exp
		{
			// Create a new plus node
			 $$ = new lp::PlusNode($1, $3);
		 }

	| 	exp MINUS exp
      	{
			// Create a new minus node
			$$ = new lp::MinusNode($1, $3);
		}

	| 	exp MULTIPLICATION exp
		{
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  // Create a new division node
		  $$ = new lp::DivisionNode($1, $3);
	   }

	| 	LPAREN exp RPAREN
       	{
		    // just copy up the expression node
			$$ = $2;
		 }

  	| 	PLUS exp %prec UNARY
		{
		  // Create a new unary plus node
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS exp %prec UNARY
		{
		  // Create a new unary minus node
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	exp MODULO exp
		{
		  // Create a new modulo node
		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER exp
     	{
		  // Create a new power node
  		  $$ = new lp::PowerNode($1, $3);
		}

	 | VARIABLE
		{
		  // Create a new variable node
		  $$ = new lp::VariableNode($1);
		}

	| exp GREATER_THAN exp
	 	{
		  // Create a new "greater than" node
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp
	 	{
		  // Create a new "greater or equal" node
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp
	 	{
		  // Create a new "less than" node
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp
	 	{
		  // Create a new "less or equal" node
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp
	 	{
		  // Create a new "equal" node
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp
	 	{
		  // Create a new "not equal" node
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp
	 	{
		  // Create a new "logic and" node
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp
	 	{
		  // Create a new "logic or" node
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp
	 	{
		  // Create a new "logic negation" node
 			$$ = new lp::NotNode($2);
		}
;

asgn: VARIABLE ASSIGNMENT exp
	{
		$$ = new lp::AssignmentStmt($1, $3);
	}
;

para: FOR VARIABLE FROM exp UNTIL exp DO stmtlist END_FOR
	{
		//crear nodo AST
	}

	| FOR VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist END_FOR
	{
		// Crear nodo AST
	}
;

repetir: REPETITION stmtlist UNTIL cond
		{
			//crear nodo AST
		}
;

mientras: WHILE cond DO stmtlist END_WHILE
		{
			//crear nodo AST
		}
;

si: IF cond THEN stmtlist END_IF
	{
		//CREAR NODO AST
	}

	| IF cond THEN stmtlist ELSE stmtlist END_IF
	{
		//crear nodo ast
	}
;

print: WRITE LEFTPARENTHESIS exp RIGHTPARENTESIS
	{
		$$ = new lp::PrintStmt($3);
	}

	| WRITE_STRING LEFTPARENTHESIS exp RIGHTPARENTESIS
	{
		//nodo ast
	}
;

read: READ LEFTPARENTHESIS VARIABLE RIGHTPARENTESIS
	{
		//nodo ast
	}

	| READ_STRING LEFTPARENTHESIS VARIABLE RIGHTPARENTESIS
	{

	}
;

borrar: ERASE
	{
		//utilizar macros para borrar la pantalla
	}
;

lugar: PLACE LEFTPARENTHESIS exp COMMA exp RIGHTPARENTESIS
	{
		//utilizar macros para situar el puntero
	}
;

cond: LEFTPARENTHESIS exp RIGHTPARENTESIS
	{
		$$ = $2;
	}
;
