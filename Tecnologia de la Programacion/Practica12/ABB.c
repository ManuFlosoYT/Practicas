#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "ABB.h" 
#define STRING_LONG 100 

struct ABBRep 
{ 
    Elemento elem; 
    ABB izq, der; 
}; 

ABB ABBCrea() 
{ 
    return NULL; 
}

void ABBLibera(ABB a) 
{ 
    if (a==NULL) return; 
    ABBLibera(a->izq); 
    ABBLibera(a->der); 
    free(a); 
} 

int ABBPertenece(ABB a, Elemento e) 
{ 
    if (a==NULL) return 0; 
    if (e==a->elem) return 1; 
    if (e<a->elem) return ABBPertenece(a->izq,e); 
    else return ABBPertenece(a->der,e); 
}

void ABBInserta(ABB * a, Elemento e) 
{ 
    if ((*a)==NULL) 
    { 
        (*a) = malloc(sizeof(struct ABBRep)); 
        (*a)->elem = e; (*a)->izq = NULL; 
        (*a)->der = NULL; return; 
    } 
    
    if (e<(*a)->elem) ABBInserta(&((*a)->izq),e); 
    else if (e>(*a)->elem) ABBInserta(&((*a)->der),e); 
}

Elemento ABBSuprimeMin(ABB * a) 
{
    if ((*a)->izq==NULL) 
    { 
        int min=(*a)->elem; 
        ABB der = (*a)->der; 
        free(*a); 
        (*a)=der; 
        return min; 
    } 
    return ABBSuprimeMin(&((*a)->izq)); 
}

void ABBSuprime(ABB * a, Elemento e) 
{ 
    if ((*a) == NULL) return; 
    if (e < (*a)->elem) ABBSuprime(&((*a)->izq),e); 
    else if (e > (*a)->elem) ABBSuprime(&((*a)->der),e); 
    else if (((*a)->izq == NULL) && ((*a)->der == NULL))
    { 
        free(*a); 
        *a = NULL; 
    } 
    else if ((*a)->izq == NULL)
    { 
        ABB der = (*a)->der; 
        free(*a); 
        (*a) = der; 
    } 
    else if ((*a)->der == NULL)
    { 
        ABB izq = (*a)->izq; 
        free(*a); 
        (*a) = izq; 
    } 
    else (*a)->elem = ABBSuprimeMin(&((*a)->der)); 
}

char* ABBToString(char* s, ABB a) 
{ 
    if (a!=NULL) 
    { 
        ABBToString(s,a->izq); 
        char aux[STRING_LONG]; 
        sprintf(aux," %d",a->elem); 
        strcat(s,aux); 
        ABBToString(s,a->der); 
    } 
    return s; 
}

void InsertaTodos(ABB* a, ABB b)
{
    if (b != NULL)
    {
        ABBInserta(a, b->elem);
        InsertaTodos(a, b->izq);
        InsertaTodos(a, b->der);
    }
}

ABB ABBUnion(ABB a, ABB b)
{
    ABB c = ABBCrea();
    InsertaTodos(&c, a);
    InsertaTodos(&c, b);
    return c;
}

void AuxInterseccion(ABB a, ABB b, ABB* c)
{
    if (a != NULL && b != NULL)
    {
        if (ABBPertenece(b, a->elem))
        {
            ABBInserta(c, a->elem);
        }
        AuxInterseccion(a->izq, b, c);
        AuxInterseccion(a->der, b, c);
    }
}

ABB ABBInterseccion(ABB a, ABB b)
{
    ABB c = ABBCrea();
    AuxInterseccion(a, b, &c);
    return c;
}

void AuxDiferencia(ABB a, ABB b, ABB* c)
{
    if (a != NULL)
    {
        if (!ABBPertenece(b, a->elem))
        {
            ABBInserta(c, a->elem);
        }
        AuxDiferencia(a->izq, b, c);
        AuxDiferencia(a->der, b, c);
    }
}

ABB ABBDiferencia(ABB a, ABB b)
{
    ABB c = ABBCrea();
    AuxDiferencia(a, b, &c);
    AuxDiferencia(b, a, &c);
    return c;
}