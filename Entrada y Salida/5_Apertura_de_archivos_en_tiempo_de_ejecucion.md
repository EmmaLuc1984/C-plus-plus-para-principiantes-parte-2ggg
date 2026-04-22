## Ingreso de Archivos en Tiempo de Ejecución

Hasta ahora, los ejemplos para abrir un archivo de entrada han incluido un código similar a lo siguiente:

```c++
ifstream archivo_de_entrada;
archivo_de_entrada.open("entrada.in")
```
La función `open`, asociada al tipo de dato `ifstream`, necesita un argumento que indique el nombre real del archivo de datos en el disco. Cuando se usa una cadena literal, como en el ejemplo anterior, ese nombre queda definido al compilar el programa. Por eso, el programa sólo sirve para ese archivo específico. Muchas veces conviene que el programa sea más flexible y que el nombre del archivo se decida al momento de ejecutarlo. Una forma común de lograrlo es pedirle al usuario el nombre del archivo, guardar su respuesta en una variable y usar esa variable como argumento de `open`. En teoría, el siguiente código debería funcionar así, pero lamentablemente el compilador no lo permite: 

```c++
ifstream archivo_de_entrada;
string nombre_del_archivo;
cout << "Introduzca el nombre del archivo de entrada: ";
cin >>  nombre_del_archivo;
archivo_de_entrada.open(nombre_del_archivo); 

```

El problema es que `open` no recibe un `string`, sino una *cadena C*. Una cadena C es un tipo de texto más simple, heredado del lenguaje C (lenguaje anterior a C++). Por eso, una cadena literal como `"entrada.in"` sí sirve para `open`, porque ya está en ese formato.

Para que el código funcione con un `string`, hay que convertirlo a cadena C. Para eso, el tipo `string` tiene la función `c_str()`, que permite hacer esa conversión. Esta se emplea de la siguiente manera: 

```c++
nombre_del_archivo.c_str()
```

Esta función devuelve una cadena C equivalente al contenido de la variable `nombre_del_archivo`. La cadena original de `nombre_del_archivo` no se modifica. Su función principal es permitir usar funciones de biblioteca que necesitan cadenas C y no `string`.

Con `c_str()`, se puede escribir la entrada del nombre de archivo en tiempo de ejecución de esta forma:

```c++
ifstream archivo_de_entrada;
string nombre_de_archivo;

cout << "Introduzca el nombre del archivo de entrada: ";
cin >> nombre_de_archivo;

archivo_de_entrada.open(nombre_de_archivo.c_str());
```
