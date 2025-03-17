#include <stdio.h>

#define TM 20  // Tamaño máximo de cada cadena
#define NUM_CADENAS 3  // Número de cadenas a leer

// Definimos el tipo tCadena para cadenas de tamaño TM
typedef char tCadena[TM];

// Función leeCad para leer una cadena desde la entrada
void leeCad(tCadena cad, int tam) {
    int j;
    char c;
    j = 0;  // Comienza la lectura de caracteres del buffer
    c = getchar();
    while (c != EOF && c != '\n' && j < tam - 1) {
        cad[j] = c;
        j++;
        c = getchar();
    }
    cad[j] = '\0';  // Termina la cadena con el carácter nulo
    while (c != EOF && c != '\n')  // Se vacía el buffer si queda algo
        c = getchar();
}

int main() {
    tCadena cadenas[NUM_CADENAS];  // Array de NUM_CADENAS cadenas
    int i;

    // Leer las cadenas
    for (i = 0; i < NUM_CADENAS; i++) {
        printf("Ingrese la cadena %d: ", i + 1);
        leeCad(cadenas[i], TM);
    }

    // Mostrar las cadenas
    printf("\nLas cadenas ingresadas son:\n");
    for (i = 0; i < NUM_CADENAS; i++) {
        printf("Cadena %d: %s\n", i + 1, cadenas[i]);
    }

    return 0;
}