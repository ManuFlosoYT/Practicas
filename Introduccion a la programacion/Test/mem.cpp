#include <iostream> 
using namespace std;

int main() 
{ 
    int *p = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        p[i] = i;
    }
    
    int *j = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        j[i] = i;
    }

    int *k = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        k[i] = i;
    }

    int *l = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        l[i] = i;
    }

    int *m = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        m[i] = i;
    }

    int *n = new int[1024*1024*1024];
    for(int i = 0; i < 1024*1024*1024; i++){
        n[i] = i;
    }
    return 0; 
}