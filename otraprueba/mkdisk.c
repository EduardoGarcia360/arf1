#include "mkdisk.h"
#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void proceso_mkdisk(Lista* lista, int nueva_linea){
    switch(nueva_linea){
    case 0:
        printf("ingrese otra linea alv\n");
        char tmp[50];
        strcpy(tmp, lista->inicio->sentencia);
        int i=0;
        int car;
        while(tmp[i]!=NULL){
                printf("entro en while\n");
            car = tmp[i];
            printf("-%c\n", car);
            i++;
        }
        break;
    default:
        break;
    }
}
