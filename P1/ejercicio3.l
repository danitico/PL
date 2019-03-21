%{
#include <stdio.h>
#include "ejercicio3.h"
%}
digito      [0-9]
letra       [a-zA-Z]

identificador     {letra}({letra}|{digito}|\_({letra}|{digito}))*

malidentificador  ({letra}|{digito})+(\_\_)+({letra}+|{digito}+)?

numero            {digito}+(\.{digito}+)?(E[+\-]?{digito}+)?

cadena            "'"(.*|"\'".*"\'")*"'"

%x ESTADO_COMENTARIO
%x ESTADO_COMENTARIO_1
%x PARENTESIS

%%

(?i:inicio) 	   {printf("\n Palabra reservada: %s --> token %d\n", yytext,INICIO);}
(?i:fin)          {printf("\n Palabra reservada: %s --> token %d\n", yytext,FIN);}
(?i:mod)          {printf("\n Palabra reservada: %s --> token %d\n", yytext,MOD);}
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

<INITIAL,PARENTESIS>":="              {printf("\n Operador Asignación: %s --> token %d\n", yytext, ASIGNACION);}

<INITIAL,PARENTESIS>"+"               {printf("\n Operador SUMA: %s --> token %d\n", yytext, SUMA);}

<INITIAL,PARENTESIS>"-"               {printf("\n Operador RESTA: %s --> token %d\n", yytext, RESTA);}

<INITIAL,PARENTESIS>"*"               {printf("\n Operador PRODUCTO: %s --> token %d\n", yytext, PRODUCTO);}

<INITIAL,PARENTESIS>"/"               {printf("\n Operador DIVISION: %s --> token %d\n", yytext, DIVISION);}

<INITIAL,PARENTESIS>"__mod"           {printf("\n Operador MODULO: %s --> token %d\n", yytext, MODULO);}

<INITIAL,PARENTESIS>"**"              {printf("\n Operador POTENCIA: %s --> token %d\n", yytext, POTENCIA);}

<INITIAL,PARENTESIS>"||"              {printf("\n Operador CONCATENACION: %s --> token %d\n", yytext, CONCATENACION);}

<INITIAL,PARENTESIS>"<"               {printf("\n Operador MENOR_QUE: %s --> token %d\n", yytext, MENOR_QUE);}

<INITIAL,PARENTESIS>"<="              {printf("\n Operador MENOR_IGUAL_QUE: %s --> token %d\n", yytext, MENOR_IGUAL_QUE);}

<INITIAL,PARENTESIS>">"               {printf("\n Operador MAYOR_QUE: %s --> token %d\n", yytext, MAYOR_QUE);}

<INITIAL,PARENTESIS>">="              {printf("\n Operador MAYOR_IGUAL_QUE: %s --> token %d\n", yytext, MAYOR_IGUAL_QUE);}

<INITIAL,PARENTESIS>"=="              {printf("\n Operador IGUAL: %s --> token %d\n", yytext, IGUAL);}

<INITIAL,PARENTESIS>"<>"              {printf("\n Operador DISTINTO: %s --> token %d\n", yytext, DISTINTO);}

<INITIAL,PARENTESIS>".o."             {printf("\n Operador DISYUNCION_LOGICA: %s --> token %d\n", yytext, DISYUNCION_LOGICA);}

<INITIAL,PARENTESIS>".y."             {printf("\n Operador CONJUNCION_LOGICA: %s --> token %d\n", yytext, CONJUNCION_LOGICA);}

<INITIAL,PARENTESIS>".no."            {printf("\n Operador NEGACION_LOGICA: %s --> token %d\n", yytext, NEGACION_LOGICA);}

<INITIAL,PARENTESIS>(?i:{identificador})    {printf("\n Identificador: %s --> token %d\n", yytext, ID);}

<INITIAL,PARENTESIS>{malidentificador}      {printf("\n Identificador no reconocible: %s\n", yytext);}

<INITIAL,PARENTESIS>.*(\_+{identificador}|{identificador}\_+).*      {printf("\n Identificador no reconocible: %s\n", yytext);}

<INITIAL,PARENTESIS>{numero}          {printf("\n Número: %s --> token %d\n", yytext, NUMERO);}

<INITIAL,PARENTESIS>([\.|E]+{numero}|{numero}[\.|E]+{numero}|{numero}[E|\.])          {printf("\n Número no reconocido: %s\n", yytext);}

<INITIAL,PARENTESIS>{cadena}          {printf("\n Cadena: %s --> token %d\n", yytext,CADENA);}

";"               {printf("\n Caracter fin de Sentencia: %s --> token %d\n", yytext, FIN_SENTENCIA);}

"#"             {BEGIN ESTADO_COMENTARIO_1; printf("\n Almohadilla: %s --> token %d\n", yytext, ALMOHADILLA);}

<ESTADO_COMENTARIO_1>.*    {BEGIN 0; printf("\n Comentario: %s\n", yytext);}

"(*"	      	   {BEGIN ESTADO_COMENTARIO;}

<ESTADO_COMENTARIO>"(*"(.|\n)  {printf("\n No se pueden anidar comentarios\n");}

<ESTADO_COMENTARIO>"*)"    {BEGIN 0;}

<ESTADO_COMENTARIO>.|\n    {ECHO;}

"("               {
                     BEGIN PARENTESIS;
                     printf("\n Parentesis Izquierdo: %s --> token %d\n", yytext, PARENTESIS_IZQUIERDO);
                     printf("\nContenido PARENTESIS \n");
                  }

<PARENTESIS>")"   {
                     BEGIN 0;
                     printf("\nTermina contenido PARENTESIS\n");
                     printf("\n Parentesis Derecho: %s --> token %d\n", yytext, PARENTESIS_DERECHO);
                  }

<INITIAL,PARENTESIS>[^[[:space:]]|^\n]     {printf("\n Caracter no reconocido --> %s\n", yytext);}

%%

extern FILE *yyin;

int main(int argc, char **argv){
   yyin=fopen(argv[1], "r");

   yylex();

   fclose(yyin);
   return 0;
}
