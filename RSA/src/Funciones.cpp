#include "Funciones.h"


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

vector <int> euclides_extendido(int a, int b)
{
    vector <int> resultados;
    int r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}

int inversa(int a, int alfabeto)
{
    int x = euclides_extendido(a,alfabeto)[1];
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}

int multipli(int a, int b, int c){
    return modulo(modulo(a,c) * modulo(b,c),c);
}

int chino(vector<int> valores, vector<int> modulos){
    int resultado = 0;
    int M = 1;
    vector<int> sub_mods;
    vector<int> invers;
    for(int i = 0; i < valores.size(); i++){
        M = M * modulos[i];
    }
    for(int i = 0; i < valores.size(); i++){
        sub_mods.push_back(M/modulos[i]);
        invers.push_back(inversa(M/modulos[i],modulos[i]));
    }
    for(int i = 0; i < valores.size(); i++){
        resultado = modulo(resultado + (modulo(multipli(multipli(valores[i],sub_mods[i],M),invers[i],M),M)),M);
    }
    return resultado;
}

bool primo(int a){
    if(euclides(2,a)!=1) return 0;
    for(int i = 3; i < a; i+=2){
        if(euclides(i,a)!=1) return 0;
    }
    return 1;
}

int potencia_i(int a, int b, int modu)
{
    int result = 1;
    int i = 1;
    int x = a;
    while(b != 0){
        if(b&1){
            result = multipli(result , a,modu);
        }
        a = multipli(a, a, modu);
        b = b/2;
        i = i*2;
    }
    return result;
}


