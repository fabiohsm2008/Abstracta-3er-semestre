#ifndef RSA_H
#define RSA_H
#include "Funciones.h"
#include <string>
#include <iostream>

using namespace std;

class RSA
{
private:
    string alfabeto = ".-_: abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789";
    int p;
    int q;
    int N;
    int pub;
    int priv;
public:
    RSA();
    RSA(int a,int b);
    void imprimir_claves();
    vector<int> cifrar(string mensaje);
    string descifrar(vector<int> mensaje);
};

#endif // RSA_H
