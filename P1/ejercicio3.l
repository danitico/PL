%{
#include <stdio.h>
#include "ejemplo3.h"
%}

digito      [0-9]
letra       [a-zA-Z]

identificador     {letra}({letra}|{digito}|\_({letra}|{digito}))*

numero            {digito}+(\.{digito}+)?(E[+\-]?{digito}+)?

cadena            "'"({letra}|[[:space:]]|"\'"({letra}|[[:space:]])*"\'")*"'"

%x ESTADO_COMENTARIO

%%

(?i:inicio) 	   {printf("\n Palabra reservada: %s --> token %d\n", yytext,INICIO);}
(?i:fin)          {printf("\n Palabra reservada: %s --> token %d\n", yytext,FIN);}
(?i:leer)         {printf("\n Palabra reservada: %s --> token %d\n", yytext,LEER);}
(?i:escribir)     {printf("\n Palabra reservada: %s --> token %d\n", yytext,ESCRIBIR);}
(?i:si)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,SI);}
(?i:entonces)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,ENTONCES);}
(?i:si_no)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,SI_NO);}
(?i:fin_si)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,FIN_SI);}
(?i:mientras)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,MIENTRAS);}
(?i:hacer)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,HACER);}
(?i:fin_mientras) {printf("\n Palabra reservada: %s --> token %d\n", yytext,FIN_MIENTRAS);}
(?i:repetir)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,REPETIR);}
(?i:hasta_que)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,HASTA_QUE);}
(?i:para)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,PARA);}
(?i:desde)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,DESDE);}
(?i:hasta)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,HASTA);}
(?i:paso)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,PASO);}
(?i:fin_para)           {printf("\n Palabra reservada: %s --> token %d\n", yytext,FIN_PARA);}

{identificador}    {printf("\n Identificador: %s --> token %d\n", yytext, ID);}

{numero}          {printf("\n Número: %s --> token %d\n", yytext, NUMERO);}

{cadena}          {printf("\n Cadena: %s --> token %d\n", yytext,CADENA);}

":="              {printf("\n Operador Asignación: %s --> token %d\n", yytext, ASIGNACION);}

"+"               {printf("\n Operador SUMA: %s --> token %d\n", yytext, SUMA);}

"-"               {printf("\n Operador RESTA: %s --> token %d\n", yytext, RESTA);}

"*"               {printf("\n Operador PRODUCTO: %s --> token %d\n", yytext, PRODUCTO);}

"/"               {printf("\n Operador DIVISION: %s --> token %d\n", yytext, DIVISION);}

"__mod"           {printf("\n Operador MODULO: %s --> token %d\n", yytext, MODULO);}

"**"              {printf("\n Operador POTENCIA: %s --> token %d\n", yytext, POTENCIA);}

"||"              {printf("\n Operador CONCATENACION: %s --> token %d\n", yytext, CONCATENACION);}

"<"               {printf("\n Operador MENOR_QUE: %s --> token %d\n", yytext, MENOR_QUE);}

"<="              {printf("\n Operador MENOR_IGUAL_QUE: %s --> token %d\n", yytext, MENOR_IGUAL_QUE);}

">"               {printf("\n Operador MAYOR_QUE: %s --> token %d\n", yytext, MAYOR_QUE);}

">="              {printf("\n Operador MAYOR_IGUAL_QUE: %s --> token %d\n", yytext, MAYOR_IGUAL_QUE);}

"=="              {printf("\n Operador IGUAL: %s --> token %d\n", yytext, IGUAL);}

"<>"              {printf("\n Operador DISTINTO: %s --> token %d\n", yytext, DISTINTO);}

".o."             {printf("\n Operador DISYUNCION_LOGICA: %s --> token %d\n", yytext, DISYUNCION_LOGICA);}

".y."             {printf("\n Operador CONJUNCION_LOGICA: %s --> token %d\n", yytext, CONJUNCION_LOGICA);}

".no."            {printf("\n Operador NEGACION_LOGICA: %s --> token %d\n", yytext, NEGACION_LOGICA);}

"/*"	      	   {BEGIN ESTADO_COMENTARIO;printf("\nEmpieza comentario\n");}

<ESTADO_COMENTARIO>"/*"/(.|\n)  {printf("\n No se pueden anidar comentarios\n");}

<ESTADO_COMENTARIO>"*/"    {BEGIN 0;printf("\nTermina comentario\n");}

<ESTADO_COMENTARIO>.|\n    {ECHO;}

.*     {printf("\n No lo reconozco -> %s", yytext);}

%%

extern FILE *yyin;

int main(int argc, char **argv){
   yyin=fopen(argv[1], "r");

   yylex();

   fclose(yyin);
   return 0;
}
