# Entrada Estandar

Una de las principales ventajas de las computadoras es que un mismo programa puede utilizarse con diferentes conjuntos de datos. Para lograrlo, los datos deben permanecer separados del programa hasta el momento de su ejecución. Entonces, las instrucciones toman los valores del conjunto de datos y los asignan a las variables del programa. Una vez guardados en ellas, el programa ya puede realizar cálculos con esos valores.
A este proceso de transferir valores desde un conjunto de datos externo hacia las variables de un programa se le llama entrada. En términos generales, también se dice que la computadora está leyendo datos externos para almacenarlos en variables. Estos datos pueden provenir de un dispositivo de entrada o de un archivo guardado en un dispositivo de almacenamiento. Más adelante veremos el uso de archivos; por ahora, se consideraremos al teclado como el medio estándar para introducir datos.

## Flujo de Entrada y el Operador de Extracción `>>`


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
Cuando la computadora ejecuta esta instrucción, toma el siguiente dato escrito en el teclado, por ejemplo 42, y lo almacena en la variable `costo`.

El operador de extracción `>>` utiliza dos operandos. El de la izquierda es una expresión de flujo, que en su forma más simple es la variable `cin`. El de la derecha es la variable donde se guardan los datos ingresados. Por ahora, asumiremos que esa variable es de un tipo sencillo, `int`, `float` o `char`. 

También es posible usar `>>` varias veces en una sola instrucción de entrada. Cada uso toma el siguiente dato disponible del flujo de entrada. Por ejemplo, estas dos formas son equivalentes:

```c++ 
cin >>> costo >>> peso;
```
y 

```c++
cin >> costo;
cin >> peso;
```

Por practicidad, procura usar la primer opción. 

Algunas cosas mas que debes de saber sobre el uso del operador de extracción son las siguientes: 

- En una sentencia de entrada *solo* se usan variables, porque son las que tienen un espacio reservado en memoria para guardar datos. Por ejemplo, algo como:  
  ```c++
  cin >>> 5
  ```
  no está permitido porque 5 no es un lugar donde poder guardar información. 

- El dato que escribas debe coincidir con el tipo de la variable. Si la variable es `int`, debe recibir un número entero; si es `float`, un número decimal.
- El operador `>>` omite los espacios en blanco y lee solo lo necesario. Eso significa que no toma en cuenta espacios, saltos de línea ni tabulaciones al buscar el siguiente dato. 

## Marcador de Lectura 

Para entender un poco mejor cómo funciona la entrada de datos, tenemos el concepto de *marcador de lectura*. Este marcador funciona como un separador que indica en qué parte del flujo de entrada debe seguir leyendo la computadora. Es decir, señala cuál es el siguiente carácter que todavía no se ha leído. El operador de extracción `>>` deja ese marcador justo después del último dato capturado. Por ejemplo, supon que quieres ingresar los datos 25 8 y el porgrama tiene las siguientes sentencias: 

``` c++
int x, y;
cin >> x;
```

Cuando se ejecuta `cin >> x;`, el operador de extracción busca el primer número disponible en la entrada, lee 25 y lo guarda en la variable `x`; como ya obtuvo un entero completo, se detiene en ese punto y deja el siguiente dato, 8, esperando para una próxima lectura, de modo que el marcador de lectura queda colocado justo antes de ese valor para continuar desde allí cuando se use otra vez `cin >> `.


## Lectura de Datos con la Función `get`

Como mencionamos hace un ratito, el operador `>>` ignora los espacios en blanco iniciales, como espacios y saltos de línea, mientras busca el siguiente dato en la entrada. Por ejemplo, si tenemos que `ch1` y `ch2` son varibales de tipo `char` y el programa ejecuta: 

```c++
cin >> ch1 >> ch2; 
```
y el flujo de entrada contiene: 

```c++
'R' '-' '1' // '-' dentota un espacio en blanco
```
entonces el operador de extracción guarda R en `ch1`, pasa por alto el espacio en blanco y coloca 1 en `ch2`. Nota que el carácter '1' no es igual al entero 1; ambos se representan de forma distinta en la memoria, y el operador interpreta los datos según el tipo de variable que recibe.

Ahora bien, si se quiere leer exactamente tres caracteres (R, un espacio y 1), `>>` no sirve, porque siempre omite los espacios en blanco. Para eso, el tipo `istream` ofrece otra opción: la función `get`, que lee el siguiente carácter sin saltarse ningún espacio. Una llamada a esta función se escribe así:

```c++
cin.get(alguna_variable_char);
```

Para usar `get`, se escribe primero el nombre de una variable de tipo `istream`  (en este caso, `cin`), luego un punto y después el nombre de la función junto con sus argumentos.

Es importante notar que `get` se llama como una *función void*, es decir, la llamada completa forma una sentencia por sí sola y no se utiliza dentro de una expresión más grande. Su función es leer el siguiente carácter disponible en el flujo de entrada, incluso si es un espacio en blanco, y guardarlo en la variable indicada, como, en nuestro caso, `alguna_variable_char`.

Además, el argumento de `get` debe ser una variable, no una constante ni una expresión, porque la función necesita saber en qué lugar va a almacenar el carácter leído.

Gracias a `get`, ahora es posible ingresar los tres caracteres anteriores:

```c++
'R' '-' '1'  // '-' denota el espacio en blanco que tecleamos en la computadora.
```

Se pueden usar tres llamadas consecutivas para la función `get`:

```c++
cin.get(ch1);
cin.get(ch2);
cin.get(ch3);
```

o se puede hacer de esta manera:

```c++
cin >> ch1;
cin.get(ch2);
cin >> ch3;

```

Por lo general, la primer forma suele ser mas facil de leer y entender. 



## Omitir Carácterees con la Función `ignore `

En C++ contamos con la función `ignore`, la cual del tipo `istream`. Esta es una herramienta que casi nunca se usa, pero que resulta muy útil cuando se necesita. Sirve para leer y descartar caracteres que están en el flujo de entrada, es decir, hace que el programa ignore parte de lo que el usuario escribió. Es una función con dos argumentos, llamada de esta manera:

```c++
cin.ignore(cantidad, delimitador);
```
- La `cantidad` es el número máximo de caracteres que se van a descartar.
- El `delimitador` hace referencia al carácter que indica cuándo se debe detener el proceso de ignorar (a menudo `\n`)

Un ejemplo para ver como funciona es el siguiente. Supón que tienes el siguiente programa: 

```c++
#include <iostream>
using namespace std;

int main() {
    int edad;
    char opcion;

    cout << "Escribe tu edad: ";
    cin >> edad;   // El usuario escribe: 25abc⏎

    cin.ignore(100, '\n');  // Borra TODO lo que quedó: "abc\n"

    cout << "¿Deseas continuar? (s/n): ";
    cin >> opcion;

    cout << "Edad: " << edad << endl;
    cout << "Opcion: " << opcion << endl;

    return 0;
}
```

Y supón que por alguna razón quie está usando el programa ingresa como edad: 

```c++
25abc\n  //`\n` en este caso es el enter que hacemos al momento de ingresar el último dato. 
```
Entonces el flujo de entrada queda de la siguiente manera: 

```c++
'2' '5' 'a' 'b' 'c' '\n' 
```

Entonces `cin >>` solo toma como entrada 25 y el resto de carácteres se queda en el *buffer*. Posteriormente `cin.ignore(100, '\n');` elimina del *buffer*: 

```c++
'a' 'b' 'c' '\n'
```

## Lectura de Datos de Cadena

Ahora veremos como ingresar cadenas de caracteres: Para guardar una cadena de caracteres en una variable `string`, hay dos maneras principales. La primera consiste en usar el operador de extracción `>>`. Cuando este operador lee datos para una variable `string`, ignora primero los espacios en blanco al inicio y luego comienza a copiar los caracteres hasta encontrar el siguiente espacio en blanco. Ese espacio no se guarda en la cadena; simplemente queda pendiente en el flujo de entrada. Por ejemplo, si tenemos las instrucciones: 

```c++
string nombre; 
string apellido; 
cin >> nombre >> apellido; 
```
Y tenemos como flujo de entrada: 

```c++
'-' '-' 'P' 'e' 't' 'e' 'r' '-' '-' 'P' 'a' 'r' 'k' 'e' 'r' '-' '-' '-' '2' '5' 
// '-' denota a un espacio en blanco
```
Es decir, que lo que ingresamos se ve de la forma: 

```c++
  Peter  Parker   25
```

entonces `nombre` almacena `Peter`, `apellido` alamcena `Parker` y lo que queda en el flujo es:

```c++
'-' '-' '-' '2' '5' 
// '-' denota a un espacio en blanco
 ```

 Sin embargo, `>>` tiene una limitación importante: no sirve para leer cadenas que contengan espacios, porque la lectura se detiene en cuanto aparece uno. Por eso existe una segunda opción: la función `getline`. Esta función se usa de la siguiente manera: 

 ```c++
 getline(cin, alguna_variable_string);
 ```

 A diferencia del operador `>>`, `getline` recibe dos argumentos: el primero es el flujo de entrada, como `cin`, y el segundo es la variable `string` donde se guardará el texto. Esta función no salta los espacios iniciales y sigue leyendo hasta encontrar el carácter de nueva línea `\n`. En otras palabras, `getline` permite capturar una línea completa, incluyendo los espacios que haya dentro. El salto de línea se lee, pero no se guarda dentro de la cadena. El ejemplo completo quedaria de esta manera: 


```c++
#include <iostream>
#include <string>
using namespace std;

int main() {

    string nombre_completo_y_edad;

    cout << "Escribe tu nombre completo: ";
    getline(cin, nombre_completo_y_edad);

    cout << "Tu nombre completo es: " << nombre_completo_y_edad << endl;

    return 0;
}
```

Si tu ingresas:

```c++
  Peter  Parker   25

```
entonces `nombre_completo_y_edad` guardará todo incluyendo espacios, hasta encontrar el salto de linea. 