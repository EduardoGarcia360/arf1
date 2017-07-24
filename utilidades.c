#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

char* concatenar(char* destino, char* letra){
    char* r = malloc(strlen(destino)+strlen(letra)+1);
    strcpy(r, destino);
    strcat(r, letra);
    return r;
}

int validar_nombre(char* nombre){
    int correcto=0;
    char a_nom[15];
    strcpy(a_nom, nombre);
    int caracter, pos=0, estado=0;
    while(a_nom[pos] != NULL){
        caracter=a_nom[pos];
        switch(estado){
            case 0:
                if(isalpha(caracter)){
                    estado=1;
                }else{
                    estado=99;
                }
            break;
            case 1:
                if(isalpha(caracter)){
                    estado=1;
                }else if(caracter=='_'){
                    estado=2;
                }else if(caracter=='.'){
                    estado=4;
                }else{
                    estado=99;
                }
            break;
            case 2:
                if(isdigit(caracter)){
                    estado=3;
                }else{
                    estado=99;
                }
            break;
            case 3:
                if(isdigit(caracter)){
                    estado=3;
                }else if(caracter=='.'){
                    estado=4;
                }else{
                    estado=99;
                }
            break;
            case 4:
                if(strcmp("d", &caracter)==0){
                    estado=5;
                }else{
                    estado=99;
                }
            break;
            case 5:
                if(strcmp("s", &caracter)==0){
                    estado=6;
                }else{
                    estado=99;
                }
            break;
            case 6:
                if(strcmp("k", &caracter)==0){
                    correcto=1;
                }else{
                    correcto=0;
                    estado=99;
                }
            break;
        }

        if(estado==99){
            printf("\n==>Error:\n");
            printf("El nombre: '%s'\n", nombre);
            printf("no cumple con los requisitos para ser valida.\n========\n");
            break;
        }
        pos++;
    }

    return correcto;
}

int validar_ruta_nombre(char* ruta){
    int correcto=0;
    char a_ruta[100];
    strcpy(a_ruta, ruta);
    int caracter, pos=0, estado=0;
    while(a_ruta[pos] != NULL){
        caracter=a_ruta[pos];
        switch(estado){
            case 0:
                if(caracter=='"'){
                    estado=1;
                }else{
                    estado=99;
                }
            break;
            case 1:
                if(caracter=='/'){
                    estado=2;
                }else{
                    estado=99;
                }
            break;
            case 2:
                if(isalpha(caracter)){
                    estado=3;
                }else{
                    estado=99;
                }
            break;
            case 3:
                if(isalpha(caracter)){
                    estado=3;
                }else if(caracter=='/'){
                    estado=4;
                }else if(caracter=='_'){
                    estado=6;
                }else if(caracter=='.'){
                    estado=8;
                }else{
                    estado=99;
                }
            break;
            case 4:
                if(isalpha(caracter)){
                    estado=3;
                }else if(caracter=='"'){
                    estado=5;
                    correcto=1;
                }else{
                    estado=99;
                }
            break;
            case 5:
                if(a_ruta[pos+1]==NULL){
                    correcto=1;
                }else{
                    estado=99;
                    correcto=0;
                }
            break;
            case 6:
                if(isdigit(caracter)){
                    estado=7;
                }else{
                    estado=99;
                }
            break;
            case 7:
                if(isdigit(caracter)){
                    estado=7;
                }else if(caracter=='.'){
                    estado=8;
                }else{
                    estado=99;
                }
            break;
            case 8:
                if(strcmp("t", &caracter)==0){
                    estado=9;
                }else{
                    estado=99;
                }
            break;
            case 9:
                if(strcmp("x", &caracter)==0){
                    estado=10;
                }else{
                    estado=99;
                }
            break;
            case 10:
                if(strcmp("t", &caracter)==0){
                    estado=11;
                }else{
                    estado=99;
                }
            break;
            case 11:
                if(caracter=='"'){
                    estado=5;
                    correcto=1;
                }else{
                    estado=99;
                }
            break;
        }

        if(estado==99){
            printf("\n==>Error:\n");
            printf("La ruta: %s\n", ruta);
            printf("no cumple con los requisitos para ser valida.\n========\n");
            break;
        }

        pos++;
    }

    return correcto;
}

char* quitar_comillas(char* ruta){
    char aruta[50];
    strcpy(aruta, ruta);
    int pos=0, caracter;
    char* limpia="";
    while(aruta[pos]!=NULL){
        caracter=aruta[pos];
        if(caracter!='"'){
            limpia=concatenar(limpia, &caracter);
        }
        pos++;
    }
    return limpia;
}

char* quitar_salto(char* entrada){
    char aentrada[200];
    strcpy(aentrada, entrada);
    int pos=0, caracter, detener=0;
    char* limpia="";
    while(detener==0){
        caracter=aentrada[pos];
        if(caracter!='\n'){
            limpia=concatenar(limpia, &caracter);
        }else{
            detener=1;
        }
        pos++;
    }
    return limpia;
}

int confirmacion(char* mensaje){
    int d;
    printf("%s\n", mensaje);
    printf("Ingrese:\n1. Aceptar\t2. Cancelar\nEleccion: ");
    scanf("%d", &d);
    return d;
}
