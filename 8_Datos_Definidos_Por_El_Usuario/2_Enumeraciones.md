# Enumeraciones

Una *enumeración* es un tipo de dato definido por el usuario cuyos valores están restringidos a un conjunto de constantes simbólicas con nombre (llamadas *enumeradores*).

C++ permite definir dos tipos de enumeraciones: las **enumeraciones sin ámbito**, que corresponden a la forma tradicional de declarar un `enum`, y las **enumeraciones con ámbito**, que se declaran mediante la sentencia `enum class`. En esta sección nos centraremos primero en las enumeraciones sin ámbito, ya que las enumeraciones con ámbito requieren introducir previamente algunos conceptos relacionados con temas posteriores.

## Enumeraciones Sin Ambito 
Las enumeraciones sin ámbito se crean crean con una instrucción como esta: 

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

En el ejemplo, comenzamos escribiendo la palabra reservada `enum`, que le indica al compilador que vamos a definir una enumeración sin ámbito, a la que llamamos `Color`.

Dentro de llaves, colocamos los enumeradores del tipo: `rojo`, `verde` y `azul`. Estos valores son los únicos que puede tomar `Color`. Cada enumerador se separa con una coma, no con punto y coma. La coma final es opcional, aunque se recomienda para mantener un estilo uniforme.

Normalmente, cada enumerador se escribe en una línea distinta. Sin embargo, en ejemplos simples, donde hay pocos valores y no se necesitan comentarios, también pueden escribirse todos en la misma línea. La definición del tipo `Color` termina con un punto y coma. Con esto, la enumeración queda completamente definida.

Después, dentro de `main`, se crean tres variables de tipo `Color`: `manzana` se inicializa con `rojo`, `camisa` con `verde` y `taza` con `azul`. En cada caso se reserva memoria para el objeto correspondiente. Es importante recordar que una variable de este tipo solo puede inicializarse con uno de los enumeradores definidos para esa enumeración. Por eso, `calcetines` y `sombrero` provocan errores de compilación: `blanco` y 2 no pertenecen al tipo `Color`.

Por convención, los nombres de los tipos enumerados suelen empezar con mayúscula. En cambio, los enumeradores deben tener nombre, aunque no existe una forma universalmente aceptada para escribirlos. Algunas convenciones comunes son usar minúsculas (rojo), mayúsculas iniciales (Rojo), mayúsculas completas (ROJO), etc. En nuestro caso, optaremos por escirbirlas unicamente usando minusculas: `rojo`

Cada tipo enumerado que se crea se considera un tipo diferente, lo que permite que el compilador lo distinga de los demás (contrario al uso `typedef`, que no se consideran tipos nuevos, sino solo otra forma de nombrar un tipo ya existente)

Como cada enumeración es independiente, los enumeradores pertenecientes a una no pueden usarse con objetos de otra enumeración. Por ejemplo:


```c++

enum Mascota
{
    gato,
    perro,
    cerdo,
    ballena,
};

enum Color
{
    rojo,
    verde,
    azul,
};

int main()
{
    Mascota mi_mascota { negro }; // error de compilación: negro no es un enumerador de Mascota
    Color camisa { cerdo };      // error de compilación: cerdo no es un enumerador de Color

    return 0;
}
```