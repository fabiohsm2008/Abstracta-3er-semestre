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

int mult_mod(int a, int b, int c){
    cout << "(" << a << " mod " << c << " * " << b << " mod " << c << ")" << " mod " << c << endl;
    cout << "(" << modulo(a,c) << " * " << modulo(b,c) << ")" << " mod " << c << endl;
    cout << modulo(a,c) * modulo(b,c) << " mod " << c << endl;
    cout << modulo(modulo(a,c) * modulo(b,c),c) << " mod " << c << endl;
    return modulo(modulo(a,c) * modulo(b,c),c);
}

int multipli(int a, int b, int c){
    return modulo(modulo(a,c) * modulo(b,c),c);
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

int inversa(int a, int m)
{
    int x = euclides_extendido(a,m)[1];
    int i;
    for(i = 1; i <= x; i++){
        cout << a << " * " << i << " = " << multipli(a,i,m) << " mod " << m << endl;
    }
    if(x<0){
        x = modulo(x,m);
        for(i = 1; i <= x; i++){
        cout << a << " * " << i << " = " << multipli(a,i,m) << " mod " << m << endl;
        }
        return x;
    }
    return x;
}

int potencia_i(int a, int b, int modu)
{
    int result = 1;
    while(b != 0){

        if(b&1){
            result = multipli(result , a,modu);
        }
        a = multipli(a, a, modu);
        b = b/2;
    }
    return result;
}

int main(){

    int x, y, z;
    bool estado = true;
    while(estado){
        int a;
        cout << "Ingrese el valor siguiente:" << endl;
        cout << "1. Multiplicacion:" << endl;
        cout << "2. Inversa:" << endl;
        cout << "3. Potencia:" << endl;
        cout << "0. Salir:" << endl;
        cin >> a;
        switch(a){
        case 1:

            cout << "Ingrese el valor de a: ";
            cin >> x;
            cout << "Ingrese el valor de b: ";
            cin >> y;
            cout << "Ingrese el valor de c: ";
            cin >> z;
            cout << "El valor de la multiplicacion modular de " << x << " * " << y << " modulo (" << z << ") = " << mult_mod(x,y,z) << endl;
            cout << endl;
            break;
        case 2:
            cout << "Ingrese el valor de a: ";
            cin >> x;
            cout << "Ingrese el valor de c: ";
            cin >> y;
            cout << "El inverso modular de " << x << " modulo " << y << " = " << inversa(x,y) << endl;
            cout << endl;
            break;
        case 3:
            cout << "Ingrese el valor de a: ";
            cin >> x;
            cout << "Ingrese el valor de b: ";
            cin >> y;
            cout << "Ingrese el valor de c: ";
            cin >> z;
            cout << "El valor de la potencia modular de " << x << " elevado a " << y << " modulo (" << z << ") = " << potencia_i(x,y,z) << endl;
            cout << endl;
            break;
        case 0:
            estado = false;
            break;
        }
    }
    return 0;
}
