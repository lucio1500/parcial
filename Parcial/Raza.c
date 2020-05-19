#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Raza.h"

/** \brief harcodea un array de tipo eRaza
 *
 * \param listadoTipo[] eRaza
 * \param sizeTipo int
 * \return void
 *
 */
void hardCodearRaza(eRaza listadoRaza[], int sizeRaza)
{
  int id[10]={11,12,13,14,15,16,17,18,19,20};
  char nombre[10][15] = {"Cruza","Siames","Pastor Aleman","Bulldog","Pitbull","Caniche","Boxer","Labrador","Loro","Iguana"};
  char pais[10][15] = {"Argentina","China","Alemania","Inglaterra","Suiza","Francia","Suecia","Italia","Mexico","Brasil"};
  char tipo[10] [15] = {"gato","gato","perro","perro","perro","perro","perro","perro","raro","raro"};

  int i;

  for(i=0; i<sizeRaza; i++)
  {
      listadoRaza[i].id = id[i];
      strcpy(listadoRaza[i].nombre, nombre[i]);
      strcpy(listadoRaza[i].pais, pais[i]);
      strcpy(listadoRaza[i].tipo,tipo[i]);
  }

}


int getRaza(int idRaza,eRaza listadoRaza[],int sizeRaza,char tipoM[])
{
    int i;

    for(i=0;i<sizeRaza;i++)
    {
        if(stricmp(listadoRaza[i].tipo,tipoM)==0)
        {
        mostrarRazaPorTipo(listadoRaza,sizeRaza,tipoM);
        idRaza=validarIdRaza(listadoRaza,sizeRaza,"Ingrese la ID de la raza que desee: ","Error, reingrese ID: ");
        return idRaza;
        }
    }

}


/** \brief Muestra por pantalla un dato del tipo eRaza.
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarRaza(eRaza miRaza)
{
  printf ("%4d   %15s   %15s\n", miRaza.id,miRaza.nombre,miRaza.pais);
}


/** \brief Muestra todos los datos cargados en un array de tipo eTipo.
 *
 * \param listadoTipo[] eTipo
 * \param sizeRaza int
 * \return void
 *
 */
void mostrarRazaPorTipo(eRaza listadoRaza[], int sizeRaza,char tipo[])
{
    int i;

    printf("\n\n            RAZAS\n\n");
    printf ("ID\t\tNOMBRE\t\tPAIS\n");
    for(i=0; i<sizeRaza; i++)
    {
        if(stricmp(listadoRaza[i].tipo,tipo)==0)
        {
            mostrarRaza(listadoRaza[i]);
        }
    }
}


/** \brief Pide una id al usuario y valida su existencia.
 *
 * \param listadoRaza[] eRaza
 * \param sizeRaza int
 * \param mensaje[] char
 * \param [] char mensajeError
 * \return int Devuelve el valor de la id.
 *
 */
int validarIdRaza(eRaza listadoRaza[],int sizeRaza,char mensaje[], char mensajeError [])
{
    int indexId;
    int valueId;
    printf("%s ",mensaje);
    scanf("%d",&valueId);

    indexId=buscarRazaPorId(listadoRaza,sizeRaza,valueId);

     while(indexId != valueId)
    {
        printf("%s", mensajeError);
        scanf("%d", &valueId);
        indexId=buscarRazaPorId(listadoRaza,sizeRaza,valueId);
    }

    return valueId;
}

/** \brief Verifica que la id recibida exista en el array de tipo eRaza.
 *
 * \param listadoRaza[] eRaza
 * \param sizeRaza int
 * \param id int
 * \return int Devuelve el valor de la id.
 *
 */
int buscarRazaPorId(eRaza listadoRaza[], int sizeRaza,int id)
{
    int i;
    int index = -1;


    for (i = 0; i < sizeRaza; i++)
    {
        if(listadoRaza[i].id==id)
        {
            index = listadoRaza[i].id;
            break;
        }
    }

    return index;
}
