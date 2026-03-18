
#Sentencias y Expresiones. 

En C++ las unidades más básicas de un programa son las sentencias. Una sentencia es una **instrucción** que indica al programa que realice una acción específica, como **declarar una variable**, **asignar un valor**, **evaluar una expresión** o **controlar el flujo de ejecución**. En general, las sentencias representan los pasos que el programa ejecuta uno tras otro, y muchas de ellas terminan con un punto y coma (;).

De entre todo el conjunto de instrucciones que puedes escribir en C++, las expresiones son sin duda las piezas mas importantes: a grandes rasgos, una expresión es cualquier construcción del lenguaje que se evalúa para producir un valor. De lo que hemos visto hasta ahora, la asignación de valores a una variable es un buen ejemplo de lo que es una expresión. A lo largo del curso veremos que hay muchisimas mas cosas que producen algun valor. 

Pero entonces, ¿cómo es que las expresiones producen valores? Bueno, aquí es donde entran en juego los **operadores**. Un **operador** es un símbolo del lenguaje que indica una operación. Esta operación se realiza sobre los operandos, los cuales son valores concretos (constantes), nombres de variables o incluso otras expresiones; el operador toma esos operandos, aplica una regla (aritmética, lógica, de acceso, etc.) y produce un nuevo valor.








En el capítulo anterior aprendimos a cómo declarar variables, constantes y algunos tipos de datos básicos. En esta sección comenzaremos a conectar esos conceptos con dos de las unidades más fundamentales en un programa en C++: las **expresiones** y las **sentencias**.

De manera resumida, vimos que las variables son recipientes donde se almacenan valores, mientras que los tipos de datos determinan qué clase de valores pueden guardarse en ellas y qué operaciones son válidas. A partir de esto surgen las **expresiones**, que son combinaciones de variables, constantes y operadores utilizadas para calcular valores o provocar efectos en el programa. Por su parte, las sentencias son las instrucciones completas que le indican al **compilador** qué acción debe ejecutarse: declarar una variable, realizar una asignación, tomar una decisión, repetir un bloque de código, devolver un valor, entre otras.

## Expresiones 
Una expresión es cualquier construcción del lenguaje que se evalúa para producir un valor (y quiza algunos efectos secundarios jeje). Ejemplos sencillos son digamos, una constante (42), el nombre de una variable (x) o una operación aritmetica combinada (a + b * func(c)). Las expresiones sirven para calcular valores, evaluar condiciones o generar resultados que otras partes del programa consumen (por ejemplo, como veremos mas adelane en el curso, el valor dentro del return o la condición en un **if**). Dado que las expresiones operan sobre variables y constantes, los tipos de datos influyen directamente en el resultado y el comportamiento: sumar enteros no es lo mismo que sumar flotantes, y las conversiones de tipo pueden cambiar el resultado. 



## Sentencias 
En términos generales, una **instrucción** en un lenguaje de programación es un conjunto de líneas de código que indica a la computadora realizar una acción específica. Es la unidad básica de un programa e incluye tareas como asignar valores, realizar cálculos, tomar decisiones o repetir operaciones.

En C++, las instrucciones más comunes son las **sentencias**. Una **sentencia** es una instrucción que define una acción concreta en el programa, como **declarar una variable**, **realizar un cálculo**, **tomar una decisión** o **ejecutar un bucle**.

Las sentencias son, con diferencia, el tipo de instrucción más común en un programa de C++. Esto se debe a que son la unidad de cálculo independiente más pequeña del lenguaje C++. En ese sentido, funcionan de forma muy similar a las oraciones en el lenguaje natural. Cuando queremos transmitir una idea a otra persona, solemos escribir o hablar mediante oraciones (no con palabras o sílabas al azar). En C++, cuando queremos que nuestro programa haga algo, solemos escribir sentencias.

A grandes rasgos, en C++ podemos distingir tres tipos de sentencias: Simples, vacias y compuestas. 

![Tipos de Sentencias en C++](Sentencias.png)

De igual manera, daremos ejemplos de esto en las siguientes entradas.  


