/*!
	\file    ast.cpp
	\brief   Code of functions of AST class
	\author  Daniel Ranchal Parrado
	\date    2019-05-18
	\version 1.0
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

//
#include "../table/numericVariable.hpp"
#include "../table/stringVariable.hpp"
#include "../table/logicalVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/ipe.tab.h"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType()
{
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::print()
{
  std::cout << "VariableNode: " << this->_id << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::VariableNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric",
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


std::string lp::VariableNode::evaluateString(){
	std::string result="";

	if(this->getType() == STRINGS){
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		result = var->getValue();
	}
	else{
		warning("Runtime error in evaluateString(): the variable is not a string",
					this->_id);
	}

	return result;
	}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::print()
{
  std::cout << "ConstantNode: " << this->_id << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}

int lp::ConstantNode::getType()
{
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}


double lp::ConstantNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric",
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}

bool lp::ConstantNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::print()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber()
{
    return this->_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BoolNode::getType()
{
	return BOOL;
}

void lp::BoolNode::print()
{
  std::cout << "BoolNode: " << this->_boolean << std::endl;
}

bool lp::BoolNode::evaluateBool()
{
    return this->_boolean;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringsNode::getType()
{
	return STRINGS;
}

void lp::StringsNode::print()
{
  std::cout << "StringsNode: " << this->_string << std::endl;
}

std::string lp::StringsNode::evaluateString()
{
    return this->_string;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;

	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;

	if (this->_left->getType() == this->_right->getType())
		result = BOOL;
	else{
		warning("Runtime error: incompatible types for", "Relational Operator");
	}

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;

	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		//
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringOperatorNode::getType()
{
	int result = 0;

	if ( (this->_left->getType() == STRINGS) and (this->_right->getType() == STRINGS))
	{
		result = STRINGS;
	}
	else
		warning("Runtime error: incompatible types for", "String Operator");

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::UnaryMinusNode::print()
{
  std::cout << "UnaryMinusNode: "  << std::endl;
  std::cout << "-";
  this->_exp->print();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::print()
{
  std::cout << "UnaryPlusNode: "  << std::endl;
  this->_exp->print();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::print()
{
  std::cout << "PlusNode: "  << std::endl;
  this->_left->print();
  std::cout << " + ";
  this->_right->print();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::print()
{
  std::cout << "MinusNode: "  << std::endl;
  this->_left->print();
  std::cout << " - ";
  this->_right->print();
}

double lp::MinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::print()
{
	std::cout << "MultiplicationNode: "  << std::endl;
	this->_left->print();
	std::cout << " * ";
	this->_right->print();
}

double lp::MultiplicationNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::print()
{
  std::cout << "DivisionNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::DivisionNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
			exit(-1);
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IntegerDivisionNode::print()
{
  std::cout << "IntegerDivisionNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::IntegerDivisionNode::evaluateNumber()
{
	int result = 0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
			exit(-1);
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::print()
{
  std::cout << "ModuloNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::ModuloNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::print()
{
	std::cout << "PowerNode: "  << std::endl;
	this->_left->print();
	std::cout << " ^ ";
	this->_right->print();
}

double lp::PowerNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::print()
{
	std::cout << "BuiltinFunctionNode_0: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( ) " ;
}

double lp::BuiltinFunctionNode_0::evaluateNumber()
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;

	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::print()
{
	std::cout << "BuiltinFunctionNode_1: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( " ;
	this->_exp->print();
	std::cout << " ) " ;
}

double lp::BuiltinFunctionNode_1::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;

	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::print()
{
	std::cout << "BuiltinFunctionNode_2: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( " ;
	this->_exp1->print();
	std::cout << " , " ;
	this->_exp2->print();
	std::cout << " ) " ;
}

double lp::BuiltinFunctionNode_2::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::print()
{
  std::cout << "GreaterThanNode: " << std::endl;
  this->_left->print();
  std::cout << " > ";
  this->_right->print();
}

bool lp::GreaterThanNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber > rightNumber);
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString > rightString);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared", "operator Greater than");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::print()
{
  std::cout << "GreaterOrEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " >= ";
  this->_right->print();
}

bool lp::GreaterOrEqualNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber >= rightNumber);
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString >= rightString);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared ", "operator Greater or Equal");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or Equal");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::print()
{
  std::cout << "LessThanNode: " << std::endl;
  this->_left->print();
  std::cout << " < ";
  this->_right->print();
}

bool lp::LessThanNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber < rightNumber);
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString < rightString);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared ", "operator Less than");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::print()
{
  std::cout << "LessOrEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " <= ";
  this->_right->print();
}

bool lp::LessOrEqualNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = (leftNumber <= rightNumber);
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString <= rightString);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared ", "operator Less or Equal");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or Equal");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::print()
{
  std::cout << "EqualNode: " << std::endl;
  this->_left->print();
  std::cout << " == ";
  this->_right->print();
}

bool lp::EqualNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = std::abs( (leftNumber - rightNumber)) < ERROR_BOUND ;
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString == rightString);
			}
			break;

			case BOOL:
			{
				bool leftBool, rightBool;
				leftBool = this->_left->evaluateBool();
				rightBool = this->_right->evaluateBool();

				result = (leftBool == rightBool);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared ", "operator Equal");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Equal");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::print()
{
  std::cout << "NotEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " != ";
  this->_right->print();
}

bool lp::NotEqualNode::evaluateBool()
{
	bool result = false;

	if(this->getType() == BOOL){
		switch (this->_left->getType()) {
			case NUMBER:
			{
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				result = std::abs( (leftNumber - rightNumber)) >= ERROR_BOUND ;
			}
			break;

			case STRINGS:
			{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				result = (leftString != rightString);
			}
			break;

			case BOOL:
			{
				bool leftBool, rightBool;
				leftBool = this->_left->evaluateBool();
				rightBool = this->_right->evaluateBool();

				result = (leftBool != rightBool);
			}
			break;

			default:
				warning("Runtime error: This type of variable cannot be compared ", "operator Not Equal");
		}
	}
	else{
		warning("Runtime error: incompatible types of parameters for ", "operator Not Equal");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::print()
{
  std::cout << "AndNode: " << std::endl;
  this->_left->print();
  std::cout << " && ";
  this->_right->print();
}

bool lp::AndNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::print()
{
  std::cout << "OrNode: " << std::endl;
  this->_left->print();
  std::cout << " _o ";
  this->_right->print();
}

bool lp::OrNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::print()
{
  std::cout << "NotNode: " << std::endl;
  std::cout << " ! ";
  this->_exp->print();
}

bool lp::NotNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConcatenateNode::print()
{
  std::cout << "ConcatenateNode: " << std::endl;
  this->_left->print();
  std::cout << " || ";
  this->_right->print();
}

std::string lp::ConcatenateNode::evaluateString()
{
	std::string result = "";

	if (this->getType() == STRINGS)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Concatenate");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::print()
{
  std::cout << "assignment_node: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}

void lp::AssignmentStmt::evaluate()
{
	/* Get the identifier in the table of symbols as Variable */
	/*
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable
					// with the type NUMBER and the value
					lp::NumericVariable *v = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,value);
					table.installSymbol(v);
				}
			}
			break;

			case BOOL:
			{
				bool value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable
					// with the type BOOL and the value
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;

			case STRINGS:
			{
				std::string value;

				value = this->_exp->evaluateString();

				if(firstVar->getType() == STRINGS){
					lp::StringVariable *v = (lp::StringVariable * ) table.getSymbol(this->_id);
					v->setValue(value);
				}
				else{
					table.eraseSymbol(this->_id);

					lp::StringVariable *v = new lp::StringVariable(this->_id, VARIABLE, STRINGS, value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == NUMBER)
				{
				/* Get the identifier of the first variable in the table of symbols as NumericVariable */
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the first variable from the table of symbols
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable
					// with the type NUMBER and the value of the previous variable
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == BOOL)
				{
				/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not BOOL
				else
				{
					// Delete the first variable from the table of symbols
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as LogicalVariable
					// with the type BOOL and the value of the previous variable
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case STRINGS:
			{
				lp::StringVariable *secondVar = (lp::StringVariable *) table.getSymbol(this->_asgn->_id);
				if(firstVar->getType() == STRINGS){
					lp::StringVariable *firstVar = (lp::StringVariable *) table.getSymbol(this->_id);

					firstVar->setValue(secondVar->getValue());
				}
				else{
					table.eraseSymbol(this->_id);

					lp::StringVariable *firstVar = new lp::StringVariable(this->_id,
															VARIABLE, STRINGS, secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::SumVariableStmt::print()
{
  std::cout << "SumVariableStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}

void lp::SumVariableStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(this->_exp->getType())
	{
		case NUMBER:
		{
			// Check the type of the first varible
			if (firstVar->getType() == NUMBER)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

				// Assignment the value to the identifier in the table of symbols
				v->setValue(v->getValue() + this->_exp->evaluateNumber());
			}
				// The type of variable is not NUMBER
			else
			{
				warning("Runtime error: incompatible type of variable for ", "SumVariableAssigment");
			}
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "SumVariableAssigment");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::SubstractVariableStmt::print()
{
  std::cout << "SubstractVariableStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}

void lp::SubstractVariableStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(this->_exp->getType())
	{
		case NUMBER:
		{
			// Check the type of the first varible
			if (firstVar->getType() == NUMBER)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

				// Assignment the value to the identifier in the table of symbols
				v->setValue(v->getValue() - this->_exp->evaluateNumber());
			}
				// The type of variable is not NUMBER
			else
			{
				warning("Runtime error: incompatible type of variable for ", "SubstractVariableStmt");
			}
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "SubstractVariableStmt");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ProductVariableStmt::print()
{
  std::cout << "ProductVariableStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}

void lp::ProductVariableStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(this->_exp->getType())
	{
		case NUMBER:
		{
			// Check the type of the first varible
			if (firstVar->getType() == NUMBER)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

				// Assignment the value to the identifier in the table of symbols
				v->setValue(v->getValue() * this->_exp->evaluateNumber());
			}
				// The type of variable is not NUMBER
			else
			{
				warning("Runtime error: incompatible type of variable for ", "ProductVariableStmt");
			}
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "ProductVariableStmt");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivideVariableStmt::print()
{
  std::cout << "DivideVariableStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}

void lp::DivideVariableStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(this->_exp->getType())
	{
		case NUMBER:
		{
			// Check the type of the first varible
			if (firstVar->getType() == NUMBER)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

				if(std::abs(this->_exp->evaluateNumber()) > ERROR_BOUND){
					v->setValue(v->getValue() / this->_exp->evaluateNumber());
				}
				else{
					warning("Runtime error", "Division by zero");
					exit(-1);
				}
			}
				// The type of variable is not NUMBER
			else
			{
				warning("Runtime error: incompatible type of variable for ", "DivideVariableStmt");
			}
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "DivideVariableStmt");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusPlusStmt::print()
{
  std::cout << "PlusPlusStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  std::cout << std::endl;
}

void lp::PlusPlusStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(firstVar->getType())
	{
		case NUMBER:
		{
			// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

			v->setValue(v->getValue() + 1);
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "PlusPlusStmt");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusMinusStmt::print()
{
  std::cout << "MinusMinusStmt: "  << std::endl;
  std::cout << this->_id << " = ";
  std::cout << std::endl;
}

void lp::MinusMinusStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	switch(firstVar->getType())
	{
		case NUMBER:
		{
			// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

			v->setValue(v->getValue() - 1);
		}
		break;

		default:
			warning("Runtime error: incompatible type of expression for ", "MinusMinusStmt");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::print()
{
  std::cout << "PrintStmt: "  << std::endl;
  std::cout << " escribir ";
  this->_exp->print();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate()
{
	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber();
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "verdadero";
			else
				std::cout << "falso";

			break;

		default:
			warning("Runtime error: incompatible type for ", "escribir");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStringStmt::print()
{
  std::cout << "PrintStringStmt: "  << std::endl;
  std::cout << " escribir_cadena ";
  this->_exp->print();
  std::cout << std::endl;
}


void lp::PrintStringStmt::evaluate()
{
	std::string printed;
	switch(this->_exp->getType())
	{
		case STRINGS:
				printed = _exp->evaluateString();
				for(unsigned i=0; i<printed.size(); i++){
					if(printed[i] == '\\'){
						if(printed[i+1] == 'n'){
							std::cout << std::endl;
						}
						else if(printed[i+1] == 't'){
							std::cout << "\t";
						}
						else if(printed[i+1] == '\\'){
							std::cout << "\\";
						}
						i+=1;
					}
					else{
						std::cout << printed[i];
					}
				}
				break;

		default:
			warning("Runtime error: incompatible type for ", "escribir_cadena");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::print()
{
  std::cout << "ReadStmt: "  << std::endl;
  std::cout << " leer (" << this->_id << ")";
  std::cout << std::endl;
}


void lp::ReadStmt::evaluate()
{
	double value;
	std::cin >> value;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is NUMBER
	if (var->getType() == NUMBER)
	{
		/* Get the identifier in the table of symbols as NumericVariable */
		lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

		/* Assignment the read value to the identifier */
		n->setValue(value);
	}
	// The type of variable is not NUMBER
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as NumericVariable
		// with the type NUMBER and the read value
		lp::NumericVariable *n = new lp::NumericVariable(this->_id,
									  VARIABLE,NUMBER,value);

		table.installSymbol(n);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStringStmt::print()
{
  std::cout << "ReadStringStmt: "  << std::endl;
  std::cout << " leer_cadena (" << this->_id << ")";
  std::cout << std::endl;
}


void lp::ReadStringStmt::evaluate()
{
	std::string value;
	std::cin >> value;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is STRINGS
	if (var->getType() == STRINGS)
	{
		/* Get the identifier in the table of symbols as NumericVariable */
		lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);

		/* Assignment the read value to the identifier */
		n->setValue(value);
	}
	// The type of variable is not STRING
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as StringVariable
		// with the type NUMBER and the read value
		lp::StringVariable *n = new lp::StringVariable(this->_id,
									  VARIABLE,STRINGS,value);

		table.installSymbol(n);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::print()
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate()
{
  // Empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::IfStmt::print()
{
  std::cout << "IfStmt: "  << std::endl;
  // Condition
  this->_cond->print();

  // Consequent
  std::list<Statement *>::iterator stmtIter1;

  for (stmtIter1 = this->_stmts1->begin(); stmtIter1 != this->_stmts1->end(); stmtIter1++)
  {
	(*stmtIter1)->print();
  }

 // The alternative is printed if exists
	if (this->_stmts2 != NULL){
		std::list<Statement *>::iterator stmtIter2;

		for (stmtIter2 = this->_stmts2->begin(); stmtIter2 != this->_stmts2->end(); stmtIter2++)
		{
		(*stmtIter2)->print();
		}
	}

  std::cout << std::endl;
}


void lp::IfStmt::evaluate()
{
	if(this->_cond->getType() == BOOL){
		// If the condition is true,
		if (this->_cond->evaluateBool() == true ){
			// the consequent is run
			std::list<Statement *>::iterator stmtIter1;
			for (stmtIter1 = this->_stmts1->begin(); stmtIter1 != this->_stmts1->end(); stmtIter1++){
			 	(*stmtIter1)->evaluate();
			}
		}
		// Otherwise, the alternative is run if exists
		else if (this->_stmts2 != NULL){
			std::list<Statement *>::iterator stmtIter2;
			for (stmtIter2 = this->_stmts2->begin(); stmtIter2 != this->_stmts2->end(); stmtIter2++){
				(*stmtIter2)->evaluate();
			}
		}
	}
	else{
		warning("Runtime error: incompatible type for ", "Condition");
	}
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::WhileStmt::print()
{
  std::cout << "WhileStmt: "  << std::endl;
  // Condition
  this->_cond->print();

  // Body of the while loop
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
	  (*stmtIter)->print();
  }

  std::cout << std::endl;
}


void lp::WhileStmt::evaluate()
{
  if(this->_cond->getType() == BOOL){
	  while (this->_cond->evaluateBool() == true)
	  {
		  std::list<Statement *>::iterator stmtIter;

		  for(stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
			  (*stmtIter)->evaluate();
		  }
	  }
  }
  else{
	  warning("Runtime error: incompatible type for ", "Condition");
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ForStmt::print()
{
  std::cout << "ForStmt: "  << std::endl;
  // Variable
  std::cout << this->_variable << std::endl;

  // Body of the while loop
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
	  (*stmtIter)->print();
  }

  this->_inicio->print();

  this->_fin->print();

  if(this->_step != NULL){
	  this->_step->print();
  }


  std::cout << std::endl;
}


void lp::ForStmt::evaluate()
{
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_variable);

	lp::NumericVariable *n;
	if(firstVar->getType() != NUMBER){
		table.eraseSymbol(this->_variable);

		n = new NumericVariable(this->_variable, VARIABLE, NUMBER, 0.0);
		table.installSymbol(n);
	}
	else{
		n = (lp::NumericVariable *) table.getSymbol(this->_variable);
	}

	if(this->_inicio->getType() != NUMBER){
		warning("Runtime error: incompatible type for ", "Initial Value");
		return;
	}

	int inicio = this->_inicio->evaluateNumber();

	if(this->_fin->getType() != NUMBER){
		warning("Runtime error: incompatible type for ", "Final Value");
		return;
	}

	int final = this->_fin->evaluateNumber();

	int step;
	if(this->_step == NULL){
		step = 1;
	}
	else if(this->_step->getType() != NUMBER){
		warning("Runtime error: incompatible type for ", "Step Value");
		return;
	}

	if(this->_step != NULL){
		step = this->_step->evaluateNumber();
	}
	else{
		step = 1;
	}


	if(inicio > final && step > 0){
		warning("Runtime error: Infinite Loop", "inicio > final and step > 0");
		exit(-1);
	}
	else if(inicio < final && step < 0){
		warning("Runtime error: Infinite Loop", "inicio < final and step < 0");
		exit(-1);
	}
	else if(step == 0){
		warning("Runtime error: Infinite Loop", "step value is zero");
		exit(-1);
	}

	//We set the numeric variable to the initial value
	n->setValue(inicio);
	std::list<Statement *>::iterator stmtIter;

	for(; inicio <= final; inicio+=step){
		for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
		  (*stmtIter)->evaluate();
		}

		n->setValue(n->getValue() + step);
	}

	//We erase the variable because it is a temporal one
	table.eraseSymbol(this->_variable);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::RepeatStmt::print()
{
  std::cout << "RepeatStmt: "  << std::endl;

  // Body of the while loop
  std::list<Statement *>::iterator stmtIter;
  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
	  (*stmtIter)->print();
  }

  this->_cond->print();

  std::cout << std::endl;
}

void lp::RepeatStmt::evaluate(){
	if(this->_cond->getType() == BOOL){
		do{
			std::list<Statement *>::iterator stmtIter;
			for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
				(*stmtIter)->evaluate();
			}

		} while(!this->_cond->evaluateBool());
	}
	else{
		warning("Runtime error: incompatible type for ", "Condition");
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::SwitchStmt::print()
{
	std::cout << "SwitchStmt: "  << std::endl;

	this->_cond->print();

	if(this->_blocks->size() != 0){
		std::list<CasesStmt *>::iterator stmtIter;
		for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
		{
		  (*stmtIter)->print();
		}
	}

	if(this->_defaultCase != NULL){
		std::list<Statement *>::iterator stmtIter;
		for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++)
		{
		  (*stmtIter)->print();
		}
	}

	std::cout << std::endl;
}

bool lp::SwitchStmt::sameType(){
	if(this->_blocks->size() == 0){
		return true;
	}
	else{
		int type = this->_cond->getType();

		std::list<CasesStmt *>::iterator stmtIter;
		for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++){
			if((*stmtIter)->getCondition()->getType() != type){
				return false;
			}
		}

		return true;
	}
}

void lp::SwitchStmt::evaluate(){
	bool boolean; double number; std::string strings;

	if(!sameType()){
		if(this->_cond->getType() == NUMBER){
			warning("The case Statements have not the same type as the condition of switch Statement", "NUMBER");
			exit(-1);
		}
		else if(this->_cond->getType() == BOOL){
			warning("The case Statements have not the same type as the condition of switch Statement", "BOOL");
			exit(-1);
		}
		else if(this->_cond->getType() == STRINGS){
			warning("The case Statements have not the same type as the condition of switch Statement", "STRINGS");
			exit(-1);
		}
	}

	if(this->_blocks->size() == 0){
		std::list<Statement *>::iterator stmtIter;
		for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++)
		{
		  (*stmtIter)->evaluate();
		}
	}

	else if(this->_defaultCase == NULL){
		if(this->_cond->getType() == NUMBER){
			bool goOn=false;
			number=this->_cond->evaluateNumber();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if(std::abs( (number - (*stmtIter)->getCondition()->evaluateNumber())) < ERROR_BOUND || goOn){
					(*stmtIter)->evaluate();

					if((*stmtIter)->getBreaking()){
						break;
					}
					else{
						goOn=true;
					}
				}
			}
		}

		if(this->_cond->getType() == BOOL){
			bool goOn=false;
			boolean=this->_cond->evaluateBool();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if ( boolean == (*stmtIter)->getCondition()->evaluateBool() || goOn) {
					(*stmtIter)->evaluate();

					if((*stmtIter)->getBreaking()){
						break;
					}
					else{
						goOn=true;
					}
				}
			}
		}

		if(this->_cond->getType() == STRINGS){
			bool goOn=false;
			strings=this->_cond->evaluateString();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if ( strings == (*stmtIter)->getCondition()->evaluateString() || goOn) {
					(*stmtIter)->evaluate();

					if((*stmtIter)->getBreaking()){
						break;
					}
					else{
						goOn=true;
					}
				}
			}
		}
	}

	else{
		if(this->_cond->getType() == NUMBER){
			bool hasBeenExecuted = false, goOn=false;
			number=this->_cond->evaluateNumber();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if(std::abs( (number - (*stmtIter)->getCondition()->evaluateNumber())) < ERROR_BOUND || goOn){
					(*stmtIter)->evaluate();
					hasBeenExecuted = true;

					if((*stmtIter)->getBreaking()){
						goOn=false;
						break;
					}
					else{
						goOn=true;
					}
				}
			}

			if(!hasBeenExecuted || goOn){
				std::list<Statement *>::iterator stmtIter;
				for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++)
				{
				  (*stmtIter)->evaluate();
				}
			}
		}

		if(this->_cond->getType() == BOOL){
			bool hasBeenExecuted = false, goOn=false;
			boolean=this->_cond->evaluateBool();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if ( boolean == (*stmtIter)->getCondition()->evaluateBool() || goOn){
					(*stmtIter)->evaluate();
					hasBeenExecuted = true;

					if((*stmtIter)->getBreaking()){
						goOn=false;
						break;
					}
					else{
						goOn=true;
					}
				}
			}

			if(!hasBeenExecuted || goOn){
				std::list<Statement *>::iterator stmtIter;
				for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++)
				{
				  (*stmtIter)->evaluate();
				}
			}
		}

		if(this->_cond->getType() == STRINGS){
			bool hasBeenExecuted = false, goOn=false;
			strings=this->_cond->evaluateString();

			std::list<CasesStmt *>::iterator stmtIter;
			for (stmtIter = this->_blocks->begin(); stmtIter != this->_blocks->end(); stmtIter++)
			{
				if ( strings == (*stmtIter)->getCondition()->evaluateString() || goOn){
					(*stmtIter)->evaluate();
					hasBeenExecuted = true;

					if((*stmtIter)->getBreaking()){
						goOn=false;
						break;
					}
					else{
						goOn=true;
					}
				}
			}

			if(!hasBeenExecuted || goOn){
				std::list<Statement *>::iterator stmtIter;
				for (stmtIter = this->_defaultCase->begin(); stmtIter != this->_defaultCase->end(); stmtIter++)
				{
				  (*stmtIter)->evaluate();
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::CasesStmt::print()
{
  std::cout << "CasesStmt: "  << std::endl;

  this->_cond->print();

  // Body of the while loop
  std::list<Statement *>::iterator stmtIter;
  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
	  (*stmtIter)->print();
  }

  std::cout << "Break -> " << this->_breaking << std::endl;

  std::cout << std::endl;
}

void lp::CasesStmt::evaluate(){
	std::list<Statement *>::iterator stmtIter;
	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
		(*stmtIter)->evaluate();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EraseStmt::print()
{
  std::cout << "EraseStmt "  << std::endl;
}

void lp::EraseStmt::evaluate()
{
  std::cout << CLEAR_SCREEN;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlaceStmt::print()
{
  std::cout << "Place Stmt "  << std::endl;
  std::cout << "x -> " << this->_x << std::endl;
  std::cout << "y -> " << this->_y << std::endl;
}

void lp::PlaceStmt::evaluate()
{
  PLACE((int)this->_x, (int)this->_y);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ExecutionStmt::print()
{
  std::cout << "Execution Stmt "  << std::endl;
  std::cout << "File -> " << this->_file << std::endl;
}

void lp::ExecutionStmt::evaluate()
{
	if(this->_file == ""){
		execerror("Syntax error: The name of the file cannot be blank", "this->_file");
	}
	else{
		std::string command = "./ipe.exe " + this->_file;
		if(system(command.c_str()) != 0){
			execerror("Something went bad when executing file", this->_file);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ExitStmt::print()
{
  std::cout << "Exit Stmt "  << std::endl;
}

void lp::ExitStmt::evaluate()
{
	exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::print()
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++)
  {
     (*stmtIter)->print();
  }
}



void lp::AST::evaluate()
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++)
  {
    (*stmtIter)->evaluate();
  }
}
