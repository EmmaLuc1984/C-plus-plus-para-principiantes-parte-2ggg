
# Introducción 


## Un Pequeño Recordatorio de Tipos de Datos y su Tamaño
En la sección anterior vimos algunos tipos de datos. Quizás aún te preguntes por qué existen tipos muy parecidos entre sí, pero que aun así son distintos. La respuesta está en el tamaño que ocupan en memoria, es decir, en la cantidad de espacio que el programa reserva para guardar ese dato mientras se ejecuta. Ese tamaño normalmente se mide en *bytes*. Un byte es una unidad pequeña de almacenamiento que sirve para representar información en la computadora; de manera sencilla, puede entenderse como una “porción” de memoria que ayuda a guardar datos.

Este tamaño influye directamente en el rango de valores que puede almacenar cada tipo y en la precisión con la que representa la información. Por ejemplo, un tipo más “grande” suele permitir guardar números más grandes o con más decimales, como ocurre con `double` frente a `float`. En cambio, un tipo más “pequeño” ocupa menos memoria, lo que puede ayudar a aprovechar mejor los recursos del sistema y, en algunos casos, hacer que el programa trabaje de forma más eficiente.

La siguiente tabla muestra algunos de los tipos de datos mas comunes junto con su tamaño:

| Nombre               | Descripción                                   | Tamaño | Rango de valores* |
|---------------------:|:----------------------------------------------|:-------:|:------------------:|
| `char`               | Carácter o entero pequeño                      | 1 byte  | con signo: -128 a 127<br>sin signo: 0 a 255 |
| `short int` (o simplemente `short`)| Entero pequeño                             | 2 bytes | con signo: -32768 a 32767<br>sin signo: 0 a 65535 |
| `int`                | Entero                                         | 4 bytes | con signo: -2147483648 a 2147483647<br>sin signo: 0 a 4294967295 |
| `long int ` (o simplemente `long`)  | Entero grande                         | 8 bytes | con signo: -2147483648 a 2147483647<br>sin signo: 0 a 4294967295 |
| `bool`               | Valor booleano. Puede tomar dos valores: true o false | 1 byte  | `true` o `false` |
| `float`              | Número de punto flotante                       | 4 bytes | ~ ±3.4e±38 (≈ 7 dígitos de precisión) |
| `double`             | Punto flotante de doble precisión              | 8 bytes | ~ ±1.7e±308 (≈ 15 dígitos de precisión) |
| `long double`        | Long de punto flotante de doble precisión      | 8 bytes | ~ ±1.7e±308 (≈ 15 dígitos — depende del compilador) |

`Rango de valores*` hace referencia al conjunto de numeros que pueden representar. `sin signo` o mas precisamente `unsigned` hace referencia a que un tipo de dato no puede guardar valores negativos. `unsigned` se usa antes de un tipo entero para indicar que solo almacenará valores cero o positivos. Por ejemplo: `unsigned int`, `unsigned short` y `unsigned long`.

Se usa principalmente con tipos enteros, como `int`, `short`, `long`. No se usa normalmente con `float` o `double`, porque esos tipos ya representan números reales y no trabajan de la misma forma con el signo.

En la sección anterior tambien mencionamos  el tipo `string` el cual se usa para almacenar texto. Debido a su naturaleza, es imposible dar una descripción de su tamaño en bytes. 
## Sentencias, Expresiones y Operadores en C++. 

En C++ las unidades más básicas de un programa son las **sentencias**. Una sentencia es una **instrucción** que indica al programa que realice una acción específica, como **declarar una variable**, **asignar un valor**, **evaluar una expresión** o **controlar el flujo de ejecución**. En otras palabras, las sentencias representan los pasos individuales que el programa ejecuta para llevar a cabo una tarea. Cuando el programa se ejecuta, estas instrucciones se procesan generalmente **una tras otra**, siguiendo el orden en el que aparecen en el código. En muchos casos, las sentencias terminan con un **punto y coma** (`;`), que indica el final de la instrucción.

Dentro de este conjunto de instrucciones existe un tipo de construcción especialmente importante: las *expresiones*. De forma general, una expresión es *cualquier fragmento de código que puede evaluarse para producir un valor*. Muchas de las operaciones que realizamos en un programa se expresan precisamente mediante expresiones. Por ejemplo, cuando asignamos un valor a una variable, normalmente utilizamos una expresión cuyo resultado se almacena en dicha variable.

Hasta ahora hemos visto ejemplos sencillos, como asignar directamente un valor a una variable. Sin embargo, las expresiones pueden ser mucho más complejas: pueden combinar *valores constantes*, *variables* y *resultados de otras expresiones* para producir un nuevo valor. De hecho, una gran parte del trabajo que realiza un programa consiste en *evaluar expresiones* y utilizar sus resultados.

Para entender cómo las expresiones producen esos valores, debemos introducir otro concepto fundamental del lenguaje: los *operadores*. Un *operador* es un símbolo que indica que debe realizarse una determinada operación. Esta operación se aplica sobre uno o más *operandos*, que pueden ser valores constantes, variables o incluso otras expresiones. El operador toma esos operandos, aplica una regla definida por el lenguaje (por ejemplo, una operación *aritmética*, *lógica* o de *comparación*) y produce como resultado *un nuevo valor*.

Gracias a los operadores es posible construir expresiones cada vez más elaboradas, combinando distintos valores y operaciones. En lo que resta de esta sección nos centraremos en estudiar principalmente los *operadores aritméticos*, que permiten realizar cálculos básicos y constituyen una de las herramientas más comunes para construir expresiones en C++. No serán los únicos, pues veremos que tambien existen operadores con unanaturalez distinta. 






