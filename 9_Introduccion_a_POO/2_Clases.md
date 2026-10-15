# Clases 

En capítulos anteriores se han estudiado los valores de datos como entidades pasivas sobre las cuales actúan distintas funciones. Por ejemplo, se han utilizado enumeraciones para representar algun conjunto de cosas y se han realizado operaciones sobre sus valores mediante funciones que los reciben como parámetros. De manera similar, al trabajar con registros, hemos mostrado el ejemplo de la información de un alumno la cual se ha representado mediante una `struct` y también se han implementado funciones que reciben dicha estructura como argumento.

Sin embargo, mantener los datos separados de las operaciones que trabajan con ellos no representa del todo la idea de un tipo de dato abstracto. Esto se debe a que un TDA comprende tanto un conjunto de valores como las operaciones que pueden realizarse sobre ellos. Por ello, resulta más adecuado concebirlo como una estructura de datos activa, en la que los datos y las operaciones se integran en una misma unidad.

C++ permite adoptar este enfoque mediante las **clases**, un tipo estructurado del lenguaje que facilita la definición de tipos de datos abstractos. Los cuatro tipos estructurados fundamentales de C++ son los arreglos, los registros (`struct`), las uniones (`union`) y las clases (`class`).

Aunque una clase comparte ciertas características con un registro, su propósito va más allá de agrupar datos. Generalmente, sus miembros incluyen tanto los datos que describen un objeto como las funciones encargadas de operar sobre ellos. De esta manera, se reúnen en una misma unidad la información y las operaciones asociadas.

A continuación, se presenta una declaración de clase en C++ que representa el TDA `Tiempo`, definido en el capitulo anterior:

```cpp
class Tiempo
{
public:
    void establecer(int, int, int);
    void incrementar();
    void escribir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;

private:
    int horas; 
    int minutos;
    int segundos; 

};
```

En esta declaración, `Tiempo` es el nombre del tipo de dato definido por el usuario. Las funciones `establecer`, `incrementar`, `escribir`, `es_igual` y `es_menor_que` son miembros de la clase y especifican algunas de las operaciones disponibles para trabajar con valores de ese tipo. La palabra reservada `public` indica que estos miembros pueden utilizarse desde *fuera* de la clase.

Esta declaración presenta únicamente las operaciones que ofrece la clase, sin mostrar todavía cómo se almacenan los datos ni cómo se implementa cada operación. De esta manera, se define una interfaz que establece cómo se puede interactuar con los valores del tipo `Tiempo`.

La clase `Tiempo` está compuesta por ocho miembros: cinco funciones miembro (`establecer`, `incrementar`, `escribir`, `es_igual` y `es_menor_que`) y tres variables miembro (`horas`, `minutos` y `segundos`). Estas últimas constituyen la representación concreta de los datos del TDA `Tiempo`, mientras que las funciones miembro implementan las operaciones asociadas a este tipo de dato.

La función `establecer` permite asignar un tiempo a partir de las horas, los minutos y los segundos recibidos como argumentos. La función `incrementar` aumenta el tiempo en un segundo, mientras que `escribir` muestra su valor. Por su parte, `es_igual` compara dos valores de tipo `Tiempo` para determinar si son iguales, y `es_menor_que` permite comprobar si un tiempo es anterior a otro.

Aunque las funciones `es_igual` y `es_menor_que` comparan dos valores de tipo `Tiempo`, cada una recibe únicamente un argumento explícito de ese tipo. Esto se debe a que el otro valor corresponde al objeto sobre el cual se invoca la función miembro. Más adelante se explicará con mayor detalle este mecanismo.

Al igual que una declaración de tipo `struct`, la declaración de una clase define un nuevo tipo de dato, pero no crea por sí misma ninguna variable de ese tipo. Para crear objetos de la clase `Tiempo`, se utilizan declaraciones de variables ordinarias, como las siguientes:

```cpp
Tiempo tiempo_inicial;
Tiempo tiempo_final;
```

En este ejemplo, `tiempo_inicial` y `tiempo_final` son objetos de la clase `Tiempo`. Al código que declara y utiliza objetos de una clase se le conoce como **código cliente**, ya que emplea los servicios que ofrece dicha clase.

En las declaraciones de clases se utilizan las palabras reservadas `public` y `private`, seguidas de dos puntos, para establecer los niveles de acceso a sus miembros. Los miembros declarados bajo `public` forman la interfaz pública de la clase y pueden utilizarse directamente desde el código cliente, siempre que se cumplan las reglas de acceso del lenguaje. En cambio, los miembros declarados bajo `private` son privados y no pueden utilizarse directamente desde fuera de la clase. Si el código cliente intenta acceder a uno de ellos, el compilador señala un error.

En la clase `Tiempo`, las funciones miembro `establecer`, `incrementar`, `escribir`, `es_igual` y `es_menor_que` pueden acceder a las variables privadas `horas`, `minutos` y `segundos`. El código cliente, en cambio, no puede acceder directamente a estas variables, sino que debe interactuar con los objetos mediante las operaciones públicas proporcionadas por la clase.

Esta separación entre los miembros públicos y privados es una característica fundamental del diseño de los tipos de datos abstractos. Para preservar las propiedades y la consistencia de un TDA, sus objetos deben manipularse a través de las operaciones establecidas en su interfaz pública, evitando modificaciones directas que puedan producir estados inválidos. Este principio se retomará más adelante.


## Clases, Objetos De Clase Y Miembros De Clase

Es importante distinguir que una clase es un tipo de dato, no un objeto en sí mismo. Una clase funciona como un modelo o plantilla que permite crear múltiples objetos con las mismas características generales. Para entenderlo, podemos imaginar una clase como un *molde* para hacer galletas y los objetos como las galletas que se obtienen de él.

Por ejemplo, las siguientes declaraciones crean dos objetos de la clase `Tiempo`:

```cpp
Tiempo tiempo_1;
Tiempo tiempo_2;
```

Aunque ambos objetos pertenecen a la misma clase, cada uno posee sus propias copias de las variables miembro `horas`, `minutos` y `segundos`. Por lo tanto, sus valores pueden ser distintos. En un momento determinado, `tiempo_1` podría almacenar las 5 horas, 30 minutos y 10 segundos, mientras que `tiempo_2` podría representar las 17 horas, 58 minutos y 2 segundos.

Es importante señalar que las funciones miembro no se duplican físicamente para cada objeto. Por ejemplo, el compilador genera una sola copia de la función `Incrementar`, que puede ser utilizada por todos los objetos de la clase. Sin embargo, podemos imaginar que cada objeto dispone de sus propias funciones para comprender mejor cómo interactúa con sus datos.

Finalmente, es necesario diferenciar entre un **objeto de una clase** y un **miembro de una clase**. En el ejemplo anterior, `tiempo_1` y `tiempo_2` son dos objetos distintos de la clase `Tiempo`. Cada uno contiene sus propias variables miembro y comparte el acceso a las funciones miembro definidas en dicha clase.

## Operadores Con Objetos De Clase 

Las clases definidas por el programador comparten varias características con los tipos de datos integrados de C++. Por ejemplo, es posible crear tantos objetos de una misma clase como sean necesarios, utilizarlos como argumentos de funciones o devolverlos como resultados. Además, al igual que ocurre con otras variables, los objetos pueden tener duración automática: se crean cuando la ejecución llega a su declaración y se destruyen cuando termina su ámbito.

Sin embargo, C++ también establece diferencias entre los tipos integrados y los tipos definidos mediante `struct` o `class`. La mayoría de los operadores disponibles para los tipos integrados no pueden utilizarse directamente con objetos de estas clases. Por ejemplo, no es posible sumar dos objetos de tipo `Tiempo` mediante el operador `+` ni compararlos directamente con `==`, a menos que se definan las operaciones correspondientes para esos tipos.

Entre las operaciones que sí pueden utilizarse con los objetos de clase se encuentran la **selección de miembros** (`.`) y la **asignación** (`=`). La primera permite acceder a un miembro específico escribiendo el nombre del objeto, seguido de un punto y del nombre del miembro. Por ejemplo:

```cpp
tiempo_1.incrementar();
```

Esta instrucción invoca la función miembro `incrementar` del objeto `tiempo_1`, cuyo propósito es aumentar en un segundo el tiempo almacenado en él.

Por otra parte, el operador de asignación permite copiar los datos de un objeto a otro de la misma clase. Si `tiempo_1` y `tiempo_2` son objetos de tipo `Tiempo`, la instrucción:

```cpp
tiempo_2 = tiempo_1;
```

copia los valores de los miembros de datos de `tiempo_1` en los miembros correspondientes de `tiempo_2`. De esta manera, ambos objetos tendrán los mismos valores en sus miembros de datos después de la asignación, aunque seguirán siendo objetos independientes.

Veamos un ejemplo:

```cpp
Tiempo tiempo_1;
Tiempo tiempo_2;

int horas_entrada;
int minutos_entrada;
int segundos_entrada;

tiempo_1.establecer(5, 20, 0);
// Afirmar: tiempo_1 representa las 5:20:00.

cout << "Introduzca horas, minutos y segundos: ";
cin >> horas_entrada >> minutos_entrada >> segundos_entrada;

tiempo_2.establecer(horas_entrada, minutos_entrada, segundos_entrada);

if (tiempo_1.es_menor_que(tiempo_2))
    hacer_algo();

tiempo_2 = tiempo_1;  // Asignación entre objetos.

tiempo_2.escribir();
// Afirmar: se muestra el tiempo 5:20:00.
```

En este ejemplo, la función `es_menor_que` permite comparar dos objetos de tipo `Tiempo`, aunque solo recibe un parámetro explícito. Esto se debe a que el objeto sobre el que se invoca la función, `tiempo_1`, también participa en la comparación. En la expresión `tiempo_1.es_menor_que(tiempo_2)`, el primer objeto aparece antes del operador punto, mientras que el segundo se proporciona como argumento.

Por tanto, cuando una función miembro representa una operación binaria, el primer operando corresponde al objeto que invoca la función y los operandos restantes se indican mediante sus parámetros. De manera general, una operación de *n* operandos requiere *n* − 1 parámetros explícitos cuando se implementa como una función miembro. En cambio, una operación unaria, como `incrementar` o `escribir` en la clase `Tiempo`, no necesita parámetros explícitos, pues opera directamente sobre el objeto que la invoca.

Existen otros operadores que pueden utilizarse con objetos de tipo `struct` y `class`, especialmente aquellos relacionados con las direcciones de memoria. Sin embargo, su estudio se puede dejar para más adelante. Por el momento, conviene concentrarse en la selección de miembros mediante `.` y en la asignación mediante `=`, así como en la forma en que las funciones miembro permiten trabajar con los datos de un objeto.

Hasta ahora, las clases de C++ también se han utilizado en un contexto cotidiano: la entrada y salida de información. La biblioteca estándar incluye el encabezado `<iostream>`, que proporciona las clases `istream` y `ostream` para gestionar, respectivamente, los flujos de entrada y salida.

La biblioteca estándar también proporciona los objetos `cin` y `cout`, que permiten leer datos y mostrar información. Por ejemplo, la clase `istream` ofrece funciones miembro como `get` e `ignore`, que pueden utilizarse de la siguiente manera:

```cpp
char caracter;

cin.get(caracter);
cin.ignore(200, '\n');
```

En la primera instrucción, `get` permite leer un carácter. En la segunda, `ignore` descarta hasta 200 caracteres o hasta encontrar un salto de línea, según cuál de esas condiciones se cumpla primero. En ambos casos se utiliza la notación de punto para invocar una función miembro del objeto `std::cin`.

Las clases también se emplean al trabajar con archivos. El encabezado `<fstream>` proporciona, entre otras, las clases `ifstream` y `ofstream`, destinadas a la lectura y escritura de archivos, respectivamente. Por ejemplo:

```cpp
ifstream archivo_datos;
archivo_datos.open("datos_entrada.dat");
```

La primera instrucción declara un objeto llamado `archivo_datos`, de tipo `ifstream`. La segunda invoca su función miembro `open`, que intenta abrir el archivo `datos_entrada.dat` para leer su contenido.

No es necesario estudiar en detalle todas las funciones miembro de las clases utilizadas para la entrada y salida en este momento. Lo fundamental es reconocer que las clases y los objetos son una parte esencial del funcionamiento de C++ y que su uso no se limita a los tipos definidos por el programador: también constituye la base de numerosas herramientas de la biblioteca estándar.

## Alcance De Clase 

Como vimos anteriormente, los nombres de los miembros deben ser únicos dentro de una misma estructura. Por otra parte, en C++ existen cuatro tipos de alcance: local, global, de espacio de nombres y de clase. Este último se aplica a los nombres declarados dentro de clases, estructuras y uniones.

El alcance de clase significa que un nombre pertenece al ámbito de una clase determinada. Por ello, si se declara un identificador con el mismo nombre fuera de dicha clase, ambas declaraciones son independientes y no existe una relación directa entre ellas. Esto permite que distintas clases tengan miembros con nombres idénticos, sin provocar conflictos.

Por ejemplo, una clase `Tiempo` puede tener una función miembro llamada `escribir`. Al mismo tiempo, otra clase, como `Alguna_clase`, puede definir su propia función miembro con ese mismo nombre. Incluso es posible declarar una función global denominada `escribir`, que no pertenezca a ninguna clase.

Consideremos las siguientes declaraciones y llamadas:

```cpp
Tiempo tiempo_entrada;
Alguna_clase algun_objeto;
int numero;

tiempo_entrada.escribir();
algun_objeto.escribir();
escribir(numero);
```

El compilador de C++ puede distinguir sin dificultad a cuál de las tres funciones se refiere cada instrucción. En las dos primeras llamadas, el operador punto (`.`) indica que se debe invocar una función miembro del objeto correspondiente. Así, `tiempo_entrada.escribir()` llama a la función miembro de la clase `Tiempo`, mientras que `algun_objeto.escribir()` invoca la función miembro de `Alguna_clase`.

En cambio, la última instrucción no utiliza el operador punto, por lo que hace referencia a la función global `escribir`, que recibe `numero` como argumento. De esta manera, el alcance de clase permite que diferentes clases y el ámbito global contengan funciones con el mismo nombre, sin que el compilador las confunda.