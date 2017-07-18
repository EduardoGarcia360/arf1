#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analizador.h"
void menu_general();

int main()
{
    menu_general();
    return 0;
}

void menu_general(){
    int val;
    char* entrada = (char*)malloc(sizeof(char*));
    do{
        printf("MENU\n1. Linea de comando.\n2. Cargar Archivo.\n3. Salir\n#=>");
        val=0;
        scanf("%i", &val);
        switch(val){
            case 1:
                printf("\nIngresa un comando:\n");
                fgets(entrada, 200, stdin);
                analizar_linea(entrada);
            break;
            case 2:
                analizar_archivo();
            break;
            case 3:
                printf("\nFinalizando programa.\n");
            break;
            default:
                printf("\nError: Opcion no valida!\n");
                val=0;
            break;
        }
    }while(val != 3);
    free(entrada);
}






