%{
   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>
   char mayusculas[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                      'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                      'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   char minusculas[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                      'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   char estado[20];
   char clave[20];
   int claveLeida=-1;
   void vigenereMinuscula(char letra, char *estado);
   void vigenereMayuscula(char letra, char *estado);
%}

mayus    [A-Z]
minus    [a-z]

%%

{mayus}  {vigenereMayuscula(yytext[0], estado);}

{minus}  {vigenereMinuscula(yytext[0], estado);}

.        {ECHO;}

\n       {claveLeida=-1;ECHO;}

%%

int main(int argc, char **argv){
   if(argc!=3){
      printf("Número incorrecto de incorrectos\n");
      printf("%s <cifrar/descifrar> <clave>\n", argv[0]);
      exit(-1);
   }

   strcpy(estado, argv[1]);
   strcpy(clave, argv[2]);

   yylex();

   return 0;
}

void vigenereMinuscula(char letra, char *estado){
   char letraClave;
   claveLeida++;

   if(strcmp(estado, "cifrar")==0){
      char letraCifrada;

      letraClave = clave[claveLeida%strlen(clave)];

      letraCifrada=minusculas[(letra - 97 + letraClave - 97)%26];

      printf("%c", letraCifrada);
   }
   else{
      if(strcmp(estado, "descifrar")==0){
         char letraDescifrada;

         letraClave = clave[claveLeida%strlen(clave)];

         letraDescifrada=minusculas[( (letra - letraClave) % 26 + 26) % 26];

         printf("%c", letraDescifrada);
      }
   }
}

void vigenereMayuscula(char letra, char *estado){
   char letraClave;
   claveLeida++;

   if(strcmp(estado, "cifrar")==0){
      char letraCifrada;

      letraClave = clave[claveLeida%strlen(clave)];

      letraCifrada=mayusculas[(letra - 65 + letraClave - 97)%26];

      printf("%c", letraCifrada);
   }
   else{
      if(strcmp(estado, "descifrar")==0){
         char letraDescifrada;

         letraClave = clave[claveLeida%strlen(clave)] - 97;

         letraDescifrada=mayusculas[( (letra - 65 - letraClave) % 26 + 26) % 26];

         printf("%c", letraDescifrada);
      }
   }
}
