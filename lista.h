#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*para los datos de la linea de entrada*/
typedef struct NodoL NodoL;
typedef struct Lista_Linea Lista_Linea;

struct NodoL{
    int categoria;
    char* comando;
    char* sentencia;
    NodoL* siguiente;
};

struct Lista_Linea{
    NodoL* inicio;
};

#endif // LISTA_H_INCLUDED
