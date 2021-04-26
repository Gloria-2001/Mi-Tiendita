#include "../article/article.h"

typedef struct Product{
    Article article;
    struct Product* next;
}Product;

Product *createProduct(Article a);