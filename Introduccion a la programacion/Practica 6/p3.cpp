#include <iostream> 
using namespace std;

/*
Queremos construir un programa que dada una secuencia de enteros del primer modelo de acceso secuencial 
en el intervalo [-100...100] marcada con el valor 101, construya otra secuencia de enteros (se muestra en pantalla), 
en la que cada elemento sea la suma de cada par de elementos adyacentes en la primera (la secuencia de entrada). 
Si la secuencia de entrada es S = [S1, S2, …, Sn] la secuencia resultado debe ser R = [S1+S2, S2+S3, S3+S4, …, Sn–1+Sn]. 
Si la secuencia de entrada está vacía o consta de un único elemento, mostrará el mensaje “La secuencia está vacía”.
*/

int main() 
{ 
    const int MARCA_FIN = 101;
    int suma, anterior, actual;

    cin >> actual;
    if (actual == MARCA_FIN) {
        cout << "La secuencia esta vacia" << endl;
        return -1;
    }

    anterior = actual;
    cin >> actual;
    if (actual == MARCA_FIN) {
        cout << "La secuencia esta vacia" << endl;
        return -1;
    }

    while (actual != MARCA_FIN) {
        suma = anterior + actual;
        cout << suma << " ";
        anterior = actual;
        cin >> actual;
    }

    return 0; 
}