#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Cliente_Mascota.h"


/** \brief Permite volver atras en caso de haber elegido la opcion no deseada.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param idCliente int
 * \return int int Devuelve 0 si esta todo ok o, -1 si hubo algun error.
 *
 */
int verificarEliminacionCliente(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente,int idCliente)
{
    int r;
    int option;

    system("cls");

    do
    {
    showMenuVerificar();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
        mostrarTodosLosClientes(listadoCliente,sizeCliente);
        idCliente=validarIdCliente(listadoCliente,sizeCliente,"Ingrese el numero de id de la cliente que desea eliminar", "Error id ingresada no valida, reingrese");
        r=eliminarClienteConSusMascotas(listadoMascota,sizeMascota,listadoCliente,sizeCliente,idCliente);
            if(r==-1||r==0)
            {
            break;
            }
        }
     }while(option!=2);

     return r;
}

/** \brief Permite eliminar de manera logica un cliente con sus respectivas mascotas.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param idCliente int
 * \return int Devuelve 0 si esta todo ok o, -1 si hubo algun error.
 *
 */
int eliminarClienteConSusMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente,int idCliente)
{
    int i;//Cliente
    int j;//Mascota

    for(i=0; i<sizeCliente; i++)
    {
        if(idCliente == listadoCliente[i].id)
        {
            for(j=0; j<sizeMascota; j++)
            {
                if(listadoMascota[j].idCliente == listadoCliente[i].id  &&  listadoMascota[j].estado==OCUPADO)
                {
                listadoMascota[j].estado=LIBRE;
                }
            }
        listadoCliente[i].estado=LIBRE;
        return 0;
        }
    }
    return -1;
}


/** \brief Ordena los clientes por cantidad de mascotas y por nombre.
 *
 * \param sizeCliente int
 * \param listadoCliente[] cliente
 * \param auxCliente_Mascota[] Cliente_Mascotas
 * \return void
 *
 */
void ordenarCantidadMascotasNombre(int sizeCliente,cliente listadoCliente[], Cliente_Mascotas auxCliente_Mascota[])
{
    int i;//Cliente
    int j;//Mascota
    Cliente_Mascotas auxClienteMascota;
    cliente auxCliente;

    for(i=0; i<sizeCliente-1; i++)
    {
        for(j=i+1; j<sizeCliente; j++)
        {
            if(auxCliente_Mascota[i].cantidadMascotas!=0 && auxCliente_Mascota[i].cantidadMascotas>auxCliente_Mascota[j].cantidadMascotas)
            {
                auxClienteMascota = auxCliente_Mascota[i];
                auxCliente_Mascota[i] = auxCliente_Mascota[j];
                auxCliente_Mascota[j] = auxClienteMascota;
            }
            else if(auxCliente_Mascota[i].cantidadMascotas==auxCliente_Mascota[j].cantidadMascotas && stricmp(listadoCliente[i].nombre,listadoCliente[j].nombre)>0)
            {
                auxClienteMascota = auxCliente_Mascota[i];
                auxCliente_Mascota[i] = auxCliente_Mascota[j];
                auxCliente_Mascota[j] = auxClienteMascota;
            }
        }
    }

    for(i=0;i<sizeCliente;i++)
    {
        for(j=0;j<sizeCliente;j++)
        {
            if(listadoCliente[i].id==auxCliente_Mascota[j].idCliente)
            {
                auxCliente=listadoCliente[i];
                listadoCliente[i]=listadoCliente[j];
                listadoCliente[j]=auxCliente;
            }
        }
    }

}


/** \brief Muestra los clientes ordenados por cantidad de mascotas y por nombre.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void ordenarClientesPorCantidadDeMascotasYNombre(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente)
{
    int i;//Cliente
    int j;//Mascota

    Cliente_Mascotas ClienteMascota[sizeCliente];


    InicializarCliente_Mascota(listadoCliente,sizeCliente,ClienteMascota);

    cantidadMascotas(listadoMascota,sizeMascota,sizeCliente,ClienteMascota);

    ordenarCantidadMascotas(sizeCliente,listadoCliente,ClienteMascota);

    ordenarCantidadMascotasNombre(sizeCliente,listadoCliente,ClienteMascota);

    printf("\n\n        CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS Y NOMBRE.\n\n");
    for(i=0; i<sizeCliente; i++)
    {
        if(ClienteMascota[i].cantidadMascotas!=0)
        {
        printf("Cliente: %s\n", listadoCliente[i].nombre);
        printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(j=0; j<sizeMascota; j++)
            {
                 if(listadoMascota[j].idCliente == listadoCliente[i].id  &&  listadoMascota[j].estado==OCUPADO)
                 {
                      mostrarMascota(listadoMascota[j],listadoCliente,sizeCliente);
                 }
            }
        }
    }
}


/** \brief Ordena los clientes por cantidad de mascotas.
 *
 * \param sizeCliente int
 * \param listadoCliente[] cliente
 * \param auxCliente_Mascota[] Cliente_Mascotas
 * \return void
 *
 */
void ordenarCantidadMascotas(int sizeCliente,cliente listadoCliente[], Cliente_Mascotas auxCliente_Mascota[])
{
    int i;//Cliente
    int j;//Mascota
    Cliente_Mascotas auxClienteMascota;
    cliente auxCliente;

    for(i=0; i<sizeCliente-1; i++)
    {
        for(j=i+1; j<sizeCliente; j++)
        {
            if(auxCliente_Mascota[i].cantidadMascotas>auxCliente_Mascota[j].cantidadMascotas)
            {
                auxClienteMascota = auxCliente_Mascota[i];
                auxCliente_Mascota[i] = auxCliente_Mascota[j];
                auxCliente_Mascota[j] = auxClienteMascota;
            }
        }
    }

    for(i=0;i<sizeCliente;i++)
    {
        for(j=i;j<sizeCliente;j++)
        {
            if(listadoCliente[i].id==auxCliente_Mascota[j].idCliente)
            {
                auxCliente=listadoCliente[i];
                listadoCliente[i]=listadoCliente[j];
                listadoCliente[j]=auxCliente;
            }
        }
    }

}


/** \brief Muestra los clientes ordenados por cantidad de mascotas.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void ordenarClientesPorCantidadDeMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente)
{
    int i;//Cliente
    int j;//Mascota

    Cliente_Mascotas ClienteMascota[sizeCliente];


    InicializarCliente_Mascota(listadoCliente,sizeCliente,ClienteMascota);

    /********************************************/

    cantidadMascotas(listadoMascota,sizeMascota,sizeCliente,ClienteMascota);

    ordenarCantidadMascotas(sizeCliente,listadoCliente,ClienteMascota);


    printf("\n\n        CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS.\n\n");
    for(i=0; i<sizeCliente; i++)
    {
        if(ClienteMascota[i].cantidadMascotas!=0)
        {
        printf("Cliente: %s\n", listadoCliente[i].nombre);
        printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(j=0; j<sizeMascota; j++)
            {
                 if(listadoMascota[j].idCliente == listadoCliente[i].id  &&  listadoMascota[j].estado==OCUPADO)
                 {
                      mostrarMascota(listadoMascota[j],listadoCliente,sizeCliente);
                 }
            }
        }
    }

}


/** \brief Muestra los clientes con mas de una mascota.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void clientesConMasDeUnaMascota(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente)
{
    int i;//Cliente
    int j;//Mascota

    Cliente_Mascotas auxClienteMascota[sizeCliente];


    InicializarCliente_Mascota(listadoCliente,sizeCliente,auxClienteMascota);

    cantidadMascotas(listadoMascota,sizeMascota,sizeCliente,auxClienteMascota);


    printf("\n\n        CLIENTES CON MAS DE UNA MASCOTA.\n\n");
    for(i=0; i<sizeCliente; i++)
    {
        if(auxClienteMascota[i].cantidadMascotas>1)
        {
        printf("Cliente: %s\n", listadoCliente[i].nombre);
        printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(j=0; j<sizeMascota; j++)
            {
                 if(listadoMascota[j].idCliente == listadoCliente[i].id  &&  listadoMascota[j].estado==OCUPADO)
                 {
                      mostrarMascota(listadoMascota[j],listadoCliente,sizeCliente);
                 }
            }
        }
    }
}


/** \brief Muestra todos los clientes con sus respectivas mascotas.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void mostrarTodosLosClientesConMascotas(mascota listadoMascota[], int sizeMascota, cliente listadoCliente[], int sizeCliente)
{
    int i;//Cliente
    int j;//Mascota

    printf("\n\n        CLIENTES CON MASCOTAS.\n\n");
    for(i=0; i<sizeCliente; i++)
    {
        if(listadoCliente[i].estado==OCUPADO)
        {
            printf("Cliente: %s\n", listadoCliente[i].nombre);
            printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(j=0; j<sizeMascota; j++)
            {
                 if(listadoMascota[j].idCliente == listadoCliente[i].id  &&  listadoMascota[j].estado==OCUPADO)
                 {
                      mostrarMascota(listadoMascota[j],listadoCliente,sizeCliente);
                 }
            }
        }
    }
}


/** \brief Inicializa un array de tipo Cliente_Mascotas
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param auxCliente_Mascota[] Cliente_Mascotas
 * \return void
 *
 */
void InicializarCliente_Mascota(cliente listadoCliente[], int sizeCliente,Cliente_Mascotas auxCliente_Mascota[])
{
    int i;
    for(i=0; i<sizeCliente; i++)
    {
        auxCliente_Mascota[i].idCliente = listadoCliente[i].id;
        auxCliente_Mascota[i].cantidadMascotas = 0;
    }
}


/** \brief Calcula la cantidad de mascotas que tiene cada cliente.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param sizeCliente int
 * \param auxCliente_Mascota[] Cliente_Mascotas
 * \return void
 *
 */
void cantidadMascotas(mascota listadoMascota[], int sizeMascota,int sizeCliente, Cliente_Mascotas auxCliente_Mascota[])
{
    int i;
    int j;

    for(i=0; i<sizeCliente; i++)
    {
        for(j=0; j<sizeMascota; j++)
        {
            if(listadoMascota[j].estado==OCUPADO && auxCliente_Mascota[i].idCliente == listadoMascota[j].idCliente)
            {
                auxCliente_Mascota[i].cantidadMascotas++;
            }
        }
    }
}


/** \brief Muestra por pantalla un dato del tipo Mascota.
 *
 * \param miMascota mascota
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return
 *
 */
void mostrarMascota (mascota miMascota,cliente listadoCliente[],int sizeCliente)
{

    for(int i=0;i<sizeCliente;i++)
    {
        if(miMascota.idCliente==listadoCliente[i].id)
        {
        printf ("%4d   %15s     %20s     %20d      %8g           %3d      %15s    %15s\n", miMascota.id,
                                              miMascota.nombre,miMascota.tipo,miMascota.idRaza,
                                              miMascota.peso,
                                              miMascota.edad,miMascota.sexo,listadoCliente[i].nombre);
        }
    }

}


/** \brief Muestra todos los datos cargados en un array de tipo Mascota.
 *
 * \param listadoMascota[] Mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void mostrarTodasLasMascotas(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente)
{
    int i;

    printf("\n\n        MASCOTAS\n\n");
    printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
    for(i=0; i<sizeMascota; i++)
    {
        if(listadoMascota[i].estado==OCUPADO)
        {
            mostrarMascota(listadoMascota[i],listadoCliente,sizeCliente);
        }
    }

}


/** \brief Muestra las mascotas con mas de 3 anios.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void mostrarMascotasConMasDeTresAnos(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente)
{
    int i;

    printf("\n\n        MASCOTAS\n\n");
    printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
    for(i=0; i<sizeMascota; i++)
    {
        if(listadoMascota[i].estado==OCUPADO&&listadoMascota[i].edad>3)
        {
            mostrarMascota(listadoMascota[i],listadoCliente,sizeCliente);
        }
    }

}


/** \brief Muestra las mascotas segun un tipo en particular.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void mostrarMascotasPorTipoParticular(mascota listadoMascota[], int sizeMascota,cliente listadoCliente[],int sizeCliente)
{
    int i;
    int opcion;

    do
    {
        showMenuMascotas();
        opcion=getInt(opcion,"Ingrese la opcion que desee: ","Error opcion invalida, reingrese: ",1,4);
        switch(opcion)
        {
        case 1:
            printf("\n\n        PERRO\n\n");
            printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(i=0; i<sizeMascota; i++)
            {
                if(listadoMascota[i].estado==OCUPADO&&stricmp(listadoMascota[i].tipo,"Perro")==0)
                {
                    mostrarMascota(listadoMascota[i],listadoCliente,sizeCliente);
                }
            }
        break;
        case 2:
            printf("\n\n        GATO\n\n");
            printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(i=0; i<sizeMascota; i++)
            {
                if(listadoMascota[i].estado==OCUPADO&&stricmp(listadoMascota[i].tipo,"Gato")==0)
                {
                    mostrarMascota(listadoMascota[i],listadoCliente,sizeCliente);
                }
            }
        break;
        case 3:
            printf("\n\n        RARO\n\n");
            printf ("ID\t\tNOMBRE\t\t\tTIPO\t\t\tRAZA\t\tPESO\t\tEDAD\t\t   SEXO               CLIENTE\n");
            for(i=0; i<sizeMascota; i++)
            {
                if(listadoMascota[i].estado==OCUPADO&&stricmp(listadoMascota[i].tipo,"Raro")==0)
                {
                    mostrarMascota(listadoMascota[i],listadoCliente,sizeCliente);
                }
            }
        break;
        }

    system("pause");
    system("cls");

    }while(opcion!=4);

}


/** \brief Permite crear una mascota.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return mascota Devuelve la mascota creada.
 *
 */
mascota crearMascota(cliente listadoCliente[],int sizeCliente,int idMascota,eRaza listadoRaza[],int sizeRaza)
{
    mascota miMascota;

    miMascota.id=idMascota;
    getStringOfLetters(miMascota.nombre,"Ingrese el nombre de la mascota: ","Error nombre no valido, reingrese: ");
    getStringOfLetters(miMascota.tipo,"Ingrese el tipo de mascota (Perro,Gato,Raro,etc): ","Error, tipo de mascota no valido reingrese: ");
    miMascota.idRaza=getRaza(miMascota.idRaza,listadoRaza,sizeRaza,miMascota.tipo);
    miMascota.edad=getInt(miMascota.edad,"Ingrese la edad de su mascota: ","Error, edad no valida: ",0,100);
    miMascota.peso=getFloat(miMascota.peso,"Ingrese el peso de su mascota (en kilogramos): ","Error, peso no valido: ",0,100);
    getSexo(miMascota.sexo,"Ingrese el sexo de la mascota: ","Error, sexo de mascota no valido reingrese: ");

    mostrarTodosLosClientes(listadoCliente,sizeCliente);

    miMascota.idCliente=getInt(miMascota.idCliente,"Ingrese la id del dueño de la mascota: ","Error, reingrese id del dueño: ",1000,1010);

    miMascota.estado = OCUPADO;

    return miMascota;

}


/** \brief Carga los datos de una mascota en un array de tipo mascota.
 *
 * \param listadoMascotas[] mascota
 * \param sizeMascota int
 * \param index int
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return int Devuelve 0 si todo esta ok, o -1 si hubo algun error.
 *
 */
int cargarMascota(mascota listadoMascota[],int sizeMascota,int index,cliente listadoCliente[],int sizeCliente,int idMascota,eRaza listadoRaza[],int sizeRaza)
{
    if(sizeMascota==0||index==-1)
    {
    return -1;
    }
    else
    {
    listadoMascota[index] = crearMascota(listadoCliente,sizeCliente,idMascota,listadoRaza,sizeRaza);
    return 0;
    }

}


/** \brief Permite modificar los campos de la mascota
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int modificarMascota(mascota listadoMascota[], int sizeMascota, int id,eRaza listadoRaza[],int sizeRaza,cliente listadoCliente[],int sizeCliente)
{
    int flag=-1;
    int opcion;
    int i;

    do
    {
    showModificarMascota();
    opcion=getInt(opcion,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",1,8);
        switch(opcion)
        {
        case 1:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                getStringOfLetters(listadoMascota[i].nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 2:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                getStringOfLetters(listadoMascota[i].tipo,"Ingrese tipo: ","Error Reingrese un tipo valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 3:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                listadoMascota[i].idRaza=getRaza(listadoMascota[i].idRaza,listadoRaza,sizeRaza,listadoMascota[i].tipo);
                flag=0;
                break;
                }
            }
        break;
        case 4:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                listadoMascota[i].edad=getInt(listadoMascota[i].edad,"Ingrese edad: ","Error, reingrese edad: ",0,100);
                flag=0;
                break;
                }
            }
        break;
        case 5:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                listadoMascota[i].peso=getFloat(listadoMascota[i].peso,"Ingrese peso: ","Error, reingrese peso: ",0,100);
                flag=0;
                break;
                }
            }
        break;
        case 6:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                getStringOfLetters(listadoMascota[i].sexo,"Ingrese sexo: ","Error Reingrese un sexo valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 7:
            for(i=0; i<sizeMascota;i++)
            {
                if(id == listadoMascota[i].id)
                {
                mostrarTodosLosClientes(listadoCliente,sizeCliente);
                listadoMascota[i].idCliente=getInt(listadoMascota[i].idCliente,"Ingrese la id del dueño de la mascota: ","Error, reingrese id del dueño: ",1000,1010);
                flag=0;
                break;
                }
            }
        break;
    }
    }while(opcion!=8);

    return flag;
}
