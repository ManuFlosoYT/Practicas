#include <iostream> 
using namespace std;

int main() 
{ 
    /*
    Dada una secuencia de enteros positivos marcados con el valor -1,
    escriba un algoritmo que muestre en la salida estándar la secuencia de sumas parciales de (S1, S1 + S2, S1 + S2 + S3, ..) 
    Por ejemplo, para la secuencia de entrada: 1 4 5 3 5 6. La secuencia de salida sería: 1 5 10 13 18 24
    */

    int elementoActual, suma = 0;
    while (cin >> elementoActual && elementoActual != -1) {
        suma += elementoActual;
        cout << suma << " ";
    }

    return 0; 
}