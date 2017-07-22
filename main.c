#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analizador.h"
#include "leer_archivo.h"
void menu_general();
void analizar_linea(char* entrada);

int main()
{
    menu_general();
    return 0;
}

void menu_general(){
    char* entrada = malloc(200);
    do{
        printf("\n*Introduce linea de comando. (max. 200 caracteres):\n");
        printf("*Para cerrar la aplicacion escriba: salir\n");
        fgets(entrada, 200, stdin);
        if(strcasecmp(entrada, "salir\n")==0)
            break;
        analizar_linea(entrada);
    }while(strcasecmp("salir\n", entrada) != 0);
    free(entrada);
}

/*metodo para saber si debe irse al analizador general o
al metodo para leer un archivo*/
void analizar_linea(char* entrada){
    entrada=quitar_salto(entrada);
    char linea[200];
    strcpy(linea, entrada);
    int pos=0, detener=0, correcto=0, caracter;
    char* comando="";
    while(detener==0){
        caracter=linea[pos];
        if(isspace(caracter) || linea[pos+1]==NULL){
            /*se detiene cuando:
            1. mkdisk $size..
            2. exec $path..
            encuentra el primer espacio despues del comando o llegue a nulo*/
            detener=1;
            correcto=1;
        }else if(isalpha(caracter)){
            comando=concatenar(comando, &caracter);
        }else{
            //no puede venir ningun otro caracter que no sea letra
            printf("\nError:\nDebes ingresar un comando valido.\n\n");
            detener=1;
        }

        pos++;
    }

    switch(correcto){
        case 1:
            if(strcasecmp("exec", comando)==0){
                printf("\nde var. comando: %s\n", comando);
                validar_exec(entrada);
            }else{
                analizador_general(linea);
            }
        break;
    }
}





