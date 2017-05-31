#include "analizador.h"
#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("======= Archivos proyecto 1 ========\n");

    //int eleccion;
    //do{
    /*
        printf("1. ingresar linea de comando.\n");
        printf("2. salir\n");

        if(scanf("%d", (&eleccion))==0){
            while (getchar() != '\n'){
                printf("Error, ingrese numero: \n");
                scanf("%d", (&eleccion));
            }
        }
        switch(eleccion){
        case 1:
            analizar();
            break;
        default:
            printf("Error cerrando.\n");
            eleccion=2;
            break;
        }
*/
    //}while(eleccion!=1);
/*
    Lista* mi_lista = (Lista*)malloc(sizeof(Lista));
    insertarFinal(mi_lista, 1, "size", "32");
	insertarFinal(mi_lista, 2, "unit","k");
	insertarFinal(mi_lista, 1, "path", "c:/tugfa");
	insertarFinal(mi_lista, 1, "name", "eltado.dsk");
	mostrarLista(mi_lista);
*/
    analizar();
    return 0;
}
