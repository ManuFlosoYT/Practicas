#include <iostream> 
using namespace std; 
// En este programa el LIMITE es una constante incorporada en el programa. 
// También podría ser un valor cualquiera leído de la entrada. 

int main ()
{
    const float LIMITE = 5; //Max = 15.4
    float suma = 0.0; // valor de la suma de términos en un momento determinado
    int cuenta = 0; // cuenta el número de términos y lo utilizamos de divisor

    do 
    { 
        cuenta++;
        suma = suma + 1.0 / cuenta; 
    } while (suma <= LIMITE); 

    cout << "El numero de terminos es " << cuenta; 
}