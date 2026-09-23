# Registros (`structs`)


En programación un *registro* es un tipo de dato estructurado y heterogéneo. Esto significa que sus componentes pueden ser de distintos tipos de datos. Cada uno de esos componentes recibe el nombre de *campo*, y a cada campo se le asigna un *nombre de campo*. En C++, este concepto utiliza una terminología propia: un registro se denomina **estructura**, mientras que sus campos reciben el nombre de **miembros de la estructura**. Cada miembro, a su vez, tiene un nombre que permite identificarlo.

En C++, los tipos de datos de registro se declaran, en general, de acuerdo con la siguiente sintaxis:

```c++

struct nombre_del_tipo 
{lista de miembros
     .
     .
     .

}; 
```

donde el nombre del tipo es un identificador que da un nombre al tipo de datos y la lista de miembros se define como: 

```c++
tipo de datos nombre_del_miembro_1; 
tipo de datos nombre_del_miembro_2;
     .
     .
     . 

```

La palabra reservada `struct` es una abreviatura de "estructura". Como en programación el término "estructura" puede referirse a muchas cosas distintas, aquí conviene usar `struct` o bien `registro` para dejar claro de qué se está hablando.

Como podrás haberte dado cuenta, la sintaxis de una lista de miembros se parece mucho a poner varias declaraciones de variables, pero no es lo mismo: una declaración `struct` define un tipo de dato, no una variable en sí. Después, todavía será necesario declarar variables de ese tipo para reservar memoria y poder asociar cada ubicación con los nombres de sus miembros.

Para poder entender como funciona un registro veamos el siguiente ejemplo: Supongamos que queremos utilizar un `struct` para representar la información de un alumno de nuestro curso de **Taller de Herramientas Computacionales**. Para ello, seria bueno que pudiesemos almacenar su **nombre y apellido**, el **promedio general** que tenía antes de cursar la clase, las **calificaciones de las tareas del curso**, las **calificaciones de las prácticas del curso**, el **examen final** y finalmente la **calificación final del curso**. Para ello primero podriamoss declarar una enumeración que permita representar su calificación final mediante las opciones A, B, C, D y F para depués definir alguna estructura (digamos `Registro_alumno`) que contenga todos los datos que se desea almacenar. Un pequeño intento podria ser el siguiente: 

```c++

#include <string> 
using namespace std; 
// Enumeración para representar la calificación final del curso 
enum Tipo_calificacion {A, B, C, D, F}; 
// Estructura que reúne la información de un alumno 
struct Registro_alumno { string nombre; 
string apellido; 
float promedio; 
int calificacion_tareas; // Suponga un rango de 0 a 400 
int calificacion_practicas; // Suponga un rango de 0 a 300 
int examen_final; // Suponga un rango de 0 a 300 
Tipo_calificacion calificacion_curso;
};

// Declaraciones de variables 
Registro_alumno primer_alumno; 
Registro_alumno alumno; 
int calificacion;

```

Observa que la declaración de una `struct` termina con punto y coma. Quizá puede que te resulte confuso, ya que anteriormente habias visto que un bloque de instrucciones encerrado entre llaves no lleva punto y coma después de la llave de cierre. Sin embargo, las llaves de una declaración `struct` no representan un bloque de instrucciones; forman parte de la sintaxis utilizada para definir la estructura. Por esta razón, la declaración completa debe terminar con un punto y coma.

Los identificadores `nombre`, `apellido`, `promedio`, `calificacion_tareas`, `calificacion_practicas`, `examen_final` y `calificacion_curso` son los miembros de la estructura `Registro_alumno`. En conjunto, estos miembros forman la lista de miembros de la estructura.

Cada miembro tiene asociado un tipo de dato. En este ejemplo, `nombre` y `apellido` son de tipo `string`; `promedio` es de tipo `float`; `calificacion_tareas`, `calificacion_practicas` y `examen_final` son de tipo `int`; y `calificacion_curso` es de tipo `Tipo_calificacion`, una enumeración cuyos posibles valores son A, B, C, D y F.

También es importante notar que la declaración de la estructura, por sí sola, no crea espacios de memoria para almacenar los datos de un alumno. `Registro_alumno` funciona como un modelo o patrón que indica qué información tendrá una variable de ese tipo.

Cuando se declaran variables como `primer_alumno` y `alumno` de tipo `Registro_alumno`, entonces sí se reserva el espacio de memoria necesario para almacenar los datos correspondientes a cada alumno.


## Acceso a Componentes individuales

Para acceder a un miembro específico de una variable de tipo `struct`, se escribe primero el **nombre de la variable**, seguido de un punto (`.`) y, finalmente, el **nombre del miembro**. Esta forma de acceder a los datos recibe el nombre de **selector de miembro** y utiliza la llamada **notación de punto**.

La sintaxis general es la siguiente:

```c++
variable_struct.nombre_miembro
```

Por ejemplo, para acceder al promedio de `primer_alumno`, se escribiría:

```c++
primer_alumno.promedio
```

De manera similar, para acceder a la calificación del examen final de `alumno` lo hariamos de la siguiente forma:

```c++
alumno.examen_final
```

El miembro seleccionado se comporta como cualquier otra variable de su tipo. Por lo tanto, puede utilizarse en una asignación, como argumento de una función, dentro de una expresión o en cualquier otro contexto en el que pueda utilizarse una variable de ese tipo.

En nuestro ejemplo, podemos utilizar los selectores de miembro para trabajar con las diferentes calificaciones de un alumno. Por ejemplo, el siguiente fragmento de código puede utilizarse para que ingreses las calificaciones a lo largo del curso, hacer el promedio correspondiente y posteriormente asignar una calificación final: 

```cpp
#include <iostream>
#include <string>
using namespace std;

// Enumeración para representar la calificación final
enum Tipo_calificacion {A, B, C, D, F};

// Estructura que almacena la información de un alumno
struct Registro_alumno
{
    string nombre;
    string apellido;
    float promedio;
    int calificacion_tareas;
    int calificacion_practicas;
    int examen_final;
    Tipo_calificacion calificacion_curso;
};

int main()
{
    // Declaramos una variable de tipo Registro_alumno
    Registro_alumno alumno;

    // Pedimos los datos del alumno
    cout << "Nombre: ";
    cin >> alumno.nombre;

    cout << "Apellido: ";
    cin >> alumno.apellido;

    // Pedimos las calificaciones
    cout << "Calificacion de tareas (0-400): ";
    cin >> alumno.calificacion_tareas;

    cout << "Calificacion de practicas (0-300): ";
    cin >> alumno.calificacion_practicas;

    cout << "Calificacion del examen final (0-300): ";
    cin >> alumno.examen_final;

    // Calculamos el promedio sobre 10
    alumno.promedio =
        (alumno.calificacion_tareas
        + alumno.calificacion_practicas
        + alumno.examen_final) / 100.0f;

    // Determinamos la calificación final
    if (alumno.promedio >= 9)
        alumno.calificacion_curso = A;
    else if (alumno.promedio >= 8)
        alumno.calificacion_curso = B;
    else if (alumno.promedio >= 7)
        alumno.calificacion_curso = C;
    else if (alumno.promedio >= 6)
        alumno.calificacion_curso = D;
    else
        alumno.calificacion_curso = F;

    // Mostramos los datos almacenados
    cout << "\n--- Datos del alumno ---\n";
    cout << "Nombre: "
         << alumno.nombre << " "
         << alumno.apellido << endl;

    cout << "Promedio: "
         << alumno.promedio << endl;

    cout << "Calificacion final: ";

    // Mostramos la letra correspondiente
    switch (alumno.calificacion_curso)
    {
        case A: cout << "A"; break;
        case B: cout << "B"; break;
        case C: cout << "C"; break;
        case D: cout << "D"; break;
        case F: cout << "F"; break;
    }

    cout << endl;

    return 0;
}
```


## Operaciones Sobre `struct`


Además de acceder a los miembros individuales de una variable `struct`, también es posible trabajar con la **estructura completa como una sola unidad**. A estas acciones las podemos llamar **operaciones sobre estructuras** (tambien las puedes encontrar como operaciones de agregación), ya que involucran a la estructura en su conjunto, en lugar de manipular únicamente uno de sus miembros.



### Inicializaciones

Una variable `struct` puede inicializarse proporcionando valores para sus miembros:

```c++
struct Jugador {
    string nombre;
    int ritmo;
    int tiro;
    int pase;
    int regate;
    int defensa;
    int fisico;
};

// Se inicializan todos los miembros de la estructura
Jugador jugador1{"Vinicius Jr", 95, 89, 84, 95, 32, 75};
```

En este caso, la estructura completa `jugador1` queda creada con los valores proporcionados.

### Asignaciones

También es posible asignar una estructura completa a otra del mismo tipo:

```c++
Jugador jugador1{"Vinicius Jr", 95, 89, 84, 95, 32, 75};
Jugador jugador2;

// Se copian todos los miembros de jugador1 en jugador2
jugador2 = jugador1;
```

Después de la asignación, `jugador2` contiene los mismos datos que `jugador1`.

Esto es diferente de modificar un solo miembro:

```c++
// Solo se modifica el ritmo
jugador2.ritmo = 97;
```

### Estructuras Como Argumentos de Funciones

Una estructura completa puede enviarse como argumento a una función:

```cpp
void mostrar_jugador(Jugador jugador) {
    cout << "Nombre: " << jugador.nombre << '\n';
    cout << "Ritmo: " << jugador.ritmo << '\n';
    cout << "Tiro: " << jugador.tiro << '\n';
    cout << "Pase: " << jugador.pase << '\n';
    cout << "Regate: " << jugador.regate << '\n';
    cout << "Defensa: " << jugador.defensa << '\n';
    cout << "Fisico: " << jugador.fisico << '\n';
}

int main() {
    Jugador jugador{"Vinicius Jr", 95, 89, 84, 95, 32, 75};

    // Se envía toda la estructura a la función
    mostrar_jugador(jugador);
}
```

Aquí la función recibe una variable de tipo `Jugador` completa y puede acceder a todos sus miembros.

### Devolver Una Estructura Desde Una Función

Una función también puede devolver una estructura completa:

```c++
Jugador crear_jugador() {
    // Se devuelve una estructura completa
    return {"Vinicius Jr", 95, 89, 84, 95, 32, 75};
}

int main() {
    // Se recibe la estructura devuelta por la función
    Jugador jugador = crear_jugador();
}
```

### Entrada y Salida

Una estructura no puede utilizarse directamente con `cin` o `cout`, ya que estos operadores no saben automáticamente cómo leer o mostrar todos los miembros de una estructura.

Por ejemplo, esto no está definido para una `struct` ordinaria:

```c++
Jugador jugador;

// Error: cin no sabe cómo leer un objeto Jugador completo
cin >> jugador;
```

Tampoco es posible hacer directamente:

```c++
// Error: cout no sabe cómo mostrar un Jugador completo
cout << jugador;
```

En estos casos, es necesario trabajar con sus miembros:

```c++
Jugador jugador;

// Se introducen los datos de cada miembro
cin >> jugador.nombre;
cin >> jugador.ritmo;
cin >> jugador.tiro;

// Se muestran los datos de cada miembro
cout << jugador.nombre << '\n';
cout << jugador.ritmo << '\n';
cout << jugador.tiro << '\n';
```

Más adelante es posible definir funciones u operadores para darle a la estructura un comportamiento personalizado con `cin` y `cout`.

### Comparaciones

Tampoco existe, para una `struct` ordinaria, una regla automática que indique qué significa comparar dos estructuras completas.

Por ejemplo:

```c++
Jugador jugador1{"Vinicius Jr", 95, 89, 84, 95, 32, 75};
Jugador jugador2{"Vinicius Jr", 95, 89, 84, 95, 32, 75};

// No existe una comparación automática entre estructuras
if (jugador1 == jugador2) {
    cout << "Son iguales.\n";
}
```

Para realizar la comparación, normalmente debemos indicar **qué miembros queremos comparar**:

```c++
// Se comparan los miembros que nos interesan
if (jugador1.nombre == jugador2.nombre &&
    jugador1.ritmo == jugador2.ritmo &&
    jugador1.tiro == jugador2.tiro &&
    jugador1.pase == jugador2.pase &&
    jugador1.regate == jugador2.regate &&
    jugador1.defensa == jugador2.defensa &&
    jugador1.fisico == jugador2.fisico) {

    cout << "Los jugadores son iguales.\n";
}
```

De esta manera, la comparación se realiza sobre los miembros que forman parte de la estructura.

También podemos comparar únicamente algunos de sus miembros:

```c++
// Se compara únicamente el ritmo
if (jugador1.ritmo > jugador2.ritmo) {
    cout << jugador1.nombre << " tiene mayor ritmo.\n";
}
```

### Operadores Aritméticos

Los operadores aritméticos tampoco tienen un significado para una `struct`. No tiene sentido para C++ sumar, restar o multiplicar dos estructuras.

Por ejemplo:

```c++
Jugador jugador1{"Vinicius Jr", 95, 89, 84, 95, 32, 75};
Jugador jugador2{"Otro jugador", 90, 85, 80, 88, 40, 78};

// Error: no existe una suma definida entre estructuras
Jugador jugador3 = jugador1 + jugador2;
```

Para realizar una operación aritmética debemos trabajar con miembros individuales:

```c++
// Se suman únicamente los valores de ritmo
int suma_ritmo = jugador1.ritmo + jugador2.ritmo;

cout << "Suma de ritmo: " << suma_ritmo << '\n';
```

También podríamos calcular el promedio de un atributo:

```c++
// Se calcula el promedio de pase
double promedio_pase =
    (jugador1.pase + jugador2.pase) / 2.0;

cout << "Promedio de pase: " << promedio_pase << '\n';
```

### Estructuras De Control

Una estructura tampoco puede utilizarse directamente como una condición de `if`, `while` o `for` simplemente por ser una estructura:

```c++
Jugador jugador{"Vinicius Jr", 95, 89, 84, 95, 32, 75};

// Error: un Jugador no es automáticamente una condición booleana
if (jugador) {
    cout << "Jugador válido.\n";
}
```

En su lugar, podemos utilizar alguno de sus miembros:

```c++
// Se utiliza el ritmo como condición
if (jugador.ritmo >= 90) {
    cout << "El jugador tiene buen ritmo.\n";
}
```

También podemos combinar varios miembros:

```c++
if (jugador.ritmo >= 90 && jugador.regate >= 90) {
    cout << "El jugador destaca en ritmo y regate.\n";
}
```

## Registros Jerárquicos

Hasta ahora se han visto ejemplos en los que los miembros de una `struct` son variables de tipos `int`, `float` o `string`. Sin embargo, **un miembro de una estructura también puede ser otra estructura**. Cuando una estructura contiene como miembros otras estructuras, hablamos de una **estructura jerárquica**.

Consideremos un ejemplo. Un pequeño almacén de máquinas necesita almacenar información sobre cada una de ellas. Por un lado, se tienen **datos descriptivos**, como el número de identificación, una descripción, la fecha de compra y el costo. Por otro lado, también se conservan **datos estadísticos**, como el índice de fallas, el número de días que la máquina ha estado fuera de servicio y la fecha de su último mantenimiento.

Una primera forma de almacenar toda esta información sería colocarla directamente dentro de una sola estructura:

```cpp
struct Registro_maquina {

    int numero_id;

    string descripcion;

    float indice_fallas;

    int ultimo_servicio_mes;   // 1..12
    int ultimo_servicio_dia;   // 1..31
    int ultimo_servicio_anio;  // 1900..2050

    int dias_fuera_servicio;

    int fecha_compra_mes;      // 1..12
    int fecha_compra_dia;      // 1..31
    int fecha_compra_anio;     // 1900..2050

    float costo;
};
```

El tipo `Registro_maquina` tiene **11 miembros**. Aunque toda la información está presente, la cantidad de datos hace que resulte más difícil identificar con claridad cómo están organizados.

Podemos mejorar esta organización agrupando los datos relacionados. En este caso, hay dos fechas que necesitamos almacenar: la **fecha de compra** y la **fecha del último servicio**. Además, algunos datos corresponden al historial estadístico de la máquina.

Esto sugiere crear una estructura para representar una fecha, otra para representar la información estadística y, finalmente, una estructura general que contenga estas estructuras como miembros.

```cpp
struct Fecha {

    int mes;   // 1..12
    int dia;   // 1..31
    int anio;  // 1900..2050
};

struct Estadisticas {

    float indice_fallas;

    Fecha ultimo_servicio;

    int dias_fuera_servicio;
};

struct Registro_maquina {

    int numero_id;

    string descripcion;

    Estadisticas historial;

    Fecha fecha_compra;

    float costo;
};

Registro_maquina maquina;
```

Ahora la información está organizada de una manera más clara. La estructura `Registro_maquina` contiene dos miembros que también son estructuras: `fecha_compra`, que es de tipo `Fecha`, e `historial`, que es de tipo `Estadisticas`. A su vez, `Estadisticas` contiene otro miembro de tipo `Fecha`, llamado `ultimo_servicio`.

De esta manera se forma una **estructura jerárquica**, ya que unas estructuras se encuentran contenidas dentro de otras.

### Acceso A Miembros De Estructuras Jerárquicas

Para acceder a un miembro que se encuentra dentro de una estructura jerárquica, se escriben los nombres de los miembros **de izquierda a derecha**, utilizando el operador `.` y comenzando con el nombre de la variable de la estructura.

Por ejemplo:

```cpp
maquina.fecha_compra
```

permite acceder al miembro `fecha_compra`, que es una variable de tipo `Fecha`.

Para acceder a `mes` dentro de `fecha_compra`, escribimos:

```cpp
maquina.fecha_compra.mes
```

Aquí primero se accede a `fecha_compra` y después a su miembro `mes`.

De la misma manera:

```cpp
maquina.fecha_compra.anio
```

permite acceder al miembro `anio` de la estructura `Fecha` almacenada en `fecha_compra`.

También podemos acceder a un miembro que se encuentra a varios niveles de profundidad:

```cpp
maquina.historial.ultimo_servicio.anio
```

En este caso, se accede primero a `historial`, después a `ultimo_servicio` y finalmente a `anio`.

Por lo tanto, los selectores de miembros se van **encadenando mediante el operador `.`**, siguiendo la estructura jerárquica desde la variable principal hasta el miembro al que se desea acceder.
