#include <iostream>
#include <vector>

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

int mult_mod(int a, int b, int c){
    cout << "(" << a << " mod " << c << " * " << b << " mod " << c << ")" << " mod " << c << endl;
    cout << "(" << modulo(a,c) << " * " << modulo(b,c) << ")" << " mod " << c << endl;
    cout << modulo(a,c) * modulo(b,c) << " mod " << c << endl;
    cout << modulo(modulo(a,c) * modulo(b,c),c) << " mod " << c << endl;
    return modulo(modulo(a,c) * modulo(b,c),c);
}

void congruencia(int a, int b, int c){
    cout << "Ecuacion: " << a << "x" << char(240) << b << "mod" << c << endl;
    int w = euclides(a,c);
    int invers = inversa(a,c);
    cout << "MCD(" << a << "," << c << ") = " << w << endl;
    if(modulo(b,w) != 0){
        cout << w << " no divide a " << b << "; no es congruente" << endl;
    }
    else{
        cout << "Inversa de " << a << " = " << invers << endl;
        cout << "Hallando la multiplicacion de la inversa con en valor de la congruencia:" << endl;
        cout << invers << " * " << b << " mod " << c << endl;
        mult_mod(invers,b,c);
        int respuesta = multipli(invers,b,c);
        cout << "El valor de la variable x es: " << respuesta << endl;
        cout << endl;
        cout << endl;
        cout << "Familia de equivalencias positivas: " << respuesta << " " << respuesta + c << " " << respuesta + (c*2) << " " << respuesta + (c*3) << " " << respuesta + (c*4) << endl;
        cout << "Familia de equivalencias negativas: " << respuesta << " " << respuesta - c << " " << respuesta - (c*2) << " " << respuesta - (c*3) << " " << respuesta - (c*4) << endl;
    }
}

int res_chino(vector<int> valores, vector<int> modulos){
    cout << endl;
    int M = 1;
    vector<int> sub_mods;
    for(int i = 0; i < valores.size(); i++){
        cout << "X = " << valores[i] << " mod " << modulos[i] << endl;
        M = M * modulos[i];
    }
    for(int i = 0; i < valores.size(); i++){
        sub_mods.push_back(M/modulos[i]);
    }
    cout << endl;
    for(int i = 0; i < valores.size(); i++){
        cout << sub_mods[i] << endl;
    }
}


int main(){
    /*int a, b, c;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;
    cout << "Ingrese c: ";
    cin >> c;
    congruencia(a,b,c);*/

    vector<int> val;
    vector<int> mods;
    int tam;
    int a;
    int mod;
    cout << "Ingrese la cantidad de congruencias lineales: ";
    cin >> tam;
    for(int i = 0; i < tam; i++){
        cout << "Ingrese la ecuacion " << i+1 << ":";
        cin >> a;
        cin >> mod;
        val.push_back(a);
        mods.push_back(mod);
    }
    res_chino(val,mods);
    return 0;
}
