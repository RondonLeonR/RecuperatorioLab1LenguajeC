#include "Propietarios.h"
#include "Autos.h"

#ifndef SALIDAAUTOS_H_INCLUDED
#define SALIDAAUTOS_H_INCLUDED

typedef struct{
    float importe;
    int marca;
    int estado;
}eSalidaAuto;

#endif // SALIDAAUTOS_H_INCLUDED

void eSal_MostrarPropietarioConSusAutos(ePropietario listadoPropi[], eAutosEstacionados listaAutos[],int limiteUsu, int limiteAut);
void eSal_EgresoHardcodeo(eSalidaAuto egresos[]);
void eSal_EgresoAuto(eAutosEstacionados lista[],ePropietario listado[] , eSalidaAuto egresos[], int limiteAut, int limiteUsu);
int eSal_PrecioPorEstadia(eSalidaAuto egresos[],int limite);
int devolverHorasEstadia();
void eSal_RecaudacionTotal(eSalidaAuto egresos[],int limiteAut);
void eSal_RecaudacionTotalPorMarca(eSalidaAuto egresos[],int limiteAut);
void eSal_PropietariosDeAudi(ePropietario listado[],eAutosEstacionados lista[],int limiteUsu, int limiteAut);
void eSal_ListadoDeAutosEstacionadosOrdenados(ePropietario listado[], eAutosEstacionados lista[],int limiteUsu, int limiteAut);
