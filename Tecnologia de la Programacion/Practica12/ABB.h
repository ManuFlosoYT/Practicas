#ifndef ABB_H_INCLUDED 
#define ABB_H_INCLUDED 
typedef struct ABBRep * ABB; 
typedef int Elemento; 
// Devuelve un nuevo árbol binario de búsqueda vacío. 
ABB ABBCrea(); 
// Libera la memoria asignada al árbol binario de búsqueda a. 
void ABBLibera(ABB a); 
// Devuelve 1 (true) si el elemento e pertenece al árbol binario de 
// búsqueda a, y 0 false) en caso contrario. 
int ABBPertenece(ABB a, Elemento e); 
// Inserta el elemento e en el árbol binario de búsqueda a. 
void ABBInserta(ABB * a, Elemento e); 
// Suprime el elemento e del árbol binario de búsqueda a. 
void ABBSuprime(ABB * a, Elemento e); 
// Devuelve un árbol binario de búsqueda que es la unión de los 
// árboles binarios de búsqueda a y b. 
ABB ABBUnion(ABB a, ABB b); 
// Devuelve un árbol binario de búsqueda que es la intersección de 
// los árboles binarios de búsqueda a y b. 
ABB ABBInterseccion(ABB a, ABB b); 
// Devuelve un árbol binario de búsqueda que es la diferencia de los 
// árboles binarios de búsqueda a y b. 
ABB ABBDiferencia(ABB a, ABB b); 
// Añade a la cadena apuntada por s los elementos del árbol binario a 
// en orden creciente y devuelve la dirección de la cadena. 
char* ABBToString(char * s, ABB a); 
#endif // ABB_H_INCLUDED