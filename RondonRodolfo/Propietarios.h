#ifndef PROPIETARIOS_H_INCLUDED
#define PROPIETARIOS_H_INCLUDED
typedef struct{
    int ID_Propietario;
    char nombre[20];
    char direccion[20];
    char tarjeta[20];
    int estado;

}ePropietario;
#endif // PROPIETARIOS_H_INCLUDED

void ePro_init(ePropietario listado[],int limite);
int ePro_buscarPorId(ePropietario listado[] ,int limite, int id);
int ePro_siguienteId(ePropietario listado[] ,int limite);
int ePro_buscarLugarLibre(ePropietario listado[],int limite);

void ePro_mostrarUno(ePropietario parametro);
void ePro_mostrarListado(ePropietario listado[] ,int limite);

void ePro_inicializarUsuariosHardCode(ePropietario listado[]);
void ePro_alta(ePropietario listado[],int limite);
void ePro_modificacion(ePropietario listado[] ,int limite);
void ePro_baja(ePropietario listado[] ,int limite);

