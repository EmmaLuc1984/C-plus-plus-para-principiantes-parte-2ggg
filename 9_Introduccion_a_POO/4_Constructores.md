La clase `Tiempo` que se ha estudiado hasta ahora presenta una limitación: depende de que el código cliente invoque la función `establecer` antes de utilizar cualquiera de las demás funciones miembro. Por ejemplo, la función `incrementar` tiene la siguiente precondición:

```cpp
// Precondición:
// La función establecer ha sido invocada al menos una vez.
```

Si el cliente utiliza `incrementar` sin haber llamado previamente a `establecer`, la precondición no se cumple y se incumple el contrato establecido entre la clase y quien la utiliza. Debido a que las clases suelen encapsular sus propios datos, el programador que las diseña no debería depender del usuario para inicializarlos. Si este olvida hacerlo, el objeto podría contener valores no inicializados y producir resultados inesperados.

Para solucionar este problema, C++ proporciona un mecanismo llamado **constructor de clase**, cuya función es inicializar los objetos cuando se crean. Un constructor es una función miembro especial que se ejecuta automáticamente durante la creación de un objeto de la clase.

Una característica particular de los constructores es que su nombre debe coincidir con el de la clase a la que pertenecen. Para mejorar la clase `Tiempo`, podemos incorporar dos constructores a su declaración:

```cpp
class Tiempo
{
public:
    void establecer(int, int, int);
    void incrementar();
    void escribir() const;
    bool es_igual(Tiempo) const;
    bool es_menor_que(Tiempo) const;

    Tiempo(int, int, int);  // Constructor con tres parámetros.
    Tiempo();               // Constructor por omisión.

private:
    int horas;
    int minutos;
    int segundos;
};
```

En esta declaración se incluyen dos constructores que se distinguen por sus listas de parámetros. El primero recibe tres valores de tipo `int`, que pueden utilizarse para inicializar los miembros de datos privados `horas`, `minutos` y `segundos` al crear un objeto. El segundo no recibe parámetros y permite asignar al objeto un tiempo inicial predeterminado, por ejemplo, `00:00:00`. En C++, un constructor que puede invocarse sin argumentos se conoce como **constructor por omisión**.

Las declaraciones de los constructores tienen dos particularidades que las diferencian de las funciones miembro convencionales. En primer lugar, el nombre de cada constructor es exactamente el mismo que el de su clase; en este caso, `Tiempo`. En segundo lugar, no se especifica ningún tipo de retorno, ni siquiera `void`.

Esto se debe a que un constructor no devuelve un valor como resultado de una función. Su finalidad es inicializar el objeto durante su creación, estableciendo los valores iniciales de sus miembros de datos.

En el archivo de implementación de la clase `Tiempo`, es necesario definir los dos constructores que se declararon previamente. Estas definiciones establecen los valores iniciales de los miembros de datos privados cuando se crea un objeto.

```cpp
//******************************************************************
// Constructor con tres parámetros.
//******************************************************************

Tiempo::Tiempo(/* entrada */ int horas_iniciales,
               /* entrada */ int minutos_iniciales,
               /* entrada */ int segundos_iniciales)

// Precondición:
// 0 <= horas_iniciales <= 23
// 0 <= minutos_iniciales <= 59
// 0 <= segundos_iniciales <= 59
//
// Poscondición:
// horas == horas_iniciales
// minutos == minutos_iniciales
// segundos == segundos_iniciales

{
    horas = horas_iniciales;
    minutos = minutos_iniciales;
    segundos = segundos_iniciales;
}

//******************************************************************
// Constructor por omisión.
//******************************************************************

Tiempo::Tiempo()

// Poscondición:
// horas == 0
// minutos == 0
// segundos == 0

{
    horas = 0;
    minutos = 0;
    segundos = 0;
}
```

## Invocación De Un Constructor

Aunque los constructores son miembros de una clase, no se invocan mediante el operador punto (`.`), como sucede con las funciones miembro convencionales. En su lugar, se ejecutan automáticamente cuando se crea un objeto de la clase.

Por ejemplo, la siguiente declaración incluye tres argumentos después del nombre del objeto:

```cpp
Tiempo hora_clase(10, 30, 0);
```

Cuando se ejecuta esta declaración, se invoca automáticamente el constructor de `Tiempo` que recibe tres parámetros. Los valores proporcionados se utilizan para inicializar los miembros de datos privados del objeto `hora_clase`, que queda representando las 10:30:00.

En cambio, la siguiente declaración no proporciona argumentos:

```cpp
Tiempo hora_inicio;
```

En este caso, se utiliza automáticamente el constructor por omisión, que establece los miembros de datos del objeto `hora_inicio` en cero. Por consiguiente, el objeto comienza representando las 00:00:00.

Es importante recordar que las declaraciones de variables en C++ pueden aparecer entre las instrucciones ejecutables de una función. Esto resulta útil cuando los valores necesarios para crear un objeto solo se conocen durante la ejecución del programa.

Consideremos el siguiente ejemplo:

```cpp
int horas_entrada;
int minutos_entrada;
int segundos_entrada;

cout << "Introduzca la hora de la cita en horas, minutos y segundos: ";
cin >> horas_entrada >> minutos_entrada >> segundos_entrada;

Tiempo hora_cita(horas_entrada, minutos_entrada, segundos_entrada);

cout << "La hora de la cita es ";
hora_cita.escribir();
```

En este fragmento, primero se solicitan al usuario las horas, los minutos y los segundos. Posteriormente, estos valores se utilizan como argumentos para crear el objeto `hora_cita`. De este modo, el constructor establece el tiempo inicial desde el momento en que se crea el objeto, sin necesidad de invocar por separado la función `establecer`.

## Especificación Revisada De La Clase `Tiempo`

La incorporación de constructores permite garantizar que los objetos de la clase `Tiempo` reciban valores iniciales al crearse. El constructor con tres parámetros permite que el cliente determine el tiempo inicial, mientras que el constructor por omisión establece el valor `00:00:00` cuando no se proporcionan argumentos.

Por lo tanto, una vez que se crea un objeto mediante alguno de estos constructores, sus miembros de datos quedan inicializados. Esto elimina la necesidad de exigir al cliente que invoque previamente la función `establecer` antes de utilizar las demás funciones miembro.

En consecuencia, se pueden retirar de la especificación las advertencias que exigían llamar a `establecer` antes de ejecutar otras operaciones, así como las precondiciones que dependían exclusivamente de esa llamada previa. Sin embargo, siguen siendo necesarias las condiciones que establecen restricciones sobre los valores de entrada o el uso de determinadas operaciones.

La declaración actualizada de la clase `Tiempo` puede escribirse de la siguiente manera:

```cpp
//******************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Tiempo.h)
//
// Este archivo contiene la especificación del tipo de dato
// abstracto Tiempo.
//******************************************************************

class Tiempo
{
public:
    void establecer(/* entrada */ int horas_entrada,
                    /* entrada */ int minutos_entrada,
                    /* entrada */ int segundos_entrada);

    // Precondición:
    // 0 <= horas_entrada <= 23
    // 0 <= minutos_entrada <= 59
    // 0 <= segundos_entrada <= 59
    //
    // Poscondición:
    // El tiempo queda establecido de acuerdo con los
    // valores recibidos como parámetros.

    void incrementar();

    // Poscondición:
    // El tiempo avanza un segundo. Si llega a 23:59:59,
    // vuelve a comenzar en 00:00:00.

    void escribir() const;

    // Poscondición:
    // El tiempo se muestra con el formato HH:MM:SS.

    bool es_igual(/* entrada */ Tiempo otro_tiempo) const;

    // Poscondición:
    // Devuelve true si ambos objetos representan el mismo
    // tiempo y false en caso contrario.

    bool es_menor_que(/* entrada */ Tiempo otro_tiempo) const;

    // Precondición:
    // Este objeto y otro_tiempo representan tiempos del mismo día.
    //
    // Poscondición:
    // Devuelve true si este tiempo es anterior a otro_tiempo
    // y false en caso contrario.

    Tiempo(/* entrada */ int horas_iniciales,
           /* entrada */ int minutos_iniciales,
           /* entrada */ int segundos_iniciales);

    // Constructor con tres parámetros.
    //
    // Precondición:
    // 0 <= horas_iniciales <= 23
    // 0 <= minutos_iniciales <= 59
    // 0 <= segundos_iniciales <= 59
    //
    // Poscondición:
    // El objeto se crea con el tiempo indicado
    // por los parámetros recibidos.

    Tiempo();

    // Constructor por omisión.
    //
    // Poscondición:
    // El objeto se crea con el tiempo 00:00:00.

private:
    int horas;
    int minutos;
    int segundos;
};
```

Con esta modificación, la clase `Tiempo` se encarga de establecer el estado inicial de sus objetos durante su creación. De esta manera, la inicialización deja de depender de que el código cliente recuerde invocar una función específica antes de comenzar a utilizar el objeto.

Este mecanismo mejora la confiabilidad de la clase, ya que permite establecer condiciones iniciales desde el principio y reduce la posibilidad de utilizar objetos cuyos datos no hayan sido inicializados correctamente.