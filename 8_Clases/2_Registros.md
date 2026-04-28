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

int main() {
    Personaje tiznado;

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

    cout << "\nDatos del personaje:\n";
    cout << "Nombre: " << tiznado.nombre << endl;
    cout << "Vigor: " << tiznado.vigor << endl;
    cout << "Mente: " << tiznado.mente << endl;
    cout << "Resistencia: " << tiznado.resistencia << endl;
    cout << "Fuerza: " << tiznado.fuerza << endl;
    cout << "Destreza: " << tiznado.destreza << endl;
    cout << "Inteligencia: " << tiznado.inteligencia << endl;
    cout << "Fe: " << tiznado.fe << endl;
    cout << "Arcano: " << tiznado.arcano << endl;

    return 0;
}
```
Observa que: 

- Tanto en este ejemplo como en la plantilla de sintaxis, una declaración `struct` termina en un punto y coma. Hasta este punto has aprendido que no se debe colocar punto y coma después de la llave derecha en un bloque de sentencias. Sin embargo, la lista de miembros de una declaración `struct` no cuenta como un bloque de sentencias; en este caso, las llaves solo forman parte de la sintaxis obligatoria de la declaración. Por eso, una declaración `struct`, al igual que cualquier otra declaración en C++, debe finalizar con punto y coma.
- `Personaje` es el nombre del tipo de estructura que se definió para representar al Tiznado. Dentro de esa estructura se agrupan varios datos relacionados con un mismo personaje: `nombre`, `vigor`, `mente`, `resistencia`, `fuerza`, `destreza`, `inteligencia`, `fe` y `arcano`. Todos estos nombres forman la lista de miembros de la estructura.
- Cada miembro tiene un tipo de dato asignado. `nombre` es de tipo `string`, porque almacena texto. Los demás miembros son de tipo `int`, ya que representan valores numéricos enteros correspondientes a los atributos del personaje. Al igual que ocurre con las variables normales, los nombres de los miembros dentro de una `struct` deben ser únicos.
- La estructura `Personaje` no guarda datos por sí sola hasta que se declara una variable de ese tipo. En el programa, `tiznado` es una variable de tipo `Personaje`. Esa variable sí ocupa memoria y contiene valores concretos, como `Mauricio` en `nombre`, 30 en `vigor` y 35 en `fuerza`. Por eso se dice que `Personaje` funciona como un molde, y `tiznado` es una instancia creada a partir de ese molde.

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


