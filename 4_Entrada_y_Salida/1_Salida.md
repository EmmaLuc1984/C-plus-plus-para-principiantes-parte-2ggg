 # Salida Estandar 
 
 ¿Alguna vez le has preguntado a alguien, “¿sabes qué hora es?” sólo para ver que la persona sonríe y dice, “sí, si sé”, y se aleja? Esta situación es como la que existe en realidad entre tú y la computadora. A lo largo de estas lecciones has aprendido a declarar variables, manejar operadores e incluso usar funciones, pero como te podrás haber dado cuenta, la computadora no te dará resultados hasta que le digas que los escriba.

 En C++ los valores de variables y expresiones se escriben por medio de una variable especial llamada `cout` junto con el **operador de inserción** `<<`:

 Por ejemplo: 

 ```c++ 
 cout <<  "Hola Mundo :D"; 
 ```

 Esta sentencia muestra la frase `Hola Mundo :D` en el *dispositivo de salida estándar*, normalmente la pantalla. La variable `cout `está predefinida en C++ para denotar un *flujo de salida*. Puedes pensar en un flujo de salida como una secuencia interminable de caracteres que vam a un dispositivo de salida.  En el caso de `cout`, el flujo de salida va al dispositivo de salida estándar.

El operador de inserción `<<` toma dos operandos. Su operando izquierdo es una expresión de flujo (en el caso más sencillo, sólo una variable de flujo como `cout`). Su operando derecho es una expresión, que podría ser tan simple como:

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre_del_videojuego = "Elden Ring";

    cout << "Estas ultimas dos semanas he estado jugando ";
    cout << nombre_del_videojuego + " compulsivamente";

    return 0;
}
```
El operador de inserción convierte a su operando derecho en una secuencia de caracteres y los inserta en (o, de manera más precisa, agrega a) el flujo de salida.  Observa cómo `<<` apunta en la dirección que van los datos, de la expresión escrita a la derecha al flujo de salida a la izquierda.

Se puede emplear el operador `<<` múltiples veces dentro de una misma instrucción de salida. Cada uso agrega un nuevo dato al flujo de salida. Por ejemplo, es posible combinar dos sentencias de salida en una sola, así: 

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre_del_videojuego = "Elden Ring";

    cout << "Estas ultimas dos semanas he estado jugando "<< nombre_del_videojuego  + " compulsivamente"; 

    return 0;
}
```
Tambien, cada uno de los elementos que van al flujo de salida pueden ser de diferente tipo, por ejemplo: 

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    int dias_jugando = 14;
    string nombre_del_videojuego = "Elden Ring";

    cout << "Llevo " << dias_jugando << " dias jugando " << nombre_del_videojuego + " compulsivamente";

    return 0;
}
```


Como nota importante, recuerda siempre usar comillas para encerrar cadenas (como lo hicimos con `"Estas ultimas dos semanas he estado jugando"`). Si no escribes la cadena entre comillas, es probable que te aparezca un mensaje de error (como “UNDECLARED IDENTIFIER”) del compilador de C++. Si deseas imprimir una cadena que incluye un par de comillas, se debe escribir el carácter `\`, y un par de comillas, sin espacio entre ellas, en la cadena. Por ejemplo, para imprimir los caracteres: 

```c++
Felicidades "Elden Ring" por tu salida, saliste del videojuego
```
La instrucción debe escribirse de la siguiente manera: 

```c++
cout << "Felicidades \"Elden Ring\" por tu salida, saliste del videojuego"
```


## Formateo de Salida en Consola

Normalmente, las sentencias de salida sucesivas causan que la salida continúe a lo largo de la misma línea de la pantalla. La secuencia:

```c++
cout << "Hola";
cout << "Mundo"; 
```
imprime lo siguiente en consola: 

```c++
HolaMundo 
```

Para imprimir las dos palabras en líneas separadas, se puede hacer esto:

```c++
cout << "Hola" << endl;
cout << "Mundo" << endl; 
```
La salida en consola es la siguiente: 

```c++
Hola
Mundo 
```
El identificador `endl` es una característica especial de C++ llamada *manipulador*. Veremos que es un manipulador más adelante. Lo importante es que notes que `endl` permite terminar una línea de salida e ir a la siguiente siempre que lo desees.

Tambien puedes replicar los resultados anteriores de la siguiente manera: 

```c++
cout << "Hola\n";
cout << "Mundo\n";
```
o incluso en una sola linea: 

```c++
cout << "Hola\nMundo\n";
```
el resultado sigue siendo el mismo: 

```c++
Hola
Mundo 
```

Puedes usar cualquiera de los dos sin mucho problema, pero debes de saber que `\n` solo inserta un salto de línea, mientras que `endl` además de saltar de línea, vacía algo llamado *búfer* de salida. El búfer es una zona de memoria temporal donde se almacena lo que quieres imprimir antes de mostrarse en pantalla. Al vaciarlo, se garantiza que el texto se muestre de inmediato. Por ello, `\n` suele ser más eficiente y se utiliza con mayor frecuencia.

Ahora bien, ¿que crees que impriman las siguientes sentencias? 
```c++
cout << "Estoy jugando a " << endl;
cout << endl;
cout << "The Legend of Zelda: Tears of the Kingdom." << endl;
```

La primer sentencia de salida ocasiona que se impriman las palabras *Estoy jugando a*. `endl` hace que el cursor de pantalla vaya a la siguiente línea. La siguiente sentencia no imprime nada pero va a la siguiente línea. La tercera sentencia imprime las palabras *The Legend of Zelda: Tears of the Kingdom.*. y termina la línea. La salida resultante son las tres líneas: 

```c++
Estoy jugando a 

The Legend of Zelda: Tears of the Kingdom.
```

Como probablemente ya intuiste, tres usos consecutivos de `end1` producen dos líneas en blanco, cuatro usos consecutivos producen tres líneas en blanco, etcétera.

Nota que tenemos mucha flexibilidad en la forma de escribir una sentencia de salida en un programa en C++. Por ejemplo, las siguientes tres sentencias:

```c++
cout << "Estoy jugando a " << endl;
cout << endl;
cout << "The Legend of Zelda: Tears of the Kingdom." << endl;
```
también podrían combinarse en dos:

```c++
cout << "Estoy jugando a " << endl << endl;
cout << "The Legend of Zelda: Tears of the Kingdom." << endl;
```
o incluso en una sola: 

```c++
cout << "Estoy jugando a " << endl << endl << "The Legend of Zelda: Tears of the Kingdom." << endl;
```
Todos estos nos dan el mismo resultado: 

```c++
Estoy jugando a 

The Legend of Zelda: Tears of the Kingdom.
```

Un ejemplo mas con el mismo resultado es:
```c++
cout << "Estoy jugando a " << endl << endl
     << "The Legend of Zelda: Tears of the Kingdom." << endl;
```

En este último se muestra que es posible extender una sola sentencia de C++ en más de una línea del programa. El compilador no trata el salto de línea físico como el final de la instrucción, sino al punto y coma `;` como el fin de la sentencia. Y si, por si te lo preguntas, todo esto funciona exactamente igual usando `\n`. 


Para terminar, tambien podemos controlar el espaciamiento horizontal de la salida, una técnica es enviar caracteres extra en blanco al flujo de salida.

Por ejemplo, para producir esta salida:

```text
    *   *   *   *   *   *   *   *   *

  *   *   *   *   *   *   *   *   *

    *   *   *   *   *   *   *   *   *
```

usariamos las instrucciones: 

```c++
cout << "  *   *   *   *   *   *   *   *   *" << endl << endl;
cout << "*   *   *   *   *   *   *   *   *" << endl << endl;
cout << "  *   *   *   *   *   *   *   *   *" << endl;
```

Todos los espacios en blanco y asteriscos están entre comillas, así que se imprimen literalmente como están escritos en el programa. Los manipuladores `endl` proporcionan las líneas en blanco entre los renglones de asteriscos.

Si quieres que se impriman espacios en blanco debes de encerrarlos entre apóstrofos `' ' `. La sentencia: 

```c++
cout << "*" <<                                                     "*";
```
produce la salida:

```c++
**
```

A pesar de los espacios en blanco incluidos en la sentencia de salida, los asteriscos se imprimen lado a lado porque los espacios en blanco no están encerrados entre apóstrofos. La manera correcta es: 
```c++
cout << '*' << ' ' << '*';
```
la cual produce la salida:

```c++
* *

```