#include "utils.h"

int signIn(char *user, char *pass, char* myFile){
    FILE* clts = fopen(myFile, "r");
    char *token;
    char line[1024];
    int cmpPass, cmpUser;


    printf("\n");
    while (fgets(line, 1024, clts)){
        char *us, *pas;
        // Se hace un split, y se guarda en una variable
        token = strtok(line, ",");
        us = token;
        // Se hace un split, y se guarda en una variable
        token = strtok(NULL, ",");
        // Le quitamos el interlineado a las filas
        pas = strtok(token, "\n");

        // Se comparan el usuario y la contrasenia
        cmpPass = strcmp(pass, pas);
        cmpUser = strcmp(user, us);

        if(cmpPass == 0 && cmpUser == 0){
            system("clear");
            fclose(clts);
            return 1;
        }
    }
    printf("\n");
    printf("Usuario y/o contrasenia incorectos\n");
    fclose(clts);
    return 0;
}

int signUp(char* myFile, char *user, char *pass){
    FILE* clts = fopen(myFile, "a");
    char line[1024];
    printf("Ingrese los siguientes datos:\n");
    printf("Usuario: ");
    scanf("%[^\n]s", user);
    scanf("%c", &newline); // eat trailing newline
    fflush(stdin);
    if(inDB(user, myFile)){
        printf("El usuario ya existe\n");
        return 0;
    }
    randomPassword(pass,10);
    printf("Tu contrasenia es la siguiente:\n\t%s\nPor favor, guardalo.\n", pass);
    sprintf(line, "\n%s,%s", user, pass);
    fwrite(line, sizeof(char), strlen(line), clts);
    fclose(clts);
    return 1;
}

int inDB(char *user, char* myFile){
    FILE* clts = fopen(myFile, "r");
    char line[1024], *token;
    while (fgets(line, 1024, clts)){
        // Se hace un split, y se guarda en una variable
        token = strtok(line, ",");
        if(strcmp(user, token) == 0){
            fclose(clts);
            return 1;
        }
    }
    fclose(clts);
    return 0;
}

void randomPassword(char *pass, int n){
    char min[] = "abcdefghijklmnopqrstuvwxyz";
	char may[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char num[] = "0123456789";
    for(int i=0; i<n; i++){
        int e = (int)(rand() % 3+1);
        pass[i] = '\0';
		switch(e){
            case 1:
                pass[i]=min[rand() % 25+1];
            break;
            case 2:
                pass[i]=may[rand() % 25+1];
            break;
            case 3:
                pass[i]=num[rand() % 9+1];
            break;
        }
    }
}

void showProducts(){
    FILE* clts = fopen("../database/products.csv", "r");
    char line[1024], *token;
    char *prod;
    float prc;
    printf("\n\tProductos a la venta:\n");
    sprintf(line,"%s\t|\t%20s\t|\t%6s\n","No. producto","Producto","Precio");
    printf("%s",line);
    int t = strlen(line);
    for(int j=0; j<t+20; j++){
        printf("-");
    }
    printf("\n");
    int i=1;
    while (fgets(line, 1024, clts)){
        // Se hace un split, y se guarda en una variable
        token = strtok(line, ",");
        prod = token;
        token = strtok(NULL, ",");
        prc = atof(token);
        printf("%7d\t\t|\t%20s\t|\t%5.2f\n", i, prod, prc);
        i++;
    }
    fclose(clts);
}