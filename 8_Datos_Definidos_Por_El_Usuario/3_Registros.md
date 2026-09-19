# Registros (`structs`)


En programación un *registro* es un tipo de dato estructurado y heterogéneo. Esto significa que sus componentes pueden ser de distintos tipos de datos. Cada uno de esos componentes recibe el nombre de *campo*, y a cada campo se le asigna un *nombre de campo*. En C++, esta idea se expresa con otra terminología: un registro se conoce como *estructura*, los campos se llaman *miembros de la estructura* y cada miembro tiene su propio nombre.

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

La palabra reservada `struct` es una abreviatura de “estructura”. Como en programación el término “estructura” puede referirse a muchas cosas distintas, aquí conviene usar `struct` o bien “registro” para dejar claro de qué se está hablando.

También es importante notar que la sintaxis de una lista de miembros se parece mucho a varias declaraciones de variables, pero no es exactamente lo mismo: una declaración de `struct` define un tipo de dato, no una variable en sí. Después, todavía será necesario declarar variables de ese tipo para reservar memoria y poder asociar cada ubicación con los nombres de sus miembros.

Veamos un ejemplo (usando como base al tiznado de Elden Ring): 


```c++
#include <iostream>
#include <string>
using namespace std;

struct Personaje {
    string nombre;
    int vigor;
    int mente;
    int resistencia;
    int fuerza;
    int destreza;
    int inteligencia;
    int fe;
    int arcano;
};

void MostrarPersonaje(Personaje aPersonaje) {
    cout << "\nDatos del personaje:\n";
    cout << "Nombre: " << aPersonaje.nombre << endl;
    cout << "Vigor: " << aPersonaje.vigor << endl;
    cout << "Mente: " << aPersonaje.mente << endl;
    cout << "Resistencia: " << aPersonaje.resistencia << endl;
    cout << "Fuerza: " << aPersonaje.fuerza << endl;
    cout << "Destreza: " << aPersonaje.destreza << endl;
    cout << "Inteligencia: " << aPersonaje.inteligencia << endl;
    cout << "Fe: " << aPersonaje.fe << endl;
    cout << "Arcano: " << aPersonaje.arcano << endl;
}

int main() {
    Personaje tiznado;
    Personaje otro_tiznado;

    cout << "Ingresa el nombre: ";
    getline(cin, tiznado.nombre);

    cout << "Ingresa el vigor: ";
    cin >> tiznado.vigor;

    cout << "Ingresa la mente: ";
    cin >> tiznado.mente;

    cout << "Ingresa la resistencia: ";
    cin >> tiznado.resistencia;

    cout << "Ingresa la fuerza: ";
    cin >> tiznado.fuerza;

    cout << "Ingresa la destreza: ";
    cin >> tiznado.destreza;

    cout << "Ingresa la inteligencia: ";
    cin >> tiznado.inteligencia;

    cout << "Ingresa la fe: ";
    cin >> tiznado.fe;

    cout << "Ingresa el arcano: ";
    cin >> tiznado.arcano;

    otro_tiznado = tiznado;

    cout << "\nLa informacion de tiznado se copio en otro_tiznado.";
    MostrarPersonaje(otro_tiznado);

    return 0;
}
```


Observa que: 

- Tanto en este ejemplo como en la plantilla de sintaxis, una declaración `struct` termina en un punto y coma. Hasta este punto has aprendido que no se debe colocar punto y coma después de la llave derecha en un bloque de sentencias. Sin embargo, la lista de miembros de una declaración `struct` no cuenta como un bloque de sentencias; en este caso, las llaves solo forman parte de la sintaxis obligatoria de la declaración. Por eso, una declaración `struct`, al igual que cualquier otra declaración en C++, debe finalizar con punto y coma.
- `Personaje` es el nombre del tipo de estructura que se definió para representar al Tiznado. Dentro de esa estructura se agrupan varios datos relacionados con un mismo personaje: `nombre`, `vigor`, `mente`, `resistencia`, `fuerza`, `destreza`, `inteligencia`, `fe` y `arcano`. Todos estos nombres forman la lista de miembros de la estructura.
- Cada miembro tiene un tipo de dato asignado. `nombre` es de tipo `string`, porque almacena texto. Los demás miembros son de tipo `int`, ya que representan valores numéricos enteros correspondientes a los atributos del personaje. Al igual que ocurre con las variables normales, los nombres de los miembros dentro de una `struct` deben ser únicos.
- La estructura `Personaje` no guarda datos por sí sola hasta que se declara una variable de ese tipo. En el programa, `tiznado` y `otro_tiznado` son variables de tipo `Personaje`. Estas variables sí ocupan memoria y contienen pueden contener valores concretos. 

## Acceso a Componentes Individuales
Para acceder a un miembro de una variable `struct`, se escribe primero el nombre de la variable, luego un punto y después el nombre del miembro. A esta forma se le llama *selector de miembro*. La plantilla de sintaxis es:

```text 

Variable struct . Nombre de miembro

```

En nuestro ejemplo anterior invocamos a los miembros de `Personaje` con:

```c++
    tiznado.nombre;
    tiznado.vigor;
    tiznado.mente;
    tiznado.resistencia;
    tiznado.fuerza;
    tiznado.destreza;
    tiznado.inteligencia;
    tiznado.fe;
    tiznado.arcano;
```


## Operaciones de Agregación en Registros

Además de acceder a los componentes individuales de una variable `struct`, en ciertos casos también se pueden realizar *operaciones de agregación*. Una operación de agregación es aquella que trata a la estructura como una sola unidad, en lugar de manejar cada parte por separado. En la siguiente tabla se resume qué operaciones de agregación están permitidas en variables `struct`: 


| Operación de agregación                               | ¿Permitida en structs?           |
|------------------------------------------------------|----------------------------------|
| Entrada/Salida (I/O)                                      | No                               |
| Asignación                                           | Sí                               |
| Aritmética                                           | No                               |
| Comparación                                          | No                               |
| Paso de argumentos                                   | Sí, por valor o por referencia   |
| Retorno como un valor de devolución de una función   | Sí                               |



De acuerdo con la tabla, una variable struct se puede asignar a otra. Sin embargo, ambas variables deben ser declaradas como del mismo tipo. En nuestro ejemplo, declaranos dos variables de tipo `Personaje`: `tiznado` y `otro_tiznado`. La sentencia:
```c++
otro_tiznado = tiznado;
```
copia el contenido completo de `tiznado` en `otro_tiznado`, miembro por miembro. Esto significa que todos los datos almacenados en la estructura original pasan a la nueva variable del mismo tipo.

Por otro lado, nuestro programa también muestra que no se puede manejar la `struct` completa como una sola entrada o salida. Instrucciones como: 

```c++
cin >> tiznado; 
```
no estan permitidas. Por eso, cada dato se introduce por separado, por ejemplo: 

```c++
cin >> tiznado.vigor;
cin >> tiznado.mente;
```
Finalmente, nuestro programa demuestra que una `Personaje` puede pasarse como argumento a una función. En este caso, la función:
```c++
void MostrarPersonaje(Personaje aPersonaje)
```
recibe una copia de la estructura por valor. Dentro de la función, los datos del personaje se muestran uno por uno con `cout`, usando la sintaxis conocida para acceder a cada miembro.

## Registros Jerarquicos 

En nuestro ejemplo del Tiznado hemos visto que los componentes de un registro son variables y cadenas de texto simples. Sin embargo, un componente también puede ser a su vez otro registro. Cuando los registros están formados por componentes que son otros registros, se les llama *registros jerárquicos*. 

Veamos un ejemplo en el que este tipo de estructura resulta adecuado, para ello es conveniente ponernos en contexto:  Un pequeño taller de maquinaria conserva información sobre cada una de sus máquinas. Por un lado, guarda datos descriptivos, como el número de identificación, la descripción de la máquina, la fecha de compra y su costo; por otro, mantiene datos estadísticos, como los días de inactividad, el índice de fallas y la fecha del último mantenimiento. ¿Cuál sería una manera lógica de organizar toda esta información? Para empezar, pensemos en una estructura de registro horizontal, es decir, no jerárquica, que incluya todos estos datos.


```c++
struct Maquina{
    int identificador;
    string descripcion;
    float indice_fallas;
    int mes_ultimo_mantenimiento;
    int dia_ultimo_mantenimiento;
    int anio_ultimo_mantenimiento;
    int dias_inactiva;
    int mes_adquisicion;
    int dia_aquisicion;
    int anio_adquisicion;
    float costo_adquisicion;
```
 
`Maquina` cuenta con 11 miembros. Aquí hay tanta información detallada que resulta difícil identificar con claridad qué representa el registro. Conviene entonces reorganizarla en una estructura jerárquica más coherente. Para ello, podemos dividir la información en dos grupos: la que cambia y la que permanece fija. Además, es necesario conservar dos fechas: la de compra y la del último servicio. Estas observaciones sugieren utilizar un registro para describir una fecha, otro para los datos estadísticos y un registro general que incluya a los dos anteriores como componentes. Las siguientes declaraciones reflejan esa organización: 


```c++

struct Fecha
{
 int mes; 
 int dia; 
 int año; 

struct Estadisticas
{
 float indice_fallas;
 Fecha ultimo_mantenimiento;
 int dias_inaciva;
};

struct Maquina
{
 int identificador;
 string descripcion;
 Estadisticas historial;
 Fecha fecha_de_adqusicion;
 float costo_adquisicion;
};

Maquina maquina; 
```

