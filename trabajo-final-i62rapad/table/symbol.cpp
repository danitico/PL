/*!
	\file    symbol.cpp
	\brief   Code of some functions of Symbol class
	\author  Daniel Ranchal Parrado
	\date    2019-05-18
	\version 1.0
*/


#include "symbol.hpp"

// The calificator lp:: y std::  have been use instead of the following statements
//using namespace lp;
//using namespace std;


/*
	\name Relational operators
*/


bool lp::Symbol::operator==(const lp::Symbol & s) const
	{
		return ( this->getName() == s.getName() );
	}


bool lp::Symbol::operator <(const lp::Symbol & s) const
{
   if ( this->getName() < s.getName() )
        return true;
  else
   	  return false;
}
