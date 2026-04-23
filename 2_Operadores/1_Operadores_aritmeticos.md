# Operadores Aritméticos

Recordemos que las *expresiones* son *instrucciones* que están constituidas por constantes, variables y operadores. Si inicializamos: 

```c++
int costo{2568};
float peso{14.5}; 
int numero_de_piezas{5}
```
entonces las siguientes son expresiones válidas:


```c++
20.5-peso; 
12000-costo;
peso*numero_de_piezas; 
```

Los operadores permitidos en una expresión dependen de los tipos de datos de las constantes y variables en la expresión.
Los operadores aritméticos son: 

- `+` Signo positivo unario
- `-`Signo negativo unario
- `+` Suma
- `-` Resta
- `*` Multiplicación
- `/` División
- `%` Módulo (o tambien conocida como residuo)

Los dos primeros de esta lista son *operadores unarios*, pues toman solo un operando. Funcionan de la siguiente manera: 

``` c++
int i{-100}; 
int j{-i};
int k{+100}; 
int l{+k};
 ```
En el caso de `+`, solo sirve para preservar el signo (ciertamente es dificil encontrar casos donde su uso tenga sentido). 

Los cinco restantes son *operadores binarios*, pues toman dos operandos.

 La suma, resta y multiplicación funcionan de la manera que uno se espera. Por ejemplo, para la suma: 

 ``` c++

int i{100}; 
int j{12};
int k{i + j};


float x {1.25}; 
float y {0.5};
float z {x + y};
 ```

El valor de `k` es 112 y el valor de `z` es 1.75. Para la resta:

``` c++

int i{100}; 
int j{10};
int k{i - j};


float x {1.0}; 
float y {0.5};
float z {x - y};
 ```
El valor de `k` es 90 y el valor de `z` es 0.5. Por último, para la multiplicación: 


 ``` c++

int i{10}; 
int j{12};
int k{i * j};


float x {1.25}; 
float y {0.5};
float z {x * y};
 ```
Y como es de esperarse, el valor de `k` es 120 y el valor de `z` es 0.625. 


La división es algo que funciona de la siguiente manera: 
``` c++
int i{10}; 
int j{5};
int k{i / j};


float x {1.0}; 
float y {2.0};
float z {x / y};
 ```

En este caso, `k` toma el valor de 2 y `z` toma el vaor de 0.5. Ahora bien, como probablemente habrás adivinado, dividir por cero está estrictamente prohibido, pero la penalización por romper esta regla no siempre llega de manera inmediata. Por ejemplo, si consideramos: 
 
``` c++
float x;
x =1.0 / 0.0;
 ```
el compilador se volverá loco: recibirás un error de compilación, un error de ejecución o algún mensaje en tiempo de ejecución. Por otro lado, si ejecutas el siguiente código: 

``` c++
#include <iostream>

int main() {
    float x, y;

    x = 0.0;
    y = 1.0 / x;

    std::cout << y << std::endl;
}

```
el compilador no te dirá nada, pero el resultado de la operación puede que te caiga de sorpresa (¿por qué?). En cualquier caso, evita por favor dividir entre cero. 

Por último tenemos a la operación de módulo (o residuo). Esta operación solo se realiza con datos de tipo entero (nada de flotantes). Funciona de la siguiente manera:

Al hacer el cálculo: 

```c++
7 % 3   
```
Nos da como resultado 1. Esto ocurre porque 7 = 3 * 2 + **1**

Asi, si tenemos: 
```c++
int i, j, k;

i = 13;
j = 5;
k = i % j;
```
el valor de `k` es 3. 