#include "leer_archivo.h"
#include "utilidades.h"
#include "analizador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void abrir_archivo(char* ruta);

/*recibe: exec $path=>"/home/algo/archivo.sh"
lo separa en:
-parametro: path
-sentencia: "/home/algo/archivo.sh"*/
void validar_exec(char* entrada){
    //printf("\n\nRecibe: '%s'", entrada);
    char linea[200];
    strcpy(linea, entrada);
    int pos=0, estado=0, correcto=0, detener=0, caracter;
    char* parametro="";
    char* sentencia="";
    while(detener==0){
        caracter=linea[pos];
        switch(estado){
            case 0:
                if(isalpha(caracter)){
                    estado=0;
                }else if(isspace(caracter)){
                    estado=1;
                }else{
                    detener=1;
                }
            break;
            case 1:
                if(caracter=='$'){
                    estado=2;
                }else{
                    detener=1;
                }
            break;
            case 2:
                if(isalpha(caracter)){
                    parametro=concatenar(parametro, &caracter);
                    estado=2;
                }else if(caracter=='='){
                    estado=3;
                }else{
                    detener=1;
                }
            break;
            case 3:
                if(caracter=='>'){
                    estado=4;
                }else{
                    detener=1;
                }
            break;
            case 4:
                if(linea[pos+1]==NULL){
                    detener=1;
                    correcto=1;
                }
                sentencia=concatenar(sentencia, &caracter);
            break;
        }
        pos++;
    }
    switch(correcto){
        case 0:
            printf("\n\nError:\nLinea de comando no valida.\n");
        break;
        case 1:
            if(strcasecmp("path", parametro)==0){
                int res = validar_ruta_nombre(sentencia);
                if(res==1){
                    char* ruta="";
                    ruta=quitar_comillas(sentencia);
                    abrir_archivo(ruta);
                }
            }else{
                printf("\n\nError:\nParametro '%s' incorrecto.\n", parametro);
            }
        break;
    }
}

void abrir_archivo(char* ruta){
    FILE* archivo;
    archivo = fopen(ruta, "r");
    if(archivo==NULL){
        printf("\n\nError:\nNo existe el archivo en:\n'%s'\n", ruta);
    }else{
        printf("\nLeyendo el archivo.....\n");
        char linea[200]="";
        while(fgets(linea, 200, archivo) != NULL){
            analizador_general(linea);
        }
        fclose(archivo);
    }
}












