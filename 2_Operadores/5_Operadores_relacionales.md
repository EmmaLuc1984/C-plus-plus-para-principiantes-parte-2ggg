# Operadores Relacionales

Ya hemos trabajado con operadores aritméticos, pero estos no son los únicos que podemos usar en C++, pues tambien tenemos los **operadores relacionales**. Los operadores relacionales (tambien denominados operadores de comparación), a diferencia de los operadores aritméticos, no se utilizan para realizar cálculos, sino para comparar dos valores y determinar si una condición se cumple o no. El resultado de esta comparación siempre será un valor lógico: `true` o `false`. 

Los operadores relacionales son los siguientes:  
- `<` Menor  
- `>` Mayor
- `<=` Menor o igual  
-  `>=` Mayor o igual
-  `==` Igual
-  `!=` Distinto 
  
Como puedes intuir, todos ellos son operadores binarios. 

Ahora bien, para poder hacer uso de estos operadores, normalmente los combinamos con estructuras de control (tema que abordaremos con mayor profundidad más adelante), como `if`, `while` o `switch` que nos permiten ejecutar ciertas instrucciones solo cuando una condición se cumple.  Por ejemplo, la estructura `if` funciona de la siguiente manera: 



```c++ 

if (condicion) // Se evalúa una cierta condición 

{ 
    // Si la condición evaluada es verdadera, se ejecutan el resto de instrucciones
}

```


Así, si tenemos: 


```c++

#include <iostream>

int main() {

    int i{10};
    int j{12};

    if (i < j) {
        std::cout << "i es menor que j" << std::endl; //fkdfmo
    }

    return 0; 

}
 ```

 Al ejecutar este código, podrás observar que, como `i` vale 10 y `j` vale 12, la condición `i < j `es verdadera; por lo tanto, se imprimirá en pantalla el mensaje: "i es menor que j".

Los siguientes tambien son ejemplos de como usar operadores relacionales: 

```c++

#include <iostream>

int main() {

    // Mayor que (>)
    int a{15};
    int b{8};

    if (a > b) {
        std::cout << "a es mayor que b" << std::endl;
    }

    // Menor o igual que (<=)
    int m{7};
    int n{7};

    if (m <= n) {
        std::cout << "m es menor o igual que n" << std::endl;
    }

    // Mayor o igual que (>=)
    float x{1.25f};
    float y{2.0f};

    if (x >= y) {
        std::cout << "x es mayor o igual que y" << std::endl;
    }

    // Igual que (==)
    int p{6};
    int q{6};

    if (p == q) {
        std::cout << "p es igual a q" << std::endl;
    }

    // Distinto de (!=)
    float u{4.5f};
    float v{2.0f};

    if (u != v) {
        std::cout << "u es distinto de v" << std::endl;
    }

    return 0;
}
```
