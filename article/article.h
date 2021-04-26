#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Article{
    char name[100];
    float price;
    char description[100];
}Article;

void printArticle(Article a);
char* getDescription(Article a);