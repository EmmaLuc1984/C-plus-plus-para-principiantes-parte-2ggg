## **Uniones**

En C++, una **unión (`union`)** es un tipo de dato que permite almacenar **uno solo de sus miembros a la vez**. A diferencia de una `struct`, en una unión todos sus miembros comparten el mismo espacio de memoria.

La declaración de una unión es muy parecida a la de un registro. La principal diferencia es que se utiliza la palabra clave `union` en lugar de `struct`.

```cpp
union Peso {
    long peso_en_onzas;
    int peso_en_libras;
    float peso_en_toneladas;
};

Peso peso;
```
Al declarar la variable `peso`, no se reserva memoria suficiente para almacenar simultáneamente los tres valores. En su lugar, los tres miembros **comparten el mismo espacio de memoria**, por lo que la variable puede contener solamente uno de ellos en un momento determinado.

Por ejemplo:

```c++
peso.peso_en_toneladas = 4.83f; // Se almacena el peso en toneladas.

// Ahora se utiliza el mismo espacio para almacenar el peso en libras.
peso.peso_en_libras = 35;
```

Después de ejecutar la segunda asignación, el valor `4.83` deja de representar un valor válido para el miembro `peso_en_toneladas`, ya que el mismo espacio de memoria ahora contiene el valor `35` correspondiente a `peso_en_libras`.

Por lo tanto, una unión puede ser útil cuando un programa necesita representar **diferentes tipos de datos, pero nunca necesita utilizarlos al mismo tiempo**. Su propósito principal es **ahorrar memoria**, haciendo que varios miembros compartan la misma ubicación.

Una unión puede parecerse a una `struct`, pero existe una diferencia fundamental:

- En una `struct`, todos sus miembros pueden almacenar valores al mismo tiempo.
- En una `union`, los miembros comparten memoria y solamente uno debe utilizarse a la vez.

Por esta razón, podría decirse que una unión no representa una colección de valores independientes, sino **un único valor que puede tener diferentes formas o tipos**.

Existen otros aspectos más avanzados relacionados con las uniones, especialmente cuando se estudian temas como **administración de memoria**, pero son tópicos mas avanzados que se salen un poco de este curso. Por ahora, basta con entender su idea principal: **varios miembros comparten el mismo espacio de memoria y solamente uno puede representar el valor almacenado en un momento dado**.

