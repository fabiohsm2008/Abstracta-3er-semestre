#include <iostream>
#include <fstream>
#include <locale>
#include "afin.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"spanish");
    ifstream ficheroEntrada;
    ficheroEntrada.open("mensaje.txt");
    string mensaje;
    getline(ficheroEntrada, mensaje);
    ficheroEntrada.close();

    int clave;
    cout << "Ingrese su clave: ";
    cin >> clave;
    afin a(1,clave);
    string encriptado = a.codificar(mensaje);
    cout << endl;
    cout << "Su mensaje ENCRIPTADO es: " << encriptado << endl;
    cout << endl;
    cout << "Su mensaje ORIGINAL es: " << a.decodificar(encriptado) << endl;

    return 0;
}
