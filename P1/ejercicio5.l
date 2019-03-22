%{
   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>
   char mayusculas[]={"A", "B", "C", "D", "E", "F", "G", "H", "I",
                      "J", "K", "L", "M", "N", "O", "P", "Q",
                      "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}

   char minusculas[]={"a", "b", "c", "d", "e", "f", "g", "h", "i",
                      "j", "k", "l", "m", "n", "o", "p", "q",
                      "r", "s", "t", "u", "v", "w", "x"  "y", "z"}

   char estado[20];
   char* vigenere(char *letra, char *estado);
   int NumLetraLeida;
%}

mayus    [A-Z]
minus    [a-z]

%%

{mayus}  {printf(vigenere(yytext, NumLetraLeida, estado)); NumLetraLeida++;}

{minus}  {printf(vigenere(yytext, NumLetraLeida, estado)); NumLetraLeida++;}

.        {ECHO;}

\n       {}

%%

int main(int argc, char **argv){
   if(argc!=2){
      printf("Número incorrecto de incorrectos");
   }
   strcpy(estado, argv[1]);
   NumLetraLeida=0;

   yylex();

   return 0;
}

char *vigenere(char letra, int letraLeida, char *estado){
   if(strcmp(estado, "cifrar")==0){
      return isupper(letra) ? mayusculas[(letra - 65 - letraLeida)%26] : minusculas[(letra - 97 - letraLeida)%26]
   }
}
