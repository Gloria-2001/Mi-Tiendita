#include "../client/client.h"
#include "../provider/provider.h"

Client cliente;
Provider proveedor;
Cart carrito;

int main(int argc, char* argv[]){
    int ind = 0, flag = 1;
    char *user;
    srand(time(NULL));

    if(argc == 2 && strcmp(argv[1], "-p") == 0){
        ind = indexProvider(&proveedor);
        user = proveedor.username;
        flag = 0;
    }else{
        ind = indexClient(&cliente);
        user = cliente.username;
    }

    if(ind){
        printf("\n\tBienvenid@ %s\n", user);
        if(flag){
            initCart(&carrito);
            char op;
            showProducts();
            printf("\nQuieres agregar algo al carrito?\n");
            printf("\t[S]i\n\t[N]o\n");
            printf("Opción: ");
            scanf("%c",&op);
            printf("\n");
            if(op == 'S' || op == 's'){
                addCart(&carrito);
                addCart(&carrito);
                showCart(&carrito);
            }
        }
    }else{
        printf("\nAlgo salio mal\n");
    }

    printf("\nFin del programa\n");

    return 0;
}