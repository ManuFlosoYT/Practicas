#include <iostream>

using namespace std;

int main ()
{
	char a, b, c, aux;

	cout << "Introduce las variables a, b y c: ";
	
	cin >> a >> b >> c;
	
	aux = b;
	b = a;
	a = c;
	c = aux;
	
	
	cout << "Los valores de a, b y c desplazados son: ";
	cout << a << " " << b << " " << c;

    return 0;
}
