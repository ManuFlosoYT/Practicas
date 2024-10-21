#include <iostream> 
using namespace std; 

int main () 
{ 
    int x, y, i, p; 
    
    cin >> x >> y; 
    
    p = 1; 
    
    for (i = 1; i <= x; i++) 
    { 
        p = p*2; 
    } 
    
    cout << p << endl; 
    
    for (i = x+1; i <= y; i++) 
    { 
        p = p*2; 
        cout << p << endl; 
    } 
    
    return 0; 
}