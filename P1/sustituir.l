%{
   #include <stdio.h>
   #include <string.h>
   int palabras_sustituidas=0;
   char antigua[30];
   char nueva[30];
%}

%%

[a-zA-Z]+   {
               if(strcmp(antigua, yytext)==0){
                  fseek(yyin, - sizeof(yytext), SEEK_CUR);
                  fprintf(yyin, "%s", nueva);
                  palabras_sustituidas++;
               }
               /* else{
                  fprintf(yyin, "%s", yytext);
               } */
            }

.|\n        {;}

%%

extern FILE *yyin;

int main(int argc, char **argv){
   yyin=fopen(argv[1], "r+");

   strcpy(antigua, argv[2]);
   strcpy(nueva, argv[3]);
   yylex();

   printf("palabras -> %i\n", palabras_sustituidas);
   fclose(yyin);
   return 0;
}
