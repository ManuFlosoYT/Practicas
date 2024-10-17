#include <iostream>

using namespace std;

int Max2 (int a, int b)
{ 
    int mayor; 
    if (a > b) 
    { 
        mayor = a; 
    } 
    else 
    { 
        mayor = b; 
    } 
    return mayor; 
}

int main()
{
    int primero, segundo;
    cout << "Introduce 2 numeros: ";
    cin >> primero >> segundo;
    cout << "El numero mas grande es: " << Max2(primero, segundo);
    return 0;
}