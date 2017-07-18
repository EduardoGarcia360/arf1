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
    int val=0;
    char* entrada = (char*)malloc(sizeof(char*));
    do{
        printf("MENU\n1. Linea de comando.\n2. Cargar Archivo.\n3. Salir\n#=>");

        scanf("%i", &val);
        switch(val){
            case 1:
                printf("\n=======case 1\n");
                fgets(entrada, 200, stdin);
                analizar_linea(entrada);

            break;
            case 2:
                printf("\n=======case 2\n");
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
        //val = 0;
    }while(val != 3);
    free(entrada);
}










