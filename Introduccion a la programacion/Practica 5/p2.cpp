#include <iostream> 
using namespace std; 

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    if(fact == 0){return 1;}

    return fact;
}

int elevar(int x, int y)
{
    int ele = 1;

    for (int i = 0; i < y; i++)
    {
        ele *= x;
    }

    return ele;
}

int main ()
{
    int x, fact, ele;

    cout << "Introduce un numero: ";
    cin >> x;

    int total = 0;
    for(int i = 0; i < x; i++)
    {
        ele = elevar(x, i);
        fact = factorial(i);
        total += ele/fact;
    }

    cout << total << endl;
}
