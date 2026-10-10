# **Datos Simples vs. Datos Estructurados**

Desde el inicio del curso hemos estado trabajando con datos **simples** o **atómicos**. Como recordarás, estos se caracterizan por representar un único valor que no puede dividirse en componentes más pequeños. Algunos ejemplos son las variables de tipo `int` o `float`.

Por otro lado, los tipos de **datos estructurados** permiten agrupar varios elementos bajo un mismo nombre, sin perder la posibilidad de acceder a cada uno de ellos por separado. Ya hemos trabajado con este tipo de datos desde el inicio del curso, pues en C++ tenemos el tipo `string` (que no es definido por el usuario), el cual permite almacenar y manipular cadenas de caracteres. Cuando se declara una variable de este tipo, no se trabaja únicamente con un dato individual, sino con una secuencia de caracteres. Sin embargo, es posible acceder a cada carácter mediante su posición, por ejemplo, utilizando una expresión como:

```c++
mi_cadena[3]
```

Esta expresión permite obtener el carácter ubicado en el índice `3`.

Los tipos de datos simples, tanto los que ofrece el lenguaje como los definidos por el programador, sirven como elementos básicos para construir tipos de **datos estructurados**. Estos últimos agrupan valores componentes siguiendo una organización determinada. La forma de acceder a cada componente depende de cómo estén organizados los datos dentro de la estructura. Por ello, al estudiar las distintas maneras de organizar información en C++, también es necesario examinar los mecanismos que permiten consultar y manipular sus componentes.

En C++, existen diversas formas de organizar los datos en tipos estructurados, entre las que destacan los **arreglos**, los **registros** (`struct`), las **uniones** (`union`) y las **clases** (`class`). Como veremos más adelante, cada una de estas formas establece una manera particular de agrupar y organizar sus componentes. Por ejemplo, los arreglos reúnen elementos de un mismo tipo y permiten acceder a ellos mediante su posición, mientras que los registros y las clases agrupan miembros que pueden tener distintos tipos de datos. Las uniones, por su parte, permiten que diferentes miembros compartan una misma región de memoria.

Ahora bien, es importante distinguir los tipos de datos estructurados de los mecanismos que permiten definir o nombrar otros tipos de dato (datos que vimos en las dos lecciones anteriores). Por ejemplo, `using` no crea por sí mismo un tipo de datos nuevo, sino que permite establecer un alias, es decir, un nombre alternativo para un tipo existente. De esta manera, se facilita la lectura y la escritura del código sin modificar las características del tipo original.

Por otro lado, las enumeraciones (`enum`) requieren una distinción diferente. Aunque permiten definir un tipo de dato propio, no se consideran tipos estructurados, puesto que sus valores representan opciones de un conjunto previamente establecido y no colecciones de componentes. Por ejemplo, una enumeración que represente los días de la semana permite utilizar valores como lunes, martes o miércoles, pero cada variable de ese tipo almacena un único valor de la enumeración.

En consecuencia, no todos los tipos definidos por el programador son estructurados, ni todos los tipos estructurados son necesariamente definidos por él. En C++, los arreglos son tipos compuestos que ofrece el lenguaje, mientras que los registros, las uniones y las clases permiten definir tipos que agrupan componentes mediante declaraciones específicas. Esta distinción ayuda a comprender tanto las diferentes maneras de organizar los datos como los mecanismos disponibles para definir nuevos tipos en un programa.

En las siguientes lecciones veremos una breve introducción a los registros y las uniones, con lo que prepararemos el camino para abordar el que por consideración de muchos es el más importante: **las clases**.