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
   yyin=fopen(argv[1], "r");
   yyout=fopen("aux.txt", "a+");

   strcpy(antigua, argv[2]);
   strcpy(nueva, argv[3]);

   yylex();

   printf("palabras -> %i\n", palabras_sustituidas);
   fclose(yyin);
   fclose(yyout);

   remove(argv[1]);
   rename("aux.txt", argv[1]);
   return 0;
}
