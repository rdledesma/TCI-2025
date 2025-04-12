#include <stdio.h>
#include <stdlib.h>
#include "string.h"


// ==========================
// Estructura tData
// ==========================

#define STR 1
#define SET 2
#define LIST 3

// Declaración anticipada para usar en la unión

typedef struct dataType {
    int nodeType; // Tipo de nodo: STR, SET, LIST
    union {
        str strData; // Si nodeType == STR

        struct {
            struct dataType* data; // Contenido (otro tData)
            struct dataType* next; // Siguiente nodo en la lista
        };
    };
} dataType;

typedef dataType* tData;

// =========
// Funciones para trabajar con tData
// =========

// Crea un nodo tipo STR con contenido de texto
tData createStrNode(const char* texto) {
    tData nodo = (tData)malloc(sizeof(dataType));
    nodo->nodeType = STR;
    nodo->strData = load2(texto);
    return nodo;
}

// Crea un nodo tipo LIST que contiene un nodo STR

/*
Ahora vamos a crear Nodos que permiten crear listas de nodos 
(los de tipo str no permiten eso).
Al crear varios de estos y enlazarlos con .next, 
vamos a poder recorrerlos como cualquier lista:
*/
tData createListNode(tData contenido) {
    tData nodo = (tData)malloc(sizeof(dataType)); // Reserva memoria para un nodo tData
    nodo->nodeType = LIST;  // Indica que este nodo es de tipo LIST
    nodo->data = contenido; // Guarda el contenido (esto puede ser un nodo STR, otro LIST o un SET)
    nodo->next = NULL; // Inicializa el puntero al siguiente nodo como NULL
    return nodo;
}

// Agrega un nodo al final de la lista
//En los diversos lenguajes el concatenar elementos a la lista es realizado
//por una función llamada push 
tData push(tData lista, tData nuevoNodo) {    
    if (lista){         // Si la lista está vacía será igual a NULL, entonces el if devolverá falso
        tData temp = lista;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
        return lista;
    }
    else{
        return nuevoNodo;
    }
      
    
}


// Agrega un nodo al final de la lista
/*tData push(tData lista, tData nuevoNodo) {
    
    if (!lista) return nuevoNodo; // Si la lista está vacía
    tData temp = lista;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = nuevoNodo;
    return lista;
}
*/






// Imprime una lista de cadenas
void printList(tData lista) {
    printf("[ ");
    while (lista) {
        
        if (lista->nodeType == LIST && lista->data && lista->data->nodeType == STR) {
            print(lista->data->strData);  // imprime el str
            printf(" ");
        }
        lista = lista->next;
    }
    printf(" ]");
    //printf("NULL\n");
}

// ==========================
// Main
// ==========================

int main() {
    // Crear lista vacía
    tData lista = NULL;
    tData lista2 = NULL;

    // Crear nodos STR y envolverlos como LIST
    tData palabra1 = createListNode(createStrNode("hola"));
    tData palabra2 = createListNode(createStrNode("mundo"));
    tData palabra3 = createListNode(createStrNode("arboles"));

    // Agregar nodos a la lista
    lista = push(lista, palabra1);
    lista = push(lista, palabra2);
    lista = push(lista, palabra3);

    // Imprimir lista
    //printf("Contenido de la lista:\n");

    printf("\n");
    printList(lista);
    printf("\n");

    lista2 = push(lista2, createListNode(createStrNode("Elemento de L2")));
    printf("\n");
    printList(lista2);
    printf("\n\n");


    lista = push(lista, lista2);
    printf("Contenido de las listas concatenadas:\n");
    printList(lista);
    printf("\n");
    return 0;
}
