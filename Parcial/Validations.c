#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include"Validations.h"


/** \brief Verifica si la cadena ingresada es un numero entero.
 *
 * \param numero[] char
 * \return int Devuelve 1 si la cadena es numerica o 0 (cero) si no lo es.
 *
 */
int validateNumbersInt(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {
        if(!(numero[i]>=48 && numero[i]<=57))
        {
            printf("SOLO INGRESA NUMEROS\n");
            return 0;
        }
    }
    return 1;
}

/** \brief Verifica si la cadena ingresada es un numero flotante.
 *
 * \param numero[] char
 * \return int Devuelve 1 si la cadena es numerica o 0 (cero) si no lo es.
 *
 */
int validateNumbersFloat(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {

            if(!(numero[i]>=48 && numero[i]<=57 ))
            {
                if(numero[i]!='.'|| numero[i-1]=='.')
                {
                printf("SOLO INGRESA NUMEROS\n");
                return 0;
                }

            }
    }
    return 1;
}

/** \brief Verifica que la cadena contenga solo letra o espacios.
 *
 * \param array[] char
 * \return int Devuelve 1 si la cadena contiene solo letras o si no 0 (cero).
 *
 */
int validateStringOfLetters(char array[])
{
    int i;
    for(i=0 ; i<strlen(array); i++)
    {
        if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
        {
            if(array[i]!=' ' || array[i-1]==' ')
            {
            printf("SOLO INGRESA LETRAS O CON MAXIMO UN ESPACIO ENTRE ELLAS\n");
            return 0;
            }
        }
    }
    return 1;
}

