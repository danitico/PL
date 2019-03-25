%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   int palabras_sustituidas=0;
   char antigua[255];
   char nueva[255];
%}

%%

[a-zA-Z]+   {
               if(strcmp(antigua, yytext)==0){
                  fprintf(yyout, "%s", nueva);
                  palabras_sustituidas++;
               }
               else{
                  fprintf(yyout, "%s", yytext);
               }
               }

.|\n        {fprintf(yyout, "%s", yytext);}

%%

extern FILE *yyin, *yyout;

int main(int argc, char **argv){
   if(argc!=4){
      printf("Error en la llamada al programa\n");
      printf("%s <nombre_fichero> <palabra_antigua> <palabra_nueva>\n", argv[0]);
      exit(-1);
   }

   yyin=fopen(argv[1], "r");
   if(yyin == NULL){
      printf("Error al abrir el archivo\n");
      exit(-1);
   }
   yyout=fopen("aux.txt", "a+");

   strcpy(antigua, argv[2]);
   strcpy(nueva, argv[3]);

   yylex();

   printf("Palabras sustituidas-> %i\n", palabras_sustituidas);
   fclose(yyin);
   fclose(yyout);

   remove(argv[1]);
   rename("aux.txt", argv[1]);
   return 0;
}
