#include <iostream> 

int main() {

    int num; // Variable donde se almacenará el número que introduzca el usuario

    bool es_primo = true; // Variable booleana que indica si el número es primo (se asume que sí al inicio)

    // Se pide al usuario que introduzca un número
    std::cout << "Introduce un número positivo: ";
    std::cin >> num; // Se guarda el número introducido en la variable num

    // Bucle que prueba si el número tiene divisores distintos de 1 y de sí mismo
    for (int i = 2; i <= num / 2; i++) {

        // Si el residuo de num dividido entre i es 0, entonces i es divisor de num
        if (num % i == 0) {
            es_primo = false; // El número no es primo
            break; // Se detiene el bucle porque ya encontramos un divisor
        }

    }

    // Los números menores o iguales a 1 no son primos
    if (num <= 1) {
        es_primo = false;
    }

    // Se imprime el resultado dependiendo del valor de es_primo
    if (es_primo) {
        std::cout << "El numero es primo\n";
    } else {
        std::cout << "El numero no es primo\n";
    }

    return 0; // Indica que el programa terminó correctamente
}