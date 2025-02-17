/* Compilar con: gcc -Wall -g -std=c11 -oprograma-ejercicio programa-ejercicio.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h" // Define print_string, print_integer, read_character y read_integer, entre otras funciones.

bool es_primo(int num) {  
  if (num < 2) { 
    return false;
  } else if ( num == 2 ) {
       return true;
   } else if (num % 2 == 0) {
      return false;
  }
  for (int i = 3; i < num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

#define MAX_LINEAS 44

void dibujar_triangulo(int num_lineas)
{  
  int max_lineas = num_lineas;
  if (num_lineas > MAX_LINEAS) {
    max_lineas = MAX_LINEAS;
  }
  int blancos = max_lineas - 1 ;
  int elementos = 1;
  for (int i = 0; i < max_lineas; i++) {
    for (int k = 0; k < blancos; k++) {
      print_string(" ");
    }
    for (int k = 0; k < elementos; k++) {
      print_string("#");
    }
    print_string("\n");
    blancos = blancos - 1;
    elementos = elementos + 2;
  }
}

int contar_letras(char contar_c, char fin_c) {
  /* POR HACER */
}

void calcular_potencia(int base, int num_potencias) {
  /* POR HACER */
}



int main(int argc, char* argv[]) {
  clear_screen();
  print_string("\nPráctica 2 de ensamblador de ETC\n");
  while (true) {
    print_string("\n"); 
    print_string("\n 1 - ¿Es primo? \n 2 - Dibujar triángulo \n 3 - Contar letras \n 4 - Calcular potencias \n 5 - Salir\n\nElige una opción: ");
    char opc = read_character();
    print_string("\n");
    if (opc == '1') {
      print_string("Introduce un número: ");
      int num = read_integer();
      bool resul = es_primo(num);
      if (!resul) {
        print_string("El número no es primo\n");
      } else {
        print_string("El número es primo\n");
      }
    } else if (opc == '2') {
      print_string("Introduce número de líneas: ");
      int num_lineas = read_integer();
      dibujar_triangulo(num_lineas);
    } else if (opc == '3') {
      print_string("Introduce el caracter a contar: ");
      char contar_c = read_character();
      print_string("\nIntroduce el caracter de fin: ");
      char fin_c = read_character();
      int total = contar_letras(contar_c, fin_c);
      print_string("\nEl caracter se ha introducido "); print_integer(total); print_string(" veces\n");
    } else if (opc == '4') {
      print_string("Introduce un número base: ");
      int base = read_integer();
      print_string("Introduce hasta qué potencia calcular: ");
      int num_potencias = read_integer();
      calcular_potencia(base, num_potencias);
    } else if (opc == '5') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
