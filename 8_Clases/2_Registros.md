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

Veamos un ejemplo: 


```c++



```