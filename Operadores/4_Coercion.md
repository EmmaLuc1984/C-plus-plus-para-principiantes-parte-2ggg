# Coerción De Tipos

Los valores enteros y los valores de punto flotante se almacenan de modo diferente en la memoria de una computadora. El patrón de bits que representa la constante 2 no se parece en absoluto al patrón de bits que representa a la constante 2.0. Entonces, ¿qué sucede si se combinan valores enteros y de punto flotante en una sentencia de asignación o una expresión aritmetica? Por ejemplo, si consideramos: 

```c++
int x;
float y;
```
entonces `x` puede contener *sólo* valores enteros y `y` puede contener *sólo* valores de punto flotante. 

La siguiente sentencia:

 ```c++
float y=13;
```
pareciera que almacena el valor 13 en `y` pero esto no es cierto. La computadora rechaza almacenar cualquier otra cosa que no sea un valor `float` en `y`. Muy por dentro, el compilador inserta instrucciones de lenguaje máquina extra que primero convierten a 13 en 13.0 y luego almacenan a 13.0 en `y`. Esta conversión implícita (automática) de un valor de un tipo de datos a otro se conoce como **coerción de tipo**. La sentencia: 

```c++
int x=4.8;
```

también causa coerción de tipo. Cuando se asigna un valor de punto flotante a una variable de tipo entero, se trunca la parte fraccionaria. Como resultado, a `x` se le asigna el valor 4.

La coerción tambien actua en expresiones mas complejas, por ejemplo: 

```c++
int x;
float y;

y = 3 * x + 2;
x = 5.2 / y - 10.5;
```
En la primera sentencia, tanto 3 como 2 son constantes enteras, y `x` también es un entero. Por lo tanto, la expresión `3 * x + 2` se evalúa completamente usando aritmética entera. El resultado de esa expresión es un entero, pero como el valor final debe almacenarse en `y`, que es de tipo `float`, el compilador convierte automáticamente ese entero a un valor de punto flotante antes de asignarlo. Lo mismo ocurre con la segunda sentencia: las constantes 5.2 y 10.5 son valores de punto flotante. Como `y` también es de tipo `float`, las operaciones se realizan utilizando aritmética de punto flotante. El resultado de la expresión es entonces un valor `float`. Sin embargo, al asignarlo a `x`, el compilador realiza nuevamente una coerción de tipo: el valor de punto flotante se convierte a entero truncando su parte fraccionaria.

Puedes hacer que el compilador deduzca automáticamente el tipo de la variable a partir de la expresión con la que se inicializa empleando la palabra reservada `auto`.
Por ejemplo en: 
```c++
 long double a{5.0};
    int b{2};

    auto resultado = a + b;
```
el resultado es 7.0. Y con: 

```c++
 double x{3.5};
    int y{2};

    auto resultado = x * y;

```
el resultado es 7.0. La regla general es que el tipo de dato del resultado será el tipo de dato mas "amplio" o "preciso" (en el sentido de la cantidad de memoria que usan) de los operandos involucrados en la operación. Esta idea viene resumida en la siguiente tabla: 



| Si uno de los operandos es... | Entonces el otro operando se convierte a... |  Tipo del resultado  |
| ----------------------------: | :-----------------------------------------: | :------------------: |
|                 `long double` |                `long double`                |     `long double`    |
|                      `double` |                   `double`                  |       `double`       |
|                       `float` |                   `float`                   |        `float`       |
|                        `long` |                    `long`                   |        `long`        |
|                         `int` |                    `int`                    |         `int`        |




Como nota final: almacenar el resultado de una expresión `int` en una variable `float` en general no causa pérdida de información; un número entero como 24 se puede representar en forma
de punto flotante como 24.0. Sin embargo, almacenar el resultado de una expresión de punto flotante en una variable de tipo entero puede causar pérdida de información porque se trunca la parte fraccionaria. En cualquier caso, evita mezclar tipos enteros y de punto flotante en la misma expresión cuando no sea necesario.



## Programas Auxiliares:
En `Media_aritmetica.cpp` vemos un pequeño ejemplo práctico de como funciona la coerción. 