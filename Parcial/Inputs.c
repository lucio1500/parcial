#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Validations.h"


/** \brief Pide el ingreso de un numero luego de verificarlo devuelve un entero.
 *
 * \param num int
 * \param message[] char
 * \param messageError[] char
 * \param min int
 * \param max int
 * \return int Devuelve un entero validado.
 *
 */
int getInt(int num,char message[],char messageError[],int min,int max)
{
    char cadena[50];
    int flag=0;
    printf("%s",message);
    flag=getIntAndRange(flag,cadena,num,min,max);
    num=atoi(cadena);

    while(flag==0||flag==1)
    {
    printf("%s",messageError);
    flag=getIntAndRange(flag,cadena,num,min,max);
    num=atoi(cadena);
    }

    num=atoi(cadena);

    return num;
}





/** \brief Valida un numero entero dentro de un rango.
 *
 * \param flag int
 * \param cadena[] char
 * \param num int
 * \param min int
 * \param max int
 * \return int Devuelve 1 si es un numero entero o 2 si es un numero entero y esta dentro del rango.
 *
 */
int getIntAndRange(int flag,char cadena[],int num,int min,int max)
{
    int validate=0;
    fflush(stdin);
    gets(cadena);
    validate=validateNumbersInt(cadena);

    if(validate==1)
    {
    flag=1;
     num=atoi(cadena);
        if(num>=min&&num<=max)
        {
        flag=2;
        return flag;
        }
    }

    return flag;

}


/** \brief Pide el ingreso de un numero luego de validarlo devuelve un numero flotante.
 *
 * \param num float
 * \param message[] char
 * \param messageError[] char
 * \param min float
 * \param max float
 * \return float Devuelve el numero flotante validado.
 *
 */
float getFloat(float num,char message[],char messageError[],float min,float max)
{
    char cadena[50];
    int flag=0;
    printf("%s",message);
    flag=getFloatAndRange(flag,cadena,num,min,max);
    num=atof(cadena);

    while(flag==0||flag==1)
    {
    printf("%s",messageError);
    flag=getFloatAndRange(flag,cadena,num,min,max);
    num=atof(cadena);
    }

    num=atof(cadena);

    return num;
}


/** \brief Valida un numero flotante dentro de un rango.
 *
 * \param flag int
 * \param cadena[] char
 * \param num float
 * \param min float
 * \param max float
 * \return int Devuelve 1 si es un numero flotante o 2 si es un numero flotante y esta dentro del rango.
 *
 */
int getFloatAndRange(int flag,char cadena[],float num,float min,float max)
{
    int validate=0;
    fflush(stdin);
    gets(cadena);
    validate=validateNumbersFloat(cadena);

    if(validate==1)
    {
    flag=1;
     num=atoi(cadena);
        if(num>=min&&num<=max)
        {
        flag=2;
        return flag;
        }
    }

    return flag;

}

/** \brief Pide el ingreso de una cadena y la guarda en una variable.
 *
 * \param dato[] char
 * \param mensaje[] char
 * \return void
 *
 */
void getString(char dato[], char mensaje[])
{
     printf("%s", mensaje);
     fflush(stdin);
     gets(dato);
}



/** \brief pide el ingreso de una cadena que contenga solo letras.
 *
 * \param array[] char
 * \param message[] char
 * \param messageError[] char
 * \return void
 *
 */
void getStringOfLetters(char array[],char message[],char messageError[])
{
    int validate=0;

    printf("%s",message);
    fflush(stdin);
    gets(array);
    validate=validateStringOfLetters(array);

    while(validate==0)
    {
    printf("%s",messageError);
    fflush(stdin);
    gets(array);
    validate=validateStringOfLetters(array);
    }

}


/** \brief Permite elejir un sexo.
 *
 * \param array[] char
 * \param message[] char
 * \param messageError[] char
 * \return void
 *
 */
void getSexo(char array[],char message[],char messageError[])
{
    int opcion;

    showSexo();
    opcion=getInt(opcion,message,messageError,1,2);

    switch(opcion)
    {
    case 1:
        strcpy(array,"hombre");
    break;
    case 2:
        strcpy(array,"mujer");
    break;
    }

}


/** \brief recibe una id inicializada y le suma uno.
 *
 * \param id int
 * \return int Devuelve una id nueva.
 *
 */
int generateId(int id)
{
    id++;

    return id;
}
