#include <stdio.h>

#define STEP 50000
int ping(int parametro);
int pong(int parametro);

int pong(int parametro) {
    return ping(parametro+1);
}

int ping(int parametro) {
    if ((parametro % STEP) == 0) {
        printf("\n");
        printf("ping: parametro=%d\n\n", parametro);
        printf("En el otro terminal, observa el tamaño de la pila con pmap en este punto.\n\n");
        printf("Pulsa INTRO para continuar...");
        getchar();
    }
    return pong(parametro+1);
}


int main() {
    printf("### Ejemplo de desbordamiento de pila ###\n");
    printf("Este programa contiene en dos procedimientos (ping, pong) que se llaman mutuamente de forma recursiva sin que haya condición de parada.\n");
    printf("ping(0)->pong(1)->ping(2)->pong(3)....\n\n");
    printf("El programa se detendrá cada %d llamadas recursivas para poder visualizar el estado de la pila\n", STEP);
    printf("En otro terminal, ejecuta la siguiente orden en cada pausa del programa:\n\n");
    printf("pmap %d\n\n", getpid());

    ping(0);
}
