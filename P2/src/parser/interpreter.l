/**
   @file interpreter.l
   @brief Lexical file
*/
%{
   #include <cstdlib>
   #include "../ast/ast.hpp"
   #include "interpreter.tab.h"
   #include "../error/error.hpp"
   #include "../table/table.hpp"
   #include "../table/numericVariable.hpp"

   extern lp::Table table;
   extern int lineNumber;
%}

/** @name REGULAR EXPRESSIONS */
digit   [0-9]
letter  [a-zA-Z]

identifier        {letter}({letter}|{digit}|\_({letter}|{digit}))*
bad_identifier    ({letter}|{digit})+(\_\_)+({letter}+|{digit}+)?
number            {digit}+(\.{digit}+)?(E[+\-]?{digit}+)?
strings           "'"(.*|"\'".*"\'")*"'"

%x COMMENTARY_1
%x COMMENTARY_2
%x ERROR

%%

(?i:_o)              {return OR;}
(?i:_y)              {return AND;}
(?i:_no)             {return NOT;}

"<"                  {return LESS_THAN;}
"<="                 {return LESS_OR_EQUAL;}
">"                  {return GREATER_THAN;}
">="                 {return GREATER_OR_EQUAL;}
"="                  {return EQUAL;}
"<>"                 {return NOT_EQUAL;}
"||"                 {return CONCATENATE;}
"**"                 {return POWER_OF;}
(?i:_mod)            {return MODULUS;}
(?i:_div)            {return INTEGER_DIVISION;}
"/"                  {return DIVISION;}
"*"                  {return PRODUCT;}
"-"                  {return MINUS;}
"+"                  {return PLUS;}
":="                 {return ASSIGNMENT;}
";"                  {return SEMICOLON;}
","                  {return COMMA;}
"("                  {return LEFTPARENTHESIS;}
")"                  {return RIGHTPARENTHESIS;}

"#"                           {BEGIN(COMMENTARY_1);}
<COMMENTARY_1>[^"#"|^\n]      {;}
<COMMENTARY_1>\n              {lineNumber++;}
<COMMENTARY_1>"#"             {BEGIN(INITIAL);}

"@"                  {BEGIN(COMMENTARY_2);}
<COMMENTARY_2>.      {;}
<COMMENTARY_2>\n     {BEGIN(INITIAL); lineNumber++;}

(?i:_borrar)         {return ERASE;}
(?i:_lugar)          {return PLACE;}

[ \t]                {;}
\n                   {lineNumber++;}

{identifier}   {
                     for(int i=0; yytext[i] != '\0'; i++){
                        yytext[i]=tolower(yytext[i]);
                     }
                     std::string identifier(yytext);
                     yylval.identifier = strdup(yytext);

                     if(! table.lookupSymbol(identifier)){
                        lp::NumericVariable *var = new lp::NumericVariable(identifier, VARIABLE, NUMBER, 0.0);
                        table.installSymbol(var);

                        return VARIABLE;
                     }
                     else{
                        lp::Symbol *s = table.getSymbol(identifier);

                        return s->getToken();
                     }
                  }

{number}          {
                     yylval.number = atof(yytext);
                     return NUMBER;
                  }

{strings}         {
                     std::string aux(yytext);
                     aux = aux.substr(1, aux.size()-2);
                     yylval.strings = strdup(aux.c_str());

                     return STRINGS;
                  }

<<EOF>>  {return 0;}

.        {
            BEGIN(ERROR);
            yymore();
         }

<ERROR>[^0-9+\-*/()\^%\|\: \t\n\;\,\#\@a-zA-Z=<>!&]   {
                                                         yymore();
                                                      }

<ERROR>(.|\n)  {
                  yyless(yyleng-1);
                  warning("Lexical error", yytext);
                  BEGIN(INITIAL);
					}

%%
