#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Inputs.h"
#include "Validations.h"
#include "ShowData.h"
#include "Clientes.h"
#include "Mascotas.h"
#include "Tipo.h"


/** \brief inicializa un array de tipo eTipo.
 *
 * \param listadoTipo[] eTipo
 * \param sizeTipo int
 * \return void
 *
 */
void inicializarTipo(eTipo listadoTipo[], int sizeTipo)
{
    int i;

    for(i=0; i<sizeTipo; i++)
    {
    listadoTipo[i].estado = LIBRE;
    }
}


/** \brief harcodea un array de tipo eTipo
 *
 * \param listadoTipo[] eTipo
 * \param sizeTipo int
 * \return void
 *
 */
void hardCodearTipo(eTipo listadoTipo[], int sizeTipo)
{
  int id[3]={1,2,3};
  char tipo[3][15] = {"Gato","Perro","Raro"};
  char descripcion[3][50] = {"Los gatos son felinos.","Los perros son caninos.","Los raros son aves, anfibios, marsupiales,etc."};


  int i;

  for(i=0; i<sizeTipo; i++)
  {
      listadoTipo[i].id = id[i];
      strcpy(listadoTipo[i].tipo, tipo[i]);
      strcpy(listadoTipo[i].descripcion, descripcion[i]);
      listadoTipo[i].estado = OCUPADO;
  }

}
