#include <iostream> 
using namespace std; 

int main() 
{ 
    const float MF=-1; 
    float EA; 
    float cont; 
    //Primer esquema de recorrido del primer modelo de acceso secuencial 
    cout<<"Introduce una serie de notas separadas por bancos "<< endl; 
    cin >> EA; 
    cont = 0; 

    while (EA != MF) 
    { 
        if (EA >= 5.0) 
        {
            cont=cont +1; 
        } 
        cin >> EA; 
    } 
    cout << "El número de aprobados es: " << cont; 
    return 0; 
}