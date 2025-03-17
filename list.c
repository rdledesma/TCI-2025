#include "list.h"
#include <stdio.h>
#include <stdlib.h>


list createList(){
    list l = (list)malloc(sizeof(TNodoList));
    l = NULL;
    return l;
}

void append(list* l, str s){
    list new, aux;
    new = (list)malloc(sizeof(TNodoList));
    new->data = s;
    new->sig = NULL;

    if(*l == NULL){
        *l = new;
    }
    else
    {
        aux = *l;
        
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = new;
        
    }
}


void show(list l){
    if (l == NULL) {
        printf("La lista está vacía.\n");
    } else {
        printf("[ ");
        while (l->sig != NULL) {
            print(l->data);
            printf(", ");
            l = l->sig;
        }
        print(l->data);

        printf(" ]");
       printf("\n");
    }
}

str toStr(list l){
    str aux,s;

    aux = create();
    s = create();


    if (l == NULL) {
        return s;
    } else {
        
        while (l != NULL) {
            //aux = load2(l->data);
            
            
            s = concat(s, l->data);
            l = l->sig;
        }
 

        return s;
       //printf("NULL\n");
    }
}

