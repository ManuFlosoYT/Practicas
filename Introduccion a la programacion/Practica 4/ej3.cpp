#include <iostream>

using namespace std;

void divisionEntera(int dividendo, int divisor, int &cociente, int &resto)
{
	cociente = dividendo / divisor;
	resto = dividendo % divisor;
}

int main ()
{
	int cantidad, resto, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco;
	
	cout << "Introduce cantidad de dinero: ";
	cin >> cantidad;
	
	divisionEntera(cantidad, 500, quinientos, resto);
	
	divisionEntera(resto, 200, doscientos, resto);
	
	divisionEntera(resto, 100, cien, resto);
	
	divisionEntera(resto, 50, cincuenta, resto);
	
	divisionEntera(resto, 20, veinte, resto);
	
	divisionEntera(resto, 10, diez, resto);
	
	divisionEntera(resto, 5, cinco, resto);
	
	cout << "Billetes de 500: " << quinientos << endl
		<< "Billetes de 200: " << doscientos << endl
		<< "Billetes de 100: " << cien << endl
		<< "Billetes de 50: " << cincuenta << endl
		<< "Billetes de 20: " << veinte << endl
		<< "Billetes de 10: " << diez << endl
		<< "Billetes de 5: " << cinco << endl
		<< "Resto: " << resto << endl;
	
	cout << "500*" << quinientos << " +"
		<< " 200*" << doscientos << " +"
		<< " 100*" << cien << " +"
		<< " 50*" << cincuenta << " +"
		<< " 20*" << veinte << " +"
		<< " 10*" << diez << " +"
		<< " 5*" << cinco << " + "
		<< resto << " = " << cantidad;
	

    return 0;
}
