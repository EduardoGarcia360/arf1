#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//----------------------------Declaracion para booleanos
typedef int bool;
#define true 1
#define false 0
//----------------------------Fin para booleanos

//----------------------------Estructuras
//1
struct s_disco{
    char nombre[50];
    char tam[10];
    char particiones[10];
    char puntero[10];
};


//----------------------------Fin de Estructuras

//2
void crear_disco(){
    struct s_disco disco;
    printf("\n========== creando disco ==========\n");
    printf("Ingrese lo que se le pide:\n");
    printf("Nombre para el disco:\n");
    scanf("%s", disco.nombre);
    printf("Una cantidad para el tamaño multiplo de 8\n");
    int tam;
    bool detener = false;
    while(detener != true){
        scanf("%i", &tam);
        if(tam == 0){
            while(tam == 0){
                printf("Error: ingresa un numero mayor a cero.\n");
                scanf("%i", &tam);
            }
            detener = true;
            printf("correcto.\n");
        }else{
            detener = true;
            printf("correcto de else.\n");
        }
    }
}

//1
void Menu(){
    int eleccion=0;
    do{
        printf("Ingrese linea de comando:\n");
        scanf("%d", &eleccion);
        switch(eleccion){
            case 1:
                crear_disco();
            break;
        }
    }while(eleccion != 5);
}

int main(int argc, char **argv) {
    //entra aqui para cargar todo
    Menu();
    //cuando termina regresa a este punto
    printf("\n");
    printf("Finalizo el programa.");
    printf("\n");
    return 0;
}
