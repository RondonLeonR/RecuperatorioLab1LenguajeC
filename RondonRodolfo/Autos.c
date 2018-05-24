#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Propietarios.h"
#include "Autos.h"
#define TAMANIO 10
#define OCUP 1
#define LIB  -1

#define ALPHA_ROMEO 111
#define FERRARI 222
#define AUDI 333
#define OTRO 444
void eAutE_init( eAutosEstacionados listado[],int limite)
{
    int i;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIB;
        }
}
//Busco lugar libre, devuelvo el primero encontrado.
int eAutE_buscarLugarLibre(eAutosEstacionados listado[],int limite)
{
    int retorno = -1;
    int i;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIB)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}
//Devuelvo la siguiente posicion en el array, que este libre.
int eAutE_siguienteId(eAutosEstacionados listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUP)
            {
                if(listado[i].ID_Propietario>retorno)
                {
                    retorno=listado[i].ID_Propietario;
                    break;
                }
            }
        }
    }

    return retorno+1;
}

//Devulvo la posicion del id con los datos guardados en el.
int eAutE_buscarPorId(eAutosEstacionados listado[] ,int limite, int id)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(listado[i].ID_Auto==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void eAutE_mostrarUno(eAutosEstacionados parametro)
{
        /*if(parametro.marca==1){
            parametro.marca=A2500;
        }
        else if(parametro.marca==2){
            parametro.marca=MARCA2;
        }
        else if(parametro.marca==3){
            parametro.marca= MARCA3;
        }
        else{
            parametro.marca=MARCA4;
        }*/
     printf("       %d  --  %d  --  %s   \n",parametro.ID_Propietario,parametro.marca,parametro.patente);
}


void eAutE_inicializarUsuariosHardCode(eAutosEstacionados listados[])
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char paten[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {111,333,333,222,222,333,333,444,333,111};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    for(int j=0;j<=10;j++)
    {
        listados[j].ID_Auto=id[j];
        listados[j].estado = OCUP;
        strcpy(listados[j].patente,paten[j]);
        listados[j].ID_Propietario=propietario[j];
        listados[j].marca=marca[j];
    }
}

void eAutE_alta(eAutosEstacionados listado[] ,int limite)
{
    eAutosEstacionados autoAux;
    int idAuto;
    int indice;
    int flag=1;

        idAuto = eAutE_siguienteId(listado,limite);
        indice = eAutE_buscarLugarLibre(listado,limite);

        if(indice == -1)
        {
            printf("No hay mas lugar.");
            getch();
        }
        else{
            printf("Ingrese Patente: ");
            fflush(stdin);
            gets(autoAux.patente);

            printf("Ingrese marca: ");
            fflush(stdin);
            scanf("%d",&autoAux.marca);

        while(flag==1){
            printf("Ingrese ID del propietario: ");
            scanf("%d",&autoAux.ID_Propietario);
            for(int i=0;i<limite;i++){
                if(listado[i].ID_Propietario==autoAux.ID_Propietario){
                        printf("\nID encontrado.");
                        flag=0;
                        break;
                    }
                }
            }
            listado[indice].estado=OCUP;
            listado[indice].marca=autoAux.marca;
            listado[indice].ID_Propietario=autoAux.ID_Propietario;
            listado[indice].ID_Auto=idAuto;
            strcpy(listado[indice].patente,autoAux.patente);
            system("cls");
            printf("\n              Auto ingresado con exito.");
            getch();
        }


         eAutE_mostrarUno(listado[indice]);
         getch();
}
