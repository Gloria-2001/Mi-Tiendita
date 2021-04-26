#include "article.h"

void printArticle(Article a){
    printf("Nombre: %s\n", a.name);
    printf("\t$%5.2f MXN\n\n", a.price);
}