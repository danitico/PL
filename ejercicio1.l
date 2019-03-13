%{
int divisor;
#include <stdlib.h>
%}
digito      [0-9]+

%%

{digito}       {
                  if(atoi(yytext)%divisor!=0){
                     fprintf(yyout, "%s", yytext);
                  }
               }
%%

extern FILE *yyin, *yyout;

int main(int argc, char **argv){
   yyin=fopen(argv[2], "r");
   yyout=fopen(argv[3], "w");

   divisor=atoi(argv[1]);
   yylex();

   return 0;
}
