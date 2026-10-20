# Programación Orientada A Objetos

Como recordarás, los antecedentes de la programación orientada a objetos se remontan a mediados de la década de 1960, con la aparición del lenguaje Simula. Sin embargo, buena parte de los términos que se utilizan actualmente en este paradigma provienen de Smalltalk, un lenguaje desarrollado a finales de los años setenta.

En programación orientada a objetos, un **objeto** es una entidad que reúne datos y las operaciones que permiten trabajar con ellos. Desde esta perspectiva, un objeto constituye una instancia de un tipo de dato abstracto. Cada objeto mantiene un estado interno, determinado por los valores de sus datos privados, conocidos como *variables de instancia* o *atributos*, y ofrece un conjunto de operaciones públicas llamadas *métodos*.

Los métodos constituyen la interfaz mediante la cual otros objetos pueden consultar o modificar el estado de un objeto. De esta manera, el acceso a los datos internos se controla a través de las operaciones que este proporciona.

Un programa con diseño orientado a objetos está formado por un conjunto de objetos que interactúan entre sí mediante el envío de mensajes. Por ejemplo, si tenemos un par de objetos A y B, y además el objeto A necesita que el objeto B realice una tarea, entonces A le envía a B un mensaje que identifica la operación que debe ejecutar. El objeto B responde llevando a cabo la operación correspondiente y, como resultado, puede modificar su propio estado o comunicarse con otros objetos.

Esta forma de organizar un programa permite distinguir los objetos de las estructuras de datos tradicionales. Por ejemplo, una `struct` suele utilizarse para agrupar datos sobre los que actúan otras partes del programa. En cambio, en el diseño orientado a objetos, los datos y las operaciones que los manipulan se reúnen en una misma entidad. Por ello, se dice que un objeto no solo contiene información, sino que también dispone de los métodos necesarios para trabajar con ella.

Cabe señalar que, en C++, tanto una `struct` como una `class` pueden incluir funciones miembro. La diferencia fundamental no consiste en que las `structs` sean incapaces de tener este tipo de funciones, sino en la forma en que se diseñan y organizan los tipos de datos.

La terminología de la programación orientada a objetos está muy influida por Smalltalk. Por este motivo, es habitual encontrar expresiones como *método*, *variable de instancia*, *atributo* y *envío de mensajes*. A continuación, revisaremos algunos de estos conceptos mediante la clase `Tiempo`, definida anteriormente para representar el tipo de dato abstracto que modela el tiempo, y adaptaremos su diseño para incorporar los principios y el vocabulario de la programación orientada a objetos.

## Responsabilidades De Los Objetos

En el diseño orientado a objetos, los métodos que ofrece una clase también pueden interpretarse como sus **responsabilidades**. La versión inicial de `Tiempo` contaba con siete métodos: cinco funciones miembro (`establecer`, `incrementar`, `escribir`, `igual` y `menor_que`) y dos constructores. Uno de los constructores recibía las horas, los minutos y los segundos como argumentos; el otro inicializaba el tiempo en cero.

Las responsabilidades de un objeto pueden clasificarse en dos categorías: **responsabilidades de acción** y **responsabilidades de conocimiento**.

Las responsabilidades de acción corresponden a las operaciones que ejecutan una tarea o producen algún resultado. Las funciones originales de `Tiempo` pertenecen a esta categoría, pues permiten modificar el tiempo, incrementarlo, mostrarlo o compararlo con otro valor.

Por otra parte, un objeto también debe ofrecer mecanismos para informar sobre su estado interno. Para ello, se pueden incluir funciones que permitan consultar los valores de sus datos privados sin modificarlos. Estas operaciones pueden complementar a `escribir`, o incluso sustituirla, ya que permiten que el programa cliente decida cómo utilizar y presentar la información obtenida mediante el tipo de dato abstracto.

Las funciones que devuelven información acerca de los datos internos de un objeto se denominan **responsabilidades de conocimiento**. En nuestro ejemplo, añadiremos tres funciones para consultar por separado las horas, los minutos y los segundos. También incorporaremos una función que permita solicitar estos tres valores al usuario mediante la entrada estándar.

Acá tenemos la especificación y la implementación de `Tiempo`: 

```cpp
//***************************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Tiempo.h)
//
// Declara la clase Tiempo y sus responsabilidades de acción
// y de conocimiento.
//***************************************************************************

class Tiempo
{
public:
    // Responsabilidades de acción

    void establecer(
        /* entrada */ int horas,
        /* entrada */ int minutos,
        /* entrada */ int segundos
    );

    void incrementar();

    void escribir() const;

    bool es_igual(/* entrada */ Tiempo otro_tiempo) const;

    bool es_menor_que(/* entrada */ Tiempo otro_tiempo) const;

    Tiempo(
        /* entrada */ int horas_iniciales,
        /* entrada */ int minutos_iniciales,
        /* entrada */ int segundos_iniciales
    );

    Tiempo();

    void leer_tiempo();

    // Poscondición:
    // Se solicitaron y leyeron las horas, los minutos y los segundos.

    // Responsabilidades de conocimiento

    int obtener_horas() const;

    // Poscondición:
    // El valor devuelto corresponde a las horas.

    int obtener_minutos() const;

    // Poscondición:
    // El valor devuelto corresponde a los minutos.

    int obtener_segundos() const;

    // Poscondición:
    // El valor devuelto corresponde a los segundos.

private:
    int horas;
    int minutos;
    int segundos;
};
```



```cpp
//***************************************************************************
// ARCHIVO DE IMPLEMENTACIÓN (Tiempo.cpp)
//
// Contiene las definiciones de las funciones miembro de Tiempo.
//***************************************************************************

#include "Tiempo.h"
#include <iostream>

using namespace std;
//***************************************************************************

int Tiempo::obtener_horas() const
// Poscondición:
// El valor devuelto corresponde a las horas.
{
    return horas;
}

//***************************************************************************

int Tiempo::obtener_minutos() const
// Poscondición:
// El valor devuelto corresponde a los minutos.
{
    return minutos;
}

//***************************************************************************

int Tiempo::obtener_segundos() const
// Poscondición:
// El valor devuelto corresponde a los segundos.
{
    return segundos;
}

//***************************************************************************

void Tiempo::leer_tiempo()
// Poscondición:
// Se solicitaron y leyeron las horas, los minutos y los segundos,
// y sus valores se guardaron en los datos correspondientes.
{
    cout << "Introduce las horas (0 a 23):\n";
    cin >> horas;

    cout << "Introduce los minutos (0 a 59):\n";
    cin >> minutos;

    cout << "Introduce los segundos (0 a 59):\n";
    cin >> segundos;
}

//***************************************************************************
```

