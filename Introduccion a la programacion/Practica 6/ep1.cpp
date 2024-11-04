#include <iostream> 
using namespace std; 

int main() 
{ 
    const char MF='#'; // Distancia entre los juegos de caracteres mayúsculas y minúsculas: 
    const int Distancia = int('a') - int('A'); //Calcular la distancia entre mayúsculas y minúsculas
    char EA; // Elemento actual 
    char c_conv; // Elemento a Mayúsculas 

    // Primer esquema de recorrido del primer modelo de acceso secuencial
    cout <<"Introduce una serie de caracteres, para terminar el carácter #"<<endl; 
    cin >> EA; // Comenzar 
    while (EA != MF) 
    { 
        // Condición de finalización 
        if ((EA >= 'a') && (EA <= 'z'))
        { 
            c_conv = char(int(EA) - Distancia); //Tratamiento EA 
        } 
        else
        { 
            c_conv = EA; 
        } 
        cout << c_conv <<' '; // Registrar en la salida, separamos por un blanco 
        cin >> EA; 
    }
    return 0; 
}