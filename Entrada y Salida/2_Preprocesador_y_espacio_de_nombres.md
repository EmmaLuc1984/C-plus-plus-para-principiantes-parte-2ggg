# El Preprocesador en C++

Imagina por un momento que eres un compilador de C++ y te dan el siguiente programa para comprobar errores de sintaxis y, si no existen, los traducirás en código de lenguaje maquina: 

```c++
// ***************************************************************
// Este programa debe de imprimir en pantalla "feliz cumpleaños" 
// ***************************************************************
int main()
{
 cout << "Feliz Cumpleaños :D" << endl;
 return 0;
}
```

Como eres un compilador, reconoces a `int` como una palabra reservada del lenguaje, y a `main`, como el nombre de una función requerida. ¿Pero que sucede con `cout` y `endl`? Quien sea que haya hecho el programa, no las ha declarado como variables o constantes, y tampoco son palabras reservadas. Asi que tú como compilador, no tienes mas opción que emitir un mensaje de error y desistir. 

Para arreglar este programa, lo primero que se debe hacer es insertar una línea cerca de la parte superior que diga: 

```c++
 #include <iostream>
```

La línea dice insertar el contenido de un archivo llamado `iostream` en el programa. Este archivo contiene las declaraciones de `cout`, `endl`, y otros elementos necesarios para efectuar el flujo de entrada y salida. La línea `#include` no es manejada por el compilador de C++, sino por un programa conocido como *preprocesador*. El preprocesador es una parte importante del lenguaje C++. Funciona como un filtro en la etapa de compilación, ya que revisa el código fuente antes de que este llegue al compilador.

Una línea que empieza con el signo de "gato" `#` no se considera una sentencia de C++ y, por eso, no lleva punto y coma. A este tipo de línea se le llama *directiva de preprocesador*. Cuando el preprocesador encuentra una directiva `#include`, inserta en el programa el contenido del archivo indicado. Ese archivo se conoce como *archivo de encabezado* o *header file*. Los archivos de encabezado contienen declaraciones de constantes, variables, tipos de datos y funciones que el programa necesita.

En, por ejemplo, las directivas: 

```c++
#include <iostream> 
#include <cmath>
```

es necesario usar los signos `< >`. Ellos indican al procesador que busque archivos en el *directorio include* estándar, un lugar en el sistema de la computadora que contiene los archivos de encabezado que se relacionan con la biblioteca estándar de C++. En este caso, el archivo `iostream` contiene lo necesario para manejar la entrada y salida de datos, mientras que `cmath` incluye funciones matemáticas que después nos serán útiles como raíces, potencias y funciones trigonométricas. Más adelante utilizaremos otros archivos de encabezado distintos a estos. 

Antes, en el lenguaje C y en versiones antiguas de C++, los archivos de encabezado terminaban con `.h` (por ejemplo, `iostream.h`), donde la “h” hacía referencia a “header”. Sin embargo, en el estándar actual de C++, estos archivos ya no usan ese sufijo.                                                                   



# Introducción a los Espacios de Nombres (Namespaces)

Regresando al programa anterior, incluso si se añade la directiva al preprocesador `#include <iostream>`, el programa no compilará. El compilador aún no reconoce a `cout` y `endl`. La razón es porque esos elementos pertenecen a un *espacio de nombres* (*namespace*) llamado `std`, que es como una “carpeta” donde se organizan elementos relacionados para evitar confusiones con otros nombres parecidos.

Una forma de usar sus elementos es escribir su nombre completo, es decir, poner std:: antes del nombre:

```c++
std::cout
```
Así, el programa quedaría de la siguiente manera:

``` c++ 
// ***************************************************************
// Este programa debe de imprimir en pantalla "feliz cumpleaños" 
// ***************************************************************

#include <iostream>

int main()
{
    std::cout << "Feliz Cumpleaños :D" << std::endl;
    return 0;
}
```

Como puedes ver, tanto `cout` como `endl` deben escribirse con `std::` delante para que el programa los reconozca.

La segunda opción es usar la sentencia `using namespace std;`. Si se coloca cerca del inicio del programa, antes de `main`, permite usar directamente los nombres que están dentro de `std` sin tener que escribir `std::` todo el tiempo. 

Asi, nuestro programa del inicio queda de la siguiente forma: 

```c++
// ***************************************************************
// Este programa debe de imprimir en pantalla "feliz cumpleaños" 
// ***************************************************************

#include <iostream>
using namespace std;

int main()
{
    cout << "Feliz Cumpleaños :D" << endl;
    return 0;
}

```

Por el momento, dado que estamos trabajando en programas pequeños, esta bien usarlo, sin empargo, en programas grandes no es muy recomendable usar `using namespace std;`, pues hace que todos los nombres de `std` se mezclen con los del resto del programa. Esto puede causar confusiones si dos elementos tienen el mismo nombre o incluso provocar errores difíciles de detectar. Por eso, aunque es cómodo para programas pequeños o de práctica, en proyectos más grandes es mejor que escribas `std::` para dejar claro de dónde viene cada elemento.