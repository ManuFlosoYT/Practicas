#include <iostream> 
using namespace std; 

int main() 
{ 
    const int MF=-1; 
    int EA;
    int contador = 0;

    cout << "Introduce una serie de enteros, para terminar el -1" << endl;
    cin >> EA; //Comenzar

    while(EA != MF)
    {
        if(EA % 7 == 0)
        {
            contador++;
        }
    
        cin >> EA;
    }

    cout << "El numero de elementos que son multiplos de 7 es: " << contador << endl;
    return 0;
}