# Paradigmas En Los Lenguajes De Programación
En el primer capitulo de este curso definimos de manera escueta un **objeto** en C++ como «un fragmento de memoria que se puede usar para almacenar valores», un ejemplo de ello es una variable. 

Hasta ahora nuestros programas en C++ han consistido en listas secuenciales de instrucciones para la computadora que definen datos (a través de objetos) y operaciones realizadas sobre esos datos (a través de funciones que contienen sentencias y expresiones).

Todo esto que hemos hecho ha sido bajo el paradigma de la **programación procedimental**. En la programación procedimental, nos centramos en crear "procedimientos" (que en C++ vendrían siendo las funciones) que implementan la lógica de nuestro programa. Pasamos datos a estas funciones, estas realizan operaciones con los datos y, posteriormente, pueden devolver un resultado que será utilizado por quien las invocó.

En la programación procedimental, las funciones y los datos sobre los que operan son entidades separadas. El programador es responsable de combinar las funciones y los datos para producir el resultado deseado. Esto da como resultado código similar a este:

```c++
comer(tu, manzana);
```
Ahora, observa a tu alrededor: por todas partes hay objetos: libros, edificios, comida e incluso tú. Estos objetos tienen dos componentes principales:
 1) Una serie de propiedades asociadas (por ejemplo, peso, color, tamaño, forma, etc.) 
 2) Una serie de comportamientos que pueden exhibir (por ejemplo, abrirse, calentar algo, etc.). Estas propiedades y comportamientos son inseparables.

En programación, las propiedades se representan mediante objetos y los comportamientos mediante funciones. Por lo tanto, la programación procedimental representa la realidad de forma bastante deficiente, ya que separa las propiedades (objetos) de los comportamientos (funciones).

# ¿Que Es La Programación Orientada A Objetos? 

En la programación orientada a objetos (a menudo abreviada como POO), el enfoque se centra en la creación de tipos de datos definidos por el usuario que contienen tanto propiedades como un conjunto de comportamientos bien definidos. El término **objeto** en POO hace referencia a las entidades que podemos crear a partir de estos tipos.

Esto da lugar a un código que se parece más a lo siguiente:

```c++
tu.comer(manzana); 
```
Esto permite identificar con mayor claridad **quién realiza la acción** (`tu`), **qué comportamiento se está invocando** (`comer()`) y **qué objetos participan en dicho comportamiento** (`manzana`).

Como las propiedades y los comportamientos ya no se encuentran separados, **los objetos pueden organizarse de forma más modular**. Esto hace que nuestros programas sean más fáciles de escribir y comprender, además de proporcionar un mayor grado de **reutilización del código**.

Estos objetos también ofrecen una forma más intuitiva de trabajar con nuestros datos, ya que nos permiten definir **cómo interactuamos con los objetos y cómo estos interactúan entre sí**.

En la siguiente lección veremos cómo crear este tipo de objetos.

# Programación Procedimental vs POO

Para notar un poco mas las diferencias entre ambos paradigmas, veamos un par de ejemplos: 

