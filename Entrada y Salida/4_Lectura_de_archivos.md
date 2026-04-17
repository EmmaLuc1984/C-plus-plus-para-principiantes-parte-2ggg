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

Vamos a desmenuzar esto por partes: 

### *Incluir el *header* `fstream` mediante el preprocesador (`#include <fstream>`):*


A través del encabezado `fstream`, la biblioteca estándar de C++ define dos tipos de datos: `ifstream` y `ofstream`, que corresponden, respectivamente, a flujos de entrada y de salida de archivos. De acuerdo con la idea general de los flujos en C++, `ifstream` representa una secuencia de caracteres que proviene de un archivo de entrada, mientras que `ofstream` representa una secuencia de caracteres que se dirige a un archivo de salida.

Las operaciones que ya se conocen de `istream`, como el operador de extracción `>>`, la función `get` y la función `ignore`, también pueden utilizarse con `ifstream`. Del mismo modo, las operaciones de `ostream`, como el operador de inserción `<<` y los manipuladores como `endl`, también funcionan con `ofstream`. Además de estas operaciones básicas, `ifstream` y `ofstream` incluyen funciones adicionales diseñadas específicamente para trabajar con archivos.