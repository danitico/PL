/**
   @file interpreter.l
   @brief Lexical file
*/
%{
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

"#"                  {BEGIN(COMMENTARY_1); return HASHTAG;}
<COMMENTARY_1>.      {;}
<COMMENTARY_1>\n     {lineNumber++;}
<COMMENTARY_1>"#"    {BEGIN(INITIAL); return HASHTAG;}

"@"                  {BEGIN(COMMENTARY_2); return AT;}
<COMMENTARY_2>.      {;}
<COMMENTARY_2>\n     {BEGIN(INITIAL); lineNumber++;}

(?i:repetir)         {return REPETITION;}
(?i:hasta)           {return UNTIL;}
(?i:para)            {return FOR;}
(?i:desde)           {return FROM;}
(?i:paso)            {return STEP;}
(?i:hacer)           {return DO;}
(?i:fin_para)        {return END_FOR;}
(?i:mientras)        {return WHILE;}
(?i:fin_mientras)    {return END_WHILE}
(?i:si)              {return IF;}
(?i:entonces)        {return THEN;}
(?i:si_no)           {return ELSE;}
(?i:fin_si)          {return END_IF;}
(?i:leer)            {return READ;}
(?i:leer_cadena)     {return READ_STRING;}
(?i:escribir)        {return WRITE;}
(?i:escribir_cadena) {return WRITE_STRING;}
(?i:_borrar)         {return ERASE;}
(?i:_lugar)          {return PLACE;}

[ \t]                {;}
\n                   {lineNumber++;}

?i:{identifier}   {

}

{number}          {

}

{strings}         {

}

<<EOF>>  {return 0;}

.        {
            BEGIN(ERROR);
            yymore()
         }

<ERROR>[^0-9+\-*/()\^%\|\: \t\n\;\,\#\@a-zA-Z=<>!&]   {
   yymore();
}
%%
