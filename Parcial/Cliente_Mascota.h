#include "Mascotas.h"
#include "Clientes.h"
#include "Raza.h"

typedef struct
{
 int cantidadMascotas;
 int idCliente;
}Cliente_Mascotas;


int eliminarClienteConSusMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente,int idCliente);
int cargarMascota(mascota listadoMascota[],int sizeMascota,int index,cliente listadoCliente[],int sizeCliente,int idMascota,eRaza listadoRaza[],int sizeRaza);
mascota crearMascota(cliente listadoCliente[],int sizeCliente,int idMascota,eRaza listadoRaza[],int sizeRaza);

void InicializarCliente_Mascota(cliente listadoCliente[], int sizeCliente,Cliente_Mascotas auxCliente_Mascota[]);
void mostrarTodosLosClientesConMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente);
void cantidadMascotas(mascota listadoMascota[], int sizeMascota,int sizeCliente, Cliente_Mascotas auxCliente_Mascota[]);


void mostrarMascota (mascota miMascota,cliente listadoCliente[],int sizeMascota);
void mostrarTodasLasMascotas(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente);

int modificarMascota(mascota listadoMascota[], int sizeMascota, int id,eRaza listadoRaza[],int sizeRaza);

void mostrarMascotasConMasDeTresAnos(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente);
void mostrarMascotasPorTipoParticular(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente);

void ordenarCantidadMascotasNombre(int sizeCliente,cliente listadoCliente[], Cliente_Mascotas auxCliente_Mascota[]);
void ordenarClientesPorCantidadDeMascotasYNombre(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente);

void ordenarCantidadMascotas(int sizeCliente,cliente listadoCliente[], Cliente_Mascotas auxCliente_Mascota[]);
void ordenarClientesPorCantidadDeMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente);

void clientesConMasDeUnaMascota(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente);

void mostrarTodosLosClientesConMascotasDelMismoS(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente);
