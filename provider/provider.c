#include "provider.h"

int indexProvider(Provider *p){
    int opc;
    system("clear");
    printf("Bienvenido proveedor, que desea hacer?\n");
    printf("\t[1] Iniciar sesion\n");
    printf("\t[2] Crear cuenta\n");
    printf("Opcion: ");
    scanf("%d", &opc);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);

    if(opc == 1){
        system("clear");
        printf("\n\tIniciar sesion\n");
        inputProvider(p);
        return signIn(p->username, p->password, "../database/providers.csv");
    }else{
        system("clear");
        printf("\n\tCrear cuenta\n");
        return signUp("../database/providers.csv", p->username, p->password);
    }

    return 0;
}

void inputProvider(Provider *p){
    printf("Ingrese los siguientes datos:\n");
    
    printf("Usuario: ");
    scanf("%[^\n]s", p->username);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);

    printf("Password: ");
    scanf("%[^\n]s", p->password);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);
}