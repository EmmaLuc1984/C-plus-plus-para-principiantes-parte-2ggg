
# Implementación Y Especificación

Un tipo de dato abstracto (TDA) está compuesto por dos elementos principales: una **especificación** y una **implementación**. La especificación establece qué comportamiento ofrece el tipo de dato y cuáles son las operaciones que pueden realizarse con él, sin explicar los detalles de su funcionamiento interno. Por su parte, la implementación se encarga de definir cómo se representan los datos y cómo se llevan a cabo dichas operaciones. De esta manera, se establece una barrera de abstracción que separa el uso del tipo de dato de los detalles necesarios para construirlo.

En C++, la declaración de una clase puede funcionar como la especificación de un TDA. En ella se presenta la interfaz pública mediante las declaraciones de sus funciones miembro, indicando qué operaciones están disponibles para el código cliente. Para completar la implementación de la clase, es necesario proporcionar las definiciones de estas funciones, es decir, el código que describe cómo se ejecuta cada operación.

Aunque C++ no exige que la declaración y la implementación de una clase se almacenen en archivos diferentes, es una práctica habitual organizarlas por separado. Para ello, suelen utilizarse dos archivos: un **archivo de especificación**, generalmente con extensión `.h`, que contiene la declaración de la clase; y un **archivo de implementación**, que contiene las definiciones de sus funciones miembro.

## Archivo de especificación

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

## Archivo de implementación

El archivo de especificación (`.h`) de la clase `Tiempo` contiene únicamente su declaración. Para completar la clase, se necesita un archivo de implementación que incluya las definiciones de todas sus funciones miembro, es decir, el código que establece cómo se ejecuta cada operación. En este ejemplo, el archivo se denomina `Tiempo.cpp`, aunque la extensión utilizada para los archivos de código fuente puede variar según el compilador o el entorno de desarrollo.

A continuación, se presenta el código de implementación de la clase `Tiempo`. Por ahora, conviene concentrarse en comprender las operaciones que realiza cada función, sin preocuparse demasiado por la sintaxis nueva que aparece en sus encabezados, particularmente el uso del nombre de la clase seguido del operador `::`.

### Código del archivo `Tiempo.cpp`

```cpp
//******************************************************************
// ARCHIVO DE IMPLEMENTACIÓN (Tiempo.cpp)
//
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Tiempo.
//******************************************************************

#include "Tiempo.h"
#include <iostream>

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

    std::cout << horas << ':';

    if (minutos < 10)
        std::cout << '0';

    std::cout << minutos << ':';

    if (segundos < 10)
        std::cout << '0';

    std::cout << segundos;
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

El uso de `const` beneficia tanto a quien utiliza la clase como a quien la implementa: permite reconocer cuáles funciones están destinadas a consultar información y ayuda a detectar modificaciones accidentales. Es importante que esta palabra clave aparezca tanto en la declaración de la función dentro de la clase como en su definición en el archivo de implementación.

En conjunto, la separación entre el archivo de especificación y el archivo de implementación facilita la ocultación de información. El código cliente conoce las operaciones disponibles a través de la interfaz pública, mientras que los detalles de cómo se ejecutan dichas operaciones permanecen en el archivo de implementación.

## Compilación


























































En el capítulo anterior presentamos el tipo de dato definido por el usuario  `struct`, que permite agrupar variables miembro. A continuación, se muestra un ejemplo de una `struct `utilizado para almacenar una fecha:

```cpp
struct Fecha
{
    int anio {};
    int mes {};
    int dia {};
};
```

Ahora bien, si queremos imprimir la fecha en pantalla (algo que probablemente necesitemos hacer con frecuencia), resulta conveniente escribir una función que se encargue de ello. A continuación, se muestra un programa completo implementando este hecho:

```cpp

#include <iostream>

struct Fecha
{
    // Estas son las variables miembro del registro.
    int anio {};
    int mes {};
    int dia {};
};

void imprimir(const Fecha& fecha)
{
    // Se accede a las variables miembro mediante
    // el operador de selección de miembros (.).
    std::cout << fecha.anio << '/' << fecha.mes << '/' << fecha.dia;
}

int main()
{
    Fecha hoy { 2020, 10, 14 }; // Inicializamos el registro con sus valores.

    hoy.dia = 16;  // Accedemos a una variable miembro mediante el operador (.).
    imprimir(hoy); // Llamamos a una función externa al registro mediante la
                   // sintaxis habitual de llamada a funciones.

    return 0;
}
```

Este programa imprime el siguiente resultado:

```cpp
2020/10/16
```
## Propiedades Y Acciones

Observa lo que hay a tu alrededor: libros, edificios, alimentos e incluso tú mismo. Todos estos son ejemplos de objetos. En el mundo real, los objetos tienen dos componentes principales: **un conjunto de propiedades observables**, como el peso, el color, el tamaño, la dureza o la forma, y **un conjunto de acciones que pueden realizar o que pueden realizarse sobre ellos**, como abrirlos o utilizarlos para modificar otro objeto. Ambos componentes están estrechamente relacionados, pues las acciones que puede realizar un objeto dependen, en cierta medida, de sus propiedades.

En programación, las propiedades se representan mediante variables, mientras que las acciones se implementan mediante funciones.

En el ejemplo anterior de `Fecha`, definimos sus propiedades (las variables miembro del registro) y las acciones que podemos realizar con ellas (como la función `imprimir()`) de manera independiente. Por lo tanto, la relación entre el tipo `Fecha` y la función `imprimir()` no está establecida explícitamente, sino que debemos deducirla a partir del parámetro `const Fecha&` que recibe la función.

Una posible solución sería colocar tanto `Fecha` como `imprimir()` dentro de un espacio de nombres (`namespace`) para indicar que ambos elementos están relacionados y pertenecen a un mismo conjunto. Sin embargo, esto también introduciría más nombres en el programa y obligaría a utilizar prefijos adicionales al acceder a ellos, lo que podría hacer que el código resultara más recargado.

Sería conveniente disponer de una forma de agrupar las propiedades y las acciones relacionadas con un objeto en una sola unidad, de modo que pudieran definirse y utilizarse como un conjunto.

# Funciones Miembro  