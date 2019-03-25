%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char usuario[100];
char fecha[100];
int numDocumentos;
int buscarFecha;
%}

username    ^([[:alpha:]]|[[:digit:]])+
fecha       ([[:digit:]]{2,2}\/){2,2}[[:digit:]]{4,4}

%x FECHA
%%

{username}     {
                  if(strcmp(yytext, usuario)==0){
                     numDocumentos++;
                     if(buscarFecha==1){
                        BEGIN FECHA;
                     }
                  }
               }

<FECHA>{fecha}     {
                        if(strcmp(yytext, fecha)!=0){
                           numDocumentos--;
                        }
                        BEGIN 0;
                     }

<INITIAL,FECHA>.|\n             {;}
%%

extern FILE *yyin;
int main(int argc, char **argv){
   numDocumentos=0;
   switch(argc){
      case 3:
         yyin = fopen(argv[1], "r");
         if(yyin == NULL){
            printf("Error al leer el archivo\n");
            exit(-1);
         }
         strcpy(usuario, argv[2]);
         buscarFecha=0;
         break;

      case 4:
         yyin = fopen(argv[1], "r");
         if(yyin == NULL){
            printf("Error al leer el archivo\n");
            exit(-1);
         }
         strcpy(usuario, argv[2]);
         strcpy(fecha, argv[3]);
         buscarFecha=1;
         break;

      default:
         printf("Numero incorrecto de argumentos\n");
         printf("%s <fichero> <usuario> [<fecha>]\n", argv[0]);
         return 0;
   }

   yylex();

   if(buscarFecha==0){
      printf("El numero de documentos del usuario %s es %i\n", argv[2], numDocumentos);
   }
   else{
      printf("\n El numero de documentos del usuario %s con fecha %s es %i\n", argv[2], argv[3], numDocumentos);
   }

   return 0;
}
