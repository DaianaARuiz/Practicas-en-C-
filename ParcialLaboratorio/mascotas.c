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
void HarcodearMascotas(eMascotas listaMasc[])
{
    int idMascota[]={100,200,300,400,500,600,700};
    char nombre[][20]={"Michi","Yoyo","Dobby","Mimi","Tomy","Roman","Genaro"};
    int edad[]={3,2,4,7,2,8,9};
    char sexo[]={'f','m','f','m','m','m','m'};
    char tipo[][10]={"gato","perro","gato","perro","gato","perro","perro"};
    int idRaza[]={1000,1100,1200,1300,1400,1500,1500};
    int peso[]={10,20,5,16,7,8,13};


    for(int i=0;i<7;i++)
    {
        listaMasc[i].idMascota=idMascota[i];
        strcpy(listaMasc[i].nombreMascota,nombre[i]);
        listaMasc[i].edad=edad[i];
        strcpy(listaMasc[i].tipoMascota,tipo[i]);
        listaMasc[i].sexoMascota=sexo[i];
        listaMasc[i].peso=peso[i];
        listaMasc[i].idRaza=idRaza[i];

        listaMasc[i].isEmpty=FALSE;
    }
}

//////////////////////ALTA MASCOTA////////////////////////////////////////ALTA MASCOTA////////////////////////////////////////////
int InicializarArrayMascotas(eMascotas listaMasc[],int tamanioArray)
{
    int retorno;
	retorno=-1;
    for(int i=0;i <tamanioArray; i++)
    {
        listaMasc[i].isEmpty =TRUE;
        retorno=0;
    }
    return retorno;
}

 int BuscarLibreMascota(eMascotas listaMasc[], int tamanioArray)
 {
     int index=-1;
     for(int i=0;i<tamanioArray;i++)
     {
         if(listaMasc[i].isEmpty==TRUE)
         {
             index=i;
             break;
         }
     }
     return index;
 }

 eMascotas AltaMascotas(eMascotas listaMasc[],int tamMascota, int indiceLibre,int tamRaza, eRazas listaRazas[])
 {
    eMascotas unaMascota;

    PedirString("\nIngrese nombre mascota: ","Error. Reingrese nombre: ",20, unaMascota.nombreMascota);
    ObtenerTipoValido("Ingrese el tipo de mascota('gato','perro','raro'): ","Error. Reingrese tipo: ('gato','perro','raro')",unaMascota.tipoMascota);
    unaMascota.edad= PedirEntero("Ingrese edad de la mascota: ","Error, reingrese edad valida:");
    unaMascota.sexoMascota= ObtenerSexoValido("Ingrese sexo mascota(f o m): ", "Erro. Sexo no valido. Reingrese: ");
    unaMascota.peso= PedirFlotante("Ingrese el peso de la mascota: ","Error, reingrese peso valido:");

    ListarRazas(listaRazas,tamRaza);
    unaMascota.idRaza=ObtenerIdRazaValido("\nIngrese el id de la raza de la mascota: ","Error, reingrese id valido:",listaRazas,tamRaza);

    unaMascota.isEmpty=FALSE;
    unaMascota.idMascota=calcularNuevoIDMascota(listaMasc,tamMascota);

    listaMasc[indiceLibre]=unaMascota;

    return unaMascota;
 }

 int BuscarIdMayorMascota(eMascotas listaMascotas[],int tamMascota)
{
    int IdAux=0;
    int IdMax=0;

    for(int i=0 ; i<tamMascota; i++)
    {
        if(listaMascotas[i].isEmpty==FALSE)
        {
            IdAux=listaMascotas[i].idMascota;
            if(IdAux > IdMax)
            {
                IdMax = IdAux;
            }
        }
    }
    return IdMax;
}


int calcularNuevoIDMascota(eMascotas listaMascotas[],int tamMascota)
{
    int mayorID;

    mayorID=BuscarIdMayorMascota(listaMascotas,tamMascota);

    return mayorID + 100;
}

 ////////////////////MODIFICAR MASCOTA////////////////////////////////MODIFICAR MASCOTA//////////////////////////////////////////
int ModificarUnaMascota( eMascotas listaMasc[],int idAModificar,int opcion, int tamanioArray,eRazas listaRazas[],int tamRaza)
{
    int indiceIDbuscado=BuscarPorIDMascota(idAModificar,tamanioArray,listaMasc);
    char nombreModificado[10];
    char tipoModificado[10];
    int retorno=-1;

    switch(opcion)
    {
        case 1:
            PedirString("Ingrese el nuevo nombre:","Error. Reingrese nombre: ",51,nombreModificado);
            strcpy(listaMasc[indiceIDbuscado].nombreMascota,nombreModificado);
            retorno=0;
            break;
        case 2:
             listaMasc[indiceIDbuscado].edad=PedirEntero("Ingrese nueva edad: ","Error, reingrese edad valida: ");
             retorno=0;
             break;
        case 3:
            ObtenerTipoValido("Ingrese el tipo de mascota: ","Error. Reingrese tipo: ",tipoModificado);
            strcpy(listaMasc[indiceIDbuscado].tipoMascota,tipoModificado);
            retorno=0;
            break;
        case 4:
            listaMasc[indiceIDbuscado].sexoMascota= ObtenerSexoValido("Ingrese sexo mascota(f o m): ", "Erro. Sexo no valido. Reingrese: ");
            retorno=0;
           break;
        case 5:
            listaMasc[indiceIDbuscado].peso=PedirFlotante("Ingrese nuevo peso: ","Error, reingrese peso valido: ");
            retorno=0;
            break;
        case 6:
            ListarRazas(listaRazas,tamRaza);
            listaMasc[indiceIDbuscado].idRaza=ObtenerIdRazaValido("\nIngrese el id de la raza de la mascota: ","Error, reingrese id valido:",listaRazas,tamRaza);
            retorno=0;
            break;
        default:
                printf("\nOpcion no valida. Intente nuevamente\n");
                break;
    }
    return retorno;
}

/////////////////////BAJA MASCOTA////////////////////////////////////////////////BAJA MASCOTA/////////////////////////////////////////////
int eliminarUnaMascota(eMascotas listaMasc[],int tamMasc, int idEliminar)
{
    int retorno=0;
    int indiceIDbuscado=BuscarPorIDMascota(idEliminar,tamMasc,listaMasc);
    if(indiceIDbuscado!=-1)
    {
        retorno=1;
        listaMasc[indiceIDbuscado].isEmpty=TRUE;
    }
    return retorno;
}

int BuscarPorIDMascota(int idIngresado, int tam, eMascotas listaMasc[])
{
    int indiceIDbuscado=-1;
    for(int i=0;i<tam;i++)
    {
       if(listaMasc[i].idMascota==idIngresado)
       {
            indiceIDbuscado=i;
            break;
       }
    }
    return indiceIDbuscado;
}
///////////////////////INFORMAR//////////////////////////////////////INFORMAR/////////////////////////////////////////////
void ListarMascotas(eMascotas listaMasc[], int tamanioArray)
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de mascotas: \n\n");
    printf("ID \tNOMBRE\tTIPO\t EDAD \tSEXO\t PESO\n");
    for(int i=0;i<tamanioArray;i++)
    {
        if(listaMasc[i].isEmpty==FALSE)
        {
            imprimirUnaMascota(listaMasc[i]);
        }
    }
    printf("\n*********************************************************************************");
}

void imprimirUnaMascota(eMascotas unaMascota)
{
     printf("%4d %8s %8s %4d %4c %14f\n",   unaMascota.idMascota,
                                            unaMascota.nombreMascota,
                                            unaMascota.tipoMascota,
                                            unaMascota.edad,
                                            unaMascota.sexoMascota,
                                            unaMascota.peso);
}

