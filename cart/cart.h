#include "../product/product.h"

typedef struct Cart{
    Product *fist;
    Product *last;
    int size;
}Cart;

void initCart(Cart *c);
int isEmpty(Cart *c);
void add(Cart *c, Article a, int index);
void addBack(Cart *c, Article a);
void showCart(Cart *c);