#include <iostream> 
using namespace std; 

int main() 
{ 
    const int MF=-1; 
    int EA;

    cout << "Introduce una serie de enteros, para terminar el -1" << endl;
    cin >> EA; //Comenzar

    while( (EA != MF) && ( (EA % 2 != 0) || (EA % 3 != 0) ) )
    {
        
    
        cin >> EA;
    }

    return 0;
}