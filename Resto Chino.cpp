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

int res_chino(int *a, int *b, int tam){
    return 0;
}

void prueba(){
    int i = 0;
    for(int j = 0; j < 256 ; j++){
        cout << i << ": " << char(i) << endl;
        i++;
    }
}

int main(){
    int a, b, c;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;
    cout << "Ingrese c: ";
    cin >> c;
    congruencia(a,b,c);

    return 0;
}
