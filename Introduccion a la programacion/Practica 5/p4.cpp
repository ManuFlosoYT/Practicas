#include <iostream> 
using namespace std; 

int main () 
{ 
    int m, n, actual, ultimo, penultimo, antepenultimo;

    cout << "Introduce el valor de m: ";
    cin >> m;

    if(m < 0)
    {
        cout << "Los valores de m deben ser mayores a 0" << endl;
        return -1;
    }

    if(m < 3)
    {
        cout << "El indice de n es: " << m << endl;
        return 0; 
    }

    actual = 7;
    ultimo = 3;
    penultimo = 2;
    antepenultimo = 1;
    n = 3;

    while(actual <= m)
    {
        antepenultimo = penultimo;
        penultimo = ultimo;
        ultimo = actual;

        actual = 3*ultimo - 2*antepenultimo;
        n++;
    }

    cout << "El valor actual es: " << actual << endl;
    cout << "El indice de n es: " << n << endl;

    return 0; 
}