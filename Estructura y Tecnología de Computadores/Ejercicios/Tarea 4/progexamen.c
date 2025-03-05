#include <stdbool.h>
#include "mips-runtime.h"

/*Ejercicio 1*/
/* Imprime x elementos de la serie de Fibonnaci */
void serie_fibonacci(int x) {
  if (x <= 0) {  
    return;
  }
  print_string("Serie Fibonacci: ");
  int f0 = 0;
  print_integer(f0);
  if ( x > 1 ) {
      int f1 = 1;
      int siguiente = f0 + f1;
      print_string(" ");
      print_integer(f1);
      for (int i = 2; i < x; i++) {
        print_string(" ");
        print_integer(siguiente);
        f0 = f1;
        f1 = siguiente;
        siguiente = f0 + f1;
      }
  }
  print_string("\n");
}

int gasto=0;

/*Ejercicio 2*/
/* Devuelve la cuenta total del dinero gastado */
int hacer_cuenta(int max) {
  int total = 0;

  print_string("Introduce las cantidades gastadas: ");
  int gasto = read_integer();

  if(gasto <= 0)
  {
    return 0;
  }

  while(gasto <= max || gasto > 0)
  {
    total += gasto;
    gasto = read_integer();
  }
  return total;
}


int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Serie de Fibonacci\n"
                 " 2. Hacer cuenta\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      print_string("Introduce el número para calcular la serie de Fibonacci: ");
      int num = read_integer();
      serie_fibonacci(num);
      print_string("\n");
    } else if (opc == '2') {
      print_string("Límite máximo de gasto permitido: ");
      int max = read_integer();
      int total = hacer_cuenta(max);
      print_string("El total gastado es: ");
      print_integer(total);
      print_string("\n");
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
