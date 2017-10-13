#include "afin.h"

afin::afin()
{
    srand(time(NULL));
    clave_a = 1;
    while(euclides(clave_a,alfabeto.length()) != 1){
        clave_a = rand();
    }
    clave_b = rand()%alfabeto.length();
    privada = inverso(clave_a,alfabeto.length());
    cout << "Su clave publica es: " << clave_a << endl;
    cout << "Su clave privada es: " << privada << endl;
    cout << "Su segunda clave es: " << clave_b << endl;
    cout << "La clave de encriptacion es: " << clave_b << endl;
}

afin::afin(int a, int b)
{
    this -> clave_a = a;
    this -> clave_b = b;
    privada = inverso(clave_a,alfabeto.size());
}

string afin::codificar(string cadena)
{
    int i;
    int valores = cadena.size();
    string rpta;
    for(i = 0; i < valores; i++){
        if(cadena[i] == ' ') continue;
        int temp = modulo(clave_a,alfabeto.length());
        temp = temp * alfabeto.find(cadena[i]);
        temp = modulo(temp,alfabeto.length()) + modulo(clave_b,alfabeto.length());
        temp = modulo(temp,alfabeto.length());
        rpta += alfabeto[temp];
    }
    valores = rpta.size();
    string resultado;
    for(int j = 0; j < valores; j++){
        if(modulo(j+1,5) != 0){
            resultado += rpta[j];
        }
        else{
            resultado += rpta[j];
            resultado += " ";
        }
    }
    return resultado;
}

string afin::decodificar(string cadena)
{
    int i;
    int valores = cadena.size();
    string rpta;
    for(i = 0; i < valores; i++){
        if(cadena[i] != ' '){
            int temp = modulo(clave_b,alfabeto.length());
            temp = alfabeto.find(cadena[i]) - temp;
            temp = modulo(privada,alfabeto.length()) * temp;
            temp = modulo(temp,alfabeto.length());
            rpta += alfabeto[temp];
        }
    }
    return rpta;
}
