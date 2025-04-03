#include <stdio.h>

union Dato {
    int i;
    float f;
    char c;
};

int main() {
    union Dato valor;
    
    valor.i = 10;
    printf("Entero: %d\n", valor.i);

    valor.f = 3.14;  // Ahora, sobrescribe la memoria anterior
    printf("Flotante: %.2f\n", valor.f);

    valor.c = 'A';  // Nuevamente, sobrescribe la memoria
    printf("Carácter: %c\n", valor.c);

    return 0;
}


/* 

el tipo de dato union es una estructura especial que permite 
almacenar diferentes tipos de datos en la misma ubicación de memoria. 

A diferencia de struct, donde cada miembro tiene su propia dirección de memoria, 
en una union, todos los miembros comparten el mismo espacio de memoria.
*/

/*Tener en cuenta */

/*

    Uso de memoria eficiente:

        La union ocupa el tamaño del miembro más grande.

        En el ejemplo, si int ocupa 4 bytes, float 4 bytes y char 1 byte, la union ocupará 4 bytes (el tamaño máximo entre sus miembros).

    Solo se puede almacenar un valor a la vez:

        Como todos los miembros comparten la misma memoria, cambiar un valor sobrescribe el anterior.

    Acceder a un valor después de sobrescribirlo puede causar resultados inesperados:

        En el código, al asignar valor.f = 3.14, la memoria que contenía valor.i = 10 es reemplazada.

        Luego, al asignar valor.c = 'A', se sobrescribe nuevamente.

*/
