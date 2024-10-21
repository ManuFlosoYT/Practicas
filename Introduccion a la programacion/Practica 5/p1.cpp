#include <iostream> 
using namespace std; 

int main () 
{ 
    // Cambio de while a do-while
    int cont; // contador de blancos 
    char c; // carácter actual 

    cont = 0; 
    cin.get(c); 

    do
    { 
        if(c == '\n') break; // fin de línea de la entrada de datos

        if (c == ' ') 
        { 
            cont = cont + 1; 
        }

        cin.get(c); 
    } while (c != '\n'); // fin de línea de la entrada de datos
    
    cout << "El numero de blancos es: " << cont << endl;



    // Cambio de do-while a while

    const float LIMITE = 5; //Max = 15.4
    float suma = 0.0; // valor de la suma de términos en un momento determinado
    int cuenta = 1; // cuenta el número de términos y lo utilizamos de divisor

    while(suma <= LIMITE)
    { 
        suma = suma + 1.0 / cuenta;
        cuenta++;
    };
    cuenta--;

    cout << "El numero de terminos es " << cuenta; 

    return 0;
}