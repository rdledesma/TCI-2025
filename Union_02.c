#include <stdio.h>
#include <stdlib.h>

// Definimos una unión para almacenar enteros o caracteres
union Dato {
    int num;
    char letra;
};

// Definimos un nodo para la lista enlazada
struct Nodo {
    union Dato dato;  // Puede ser un entero o un carácter
    int esEntero;     // Indicador: 1 si es entero, 0 si es char
    struct Nodo* siguiente;
};

// Función para crear un nodo con un entero
struct Nodo* crearNodoEntero(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato.num = valor;
    nuevo->esEntero = 1; // Es un entero
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para crear un nodo con un carácter
struct Nodo* crearNodoChar(char valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato.letra = valor;
    nuevo->esEntero = 0; // Es un char
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->esEntero)
            printf("Entero: %d\n", actual->dato.num);
        else
            printf("Char: %c\n", actual->dato.letra);
        actual = actual->siguiente;
    }
}

// Función para liberar memoria
void liberarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

int main() {
    // Crear lista combinada de enteros y caracteres
    struct Nodo* cabeza = crearNodoEntero(10);
    cabeza->siguiente = crearNodoChar('A');
    cabeza->siguiente->siguiente = crearNodoEntero(20);
    cabeza->siguiente->siguiente->siguiente = crearNodoChar('B');

    // Imprimir lista
    imprimirLista(cabeza);

    // Liberar memoria
    liberarLista(cabeza);

    return 0;
}

