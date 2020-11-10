#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20
#define TRUE 1
#define FALSE 0


/////Se debe mostrar un listado de mascotas con sus razas y países de origen:
void ListarMascotasConRaza(eMascotas listaMasc[], int tamMasc, eRazas listaRazas[], int tamRaza)
{
    int idRaza;
    eRazas unaRaza;

    printf("\n*********************************************************************************************************");
    printf("\n\t\tListado de mascotas con su raza y pais de origen: \n\n");
    printf("ID\tNOMBRE\t\tTIPO\tEDAD\tSEXO\t\tPESO\t\tRAZA\t\tPAIS ORIGEN\n");
    for(int i=0;i<tamMasc;i++)
    {
        idRaza=listaMasc[i].idRaza;
        unaRaza=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza);
        if(listaMasc[i].isEmpty==FALSE)
        {
            ImprimirMascotaConRaza(listaMasc[i],unaRaza);
        }
    }
    printf("\n*********************************************************************************************************");
}

eRazas EncontrarRazaDeUnaMascota(eRazas listaRazas[],int tamRaza, int idRaza)
{
    eRazas razaMascota;

    for(int j=0;j<tamRaza;j++)
    {
        if(idRaza==listaRazas[j].idRaza)
        {
            razaMascota=listaRazas[j];
        }
    }

    return razaMascota;
}

void ImprimirMascotaConRaza(eMascotas unaMascota,eRazas unaRaza)
{
    printf("%4d %10s %12s %5d %7c %17f %18s %15s\n",unaMascota.idMascota,
                                                    unaMascota.nombreMascota,
                                                    unaMascota.tipoMascota,
                                                    unaMascota.edad,
                                                    unaMascota.sexoMascota,
                                                    unaMascota.peso,
                                                    unaRaza.descripcionRaza,
                                                    unaRaza.paisOrigenRaza);
}


////Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa raza:

void ListarPorCadaRazaLasMascotas(eMascotas listaMasc[], int tamMasc, eRazas listaRazas[], int tamRaza)
{
    int idRaza;

    printf("\n***********************************************************\n");
    printf("  Listado de cada raza con las mascotas de esa raza:\n\n");
    printf("ID     NOMBRE   TIPO   EDAD   SEXO    PESO\t\n");
    for(int j=0;j<tamRaza;j++)
    {
        printf(" ----------------------%s---------------------- \n", listaRazas[j].descripcionRaza);
        idRaza=listaRazas[j].idRaza;
        if(listaRazas[j].isEmpty==FALSE)
        {
            ImprimirMascotasDeUnaRaza(listaMasc,tamMasc,idRaza);
        }
    }
    printf("\n***********************************************************\n");
}

void ImprimirMascotasDeUnaRaza(eMascotas listaMasc[],int tamMasc,int idRaza)
{
    for(int i=0;i<tamMasc;i++)
    {
        if( listaMasc[i].idRaza==idRaza && listaMasc[i].isEmpty==FALSE)
        {
            imprimirUnaMascota(listaMasc[i]);
        }
    }
}

void EliminarMascotasDeUnaRaza(eMascotas listaMasc[],int tamMasc,int idRaza)
{
    for(int i=0;i<tamMasc;i++)
    {
        if(listaMasc[i].idRaza==idRaza)
        {
            listaMasc[i].isEmpty=TRUE;
        }
    }
}

//Se debe mostrar un listado de mascotas ordenadas por peso:
int OrdenarMascotasPorPeso(eMascotas listaMasc[], int tamanioArray)
{
    int retorno=0;
    eMascotas auxMascota;
    for(int i=0;i<tamanioArray-1;i++)
    {
       for(int j=i+1;j<tamanioArray;j++)
       {
           if(listaMasc[i].peso<listaMasc[j].peso)
           {
               auxMascota=listaMasc[i];
               listaMasc[i]=listaMasc[j];
               listaMasc[j]=auxMascota;
               retorno=1;
           }
        }
    }
    return retorno;
}

//Mostrar el país de origen que tenga más mascotas:
void MostrarPaisConMasMascotas(eMascotas listaMasc[],int tamMasc,eRazas listaRaza[],int tamRaza)
{
    int contadorMascotasPorPais[TAM_RAZA]={0};
    int idRaza;
    int mayorCantidadMascotas=0;
    int indicePais=0;
    char paisConMayorCantidadMascotas[15];

    for(int j=0;j<tamRaza;j++)
    {
        idRaza=listaMasc[j].idRaza;
        ContarMascotasRazas(listaMasc,tamMasc,idRaza,contadorMascotasPorPais,j);
        if(contadorMascotasPorPais[j]>mayorCantidadMascotas)
        {
            mayorCantidadMascotas=contadorMascotasPorPais[j];
            indicePais=j;
            strcpy(paisConMayorCantidadMascotas,listaRaza[j].paisOrigenRaza);
        }
    }
    printf("\nEl pais que mas mascotas tiene es: %s con %d mascotas \n\n",paisConMayorCantidadMascotas,contadorMascotasPorPais[indicePais]);
}

void ContarMascotasRazas(eMascotas listaMasc[],int tamMasc,int idRaza,int contadorMascotasPorPais[],int j)
{
    for(int i=0;i<tamMasc;i++)
    {
        if(listaMasc[i].idRaza==idRaza)
        {
            contadorMascotasPorPais[j]++;
        }
    }
}

///////////////////////////////LISTA MASCOTAS CON RAZA Y CODIGO TELEFONICO DEL PAIS//////////////////////////////////////////////////////
void ListarMascotasConRazaYCodigoTelefonico(eMascotas listaMasc[], int tamMasc, eRazas listaRazas[], int tamRaza,ePaisOrigen listaPaises[],int tamPais)
{
    int idRaza;
    eRazas unaRaza;
    ePaisOrigen unPais;

    printf("\n***************************************************************************************************");
    printf("\n\tListado de mascotas con su raza y codigo telefonico del pais: \n\n");
    printf("ID\tNOMBRE\t\tTIPO\tEDAD\tSEXO\t\tPESO\t\tRAZA\t\tCODIGO TELEFONICO PAIS\n");
    for(int i=0;i<tamMasc;i++)
    {
        idRaza=listaMasc[i].idRaza;
        unaRaza=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza);
        unPais=EncontrarPaisDeUnaRaza(unaRaza,listaPaises,tamPais);

        if(listaMasc[i].isEmpty==FALSE && unaRaza.isEmpty==FALSE && unPais.isEmpty==FALSE )
        {
            ImprimirListadoMascotasRazaPais(listaMasc[i],unaRaza,unPais);
        }
    }
    printf("\n***************************************************************************************************");
}

void ImprimirListadoMascotasRazaPais(eMascotas unaMascota,eRazas unaRaza,ePaisOrigen unPais)
{
     printf("%4d %10s %12s %5d %7c %17f %18s %15d\n",   unaMascota.idMascota,
                                                        unaMascota.nombreMascota,
                                                        unaMascota.tipoMascota,
                                                        unaMascota.edad,
                                                        unaMascota.sexoMascota,
                                                        unaMascota.peso,
                                                        unaRaza.descripcionRaza,
                                                        unPais.codigoTelefonico);
}

///////////////////////////////LISTA MASCOTAS ORDENADAS POR CODIGO TELEFONICO////////////////////////////////////////////////////////////

void ListarMascotasOrdenadasPorCodigoTelefonico(eMascotas listaMasc[], int tamMasc, eRazas listaRazas[], int tamRaza,ePaisOrigen listaPaises[],int tamPais)
{
    int idRaza;
    eRazas unaRaza;
    ePaisOrigen unPais;

    printf("\n***************************************************************************************************");
    printf("\n\t Listado de mascotas ordenadas segun codigo telefonico: \n\n");
    printf("ID\tNOMBRE\t\tTIPO\tEDAD\tSEXO\t\tPESO\t\tCODIGO TELEFONICO PAIS\n");
    for(int i=0;i<tamMasc;i++)
    {
        idRaza=listaMasc[i].idRaza;
        unaRaza=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza);
        unPais=EncontrarPaisDeUnaRaza(unaRaza,listaPaises,tamPais);
        if(listaMasc[i].isEmpty==FALSE && (OrdenarMascotasPorCodigoTelefonico(listaMasc,unPais,tamMasc))==1 )
        {
           ImprimirListadoMascotasCodigoTelefonico(listaMasc[i],unPais);
        }
    }
    printf("\n***************************************************************************************************");
}

void ImprimirListadoMascotasCodigoTelefonico(eMascotas unaMascota,ePaisOrigen unPais)
{
     printf("%4d %10s %12s %5d %7c %17f %15d\n",unaMascota.idMascota,
                                                unaMascota.nombreMascota,
                                                unaMascota.tipoMascota,
                                                unaMascota.edad,
                                                unaMascota.sexoMascota,
                                                unaMascota.peso,
                                                unPais.codigoTelefonico);
}


ePaisOrigen EncontrarPaisDeUnaRaza(eRazas unaRaza,ePaisOrigen listaPaises[],int tamPais)
{
    ePaisOrigen paisRaza;
     for(int i=0;i<tamPais;i++)
     {
         if(unaRaza.idPais==listaPaises[i].idPais)
         {
            paisRaza=listaPaises[i];
         }
     }
     return paisRaza;
}




int OrdenarMascotasPorCodigoTelefonico(eMascotas listaMasc[],ePaisOrigen unPais,int tamMasc)
{
    eMascotas auxMascota;
    int retorno=0;
    int codigoTelefonicoMayor=0;
    for(int i=0;i<tamMasc-1;i++)
    {
        for(int j=i+1;j<tamMasc;j++)
       {
           if(unPais.codigoTelefonico>codigoTelefonicoMayor)
            {
                auxMascota=listaMasc[i];
                listaMasc[i]=listaMasc[j];
                listaMasc[j]=auxMascota;
                codigoTelefonicoMayor=unPais.codigoTelefonico;
                printf("%d el de la estrucuta",unPais.codigoTelefonico);
            }
       }
       retorno=1;
    }
    return retorno;
}

/////////////////////////////////////////////////////////PARTE 6///////////////////////////////////////////////////////////////////////

void RecogerDatosDeCadaTipo(eMascotas listaMasc[], int tamMasc)
{
    int contadorTipo[3]={0,0,0};
    float acumuladorPesoTipo[3]={0,0,0};
    float promedioDeCadaTipo[3]={0,0,0};

    for(int i=0;i<tamMasc;i++)
    {
            if(listaMasc[i].isEmpty==FALSE)
            {
                if(strcmp(listaMasc[i].tipoMascota,"gato")==0)
                {
                    contadorTipo[0]++;
                    acumuladorPesoTipo[0]=acumuladorPesoTipo[0]+ listaMasc[i].peso;
                }else
                {
                    if(strcmp(listaMasc[i].tipoMascota,"perro")==0)
                    {
                        contadorTipo[1]++;
                        acumuladorPesoTipo[1]=acumuladorPesoTipo[1]+ listaMasc[i].peso;
                    }else
                    {
                        if(strcmp(listaMasc[i].tipoMascota,"raro")==0)
                        {
                             contadorTipo[2]++;
                             acumuladorPesoTipo[2]=acumuladorPesoTipo[2]+ listaMasc[i].peso;
                        }
                    }
                }
        }
    }

    CalcularPromedioDeCadaTipo(acumuladorPesoTipo,contadorTipo,promedioDeCadaTipo);
    ImprimirDatosDeCadaTipo(acumuladorPesoTipo,contadorTipo,promedioDeCadaTipo);
}

void CalcularPromedioDeCadaTipo(float totalPesoTipo[],int cantidadTipo[],float promedioDeCadaTipo[])
{
    for(int i=0;i<3;i++)
    {
        promedioDeCadaTipo[i]=totalPesoTipo[i]/cantidadTipo[i];
        if(cantidadTipo[i]==0)
        {
            promedioDeCadaTipo[i]=0;
        }
    }
}

void ImprimirDatosDeCadaTipo(float acumuladorPesoTipo[],int contadorTipo[], float promedioDeCadaTipo[])
{
    char auxiliarTipoMascota[][10]={"gato","perro","raro"};

    printf("\n*****************************************************************\n");
    printf("    PESO TOTAL\t\tCANTIDAD DE MASCOTAS\tPROMEDIO PESO\n");
    for(int i=0;i<3;i++)
    {
        printf(" \n----------------------------%s----------------------------\n", auxiliarTipoMascota[i] );
        printf("     %8f  %20d  %20f",acumuladorPesoTipo[i], contadorTipo[i],promedioDeCadaTipo[i]);
    }
    printf("\n*****************************************************************\n");
}

///////////////////////////////////////////PARTE 7/////////////////////////////////////////////////////////

void ListarPorTamanioYPeso(eMascotas listaMascotas[],int tamMascotas,eRazas listaRazas[],int tamRaza,ePaisOrigen listaPaises[],int tamPais, char tamanioIngresado[])
{
    ePaisOrigen unPais;
    int idRaza;
    float pesoTotal=0;

    printf("\n*************************************************************************************************************\n");
    printf("ID\tNOMBRE\t\tTIPO\tEDAD\tSEXO\t\tPESO\t\tNOMBRE RAZA\t\tNOMBRE PAIS\n\n");
    for(int j=0;j<tamRaza;j++)
    {
         if(strcmp(tamanioIngresado,listaRazas[j].tamanioRaza)==0)
         {
            idRaza=listaRazas[j].idRaza;
            unPais=EncontrarPaisDeUnaRaza(listaRazas[j],listaPaises,tamPais);
            BuscarEimprimirMascotasDeUnaRaza(listaMascotas,tamMascotas,idRaza,listaRazas[j],unPais);
            SumarPesoTotalDelMismoTamanio(listaMascotas,tamMascotas,idRaza,&pesoTotal);
         }
    }
    printf("\n*************************************************************************************************************\n");
    printf("El peso total de las mascotas de tamanio %s es: %2.f kilos.\n",tamanioIngresado,pesoTotal);
}

void BuscarEimprimirMascotasDeUnaRaza(eMascotas listaMasc[],int tamMasc,int idRaza,eRazas unaRaza,ePaisOrigen unPais)
{
    for(int i=0;i<tamMasc;i++)
    {
        if( listaMasc[i].idRaza==idRaza && listaMasc[i].isEmpty==FALSE)
        {
           ImprimirUnaMascotaConRazaYPais(listaMasc[i],unaRaza,unPais);
        }
    }
}

void SumarPesoTotalDelMismoTamanio(eMascotas listaMasc[],int tamMasc,int idRaza,float *acumuladorPeso)
{
    for(int i=0;i<tamMasc;i++)
    {
        if( listaMasc[i].idRaza==idRaza && listaMasc[i].isEmpty==FALSE)
        {
             (*acumuladorPeso) = (*acumuladorPeso) + listaMasc[i].peso;
        }
    }
}

void ImprimirUnaMascotaConRazaYPais(eMascotas unaMascota,eRazas unaRaza,ePaisOrigen unPais)
{
     printf("%4d %10s %12s %5d %7c %17f %18s %24s\n",   unaMascota.idMascota,
                                                        unaMascota.nombreMascota,
                                                        unaMascota.tipoMascota,
                                                        unaMascota.edad,
                                                        unaMascota.sexoMascota,
                                                        unaMascota.peso,
                                                        unaRaza.descripcionRaza,
                                                        unPais.nombreDePais);
}


