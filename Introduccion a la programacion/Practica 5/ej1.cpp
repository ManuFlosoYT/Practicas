#include <iostream> 
using namespace std; 

int main () 
{ 
    int cont; // contador de blancos 
    char c; // carácter actual 

    cont = 0; 
    cin.get(c); 
    while (c != '\n') // fin de línea de la entrada de datos 
    { 
        if (c == ' ') 
        { 
            cont = cont + 1; 
        } 
        cin.get(c); 
    }; 
    
    cout << "El numero de blancos es: " << cont << endl; 
}