#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20

#define TRUE 1
#define FALSE 0
void HarcodearPaises(ePaisOrigen listaPaises[])
{
    char nombreDePais[][15]={"argentina","alemania","belgica","tailandia","persia"};
    char continente[][8]={"america","europa","europa","asia","asia"};
    int codigoTelefonico[]={54,49,32,66,98};
    int idPais[]={10,20,30,40,50};

     for(int i=0;i<5;i++)
    {
        strcpy(listaPaises[i].nombreDePais,nombreDePais[i]);
        strcpy(listaPaises[i].continente,continente[i]);
        listaPaises[i].codigoTelefonico=codigoTelefonico[i];
        listaPaises[i].idPais=idPais[i];
        listaPaises[i].isEmpty=FALSE;
    }
}

void MostrarListadoPaisesDisponibles(ePaisOrigen listaPaises[], int tamPais)
{
    printf("\n***********************************************************************");
    printf("\n\t \tListado de paises disponibles: \n\n");
    printf("ID \tNOMBRE\tCONTINENTE\t\tCODIGO TELEFONICO \n");
    for(int i=0;i<tamPais;i++)
    {
        ImprimirUnPais(listaPaises[i]);
    }
    printf("\n***********************************************************************");
}

void ImprimirUnPais(ePaisOrigen unPais)
{
    printf("%2d %10s %15s %10d \n", unPais.idPais,
                                    unPais.nombreDePais,
                                    unPais.continente,
                                    unPais.codigoTelefonico);
}
