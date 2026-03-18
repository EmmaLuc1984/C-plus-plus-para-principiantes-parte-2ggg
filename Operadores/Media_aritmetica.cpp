#include <iostream>

int main() {

// Declaramos variables para almacenar las calificaciones de un estudiante
    int calificacion1{85};
    int calificacion2{90};
    int calificacion3{88};

    // Variable para almacenar el promedio, inicializada a 0.0
    float promedio{0.0};

    // Aquí ocurre la coerción: La suma de tres enteros produce un entero, pero al dividir entre 3.0
    // el compilador convierte automáticamente los enteros a tipo double para poder realizar
    // la operación correctamente.
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0;

    // Mostramos el resultado
    std::cout << "El promedio del estudiante es: " << promedio << std::endl;

    return 0;
}