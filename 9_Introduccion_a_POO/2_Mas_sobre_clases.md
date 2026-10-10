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