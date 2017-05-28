#ifndef LISTASE_H
#define LISTASE_H

typedef struct NodoL NodoL;
typedef struct Lista Lista;

struct NodoL{
	char* dato;
	NodoL* siguiente;
};

struct Lista{
	NodoL* inicio;
};

void insertarFinal(Lista* lista, char* d);
void mostrarLista(Lista* lista);

#endif // LISTASE_H_INCLUDED
