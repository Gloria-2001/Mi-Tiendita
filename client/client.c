#include "client.h"

int indexClient(Client *c){
    int opc, sgIn;
    system("clear");
    initCart(&cart);
    printf("Bienvenido, que desea hacer?\n");
    printf("\t[1] Iniciar sesion\n");
    printf("\t[2] Crear cuenta\n");
    printf("Opcion: ");
    scanf("%d", &opc);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);

    if(opc == 1){
        system("clear");
        printf("\n\tIniciar sesion\n");
        inputClient(c);
        return signIn(c->username, c->password, "../database/clients.csv");
    }else{
        system("clear");
        printf("\n\tCrear cuenta\n");
        return signUp("../database/clients.csv", c->username, c->password);
    }

    return 0;
}

void inputClient(Client *c){
    printf("Ingrese los siguientes datos:\n");
    
    printf("Usuario: ");
    scanf("%[^\n]s", c->username);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);

    printf("Password: ");
    scanf("%[^\n]s", c->password);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);
}

void addCart(Cart *c){
    Article art;
    strcpy(art.name, "Algo");
    art.price = 129.88;
    strcpy(art.description, "Es algo muy lindo para regalar");
    addBack(c, art);
}