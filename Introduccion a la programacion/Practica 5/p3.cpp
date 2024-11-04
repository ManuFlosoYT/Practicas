#include <iostream> 
using namespace std; 

int main () 
{ 
    int dividendo, divisor, cociente, resto;
    resto = 0;
    cociente = 0;

    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisor;

    if(divisor == 0)
    {
        cout << "No se puede dividir por 0" << endl;
        return 0;
    }

    if(dividendo < divisor){
        cout << "El dividendo no puede ser menor al divisor" << endl;
        return 0;
    }

    while(resto < divisor)
    {
        resto -= divisor ;
        cociente++;
    }

    cout << "El cociente es: " << cociente << endl;
    cout << "El resto es: " << resto << endl;

    return 0; 
}