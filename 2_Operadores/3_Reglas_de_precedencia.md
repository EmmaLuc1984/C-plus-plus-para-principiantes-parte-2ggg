# Reglas de Precedencia 


A lo largo de estas lecciones hemos trabajado un poco con las expresiones aritmeticas las cuales a lo sumo han tenido un solo operador. También se ha tenido cuidado de no combinar valores enteros y de punto flotante en la misma expresión. Ahora vamos a considerar expresiones un poco mas complicadas, compuestas de varios operadores y que contienen tipos de datos mixtos.


En general, las expresiones aritméticas pueden estar constituidas por muchas constantes, variables, operadores y paréntesis. ¿En qué orden se ejecutan las operaciones? Por ejemplo, en la siguiente sentencia: 

```c++
temperatura_promedio = PUNTO_CONGELACION + PUNTO_EBULLICION / 2.0;
```

¿se calcula primero `PUNTO_CONGELACION + PUNTO_EBULLICION` o `PUNTO_EBULLICION / 2.0`? Bueno, para los operadores aritmeticos que hemos visto hasta ahora tenemos el siguiente orden de prioridades: 

| Prioridad | Operadores       |
|----------------------------|--------------------|
| Alta            | `+` (unario), `-` (unario) |
| Media              | `*`, `/`, `%`      | 
| Baja                     | `+`, `-` (binarios)| 


Debido a que la división tiene prioridad más alta que la suma, la expresión del ejemplo anterior se encierra entre paréntesis de manera implícita como: 

```c++
temperatura_promedio = PUNTO_CONGELACION + (PUNTO_EBULLICION / 2.0);
```

Es decir, se divide primero `PUNTO_EBULLICION` entre 2.0 y luego se suma `PUNTO_CONGELACION` al resultado. 


Por supuesto, puedes cambiar el orden de evaluación siempre que quieras haciendo el uso de parentesis: 

```c++
temperatura_promedio = (PUNTO_CONGELACION + PUNTO_EBULLICION) / 2.0;
```
 
Al igual que con las reglas aritméticas, las subexpresiones entre paréntesis siempre se calculan primero (en este caso PUNTO_CONGELACION y PUNTO_EBULLICION se suman primero, y luego su suma se divide entre 2.0). Puedes usar tantos paréntesis como necesites y, a menudo, los usamos para mejorar la legibilidad de una expresión, incluso si no alteran el orden de las operaciones. 


Cuando una expresión aritmética tiene varios operadores binarios con la misma prioridad, su orden de agrupamiento (o asociatividad) es de izquierda a derecha. La expresión:

```c++
int1-int2 +int3; 
```
significa `(int1 - int2) + int3`, no `int1 - (int2 + int3)`. Como otro ejemplo tenemos: 

```c++
 (float1 + float2) / float1 * 3.0
```
En este caso, se evalua primero la expresion entre parentesis, despues se divide la suma entre `float1` y finalmente se multiplica por 3.0 el resultado. 


Ya por último, en C++, los operadores unarios (como `+ unario` y `- unario`) tienen asociatividad de derecha aizquierda. Aunque al principio esto podría parecer extraño, resulta ser el orden de agrupamiento natural. Por ejemplo, `- + x` significa `- (+ x)` y no el orden `(- +) x` carente de significado. 