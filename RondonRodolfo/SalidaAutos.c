#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Autos.h"
#include "Propietarios.h"
#include "SalidaAutos.h"

#define ALPHA_ROMEO 111
#define FERRARI 222
#define AUDI 333
#define OTROS 444

void eSal_MostrarAutosPorPropietario(ePropietario listadoPropi[], eAutosEstacionados listaAutos[],int limiteUsu, int limiteAut)
{
    int idUsu;
    int indice;

    ePro_mostrarListado(listadoPropi,limiteUsu);

    printf("\n\n        Ingrese el ID del usuario que desea ver: ");
    scanf("%d",&idUsu);

}

void eSal_EgresoHardcodeo(eSalidaAuto egresos[])
{
    int i;
    int marca[]= {111,111,222,333,222,222,333,444,111,111};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(i=0;i<=10;i++)
    {
        egresos[i].marca=marca[i];
        egresos[i].importe=importe[i];
        egresos[i].estado=1;
    }
}

void eSal_EgresoAuto(eAutosEstacionados lista[],ePropietario listado[] , eSalidaAuto egresos[], int limiteAut, int limiteUsu)
{
    int i,j,l;
    int hora;
    hora = eSal_PrecioPorEstadia(egresos,limiteAut);
    system("cls");
    printf("\nMarca\t\t\tPrecio Por Hora\n\n");
    printf("ALPHA_ROMEO\t\t     $150\n");
    printf("FERRARI\t\t\t     $175\n");
    printf("AUDI\t\t\t     $200\n");
    printf("OTROS\t\t\t     $250\n");

    printf("\n\t\tTicket\n\nPropietario\t Patente\tMarca\t  Importe\n");

    for(i=0;i<limiteUsu;i++)
    {
        if(listado[i].estado!=-1)
        {
            printf("\n%s",listado[i].nombre);

                for(j=0;j<limiteAut;j++)
                {
                    if(listado[i].ID_Propietario==lista[j].ID_Propietario)
                    {
                        if(lista[j].estado!=-1)
                        {
                            printf("\t\t %s \t         %d",lista[j].patente, lista[j].marca);

                            for(l=0;l<limiteAut;l++)
                            {
                                if(lista[j].marca==egresos[l].marca)
                                {
                                    printf("\t  $%.2f\n",egresos[l].importe);
                                    break;
                                }
                            }
                        }
                    }

                }
        }
    }

    printf("Se estuvo %d Hrs.",hora);
    getch();
}

int eSal_PrecioPorEstadia(eSalidaAuto egresos[],int limite)
{
    int resul;
    int hora = devolverHorasEstadia();
    int i;

    for(i=0;i<limite;i++)
    {
        if(egresos[i].estado==1)
        {
            if(egresos[i].marca==111)
            {
                resul=hora*150;
                egresos[i].importe=resul;
            }
            else if(egresos[i].marca==222)
            {
                resul=hora*175;
                egresos[i].importe=resul;
            }
            else if(egresos[i].marca==333)
            {
                resul=hora*200;
                egresos[i].importe=resul;
            }
            else if(egresos[i].marca==444)
            {
                resul=hora*250;
                egresos[i].importe=resul;
            }
        }
    }
    return hora;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas;
}

void eSal_RecaudacionTotal(eSalidaAuto egresos[],int limiteAut)
{
    int i;
    float recaudac=0;
    float val=0;
    int hora;

    hora = eSal_PrecioPorEstadia(egresos,limiteAut);

    for(i=0;i<limiteAut;i++)
    {
        if(egresos[i].estado==1)
        {
        val=egresos[i].importe;
        recaudac=recaudac+val;
        }
    }
    printf("\n\t La recaudacion Total es: $%.2f",recaudac);
    printf("\n\n\t\t%d de Horas.",hora);

    getch();
}

void eSal_RecaudacionTotalPorMarca(eSalidaAuto egresos[],int limiteAut)
{
    int i;
    float recaudAROM=0;
    float recaudFERR=0;
    float recaudAUDI=0;
    float recaudOTRO=0;
    float aux;
    int hora;
    hora = eSal_PrecioPorEstadia(egresos,limiteAut);

    for(i=0;i<limiteAut;i++)
    {
        if(egresos[i].estado==1)
        {
            if(egresos[i].marca==111)
            {
                aux=0;
                aux=egresos[i].importe;
                recaudAROM=recaudAROM+aux;
            }
            else if(egresos[i].marca==222)
            {
                aux=0;
                aux=egresos[i].importe;
                recaudFERR=recaudFERR+aux;
            }
            else if(egresos[i].marca==333)
            {
                aux=0;
                aux=egresos[i].importe;
                recaudAUDI=recaudAUDI+aux;
            }
            else if(egresos[i].marca==444)
            {
                aux=0;
                aux=egresos[i].importe;
                recaudOTRO=recaudOTRO+aux;
            }
        }
    }
    system("cls");
    printf("\tEstuvieron %d Hrs\n",hora);
    printf("\nRecaudacion total de Alpha-Romeo: $%.2f",recaudAROM);
    printf("\nRecaudacion total de Ferrari: $%.2f",recaudFERR);
    printf("\nRecaudacion total de Audi: $%.2f",recaudAUDI);
    printf("\nRecaudacion total de Otros: $%.2f",recaudOTRO);
    getch();
}

void eSal_MostrarPropietarioConSusAutos(ePropietario listadoPropi[], eAutosEstacionados listaAutos[],int limiteUsu, int limiteAut)
{
    int idIngresado;
    int idEncont;
    int i;

    ePro_mostrarListado(listadoPropi,limiteUsu);
    printf("Ingrese el ID del propietario: ");
    scanf("%d",&idIngresado);
    idEncont=ePro_buscarPorId(listadoPropi,limiteUsu,idIngresado);
    if(listadoPropi[idEncont].estado!=1)
    {
        printf("\n\n\tEl ID ingresado no existe.");
    }
    else
    {
        printf("\n\tPropietario\tPatente\t   Marca");
        printf("\n\t%s",listadoPropi[idEncont].nombre);
        for(i=0;i<limiteAut;i++)
        {
            if(listadoPropi[idEncont].ID_Propietario==listaAutos[i].ID_Propietario)
            {
                if(listaAutos[i].estado==1)
                {
                    printf("\n\t\t\t   %s    %d\n",listaAutos[i].patente,listaAutos[i].marca);
                }
            }
        }
    }
getch();
}

void eSal_PropietariosDeAudi(ePropietario listado[],eAutosEstacionados lista[],int limiteUsu, int limiteAut)
{
    int i;
    int j;
    printf("Marca \tPropietario");
    for(i=0;i<limiteAut;i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].marca==333)
            {
                printf("\n%d",lista[i].marca);

                for(j=0;j<limiteUsu;j++)
                {
                    if(lista[i].ID_Propietario==listado[j].ID_Propietario)
                    {
                        if(listado[j].estado==1)
                        {
                            printf("     %s",listado[j].nombre);
                        }
                    }
                }
            }
        }
    }
getch();
}

void eSal_ListadoDeAutosEstacionadosOrdenados(ePropietario listado[], eAutosEstacionados lista[],int limiteUsu, int limiteAut)
{
    eAutosEstacionados auxiliar[limiteAut];
    int i,k,j;
    char aux;
    int auxNum;

    for(i=0;i<limiteAut;i++)
    {
        auxiliar[i].ID_Propietario=lista[i].ID_Propietario;
        auxiliar[i].marca=lista[i].marca;
        strcpy(auxiliar[i].patente,lista[i].patente);
        auxiliar[i].estado=lista[i].estado;
        auxiliar[i].ID_Auto=lista[i].ID_Auto;
    }
    for(k=0;k<limiteAut;k++)
    {
        for(j=k+1;j<limiteAut;j++)
        {
            if(strcmp(auxiliar[k].patente,auxiliar[j].patente)>0)
            {
                strcpy(aux,auxiliar[j].patente);
                strcpy(auxiliar[j].patente,auxiliar[k].patente);
                strcpy(auxiliar[k].patente,aux);

                auxNum=auxiliar[j].ID_Propietario;
                auxiliar[j].ID_Propietario=auxiliar[k].ID_Propietario;
                auxiliar[k].ID_Propietario=auxNum;

                auxNum=auxiliar[j].marca;
                auxiliar[j].marca=auxiliar[k].marca;
                auxiliar[k].marca=auxNum;

                auxNum=auxiliar[j].estado;
                auxiliar[j].estado=auxiliar[k].estado;
                auxiliar[k].estado=auxNum;
            }
        }
        eAutE_mostrarListado(auxiliar,limiteAut);
    }
}
