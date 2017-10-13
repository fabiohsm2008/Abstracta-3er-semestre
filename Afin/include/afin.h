#ifndef AFIN_H
#define AFIN_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Funciones.h"

using namespace std;

class afin
{
private:
    string alfabeto = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    int clave_a;
    int clave_b;
    int privada;
public:
    afin();
    afin(int a, int b);
    string codificar(string cadena);
    string decodificar(string cadena);
};

#endif // AFIN_H
