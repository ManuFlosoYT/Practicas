/**
 * @file Practica7.h
 * @brief This file defines the interface for a "Bombo" data structure, which simulates a lottery drum.
 *
 * The Bombo data structure allows for the creation, manipulation, and extraction of balls from a virtual drum.
 * It provides functions for creating a Bombo, inserting balls, extracting balls, checking if the Bombo is empty,
 * and freeing the Bombo's memory. Error handling is included, with specific error codes and messages.
 */


#ifndef PRACTICA7_H_INCLUDED 
#define PRACTICA7_H_INCLUDED 
extern int error; 
typedef struct BomboRep* Bombo; 
// Construye y devuelve un bombo vacío que puede contener un 
// máximo de max bolas. Si max<2 devuelve NULL y asigna 
// error=1. 

Bombo BomboCrea(int max); // Inserta una bola en el bombo b. 
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

#endif