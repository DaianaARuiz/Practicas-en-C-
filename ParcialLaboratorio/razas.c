#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20

#define TRUE 1
#define FALSE 0

//////////////////////////////HARCODEO////////////////////////////////////////HARCODEO/////////////////////////////////////
void HarcodearRazas(eRazas listaRazas[])
{
    char descripcionRaza[][10]={"siames","doberman","persa","pastor","dogo","ovejero"};
    char tamanioRaza[][8]={"chico","grande","mediano","grande","grande","grande"};
    char paisOrigenRaza[][10]={"tailandia","alemania","persia","belgica","argentina","alemania"};
    int idRaza[]={150,135,180,175,130,140};
    int idPais[]={40,20,50,30,10,20};

     for(int i=0;i<6;i++)
    {
        strcpy(listaRazas[i].descripcionRaza,descripcionRaza[i]);
        strcpy(listaRazas[i].tamanioRaza,tamanioRaza[i]);
        strcpy(listaRazas[i].paisOrigenRaza,paisOrigenRaza[i]);
        listaRazas[i].idRaza=idRaza[i];
        listaRazas[i].idPais=idPais[i];
        listaRazas[i].isEmpty=FALSE;
    }
}

 ////////////////////////////ALTA RAZA///////////////////////////////////////ALTA RAZA///////////////////////////////////////
int InicializarArrayRaza(eRazas listaRaza[],int tamanioArray)
{
    int retorno;
	retorno=-1;
    for(int i=0;i <tamanioArray; i++)
    {
        listaRaza[i].isEmpty =TRUE;
        retorno=0;
    }

    return retorno;
}

 int BuscarLibreRaza(eRazas listaRaza[], int tamanioArray)
 {
     int index=-1;
     for(int i=0;i<tamanioArray;i++)
     {
         if(listaRaza[i].isEmpty==TRUE)
         {
             index=i;
             break;
         }
     }
     return index;
 }

 eRazas AltaRaza(eRazas listaRaza[],int tamanioArray, int indiceLibre)
 {
    eRazas unaRaza;
    PedirString("\nIngrese la descripcion de la raza: ","Error. Reingrese descripcion: ",15, unaRaza.descripcionRaza);
    ObtenerTamanioRazaValido("Ingrese el tamanio de la raza(chico-mediano-grande): ","Error. Reingrese tamanio: ", unaRaza.tamanioRaza);
    PedirString("Ingrese el pais de origen de la raza: ","Error. Reingrese pais de origen: ",15, unaRaza.paisOrigenRaza);
    unaRaza.idRaza=PedirEntero("Ingrese el id de la raza : ","Error, reingrese id valido:");
    unaRaza.idPais=PedirEntero("Ingrese el id del pais : ","Error, reingrese id valido:");
    unaRaza.isEmpty=FALSE;

    listaRaza[indiceLibre]=unaRaza;
    return unaRaza;
 }

///////////////////////BAJA EN CASCADA//////////////////////////////////////BAJA EN CASCADA///////////////////////////////////////
int EliminarUnaRaza(eRazas listaRaza[],int tamRaza, int idEliminar, eMascotas listaMascotas[],int tamMasc)
{
    int retorno=0;
    int indiceIDRazaAEliminar=BuscarRazaPorID(idEliminar,tamRaza,listaRaza);

    if(  indiceIDRazaAEliminar !=-1)
    {
        retorno=1;
        listaRaza[indiceIDRazaAEliminar].isEmpty=TRUE;
        EliminarMascotasDeUnaRaza(listaMascotas,tamMasc,idEliminar);
    }
    return retorno;
}

int BuscarRazaPorID(int idIngresado, int tam, eRazas listaRaza[])
{
    int indiceIDbuscado=-1;
    for(int i=0;i<tam;i++)
    {
       if(listaRaza[i].idRaza==idIngresado)
       {
            indiceIDbuscado=i;
            break;
       }
    }
    return indiceIDbuscado;
}
///////////////////////INFORMAR//////////////////////////////////////INFORMAR/////////////////////////////////////////////


void ListarRazas(eRazas listaRazas[], int tamanioArray)
{
    printf("\n***********************************************************************");
    printf("\n\t \tListado de razas registradas: \n\n");
    printf("ID \tDESCRIPCION\tTAMANIO\t\tPAIS DE ORIGEN \n");
    for(int i=0;i<tamanioArray;i++)
    {
        if(listaRazas[i].isEmpty==FALSE )
        {
            ImprimirUnaRaza(listaRazas[i]);
        }
    }
    printf("\n***********************************************************************");
}

void ImprimirUnaRaza(eRazas unaRaza)
{
     printf("%2d %10s %15s %20s \n",unaRaza.idRaza,
                                    unaRaza.descripcionRaza,
                                    unaRaza.tamanioRaza,
                                    unaRaza.paisOrigenRaza);
}
