# Entrada 

Una de las principales ventajas de las computadoras es que un mismo programa puede utilizarse con diferentes conjuntos de datos. Para lograrlo, los datos deben permanecer separados del programa hasta el momento de su ejecución. Entonces, las instrucciones toman los valores del conjunto de datos y los asignan a las variables del programa. Una vez guardados en ellas, el programa ya puede realizar cálculos con esos valores.
A este proceso de transferir valores desde un conjunto de datos externo hacia las variables de un programa se le llama entrada. En términos generales, también se dice que la computadora está leyendo datos externos para almacenarlos en variables. Estos datos pueden provenir de un dispositivo de entrada o de un archivo guardado en un dispositivo de almacenamiento. Más adelante veremos el uso de archivos; por ahora, se consideraremos al teclado como el medio estándar para introducir datos.

## Flujo de Entarda y el Operador de Extracción `>>`


El concepto de *flujo* es esencial para comprender la entrada y salida en C++. Como explicamos antes, un *flujo de salida* puede imaginarse como una sucesión continua de caracteres que viajan desde el programa hacia un dispositivo de salida. De forma similar, un *flujo de entrada* es una sucesión continua de caracteres que llega al programa desde un dispositivo de entrada.

Para trabajar con estos flujos, se utiliza la directiva del preprocesador:

``` c++
#include <iostream>
```

El *header file* `iostream` incluye, entre otras cosas, la definición de dos tipos de datos: `istream` y `ostream`. Estos tipos representan, respectivamente, los flujos de entrada y de salida. Además, este encabezado contiene declaraciones como las siguientes:

```c++
istream cin;
ostream cout;
```

La primera indica que `cin` es una variable de tipo `istream`. La segunda señala que `cout` es una variable de tipo `ostream`. En general, `cin` está asociado con el dispositivo de entrada estándar, que normalmente es el teclado, mientras que `cout` se relaciona con el dispositivo de salida estándar, que por lo común es la pantalla.

Como ya vimos en entradas anteriores, puedes enviar valores a `cout` mediante el operador de inserción `<<`:

```c++
cout <<  "Hola Mundo :D"; 
```
De manera parecida, se pueden "leer" datos desde `cin` con el operador de extracción `>>`:

```c++
cin >> costo;
```
Cuando la computadora ejecuta esta instrucción, toma el siguiente dato escrito en el teclado, por ejemplo 425, y lo almacena en la variable `cost`.

