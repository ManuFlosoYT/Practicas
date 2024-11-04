//Obtención de cuadrados de una secuencia de números enteros en el intervalo [99, -99] introducidos desde el teclado. 
#include <iostream> 
using namespace std; 

int main() 
{ 
    const int MF=-100; 
    int EA; //Elemento actual de la entrada 
    int EA_R; //Cuadrado del EA 
    
    //Primer esquema de recorrido del primer modelo de acceso secuencial 
    cout<<"Introduce una serie de enteros, para terminar el -100"<<endl; 
    cin >> EA; //Comenzar 
    
    while (EA != MF) 
    { 
        //Condición de finalización 
        EA_R= EA * EA;
        // Tratamiento del elemento actual 
        cout << EA_R << ", "; 
        // Registrar en la salida 
        cin >> EA; //Avanzar 
    } 
    return 0;
}