#include <stdio.h>

#define STEP 50000
int ping(int parametro);
int pong(int parametro);

int pong(int parametro) {
    return ping(parametro+1);
}

int ping(int parametro) {
    return pong(parametro+1);
}


int main() {
    printf("### Ejemplo de desbordamiento de pila ###\n");
    printf("Este programa contiene en dos procedimientos (ping, pong) que se llaman mutuamente de forma recursiva sin que haya condición de parada.\n");

    ping(0);
}
