/* Compilar con: gcc -Wall -g -std=c99 -oejemplo-depuracion ejemplo-depuracion.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h" // Define print_string, print_integer, read_character, read_integer y random_int_range, entre otras funciones.


int factorial_max10( int n )
{
    if (n < 0) {
        print_string("El número introducido es menor que 0\n");
        return -1;
    }
    else if (n > 10) {
        print_string("El número introducido es mayor que 10\n");
        return -1;
    }
    else { // n >= 0 && n <= 10
        int product = 1;
        for ( int i=1; i <= n; i++ ) {
            product *= i;
        }
        return product;
    }
}


int main(int argc, char* argv[]) {
  clear_screen();
  print_string("\nTUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS\n");
  while (true) {
    print_string("\n");
    print_string("1 - Cálculo de la función factorial\n");
    print_string("2 - Salir\n");
    print_string("\n");
    print_string("Elige una opción: ");
    char opc = read_character();
    print_string("\n");
    if (opc == '1') {
      print_string("Introduce un número de 0 a 10: ");
      int numero = read_integer();
      int resultado = factorial_max10(numero);
      if (resultado > 0) {
          print_string("El resultado de la función factorial para dicho número es: ");
          print_integer(resultado);
          print_string("\n");
      }
    } else if (opc == '2') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
