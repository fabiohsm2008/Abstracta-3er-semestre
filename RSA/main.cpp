#include <iostream>
#include "RSA.h"
#include <locale>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"spanish");
    RSA hola(11,31);
    hola.imprimir_claves();
    vector<int>msg = hola.cifrar("Esto muestra que si funcioña");
    for(int i = 0; i < msg.size(); i++){
        cout << msg[i] << " ";
    }
    cout << endl;
    string rpta = hola.descifrar(msg);
    cout << rpta;
    return 0;
}
