#ifndef LIST_H
#define LIST_H

#include "string.h"




typedef struct NodoList {
    str data;
    struct NodoList* sig;
} TNodoList;

typedef TNodoList* list;







// Prototipos de funciones
list createList();
void show(list);
void append(list*, str);
str toStr(list);
list StrToList(str);


/*
void cargarLista(TPtr*, int);
void agregarCabecera(TPtr*, int);
void agregarFin(TPtr*, int);
void muestraLista(TPtr);
void aniadirEnPosicionP(TPtr*, int, int);
void eliminarPares(TPtr*);
void aniadirCerosPrimos(TPtr*);
void aniadirCerosPrimos2(TPtr*);
*/

#endif
