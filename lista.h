#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "libro.h"

typedef struct Nodo 
{
    Libro libro;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo *cabeza;
    int longitud;
} Lista;

Nodo *CrearNodo(Libro *libro);
Libro *Obtener(int n, Lista *lista);

void DestruirNodo(Nodo *nodo);
void InsertarPrincipio(Lista *lista, Libro *libro);
void InsertarFinal(Lista *lista, Libro *libro);
void InsertarDespues(int n, Lista *lista, Libro *libro);
void EliminarPrincipio(Lista  *lista);
void EliminarUltimo(Lista *lista);
void EliminarElemento(int n, Lista *lista);

int Contar(Lista *lista);
int Estavacia(Lista *lista);




#endif