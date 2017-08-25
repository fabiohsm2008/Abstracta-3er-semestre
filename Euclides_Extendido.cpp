#include <iostream>
#include <vector>

using namespace std;

vector <int> euclides_extendido(int a, int b)
{
    vector <int> resultados;
    vector <int> fila_q;
    vector <int> fila_u;
    vector <int> fila_v;
    vector <int> fila_r;

    int r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    fila_u.push_back(s1);
    fila_v.push_back(t1);
    fila_r.push_back(r1);
    while(r2>0)
    {
        q = r1/r2;
        fila_q.push_back(q);

        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;

        fila_u.push_back(s1);
        fila_v.push_back(t1);
        fila_r.push_back(r1);

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);

    cout << "       ";
    for(int i = 0; i < fila_q.size()-1; i++){
        cout << fila_q[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < fila_u.size(); i++){
        cout << fila_u[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < fila_v.size(); i++){
        cout << fila_v[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < fila_r.size(); i++){
        cout << fila_r[i] << "  ";
    }
    cout << endl;
    cout << endl;

    return resultados;
}

int main(){

    vector<int> respuestas;
    int a,b;
    cout << "Ingrese el primer valor: ";
    cin >> a;
    cout << "Ingrese el segundo valor: ";
    cin >> b;
    respuestas = euclides_extendido(a,b);
    cout << a << " (x) + " << b << " (y) = c" << endl;
    cout << "El valor de c es: " << respuestas[0] << endl;
    cout << "El valor de x es: " << respuestas[1] << endl;
    cout << "El valor de y es: " << respuestas[2] << endl;
    cout << endl;
    cout << a << " (" << respuestas[1] << ") + " << b << " (" << respuestas[2] << ") = " << respuestas[0] << endl;

    return 0;
}
