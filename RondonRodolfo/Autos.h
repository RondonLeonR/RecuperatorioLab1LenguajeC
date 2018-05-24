#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "Propietarios.h"

typedef struct{
int ID_Auto;
char patente[20];
int marca;
int ID_Propietario;
int estado;
}eAutosEstacionados;
#endif // AUTOS_H_INCLUDED

void eAutE_init(eAutosEstacionados[],int limite);
int eAutE_buscarPorId(eAutosEstacionados listado[] ,int limite, int id);
int eAutE_siguienteId(eAutosEstacionados listado[] ,int limite);
int eAutE_buscarLugarLibre(eAutosEstacionados listado[],int limite);

void eAutE_mostrarUno(eAutosEstacionados parametro);
void eAutE_mostrarListado(eAutosEstacionados listado[],int limite);

void eAutE_inicializarUsuariosHardCode(eAutosEstacionados listado[]);
void eAutE_alta(eAutosEstacionados listado[] ,int limite);
