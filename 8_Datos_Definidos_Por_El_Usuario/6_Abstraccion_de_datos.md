# Abtrabción De Datos 

A medida que aumenta la complejidad del software, el diseño de los algoritmos y de las estructuras de datos se realiza de manera conjunta. Este proceso parte de una representación lógica o abstracta de la estructura de datos, planteada en un nivel general, y avanza mediante sucesivas etapas de refinamiento hasta llegar a su implementación concreta en C++.

Para ilustrar este proceso, en `4_registros` se presentaron dos formas de representar la estructura lógica de un registro utilizado en un inventario de almacén. En la primera, todos los componentes del registro se definieron directamente en un mismo nivel. En la segunda, se empleó un registro jerárquico, en el que las fechas y las estadísticas relacionadas con el historial de la máquina se agruparon en un registro de menor nivel.

Consideremos nuevamente ambas formas de representar la estructura lógica de los datos:


```cpp
struct Registro_maquina {

    int numero_id;

    string descripcion;

    float indice_fallas;

    int ultimo_servicio_mes;   // 1..12
    int ultimo_servicio_dia;   // 1..31
    int ultimo_servicio_anio;  // 1900..2050

    int dias_fuera_servicio;

    int fecha_compra_mes;      // 1..12
    int fecha_compra_dia;      // 1..31
    int fecha_compra_anio;     // 1900..2050

    float costo;
};
```

```cpp
struct Fecha {

    int mes;   // 1..12
    int dia;   // 1..31
    int anio;  // 1900..2050
};

struct Estadisticas {

    float indice_fallas;

    Fecha ultimo_servicio;

    int dias_fuera_servicio;
};

struct Registro_maquina {

    int numero_id;

    string descripcion;

    Estadisticas historial;

    Fecha fecha_compra;

    float costo;
};

Registro_maquina maquina;
```
¿Cuál de estas dos representaciones es mejor? La segunda presenta dos ventajas principales.

En primer lugar, permite agrupar los elementos de acuerdo con su naturaleza lógica. Las fechas y las estadísticas pueden considerarse entidades independientes, que podrían utilizarse también en otros tipos de `structs`. Si se definieran únicamente como componentes de `Registro_maquina`, tal como ocurre en la primera representación, sería necesario volver a declararlas en cada estructura que las necesitara. Esto daría lugar a múltiples definiciones de elementos que representan la misma entidad lógica.

En segundo lugar, la segunda representación permite trasladar los detalles de estas entidades (las estadísticas y las fechas) a un nivel inferior de la estructura. El principio de dejar los detalles para el nivel más bajo posible no solo se aplica al diseño de algoritmos, sino también al diseño de estructuras de datos. La manera en que se representan una fecha o el historial de una máquina no afecta directamente al concepto general de un registro de máquina. Por lo tanto, no es necesario especificar esos detalles hasta el momento en que se desarrollen los algoritmos encargados de trabajar con dichos componentes.

Separar los detalles de implementación de un tipo de datos y trasladarlos a un nivel inferior permite distinguir entre su descripción lógica y su implementación concreta. Cuando se separan las propiedades lógicas de un tipo de datos de los detalles de su implementación, se habla de **abstracción de datos**. Este principio es fundamental para desarrollar programas de manera efectiva y constituye la base de los tipos de datos abstractos, concepto que estudiaremos mas a fondo en el siguiente capítulo.

Finalmente, las propiedades lógicas de una estructura deben definirse a partir de tipos de datos concretos y de las rutinas necesarias para manipularlos. Cuando la implementación se diseña adecuadamente, estas mismas rutinas pueden reutilizarse en distintas aplicaciones.

Por ejemplo, una rutina que permita comparar fechas puede emplearse tanto para comparar las fechas de compra o mantenimiento de un equipo como para comparar las fechas de nacimiento de distintas personas. La idea de diseñar estructuras de datos de bajo nivel y desarrollar rutinas para operar sobre ellas constituye uno de los fundamentos de los tipos `class` de C++, los cuales estudiaremos con mayor profundidad en el siguiente capítulo.

# Tipos De Datos Abstractos

Vivimos en un mundo complejo, en el que constantemente recibimos información y nos enfrentamos a una gran cantidad de hechos y detalles. Para comprender nuestro entorno sin tener que conocer cada uno de sus aspectos, la mente humana recurre a la **abstracción**, un proceso que consiste en identificar las características esenciales de una idea u objeto, dejando de lado los detalles de cómo está construido o cómo funciona internamente.

La abstracción nos permite concentrarnos en el *qué* en lugar del *cómo*. Por ejemplo, cuando utilizamos un automóvil, sabemos que su motor permite generar el movimiento necesario para desplazarnos, aunque no conozcamos todos los mecanismos que intervienen en su funcionamiento. Comprender su propósito es suficiente para utilizarlo, sin necesidad de estudiar cada uno de sus componentes internos. De esta manera, la abstracción nos permite comprender y utilizar objetos sin tener que conocer todos los detalles que los conforman.

En el desarrollo de software ocurre algo similar. La abstracción es indispensable para trabajar con programas grandes y complejos, ya que permite dividirlos en partes más manejables y concentrarse en sus características esenciales. En un curso introductorio, es común trabajar con programas de unas cuantas decenas o cientos de líneas de código, cuyo funcionamiento puede comprenderse en su totalidad con relativa facilidad. Sin embargo, los sistemas comerciales pueden estar formados por cientos de miles o incluso millones de líneas de código. En estos casos, sería muy difícil diseñar, comprender y probar cada parte del programa sin recurrir a distintas técnicas de abstracción.

Entre las técnicas más importantes para manejar esta complejidad se encuentran la **abstracción de control** y la **abstracción de datos**.

La abstracción de control consiste en separar lo que hace una operación de los detalles de cómo se lleva a cabo. Cada vez que definimos una función para realizar una tarea específica, podemos utilizarla mediante una llamada sin tener que revisar todos los pasos que ejecuta internamente. Por ejemplo, al escribir una expresión como:

```cpp
4.6 + sqrt(x)
```

podemos utilizar la función `sqrt` para calcular la raíz cuadrada de `x` sin necesidad de conocer el algoritmo que utiliza para obtener el resultado. Basta con comprender qué hace la función y cómo se utiliza. De esta manera, la operación se presenta como una acción concreta, mientras que los detalles de su implementación permanecen ocultos. Esto permite escribir programas más claros y reducir la complejidad con la que debemos lidiar en cada momento.

Este mismo principio puede aplicarse a los datos. Todo tipo de dato está formado por un conjunto de valores posibles, conocido como su *dominio*, y por las operaciones que pueden realizarse sobre ellos. La **abstracción de datos** consiste en separar las propiedades y el comportamiento de un tipo de dato de los detalles relacionados con su implementación.

Esta idea resulta especialmente útil cuando necesitamos trabajar con un tipo de dato que no se encuentra definido directamente en el lenguaje de programación. En lugar de preocuparnos desde el principio por cómo se almacenarán sus valores o cómo se implementarán sus operaciones, podemos comenzar por establecer qué representa ese tipo de dato y qué acciones será posible realizar con él. Cuando nos concentramos en estas propiedades y dejamos para después los detalles de implementación, podemos definir un **tipo de dato abstracto (TDA)**.

Al igual que ocurre con la abstracción de control, un tipo de dato abstracto tiene dos aspectos fundamentales: una **especificación**, que describe qué representa y cómo se comporta, y una **implementación**, que establece cómo se almacenan sus datos y cómo se llevan a cabo sus operaciones. Quien utiliza un TDA necesita conocer su especificación para trabajar con él, pero no tiene que conocer necesariamente los detalles de su implementación.

Para comprender mejor esta idea, consideremos esta lista como ejemplo de un tipo de dato abstracto: 


**TIPO**

`Lista_enteros`

**DOMINIO**

Cada valor de `Lista_enteros` representa una colección de hasta 100 números enteros independientes.

**OPERACIONES**

- Insertar un elemento en la lista.
- Eliminar un elemento de la lista.
- Buscar un elemento en la lista.
- Obtener la longitud actual de la lista.
- Ordenar los elementos de menor a mayor.
- Imprimir los elementos de la lista.

Observa que esta especificación describe qué representa una lista y qué operaciones podemos realizar sobre ella, pero no explica cómo se almacenan sus elementos ni cómo se llevan a cabo las operaciones. Al dejar estos detalles fuera de la especificación, se reduce la complejidad para quien utiliza el tipo de dato y se evita que dependa de una implementación particular. Así, si en el futuro se modifica la manera en que se almacena la información, los programas que utilizan la lista pueden seguir funcionando, siempre que se mantenga el comportamiento establecido.

Consideremos ahora otro tipo de dato abstracto que podría utilizarse para representar la hora del día en un programa.

**TIPO**

`Tiempo`

**DOMINIO**

Cada valor de `Tiempo` representa una hora del día mediante horas, minutos y segundos.

**OPERACIONES**

- Establecer una hora.
- Mostrar la hora.
- Incrementar la hora en un segundo.
- Comparar dos horas para determinar si son iguales.
- Determinar si una hora es anterior a otra.

Al igual que en el ejemplo anterior, esta especificación establece las características de los valores y las operaciones que se pueden realizar sobre ellos, sin indicar cómo deben almacenarse ni cómo deben implementarse dichas operaciones.

En ambos casos, la especificación define las propiedades y el comportamiento que el usuario puede esperar del tipo de dato abstracto. Sin embargo, para utilizarlo en un programa real, es necesario traducir esa descripción a instrucciones concretas de C++. Para ello, el programador debe tomar dos decisiones fundamentales:

1. **Elegir una representación concreta de los datos**, utilizando tipos que ya existan en el lenguaje.
2. **Implementar cada una de las operaciones permitidas**, mediante algoritmos que trabajen con la representación elegida.

Por ejemplo, para implementar el tipo de dato abstracto `Lista_enteros`, podríamos utilizar un arreglo de 100 elementos de tipo `int` y una variable adicional que indique cuántos elementos contiene actualmente la lista. El arreglo permitiría almacenar los números, mientras que la variable auxiliar serviría para conocer la longitud actual de la colección. A partir de esta representación, sería necesario desarrollar los algoritmos para insertar, eliminar, buscar y ordenar los elementos, entre otras operaciones.

Por otro lado, el tipo de dato abstracto `Tiempo` podría representarse mediante tres variables de tipo `int`: una para las horas, otra para los minutos y una más para los segundos. También podrían considerarse otras representaciones, siempre que permitan cumplir con las operaciones establecidas en la especificación.

Lo importante es que **la especificación de un TDA no obliga a utilizar una representación concreta**. Mientras la implementación respete las propiedades y el comportamiento definidos, el programador puede elegir entre distintas alternativas. Esta decisión puede depender de varios factores, como la eficiencia en el tiempo de ejecución, la cantidad de memoria que se necesita o la sencillez y legibilidad del código.

Conforme se adquiere experiencia, resulta más sencillo evaluar estas alternativas y elegir la que mejor se adapte a cada problema. La separación entre la especificación y la implementación permite precisamente esto: definir primero qué debe hacer un tipo de dato y decidir después cómo llevarlo a la práctica.
