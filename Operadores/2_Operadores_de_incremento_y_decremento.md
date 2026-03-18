# Operadores de Incremento y Decremento 

Además de los operadores aritméticos, C++ provee los **operadores de incremento y decremento**:
- -- Decremento
- ++ Incremento

Estos tambien son operadores unarios. Para entender como funcionan, considera el siguiente ejemplo: 

``` c++
int contador_de_ovejas;

contador_de_ovejas=0;
```
Cada vez que una oveja pasa por nuestros pensamientos queremos que la variable se incremente, así:

``` c++
contador_de_ovejas = contador_de_ovejas+1;
```
 Instrucciones similares a estas aparecen frecuentemente al momento de programar, por lo que los creadores del lenguaje C++ introdujeron un conjunto de operadores especiales para estas acciones.

 Con el operador `++` podemos escribir lo anterior de una manera mas concisa: 

 ``` c++
contador_de_ovejas++;
```

De igual forma, también se puede disminuir el valor de una variable elegida. Por ejemplo, si estamos deseando que lleguen nuestras vacaciones, nuestra mente realiza la siguiente operación cada dia: 

 ``` c++
dias_hasta_vacaciones = dias_hasta_vacaciones-1;
```
O equivalentemente: 

``` c++
dias_hasta_vacaciones--;
```
Ya has visto como funcionan `++` y `--` cuando los ponemos a la derecha de las variables (en la literatura lo puedes encontrar como **postfijo** o **sufijo**). Sin embargo, ambos operadores también pueden colocarse a la izquierda de una variable (como operadores de prefijo), asi: 

``` c++
++contador_de_ovejas;
--dias_hasta_vacaciones;
```
El efecto será exactamente el mismo: `contador_de_ovejas` aumentará en 1 y `dias_hasta_vacaciones` disminuirá en 1, sin embargo, aunque no lo parezca, hay una diferencia significativa en como funcionan. Si tomamos: 

```c++
int x{1}; 
++x; 
--x; 
```

Se incrementa/decrementa la variable en 1 y devuelve su valor **ya** incrementado/reducido. Y si tomamos: 

```c++
int x{1}; 
x++; 
x--; 
```

Devuelve el valor de la variable original (sin cambios) y luego incrementa/decrementa la variable en 1. Para ver como es que esto afecta de manera mas significativa, consideremos los siguientes ejemplos: 

```c++
int i{1};
int j{i++};
```

```c++
int i{1};
int j{++i};
```

Para el primer ejemplo, se inicializa la variable `ì` en uno, y al usarse `++` como postfijo ocurre lo siguiente: 

- `j` recibe el valor de 1. 
- Posteriormente `i` toma el valor de 2. 

Lo que al final nos da como resultado que: 

```c++
i == 2
j == 1
```


Para el segundo ejemplo, se vuelve a inicializar la variable `i` en 1, y al usarse `++` como prefijo ocurre lo siguiente:
- La variable `i` incrementa su valor en 1.
- A `j` se le asigna el valor de 2. 
  
Lo que nos da como resultado que: 

```c++
i == 2
j == 2
```


Todo lo que acabamos de ver viene resumido en la siguiente tabla: 



| Operador | Símbolo | Ejemplo | Descripción |
|---|---|---|---|
| Incremento prefijo (pre-incremento) | `++` | `++x` | Incrementa `x` y luego devuelve `x`. |
| Decremento prefijo (pre-decremento) | `--` | `--x` | Decrementa `x` y luego devuelve `x`. |
| Incremento postfijo (post-incremento) | `++` | `x++` | Copia `x`, luego incrementa `x` y finalmente devuelve la copia. |
| Decremento postfijo (post-decremento) | `--` | `x--` | Copia `x`, luego decrementa `x` y finalmente devuelve la copia. |


## Programas Auxiliares. 

En `Primos.cpp` viene un ejemplo elaborado de como empleamos varios operadores vistos para construir un programa que nos diga si un entero es primo. Algunos elementos empleados no los hemos visto, asi que no te asustes, poco a poco iremos trazando el camino. 