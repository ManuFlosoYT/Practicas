/* Compilar con: gcc -Wall -g -std=c99 -oejemplo-depuracion ejemplo-depuracion.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include <stdio.h>
#include "mips-runtime.h" // Define print_string, print_integer, read_character, read_integer y random_int_range, entre otras funciones.

bool es_digito(char caracter) {
    return (caracter >= '0' &&
            caracter <= '9');
}

int contar_digitos(char fin_c )
{
   char c;
   int contador = 0;
   print_string("Introduce caracteres: ");
   do {
       c = read_character();
       if (es_digito(c)) {
           contador ++;
       }
   } while ( c != fin_c );
  return contador;
}

int main(int argc, char* argv[]) {
  clear_screen();
  print_string("\nTUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS\n");
  while (true) {
    print_string("\n");

    print_string("1 - Contar dígitos\n");
    print_string("2 - Salir\n");
    print_string("\n");
    print_string("Elige una opción: ");
    char opc = read_character();
    print_string("\n");
    if (opc == '1') {
      print_string("Introduce caracter de fin: ");
      char fin_c = read_character();
      printf("\n");
      int total = contar_digitos(fin_c);
      print_string("\nEl número de dígitos introducidos es ");
      print_integer(total);
    } else if (opc == '2') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
