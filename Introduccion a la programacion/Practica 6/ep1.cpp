#include <iostream> 
using namespace std; 

int main() 
{ 
    const char MF='#'; // DISTANCIA entre los juegos de caracteres mayúsculas y minúsculas: 
    const int DISTANCIA = int('a') - int('A'); //Calcular la distancia entre mayúsculas y minúsculas
    char ea; // Elemento actual 
    char c_conv; // Elemento a Mayúsculas 

    // Primer esquema de recorrido del primer modelo de acceso secuencial
    cout <<"Introduce una serie de caracteres, para terminar el caracter #"<<endl; 
    cin >> ea; // Comenzar 
    while (ea != MF) 
    { 
        // Condición de finalización 
        if ((ea >= 'a') && (ea <= 'z'))
        { 
            c_conv = char(int(ea) - DISTANCIA); //Tratamiento EA 
        } 
        else
        { 
            c_conv = ea; 
        }
        cout << c_conv << ' '; // Registrar en la salida, separamos por un blanco 
        cin >> ea; 
    }
    return 0; 
}