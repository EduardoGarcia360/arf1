#ifndef LISTASE_H
#define LISTASE_H

typedef struct NodoL NodoL;
typedef struct Lista Lista;

struct NodoL{
    int categoria;//(1) obligatorio (2) opcional
    char* comando;//size, path, name, etc.
	char* sentencia;
	NodoL* siguiente;
};

struct Lista{
	NodoL* inicio;
};

void insertarFinal(Lista* lista, int categoria, char* comando, char* sentencia);
void mostrarLista(Lista* lista);

#endif // LISTASE_H_INCLUDED
