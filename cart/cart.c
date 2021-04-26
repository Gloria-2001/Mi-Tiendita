#include "cart.h"

void initCart(Cart *c){
    c->fist = NULL;
    c->last = NULL;
    c->size = 0;
}

int isEmpty(Cart *c){
    if(c->size == 0)
        return 1;
    if(c->fist == NULL && c->last == NULL)
        return 1;
    return 0;
}

void add(Cart *c, Article a, int index){
    Product *nuevo = createProduct(a);
    Product *aux;
    int i;
    if(isEmpty(c)){
        c->fist = nuevo;
        c->last = nuevo;
    }else{
        if(index == 0){
            nuevo->next = c->fist;
            c->fist = nuevo;
        }else if(index > c->size){
            c->last->next = nuevo;
            c->last = nuevo;
        }else{
            aux = c->fist;
            i=1;
            do{
                if(i == index){
                    nuevo->next = aux->next;
                    aux->next = nuevo;
                    break;
                }
                aux = aux->next;
                i++;
            }while(aux!=NULL);
        }
    }
    c->size++;
}

void addBack(Cart *c, Article a){
    Product *nuevo = createProduct(a);
    if(isEmpty(c)){
        c->fist = nuevo;
        c->last = nuevo;
    }else{
        c->last->next = nuevo;
        c->last = nuevo;
    }
    c->size++;
}

void showCart(Cart *c){
    Product *aux = c->fist;
    do{
        printArticle(aux->article);
        aux = aux->next;
    }while(aux != NULL);
    printf("\n");
}