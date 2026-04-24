#include <iostream>  // Permite usar cin y cout
#include <string>    // Permite usar datos de tipo string

using namespace std;

int main() {
    string nombre;          // Variable para guardar el nombre del usuario
    double numero1, numero2; // Variables para guardar los números que el usuario introducirá
    double suma;             // Variable para guardar el resultado de la suma

    // Mensaje para pedir el nombre
    cout << "Hola. ¿Como te llamas? ";
    getline(cin, nombre);    // Lee una línea completa, incluso si hay espacios

    // Pide el primer número
    cout << "Hola, " << nombre << ". Ingresa el primer numero: ";
    cin >> numero1;          // Lee el primer valor numérico

    // Pide el segundo número
    cout << "Ingresa el segundo numero: ";
    cin >> numero2;          // Lee el segundo valor numérico

    // Realiza la suma
    suma = numero1 + numero2;

    // Muestra el resultado final
    cout << nombre << ", la suma de " << numero1 << " y " << numero2
         << " es: " << suma << endl;

    return 0; // Indica que el programa terminó correctamente
}