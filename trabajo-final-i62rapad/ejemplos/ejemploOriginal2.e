#
   Este programa se encarga de calcular un número combinatorio
#

escribir_cadena('Introduzca m -> ');
leer(m);

escribir_cadena('Introduzca n -> ');
leer(n);

segun(n)
   valor 0:
      resultado := 1;
      romper;

   valor m:
      resultado := 1;
      romper;

   defecto:
      si (m < n) entonces
         escribir_cadena('Es imposible calcular ese número combinatorio\n');
         _terminar;
      fin_si;

      numerador := denominador := 1;
      si (m - n < n) entonces
         para i desde n + 1 hasta m hacer
            numerador *:= i;
         fin_para;

         para j desde 1 hasta m - n hacer
            denominador *:= j;
         fin_para;
      si_no
         para i desde m - n + 1 hasta m hacer
            numerador *:= i;
         fin_para;

         para j desde 1 hasta n hacer
            denominador *:= j;
         fin_para;
      fin_si;

      resultado := numerador / denominador;

fin_segun;

escribir_cadena('El resultado del número combinatorio es: ');
escribir(resultado);
escribir_cadena('\n');
