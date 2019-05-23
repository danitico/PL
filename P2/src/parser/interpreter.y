/**
	@file interpreter.y
	@brief Grammar file
*/

%{
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
	std::list<lp::CasesStmt *> *cases;
	lp::Statement *st;
	lp::AST *prog;
}

/* Type of the non-terminal symbols */
// New in example 17: cond
%type <expNode> exp cond

/* New in example 14 */
%type <parameters> listOfExp restOfListOfExp

%type <stmts> stmtlist

%type <cases> blocks

// New in example 17: if, while, block
%type <st> stmt asgn print read si mientras para repetir borrar lugar segun ejecutar

%type <prog> program

/////////////////////////////////

%token SEMICOLON COLON

%token ERASE PLACE REPETITION UNTIL FOR FROM STEP DO END_FOR WHILE END_WHILE IF THEN ELSE END_IF READ READ_STRING WRITE WRITE_STRING SWITCH END_SWITCH VALUE BREAK DEFAULT EXECUTE

%right ASSIGNMENT

%token COMMA

%token <number> NUMBER

%token <logic> BOOL

%token <strings> STRINGS

%token <identifier> VARIABLE UNDEFINED CONSTANT BUILTIN

%left OR
%left AND
%nonassoc LESS_THAN LESS_OR_EQUAL GREATER_THAN GREATER_OR_EQUAL EQUAL NOT_EQUAL
%left NOT

%left CONCATENATE

%left SUM_VARIABLE SUBSTRACT_VARIABLE PRODUCT_VARIABLE DIVIDE_VARIABLE
%left PLUS MINUS PLUS_PLUS MINUS_MINUS
%left PRODUCT DIVISION MODULUS INTEGER_DIVISION

%left LEFTPARENTHESIS RIGHTPARENTHESIS

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
					if(manageInteractiveMode == 0){
						$2->evaluate();
						std::cout << std::endl << BIYELLOW << " > " << RESET;
					}
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
			$$ = $1;
		}

		| segun SEMICOLON
		{
			$$ = $1;
		}

		| ejecutar SEMICOLON
		{
			$$ = $1;
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

	|	BOOL
		{
			$$ = new lp::BoolNode($1);
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

	| 	exp PRODUCT exp
		{
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  // Create a new division node
		  $$ = new lp::DivisionNode($1, $3);
	   }

	|	exp INTEGER_DIVISION exp
		{
			$$ = new lp::IntegerDivisionNode($1, $3);
		}

	| 	LEFTPARENTHESIS exp RIGHTPARENTHESIS
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

	|	exp MODULUS exp
		{
		  // Create a new modulo node
		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER_OF exp
     	{
		  // Create a new power node
  		  $$ = new lp::PowerNode($1, $3);
		}

	| VARIABLE
		{
		  // Create a new variable node
		  $$ = new lp::VariableNode($1);
		}

	| CONSTANT
		{
			// Create a new Constant node

			$$ = new lp::ConstantNode($1);
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

	 | exp CONCATENATE exp
	 	{
			$$ = new lp::ConcatenateNode($1, $3);
		}

	 | BUILTIN LEFTPARENTHESIS listOfExp RIGHTPARENTHESIS
	 	{
			lp::Builtin *f = (lp::Builtin *) table.getSymbol($1);

			if(f->getNParameters() == (int) $3->size()){
				switch(f->getNParameters()){
					case 0:
						{
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							lp::ExpNode *e = $3->front();

							$$ = new lp::BuiltinFunctionNode_1($1, e);
						}
						break;

					case 2:
						{
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							$$ = new lp::BuiltinFunctionNode_2($1, e1, e2);
						}
						break;

					default:
						execerror("Syntax error: too many parameters for function ", $1);
				}
			}
			else{
				execerror("Syntax error: incompatible number of parameters for function", $1);
			}
		}
;

asgn: VARIABLE ASSIGNMENT exp
	{
		$$ = new lp::AssignmentStmt($1, $3);
	}

	| VARIABLE ASSIGNMENT asgn
	{
		$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
	}

	| VARIABLE SUM_VARIABLE exp
	{
		$$ = new lp::SumVariableStmt($1, $3);
	}

	| VARIABLE SUBSTRACT_VARIABLE exp
	{
		$$ = new lp::SubstractVariableStmt($1, $3);
	}

	| VARIABLE PRODUCT_VARIABLE exp
	{
		$$ = new lp::ProductVariableStmt($1, $3);
	}

	| VARIABLE DIVIDE_VARIABLE exp
	{
		$$ = new lp::DivideVariableStmt($1, $3);
	}

	| VARIABLE PLUS_PLUS
	{
		$$ = new lp::PlusPlusStmt($1);
	}

	| PLUS_PLUS VARIABLE
	{
		$$ = new lp::PlusPlusStmt($2);
	}

	| VARIABLE MINUS_MINUS
	{
		$$ = new lp::MinusMinusStmt($1);
	}

	| MINUS_MINUS VARIABLE
	{
		$$ = new lp::MinusMinusStmt($2);
	}

	| CONSTANT ASSIGNMENT exp
	{
		execerror("Semantic error in assignment: it is not allowed to modify a constant ", $1);
	}

	| CONSTANT ASSIGNMENT asgn
	{
		execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",$1);
	}
;

para: FOR VARIABLE FROM exp UNTIL exp DO stmtlist END_FOR
	{
		$$ = new lp::ForStmt($2, $8, $4, $6);
	}

	| FOR VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist END_FOR
	{
		$$ = new lp::ForStmt($2, $10, $4, $6, $8);
	}
;

repetir: REPETITION stmtlist UNTIL cond
		{
			$$ = new lp::RepeatStmt($2, $4);
		}
;

mientras: WHILE cond DO stmtlist END_WHILE
		{
			$$ = new lp::WhileStmt($2, $4);
		}
;

si: IF cond THEN stmtlist END_IF
	{
		$$ = new lp::IfStmt($2, $4);
	}

	| IF cond THEN stmtlist ELSE stmtlist END_IF
	{
		$$ = new lp::IfStmt($2, $4, $6);
	}
;

print: WRITE LEFTPARENTHESIS exp RIGHTPARENTHESIS
	{
		$$ = new lp::PrintStmt($3);
	}

	| WRITE_STRING LEFTPARENTHESIS exp RIGHTPARENTHESIS
	{
		$$ = new lp::PrintStringStmt($3);
	}
;

read: READ LEFTPARENTHESIS VARIABLE RIGHTPARENTHESIS
	{
		$$ = new lp::ReadStmt($3);
	}

	| READ_STRING LEFTPARENTHESIS VARIABLE RIGHTPARENTHESIS
	{
		$$ = new lp::ReadStringStmt($3);
	}
;

borrar: ERASE
	{
		$$ = new lp::EraseStmt();
	}
;

lugar: PLACE LEFTPARENTHESIS NUMBER COMMA NUMBER RIGHTPARENTHESIS
	{
		$$ = new lp::PlaceStmt($3, $5);
	}
;

cond: LEFTPARENTHESIS exp RIGHTPARENTHESIS
	{
		$$ = $2;
	}
;

blocks:
		{
			$$ = new std::list<lp::CasesStmt *>();
		}

		| blocks VALUE exp COLON stmtlist
		{
			$$ = $1;
			$$->push_back(new lp::CasesStmt($3, $5, false));
		}

		| blocks VALUE exp COLON stmtlist BREAK SEMICOLON
		{
			$$ = $1;
			$$->push_back(new lp::CasesStmt($3, $5, true));
		}

segun: SWITCH cond blocks DEFAULT COLON stmtlist END_SWITCH
	{
		$$ = new lp::SwitchStmt($2, $3, $6);
	}

	| SWITCH cond blocks END_SWITCH
	{
		$$ = new lp::SwitchStmt($2, $3);
	}
;

ejecutar: EXECUTE LEFTPARENTHESIS STRINGS RIGHTPARENTHESIS
	{
		$$ = new lp::ExecutionStmt($3);
	}

listOfExp:
	{
		$$ = new std::list<lp::ExpNode *>();
	}

	| exp restOfListOfExp
	{
		$$ = $2;

		$$->push_front($1);
	}
;

restOfListOfExp:
	{
		$$ = new std::list<lp::ExpNode *>();
	}

	| COMMA exp restOfListOfExp
	{
		$$ = $3;

		$$->push_front($2);
	}
;
