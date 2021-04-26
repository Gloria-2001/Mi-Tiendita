#include "product.h"

Product *createProduct(Article a){
    Product *nueProduct;
    nueProduct = (Product*)malloc(sizeof(Product));
    nueProduct->article = a;
    nueProduct->next = NULL;
    return nueProduct;
}