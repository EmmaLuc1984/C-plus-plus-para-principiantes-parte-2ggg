#include <fstream>   // PASO 1: INCLUIR EL HEADER PARA LOS ARCHIVOS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // PASO 2: DECLARAR LOS FLUJOS DE ENTRADA
    ifstream in_data;     // flujo de entrada
    ofstream out_data;    // flujo de salida

    // Variables
    string juego;
    float precio;
    float descuento;
    float iva = 0.16f;
    float monto_descuento;
    float subtotal;
    float total;

    // PASO 3: ABRIR LOS ARCHIVOS
    in_data.open("juego.txt");
    out_data.open("recibo.txt");

    // Verificar que el archivo de entrada se abrió bien
    if (!in_data)
    {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    // PASO 4: USAR EL NOMBRE DEL FLUJO EN LA LECTURA
    getline(in_data, juego);   // nombre del videojuego
    in_data >> precio;         // precio original
    in_data >> descuento;      // porcentaje de descuento

    // Cálculos
    monto_descuento = precio * (descuento / 100.0f);
    subtotal = precio - monto_descuento;
    total = subtotal + (subtotal * iva);

    // PASO 4: usar el nombre del flujo en la escritura
    out_data << fixed << setprecision(2);
    out_data << "Videojuego: " << juego << endl;
    out_data << "Precio original: $" << precio << endl;
    out_data << "Descuento: " << descuento << "%" << endl;
    out_data << "Subtotal: $" << subtotal << endl;
    out_data << "Total con IVA: $" << total << endl;

    // Cerrar archivos
    in_data.close();
    out_data.close();

    return 0;
}
