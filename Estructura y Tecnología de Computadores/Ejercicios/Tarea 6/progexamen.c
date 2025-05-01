/* Compilar con: gcc -Wall -g -std=c11 -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"
#define NUM_MESES 12
#define MAX_LONGITUD_NOMBRE_DESTINO 23
#define MAX_LEN_NOMBRE 54

struct FechaRep 
{
	int ano;
	int mes;
	int dia;
};

typedef struct FechaRep Fecha;

char *meses[12] = 
{ 
	"enero", 
	"febrero", 
	"marzo", 
	"abril", 
	"mayo", 
	"junio", 
	"julio", 
	"agosto", 
	"septiembre", 
	"octubre", 
	"noviembre", 
	"diciembre" 
};

struct ViajeRealizadoRep 
{
	char cliente[MAX_LEN_NOMBRE];
	int id_viaje;
	Fecha fecha_viaje;
	int precio_viaje; 
};

typedef struct ViajeRealizadoRep ViajeRealizado;

struct ViajeRep 
{
	int id;
	char ciudad_destino[MAX_LONGITUD_NOMBRE_DESTINO];
	char pais[MAX_LONGITUD_NOMBRE_DESTINO];
	int duracion;
	int precio_mes[NUM_MESES];
};

typedef struct ViajeRep Viaje;


#define MAX_VENTAS 100
ViajeRealizado viajesrealizados[MAX_VENTAS] = 
{
	{ "Pilar",   23, { 2024,  5, 10 }, 2730 },
	{ "Gema",    28, { 2023,  4, 20 }, 1130 },
	{ "Pilar",    8, { 2024,  1, 15 }, 2130 },
	{ "Ricardo", 43, { 2023, 12,  7 }, 5000 },
	{ "Juan",    16, { 2023,  8,  7 }, 1840 },
	{ "Agustin", 35, { 2023, 12, 18 }, 2410 },
	{ "Jesus",   15, { 2023,  1, 18 }, 1400 },
};

int num_ventas = 7;

#define MAX_VIAJES 100
Viaje viajes[MAX_VIAJES] = 
{
	{ 
		28, "Tokio", "Japón", 15,
		{ 2000, 2500, 2300, 1300, 2130, 2850, 3300, 3500, 3100, 2830, 2550, 3210 }
	},
	{  
		8, "Kioto",      "Japón",         12,
		{ 2200, 1500, 2100, 1600, 2730, 2650, 4300, 4100, 3400, 1830, 2450, 3610 } 
	},
	{ 
		18, "Sidney",     "Australia",     21,
		{ 4200, 3500, 4100, 5600, 3730, 3650, 4300, 5100, 6400, 5830, 4450, 6610 } 
	},
	{ 
		43, "Melbourne",  "Australia",     28,
		{ 4600, 4550, 5300, 6600, 4730, 4750, 6230, 4140, 5500, 4730, 5650, 5710 } 
	},
	{ 
		23, "Auckland",   "Nueva Zelanda", 19,
		{ 2600, 3550, 3300, 3600, 2730, 2750, 3230, 3140, 2500, 2730, 2650, 1710 } 
	},
	{ 
		35, "Wellington", "Nueva Zelanda", 19,
		{ 3400, 2350, 2600, 2900, 2930, 2950, 2830, 3440, 3500, 3730, 3650, 2410 } 
	},
	{ 
		15, "Galway",     "Irlanda",        9,
		{ 1400, 1350, 2600, 2100, 1130, 2250, 2230, 2140, 2500, 3430, 1650, 2410 } 
	},
	{
		16, "Cork",       "Irlanda",        10,
		{ 2500, 1460, 2700, 1400, 1310, 1450, 2730, 3840, 2450, 2230, 1400, 2710 } 
	},
};

int num_viajes = 8;

/* Funciones varias de utilidad */





int buscar_viaje_id(int id) 
{
	for(int i = 0; i < num_viajes; i ++)
	{
		if (viajes[i].id == id) 
		{
			return i;
		}
	}
	return -1;   
}

void print_ciudad_destino_viaje(int id)
{
	for(int i = 0; i < num_viajes; i ++)
	{
		if (viajes[i].id == id) 
		{
			print_string(viajes[i].ciudad_destino);
			return;   
		}
	}
}


void print_nombre_mes(int mes) 
{
	print_string(meses[mes]);
}

/* EJERCICIO 1 */

void listar_viajes_realizados(void){
	for(int i = 0 ; i < num_ventas; i++) 
	{
		int indice_viaje = buscar_viaje_id(viajesrealizados[i].id_viaje);

		if (indice_viaje >= 0)  
		{
			print_string(viajesrealizados[i].cliente);
			print_string(" viajó a ");
			print_ciudad_destino_viaje(viajesrealizados[i].id_viaje);
			print_string(" y pagó ");
			print_integer(viajesrealizados[i].precio_viaje);
			print_string(" euros\n");
		}
	}	
}

/* EJERCICIO 2 */

int buscar_viaje_precio_dias(int min, int max, int duracion_max) 
{
	int total_destinos = 0;	

	for (int i = 0; i < num_viajes; ++i) 
	{
		if (viajes[i].duracion <= duracion_max) 
		{
			print_string("Viajar a ");
			print_string(viajes[i].ciudad_destino);
			print_string(" dura ");
			print_integer(viajes[i].duracion);
			print_string(" días y cuesta:\n");

			for (int j = 0; j < 12; ++j) 
			{
				if (min <= viajes[i].precio_mes[j] && max >= viajes[i].precio_mes[j]) 
				{
					total_destinos++;
					print_integer(viajes[i].precio_mes[j]);
					print_string(" euros en el mes de ");
					print_nombre_mes(j);
					print_string(".\n");
				}
			}
			print_string("\n");
		}
	}
	return total_destinos;
}

/* EJERCICIO 3 */
void buscar_viaje_mas_barato(void) 
{
/* Por hacer*/
}


int main(int argc, char* argv[]) 
{
	clear_screen();

	while (true) 
	{
		print_string("\n\nExamen de ETC de ensamblador\n\n"
		" 1. Listar viajes realizados\n"
		" 2. Viajes precio medio\n"
		" 3. Mostrar mes más barato por destino\n"
		" 0. Salir\n\n"
		"Elige una opción: ");

		char opc = read_character();
		print_string("\n\n");

		if (opc == '1') 
		{
			print_string("Listado de viajes realizados:\n");
			listar_viajes_realizados();
			print_string("\n\n");
		} else if (opc == '2') 
		{
			int total_destinos = buscar_viaje_precio_dias(1000, 2000, 18);
			print_string("Se han encontrado ");
			print_integer(total_destinos);
			print_string(" viajes con un precio entre 1000 y 2000 euros y una duración máxima de 18 días.\n\n");
			total_destinos = buscar_viaje_precio_dias(2500, 3000, 20);
			print_string("Se han encontrado ");
			print_integer(total_destinos);
			print_string(" viajes con un precio entre 2000 y 3000 euros y una duración máxima de 20 días.\n\n");
			total_destinos = buscar_viaje_precio_dias(1000, 1500, 12);
			print_string("Se han encontrado ");
			print_integer(total_destinos);
			print_string(" viajes con un precio entre 1000 y 1500 euros y una duración máxima de 12 días.\n");
		} else if (opc == '3') 
		{
			mostrar_mes_mas_barato_por_destino();
		} else if (opc == '0') 
		{
			print_string("¡Adiós!\n");
			mips_exit(0);
		} else 
		{
			print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
			read_character();
		}
	}
}

