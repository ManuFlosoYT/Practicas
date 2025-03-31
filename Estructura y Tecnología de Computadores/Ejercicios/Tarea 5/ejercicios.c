/* Compilar con: gcc -Wall -g -std=c11 -oprograma-ejercicio programa-ejercicio.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h" // Define print_string, print_integer, read_character y read_integer entre otras funciones.

/* Ejercicio 1 */ 

struct Vector3D {
  int x;
  int y;
  int z;
};

struct Vector3D va;
struct Vector3D vb;
struct Vector3D vc;
  
void sumar_vb_vc(void) {
  va.x = vb.x + vc.x;
  va.y = vb.y + vc.y;
  va.z = vb.z + vc.z;
}

/* Ejercicio 2 */ 

char texto[] = "En un lugar de la Mancha, de cuyo nombre no quiero acordarme, no ha mucho tiempo que...";
int cuentas_letras[26];  // 26 letras de la a a la z

void contar_letras(void) {
  for (int i = 0; i < 26; ++i) {
    cuentas_letras[i] = 0;
  }
  for (int i = 0; texto[i] != '\0'; ++i) {
    char letra = texto[i];
    if (letra >= 'a' && letra <= 'z') {
      int idx = letra - 'a';
      cuentas_letras[idx] = cuentas_letras[idx] + 1;
    }
  }
}

/* Ejercicio 3 */ 

int matA[5][4] = {
  { 3, 4, 5, 6 },
  { 2, 1, 3, 0 },
  { 7, 8, 7, 2 },
  { 0, 1, 9, 5 },
  { 8, 3, 6, 1 },
};
int matB[4][3] = {
  { 7, 8, 2 },
  { 3, 7, 1 },
  { 9, 0, 1 },
  { 1, 2, 4 }
};
int matC[5][3];

void multiplicar_matA_matB(void) 
{
  for (int i = 0; i < 5; ++i) 
  {
    for (int j = 0; j < 3; ++j) 
	{
      int r = 0;
      for (int k = 0; k < 4; ++k) 
	  {
        r = r + matA[i][k] * matB[k][j];
      }
      matC[i][j] = r;
    }
  }
}

/* Ejercicio 4 */ 

struct Contacto {
  char nombre[100];
  int edad;
  char email[50];
};

struct Contacto agenda[1000] = {
  { "María", 21, "maria@example.org" },
  { "Pepe",  20, "pepe@example.org" },
  { "Paco",  22, "paco@example.org" },
  { "Lola",  19, "lola@example.org" },
};
int num_contactos = 4;

void mostrar_agenda(void) {
  print_string("Contenido actual de la agenda:\n");
  for (int i = 0; i < num_contactos; ++i) {
    print_integer(i);
    print_string(" - Nombre: ");
    print_string(agenda[i].nombre);
    print_string(", Edad: ");
    print_integer(agenda[i].edad);
    print_string(", Email: ");
    print_string(agenda[i].email);
    print_string("\n");
  }
}

/* Ejercicio 5 */ 

/* Lee una línea de la entrada y la almacena en buffer sin el caracter
 * de retorno de carro final. Lee como máximo buffer_size-1 caracteres
 * y la cadena almacenada siempre acaba en \0. Este procedimiento es
 * necesario porque la llamada al sistema read_string de MARS incluye
 * el retorno de carro leído en el resultado. */
void read_line(char *buffer, int buffer_size) {
  read_string(buffer, buffer_size);
  for (int i = 0; i < buffer_size && buffer[i] != '\0'; ++i) {
    if (buffer[i] == '\n') {
      buffer[i] = '\0';
    }
  }
}

void anadir_contacto(void) {
  print_string("Introduzca el nombre del nuevo contacto: ");
  read_line(agenda[num_contactos].nombre, 100);
  print_string("Introduzca la edad del nuevo contacto: ");
  agenda[num_contactos].edad = read_integer();
  print_string("Introduzca el correo del nuevo contacto: ");
  read_line(agenda[num_contactos].email, 50);
  /* pone el email en minúsculas */
  for (int i = 0; i < 50 && agenda[num_contactos].email[i] != '\0'; ++i) {
    char c = agenda[num_contactos].email[i];
    if (c >= 'A' && c <= 'Z') {
      agenda[num_contactos].email[i] = c + ('a' - 'A');
    }
  }
  num_contactos = num_contactos + 1;
}

/* Procedimiento principal de prueba */
int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\nPráctica 4 de ensamblador de ETC\n\n 1 - Estructuras\n 2 - Arrays y cadenas\n 3 - Arrays bidimensionales\n 4 - Estructuras\n 0 - Salir\n\nElige una opción: ");
    char opc = read_character();
    print_string("\n");
    print_string("\n");
    if (opc == '1') {
      vb.x = 7;
      vb.y = 8;
      vb.z = 9;
      vc.x = 3;
      vc.y = 4;
      vc.z = 2;
      sumar_vb_vc();
      print_string("(");
      print_integer(vb.x);
      print_string(",");
      print_integer(vb.y);
      print_string(",");
      print_integer(vb.z);
      print_string(") + (");
      print_integer(vc.x);
      print_string(",");
      print_integer(vc.y);
      print_string(",");
      print_integer(vc.z);
      print_string(") = (");
      print_integer(va.x);
      print_string(",");
      print_integer(va.y);
      print_string(",");
      print_integer(va.z);
      print_string(")\n");
    } else if (opc == '2') {
      contar_letras();
      print_string("\nFrecuencia de cada letra en el texto:\n");
      for (int i = 0; i < 26; ++i) {
        print_character(i + 'a');
        print_string(": ");
        print_integer(cuentas_letras[i]);
        print_string("\n");
      }
    } else if (opc == '3') {
      multiplicar_matA_matB();
      print_string("matA:\n");
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
          print_integer(matA[i][j]);
          print_string(" ");
        }
        print_string("\n");
      }
      print_string("matB:\n");
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
          print_integer(matB[i][j]);
          print_string(" ");
        }
        print_string("\n");
      }
      print_string("matC = matA × matB:\n");
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
          print_integer(matC[i][j]);
          print_string(" ");
        }
        print_string("\n");
      }
    } else if (opc == '4') {
      anadir_contacto();
      mostrar_agenda();
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
