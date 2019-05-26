#
   El siguiente algoritmo se encarga de hacer la integración
   de un número.

   Para ello, se utilizará la función x^3 - 1. Para poder representar
   esta función, se utilizarán los builtinFuncion, que recibirá un
   argumento, el cual será el valor de x y devolverá el valor de la función
   en ese punto.

   Para poder realizar la integración numérica, hay que crear una función que
   genere un número aleatorio en un rango.
#

escribir_cadena('Se va a proceder a calcular la integral de x^3 - 1\n');

escribir_cadena('Introduzca el número de simulaciones: ');
leer(simulaciones);

escribir_cadena('Introduzca los intervalos para el método de los trapecios: ');
leer(intervalos);

escribir_cadena('Introduzca el límite inferior de la integral: ');
leer(inferior);

escribir_cadena('Introduzca el límite superior de la integral: ');
leer(superior);

@ Método integración numérica

suma := 0;

para i desde 1 hasta simulaciones hacer
   x := randomrange(inferior, superior);
   suma +:= f(x);
fin_para;

area := ((superior - inferior)*suma)/simulaciones;


@ Método de los trapecios

step := (superior-inferior)/intervalos;
suma1 := f(inferior) + f(superior);

para j desde 1 hasta intervalos hacer
   suma1 +:= 2 * f(inferior + step*j);
fin_para;

area1 := (suma1 * step) / 2;


escribir_cadena('La integral de la función en esos límites es: ');
escribir(area);
escribir_cadena('\n');

escribir_cadena('La integral de la función utilizando el método de los trapecios es: ');
escribir(area1);
escribir_cadena('\n');
