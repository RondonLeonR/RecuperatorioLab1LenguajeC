#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propietarios.h"
#define TAMANIO 20
#define OCUP 1
#define LIB  -1

void ePro_init(ePropietario listado[],int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
         listado[i].estado=LIB;
         listado[i].ID_Propietario=0;
    }
}

int ePro_buscarLugarLibre(ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;

        retorno = -2;
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
int ePro_siguienteId(ePropietario listado[],int limite)
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
                }
            }
        }
    }

    return retorno+1;
}

//Devulvo la posicion del id con los datos guardados en el.
int ePro_buscarPorId(ePropietario listado[] ,int limite, int id)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(listado[i].ID_Propietario==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void ePro_mostrarUno(ePropietario parametro)
{
        printf("ID: %d\tNombre: %s\tDireccion:  %s\tN Tarjeta: %s\n",parametro.ID_Propietario,parametro.nombre,parametro.direccion,parametro.tarjeta);
}
//Muestro todos el listado, usando la funcion mostrar uno.
void ePro_mostrarListado(ePropietario listado[],int limite)
{
    int i;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUP)
            {
                ePro_mostrarUno(listado[i]);
            }
        }
}

void ePro_alta(ePropietario listado[],int limite)
{
    int id;
    int indice;
        indice = ePro_buscarLugarLibre(listado,limite);
        if(indice==-1)
        {
            printf("No hay mas lugar.");
            getch();
        }
        else{
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listado[indice].nombre);
            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(listado[indice].direccion);
            printf("Ingrese el N de la Tarjeta: ");
            fflush(stdin);
            gets(listado[indice].tarjeta);
            system("cls");
            printf("\nUsuario %s ingresado con exito.",listado[indice].nombre);
            getch();
            system("cls");
        }
            id=ePro_siguienteId(listado,limite);//importante
            listado[indice].ID_Propietario = id;
            listado[indice].estado = OCUP;

         ePro_mostrarListado(listado,limite);
         getch();
}

void ePro_inicializarUsuariosHardCode(ePropietario listado[])
{
    int id[]= {1,2,3,4};
    char nomb[][20]= {"Juan","Luis","Maria","Jose"};
    char tarj[][20]= {"111-111","222-222","333-333","444-444"};
    char direc[][20]= {"mitre","urquiza","belgrano","alsina"};

    int i;

    for(i=0;i<4;i++)
    {
        listado[i].ID_Propietario=id[i];
        listado[i].estado = OCUP;
        strcpy(listado[i].direccion,direc[i]);
        strcpy(listado[i].nombre,nomb[i]);
        strcpy(listado[i].tarjeta,tarj[i]);
    }
}

void ePro_modificacion(ePropietario listado[],int limite)
{
    int idIngresado;
    int idEncontrado;

    ePro_mostrarListado(listado,limite);
    printf("Ingrese el ID del usuario a modificar: ");
    scanf("%d",&idIngresado);

    idEncontrado = ePro_buscarPorId(listado,limite,idIngresado);
    if(idEncontrado==-1)
        {
            printf("El ID ingresado es inexistente.\n");
            getch();
        }
    else{
            //Validar con un if y switch
            printf("Usuario a modificar: %s\n",listado[idEncontrado].nombre);
            printf("Ingrese Nuevo numero de la Tarjeta de Credito: ");
            fflush(stdin);
            gets(listado[idEncontrado].tarjeta);

            system("cls");
            printf("\n \n       Modificacion realizada con exito.\n");
            getch();
        }
        ePro_mostrarListado(listado,limite);
        getch();

}

void ePro_baja(ePropietario listado[] ,int limite)
{
    int i;
    int idIngresado;
    int idEncontrado;
    int opc;

    ePro_mostrarListado(listado,limite);
    printf("Ingrese el ID del usuario que desea dar de baja:");
    scanf("%d",&idIngresado);
    idEncontrado = ePro_buscarPorId(listado,limite,idIngresado);
    if(idEncontrado==-1)
    {
        printf("El ID ingresado no existe.");
        getch();
    }
    else{
        printf("\nEl usuario que desea borrar es %s?",listado[idEncontrado].nombre);
        printf("\nOpcion 1) SI\nOpcion 2) NO");
        scanf("%d",&opc);
            switch(opc){
            case 1:{
                listado[idEncontrado].estado=-1;
                printf("El usuario ha sido eliminado.");
                getch();
                break;
                }
            case 2:{
                printf("La baja ha sido cancelada.");
                getch();
                break;
                }
            }
        }
        system("cls");
    ePro_mostrarListado(listado,limite);
    getch();
}

