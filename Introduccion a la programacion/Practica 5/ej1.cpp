#include <iostream> 
using namespace std; 

int main () 
{ 
    int cont = 0; // contador de blancos 
    char c; // carácter actual 

    cin.get(c); 
    while (c != '\n') // fin de línea de la entrada de datos 
    { 
        if (c == ' ') 
        { 
            cont++; 
        } 
        cin.get(c); 
    }; 
    
    cout << "El numero de blancos es: " << cont << endl; 
}