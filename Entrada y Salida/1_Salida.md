 # Salida Estandar 
 
 ¿Alguna vez le has preguntado a alguien, “¿sabes qué hora es?” sólo para ver que la persona sonríe y dice, “sí, si sé”, y se aleja? Esta situación es como la que existe en realidad entre tú y la computadora. A lo largo de estas lecciones has aprendido a declarar variables, manejar operadores e incluso usar funciones, pero como te podrás haber dado cuenta, la computadora no te dará resultados hasta que le digas  que los escriba.

 En C++ los valores de variables y expresiones se escriben por medio de una variable especial llamada `cout` junto con el **operador de inserción** `<<`:

 Por ejemplo: 

 ```c++ 
 cout <<  "Hola Mundo :D"; 
 ```

 Esta sentencia muestra la frase `Hola Mundo :D` en el *dispositivo de salida estándar*, normalmente la pantalla. La variable `cout `está predefinida en C++ para denotar un *flujo de salida*. Puedes pensar en un flujo de salida como una secuencia interminable de caracteres que vam a un dispositio de salida.  En el caso de `cout`, el flujo de salida va al dispositivo de salida estándar.

El operador de inserción `<<` toma dos operandos. Su operando izquierdo es una expresión de flujo (en el caso más sencillo, sólo una variable de flujo como `cout`). Su operando derecho es una expresión, que podría ser tan simple como:

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombreDelJuego = "Elden Ring";

    cout << "Estas ultimas dos semanas he estado jugando ";
    cout << nombreDelJuego + " compulsivamente";

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
    string nombreDelJuego = "Elden Ring";

    cout << "Estas ultimas dos semanas he estado jugando "<< nombreDelJuego + " compulsivamente"; 

    return 0;
}
```
Tambien, cada uno de los elementos que van al flujo de salida pueden ser de diferente tipo, por ejemplo: 

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    int diasJugando = 14;
    string nombreDelJuego = "Elden Ring";

    cout << "Llevo " << diasJugando << " dias jugando " << nombreDelJuego + " compulsivamente";

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