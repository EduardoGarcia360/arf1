#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"
#include "analizador.h"

/*
recibe: mkdisk $size=>32 $path=>"/home/algo/" $name=>disco_43.dsk
se separa en tipo, comando y sentencia cada datos de los parametros
va en un nodo de la lista quedando:
-tipo: mkdisk
-lista s. enlazada: [size|32]->[path|"/home/algo/"]->[name|disco_43.dsk]
*/
void analizador_general(char linea[]){
    int caracter, pos=0, estado=0, correcto=0;
    while(linea[pos]!=NULL){
        caracter = linea[pos];
        printf("%c\n", caracter);
        pos++;
    }
}
