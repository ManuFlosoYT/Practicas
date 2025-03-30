#ifndef PARCIAL1_H
#define PARCIAL1_H

// Imprime el menu con las opciones disponibles
void ImprimirMenu();

// Vacía el buffer de entrada
void VaciarBufferEntrada();


// Ejercicio 1

// El usuario debe adivinar un número aleatorio entre 1 y 10
// Se le indicará si el número es mayor o menor
// Se le indicará el número de intentos
void ElejirNumeroAleatorio();


// Ejercicio 2

// Calcula el tiempo que tardaría un objeto en llegar al sol
// El usuario introduce la velocidad en kmh
// La distancia de la tierra al sol es de 149 600 000 km
// La velocidad de la luz es de 299 792 km/s
// Imprime el tiempo en segundos, minutos, horas, días y años
void TiempoViajeSol();
const int _DISTANCIA_TIERRA_SOL = 149600000; // Distancia de la tierra al sol en Km
const int _VELOCIDAD_LUZ = 299792;  // Velocidad de la luz en Km/s


// Ejercicio 3

// El usuario introduce un rango de numeros enteros
// El usuario introduce un número
// Se le indicará si el número está dentro del rango

// Devuelve codigo de error si la lectura falla o el rango es incorrecto
// Devuelve 0 si el número está dentro del rango
// Devuelve -1 si el número está fuera del rango
int LeerEnteroRango(int* min, int* max, int* numero);
void ComprobarRango();


// Ejercicio 4

// El usuario introduce un número n
// Se crea un array de largo n
// El usuario introduce n números
// Se imprime el array
// El usuario introduce un número
// Se le indica si el número está en el array

void TratarArray();
void ImprimirArray(int n, int array[n]);
int PerteneceArray(int n, int array[n], int num);

// El usuario introduce dos cadenas de caracteres
// Se imprimen ambas cadenas
// Se indica si son iguales o no
void TratarCadenas();
int CadenasIguales(char cadena1[256], char cadena2[256]);


// Ejercicio 5

// El usuario introduce un número n
// Se crea un array de largo n
// Se llena de números aleatorios
// Se imprime el array
// Se pide otro numero x al usuario
// Se expande o contrae el array según x
// Se imprime el array
void TratarArrayDinamico();


// Ejericio 6

// Se pide al usuario un texto
// Se escribe el texto en un fichero "texto.txt"
// Devuelve codigo de error si no se puede abrir el fichero
// Devuelve 0 si se ha escrito correctamente

// Se lee el fichero "texto.txt"
// Se imprime el numero de palabras y caracteres
// Devuelve codigo de error si no se puede abrir el fichero
// Devuelve 0 si se ha leido correctamente
void TratarArchivo();
int EscribirFichero(char* nombreArchivo);
int contarChars(char* nombreArchivo);
int contarPalabras(char* nombreArchivo);


// Ejercicio 7
void TratarBombo();

extern int error; 
typedef struct BomboRep* Bombo;
// Construye y devuelve un bombo vacío que puede contener un 
// máximo de max bolas. Si max<2 devuelve NULL y asigna 
// error=1. 

Bombo BomboCrea(int max); 
// Inserta una bola en el bombo b. 
// Si el bombo b está lleno devuelve -1 y asigna error=2, 
// en caso contrario devuelve 0. 

int BomboInserta(Bombo b, int bola); 
// Libera el bombo b. 

void BomboLibera(Bombo b); 
// Extrae y devuelve una bola del bombo b. 
// Si el bombo b está vacío devuelve -1 y asigna error=3. 

int BomboExtrae(Bombo b); 
// Devuelve 1 si el bombo b está vacío y 0 en caso contrario. 

int BomboVacia(Bombo b); 
// Devuelve el mensaje de error asociado a un código de error 
// del bombo b. 

char* BomboMensajeError(Bombo b, int codigoError); 


// Ejercicio 8


// Pedir al usuario un número n
// Pedir al usuario 2 numeros a y b tal que a < b y a y b son enteros positivos para declarar un rango
// Crear una estructura enlazada con n elementos
// Cada elemento tiene un número aleatorio en un rango y un puntero al siguiente
// Imprimir la lista
void TratarListaEnlazada();

typedef struct EstructuraRep* Estructura;

Estructura EstructuraCrea(int n, int a, int b);
void EstructuraImprime(Estructura e);
void PedirEntrada(int* n, int* a, int* b);
void EstructuraLibera(Estructura e);
void EstructuraEliminaRepetidos(Estructura e);
Estructura EstructuraConcatena(Estructura e1, Estructura e2);


#endif /* PARCIAL1_H */
