# Problemas En Registros

En la sección de `Datos definidos por el usuario` conocimos los registros (`struct`) y vimos que son muy útiles para agrupar varias variables dentro de un solo objeto, facilitando su inicialización y el manejo de todos sus datos dentro de una sola unidad. En otras palabras, los registros ofrecen una forma práctica de organizar, almacenar y manipular información relacionada.

Consideremos el siguiente registro:

```c++
#include <iostream>

struct Fecha
{
    int dia{};
    int mes{};
    int anio{};
};

void imprimir_fecha(const Fecha& fecha)
{
    std::cout << fecha.dia << '/' << fecha.mes << '/' << fecha.anio; 
}

int main()
{
    Fecha fecha{ 4, 10, 21 }; 
    imprimir_fecha(fecha);    
    return 0;
}
```

En el ejemplo anterior, creamos un objeto de tipo `Fecha` y posteriormente lo pasamos a una función que imprime la fecha. Este programa muestra:

```c++
4/10/21
```
Aunque los registros son muy útiles, presentan algunas deficiencias que pueden dificultar la construcción de programas grandes y complejos, especialmente cuando estos son desarrollados por varias personas.

Quizás la mayor dificultad de los registros es que no proporcionan una forma efectiva de documentar y hacer cumplir los **invariantes de clase**. Podemos definir a un invariante como **una condición que debe cumplirse mientras un componente del programa está en funcionamiento**.

Cuando hablamos datos estructurados, como los registros o las uniones, un invariante de clase es una condición que debe mantenerse durante toda la existencia de un objeto para garantizar que este se encuentre en un estado válido.

Por ejemplo, si un objeto debe cumplir ciertas condiciones para funcionar correctamente y alguna de ellas deja de cumplirse, se dice que el objeto está en un **estado inválido**. Utilizar un objeto en este estado puede provocar resultados inesperados o incluso un comportamiento indefinido.

Supongamos que tenemos: 

```c++
struct Par
{
    int primero {};
    int segundo {};
};
```

En este caso, los miembros `primero` y `segundo` pueden tomar cualquier valor de manera independiente. No existe ninguna condición que ambos deban cumplir para que el objeto sea válido, por lo que la estructura `Par` no tiene un invariante de clase.

Ahora veamos una estructura similar:

```c++
struct Fraccion
{
    int numerador { 0 };
    int denominador { 1 };
};
```

En una fracción, el denominador no puede ser `0`, ya que una división entre `0` no está definida. Por esta razón, podemos establecer como **invariante de clase** que el miembro `denominador` siempre debe ser diferente de `0`.

Cuando esta condición se cumple, el objeto se encuentra en un **estado válido**. Por el contrario, si `denominador` toma el valor `0`, el objeto pasa a un **estado inválido** y utilizarlo posteriormente puede provocar errores o comportamientos inesperados.

Por ejemplo:

```cpp
#include <iostream>

struct Fraccion
{
    int numerador { 0 };
    int denominador { 1 }; // invariante de clase: no debe ser 0
};

void imprimir_valor_fraccion(const Fraccion& fraccion)
{
    std::cout << fraccion.numerador / fraccion.denominador << '\n';
}

int main()
{
    Fraccion fraccion { 5, 0 }; // se crea una fracción inválida
    imprimir_valor_fraccion(fraccion); // división entre 0

    return 0;
}
```

En este ejemplo, el invariante se indica mediante un comentario junto al miembro `denominador`. Además, se le asigna el valor inicial `1`, de modo que el objeto tenga un denominador válido cuando no se especifique otro valor durante su creación.

Sin embargo, esta medida por sí sola no evita que el invariante sea incumplido. En `main`, por ejemplo, podemos crear directamente un objeto con `denominador` igual a `0` inicializando directamente los miembros. Aunque el objeto se crea correctamente desde el punto de vista de la sintaxis del programa, ahora se encuentra en un estado inválido.

El problema aparece cuando intentamos utilizar ese objeto. Al llamar a `imprimir_valor_fraccion`, el programa intenta dividir `5` entre `0`, lo que provoca un error.

En un ejemplo tan sencillo como este, puede resultar fácil recordar que el denominador nunca debe ser `0`. No obstante, en programas más grandes la situación puede complicarse. Un registro puede tener muchos miembros y estos pueden depender unos de otros de distintas maneras. En esos casos, puede ser difícil identificar qué combinaciones de valores producen un objeto válido y cuáles hacen que su estado sea inválido.

## Un Invariante De Clase Mas Complejo

El invariante de clase del tipo `Fraccion` es bastante sencillo: el miembro `denominador` no debe tomar el valor `0`. Es una regla fácil de comprender y de respetar.

Sin embargo, la situación se vuelve más complicada cuando los miembros de un registro están relacionados entre sí y sus valores deben mantenerse coordinados.

```cpp
#include <string>

struct Empleado
{
    std::string nombre { };
    char inicial_nombre { }; // debe contener el primer carácter de `nombre` (o 0)
};
```

En este ejemplo, el miembro `inicial_nombre` debe corresponder siempre al primer carácter almacenado en `nombre`. Esto establece una relación que debe conservarse para que el objeto permanezca en un estado válido.

El problema es que la estructura permite modificar ambos miembros por separado. Al crear un objeto `Empleado`, el usuario debe asegurarse de que `inicial_nombre` corresponda con `nombre`. Del mismo modo, si posteriormente se cambia el valor de `nombre`, también será necesario actualizar `inicial_nombre`. Esta relación puede pasar desapercibida para quien utiliza la estructura y, aunque la conozca, podría olvidar actualizar alguno de los miembros.

Una posible solución sería crear funciones que se encarguen de construir y modificar los objetos `Empleado`, haciendo que `inicial_nombre` se actualice automáticamente a partir de `nombre`. Aun así, esta solución sigue dependiendo de que el usuario conozca esas funciones y las utilice correctamente.

Por lo tanto, hacer que el usuario sea responsable de mantener los invariantes de un objeto puede facilitar la aparición de errores, especialmente a medida que el programa se vuelve más grande y complejo.

Lo ideal sería que nuestros tipos de clase pudieran proteger sus propios datos, evitando que un objeto entrara en un estado inválido o detectando inmediatamente cuando esto sucediera. De esta manera, los errores podrían identificarse en el momento en lugar de manifestarse más adelante mediante comportamientos inesperados o indefinidos.

Sin embargo, los registros, debido a la forma en como funcionan, no ofrecen los mecanismos necesarios para controlar estas situaciones de una manera sencilla y adecuada.

# Introducción A Las Clases 

Durante el desarrollo de C++, Bjarne Stroustrup (creador de C++) buscaba incorporar mecanismos que permitieran a los programadores crear **tipos definidos por el usuario** que pudieran utilizarse de una manera más intuitiva. También estaba interesado en encontrar soluciones elegantes para algunos de los problemas frecuentes y las dificultades de mantenimiento que aparecen en programas grandes y complejos, como el problema de los invariantes de clase mencionado anteriormente.

A partir de su experiencia con otros lenguajes de programación, especialmente con **Simula**, considerado el primer lenguaje de programación orientado a objetos, Bjarne llegó a la conclusión de que era posible crear un tipo definido por el usuario lo suficientemente general y poderoso como para utilizarse en una gran variedad de situaciones. Como referencia a Simula, decidió llamar a este nuevo tipo **clase**.

Al igual que los registros, una **clase** es un tipo de dato estructurado definido por el usuario que puede contener múltiples variables miembro de diferentes tipos.

## Definición De Una Clase 
A grandes rasgos, una clase tiene la misma sintaxis que un registro: 

```c++

class nombre_del_tipo 
{lista de miembros
     .
     .
     .

}; 
```

Para que veas que tan similares son un objeto de tipo `class` y uno de tipo `struct`, observa el siguiente programa: 
```cpp
#include <iostream>

class Fecha
{
public:
    int m_dia{};
    int m_mes{};
    int m_anio{};
};

void imprimir_fecha(const Fecha& fecha)
{
    std::cout << fecha.m_dia << '/' << fecha.m_mes << '/' << fecha.m_anio;
}

int main()
{
    Fecha fecha{4, 10, 21};
    imprimir_fecha(fecha);

    return 0;
}
```

La salida es:

```c++
4/10/21
```
Quizas te preguntes que es `public`. Tranquilo, en el transcurso de esta unidad lo iremos desarrollando.