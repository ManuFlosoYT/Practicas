#include <iostream> 

using namespace std; 

void BinDec (int b1, int b2, int b3, int b4, int &dec) 
{ 
	dec = b1*1 + b2*2 + b3*4 + b4*8; 
} 

void Intercambio (char &a, char &b) 
{ 
	char aux; 
	aux = a;
	 a = b;
	 b = aux; 
}

 int main() 
 { 
	 int b1, b2, decimal1, decimal2; 
	 char x, y, z;
	 
	 b1 = 0; 
	 b2 = 1; 
	 
	 x = 'O'; 
	 y = 'P'; 
	 z = 'Q'; 
	 
	 Intercambio (x, y); 
	 Intercambio (y, z); 
	 
	 BinDec (b1, b2, b1, b2, decimal1); 
	 BinDec (0, 1, b1, b1, decimal2); 
	 
	 cout << "Valor de las variables x, y, z es: " << x << y << z << endl; 
	 cout << "El valor del numero 1 es : " << decimal1 << endl; 
	 cout << "El valor del numero 2 es : " << decimal2 << endl; 
	 return 0; 
}
