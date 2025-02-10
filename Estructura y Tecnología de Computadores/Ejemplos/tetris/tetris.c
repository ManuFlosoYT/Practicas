/* Versión de tetris.c para los alumnos */
/* Sincronizada con ../tetris.c:3686 */
/* Compilar con: gcc -Wall -g -std=c11 -otetris tetris.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"
#include "keyio.h"

#define IMAGEN_MAX_SIZE 1024

typedef unsigned char Pixel;
#define PIXEL_VACIO ((Pixel) 0)
struct ImagenRep { 
  unsigned int ancho; 
  unsigned int alto;
  Pixel data[IMAGEN_MAX_SIZE];
};
typedef struct ImagenRep Imagen;

Pixel* imagen_pixel_addr(Imagen *img, int x, int y) {
  return &(img->data[0]) + (y * img->ancho + x);
}

void imagen_set_pixel(Imagen *img, int x, int y, Pixel color) {
  Pixel *pixel = imagen_pixel_addr(img, x, y);
  *pixel = color;
}

Pixel imagen_get_pixel(Imagen *img, int x, int y) {
  Pixel *pixel = imagen_pixel_addr(img, x, y);
  return *pixel;
}

void imagen_clean(Imagen *img, Pixel fondo) {
  for (int y = 0; y < img->alto; ++y) {
    for (int x = 0; x < img->ancho; ++x) {
      imagen_set_pixel(img, x, y, fondo);
    }
  }
} 

void imagen_init(Imagen *img, int ancho, int alto, Pixel fondo) {
  img->ancho = ancho;
  img->alto = alto;
  imagen_clean(img, fondo);
}

void imagen_copy(Imagen *dst, Imagen *src) {
  dst->ancho = src->ancho;
  dst->alto = src->alto;
  for (int y = 0; y < src->alto; ++y) {
    for (int x = 0; x < src->ancho; ++x) {
      Pixel p = imagen_get_pixel(src, x, y);
      imagen_set_pixel(dst, x, y, p);
    }
  }
}

void imagen_print(Imagen *img) {
  for (int y = 0; y < img->alto; ++y) {
    for (int x = 0; x < img->ancho; ++x) {
      Pixel p = imagen_get_pixel(img, x, y);
      print_character(p);
    }
    print_character('\n');
  }
}

void imagen_dibuja_imagen(Imagen *dst, Imagen *src, int dst_x, int dst_y) {
  for (int y = 0; y < src->alto; ++y) {
    for (int x = 0; x < src->ancho; ++x) {
      Pixel p = imagen_get_pixel(src, x, y);
      if (p != PIXEL_VACIO) {
        imagen_set_pixel(dst, dst_x + x, dst_y + y, p);
      }
    }
  }
}

void imagen_dibuja_imagen_rotada(Imagen *dst, Imagen *src, int dst_x, int dst_y) {
  for (int y = 0; y < src->alto; ++y) {
    for (int x = 0; x < src->ancho; ++x) {
      Pixel p = imagen_get_pixel(src, x, y);
      if (p != PIXEL_VACIO) {
        imagen_set_pixel(dst, dst_x + src->alto - 1 - y, dst_y + x, p);
      }
    }
  }
}

void integer_to_string(int n, char* buf) {
  char *p = buf;
  if (n != 0) {
    for (int i = n < 0 ? -n : n;
         i > 0;
         i = i / 10) {
      int d = i % 10;
      *p = d + '0';
      ++p;
    }
    if (n < 0) {
      *p = '-';
      ++p;
    }
  } else {
    *p = '0';
    ++p;
  }
  *p = '\0';
  --p;
  while (p > buf) {
    char c = *p;
    char *p = buf;
    *p = c;
    --p;
    ++buf;
  }
}

Imagen pieza_jota = { 2, 3, 
                             { 0,   '#',
                               0,   '#',
                               '#', '#' } };
Imagen pieza_ele = { 2, 3, 
                            { '#', 0,
                              '#', 0,
                              '#', '#' } };
Imagen pieza_barra = { 1, 4, 
                              { '#',
                                '#',
                                '#',
                                '#' } };
Imagen pieza_zeta = { 3, 2, 
                             { '#', '#', 0,
                               0,   '#', '#' } };
Imagen pieza_ese = { 3, 2, 
                            { 0,   '#', '#',
                              '#', '#', 0 } };
Imagen pieza_cuadro = { 2, 2, 
                               { '#', '#',
                                 '#', '#' } };
Imagen pieza_te = { 3, 2, 
                           { 0,   '#', 0,
                             '#', '#', '#' } };
Imagen *piezas[] = { &pieza_jota, &pieza_ele, &pieza_zeta, &pieza_ese, &pieza_barra, &pieza_cuadro, &pieza_te };
const int num_piezas = sizeof(piezas) / sizeof(piezas[0]);

Imagen *pieza_aleatoria(void) {
  return piezas[random_int_range(0, num_piezas)];
}

typedef unsigned long long Hora; // en milisegundos desde 1970-01-01T0:00

Imagen pantalla;
Imagen campo;
Imagen pieza_actual;
Imagen imagen_auxiliar;
int pieza_actual_x;
int pieza_actual_y;
bool acabar_partida;

void actualizar_pantalla(void) {
  const int pos_campo_x = 1;
  const int pos_campo_y = 2;

  /* limpia la pantalla */
  imagen_clean(&pantalla,' ');
  /* dibuja los bordes del campo */
  for (int y = 0; y < campo.alto; ++y) {
    imagen_set_pixel(&pantalla, pos_campo_x - 1, y + pos_campo_y, '|');
    imagen_set_pixel(&pantalla, pos_campo_x + campo.ancho, y + pos_campo_y, '|');
  }  
  for (int x = 0; x < campo.ancho + 2; ++x) {
    imagen_set_pixel(&pantalla, pos_campo_x - 1 + x, pos_campo_y + campo.alto, '-');
  }

  imagen_dibuja_imagen(&pantalla, &campo, pos_campo_x, pos_campo_y);
  imagen_dibuja_imagen(&pantalla, &pieza_actual, pieza_actual_x + pos_campo_x, pieza_actual_y + pos_campo_y);

  clear_screen();
  imagen_print(&pantalla);
}

void nueva_pieza_actual(void) {
  Imagen *elegida = pieza_aleatoria();
  imagen_copy(&pieza_actual, elegida);
  pieza_actual_x = 8;
  pieza_actual_y = 0;
}

bool probar_pieza(Imagen* pieza, int x, int y) {
  if (x < 0 || x + pieza->ancho > campo.ancho
      || y < 0 || y + pieza->alto > campo.alto) {
    return false;
  }
  for (int i = 0; i < pieza->ancho; ++i) {
    for (int j = 0; j < pieza->alto; ++j) {
      if (imagen_get_pixel(pieza, i, j) != PIXEL_VACIO
          && imagen_get_pixel(&campo, x + i, y + j) != PIXEL_VACIO) {
        return false;
      }
    }
  }
  return true;
}

bool intentar_movimiento(int x, int y) {
  if (probar_pieza(&pieza_actual, x, y)) {
    pieza_actual_x = x;
    pieza_actual_y = y;
    return true;
  }
  return false;
}

void bajar_pieza_actual(void) {
  if (!intentar_movimiento(pieza_actual_x, pieza_actual_y + 1)) {
    imagen_dibuja_imagen(&campo, &pieza_actual, pieza_actual_x, pieza_actual_y);
    nueva_pieza_actual();
  }
}

void intentar_rotar_pieza_actual(void) {
  Imagen *pieza_rotada = &imagen_auxiliar;
  imagen_init(pieza_rotada, pieza_actual.alto, pieza_actual.ancho, PIXEL_VACIO); // como la imagen se va a rotar 90 grados, se intercambian el ancho y el alto.
  imagen_dibuja_imagen_rotada(pieza_rotada, &pieza_actual, 0, 0);
  if (probar_pieza(pieza_rotada, pieza_actual_x, pieza_actual_y)) {
    imagen_copy(&pieza_actual, pieza_rotada);
  }
}

void tecla_salir(void) {
  acabar_partida = true;
}

void tecla_izquierda(void) {
  intentar_movimiento(pieza_actual_x - 1, pieza_actual_y);
}

void tecla_derecha(void) {
  intentar_movimiento(pieza_actual_x + 1, pieza_actual_y);
}

void tecla_abajo(void) {
  bajar_pieza_actual();
}

void tecla_rotar(void) {
  intentar_rotar_pieza_actual();
}

void tecla_truco(void) {
  for (int y = 13; y < 18; ++y) {
    for (int x = 0; x < campo.ancho - 1; ++x) {
      imagen_set_pixel(&campo, x, y, '#');
    }
  }
  imagen_set_pixel(&campo, 10, 16, PIXEL_VACIO);
}

void procesar_entrada(void) {
  struct { char tecla; void (*accion)(void); } opciones[] = {
    { 'x', tecla_salir },
    { 'j', tecla_izquierda },
    { 'l', tecla_derecha },
    { 'k', tecla_abajo },
    { 'i', tecla_rotar },
    { 't', tecla_truco }
  };
  int c = keyio_poll_key();
  for (int i = 0; i < sizeof(opciones) / sizeof(opciones[0]); ++i) {
    if (opciones[i].tecla == c) {
      opciones[i].accion();
      actualizar_pantalla();
    }
  }
}

void jugar_partida(void) {
  imagen_init(&pantalla, 20, 22, ' ');
  imagen_init(&campo, 14, 18, PIXEL_VACIO);
  nueva_pieza_actual();
  acabar_partida = false;

  int pausa = 1000; 
  Hora antes = get_time();
  actualizar_pantalla();
  while (!acabar_partida) {
    procesar_entrada();
    Hora ahora = get_time();
    int transcurrido = ahora - antes;
    if (transcurrido > pausa) {
      antes = ahora;
      bajar_pieza_actual();
      actualizar_pantalla();
    }
  }
}

int main(int argc, char* argv[]) {
  while (true) {
    clear_screen();
    print_string("Tetris\n\n 1 - Jugar\n 2 - Salir\n\nElige una opción:\n");
    char opc = read_character();
    if (opc == '1') {
      jugar_partida();
    } else if (opc == '2') {
      print_string("\n¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("\nOpción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
