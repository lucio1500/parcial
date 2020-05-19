#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Clientes.h"
#include "Mascotas.h"


/** \brief inicializa un array de tipo mascota.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \return void
 *
 */
void inicializarMascota(mascota listadoMascota[], int sizeMascota)
{
    int i;

    for(i=0; i<sizeMascota; i++)
    {
    listadoMascota[i].estado = LIBRE;
    }
}


/** \brief harcodea un array de tipo Mascota
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \return void
 *
 */
void hardCodearMascota(mascota listadoMascota[], int sizeMascota)
{
  int id[11]={500,501,502,503,504,505,506,507,508,509,510};
  char nombre[11][15] = {"Mosa","Cab","Jason","Fabian","Franco","Agus","Platon","Tec","Mose","Mou","juan"};
  char tipo[11][15] = {"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
  int raza[11] = {11,12,14,13,12,15,20,18,13,16,17};
  float peso[11]={10,4,9,8,7,8,10.5,30,40,19,11};
  int edad[11]={2,8,6,9,10,5,7,10,16,10,11};
  char sexo [11] [10] = {"mujer","mujer","hombre","hombre","hombre","hombre","hombre","hombre","hombre","hombre","hombre"};
  int cliente[11] = {1002,1002,1000,1000,1000,1001,1001,1004,1003,1003,1003};
  int i;

  for(i=0; i<sizeMascota; i++)
  {
      listadoMascota[i].id = id[i];
      strcpy(listadoMascota[i].nombre, nombre[i]);
      strcpy(listadoMascota[i].tipo, tipo[i]);
      listadoMascota[i].idRaza = raza[i];
      listadoMascota[i].peso = peso[i];
      listadoMascota[i].edad = edad[i];
      strcpy(listadoMascota[i].sexo, sexo[i]);
      listadoMascota[i].idCliente = cliente[i];
      listadoMascota[i].estado = OCUPADO;
  }

}


/** \brief Elimina de manera lógica una mascota recibiendo como parámetro su Id.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param id int
 * \return int (0) si esta todo ok o (-1) si hubo algun error.
 *
 */
int eliminarMascota(mascota listadoMascota[], int sizeMascota,int id)
{
    int i;

         for(i=0; i<sizeMascota;i++)
        {
            if(id == listadoMascota[i].id)
            {
            listadoMascota[i].estado=LIBRE;
            return 0;
            break;
            }
        }
    return -1;
}


/** \brief Busca un espacio libre en un array de tipo mascota
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \return int En caso de encontrarlo devuelve el indice del espacio libre o (-1) si no hay mas espacio.
 *
 */
int buscarLibreMascota(mascota listadoMascota[], int sizeMascota)
{
  int i;
  int index = -1;

  for(i=0; i<sizeMascota; i++)
  {
      if(listadoMascota[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}

/** \brief Pide una id al usuario y valida su existencia.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param mensaje[] char
 * \param [] char mensajeError
 * \return int Devuelve el valor de la id.
 *
 */
int validarIdMascota(mascota listadoMascota[],int sizeMascota,char mensaje[], char mensajeError [])
{
    int indexId;
    int valueId;
    printf("%s ",mensaje);
    scanf("%d",&valueId);

    indexId=buscarMascotaPorId(listadoMascota,sizeMascota,valueId);

     while(indexId != valueId)
    {
        printf("%s", mensajeError);
        scanf("%d", &valueId);
        indexId=buscarMascotaPorId(listadoMascota,sizeMascota,valueId);
    }

    return valueId;
}

/** \brief Verifica que la id recibida exista en el array de tipo mascota.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \param id int
 * \return int Devuelve el valor de la id.
 *
 */
int buscarMascotaPorId(mascota listadoMascota[], int sizeMascota,int id)
{
    int i;
    int index = -1;


    for (i = 0; i < sizeMascota; i++)
    {
        if(listadoMascota[i].id==id)
        {
            index = listadoMascota[i].id;
            break;
        }
    }

    return index;
}


/** \brief Ordena las mascotas segun su tipo de manera ascendente.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascota int
 * \return void
 *
 */
void ordenarMascotasPorTipo(mascota listadoMascota[], int sizeMascota)
{
    int i;
    int j;
    mascota auxMascota;

    for(i=0; i<sizeMascota-1; i++)
    {
        for(j=i+1; j<sizeMascota; j++)
        {
            if(strcmp(listadoMascota[i].tipo,listadoMascota[j].tipo)>0)
            {
                auxMascota = listadoMascota[i];
                listadoMascota[i] = listadoMascota[j];
                listadoMascota[j] = auxMascota;
            }
        }

    }
}


/** \brief Calcula el promedio de las edades de las mascotas
 *
 * \param listadoMascota[] mascota
 * \param sizeMascotas int
 * \return float Devuelve el promedio.
 *
 */
float promedioEdad(mascota listadoMascota[],int sizeMascotas)
{
    int i;
    int acumuladorEdad=0;
    int contadorEdad=0;
    float promedioEdadMascotas=0;

    for(i=0;i<sizeMascotas;i++)
    {
        if(listadoMascota[i].estado==OCUPADO && listadoMascota[i].edad>0)
        {
        acumuladorEdad=acumuladorEdad+listadoMascota[i].edad;
        contadorEdad++;
        }
    }

    promedioEdadMascotas=(float)acumuladorEdad/contadorEdad;

    return promedioEdadMascotas;
}


/** \brief Calcula el promedio de edades segun el tipo de mascota recibido.
 *
 * \param listadoMascota[] mascota
 * \param sizeMascotas int
 * \param tipoM[] char
 * \return float Devuelve el promedio.
 *
 */
float promedioEdadPorTipo(mascota listadoMascota[],int sizeMascotas,char tipoM[])
{
    int i;
    int acumuladorEdad=0;
    int contadorEdad=0;
    float promedioEdadMascotasPorTipo=0;

    for(i=0;i<sizeMascotas;i++)
    {
            if(listadoMascota[i].estado==OCUPADO && listadoMascota[i].edad>0 && stricmp(listadoMascota[i].tipo,tipoM)==0)
            {
            acumuladorEdad=acumuladorEdad+listadoMascota[i].edad;
            contadorEdad++;
            }
    }

    return promedioEdadMascotasPorTipo=(float)acumuladorEdad/contadorEdad;


}
