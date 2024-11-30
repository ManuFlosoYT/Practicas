#include <iostream>
using namespace std;
int main()
{
    //Definimos las constantes y las variables
    const int a0 = 5;
    const int a1 = 2;
    int x;

    //Solicitamos la entrada de datos
    cout << "Introduce un número" << endl;
    cin >> x;

    //Tratamos el caso de X = 0 imprimiendo la constante a0
    if(x == 0)
    {
        cout << "Solución: " << a0;
        return 0; //Terminamos la ejecución del programa
    }
    //Tratamos el caso de X = 1 imprimiendo la constante a1
    if(x == 1)
    {
        cout << "Solución: " << a1;
        return 0; //Terminamos la ejecución del programa
    }
    //Creamos una lista de enteros con largo X
    int* lista = new int[x];
    lista[0] = a0; //Definimos el primer elemento de la lista a 5 (a0)
    lista[1] = a1; //Definimos el segundo elemento de la lista a 2 (a1)
    //Empezamos el bucle en i=2 porque los casos anteriores ya están tratados de forma especial y ponemos la condición i <= X para terminar el bucle
    for(int i = 2; i <= x; i++)
    {
        //Calculamos el i-ésimo elemento de la lista usando la formula
        lista[ i ] = lista[ i - 2 ] - lista[ i - 1 ];
    }
    //Imprimimos el ultimo elemento de la lista que contiene la solución al problema, como hemos creado una lista de largo X, el ultimo elemento de la lista está almacenado en el índice X
    cout << "Solución: "<< lista[x] << endl;
    return 0;
}