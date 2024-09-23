#include <iostream>

using namespace std;

int metodo1()
{
	int bit0, bit1, bit2, bit3;
	char cbit0, cbit1, cbit2, cbit3;
	int decimal;
	
	cout << "Introduce 4 cifras en binario: ";
	cin >> cbit3 >> cbit2 >> cbit1 >> cbit0;
	
	//Se resta el caracter 0 para sacar la diferencia entre los numeros al convertirlos de CHAR a INT
	bit0 = (int)cbit0 - '0';
	bit1 = (int)cbit1 - '0';
	bit2 = (int)cbit2 - '0';
	bit3 = (int)cbit3 - '0';
		
	decimal = bit0 + bit1*2 + bit2*4 + bit3*8;
	
	cout << "El valor decimal es: " << decimal;
	return 0;
}

int metodo2()
{
	int bit0, bit1, bit2, bit3;
	int decimal, binario;
	
	cout << "Introduce 4 cifras en binario: ";
	cin >> binario;
	
	bit3 = binario / 1000;
	bit2 = (binario % 1000) / 100;
	bit1 = (binario % 100) / 10;
	bit0 = binario % 10;
		
	decimal = bit0 + bit1*2 + bit2*4 + bit3*8;
	
	cout << "El valor decimal es: " << decimal;
	return 0;
}

int main()
{
	return metodo2();
}
