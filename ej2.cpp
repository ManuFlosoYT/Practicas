#include <iostream>

using namespace std;

int main ()
{
	int cantidad, resto, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco;
	
	cout << "Introduce cantidad de dinero: ";
	cin >> cantidad;
	
	quinientos = cantidad / 500;
	resto = cantidad % 500;
	
	doscientos = resto / 200;
	resto = resto % 200;
	
	cien = resto / 100;
	resto = resto % 100;
	
	cincuenta = resto / 50;
	resto = resto % 50;
	
	veinte = resto / 20;
	resto = resto % 20;
	
	diez = resto / 10;
	resto = resto % 10;
	
	cinco = resto / 5;
	resto = resto % 5;
	
	cout << "Billetes de 500: " << quinientos << endl;
	cout << "Billetes de 200: " << doscientos << endl;
	cout << "Billetes de 100: " << cien << endl;
	cout << "Billetes de 50: " << cincuenta << endl;
	cout << "Billetes de 20: " << veinte << endl;
	cout << "Billetes de 10: " << diez << endl;
	cout << "Billetes de 5: " << cinco << endl;
	cout << "Resto: " << resto << endl;
	
	cout << "500*" << quinientos << " +";
	cout << " 200*" << doscientos << " +";
	cout << " 100*" << cien << " +";
	cout << " 50*" << cincuenta << " +";
	cout << " 20*" << veinte << " +";
	cout << " 10*" << diez << " +";
	cout << " 5*" << cinco << " + ";
	cout << resto;
	cout << " = " << cantidad;
	

    return 0;
}
