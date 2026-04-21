# Lectura de Archivos
En todo lo que se ha visto hasta aquí, se ha supuesto que el ingreso de datos para los programas viene del teclado y que el resultado va a la pantalla. Ahora se examina la introducción y salida de datos hacia y desde archivos.
## Archivos 
Podemos definir a un *archivo*  como un área nombrada en el almacenamiento secundario que contiene una colección de información (por ejemplo, el código de programa que se ha tecleado en algún editor de texto). La información de un archivo se almacena en un medio de almacenamiento secundario, como un disco. Un programa puede obtener datos desde un archivo del mismo modo en que los recibe del teclado, y también puede guardar su salida en un archivo de disco igual que la muestra en la pantalla.

¿Para qué leer datos desde un archivo en lugar de capturarlos desde el teclado? Cuando un programa necesita procesar muchos datos, suele ser más práctico escribirlos primero en un archivo con ayuda de un editor de texto, en vez de ingresarlos mientras el programa se está ejecutando. Además, con un editor es más fácil corregir errores. También permite trabajar por partes, sin necesidad de introducir todo de una sola vez. Y si después se desea ejecutar otra vez el programa, los datos ya guardados pueden reutilizarse sin tener que volver a escribirlos.

¿Por qué querría guardarse la salida de un programa en un archivo? Porque el contenido de ese archivo puede verse en la pantalla y analizarse. Así, es posible revisar los resultados varias veces sin necesidad de ejecutar de nuevo el programa. Además, la información guardada puede usarse como entrada en otro programa.

## Uso de Archivos 

Si se desea que un programa trabaje con entrada y salida de archivos, hay cuatro pasos básicos:

- Incluir el *header* `fstream` mediante el preprocesador (`#include <fstream>`).
- Declarar los flujos de archivo que se van a utilizar.
- Abrir cada archivo para lectura o escritura mediante la función `open`.
- Indicar el nombre del flujo de archivo en cada operación de entrada o salida.

Vamos a desmenuzar esto por partes y posteriormente construiremos un programa: 

### *Incluir el *header* `fstream` mediante el preprocesador (`#include <fstream>`):*


A través del encabezado `fstream`, la biblioteca estándar de C++ define dos tipos de datos: `ifstream` y `ofstream`, que corresponden, respectivamente, a flujos de entrada y de salida de archivos. De acuerdo con la idea general de los flujos en C++, `ifstream` representa una secuencia de caracteres que proviene de un archivo de entrada, mientras que `ofstream` representa una secuencia de caracteres que se dirige a un archivo de salida.

Las operaciones que ya se conocen de `istream`, como el operador de extracción `>>`, la función `get` y la función `ignore`, también pueden utilizarse con `ifstream`. Del mismo modo, las operaciones de `ostream`, como el operador de inserción `<<` y los manipuladores como `endl`, también funcionan con `ofstream`. Además de estas operaciones básicas, `ifstream` y `ofstream` incluyen funciones adicionales diseñadas específicamente para trabajar con archivos.

### *Declarar los flujos de archivo que se van a utilizar:*

En un programa, las variables de flujo se declaran igual que cualquier otra variable: primero se escribe el tipo de dato y después el nombre. Por ejemplo:

```c++
int algun_entero;
float algun_ flotante;
ifstream archivo_de_entrada;
ofstream archivo_de_salida;
```

Las variables de flujo `cin` y `cout` no es necesario declararlas, porque el encabezado iostream ya lo hace automáticamente.


### *Abrir cada archivo para lectura o escritura mediante la función `open`:*

Este paso consiste en consiste en preparar cada archivo para su lectura o escritura, proceso que se conoce como *apertura de archivo*. Al abrir un archivo, el sistema operativo realiza ciertas acciones que dejan listo el archivo para la entrada o la salida de datos.

Los archivos que se usan con más frecuencia se abren con estas instrucciones:

```c++
 archivo_de_entrada.open("entrada.in")
 archivo_de_salida.open("salida.in")
```
Estas dos líneas son llamadas a función. Se nota por los argumentos que reciben. En ambos casos, el argumento es una cadena escrita entre comillas. La primera línea llama a la función `open`, que pertenece al tipo de datos `ifstream`. La segunda llama a otra función `open`, pero relacionada con el tipo `ofstream`. ¿Que hace `open`? Primero, conecta una variable de flujo del programa con un archivo físico almacenado en el disco. En el primer caso, la variable `archivo_de_entrada` queda asociada con el archivo real llamado `entrada.in`. Del mismo modo, la segunda llamada enlaza `archivo_de_salida` con el archivo `salida.in`.

La función `open` también actúa de manera distinta según se trate de un archivo de entrada o de salida. Si es de entrada, coloca el *marcador de lectura* al inicio de los datos del archivo al inicio para que el programa empiece a leer desde el primer dato. Si es un archivo de salida, `open` primero verifica si el archivo ya existe. Si no existe, crea uno nuevo y vacío. Si ya existía, borra su contenido anterior. Después, el *marcador de escritura* se coloca al comienzo del archivo. Conforme el programa guarda información, ese punto avanza y los datos nuevos se van agregando al final.

Debido a que la razón para abrir archivos es prepararlos para lectura o escritura, es necesario abrirlos antes de usar cualquier instrucción de entrada o salida que trabaje con ellos. En un programa, es una buena idea abrir de inmediato los archivos para asegurarse de que están preparados antes de que el programa intente cualquier ingreso o salida de archivos.

Además de la función `open`, los tipos `ifstream` y `ofstream` también cuentan con una función llamada `close`. Esta función no recibe argumentos y se usa de manera similar a esto:

```c++
ifstream archivo_de_entrada;
archivo_de_entrada.open("entrada.in"); // Abrir el archivo
...    
... // Leer y procesar los datos del archivo
...
archivo_de_entrada.close(); // Cerrar el archivo

```

Cerrar un archivo hace que el sistema operativo realice las tareas finales necesarias en el disco y, al mismo tiempo, elimina la conexión entre la variable de flujo y el archivo almacenado.

¿Es obligatorio llamar siempre a `close` cuando terminas de leer o escribir un archivo? En algunos lenguajes sí es muy importante recordarlo. Pero en C++, el archivo se cierra automáticamente cuando el programa sale del bloque de instrucciones en el que se declaró la variable de flujo. En este momento, se ejecuta una función especial llamada *destructor*, que pertenece a `ifstream` y `ofstream`, y esa función se encarga de cerrar el archivo por ti. Por eso, no es muy común ver programas en C++ que llamen explícitamente a `close`. Aun así, muchos programadores prefieren hacerlo como una buena costumbre, y tú también puedes usar esa práctica.


### Indicar el nombre del flujo de archivo en cada operación de entrada o salida: 

Hay un último detalle que debe realizarse al trabajar con archivos. Como ya se indicó, todas las operaciones de `istream` también funcionan con `ifstream`, y todas las operaciones de `ostream` también pueden usarse con `ofstream`. Por eso, para leer o escribir en un archivo, basta con reemplazar `cin` o `cout` por el flujo de archivo correspondiente en las sentencias de entrada y salida. Vamos a revisar esto, para ello considera el siguiente programa: 

```c++




```