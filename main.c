#include "string.h"
#include <stdio.h>
#include "list.h"


int main(){

    str str1, str2, str3, listaStr;
    str1 = load2("ola la ");
    str2 = load2("bola");
    
    str3 = beforeToken(str2, 'b');


    //print(str1);
    print(str3);
    //printf("\n");
    //list l1;
    //l1 = createList();

    //append(&l1, str1);
    //append(&l1, str2);
    //show(l1);    



    //listaStr = toStr(l1);

    //print(listaStr);
    printf("\n");
  
}

