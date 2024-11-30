#include <iostream>
using namespace std;
int main()
{
    const int MF = -1; //La marca de fin es constante durante ejecución
    int EA, m; //Creamos las variables a usar
    int suma = 0; //Se inicializa a 0 para tratar el caso de secuencia vacía

    //Pedir la entrada de datos
    cout << "Introduce el valor de m" << endl;
    cin >> m;
    cout << "Introduce la secuencia de datos" << endl;
    cin >> EA;

    //Iterar por la secuencia de datos hasta que se encuentre la marca de fin
    while(EA != MF)
    {
        if(EA % m == 0) //Comprueba que EA sea multiplo de m
        {
            suma += EA; //Suma el valor de EA a la suma total
        }
        cin >> EA; //Avanzamos al siguiente elemento
    }
    
    //Mostramos la salida de datos y termina la ejecución del programa
    cout << "La suma de los múltiplos de m es: " << suma << endl;
    return 0;
}