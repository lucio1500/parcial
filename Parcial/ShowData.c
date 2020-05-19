#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

/** \brief Muestra el menu principal del programa.
 *
 * \param void
 * \return void
 *
 */
void showMenu(void)
{
        printf("\n1.Cargar CLIENTE\n");
        printf("2.ELiminar CLIENTE\n");
        printf("3.Mostrar CLIENTES\n");
        printf("4.Modificar  CLIENTE\n");
        printf("5.Cargar MASCOTA\n");
        printf("6.ELiminar MASCOTA\n");
        printf("7.Modificar  MASCOTA\n");
        printf("8.Mostrar MASCOTAS\n");
        printf("9.Mostrar CLIENTES con MASCOTAS\n");
        printf("10.Ordenar MASCOTAS por tipo y listarlas con sus duenos\n");
        printf("11.Listar CLIENTES con mas de una Mascota\n");
        printf("12.Listar MASCOTAS con mas de 3 anios\n");
        printf("13.Listar MASCOTAS de un tipo particular (Perro,Gato,Raro)\n");
        printf("14.Ordenar a los CLIENTES por cantidades de mascotas y mostrarlos. \n");
        printf("15.Ordenar a los CLIENTES por cantidades de mascotas y por orden alfabetico de los nombres y mostrarlos. \n");
        printf("16.El promedio de edad entre las MASCOTAS\n");
        printf("17.El promedio de edad entre las MASCOTAS, por tipo\n");
        printf("18.El promedio que tengo entre varones y mujeres de mis CLIENTES\n");
        printf("19.Modificar Raza.\n");
        printf("20.SALIR\n");

}


/** \brief Muestra el menu principal de las mascotas.
 *
 * \param void
 * \return void
 *
 */
void showMenuMascotas(void)
{
        printf("\n1.PERRO\n");
        printf("2.GATO\n");
        printf("3.RARO\n");
        printf("4.SALIR\n");

}


void showMenuClientes(void)
{
        printf("\n1.Cargar Cliente\n");
        printf("2.ELiminar Cliente\n");
        printf("3.Mostrar Clientes\n");
        printf("4.Modificar  Cliente\n");
        printf("5.SALIR\n");
}


void showMenuVerificar(void)
{
        printf("\n1.Ver lista de Clientes\n");
        printf("2.Volver atras\n");
}


/** \brief Muestra el menu de campos que se pueden modificar.
 *
 * \param void
 * \return void
 *
 */
void showModificarMascota(void)
{
        printf("\n¿Que desea modificar?\n");
        printf("1.Nombre \n");
        printf("2.Tipo \n");
        printf("3.Raza\n");
        printf("4.Edad\n");
        printf("5.Peso\n");
        printf("6.Sexo\n");
        printf("7.Duenio\n");
        printf("8.SALIR\n");

}

/** \brief Muestra el menu de campos que se pueden modificar.
 *
 * \param void
 * \return void
 *
 */
void showModificarRaza(void)
{
        printf("\n¿Que desea modificar?\n");
        printf("1.Nombre \n");
        printf("2.Pais \n");
        printf("3.Tipo\n");
        printf("4.SALIR\n");

}

void showModificarCliente(void)
{
        printf("\n¿Que desea modificar?\n");
        printf("1.Nombre \n");
        printf("2.Apellido \n");
        printf("3.Localidad \n");
        printf("4.Telefono\n");
        printf("5.Edad\n");
        printf("6.Sexo\n");
        printf("7.SALIR\n");

}

void showSexo(void)
{
        printf("1.Hombre \n");
        printf("2.Mujer \n");
}

