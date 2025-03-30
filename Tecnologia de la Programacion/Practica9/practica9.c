/**
 * @file practica9.c
 * @brief This program simulates a patient consultation system using queues.
 *
 * The program allows users to add patients to different specialties (queues) and then
 * simulates attending to patients from these queues in a random order.
 *
 * @author [Your Name]
 * @date [Date]
 */


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cola.h"

#define NUM_COLAS 5

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));

    // Reservar memoria para las colas y crearlas
    Cola* consultorio = malloc(sizeof(Cola) * NUM_COLAS);
    for (int i = 0; i < NUM_COLAS; i++)
    {
        consultorio[i] = crea();
    }

    char especialidades[NUM_COLAS][30] = {
        "Medicina General",
        "Pediatría",
        "Enfermería",
        "Medicina Interna",
        "Traumatología"
    };

    Elemento paciente;
    int especialidad = 0;
    do
    {
        printf("Introduce especialidad (1-5) (0 para terminar):\n");
        for (int i = 0; i < NUM_COLAS; i++)
        {
            printf("%d. %s\n", i + 1, especialidades[i]);
        }
        printf("0. Salir\n");

        scanf("%d", &especialidad);
        if (especialidad != 0)
        {
            printf("Introduce nombre: ");
            scanf("%s", paciente.nombre);
            printf("Introduce DNI: ");
            scanf("%s", paciente.DNI);
            inserta(consultorio[especialidad - 1], paciente);
        }
    } while(especialidad != 0);

    int alguna_cola_no_vacia;
    do {
        alguna_cola_no_vacia = 0;
        int aleatorio = rand() % NUM_COLAS; // Elegir una especialidad aleatoria

        if (!vacia(consultorio[aleatorio])) // Si la cola no está vacía, atender al paciente
        {
            paciente = recupera(consultorio[aleatorio]);
            printf("Paciente %s (%s) atendido en %s\n", paciente.nombre, paciente.DNI, especialidades[aleatorio]);
            suprime(consultorio[aleatorio]);
        }

        // Comprobar si alguna cola no está vacía
        for (int i = 0; i < NUM_COLAS; i++)
        {
            if (!vacia(consultorio[i])) 
            {
                alguna_cola_no_vacia = 1;
            }
        }
    } while (alguna_cola_no_vacia);

    // Liberar memoria de las colas y de la matriz de colas
    for (int i = 0; i < NUM_COLAS; i++)
    {
        libera(consultorio[i]);
    }
    free(consultorio);

    return 0;
}
