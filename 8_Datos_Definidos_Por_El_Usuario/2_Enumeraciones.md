# Enumeraciones

Una *enumeración* es un tipo de dato definido por el usuario cuyos valores están restringidos a un conjunto de constantes simbólicas con nombre (llamadas *enumeradores*).

C++ permite definir dos tipos de enumeraciones: las **enumeraciones sin ámbito**, que corresponden a la forma tradicional de declarar un `enum`, y las **enumeraciones con ámbito**, que se declaran mediante la sentencia `enum class`. En esta sección nos centraremos primero en las enumeraciones sin ámbito, ya que las enumeraciones con ámbito requieren introducir previamente algunos conceptos relacionados con temas posteriores.

## Enumeraciones Sin Ambito 
La sintaxis de una enumeración es la siguiente: 

```c++
enum Nombre { enumerador1, 
              enumerador2, 
                 .
                 .
                 .}; 
```
Por ejemplo: 


```c++ 

// Definimos una nueva enumeración sin ámbito llamada Color
enum Color
{
    // Aquí están los enumeradores
    // Estas constantes simbólicas definen todos los valores posibles que puede contener este tipo
    // Cada enumerador se separa con una coma, no con un punto y coma
    rojo,
    verde,
    azul, // la coma al final es opcional, pero es recomendable ponerla
}; // la definición del enum debe terminar con punto y coma

int main()
{
    // Define algunas variables del tipo enumerado Color
    Color manzana { rojo };   // mi manzana es roja
    Color camisa { verde }; // mi camisa es verde
    Color taza { azul };    // mi taza es azul

    Color calcetines { blanco}; // error:  blanco  no es un enumerador de Color
    Color sombrero { 2 };       // error: 2 no es un enumerador de Color

    return 0;
}

```

Observa con atención: En el ejemplo comenzamos escribiendo la palabra reservada `enum`, que le indica al compilador que vamos a definir una enumeración sin ámbito, a la que llamamos `Color`.

Dentro de llaves, colocamos los enumeradores del tipo: `rojo`, `verde` y `azul`. Estos valores son los únicos que puede tomar `Color`. Cada enumerador se separa con una coma, no con punto y coma. La coma final es opcional, aunque se recomienda para mantener un estilo uniforme.

Normalmente, cada enumerador se escribe en una línea distinta. Sin embargo, en ejemplos simples, donde hay pocos valores y no se necesitan comentarios, también pueden escribirse todos en la misma línea. La definición del tipo `Color` termina con un punto y coma. Con esto, la enumeración queda completamente definida.

Después, dentro de `main`, se crean tres variables de tipo `Color`: `manzana` se inicializa con `rojo`, `camisa` con `verde` y `taza` con `azul`. En cada caso se reserva memoria para el objeto correspondiente. Es importante recordar que una variable de este tipo solo puede inicializarse con uno de los enumeradores definidos para esa enumeración. Por eso, `calcetines` y `sombrero` provocan errores de compilación: `blanco` y 2 no pertenecen al tipo `Color`.

Por convención, el nombre de una enumeración suele empezar con mayúscula. En cambio, los enumeradores deben tener nombre, aunque no existe una forma universalmente aceptada para escribirlos. Algunas convenciones comunes son usar minúsculas (rojo), mayúsculas iniciales (Rojo), mayúsculas completas (ROJO), etc. En nuestro caso, optaremos por escirbirlas unicamente usando minusculas: `rojo`

Los nombres de los enumeradores deben de cumplir las mismas reglas que usamos para nombrar variables, funciones, etc. 
Por ejemplo, si consideramos ahora: 

```c++
enum Vocal {'a', 'e', 'i', 'o', 'u',}; // Error
```
Esta declaración es incorrecta porque 'A', 'E', etc. son constantes de tipo `char` y no un nombre (o mas formalmente, un *identificador*).

De manera similar:
```c++
enum Lugares {1ro, 2do, 3ro,};    // Error
```
es una declaración inválida, ya que un identificador no puede comenzar con un dígito.


También es importante considerar el alcance de los identificadores. Por ejemplo:

```c++
enum Alimento {
    maiz,
    arroz,
    papa,
    frijol,
};

enum Cereal {
    trigo,
    maiz,
    centeno,
    cebada,
    sorgo,
};    // Error
```
Cada enumeración es válida por separado, pero no pueden declararse juntas de esta manera. El problema es que `maiz` aparece en ambas enumeraciones y los identificadores que pertenecen al mismo alcance deben ser únicos. Por lo tanto, un mismo identificador no puede definirse dos veces dentro del mismo alcance.

### Asignaciónes

Supongamos que estás desarrollando un programa para una clínica veterinaria. El programa necesita llevar un registro de las distintas clases de animales que pueden ser atendidos. Para representar estas categorías, podemos definir una enumeración como la siguiente:

```c++
enum Animal {
    roedor,
    gato,
    perro,
    loro,
    tortuga,
    caballo,
    cerdo,
    oveja,
};
```

En este caso, `Animal` es el identificador del tipo de enumeración, mientras que `roedor`, `gato`, `perro`, etc. son los valores que forman parte de ella.

Es importante señalar que estos valores no son nombres de variables. Por ejemplo, `gato` representa uno de los valores posibles del tipo `Animal` y puede ser almacenado en una variable de dicho tipo.

Podemos crear, por ejemplo, dos variables de tipo `Animal`:

```c++
Animal paciente_interno;
Animal paciente_externo;
```
Estas variables pueden almacenar cualquiera de los valores definidos en la enumeración. Por ejemplo:

```c++
paciente_interno = roedor;
paciente_externo = perro;
```
De esta manera, `roedor` y `perro` son valores de la enumeración, mientras que `paciente_interno` y `paciente_externo` son variables capaces de almacenar dichos valores.



### Comparaciones
Algo que aún no habíamos mencionado es que los enumeradores son **ordenados** y, además, tienen una **representación numérica implícita**. Esto significa que cada enumerador tiene asociado un número entero. De manera predeterminada, el primero comienza en `0` y los siguientes aumentan de uno en uno. Por ejemplo:

```c++
enum dias {
    domingo,  // 0
    lunes,    // 1
    martes,   // 2
    miercoles,// 3
    jueves,   // 4
    viernes,  // 5
    sabado    // 6
};
```

Como los enumeradores están ordenados, podemos utilizar **operadores relacionales** como `<`, `>` o `==` para compararlos. Al hacerlo, estamos comprobando su posición dentro de la enumeración.

Por ejemplo:

```c++
domingo < lunes
lunes < martes
```

Ambas expresiones son verdaderas, ya que `domingo` corresponde a `0`, `lunes` a `1` y `martes` a `2`.

Los valores se asignan automáticamente siguiendo el orden en que aparecen los enumeradores. Sin embargo, también podemos establecerlos de forma explícita:

```c++
enum dias {
    domingo = 4,
    lunes = 18,
    martes = 9
};
```

En este caso, cada enumerador tiene un valor diferente al que tendría normalmente. Aunque C++ permite hacerlo, en la mayoría de los casos no es necesario especificar estos valores, ya que normalmente nos interesa trabajar con los enumeradores y su orden, más que con los números que tienen asociados.

 ### Incrementos

 






