# Enumeraciones

Una *enumeración* es un tipo de dato definido por el usuario cuyos valores están restringidos a un conjunto de constantes simbólicas con nombre (llamadas *enumeradores*).

C++ permite definir dos tipos de enumeraciones: las **enumeraciones sin ámbito**, que corresponden a la forma tradicional de declarar un `enum`, y las **enumeraciones con ámbito**, que se declaran mediante la sentencia `enum class`. En esta sección nos centraremos primero en las enumeraciones sin ámbito, ya que las enumeraciones con ámbito requieren introducir previamente algunos conceptos relacionados con temas posteriores.

## Enumeraciones Sin Ambito 
La sintaxis de una enumeración es la siguiente: 

```c++
enum Nombre { enumerador1, 
              enumerador2, 
                 .
                 .
                 .}; 
```
Por ejemplo: 


```c++ 

// Definimos una nueva enumeración sin ámbito llamada Color
enum Color
{
    // Aquí están los enumeradores
    // Estas constantes simbólicas definen todos los valores posibles que puede contener este tipo
    // Cada enumerador se separa con una coma, no con un punto y coma
    rojo,
    verde,
    azul, // la coma al final es opcional, pero es recomendable ponerla
}; // la definición del enum debe terminar con punto y coma

int main()
{
    // Define algunas variables del tipo enumerado Color
    Color manzana { rojo };   // mi manzana es roja
    Color camisa { verde }; // mi camisa es verde
    Color taza { azul };    // mi taza es azul

    Color calcetines { blanco}; // error:  blanco  no es un enumerador de Color
    Color sombrero { 2 };       // error: 2 no es un enumerador de Color

    return 0;
}

```

Observa con atención: En el ejemplo comenzamos escribiendo la palabra reservada `enum`, que le indica al compilador que vamos a definir una enumeración sin ámbito, a la que llamamos `Color`.

Dentro de llaves, colocamos los enumeradores del tipo: `rojo`, `verde` y `azul`. Estos valores son los únicos que puede tomar `Color`. Cada enumerador se separa con una coma, no con punto y coma. La coma final es opcional, aunque se recomienda para mantener un estilo uniforme.

Normalmente, cada enumerador se escribe en una línea distinta. Sin embargo, en ejemplos simples, donde hay pocos valores y no se necesitan comentarios, también pueden escribirse todos en la misma línea. La definición del tipo `Color` termina con un punto y coma. Con esto, la enumeración queda completamente definida.

Después, dentro de `main`, se crean tres variables de tipo `Color`: `manzana` se inicializa con `rojo`, `camisa` con `verde` y `taza` con `azul`. En cada caso se reserva memoria para el objeto correspondiente. Es importante recordar que una variable de este tipo solo puede inicializarse con uno de los enumeradores definidos para esa enumeración. Por eso, `calcetines` y `sombrero` provocan errores de compilación: `blanco` y 2 no pertenecen al tipo `Color`.

Por convención, el nombre de una enumeración suele empezar con mayúscula. En cambio, los enumeradores deben tener nombre, aunque no existe una forma universalmente aceptada para escribirlos. Algunas convenciones comunes son usar minúsculas (rojo), mayúsculas iniciales (Rojo), mayúsculas completas (ROJO), etc. En nuestro caso, optaremos por escirbirlas unicamente usando minusculas: `rojo`

Los nombres de los enumeradores deben de cumplir las mismas reglas que usamos para nombrar variables, funciones, etc. 
Por ejemplo, si consideramos ahora: 

```c++
enum Vocal {'a', 'e', 'i', 'o', 'u',}; // Error
```
Esta declaración es incorrecta porque 'A', 'E', etc. son constantes de tipo `char` y no un nombre (o mas formalmente, un *identificador*).

De manera similar:
```c++
enum Lugares {1ro, 2do, 3ro,};    // Error
```
es una declaración inválida, ya que un identificador no puede comenzar con un dígito.


También es importante considerar el alcance de los identificadores. Por ejemplo:

```c++
enum Alimento {
    maiz,
    arroz,
    papa,
    frijol,
};

enum Cereal {
    trigo,
    maiz,
    centeno,
    cebada,
    sorgo,
};    // Error
```
Cada enumeración es válida por separado, pero no pueden declararse juntas de esta manera. El problema es que `maiz` aparece en ambas enumeraciones y los identificadores que pertenecen al mismo alcance deben ser únicos. Por lo tanto, un mismo identificador no puede definirse dos veces dentro del mismo alcance.


### Relacionales
Algo que aún no habíamos mencionado es que los enumeradores son **ordenados** y, además, tienen una **representación numérica implícita**. Esto significa que cada enumerador tiene asociado un número entero. De manera predeterminada, el primero comienza en `0` y los siguientes aumentan de uno en uno. Por ejemplo:

```c++
enum Dias {
    domingo,  // 0
    lunes,    // 1
    martes,   // 2
    miercoles,// 3
    jueves,   // 4
    viernes,  // 5
    sabado    // 6
};
```

Como los enumeradores están ordenados, podemos utilizar **operadores relacionales** como `<`, `>` o `==` para compararlos. Al hacerlo, estamos comprobando su posición dentro de la enumeración.

Por ejemplo:

```c++
domingo < lunes
lunes < martes
```

Ambas expresiones son verdaderas, ya que `domingo` corresponde a `0`, `lunes` a `1` y `martes` a `2`.

Los valores se asignan automáticamente siguiendo el orden en que aparecen los enumeradores. Sin embargo, también podemos establecerlos de forma explícita:

```c++
enum dias {
    domingo = 4,
    lunes = 18,
    martes = 9
};
```

En este caso, cada enumerador tiene un valor diferente al que tendría normalmente. Aunque C++ permite hacerlo, en la mayoría de los casos no es necesario especificar estos valores, ya que normalmente nos interesa trabajar con los enumeradores y su orden, más que con los números que tienen asociados.


### Asignaciónes

Supongamos que estamos desarrollando un programa para una clínica veterinaria. El programa necesita llevar un registro de las distintas clases de animales que pueden ser atendidos. Para representar estas categorías, podemos definir una enumeración como la siguiente:

```c++
enum Animal {
    roedor,
    gato,
    perro,
    loro,
    tortuga,
    caballo,
    cerdo,
    oveja
};
```

En este caso, `Animal` es el identificador del tipo de enumeración, mientras que `roedor`, `gato`, `perro`, etc. son los valores que forman parte de ella.

Es importante señalar que estos valores **no son nombres de variables**. Por ejemplo, `gato` representa uno de los valores posibles del tipo `Animal` y puede almacenarse en una variable de dicho tipo.

Podemos crear, por ejemplo, dos variables de tipo `Animal`:

```c++
Animal paciente_interno;
Animal paciente_externo;
```

Ambas variables pueden almacenar cualquiera de los valores definidos en la enumeración. Por ejemplo:

```c++
paciente_interno = roedor;
paciente_externo = perro;
```

De esta manera, `roedor` y `perro` son valores de la enumeración, mientras que `paciente_interno` y `paciente_externo` son variables que pueden almacenarlos.

La asignación también puede hacerse entre variables del mismo tipo. Por ejemplo:

```c++
paciente_interno = roedor;
paciente_externo = paciente_interno;
```

Las dos asignaciones son válidas porque, tanto `roedor` como `paciente_interno`, representan valores del tipo `animal`.

Aunque los enumeradores tienen una representación numérica implícita, esto no significa que podamos asignar directamente cualquier número entero a una variable de tipo `animal`. Por ejemplo:

```c++
paciente_interno = 2;  // Error
```

En cambio, un enumerador sí puede utilizarse en una variable de tipo entero:

```c++
int numero;

numero = perro;  // Válido
```

En este caso, `perro` se convierte automáticamente en su valor entero correspondiente.

Por lo tanto, C++ permite pasar de un enumerador a un número entero, pero no realiza automáticamente la conversión en sentido contrario. Esta restricción ayuda a evitar que una variable de tipo `Animal` reciba accidentalmente un valor que no forme parte de la enumeración. Por ejemplo:

```c++
paciente_interno = 65;  // Error
```

Así, cuando trabajamos con una variable de tipo `Animal`, debemos asignarle valores que pertenezcan a la enumeración, como `roedor`, `gato`, `perro`, `loro`, etc.





### Incrementos

Supongamos que queremos avanzar al siguiente valor de una enumeración. Quizas estés animado a hacerlo de la siguiente manera:

```c++
paciente_interno = paciente_interno + 1;  // Error
```

La expresión del lado derecho sí es válida, ya que `paciente_interno` puede convertirse temporalmente a un entero para realizar la suma. Sin embargo, el resultado de `paciente_interno + 1` es de tipo `int`, y ese valor no puede asignarse directamente a una variable de tipo `Animal`.

Por la misma razón, tampoco podemos utilizar directamente el operador de incremento:

```c++
paciente_interno++;  // Error
```

Para realizar el incremento, debemos convertir nuevamente el resultado al tipo `Animal`. Por ejemplo:

```c++
paciente_interno = Animal(paciente_interno + 1);  // Correcto
```

Aquí se realiza una conversión explícita de tipos para indicar que el resultado debe tratarse como un valor del tipo `Animal`.

Esto resulta especialmente útil cuando queremos recorrer todos los valores de una enumeración mediante un ciclo. Por ejemplo:

```c++
Animal paciente;

for (paciente = roedor; paciente <= oveja; paciente++)  // Error
```

Este ciclo no es válido porque `paciente++` presenta el mismo problema que vimos anteriormente. En su lugar, podemos realizar el incremento mediante una asignación y una conversión explícita:

```c++
for (paciente = roedor;
     paciente <= oveja;
     paciente = animal(paciente + 1))
```

De esta forma, `paciente` va tomando cada uno de los valores de la enumeración, desde `roedor` hasta `oveja`.




### Estructuras de Control 

Ya vimos que los enumeradores pueden compararse mediante operadores relacionales. Ahora podemos aprovechar esta característica dentro de **estructuras de control** para controlar el flujo de un programa.

Por ejemplo, podemos utilizar una condición `if` para comprobar si un animal pertenece a cierto grupo:

```c++
if (paciente_interno <= loro) {
    cout << "Animal pequeño";
}
```

También podemos utilizar una enumeración directamente en una sentencia `switch`. Esto permite realizar diferentes acciones dependiendo del valor que contenga una variable:

```c++
switch (paciente_interno) {
    case roedor:
    case gato:
    case perro:
    case loro:
        cout << "Jaula";
        break;

    case tortuga:
        cout << "Terrario";
        break;

    case caballo:
    case cerdo:
    case oveja:
        cout << "Establo";
        break;
}
```

En este ejemplo, varios enumeradores pueden compartir un mismo `case`, ya que representan animales que requieren el mismo tipo de espacio.

Las enumeraciones también pueden utilizarse para controlar ciclos. Ya vimos que se puede hacer en un ciclo `for`, pero tambien podemos usar un ciclo `while`, por mencionar alguno:

```c++
paciente_interno = roedor;

while (paciente_interno <= oveja) {
    cout << paciente_interno << endl;
    paciente_interno = Animal(paciente_interno + 1);
}
```

### Entrada y Salida 

A diferencia de los tipos de datos básicos como `int` o `float`, no podemos leer directamente desde `cin` un valor de una enumeración escribiendo su nombre. Por ello, una forma sencilla de trabajar con ellos es leer primero una cadena de texto y después convertirla en uno de los valores de la enumeración.

Volviendo a nuestro ejemplo de la veterinaria, podemos pedir el nombre del animal y asignar el enumerador correspondiente:

```c++
#include <cctype>  // Contiene funciones como tolower()
#include <string>  // Permite utilizar el tipo string

std::string nombre_animal;

Animal paciente_interno;

std::cin >> nombre_animal;

// Se obtiene el primer carácter del nombre del animal
// y se convierte a minúscula antes de usarlo en el switch.
switch (std::tolower(nombre_animal[0])) {

    case 'r':
        // Si comienza con 'r', se asigna el enumerador roedor.
        paciente_interno = roedor;
        break;

    case 'g':
        // Si comienza con 'g', se asigna el enumerador gato.
        paciente_interno = gato;
        break;

    case 'p':
        // Si comienza con 'p', se asigna el enumerador perro.
        paciente_interno = perro;
        break;

    case 'l':
        // Si comienza con 'l', se asigna el enumerador loro.
        paciente_interno = loro;
        break;

    case 't':
        // Si comienza con 't', se asigna el enumerador tortuga.
        paciente_interno = tortuga;
        break;

    case 'c':
        // Tanto "caballo" como "cerdo" comienzan con 'c'.
        // Por eso se revisa también el segundo carácter.
        if (std::tolower(nombre_animal[1]) == 'a')
            paciente_interno = caballo;
        else
            paciente_interno = cerdo;

        break;

    default:
        // Si no coincide con ninguno de los casos anteriores,
        // se asigna el enumerador oveja.
        paciente_interno = oveja;
}
```

En este caso, el programa lee un nombre como "perro" o "caballo" y después lo convierte en el valor correspondiente de tipo animal.

De manera similar, si queremos mostrar en pantalla el nombre del animal, no basta con enviar directamente el enumerador a `cout`, ya que lo que nos interesa mostrar es el nombre que representa. Una forma de hacerlo es utilizar un switch:

```c++
switch (paciente_interno) {
    case roedor:
        cout << "Roedor";
        break;

    case gato:
        cout << "Gato";
        break;

    case perro:
        cout << "Perro";
        break;

    case loro:
        cout << "Loro";
        break;

    case tortuga:
        cout << "Tortuga";
        break;

    case caballo:
        cout << "Caballo";
        break;

    case cerdo:
        cout << "Cerdo";
        break;

    case oveja:
        cout << "Oveja";
        break;
}
```
Podrías preguntarte por qué no utilizar simplemente números o abreviaturas para representar a cada animal. Una de las principales ventajas de las enumeraciones es que hacen que el código sea más fácil de leer. Es mucho más claro trabajar con `paciente_interno = perro` que con algo como `paciente_interno = 2`. De esta manera, las enumeraciones ayudan a que el programa sea más fácil de entender por sí mismo.


### Devolución de un Valor de Función 

Hasta ahora hemos visto funciones que reciben y devuelven valores de tipos de datos básicos como `int`, `float` o `char`. Sin embargo, una función también puede devolver valores de tipos definidos por el usuario, como una enumeración.

Por ejemplo, en la sección anterior utilizamos un `switch` para convertir una cadena con el nombre de un animal en un valor de tipo `Animal`. Esta tarea puede realizarse dentro de una función:

```c++
Animal convertir_animal(string nombre_animal) {
    // Revisamos la primera letra del nombre
    switch (tolower(nombre_animal[0])) {

        case 'r':
            // "roedor" y "reptil" comienzan con la misma letra
            if (tolower(nombre_animal[1]) == 'o')
                return roedor;
            else
                return reptil;

        case 'g':
            return gato;

        case 'p':
            return perro;

        case 'l':
            return loro;

        case 't':
            return tortuga;

        case 'c':
            // "caballo" y "cerdo" también necesitan
            // revisar una segunda letra
            if (tolower(nombre_animal[1]) == 'a')
                return caballo;
            else
                return cerdo;

        default:
            // Si no coincide con los casos anteriores,
            // se considera que es una oveja
            return oveja;
    }
}
```

Lo importante en este ejemplo es que el tipo de retorno de la función es `Animal`. Por lo tanto, cada sentencia `return` devuelve uno de los valores definidos en esa enumeración.

También podemos observar que no es necesario utilizar `break` después de cada `case`. Esto se debe a que `return` termina la función inmediatamente. Una vez que se ejecuta, el programa sale de la función y no continúa con los siguientes casos del `switch`.

Podemos utilizar la función desde `main()` de la misma manera que cualquier otra función que devuelve un valor:

```c++
int main() {
    Animal paciente_interno;   // Variable para guardar el tipo de animal
    Animal paciente_externo;
    string nombre_animal;       // Cadena que escribirá el usuario

    cin >> nombre_animal;
    // Convertimos el nombre escrito en un valor de tipo Animal
    paciente_interno = convertir_animal(nombre_animal);

    cin >> nombre_animal;
    // Volvemos a utilizar la misma función para otro paciente
    paciente_externo = convertir_animal(nombre_animal);
}
```

De esta forma, podemos reutilizar `convertir_animal()` cada vez que necesitemos transformar el nombre escrito por el usuario en un valor de tipo `Animal`, sin tener que repetir el mismo `switch` en distintas partes del programa.
