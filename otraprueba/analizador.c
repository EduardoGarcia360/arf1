#include "analizador.h"
#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* concat(char* destino, char* letra);// metodo para concatenar

/*
primera parte del analisis para validar si la linea ingresada
pertenece a mkdisk o rmdisk
*/
void analizar(){
    //Lista* mi_lista = (Lista*)malloc(sizeof(Lista));

	printf("Introduce linea de comando. (max. 200 carac.):\n");
    char linea[200];
	scanf("%[^\n]s", &linea);
	printf("la linea es %s\n", linea);

	int pos=0, estado=0;
	char* comando="";
	int caracter;

	while(linea[pos] != NULL){
	    caracter = linea[pos];
	    printf("%c\n", caracter);
	    switch(estado){
        case 0:
            if(islower(caracter)||isupper(caracter)){
                estado=1;
            }
            break;
        case 1:
            if(islower(caracter)||isupper(caracter)){
                estado=1;
            }else if(isspace(caracter)){
                estado=2;
            }
            break;
        default:
            printf("Error al analizar cadena, comando desconocido.\n");
            break;
	    }//fin switch

	    //== se valida el estado
	    if(estado==2){
	        printf("comando: %c\n", caracter);
	    }else{
	        if(isdigit(caracter)){
	            //en esta parte no puede haber numeros ya que se busca determinar a que tipo de comando pertenece.
                printf("Error al analizar cadena, comando desconocido.\n");
                break;
	        }else{
	            comando=concat(comando, &caracter);
                printf("concatenado: %s\n", comando);
	        }
	    }
	    pos++;
	}

}

char* concat(char* destino, char* letra){
    char* resultado = malloc(strlen(destino)+strlen(letra)+1);
    strcpy(resultado, destino);
    strcat(resultado, letra);
    return resultado;
}
