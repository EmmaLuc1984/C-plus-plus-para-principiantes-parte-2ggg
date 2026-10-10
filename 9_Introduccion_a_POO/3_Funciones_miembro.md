


























































En el capítulo anterior presentamos el tipo de dato definido por el usuario  `struct`, que permite agrupar variables miembro. A continuación, se muestra un ejemplo de una `struct `utilizado para almacenar una fecha:

```cpp
struct Fecha
{
    int anio {};
    int mes {};
    int dia {};
};
```

Ahora bien, si queremos imprimir la fecha en pantalla (algo que probablemente necesitemos hacer con frecuencia), resulta conveniente escribir una función que se encargue de ello. A continuación, se muestra un programa completo implementando este hecho:

```cpp

#include <iostream>

struct Fecha
{
    // Estas son las variables miembro del registro.
    int anio {};
    int mes {};
    int dia {};
};

void imprimir(const Fecha& fecha)
{
    // Se accede a las variables miembro mediante
    // el operador de selección de miembros (.).
    std::cout << fecha.anio << '/' << fecha.mes << '/' << fecha.dia;
}

int main()
{
    Fecha hoy { 2020, 10, 14 }; // Inicializamos el registro con sus valores.

    hoy.dia = 16;  // Accedemos a una variable miembro mediante el operador (.).
    imprimir(hoy); // Llamamos a una función externa al registro mediante la
                   // sintaxis habitual de llamada a funciones.

    return 0;
}
```

Este programa imprime el siguiente resultado:

```cpp
2020/10/16
```
## Propiedades Y Acciones

Observa lo que hay a tu alrededor: libros, edificios, alimentos e incluso tú mismo. Todos estos son ejemplos de objetos. En el mundo real, los objetos tienen dos componentes principales: **un conjunto de propiedades observables**, como el peso, el color, el tamaño, la dureza o la forma, y **un conjunto de acciones que pueden realizar o que pueden realizarse sobre ellos**, como abrirlos o utilizarlos para modificar otro objeto. Ambos componentes están estrechamente relacionados, pues las acciones que puede realizar un objeto dependen, en cierta medida, de sus propiedades.

En programación, las propiedades se representan mediante variables, mientras que las acciones se implementan mediante funciones.

En el ejemplo anterior de `Fecha`, definimos sus propiedades (las variables miembro del registro) y las acciones que podemos realizar con ellas (como la función `imprimir()`) de manera independiente. Por lo tanto, la relación entre el tipo `Fecha` y la función `imprimir()` no está establecida explícitamente, sino que debemos deducirla a partir del parámetro `const Fecha&` que recibe la función.

Una posible solución sería colocar tanto `Fecha` como `imprimir()` dentro de un espacio de nombres (`namespace`) para indicar que ambos elementos están relacionados y pertenecen a un mismo conjunto. Sin embargo, esto también introduciría más nombres en el programa y obligaría a utilizar prefijos adicionales al acceder a ellos, lo que podría hacer que el código resultara más recargado.

Sería conveniente disponer de una forma de agrupar las propiedades y las acciones relacionadas con un objeto en una sola unidad, de modo que pudieran definirse y utilizarse como un conjunto.

# Funciones Miembro  