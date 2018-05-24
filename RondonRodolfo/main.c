#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Propietarios.h"
#include "Autos.h"
#include "SalidaAutos.h"
#define CANTIDAD 20

int main()
{
    ePropietario listados[CANTIDAD];
    ePro_init(listados,CANTIDAD);

    eAutosEstacionados listadosDeAutos[CANTIDAD];
    eAutE_init(listadosDeAutos,CANTIDAD);

    eSalidaAuto salidaAuto[CANTIDAD];

    ePro_inicializarUsuariosHardCode(listados);
    eAutE_inicializarUsuariosHardCode(listadosDeAutos);
    eSal_EgresoHardcodeo(salidaAuto);

    int opcion;
    char resp='s';

    do{
        system("cls");//                    Alta al producto.
        printf("1-Alta de Propietario\n2-Modificacion de Propietario\n3-Baja a un Propietario\n4-Ingreso de Automovil\n5-Egreso de Auto\n6-Recaudacion Total\n7-Recaudacion Total por Marca\n8-Propietario con sus Autos");
        printf("\n9-Propietarios de AUDI");
        printf("\n11-Salir");

        scanf("%d",&opcion);
        switch(opcion){
            case 1:{

                    ePro_alta(listados,CANTIDAD);
                    break;
                }
            case 2:{
                    ePro_modificacion(listados,CANTIDAD);
            break;
                }
            case 3:{
                    ePro_baja(listados,CANTIDAD);
                    break;
                }
            case 4:{
                    eAutE_alta(listadosDeAutos,CANTIDAD);
                    break;
                }
            case 5:{
                    eSal_EgresoAuto(listadosDeAutos,listados,salidaAuto,CANTIDAD,CANTIDAD);
                    break;
                }
            case 6:{
                    eSal_RecaudacionTotal(salidaAuto,CANTIDAD);
                    break;
                }
            case 7:{
                    eSal_RecaudacionTotalPorMarca(salidaAuto,CANTIDAD);
                    break;
                }
            case 8:{
                    eSal_MostrarPropietarioConSusAutos(listados,listadosDeAutos,CANTIDAD,CANTIDAD);
                    break;
            }
            case 9:{
                    eSal_PropietariosDeAudi(listados,listadosDeAutos,CANTIDAD,CANTIDAD);
                    break;
            }
            case 11:{
                    resp='n';
                    break;
                }
            }
    }while(resp=='s');
    return 0;
}
