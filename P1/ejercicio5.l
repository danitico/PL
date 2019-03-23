%{
   #include <stdlib.h>
   #include <locale.h>
   #include <stdio.h>
   #include <string.h>
   char mayusculas[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                      'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                      'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   char minusculas[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 164, 'o', 'p', 'q',
                      'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   char estado[20];
   char clave[20];
   int claveLeida=-1;
   char vigenereMinuscula(char letra, char *estado);
%}

mayus    [A-Z]
minus    [a-z]

%%


{minus}  {printf("%c", vigenereMinuscula(yytext[0], estado));}

.        {ECHO;}

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

char vigenereMinuscula(char letra, char *estado){
   /* if(strcmp(estado, "cifrar")==0){ */
      char letraCifrada;
      int letraClave;
      claveLeida++;

      if(clave[claveLeida%strlen(clave)]==(char)164){
         letraClave=14;
      }
      else if((clave[claveLeida%strlen(clave)] - 97) < 14){
         letraClave = clave[claveLeida%strlen(clave)] - 97;
      }
      else{
         letraClave = clave[claveLeida%strlen(clave)] - 97 + 1;
      }


      if(letra == (char)164){
         letraCifrada=minusculas[(14 + letraClave)%27];
      }
      else if(letra - 97 < 14){
         letraCifrada=minusculas[(letra - 97 + letraClave)%27];
      }
      else{
         letraCifrada=minusculas[(letra - 97 + 1 + letraClave)%27];
      }

      return letraCifrada;

   /* } */
}
