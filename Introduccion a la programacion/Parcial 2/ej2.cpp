#include <iostream>
using namespace std;
int main()
{
    const int MF = -1; //La marca de fin es constante durante ejecución
    int EA, k; //Creamos las variables a usar

    //Pedir la entrada de datos
    cout << "Introduce el valor de k" << endl;
    cin >> k;
    cout << "Introduce la secuencia de datos" << endl;
    cin >> EA;

    //Iterar por la secuencia de datos hasta que se encuentre la marca de fin
    while(EA != MF)
    {
        if ((EA % 7) && (EA < k))
        {
            //Si se encuentra el elemento se muestra la salida de datos y se termina la ejecución del programa
            cout << "El primer elemento divisible entre 7 y menor que " <<
            k << " es: " << EA << endl;
            return 0;
        }
        cin >> EA; //Avanzamos al siguiente elemento
    }
    
    //Solo se ejecuta esta parte si no se ha encontrado el elemento
    cout << "No hay ningun elemento que cumpla la propiedad" << endl;
    return 0;
}