#include "../utils/utils.h"
//#include "../cart/cart.h"

//Cart cart;

typedef struct Client{
    char username[50];
    char password[15];
}Client;

int indexClient(Client *c);
void inputClient(Client *c);
void initClient(Client *c);
//void addCart(Cart *c);
//void goMarket();