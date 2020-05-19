#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Clientes.h"
#include "Mascotas.h"

/** \brief inicializa un array de tipo cliente
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void inicializarCliente(cliente listadoCliente[], int sizeCliente)
{
    int i;

  for(i=0; i<sizeCliente; i++)
  {
      listadoCliente[i].estado = LIBRE;
  }
}

/** \brief harcodea un array de tipo cliente
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void hardCodearCliente(cliente listadoCliente[], int sizeCliente)
{
    int id[5]={1000,1001,1002,1003,1004};
    char nombre[5][30] = {"Juan","Maria","Ana","Pedro","Pablo"};
    char apellido[5][30] = {"Gonzalez","Perez","Lorenzo","Gaitan","Lopez"};
    char localidad[5][30] = {"capital","mar del plata","palermo","avellaneda","rosario"};
    int telefono [5] = {1111,2222,3333,4444,5555};
    int edad [5] = {10,15,20,25,30};
    char sexo [5] [10] = {"hombre","mujer","mujer","hombre","hombre"};

    int i;

    for(i=0; i<sizeCliente; i++)
    {
      listadoCliente[i].id = id[i];
      strcpy(listadoCliente[i].nombre, nombre[i]);
      strcpy(listadoCliente[i].apellido, apellido[i]);
      strcpy(listadoCliente[i].localidad, localidad[i]);
      listadoCliente[i].telefono=telefono[i];
      listadoCliente[i].edad=edad[i];
      strcpy(listadoCliente[i].sexo,sexo[i]);
      listadoCliente[i].estado = OCUPADO;
    }
}

/** \brief Permite crear un cliente.
 *
 * \param id int
 * \param
 * \return cliente El cliente creado.
 *
 */
cliente crearCliente (int idCliente)
{
    cliente miCliente;

    miCliente.id=idCliente;
    getStringOfLetters(miCliente.nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
    getStringOfLetters(miCliente.apellido,"Ingrese apellido: ","Error Reingrese un apellido valido: ");
    getStringOfLetters(miCliente.localidad,"Ingrese localidad: ","Error: ");
    miCliente.telefono=getInt(miCliente.telefono,"Ingrese telefono: ","Error Reingrese telefono: ",1000,1000000);
    miCliente.edad=getInt(miCliente.edad,"Ingrese edad: ","Error Reingrese edad: ",1,100);

    getSexo(miCliente.sexo,"Ingrese sexo: ","Error Reingrese un sexo valido: ");

    miCliente.estado = OCUPADO;

    return miCliente;

}

/** \brief guarda los datos ingresados por el usuario en una posicion del array estructura.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param index int
 * \param idCliente int
 * \return int (-1) si hubo algun error o (0) si esta todo ok.0
 *
 */
int cargarCliente(cliente listadoCliente[], int sizeCliente,int index,int idCliente)
{
    if(sizeCliente==0||index==-1)
    {
    return -1;
    }
    else
    {
    listadoCliente[index] = crearCliente(idCliente);
    return 0;
    }

}


/** \brief Elimina de manera lógica un cliente recibiendo como parámetro su Id.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int eliminarCliente(cliente listadoCliente[], int sizeCliente,int id)
{
    int i;

         for(i=0; i<sizeCliente;i++)
        {
            if(id == listadoCliente[i].id)
            {
            listadoCliente[i].estado=LIBRE;
            return 0;
            break;
            }
        }
    return -1;
}

/** \brief Busca un espacio libre en un array de tipo cliente
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return int En caso de encontrarlo devuelve el indice del espacio libre o (-1) si no hay mas espacio.
 *
 */
int buscarLibreCliente(cliente listadoCliente[], int sizeCliente)
{
  int i;
  int index = -1;

  for(i=0; i<sizeCliente; i++)
  {
      if(listadoCliente[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}


/** \brief Pide una id al usuario y valida su existencia.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return int Devuelve el valor de la id.
 *
 */
int validarIdCliente(cliente listadoCliente[],int sizeCliente,char mensaje[], char mensajeError [])
{
    int indexId;
    int valueId;
    printf("%s ",mensaje);
    scanf("%d",&valueId);

    indexId=buscarClientePorId(listadoCliente,sizeCliente,valueId);

     while(indexId != valueId)
    {
        printf("%s", mensajeError);
        scanf("%d", &valueId);
        indexId=buscarClientePorId(listadoCliente,sizeCliente,valueId);
    }

    return valueId;
}

/** \brief Verifica que la id recibida exista en el array de tipo cliente.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param id int
 * \return int Devuelve el valor de la id.
 *
 */
int buscarClientePorId(cliente listadoCliente[], int sizeCliente,int id)
{
    int i;
    int index = -1;


    for (i = 0; i < sizeCliente; i++)
    {
        if(listadoCliente[i].id==id)
        {
            index = listadoCliente[i].id;
            break;
        }
    }

    return index;
}

/** \brief Muestra por pantalla un dato del tipo cliente.
 *
 * \param miCliente cliente
 * \param
 * \return
 *
 */
void mostrarCliente(cliente miCliente)
{
  printf ("%4d   %15s      %15s       %15s      %8d     %8d     %15s\n", miCliente.id,
                                          miCliente.nombre,miCliente.apellido,
                                          miCliente.localidad,miCliente.telefono,miCliente.edad,miCliente.sexo);
}


/** \brief Muestra todos los datos cargados en un array de tipo cliente.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \return void
 *
 */
void mostrarTodosLosClientes(cliente listadoCliente[], int sizeCliente)
{
    int i;


    printf("\n\n            CLIENTES\n\n");
    printf ("ID\t\tNOMBRE\t\tAPELLIDO\t\tLOCALIDAD\tTELEFONO\tEDAD\t\tSEXO\n");
    for(i=0; i<sizeCliente; i++)
    {
        if(listadoCliente[i].estado==OCUPADO)
        {
            mostrarCliente(listadoCliente[i]);
        }
    }

}

/** \brief Permite modificar los campos del cliente
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int modificarCliente(cliente listadoCliente[], int sizeCliente, int id)
{
    int flag=-1;
    int opcion;
    int i;



    do
    {
    showModificarCliente();
    opcion=getInt(opcion,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",1,7);
        switch(opcion)
        {
        case 1:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                getStringOfLetters(listadoCliente[i].nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 2:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                getStringOfLetters(listadoCliente[i].apellido,"Ingrese apellido: ","Error Reingrese un apellido valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 3:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                getStringOfLetters(listadoCliente[i].localidad,"Ingrese localidad: ","Error: ");
                flag=0;
                break;
                }
            }
        break;
        case 4:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                listadoCliente[i].telefono=getInt(listadoCliente[i].telefono,"Ingrese telefono","Error Reingrese telefono: ",1000,1000000);
                flag=0;
                break;
                }
            }
        break;
        case 5:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                listadoCliente[i].edad=getInt(listadoCliente[i].edad,"Ingrese edad","Error Reingrese edad: ",1,100);
                flag=0;
                break;
                }
            }
        break;
        case 6:
            for(i=0; i<sizeCliente;i++)
            {
                if(id == listadoCliente[i].id)
                {
                getStringOfLetters(listadoCliente[i].sexo,"Ingrese sexo: ","Error Reingrese un sexo valido: ");
                flag=0;
                break;
                }
            }
        break;
    }
    }while(opcion!=7);

    return flag;
}


/** \brief Ordena el listado de clientes alfabeticamente por nombre.
 *
 * \param sizeCliente int
 * \param listadoCliente[] cliente
 * \return void
 *
 */
void ordenarNombre(int sizeCliente,cliente listadoCliente[])
{
int i;
int j;
cliente auxCliente;
    for(i=0;i<sizeCliente-1;i++)
    {
        for(j=i+1;j<sizeCliente;j++)
        {
                if(stricmp(listadoCliente[i].nombre,listadoCliente[j].nombre)>=0)
                {
                auxCliente=listadoCliente[i];
                listadoCliente[i]=listadoCliente[j];
                listadoCliente[j]=auxCliente;
                }
        }
    }
}


/** \brief saca el promedio y lo muestra.
 *
 * \param listadoCliente[] cliente
 * \param sizeCliente int
 * \param sexo[] char
 * \return
 *
 */
void promedioSexo(cliente listadoCliente[],int sizeCliente)
{
    int i;
    int contadorCliente=0;
    int contadorSexo=0;
    float promedioCliente=0;

    for(i=0;i<sizeCliente;i++)
    {
        if(listadoCliente[i].estado==OCUPADO)
        {
        contadorCliente++;
        }
        if(listadoCliente[i].estado==OCUPADO && stricmp(listadoCliente[i].sexo,"mujer")==0)
        {
        contadorSexo++;
        }
    }


    promedioCliente=(float)(contadorSexo*100)/contadorCliente;

    printf("Porcentaje de mujeres: %f\n",promedioCliente);

}
