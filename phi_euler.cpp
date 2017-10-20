#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int modulo(int a, int n)
{
    int q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

int euclides(int a, int b)
{
	int residuo = modulo(a,b);
	while(residuo!=0)
	{
		a = b;
		b = residuo;
		residuo = modulo(a,b);
	}
	return b;
}

struct number{
    int valor;
    int potencia;
    number(){potencia = 0;};
    number(int val){
        valor = val;
        potencia = 0;
    };
};

void traditional_phi(int n){
    int resultado = 0;
    for(int i = 1; i < n; i++){
        if(euclides(i,n) == 1){
            cout << i << " ";
            resultado++;
        }
    }
}

int phi(int numero){
    int temp = numero;
    if (numero < 1){
        cout << "No se puede hallar" << endl;
        return -1;
    }
    int a = 2;
    vector<number> primos;
    number actual;
    if(modulo(numero,a) == 0){
        actual.valor = a;
        actual.potencia++;
        numero = numero/a;
        while(modulo(numero,a) == 0){
            actual.potencia++;
            numero = numero/a;
        }
        primos.push_back(actual);
        actual.potencia = 0;
    }
    a++;
    while(numero != 1){
        if(modulo(numero,a) == 0){
            actual.valor = a;
            actual.potencia++;
            numero = numero/a;
            while(modulo(numero,a) == 0){
                actual.potencia++;
                numero = numero/a;
            }
        primos.push_back(actual);
        actual.potencia = 0;
        }
        a+= 2;
    }
    int resultado = 1;
    for(int i = 0; i < primos.size(); i++){
        cout << "(" << primos[i].valor << "^" << primos[i].potencia << " - " << primos[i].valor << "^" << primos[i].potencia-1 << ")" << " ";
        resultado *= (pow(primos[i].valor,primos[i].potencia) - pow(primos[i].valor,primos[i].potencia-1));
    }
    cout << endl;
    traditional_phi(temp);
    cout << endl;
    cout << "Phi de " << temp << " es:" << resultado;
    return resultado;
}


int main(){
    phi(240);
    return 0;
}
