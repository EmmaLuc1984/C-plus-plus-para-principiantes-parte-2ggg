# Ocultación De Información

Desde cierto punto de vista, podemos imaginar que cada objeto de una clase está rodeado por una **barrera de abstracción**. Esta barrera delimita el acceso a la información interna del objeto, impidiendo que el código cliente acceda directamente a sus datos y funciones privadas. De esta manera, los detalles internos permanecen separados de aquello que el objeto muestra al exterior. Esta separación es fundamental para las clases y los tipos de datos abstractos.

Para que un objeto pueda interactuar con el código cliente, es necesario establecer puntos de acceso a través de dicha barrera. Estos puntos conforman la **interfaz pública** de la clase y están constituidos por los miembros declarados como públicos. Por medio de esta interfaz, el cliente puede solicitar operaciones e interactuar con el objeto sin necesidad de conocer su funcionamiento interno. Así, cualquier modificación de los datos internos debe realizarse mediante las operaciones públicas que la clase proporciona, en lugar de acceder directamente a ellos.

En ingeniería existe un concepto semejante conocido como *caja negra*. Se trata de un dispositivo o módulo cuyo funcionamiento interno permanece oculto para quien lo utiliza. El usuario únicamente necesita conocer sus especificaciones, es decir, qué hace y cómo debe utilizarse, sin tener que comprender los mecanismos internos que permiten su funcionamiento. Para interactuar con él, utiliza los puntos de conexión disponibles y confía en que el dispositivo cumpla con lo establecido en sus especificaciones.

En el desarrollo de software, esta idea se relaciona con la **ocultación de información**, un principio que permite utilizar una clase sin conocer todos los detalles de su implementación. Además, protege los datos y el código internos frente a modificaciones externas que podrían provocar errores o comprometer el funcionamiento correcto del objeto.

Estos conceptos están relacionados con algo llamado  *encapsulamiento*. Por ejemplo, al definir una función, es posible separar su implementación del código que la utiliza, de modo que el cliente solo necesite conocer su interfaz. De manera similar, las funciones miembro de una clase pueden implementarse en archivos separados de aquellos en los que se encuentra el código cliente. Esto permite ocultar los detalles internos y facilita el mantenimiento del programa.

El programador que diseña una clase de C++ puede decidir qué miembros serán públicos y cuáles permanecerán privados. Sin embargo, permitir el acceso público a los miembros, como suele hacerse en tipos como `struct`, permite que el código cliente consulte y modifique sus valores directamente. Esto reduce el control que tiene la clase sobre sus propios datos.

Por este motivo, muchas clases siguen una organización habitual: los miembros de datos se colocan en la sección privada, mientras que las funciones que permiten consultar o modificar esos datos se declaran en la sección pública. Esta distribución favorece la ocultación de información y permite establecer reglas para el uso correcto de los objetos.

La clase `Tiempo` es un ejemplo de esta organización. Sus miembros de datos `horas`, `minutos` y `segundos` se declaran como privados, por lo que el código cliente no puede acceder a ellos directamente. En consecuencia, el siguiente fragmento produciría un error de compilación:

```cpp
Tiempo tiempo_entrada;

tiempo_entrada.horas = 9;  // Error: acceso a un miembro privado.
```

Aunque el objeto `tiempo_entrada` pertenece a la clase `Tiempo`, esto no significa que el código cliente tenga acceso a todos sus miembros. El compilador impide la modificación directa de `horas`, ya que este miembro se encuentra en la sección privada. Para establecer el tiempo, el cliente debe utilizar las funciones públicas que la clase proporciona, por ejemplo, `establecer`.

Por otro lado, las funciones miembro de una clase sí pueden acceder a sus miembros privados. Esto permite que el diseñador controle cómo se consulta y modifica la información interna, estableciendo las operaciones permitidas y procurando que los objetos mantengan un estado válido.

En algunos casos, puede resultar útil permitir que el código cliente consulte los datos internos sin tener la posibilidad de modificarlos directamente. Para ello, se pueden proporcionar **funciones de observación**, cuya finalidad es obtener información del objeto sin alterar su estado. En la clase `Tiempo`, las funciones `escribir`, `es_igual` y `es_menor_que` cumplen esta función, ya que permiten mostrar o comparar los tiempos sin modificar los datos almacenados.

En C++, las funciones miembro que no modifican el estado observable del objeto pueden declararse con la palabra clave `const`, colocada después de la lista de parámetros y antes del cuerpo de la función. Por ejemplo, las declaraciones correspondientes en la clase `Tiempo` serían:

```cpp
void escribir() const;
bool es_igual(Tiempo) const;
bool es_menor_que(Tiempo) const;
```

Estas funciones se conocen como **funciones miembro constantes**. Dentro de una función miembro declarada como `const`, el compilador impide modificar directamente los miembros de datos no estáticos del objeto mediante esa función. De esta manera, la declaración comunica tanto al compilador como a quienes utilizan la clase que la operación no debe modificar el estado del objeto.

Aunque el lenguaje no obliga a declarar como `const` todas las funciones miembro que no modifican el estado del objeto, hacerlo constituye una buena práctica de programación. Además de documentar la intención del programador, ayuda al compilador a detectar modificaciones accidentales y permite utilizar esas funciones con objetos constantes.


## Cuestiones De Estilo 

En C++, no es obligatorio declarar los miembros públicos y privados de una clase en un orden específico. Existen distintas maneras de organizar estas secciones, aunque algunas convenciones facilitan la lectura y comprensión del código.

Por defecto, los miembros de una clase son privados. Para permitir que otros componentes del programa accedan a determinados miembros, se utiliza la palabra reservada `public` (tambnian llamada *especificador*). Por ejemplo, la clase `Tiempo` podría declararse de la siguiente manera:

```cpp
class Tiempo
{
    int horas;
    int minutos;
    int segundos;

public:
    void establecer(int, int, int);
    void incrementar();
    void escribir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;
};
```

En este caso, las variables miembro `horas`, `minutos` y `segundos` son privadas, ya que se encuentran antes de `public`. A partir de este último, los miembros se consideran públicos hasta que aparece otro especificador de acceso o termina la declaración de la clase.

Aunque no es necesario escribir explícitamente `private` cuando los miembros se encuentran al principio de una clase, algunos programadores prefieren hacerlo para indicar de manera clara qué elementos son privados:

```cpp
class Tiempo
{
private:
    int horas;
    int minutos;
    int segundos;

public:
    void establecer(int, int, int);
    void incrementar();
    void escribir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;
};
```

Otra convención consiste en colocar primero la sección pública y después la privada:

```cpp
class Tiempo
{
public:
    void establecer(int, int, int);
    void incrementar();
    void imprimir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;

private:
    int horas;
    int minutos;
    int segundos;
};
```

Esta última organización suele ser la mas usada porque presenta primero la **interfaz pública** de la clase, es decir, las operaciones que pueden utilizar otros componentes del programa. De esta manera, se facilita la identificación de las funcionalidades disponibles sin dar tanta importancia a los detalles internos de la representación de los datos. 

La distinción entre miembros públicos y privados también permite comprender mejor una de las diferencias principales entre `struct` y `class` en C++. Ambos mecanismos permiten definir tipos de datos que contienen variables miembro y funciones miembro. Sin embargo, **sus miembros tienen distintos niveles de acceso por defecto**: los de una `struct` son públicos, mientras que los de una `class` son privados.

Aunque es posible declarar miembros privados e incluir funciones miembro en una `struct`, no existe una diferencia fundamental en cuanto a las capacidades de ambos mecanismos. La elección depende principalmente de las convenciones y del propósito del tipo de dato. Por lo general, se utiliza `struct` para representar registros que agrupan datos relacionados, mientras que `class` suele preferirse para implementar tipos de datos abstractos, en los que se busca controlar el acceso a la representación interna y ofrecer un conjunto definido de operaciones para trabajar con los objetos.