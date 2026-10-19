La clase `Tiempo` con la que hemos trabajado hasta ahora presenta una limitación: depende de que el código cliente invoque la función `establecer` antes de utilizar cualquiera de las demás funciones miembro. Por ejemplo, la función `incrementar` tiene la siguiente precondición:

```cpp
// Precondición:
// La función establecer ha sido invocada al menos una vez.
```

Si el cliente utiliza `incrementar` sin haber llamado previamente a `establecer`, la precondición no se cumple y se incumple el contrato establecido entre la clase y quien la utiliza. Debido a que las clases suelen encapsular sus propios datos, el programador que las diseña no debería depender del usuario para inicializarlos. Si este olvida hacerlo, el objeto podría contener valores no inicializados y producir resultados inesperados.

Para solucionar este problema, C++ proporciona un mecanismo llamado **constructor de clase**, cuya función es inicializar los objetos cuando se crean. Un constructor es una función miembro especial que se ejecuta automáticamente durante la creación de un objeto de la clase.

Una característica particular de los constructores es que su nombre debe coincidir con el de la clase a la que pertenecen. Para mejorar la clase `Tiempo`, podemos incorporar dos constructores a su declaración:

```cpp
class Tiempo
{
public:
    void establecer(int, int, int);
    void incrementar();
    void escribir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;

    Tiempo(int, int, int);  // Constructor con tres parámetros.
    Tiempo();               // Constructor por omisión.

private:
    int horas;
    int minutos;
    int segundos;
};
```

En esta declaración se incluyen dos constructores que se distinguen por sus listas de parámetros. El primero recibe tres valores de tipo `int`, que pueden utilizarse para inicializar los miembros de datos privados `horas`, `minutos` y `segundos` al crear un objeto. El segundo no recibe parámetros y permite asignar al objeto un tiempo inicial predeterminado, por ejemplo, `00:00:00`. En C++, un constructor que puede invocarse sin argumentos se conoce como **constructor por omisión**.

Las declaraciones de los constructores tienen dos particularidades que las diferencian de las funciones miembro convencionales. En primer lugar, el nombre de cada constructor es exactamente el mismo que el de su clase; en este caso, `Tiempo`. En segundo lugar, no se especifica ningún tipo de retorno, ni siquiera `void`.

Esto se debe a que un constructor no devuelve un valor como resultado de una función. Su finalidad es inicializar el objeto durante su creación, estableciendo los valores iniciales de sus miembros de datos.

En el archivo de implementación de la clase `Tiempo`, es necesario definir los dos constructores que se declararon previamente. Estas definiciones establecen los valores iniciales de los miembros de datos privados cuando se crea un objeto.

```cpp
//******************************************************************
// Constructor con tres parámetros.
//******************************************************************

Tiempo::Tiempo(/* entrada */ int horas_iniciales,
               /* entrada */ int minutos_iniciales,
               /* entrada */ int segundos_iniciales)

// Precondición:
// 0 <= horas_iniciales <= 23
// 0 <= minutos_iniciales <= 59
// 0 <= segundos_iniciales <= 59
//
// Poscondición:
// horas == horas_iniciales
// minutos == minutos_iniciales
// segundos == segundos_iniciales

{
    horas = horas_iniciales;
    minutos = minutos_iniciales;
    segundos = segundos_iniciales;
}

//******************************************************************
// Constructor por omisión.
//******************************************************************

Tiempo::Tiempo()

// Poscondición:
// horas == 0
// minutos == 0
// segundos == 0

{
    horas = 0;
    minutos = 0;
    segundos = 0;
}
```

## Invocación De Un Constructor

Aunque los constructores son miembros de una clase, no se invocan mediante el operador punto (`.`), como sucede con las funciones miembro convencionales. En su lugar, se ejecutan automáticamente cuando se crea un objeto de la clase.

Por ejemplo, la siguiente declaración incluye tres argumentos después del nombre del objeto:

```cpp
Tiempo hora_clase(10, 30, 0);
```

Cuando se ejecuta esta declaración, se invoca automáticamente el constructor de `Tiempo` que recibe tres parámetros. Los valores proporcionados se utilizan para inicializar los miembros de datos privados del objeto `hora_clase`, que queda representando las 10:30:00.

En cambio, la siguiente declaración no proporciona argumentos:

```cpp
Tiempo hora_inicio;
```

En este caso, se utiliza automáticamente el constructor por omisión, que establece los miembros de datos del objeto `hora_inicio` en cero. Por consiguiente, el objeto comienza representando las 00:00:00.

Es importante recordar que las declaraciones de variables en C++ pueden aparecer entre las instrucciones ejecutables de una función. Esto resulta útil cuando los valores necesarios para crear un objeto solo se conocen durante la ejecución del programa.

Consideremos el siguiente ejemplo:

```cpp
int horas_entrada;
int minutos_entrada;
int segundos_entrada;

cout << "Introduzca la hora de la cita en horas, minutos y segundos: ";
cin >> horas_entrada >> minutos_entrada >> segundos_entrada;

Tiempo hora_cita(horas_entrada, minutos_entrada, segundos_entrada);

cout << "La hora de la cita es ";
hora_cita.escribir();
```

En este fragmento, primero se solicitan al usuario las horas, los minutos y los segundos. Posteriormente, estos valores se utilizan como argumentos para crear el objeto `hora_cita`. De este modo, el constructor establece el tiempo inicial desde el momento en que se crea el objeto, sin necesidad de invocar por separado la función `establecer`.

## Especificación Revisada De La Clase `Tiempo`

La incorporación de constructores permite garantizar que los objetos de la clase `Tiempo` reciban valores iniciales al crearse. El constructor con tres parámetros permite que el cliente determine el tiempo inicial, mientras que el constructor por omisión establece el valor `00:00:00` cuando no se proporcionan argumentos.

Por lo tanto, una vez que se crea un objeto mediante alguno de estos constructores, sus miembros de datos quedan inicializados. Esto elimina la necesidad de exigir al cliente que invoque previamente la función `establecer` antes de utilizar las demás funciones miembro.

En consecuencia, se pueden retirar de la especificación las advertencias que exigían llamar a `establecer` antes de ejecutar otras operaciones, así como las precondiciones que dependían exclusivamente de esa llamada previa. Sin embargo, siguen siendo necesarias las condiciones que establecen restricciones sobre los valores de entrada o el uso de determinadas operaciones.

La declaración actualizada de la clase `Tiempo` puede escribirse de la siguiente manera:

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

    void incrementar();

    // Poscondición:
    // El tiempo avanza un segundo. Si llega a 23:59:59,
    // vuelve a comenzar en 00:00:00.

    void escribir() const;

    // Poscondición:
    // El tiempo se muestra con el formato HH:MM:SS.

    bool es_igual(/* entrada */ Tiempo otro_tiempo) const;

    // Poscondición:
    // Devuelve true si ambos objetos representan el mismo
    // tiempo y false en caso contrario.

    bool es_menor_que(/* entrada */ Tiempo otro_tiempo) const;

    // Precondición:
    // Este objeto y otro_tiempo representan tiempos del mismo día.
    //
    // Poscondición:
    // Devuelve true si este tiempo es anterior a otro_tiempo
    // y false en caso contrario.

    Tiempo(/* entrada */ int horas_iniciales,
           /* entrada */ int minutos_iniciales,
           /* entrada */ int segundos_iniciales);

    // Constructor con tres parámetros.
    //
    // Precondición:
    // 0 <= horas_iniciales <= 23
    // 0 <= minutos_iniciales <= 59
    // 0 <= segundos_iniciales <= 59
    //
    // Poscondición:
    // El objeto se crea con el tiempo indicado
    // por los parámetros recibidos.

    Tiempo();

    // Constructor por omisión.
    //
    // Poscondición:
    // El objeto se crea con el tiempo 00:00:00.

private:
    int horas;
    int minutos;
    int segundos;
};
```


Ahora veamos el archivo de implementación ya revisado: 


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
Tiempo::Tiempo(/* entrada */ int horas_iniciales,
               /* entrada */ int minutos_iniciales,
               /* entrada */ int segundos_iniciales)

// Constructor con tres parámetros.
//
// Precondición:
// 0 <= horas_iniciales <= 23
// 0 <= minutos_iniciales <= 59
// 0 <= segundos_iniciales <= 59
//
// Poscondición:
// horas == horas_iniciales
// minutos == minutos_iniciales
// segundos == segundos_iniciales

{
    horas = horas_iniciales;
    minutos = minutos_iniciales;
    segundos = segundos_iniciales;
}

//******************************************************************
Tiempo::Tiempo()

// Constructor por omisión.
//
// Poscondición:
// horas == 0
// minutos == 0
// segundos == 0

{
    horas = 0;
    minutos = 0;
    segundos = 0;
}

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

{
    horas = horas_entrada;
    minutos = minutos_entrada;
    segundos = segundos_entrada;
}

//******************************************************************
void Tiempo::incrementar()

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

// Poscondición:
// El tiempo se muestra con el formato HH:MM:SS.

{
    if (horas < 10)
        cout << '0';

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
// Este objeto y otro_tiempo representan tiempos del mismo día.
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
En contraste con la implementación anterior tenemos: 

1. La inclusión de las definiciones de función para los dos constructores de clase que se presentaron antes.
2. La eliminación de las precondiciones de función que expresan que la función `establecer` debe ser invocada antes.

En este punto, quizá te surja la siguiente pregunta: ¿sigue siendo necesaria la función `establecer` si el constructor con parámetros realiza una operación similar? Ambos permiten asignar un tiempo a partir de tres valores recibidos como argumentos y sus implementaciones pueden ser prácticamente iguales. Sin embargo, existe una diferencia fundamental entre ellos.

La función `establecer` puede invocarse sobre un objeto existente tantas veces como sea necesario para modificar el tiempo que almacena. En cambio, el constructor se ejecuta automáticamente cuando se crea el objeto y se utiliza para establecer su estado inicial. Por esta razón, se conserva `establecer`: permite que el código cliente cambie el tiempo de un objeto después de haberlo creado, lo que proporciona mayor flexibilidad al utilizar la clase.

El siguiente programa muestra cómo utilizar todas las funciones miembro de la clase `Tiempo`. Al comenzar la ejecución de `main`, se crean dos objetos: `tiempo_1`, mediante el constructor con tres parámetros, y `tiempo_2`, mediante el constructor por omisión.

```cpp
//******************************************************************
// Programa: ClienteTiempo.cpp
//
// Programa cliente que muestra el uso de la clase Tiempo.
//******************************************************************

#include <iostream>
#include "Tiempo.h"

using namespace std;

int main()
{
    Tiempo tiempo_1(5, 30, 0);
    Tiempo tiempo_2;

    int contador_repeticiones;

    cout << "tiempo_1: ";
    tiempo_1.escribir();

    cout << " tiempo_2: ";
    tiempo_2.escribir();

    cout << endl;

    if (tiempo_1.es_igual(tiempo_2))
        cout << "Los tiempos son iguales" << endl;
    else
        cout << "Los tiempos NO son iguales" << endl;

    tiempo_2 = tiempo_1;

    cout << "tiempo_1: ";
    tiempo_1.escribir();

    cout << " tiempo_2: ";
    tiempo_2.escribir();

    cout << endl;

    if (tiempo_1.es_igual(tiempo_2))
        cout << "Los tiempos son iguales" << endl;
    else
        cout << "Los tiempos NO son iguales" << endl;

    tiempo_2.incrementar();

    cout << "Nuevo tiempo_2: ";
    tiempo_2.escribir();
    cout << endl;

    if (tiempo_1.es_menor_que(tiempo_2))
        cout << "tiempo_1 es menor que tiempo_2" << endl;
    else
        cout << "tiempo_1 NO es menor que tiempo_2" << endl;

    if (tiempo_2.es_menor_que(tiempo_1))
        cout << "tiempo_2 es menor que tiempo_1" << endl;
    else
        cout << "tiempo_2 NO es menor que tiempo_1" << endl;

    tiempo_1.establecer(23, 59, 55);

    cout << "Incrementar tiempo_1 desde 23:59:55:" << endl;

    for (contador_repeticiones = 1;
         contador_repeticiones <= 10;
         contador_repeticiones++)
    {
        tiempo_1.escribir();
        cout << ' ';
        tiempo_1.incrementar();
    }

    cout << endl;

    return 0;
}
```

Al ejecutar el programa, se obtiene una salida similar a la siguiente:

```text
tiempo_1: 05:30:00 tiempo_2: 00:00:00
Los tiempos NO son iguales
tiempo_1: 05:30:00 tiempo_2: 05:30:00
Los tiempos son iguales
Nuevo tiempo_2: 05:30:01
tiempo_1 es menor que tiempo_2
tiempo_2 NO es menor que tiempo_1
Incrementar tiempo_1 desde 23:59:55:
23:59:55 23:59:56 23:59:57 23:59:58 23:59:59 00:00:00 00:00:01 00:00:02 00:00:03 00:00:04
```
## Constructores y Destructores 

Las clases son un mecanismo fundamental de C++ para definir tipos de datos abstractos. Ofrecen herramientas que permiten organizar y controlar el acceso a los datos y las operaciones de un tipo de dato. Sin embargo, para aprovechar sus ventajas, es necesario comprender las reglas que rigen su utilización.

C++ establece diversas reglas para el uso de constructores. Algunas se relacionan con características del lenguaje que se estudiarán más adelante, pero las siguientes son esenciales para comprender su funcionamiento:

1. **Los constructores no tienen tipo de retorno.** Su propósito es inicializar los objetos durante su creación, por lo que no se declara un tipo de retorno, ni siquiera `void`.

2. **Una clase puede tener varios constructores.** Cada uno puede recibir distintos parámetros. Cuando se crea un objeto, el compilador determina cuál debe utilizarse de acuerdo con la cantidad y los tipos de los argumentos proporcionados. Esta característica se conoce como sobrecarga de constructores.

3. **Los argumentos se escriben después del nombre del objeto al declararlo.** Por ejemplo:

   ```cpp
   Alguna_clase algun_objeto(argumento_1, argumento_2);
   ```

   En esta declaración, el constructor apropiado de `Alguna_clase` recibe `argumento_1` y `argumento_2` para inicializar el objeto `algun_objeto`.

4. **La declaración de un objeto sin argumentos depende de los constructores disponibles.** Por ejemplo:

   ```cpp
   Alguna_clase algun_objeto;
   ```

   El comportamiento depende de los constructores declarados en `Alguna_clase`:

   - Si la clase no declara ningún constructor, el compilador proporciona un constructor por omisión implícito. Sin embargo, esto no garantiza que todos los miembros de datos tengan valores iniciales definidos: el resultado depende de cómo estén declarados y de sus tipos.
   - Si la clase declara constructores, pero dispone de uno que puede invocarse sin argumentos, este se utiliza para crear el objeto.
   - Si la clase declara constructores, pero ninguno puede invocarse sin argumentos, la declaración anterior produce un error de compilación.

Además de los constructores, C++ proporciona otra función miembro especial: el **destructor**. Mientras que el constructor se ejecuta durante la creación de un objeto, el destructor se invoca automáticamente cuando termina su vida útil. Por ejemplo, esto sucede cuando un objeto local deja de estar dentro de su ámbito y la ejecución abandona el bloque en el que fue declarado.

El nombre de un destructor se forma utilizando el nombre de su clase precedido por el símbolo `~`. A diferencia de los constructores, una clase puede tener un solo destructor y este tampoco posee un tipo de retorno ni recibe parámetros.

La siguiente declaración muestra cómo se escribe un constructor y un destructor dentro de una clase:

```cpp
class Alguna_clase
{
public:
    Alguna_clase();   // Constructor.
    ~Alguna_clase();  // Destructor.

private:
    // Miembros de la clase.
};
```

En este ejemplo, `Alguna_clase()` es el constructor por omisión, mientras que `~Alguna_clase()` es el destructor. Ambos son miembros especiales cuyo funcionamiento está asociado a la vida útil de los objetos de la clase.

