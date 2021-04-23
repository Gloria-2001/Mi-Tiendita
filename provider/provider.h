#include "../utils/utils.h"

typedef struct Provider{
    char username[50];
    char password[15];
}Provider;

int indexProvider(Provider *p);
void inputProvider(Provider *p);