#ifndef STRING_H
#define STRING_H




typedef struct Nodo {
    char character;
    struct Nodo* sig;
} TNodoStr;

typedef TNodoStr* str;






str create();
str load();
str load2(const char *);
void print(str);
str concat(str, str);

str beforeToken(str, char);


#endif
