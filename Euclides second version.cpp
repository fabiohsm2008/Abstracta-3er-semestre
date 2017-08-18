#include <iostream>
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
		cout << a << " = ";
		a = b;
		cout << "(" << a/b << ")" << b << " + " << residuo << endl;
		b = residuo;
		residuo = modulo(a,b);
	}
	cout << a << " = " << "(" << a/b << ")" << b << " + " << residuo << endl;
	cout << "El maximo comun divisor es: " << b;
	return b;
}

int main(int argc, char *argv[]) {
	int a,b;
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	euclides(a,b);
	return 0;
}

