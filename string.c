#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"




str create(){
	str new;
	new = (str)malloc(sizeof(TNodoStr));
	new = NULL;
    return new;
}

str load(){
	str  cadena;


	char m;
	m = getchar();

	str new, aux;

	new = (str)malloc(sizeof(TNodoStr));
	new->character = m;
	new->sig = NULL;

	cadena = (str)malloc(sizeof(TNodoStr));
	cadena = NULL;


	while(m!=EOF && m!='\n'){

		if(cadena == NULL){
			cadena = new;
		}

		else{
			aux = cadena;
        
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = new;
		}

		
		m=getchar();
		new = (str)malloc(sizeof(TNodoStr));
		new->character = m;
		new->sig = NULL;
	}

	return cadena;
};



str load2(const char *d) {
    str new = NULL, caracter = NULL, aux = NULL;

    while (*d != '\0') {
        // Reservar memoria para el nuevo nodo
        caracter = (str)malloc(sizeof(TNodoStr));
        if (caracter == NULL) {
            printf("Error: No se pudo asignar memoria.\n");
            return NULL;
        }

        // Asignar valores
        caracter->character = *d;
        caracter->sig = NULL;

        // Insertar en la lista
        if (new == NULL) {
            new = caracter;
        } else {
            aux = new;
            while (aux->sig != NULL) {  // Quitar el ; del while
                aux = aux->sig;
            }
            aux->sig = caracter;
        }

        d++;  // Avanza al siguiente carácter
    }


    return new;
}



str concat(str s1, str s2){
	str aux, aux2;
	aux = (str)malloc(sizeof(TNodoStr));
	aux = NULL;

	if(s1 == NULL){
		if(s2 == NULL){
			return aux;
		}
		else return s2;
	}else{
		if (s2 == NULL){
			return s1;
		}
		else{

			aux = s1;
			while (aux->sig!=NULL)
			{
				aux = aux->sig;
			} 

			aux->sig = s2;	

			return s1;
		}
	}



}


str beforeToken(str s, char token){
	str aux, item;
	aux = create();

	item = (str)malloc(sizeof(TNodoStr));
	item = NULL;

	if(s == NULL){
		aux;
	}
	else{
		aux = s;
		while (s->sig!=NULL & s->sig->character!=token)
		{	
		    printf("Iterando \n");

			s = s->sig;
		}
		s->sig = NULL;
		
		return aux;
	}

}

void print(str cadena){
    
	if(cadena == NULL){
		printf("\n is empty\n");
	}
	else{
		
		while (cadena!=NULL)
		{
			printf("%c",cadena->character);
			cadena = cadena->sig;
		}
	
	}
}

