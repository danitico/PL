%{
int divisor;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

digito      [0-9]+

%%

{digito}       {
                  if(atoi(yytext)%divisor!=0){
                     ECHO;
                  }
               }

%%

extern FILE *yyin, *yyout;

int main(int argc, char **argv){
   if(argc!=4){
      printf("Error en la llamada al programa\n");
      printf("%s <divisor> <fichero_lectura> <fichero_escritura>\n", argv[0]);
      exit(-1);
   }

   if(strcmp(argv[2], argv[3])==0){
      printf("Los ficheros de lectura y escritura no pueden tener el mismo nombre\n");
      exit(-1);
   }

   yyin=fopen(argv[2], "r");
   if(yyin == NULL){
      printf("No se puede abrir el fichero de lectura\n");
      exit(-1);
   }

   yyout=fopen(argv[3], "w");
   if(yyout == NULL){
      printf("No se puede abrir el fichero de escritura");
      exit(-1);
   }

   divisor=atoi(argv[1]);
   yylex();

   return 0;
}
