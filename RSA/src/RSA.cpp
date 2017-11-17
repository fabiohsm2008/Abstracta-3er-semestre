#include "RSA.h"
#include <time.h>
#include <stdlib.h>

RSA::RSA()
{
    p = rand()%100;
    while(!primo(p)){
        p = rand()%100;
    }
    q = rand()%100;
    while(!primo(q)){
        q = rand()%100;
    }
    N = p*q;
    pub = rand()%10000;
    int phi = (p-1)*(q-1);
    while(euclides(pub,phi) != 1 && phi < pub){
        pub = rand()%10000;
    }
    priv = inversa(pub,phi);
}

RSA::RSA(int p1, int q1){
    p = p1;
    q = q1;
    N = p*q;
    pub = rand()%10000;
    int phi = (p-1)*(q-1);
    while(euclides(pub,phi) != 1 && phi < pub){
        pub = rand()%10000;
    }
    priv = inversa(pub,phi);
}

void RSA::imprimir_claves(){
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "N: " << N << endl;
    cout << "Publica: " << pub << endl;
    cout << "Privada: " << priv << endl;
}

vector<int> RSA::cifrar(string mensaje){
    vector<int> rpta;
    for(int i = 0; i < mensaje.size(); i++){
        rpta.push_back(alfabeto.find(mensaje[i]));
    }
    for(int i = 0; i < rpta.size(); i++){
        rpta[i] = potencia_i(rpta[i],pub,N);
    }
    return rpta;
}

string RSA::descifrar(vector<int>mensaje){
    string rpta;
    for(int i = 0; i < mensaje.size(); i++){
        rpta+= alfabeto[potencia_i(mensaje[i],priv,N)];
    }
    return rpta;
}
