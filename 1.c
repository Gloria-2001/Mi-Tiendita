#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
const int MAX = 5;
 
typedef struct member_t {
    char Name[8];
    char ID[8];
    int PWD;
    char Brand[8];
} member_s;
 
member_s* pMember = 0;
 
int nIndex = -1;
 
void save()
{
    FILE* fp = fopen("D:\\SO\\database.txt", "at");
    if(fp)
    {
        fputs(pMember[nIndex].Name,fp);
        fputs(",",fp);
        fputs(pMember[nIndex].ID,fp);
        fputs(",",fp);
        fprintf(fp,"%d",pMember[nIndex].PWD);
        fputs(",",fp);
        fputs(pMember[nIndex].Brand,fp);
        fputs("\n",fp);
        fclose(fp);
        printf("Gudardado\n");
    } else
    {
        printf("No guardado\n");
    }
}

void join()
{
    if(++nIndex >= MAX) 
    {
        printf("No se puede ingresar mas\n");
        nIndex = MAX-1;
    }
    else
    {
        pMember = (member_s*)realloc(pMember, sizeof(member_s) * (nIndex+1) );
        printf("Ingresa tus datos correspondientes(%d/%d)\n", nIndex+1, MAX);
        printf("Nombre : "); scanf("%s",pMember[nIndex].Name );
        printf("ID : "); scanf("%s",pMember[nIndex].ID );
        printf("PWD : "); scanf("%d",&pMember[nIndex].PWD );
        printf("Nombre de Brand: "); scanf("%s",pMember[nIndex].Brand );
 
        save();
    }
}
 
void login()
{
    char nID[8];
    int nPWD;
    printf("ID : "); scanf("%s", nID);
    printf("PWD : "); scanf("%d", &nPWD);
 
    for(int i = 0 ; i <= nIndex ; i++)
    {
        if(!strcmp(nID, pMember[i].ID))
        {
            if(nPWD == pMember[i].PWD)
            {
                printf("Sesion iniciado\n");
                return;
            }
            else
            {
                printf("Contrasena incorrecto\n");
                return;
            }
        }
    }
 
    printf("No existe ID\n");
}
 
int main()
{
    int a;
    while(1)
    {
        printf("Escribe 1 para nuevo ingreso, 2 para iniciar sesion (99 para salir) : ");
        scanf("%d",&a);
        switch(a)
        {
        case 1: join(); break;
        case 2: login(); break;
        case 99: return 0;
        default:
            printf("Mal numero\n");
        }
    }
 
    return 0;
}