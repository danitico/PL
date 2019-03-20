%{
#include <stdio.h>
%}

digito      [0-9]
letra       [a-zA-Z]

identificador     {letra}({letra}\_?|{digito}\_?)*({letra}|{digito})+[^_]

numero            {digito}+(\.{digito}+)?(E[+\-]?{digito}+)?

cadena            \'({letra}|[[:space:]]|\\\'({letra}|[[:space:]])*\\\')*\'
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

{cadena}          {printf(yytext);printf("\n");}

":="              {printf("Operador asignacion");}

"+"               {printf("Suma")}

"-"               {printf("Resta")}

"*"               {printf("Producto")}

"/"               {printf("Division")}

"__mod"           {printf("Modulo")}

"**"              {printf("Potencia")}

"||"              {}

.|\n     {;}

%%

extern FILE *yyin;

int main(int argc, char **argv){
   yyin=fopen(argv[1], "r");

   yylex();

   fclose(yyin);
   return 0;
}
