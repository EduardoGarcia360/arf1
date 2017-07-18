#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

void analizador_general(int caracter);

void analizar_archivo(){
    char ruta[200];
    printf("\nIngresa la ruta del archivo (.txt):\n");
    scanf("%s", ruta);

    FILE* archivo;

    archivo = fopen(ruta, "r");
    if(archivo == NULL){
        printf("\nNo existe el archivo en:\n%s", ruta);
    }else{
        int caracter;
        printf("\nLeyendo el archivo...\n");
        caracter = fgetc(archivo);
        while(caracter != EOF){
            analizador_general(caracter);
            caracter = fgetc(archivo);
        }
    }
    fclose(archivo);
}

void analizar_linea(char* entrada){
    //char* e = (char*)malloc(200);
    char e[200]="";
    //e="\n";
    fgets(e, 200, stdin);
    char linea[200];
    strcpy(linea, e);
    int pos=0, c;
    while(linea[pos]!=NULL){
        c=linea[pos];
        printf("%c\n", c);
        pos++;
    }
}

void analizador_general(int caracter){
    printf("%c\n", caracter);
}
