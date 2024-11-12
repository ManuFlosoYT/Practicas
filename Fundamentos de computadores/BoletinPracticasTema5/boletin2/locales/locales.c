#include <stdio.h>

// Max stack size by default is 8MB (ulimit -a | grep stack)

#define ARRAY_SIZE (1 << 19) // 512K elements of 4 bytes = 2 MiB

#define MAGIC_NUMBER (1234)

int magicNum = MAGIC_NUMBER;

void ayuda_pulsa_intro(void) {
    printf("En otro terminal, ejecuta la siguiente orden:\n\n");
    printf("pmap %d\n\n", getpid());
    printf("En la información mostrada por el comando pmap anterior, busca:\n");
    printf(" - El tamaño en memoria destinado a la pila\n");
    printf(" - A qué zonas de memoria corresponden las direcciones de 'magicNum' y 'inputNum'\n\n");
    printf("Finalmente, pulsa INTRO para continuar este programa...");
    getchar();
    getchar();
}

int doble_mult(int parametro) {
    ayuda_pulsa_intro();
    return parametro*2;
}

int doble_array(int parametro) {
    int localArray[ARRAY_SIZE];
    int i, res = 0;

    // Inicializa array con parámetro
    for(i=0; i < ARRAY_SIZE; i++) {
        localArray[i] = parametro;
    }
    ayuda_pulsa_intro();
    // res = doble(parametro)*N 
    for(i=0; i < ARRAY_SIZE; i++) {
        res += localArray[i]*2;
    }
    // Devuelve el resultado dividido entre N (doble)
    int doble = res / ARRAY_SIZE;
    return doble;
}

int main() {
    int inputNum;
    printf("Número mágico: %d\n", magicNum);
    printf("Dirección de memoria de la variable 'magicNum' = %#lx\n", (unsigned long)&magicNum);
    printf("Dirección de memoria de la variable 'inputNum' = %#lx\n", (unsigned long)&inputNum);
    printf("Introduce un número: ");
    int ret = scanf("%d", &inputNum);
    if (ret != 1) {
        printf("Error al leer de teclado\n");
        return 1;
    }
    int res;
    if (inputNum == MAGIC_NUMBER) {
        // Una manera muy rocambolesca de calcular el doble
        res = doble_array(inputNum);
    }
    else {
        // Devuelve el doble del valor pasado como parámetro
        res = doble_mult(inputNum);
    }
    printf("El doble de %d es: %d\n", inputNum, res);
    return 0;
}
