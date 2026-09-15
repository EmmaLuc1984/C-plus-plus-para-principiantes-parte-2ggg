# Using y Typedef

Como ya hemos visto, los tipos de datos son una parte fundamental de C++. Además de los tipos básicos como `int`, `double` o `char`, el lenguaje permite trabajar con tipos más complejos y crear un *alias* para los tipos existentes.

La sentencia `using` permite asignar un nombre alternativo a un tipo de datos. Su sintaxis básica es la siguiente:

```c++
using Nuevo_nombre = tipo_de_dato_existente;```

Por ejemplo: 

```c++
using Entero = int; 
Entero edad{20}; 
Entero cantidad{15};
```


En este caso, `Entero` es un alias de `int`. Esto significa que no se ha creado un tipo de dato nuevo: para el compilador, `Entero` e `int` representan exactamente el mismo tipo.

El uso de alias puede hacer que un programa sea más fácil de leer y comprender. Por ejemplo, si en un programa utilizamos números enteros para representar identificadores, podemos escribir:

```c++
using Identificador = int;

Identificador jugador{125};
Identificador enemigo{87};
```

Aunque ambos identificadores siguen siendo valores de tipo `int`, los nombres utilizados hacen más claro qué representa cada variable.

La sentencia `Typedef` hace algo similar. La sintaxis básica es la siguiente: 

```c++
typedef tipo_de_dato_existente Nuevo_nombre;
```
 Ejemplos sencillos son los siguientes: 

 ```c++
 typedef int Entero;
    Entero edad{20};
    Entero cantidad{15};
 ```

Como nota curiosa, antes de que el tipo de datos `bool` fuera parte del lenguaje de C++, los antiguos usaban un código como el siguiente para simular un tipo booleano:

```c++
typedef int Boolean; 
const int TRUE = 1; 
const int FALSE = 0; 
       .
       .
       .
Boolean dataOK; 
       .
       .
       .

dataOK = TRUE;

```

En este código, la sentencia `typedef` ocasiona que el compilador sustituya `int` cada vez que aparezca `Boolean` en el resto del programa.

Al ser este un curso introductorio, podemos considerar que tanto `using` como `typedef` permiten realizar la misma tarea: crear un alias para un tipo de datos existente. Sin embargo, existen algunas diferencias entre ambos que se vuelven más importantes al trabajar con características más avanzadas de C++ y que probablemente veremos en un capítulo posterior. Actualmente, `using` es la sintaxis más moderna y suele ser la opción preferida al escribir código nuevo, por lo que es común encontrarla en programas de C++ actuales. Aun así, `typedef` sigue siendo válido y puede encontrarse con frecuencia en código más antiguo.


Los alias creados mediante `using` o `typedef` también siguen las reglas de alcance de C++. Pueden declararse en un ámbito global o dentro de una función o bloque, dependiendo de las partes del programa en las que sea necesario utilizarlos.

Sin embargo, debes tener presente una limitación importante: ni `using` ni `typedef` crean realmente un nuevo tipo de dato. En este sentido, resultan insuficientes cuando lo que buscamos es definir un tipo con características, comportamiento u operaciones propias. Su función se limita a proporcionar nombres alternativos para tipos que ya existen. Para crear tipos de datos propiamente dichos, C++ ofrece otras herramientas, como `struct`, `class` y `enum`. En las siguientes entradas abordaremos todos. 




## Alcance De Las Enumeraciones Sin Ámbito

Las enumeraciones con las que estamos trabajando se llaman enumeraciones sin ámbito porque los nombres de sus enumeradores se declaran en el mismo ámbito que la propia enumeración, en lugar de crear un ámbito nuevo, como ocurre con un espacio de nombres.

Por ejemplo, en : 

```c++
enum Animal // esta enumeración está definida en el espacio de nombres global
{
    perro,   // así que rojo se coloca en el espacio de nombres global
    gato,
    caballo,
};

int main()
{
    Animal mascota { caballo }; 

    return 0;
}

```

En este caso, `Animal` está creada en el espacio global, así que sus valores (`perro`, `gato` y `caballo`) también quedan disponibles para todo el programa. Eso puede causar problemas porque es más fácil que dos nombres se repitan y choquen entre sí.

Una consecuencia de esto es que un nombre de enumerador no se puede usar en múltiples enumeraciones dentro del mismo ámbito:

```c++

enum Animal
{
    perro,
    gato,
    caballo,
};

enum Vehiculo
{
    coche,
    moto,
    caballo, // error: conflicto de nombre con 'caballo' de Animal
};

int main()
{
    Animal mi_mascota { caballo };
    Vehiculo mi_transporte { coche };

    return 0;
}
```


En el ejemplo anterior, ambas enumeraciones sin ámbito colocan enumeradores con el mismo nombre `caballo` en el ámbito global. Esto provoca una colisión de nombres y por consiguiente, un error de compilación.

Las enumeraciones sin ámbito también crean un espacio con nombre para sus valores, parecido a lo que hace un espacio de nombres con los elementos que contiene. Esto quiere decir que podemos acceder a los valores de una enumeración sin ámbito de esta manera:
