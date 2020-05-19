#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Cliente_Mascota.h"

#define TM 20 //Mascotas
#define TC 10 // Clientes
#define TR 10 //Razas


int main()
{
    int r;
    int opcion;
    int flagOpcion=0;
    int index;
    int idMascota=510;
    int idCliente=1004;
    float promedioEdadMascotas=0;
    float promedioEdadMascotasPorTipo=0;

    mascota listadoMascota[TM];
    cliente listadoCliente[TC];
    eRaza listadoRaza[TR];

    hardCodearRaza(listadoRaza,TR);
    inicializarCliente(listadoCliente,TC);
    hardCodearCliente(listadoCliente,5);

    inicializarMascota(listadoMascota,TM);
    hardCodearMascota(listadoMascota,11);

    flagOpcion=20;

    mostrarTodosLosClientes(listadoCliente,TC);

    mostrarTodasLasMascotas(listadoMascota,TM,listadoCliente,TC);

    mostrarTodosLosClientesConMascotas(listadoMascota,TM,listadoCliente,TC);

        do
        {
            showMenu();
            opcion=getInt(opcion,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",1,20);
            switch(opcion)
            {
                case 1:
                index = buscarLibreCliente(listadoCliente,TC);
                    if(index!=-1)
                    {
                    idCliente=generateId(idCliente);
                    r=cargarCliente(listadoCliente,TC,index,idCliente);

                            if(r==-1)
                            {
                            printf("\nError en la carga.\n");
                            }
                            else if(r==0)
                            {
                            printf("Carga Completada.\n");
                            flagOpcion++;
                            }
                    }
                    else
                    {
                    printf("No hay mas espacio de carga.");
                    }
                break;
                case 2:
                    if(flagOpcion>0)
                    {
                    mostrarTodosLosClientes(listadoCliente,TC);
                    idCliente=validarIdCliente(listadoCliente,TC,"Ingrese el numero de id de la cliente que desea eliminar", "Error id ingresada no valida, reingrese");
                    r=eliminarClienteConSusMascotas(listadoMascota,TM,listadoCliente,TC,idCliente);
                            if(r==-1)
                            {
                            printf("\nError en la baja.\n");
                            }
                            else if(r==0)
                            {
                            printf("\nEliminacion Completa.\n");
                            flagOpcion--;
                            }
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una cliente.\n ");
                    }
                break;
                case 3:
                    if(flagOpcion>0)
                    {
                    mostrarTodosLosClientes(listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }
                break;
                case 4:
                    if(flagOpcion>0)
                    {
                    mostrarTodosLosClientes(listadoCliente,TC);
                    idCliente=validarIdCliente(listadoCliente,TC,"Ingrese el numero de id de la cliente que desea modificar: ", "Error id ingresada no valida, reingrese: ");
                    r=modificarCliente(listadoCliente,TC,idCliente);
                            if(r==-1)
                            {
                            printf("\nError en la Modificacion.\n");
                            }
                            else if(r==0)
                            {
                            printf("Modificacion Completa.\n");
                            }
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una cliente.\n ");
                    }
                break;
                case 5:
                index = buscarLibreMascota(listadoMascota,TM);
                    if(index!=-1)
                    {
                    idMascota=generateId(idMascota);
                    r=cargarMascota(listadoMascota,TM,index,listadoCliente,TC,idMascota,listadoRaza,TR);
                            if(r==-1)
                            {
                            printf("\nError en la carga.\n");
                            }
                            else if(r==0)
                            {
                            printf("Carga Completada.\n");
                            flagOpcion++;
                            }
                    }
                    else
                    {
                    printf("No hay mas espacio de carga.");
                    }
                break;
                case 6:
                    if(flagOpcion>0)
                    {
                    mostrarTodasLasMascotas(listadoMascota,TM,listadoCliente,TC);
                    idMascota=validarIdMascota(listadoMascota,TM,"Ingrese el numero de id de la mascota que desea eliminar", "Error id ingresada no valida, reingrese");
                    r=eliminarMascota(listadoMascota,TM,idMascota);
                            if(r==-1)
                            {
                            printf("\nError en la baja.\n");
                            }
                            else if(r==0)
                            {
                            printf("Eliminacion Completa.\n");
                            flagOpcion--;
                            }
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }
                break;
                case 7:
                    if(flagOpcion>0)
                    {
                    mostrarTodasLasMascotas(listadoMascota,TM,listadoCliente,TC);
                    idMascota=validarIdMascota(listadoMascota,TM,"Ingrese el numero de id de la mascota que desea modificar: ", "Error id ingresada no valida, reingrese: ");
                    r=modificarMascota(listadoMascota,TM,idMascota,listadoRaza,TR);
                            if(r==-1)
                            {
                            printf("\nError en la Modificacion.\n");
                            }
                            else if(r==0)
                            {
                            printf("Modificacion Completa.\n");
                            }
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }
                break;
                case 8:
                    if(flagOpcion>0)
                    {
                    mostrarTodasLasMascotas(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }
                break;
                case 9:
                    if(flagOpcion>0)
                    {
                    mostrarTodosLosClientesConMascotas(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 10:
                    if(flagOpcion>0)
                    {
                    ordenarMascotasPorTipo(listadoMascota,TM);
                    mostrarTodasLasMascotas(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 11:
                    if(flagOpcion>0)
                    {
                    clientesConMasDeUnaMascota(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 12:
                    if(flagOpcion>0)
                    {
                    mostrarMascotasConMasDeTresAnos(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 13:
                    if(flagOpcion>0)
                    {
                    mostrarMascotasPorTipoParticular(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 14:
                    if(flagOpcion>0)
                    {
                    ordenarClientesPorCantidadDeMascotas(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 15:
                    if(flagOpcion>0)
                    {
                    ordenarClientesPorCantidadDeMascotasYNombre(listadoMascota,TM,listadoCliente,TC);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 16:
                    if(flagOpcion>0)
                    {
                    promedioEdadMascotas=promedioEdad(listadoMascota,TM);
                    printf("El promedio de edad de las mascotas es: %f\n",promedioEdadMascotas);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 17:
                    if(flagOpcion>0)
                    {
                    promedioEdadMascotasPorTipo=promedioEdadPorTipo(listadoMascota,TM,"perro");
                    printf("El promedio de edad de las mascotas de tipo PERRO es: %f\n",promedioEdadMascotasPorTipo);
                    promedioEdadMascotasPorTipo=promedioEdadPorTipo(listadoMascota,TM,"gato");
                    printf("El promedio de edad de las mascotas de tipo GATO es: %f\n",promedioEdadMascotasPorTipo);
                    promedioEdadMascotasPorTipo=promedioEdadPorTipo(listadoMascota,TM,"raro");
                    printf("El promedio de edad de las mascotas de tipo RARO es: %f\n",promedioEdadMascotasPorTipo);
                    }
                    else
                    {
                    printf("Para ingresar a esta opcion primero debe cargar al menos una mascota.\n ");
                    }

                break;
                case 18:
                    promedioSexo(listadoCliente,TC);
                break;

            }

        system("pause");
        system("cls");

        }while(opcion!=20);




}

