# Herencia

En muchos casos, es posible organizar distintos conceptos mediante una **jerarquía de herencia**, en la que cada concepto adquiere las propiedades del concepto que se encuentra inmediatamente por encima de él. Un ejemplo consiste en clasificar distintos tipos de vehículos de acuerdo con una jerarquía de este tipo: 


A medida que se desciende en la jerarquía, cada tipo de vehículo se vuelve más específico que su concepto padre y que los demás conceptos de los que desciende. Al mismo tiempo, es más general que sus propios conceptos hijos y que todos los que se encuentran por debajo de ellos.

Por ejemplo, un vehículo con ruedas hereda las características comunes a todos los vehículos, como transportar a una o varias personas de un lugar a otro, y añade una característica particular: tener ruedas. Por su parte, un automóvil hereda las propiedades de los vehículos con ruedas y agrega otras características más específicas, como tener cuatro ruedas, un motor y una carrocería.

La herencia representa una relación de tipo **"es un"** entre distintos conceptos. Por ejemplo, un automóvil de dos puertas es un automóvil, un automóvil es un vehículo con ruedas y un vehículo con ruedas es un vehículo.

Los lenguajes de programación orientada a objetos permiten establecer relaciones de herencia entre clases. La **herencia** es un mecanismo mediante el cual una clase puede adquirir las propiedades y operaciones definidas en otra clase.

Para comprender cómo funciona, consideremos una clase `A`, denominada **clase base** o **superclase**, a partir de la cual se define una nueva clase `B`, llamada **clase derivada** o **subclase**. Mediante la herencia, la clase `B` puede disponer de las propiedades y operaciones heredables de `A`. Esto significa que los datos y las operaciones definidos en la clase base también pueden formar parte de la clase derivada, de acuerdo con las reglas de acceso del lenguaje. De esta manera, se mantiene la relación **"es un"**: todo objeto de la clase `B` también pertenece al tipo `A` en el sentido de la herencia.

A partir de esta relación, es posible especializar la clase derivada incorporando nuevas propiedades y operaciones que complementen las heredadas de la clase base. Así, se pueden construir clases más específicas sin tener que volver a definir desde cero las características que ya comparten con otras clases.

## Derivar Una Clase De Otra 

Supongamos que queremos ampliar nuestra ya conocida clase `Tiempo` para que también almacene información sobre el huso horario. Para ello, podemos agregar un miembro privado de tipo enumeración que permita representar los siguientes husos horarios de Estados Unidos: `EST` (*Eastern Standard Time*), `CST` (*Central Standard Time*), `MST` (*Mountain Standard Time*), `PST` (*Pacific Standard Time*), `EDT` (*Eastern Daylight Time*), `CDT` (*Central Daylight Time*), `MDT` (*Mountain Daylight Time*) y `PDT` (*Pacific Daylight Time*).

Esta modificación requiere ampliar la función `establecer` y los constructores para que, además de las horas, los minutos y los segundos, reciban un valor que indique el huso horario. Asimismo, la función `escribir` deberá mostrar esta información junto con la hora. Por ejemplo:

```text
12:34:10 CST
```

Por otro lado, no es necesario modificar la función `incrementar`, ya que su propósito sigue siendo avanzar el tiempo un segundo, independientemente del huso horario almacenado.

Una alternativa para incorporar estas características consistiría en modificar directamente el código fuente de la clase `Tiempo`, analizar su implementación en el archivo `Tiempo.cpp` y volver a compilar el programa. Sin embargo, este procedimiento presenta varios inconvenientes.

En primer lugar, es posible que el código fuente de la clase no esté disponible, especialmente si forma parte de una biblioteca o de un sistema desarrollado por terceros. Además, aunque tuviéramos acceso a él, modificar una implementación que ya funciona correctamente podría introducir errores nuevos. Por último, depender del conocimiento de los detalles internos de una clase contradice uno de los objetivos de la abstracción: permitir que los usuarios aprovechen sus funcionalidades sin necesidad de conocer cómo están implementadas.

En C++, como en otros lenguajes orientados a objetos, existe una alternativa que permite extender las funcionalidades de una clase sin modificar directamente su implementación original: **la herencia**. Mediante este mecanismo, podemos definir una nueva clase a partir de `Tiempo` y añadirle las características necesarias. Llamaremos `Tiempo_extendido` a esta nueva clase, que heredará los miembros accesibles de su clase base.

La declaración de `Tiempo_extendido` podría escribirse de la siguiente manera:

```cpp
enum Tipo_zona_horaria
{
    est,
    cst,
    mst,
    pst,
    edt,
    cdt,
    mdt,
    pdt
};

class Tiempo_extendido : public Tiempo
{
public:
    void establecer(
        int horas,
        int minutos,
        int segundos,
        Tipo_zona_horaria zona);

    void escribir() const;

    Tipo_zona_horaria obtener_zona_horaria() const;

    Tiempo_extendido(
        int horas_iniciales,
        int minutos_iniciales,
        int segundos_iniciales,
        Tipo_zona_horaria zona_inicial);

    Tiempo_extendido();

private:
    Tipo_zona_horaria zona_horaria;
};
```

La expresión `class Tiempo_extendido : public Tiempo` indica que `Tiempo_extendido` es una clase derivada de `Tiempo`. El especificador `public` establece una relación de herencia pública, mediante la cual los miembros públicos de la clase base continúan siendo accesibles a través de los objetos de la clase derivada, siempre que no exista alguna restricción adicional.

Por ejemplo, las funciones `establecer`, `incrementar` y `escribir` forman parte de la interfaz pública de `Tiempo`. La nueva clase proporciona sus propias declaraciones de `establecer` y `escribir` para incorporar el tratamiento del huso horario, mientras que puede seguir utilizando la función heredada `incrementar`, pues su comportamiento no necesita cambiar. También se añade la función `obtener_zona_horaria`, que permite consultar el huso horario asociado al objeto.

En la sección privada de `Tiempo_extendido` se declara el nuevo miembro `zona_horaria`, cuyo tipo es `Tipo_zona_horaria`. De esta manera, la clase derivada incorpora información adicional a la que ya proporciona `Tiempo`. Los miembros privados de la clase base, en cambio, siguen perteneciendo a la implementación de `Tiempo` y no pueden manipularse directamente desde las funciones miembro de la clase derivada; para trabajar con ellos deben utilizarse las operaciones accesibles proporcionadas por la clase base.

Esta relación puede entenderse mediante la idea de que cada objeto de tipo `Tiempo_extendido` contiene un subobjeto correspondiente a `Tiempo`. Por tanto, un objeto de `Tiempo_extendido` puede considerarse un `Tiempo` al que se han añadido características adicionales: conserva las funcionalidades heredadas y dispone de información sobre el huso horario.

En C++, se utilizan los términos **clase base** y **clase derivada** para describir esta relación. También es posible encontrar las denominaciones *superclase* y *subclase*, aunque las primeras son las empleadas habitualmente en la terminología de C++. El término *subclase* puede resultar confuso, ya que una clase derivada no necesariamente es más pequeña que su clase base; de hecho, con frecuencia incorpora más datos y operaciones.

Por último, cuando una función de la clase base se hereda públicamente y no se declara una función equivalente en la clase derivada, su funcionalidad sigue estando disponible para los usuarios de esta última. Así ocurre con `incrementar`: como `Tiempo_extendido` no necesita redefinirla, puede utilizar la implementación heredada de `Tiempo` para avanzar el tiempo un segundo. Esta continuidad permite ampliar una clase sin tener que repetir las operaciones que ya funcionan correctamente.


## Especificación De La Clase `Tiempo_extendido`

A continuación, veremos la especificación de la clase `Tiempo_extendido`, acompañada de su documentación correspondiente.

Como nota importante, la directiva del preprocesador `#include "tiempo.h"` permite incluir la declaración de la clase `Tiempo` antes de definir `Tiempo_extendido`. Esto es necesario para que el compilador conozca la clase base y pueda comprobar que la relación de herencia está correctamente declarada.

El siguiente código corresponde al archivo de especificación `tiempo_extendido.h`:

```cpp
//***************************************************************************
// ARCHIVO DE ESPECIFICACIÓN: tiempo_extendido.h
// Este archivo define la interfaz del tipo de dato abstracto
// Tiempo_extendido.
//
// La clase Tiempo es una clase base pública de Tiempo_extendido.
// Por ello, las operaciones públicas heredadas de Tiempo también
// pueden utilizarse mediante objetos de Tiempo_extendido.
//***************************************************************************

#include "tiempo.h"

enum Tipo_zona_horaria
{
    est,
    cst,
    mst,
    pst,
    edt,
    cdt,
    mdt,
    pdt
};

class Tiempo_extendido : public Tiempo
{
public:
    void establecer(
        int horas,
        int minutos,
        int segundos,
        Tipo_zona_horaria zona);

    // Precondición:
    // 0 <= horas <= 23, 0 <= minutos <= 59 y
    // 0 <= segundos <= 59.
    // zona debe ser un valor válido de Tipo_zona_horaria.
    //
    // Poscondición:
    // El tiempo y el huso horario del objeto se establecen
    // de acuerdo con los argumentos recibidos.

    void escribir() const;

    // Poscondición:
    // Se muestra el tiempo en el formato HH:MM:SS ZZZ,
    // donde ZZZ representa la abreviatura del huso horario.

    Tipo_zona_horaria obtener_zona_horaria() const;

    // Poscondición:
    // El valor devuelto corresponde al huso horario
    // almacenado en el objeto.

    Tiempo_extendido(
        int horas_iniciales,
        int minutos_iniciales,
        int segundos_iniciales,
        Tipo_zona_horaria zona_inicial);

    // Precondición:
    // 0 <= horas_iniciales <= 23,
    // 0 <= minutos_iniciales <= 59 y
    // 0 <= segundos_iniciales <= 59.
    // zona_inicial debe ser un valor válido de
    // Tipo_zona_horaria.
    //
    // Poscondición:
    // Se construye un objeto Tiempo_extendido cuyo
    // tiempo y huso horario corresponden a los
    // argumentos recibidos.

    Tiempo_extendido();

    // Poscondición:
    // Se construye un objeto cuyo tiempo es 00:00:00
    // y cuyo huso horario es el estándar del este (EST).

private:
    Tipo_zona_horaria zona_horaria;
};
```

Mediante esta clase, el programador puede establecer una hora junto con su huso horario, ya sea utilizando el constructor con argumentos o la función `establecer`. También puede mostrar ambos datos mediante la función `escribir` y consultar el huso horario con `obtener_zona_horaria`.

Además, la clase conserva la funcionalidad heredada de `Tiempo` para avanzar el reloj un segundo mediante la función `incrementar`. No es necesario volver a implementarla, pues su comportamiento no cambia al añadir el huso horario.


Por otro lado, el siguiente programa muestra cómo utilizar la clase `Tiempo_extendido` desde un programa cliente. En él se crean dos objetos, se muestran sus valores iniciales, se modifica uno de ellos y se comprueba el funcionamiento de la operación heredada `incrementar`.

El código corresponde al archivo `demostracion_tiempo.cpp`:

```cpp
//***************************************************************************
// Programa: demostracion_tiempo.cpp
// Ejemplo de uso de la clase Tiempo_extendido.
//***************************************************************************

#include <iostream>
#include "tiempo_extendido.h"

 using namespace std;


int main()
{
    // Se utiliza el constructor con argumentos.
    Tiempo_extendido tiempo1(5, 30, 0, cdt);

    // Se utiliza el constructor por omisión.
    Tiempo_extendido tiempo2;

    int contador;

    cout << "tiempo1: ";
    tiempo1.escribir();

    cout << "\ntiempo2: ";
    tiempo2.escribir();

    cout << '\n';

    // Se establece una nueva hora para tiempo2.
    tiempo2.establecer(23, 59, 55, pst);

    cout << "Nuevo tiempo2: ";
    tiempo2.escribir();

    cout << "\nIncrementando tiempo2:\n";

    for (contador = 1; contador <= 10; contador++)
    {
        tiempo2.escribir();
          cout << ' ';

        tiempo2.incrementar();
    }

    return 0;
}
```

Al ejecutar el programa, se obtiene una salida coo esta:

```text
tiempo1: 05:30:00 CDT
tiempo2: 00:00:00 EST
Nuevo tiempo2: 23:59:55 PST
Incrementando tiempo2:
23:59:55 PST 23:59:56 PST 23:59:57 PST 23:59:58 PST 23:59:59 PST
00:00:00 PST 00:00:01 PST 00:00:02 PST 00:00:03 PST 00:00:04 PST
```

