#include "analizador.h"
#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* concat(char* destino, char* letra);// metodo para concatenar
char* limpiar();

/*
primera parte del analisis para validar si la linea ingresada
pertenece a mkdisk, rmdisk, etc. una vez encontrado el comando se continuara
leyendo la linea para encontrar el caracter \^ que es el que nos indicara
que hay otra linea de comando, al encontrarlo enviaremos una señal al metodo
correspondiente al comando ya previamente encontrado.
*/

void analizar(){
    //Lista* mi_lista = (Lista*)malloc(sizeof(Lista));

	printf("Introduce linea de comando. (max. 200 carac.):\n");
    char linea[200];
	scanf("%[^\n]s", &linea);
	printf("la linea es %s\n", linea);

	int pos=0, estado=0;
	char* tipo="";
	char* lexema="";
	char* comando="";
	char* parametro="";
	int categoria;
	int caracter;

	while(linea[pos] != NULL){
	    caracter = linea[pos];
	    //printf("%c\n", caracter);
	    switch(estado){
        case 0:
            if(isspace(caracter)){
                //con espacio se agrega el tipo: mkdisk &size...
                //el tipo seria: mkdisk.
                if(strcmp("mkdisk", lexema)==0){
                    printf("--Tipo: %s\n", lexema);
                    tipo=concat(tipo,lexema);
                    printf("de la variable tipo: %s\n", tipo);
                    lexema=limpiar();
                    estado=1;
                }else{
                    //si no es ningun tipo: mkdisk, rmdisk, etc es error
                    estado=99;
                }
            }else if(islower(caracter)||isupper(caracter)){
                caracter=tolower(caracter);
                lexema=concat(lexema, &caracter);
                estado=0;
            }else{
                //no puede venir numero en este punto: mk23disk &size..., o cualquier otro simbolo
                estado=99;
            }
            break;
        case 1:
            if(isspace(caracter)){
                estado=1;
            }else if(caracter=='&'){
                categoria=1;
                printf("categoria obligatorio\n");
                estado=2;
            }else if(caracter=='%'){
                categoria=2;
                estado=2;
            }else{
                estado=99;
            }
            break;
        case 2:
            if(isspace(caracter)){
                estado=2;
            }else if(islower(caracter)||isupper(caracter)){
                caracter=tolower(caracter);
                lexema=concat(lexema, &caracter);
                estado=2;
            }else if(caracter=='-'){
                estado=2;
            }else if(caracter=='>'){
                //comando escrito correctamente ej.: &size->32, &path->/home/.., etc.
                //comando serian: size, path,..
                comando=concat(comando, lexema);
                printf("variable comando: %s\n", comando);
                lexema=limpiar();
            }
            break;
        default:
            printf("Error al analizar cadena, comando desconocido.\n");
            estado=99;
            break;
	    }//fin switch

	    //---------------- estado de error..
	    if(estado==99){
            printf("Error al analizar la cadena formato no valido.\n");
            break;
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

char* limpiar(){
    char* d="";
    return d;
}
