# Implementación Y Especificación

Un tipo de dato abstracto está compuesto por dos elementos principales: una **especificación** y una **implementación**. La especificación establece qué comportamiento ofrece el tipo de dato y cuáles son las operaciones que pueden realizarse con él, sin explicar los detalles de su funcionamiento interno. Por su parte, la implementación se encarga de definir cómo se representan los datos y cómo se llevan a cabo dichas operaciones. De esta manera, se establece una barrera de abstracción que separa el uso del tipo de dato de los detalles necesarios para construirlo.

En C++, la declaración de una clase puede funcionar como la especificación de un TDA. En ella se presenta la interfaz pública mediante las declaraciones de sus funciones miembro, indicando qué operaciones están disponibles para el código cliente. Para completar la implementación de la clase, es necesario proporcionar las definiciones de estas funciones, es decir, el código que describe cómo se ejecuta cada operación.

Aunque C++ no exige que la declaración y la implementación de una clase se almacenen en archivos diferentes, es una práctica habitual organizarlas por separado. Para ello, suelen utilizarse dos archivos: un **archivo de especificación**, generalmente con extensión `.h`, que contiene la declaración de la clase; y un **archivo de implementación**, que contiene las definiciones de sus funciones miembro.

## Archivo De Especificación

A continuación, se presenta la especificación de la clase `Tiempo`, almacenada en el archivo `Tiempo.h`. Además de declarar las funciones miembro y los datos privados, se incluyen sus precondiciones y poscondiciones para explicar con mayor precisión el comportamiento esperado de cada operación.

Las **precondiciones** indican qué condiciones deben cumplirse antes de ejecutar una función, mientras que las **poscondiciones** describen el resultado que debe producir cuando se cumplen dichas condiciones.

```cpp
//******************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Tiempo.h)
//
// Este archivo contiene la especificación del tipo de dato
// abstracto Tiempo.
//******************************************************************

class Tiempo
{
public:
    void establecer(/* entrada */ int horas_entrada,
                    /* entrada */ int minutos_entrada,
                    /* entrada */ int segundos_entrada);

    // Precondición:
    // 0 <= horas_entrada <= 23
    // 0 <= minutos_entrada <= 59
    // 0 <= segundos_entrada <= 59
    //
    // Poscondición:
    // El tiempo queda establecido de acuerdo con los
    // valores recibidos como parámetros.
    //
    // Nota:
    // Esta función debe invocarse antes de utilizar
    // cualquiera de las demás funciones miembro.

    void incrementar();

    // Precondición:
    // La función establecer ha sido invocada al menos una vez.
    //
    // Poscondición:
    // El tiempo avanza un segundo. Si el tiempo era
    // 23:59:59, vuelve a comenzar en 00:00:00.

    void escribir() const;

    // Precondición:
    // La función establecer ha sido invocada al menos una vez.
    //
    // Poscondición:
    // El tiempo se muestra con el formato HH:MM:SS.

    bool es_igual(/* entrada */ Tiempo otro_tiempo) const;

    // Precondición:
    // La función establecer ha sido invocada al menos una vez
    // para este objeto y para otro_tiempo.
    //
    // Poscondición:
    // Devuelve true si ambos objetos representan el mismo
    // tiempo y false en caso contrario.

    bool es_menor_que(/* entrada */ Tiempo otro_tiempo) const;

    // Precondición:
    // La función establecer ha sido invocada al menos una vez
    // para este objeto y para otro_tiempo.
    // Ambos objetos representan tiempos del mismo día.
    //
    // Poscondición:
    // Devuelve true si este objeto representa un tiempo
    // anterior al de otro_tiempo y false en caso contrario.

private:
    int horas;
    int minutos;
    int segundos;
};
```

Puedes notar que algunas funciones tienen precondiciones que deben cumplirse antes de utilizarlas. Por ejemplo, antes de invocar `incrementar`, `escribir` o `es_menor_que`, el cliente debe asegurarse de que los tiempos correspondientes hayan sido establecidos previamente mediante `establecer`. Si no se cumple esta condición, el comportamiento esperado de las operaciones no está garantizado por la especificación.

En principio, un archivo de especificación debe describir qué hace cada función miembro sin revelar cómo realiza su trabajo. Sin embargo, en el ejemplo anterior existe un detalle de implementación que puede observarse directamente: la representación de los datos mediante las variables privadas `horas`, `minutos` y `segundos`.

A pesar de que estos miembros aparecen en la declaración de la clase, siguen estando protegidos frente al acceso directo del código cliente. Esto se debe a que están declarados en la sección `private`, por lo que el compilador impide consultarlos o modificarlos directamente desde fuera de la clase. En consecuencia, el cliente debe utilizar las funciones de la interfaz pública para interactuar con el objeto.

Así, la ocultación de información no depende exclusivamente de que los detalles internos permanezcan fuera del archivo de especificación, sino también de que el lenguaje establezca mecanismos que restrinjan el acceso directo a esos detalles. De esta manera, la clase conserva el control sobre la interacción con sus datos y puede ofrecer operaciones bien definidas sin exponer su funcionamiento interno.

## Archivo De Implementación

El archivo de especificación (`.h`) de la clase `Tiempo` contiene únicamente su declaración. Para completar la clase, se necesita un archivo de implementación que incluya las definiciones de todas sus funciones miembro, es decir, el código que establece cómo se ejecuta cada operación. En este ejemplo, el archivo se denomina `Tiempo.cpp`, aunque la extensión utilizada para los archivos de código fuente puede variar según el compilador o el entorno de desarrollo.

A continuación, se presenta el código de implementación de la clase `Tiempo`. Por ahora, intenta concentrarte en comprender que hace cada función. Cosas como el operador `::` los veremos mas adelante.


```cpp
//******************************************************************
// ARCHIVO DE IMPLEMENTACIÓN (Tiempo.cpp)
//
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Tiempo.
//******************************************************************

#include "Tiempo.h"
#include <iostream>

using namespace std; 
//******************************************************************
void Tiempo::establecer(/* entrada */ int horas_entrada,
                        /* entrada */ int minutos_entrada,
                        /* entrada */ int segundos_entrada)

// Precondición:
// 0 <= horas_entrada <= 23
// 0 <= minutos_entrada <= 59
// 0 <= segundos_entrada <= 59
//
// Poscondición:
// horas == horas_entrada
// minutos == minutos_entrada
// segundos == segundos_entrada
//
// Nota:
// Esta función debe invocarse antes que cualquier otra
// función miembro.

{
    horas = horas_entrada;
    minutos = minutos_entrada;
    segundos = segundos_entrada;
}

//******************************************************************
void Tiempo::incrementar()

// Precondición:
// La función establecer ha sido invocada al menos una vez.
//
// Poscondición:
// El tiempo avanza un segundo. Si llega a 23:59:59,
// vuelve a comenzar en 00:00:00.

{
    segundos++;

    if (segundos > 59)
    {
        segundos = 0;
        minutos++;

        if (minutos > 59)
        {
            minutos = 0;
            horas++;

            if (horas > 23)
                horas = 0;
        }
    }
}

//******************************************************************
void Tiempo::escribir() const

// Precondición:
// La función establecer ha sido invocada al menos una vez.
//
// Poscondición:
// El tiempo se muestra con el formato HH:MM:SS.

{
    if (horas < 10)
        std::cout << '0';

        cout << horas << ':';

    if (minutos < 10)
        cout << '0';

        cout << minutos << ':';

    if (segundos < 10)
        cout << '0';

        cout << segundos;
}

//******************************************************************
bool Tiempo::es_igual(/* entrada */ Tiempo otro_tiempo) const

// Precondición:
// La función establecer ha sido invocada al menos una vez
// para este objeto y para otro_tiempo.
//
// Poscondición:
// Devuelve true si ambos objetos representan el mismo tiempo;
// en caso contrario, devuelve false.

{
    return (horas == otro_tiempo.horas &&
            minutos == otro_tiempo.minutos &&
            segundos == otro_tiempo.segundos);
}

//******************************************************************
bool Tiempo::es_menor_que(/* entrada */ Tiempo otro_tiempo) const

// Precondición:
// La función establecer ha sido invocada al menos una vez
// para este objeto y para otro_tiempo.
// Ambos objetos representan tiempos del mismo día.
//
// Poscondición:
// Devuelve true si este tiempo es anterior a otro_tiempo;
// en caso contrario, devuelve false.

{
    return (horas < otro_tiempo.horas ||
            (horas == otro_tiempo.horas &&
             minutos < otro_tiempo.minutos) ||
            (horas == otro_tiempo.horas &&
             minutos == otro_tiempo.minutos &&
             segundos < otro_tiempo.segundos));
}
```

Este archivo de implementación permite identificar varias características importantes del funcionamiento de las clases en C++.

1. Inclusión del archivo de especificación

Al comienzo del archivo aparece la directiva de preprocesador:

```cpp
#include "Tiempo.h"
```

Tanto el archivo de implementación como los archivos del código cliente que utilizan la clase deben incluir su archivo de especificación. Esto permite que todos trabajen con la misma declaración de `Tiempo` y evita que existan declaraciones incompatibles entre la clase y las partes del programa que la utilizan.

2. Referencia a los miembros privados

En el archivo de implementación se puede incluir un comentario que recuerde cuáles son los miembros privados de la clase:

```cpp
// Miembros privados de Tiempo:
// int horas;
// int minutos;
// int segundos;
```

Este comentario sirve como referencia para el programador. Cuando las funciones miembro utilizan los identificadores `horas`, `minutos` y `segundos` sin especificar un objeto, están haciendo referencia a los miembros del objeto sobre el que se ejecuta la función.

3. Uso del operador de resolución de alcance (`::`)

En los encabezados de las definiciones aparece el nombre de la clase seguido del operador `::`. Por ejemplo:

```cpp
void Tiempo::incrementar()
```

Esta notación indica que `incrementar` es una función miembro de la clase `Tiempo`. El operador `::` permite especificar a qué clase pertenece una función y evita confusiones cuando existen funciones con el mismo nombre en diferentes clases o en el ámbito global.

Así, aunque otras clases también tengan una función llamada `incrementar`, la expresión `Tiempo::incrementar` identifica específicamente la función miembro de `Tiempo`.

4. Acceso a los miembros desde las funciones miembro

Cuando el código cliente utiliza una función miembro, necesita indicar el objeto sobre el que desea ejecutarla mediante el operador punto (`.`). Por ejemplo:

```cpp
Tiempo tiempo_entrada;

tiempo_entrada.establecer(9, 30, 0);
tiempo_entrada.incrementar();
```

En cambio, dentro de las funciones miembro de la propia clase, es posible acceder directamente a sus miembros de datos sin escribir el nombre del objeto ni utilizar el operador punto.

Por ejemplo, en `incrementar`, las expresiones `segundos++`, `minutos++` y `horas++` modifican los miembros correspondientes del objeto sobre el que se invocó la función.

Existe una situación particular cuando una función miembro trabaja con dos objetos de la misma clase. Esto sucede en `es_igual` y `es_menor_que`. Consideremos la siguiente instrucción del código cliente:

```cpp
Tiempo tiempo_inicio;
Tiempo tiempo_final;

tiempo_inicio.establecer(8, 0, 0);
tiempo_final.establecer(10, 30, 0);

if (tiempo_inicio.es_igual(tiempo_final))
{
    // Instrucciones que se ejecutan si ambos tiempos son iguales.
}
```

En esta llamada, `tiempo_inicio` es el objeto sobre el que se ejecuta la función, mientras que `tiempo_final` se recibe como argumento mediante el parámetro `otro_tiempo`.

Por tanto, dentro de `es_igual`, la expresión:

```cpp
horas == otro_tiempo.horas
```

compara las horas de dos objetos diferentes. El identificador `horas`, escrito sin el operador punto, hace referencia al miembro del objeto sobre el que se invocó la función, en este caso `tiempo_inicio`. Por otro lado, `otro_tiempo.horas` hace referencia al miembro `horas` del objeto recibido como argumento, que corresponde a `tiempo_final`.

Aunque `horas` es un miembro privado, la función miembro puede acceder también a los miembros privados de otros objetos de la misma clase. Esta característica permite comparar sus datos sin hacerlos públicos ni permitir que el código cliente acceda directamente a ellos.


5. Funciones miembro constantes

Las funciones `escribir`, `es_igual` y `es_menor_que` son funciones de observación, ya que consultan los datos del objeto sin modificarlos. Por este motivo, sus declaraciones incluyen la palabra clave `const` al final de la lista de parámetros:

```cpp
void escribir() const;
bool es_igual(Tiempo otro_tiempo) const;
bool es_menor_que(Tiempo otro_tiempo) const;
```

Estas funciones se conocen como **funciones miembro constantes**. Al declararlas de esta manera, el programador indica que no deben modificar el estado del objeto sobre el que se ejecutan. El compilador ayuda a garantizar esta condición al impedir modificaciones directas de sus miembros de datos no estáticos dentro de estas funciones.

El uso de `const` beneficia tanto a quien utiliza la clase como a quien la implementa: permite reconocer cuáles funciones están destinadas a consultar información y ayuda a detectar modificaciones accidentales. Es importante que esta palabra aparezca tanto en la declaración de la función dentro de la clase como en su definición en el archivo de implementación.

En conjunto, la separación entre el archivo de especificación y el archivo de implementación facilita la ocultación de información. El código cliente conoce las operaciones disponibles a través de la interfaz pública, mientras que los detalles de cómo se ejecutan dichas operaciones permanecen en el archivo de implementación.

## Compilación

Una vez que se han creado el archivo de especificación y el archivo de implementación de la clase `Tiempo`, es necesario comprender cómo se utilizan ambos archivos dentro de un programa. Para ello, primero debemos estudiar el concepto de *compilación separada*, que permite organizar un programa de C++ en varios archivos de código fuente.

Un programa que se distribuye en distintos archivos de código fuente se conoce como programa multiarchivo. En C++, cada uno de estos archivos puede compilarse de manera independiente, sin necesidad de compilar nuevamente todo el programa cada vez que se realiza una modificación.

Durante la compilación, cada archivo de código fuente se traduce a un archivo de código objeto. Por ejemplo, si un programa está formado por los archivos `programa.cpp`, `archivo_2.cpp` y `archivo_3.cpp`, cada uno puede compilarse por separado para generar sus correspondientes archivos de código objeto: `programa.o`, `archivo_2.o` y `archivo_3.o`. Estos archivos contienen código máquina, pero todavía necesitan combinarse para producir un programa ejecutable.

Esta combinación se realiza mediante enlazador o linker. Su función consiste en reunir los archivos de código objeto y resolver las referencias entre ellos para generar el archivo ejecutable. Las extensiones utilizadas para estos archivos dependen del sistema y de las herramientas de compilación; por ejemplo, algunos entornos utilizan `.o` para los archivos de código objeto, mientras que otros emplean `.obj`.

Por lo general, los archivos secundarios de un programa contienen definiciones de funciones que son utilizadas por otros archivos. Una ventaja importante de la compilación separada es que, cuando se modifica uno de ellos, normalmente solo es necesario volver a compilar ese archivo y enlazar nuevamente el programa con los archivos de código objeto que no han cambiado.

Sin embargo, si una modificación afecta a otros archivos, también puede ser necesario actualizarlos y compilarlos de nuevo. Esto ocurre, por ejemplo, cuando se modifica la interfaz de una función y cambia el número o el tipo de sus parámetros, ya que las partes del programa que utilizan esa función deben adaptarse a la nueva declaración.

Ahora, para nuestro ejemplo, supongamos que ya se han creado los archivos `Tiempo.h` y `Tiempo.cpp`. El primero contiene la declaración de la clase, mientras que el segundo incluye las definiciones de sus funciones miembro.

El archivo de implementación puede compilarse por separado desde la línea de comandos mediante una instrucción como la siguiente:

```text g++ -c Tiempo.cpp -o Tiempo.o```

En este comando, g++ invoca al compilador de C++, mientras que la opción `-c` indica que se debe compilar el archivo sin realizar el enlazado final. Por su parte, `-o Tiempo.o` especifica el nombre del archivo de código objeto que se generará.

Una vez obtenido `Tiempo.o`, el archivo de implementación ya no necesita compilarse cada vez que otro programa utilice la clase, siempre que no sea necesario modificarla ni actualizar su archivo de código objeto.

Para utilizar la clase, otro programador puede escribir un archivo de código cliente que incluya `Tiempo.h` y declare objetos de tipo `Tiempo`. Por ejemplo, el archivo `agenda.cpp` podría contener lo siguiente:
```c++
#include "Tiempo.h"

int main()
{
    Tiempo cita;

    cita.establecer(15, 30, 0);
    cita.escribir();

    return 0;
}
```

En este caso, el programa incluye el archivo de especificación para conocer la declaración de la clase `Tiempo`. Después, crea un objeto llamado `cita`, establece su valor a las `15:30:00` e invoca la función miembro `escribir` para mostrar el tiempo.

Para generar el ejecutable, podemos compilar el archivo cliente y enlazarlo con el archivo de código objeto de la clase. Una forma de hacerlo es mediante el siguiente comando:

```text g++ agenda.cpp Tiempo.o -o agenda ```

Esta instrucción compila el código cliente y lo enlaza con `Tiempo.o` para producir un programa ejecutable llamado `agenda`. Los nombres y las extensiones de los archivos resultantes pueden variar según el sistema operativo y el compilador utilizado.

La forma de compilar, enlazar y ejecutar un programa depende de las herramientas disponibles en cada sistema. En los ejemplos anteriores se ha supuesto que se trabaja directamente con la terminal.

Sin embargo, muchos entornos de desarrollo (como Visual Studio Code), reúnen en una misma aplicación herramientas para editar, compilar y enlazar código. Algunos también identifican la ubicación de los errores de compilación o enlazado y permiten regresar directamente a la parte del código que debe corregirse.

Además, los entornos de desarrollo suelen permitir organizar los archivos de un programa mediante proyectos. Estos proyectos almacenan información sobre los archivos que lo componen y las relaciones entre ellos. De esta manera, el entorno puede detectar qué archivos necesitan compilarse nuevamente después de una modificación y realizar automáticamente las operaciones de compilación y enlazado necesarias.

Aunque las herramientas y los procedimientos específicos varían, el proceso general sigue siendo el mismo: se compilan los archivos de código fuente para generar archivos de código objeto, se enlazan estos últimos para construir el ejecutable y, finalmente, se ejecuta el programa.

Antes de concluir, conviene destacar un aspecto importante de la relación entre los archivos `Tiempo.h` y `Tiempo.cpp`. Para que otras personas puedan utilizar la clase `Tiempo`, es suficiente con proporcionarles el archivo de especificación y el archivo de código objeto correspondiente, siempre que este último sea compatible con su entorno de compilación. No es indispensable compartir el archivo `Tiempo.cpp`.

El archivo `Tiempo.h` permite conocer las operaciones disponibles y la forma de utilizarlas, mientras que `Tiempo.o` contiene el código compilado necesario para enlazar esas operaciones con el programa cliente. En cambio, el archivo `Tiempo.cpp` contiene los detalles de implementación de la clase y puede mantenerse separado.

Esta organización refleja el principio de ocultación de información: quienes utilizan una abstracción deben poder trabajar con ella a partir de su especificación, sin tener que estudiar cómo está implementada internamente. De igual manera, el código cliente no debería depender de los detalles particulares de esa implementación.

Separar la interfaz de la implementación facilita el mantenimiento del software. Siempre que se respete la interfaz pública, es posible modificar la implementación de una clase sin obligar a los usuarios a cambiar el código que la utiliza. Así, la abstracción reduce la complejidad que debe manejar el programador y permite desarrollar programas más modulares, flexibles y fáciles de mantener.