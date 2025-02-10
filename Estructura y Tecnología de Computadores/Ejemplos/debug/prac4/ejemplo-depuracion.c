/* Compilar con: gcc -Wall -g -std=c99 -oejemplo-depuracion ejemplo-depuracion.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h" // Define print_string, print_integer, read_character, read_integer y random_int_range, entre otras funciones.

#define NUM_DATOS_MAX 16

/* Vector de enteros que serán comparados */
int enteros[NUM_DATOS_MAX] = { 
   4, 5, 3344, 655, -74, 53, 23, 14, -1005, 34, 25, 26, 7, 8, 4, 83 };

/* Compara los elementos del vector global «enteros» con respecto
   al escalar recibido y devuelve el número de apariciones de «escalar» 
   en «enteros», implementado mediante un bucle for
*/
int contar_apariciones(int escalar) {
  int apariciones = 0;
  for (int i = 0; i < NUM_DATOS_MAX; ++i) {
    if (enteros[i] == escalar) {
	++apariciones;
    }
  }
  return apariciones;
}


int main(int argc, char* argv[]) {
  clear_screen();
  print_string("\nTUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS\n");
  while (true) {
    print_string("\n Contenido del vector de enteros: ");
     for (int i = 0; i < NUM_DATOS_MAX; ++i) {
      print_integer(enteros[i]); print_string(" ");
    }
    print_string("\n");
    print_string("\n");

    print_string("1 - Contar las apariciones de un escalar en un vector (for)\n");
    print_string("2 - Salir\n");
    print_string("\n");
    print_string("Elige una opción: ");
    char opc = read_character();
    print_string("\n");
    if (opc == '1') {
      print_string("Introduce el escalar con el que quieres comparar: ");
      int escalar = read_integer();
      int apariciones = contar_apariciones(escalar);
      print_string("El número de apariciones es: ");
      print_integer(apariciones);
      print_string("\n");
    } else if (opc == '2') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
