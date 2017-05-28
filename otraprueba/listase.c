#include "listase.h"
#include <stdlib.h>
#include <stdio.h>
int cima = 0;

NodoL* crearnodo(char* d){
	NodoL* nodo = (NodoL*)malloc(sizeof(NodoL));
	nodo->dato = d;
	nodo->siguiente = NULL;
	return nodo;
}

void insertarFinal(Lista* lista, char* d){
	NodoL* nuevo = crearnodo(d);
	if(cima == 1){
		NodoL* aux = lista->inicio;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
	}else{
		lista->inicio = nuevo;
		cima = 1;
	}
}

void mostrarLista(Lista* lista){
	NodoL* actual = lista->inicio;
	char* linea;
	while(actual != NULL){
		linea = actual->dato;
		printf("[%s]->", linea);
		actual = actual->siguiente;
	}
}
