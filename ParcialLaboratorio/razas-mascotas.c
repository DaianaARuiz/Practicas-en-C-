#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20
#define TAM_PAIS 5

#define TRUE 1
#define FALSE 0

/////////////////////////////////////listado de mascotas con sus razas y pa�ses de origen:///////////////////////////////////////
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

/////////////////////////////////////listado de RAZAS con las mascotas que pertenecen a esa raza///////////////////////////////////////

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

///////////////////////////////////////////listado de mascotas ordenadas por peso:////////////////////////////////////////////////////////
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
///////////////////////////////////////////el pa�s de origen que tenga m�s mascotas:///////////////////////////////////////////////////////////////////
/*
void MostrarPaisConMasMascotas(eMascotas listaMasc[],int tamMasc,eRazas listaRaza[],int tamRaza)
{
    int contadorMascotasPorPais[TAM_RAZA]={0};
    int idRaza;
    int mayorCantidadMascotas=0;
    int indicePais;
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
*/
void MostrarPaisConMasMascotas(eMascotas listaMasc[],int tamMasc,eRazas listaRaza[],int tamRaza,ePaisOrigen listaPais[],int tamPais)
{
    eRazas razaMascota;
    int contadorMascotasPorPais[TAM_PAIS]={0};
    char paisConMayorCantidadMascotas[15];
    int idRaza;
    int indicePais;

    for(int i=0 ;i<tamMasc;i++)
    {
        idRaza=listaMasc[i].idRaza;
        razaMascota=EncontrarRazaDeUnaMascota(listaRaza,tamRaza,idRaza);
        ContarMascotasPorPais(razaMascota,listaPais,contadorMascotasPorPais,tamPais,paisConMayorCantidadMascotas,&indicePais);
    }
    printf("\nEl pais que mas mascotas tiene es: %s con %d mascotas \n\n",paisConMayorCantidadMascotas,contadorMascotasPorPais[indicePais]);
}

void ContarMascotasPorPais(eRazas razaMascota,ePaisOrigen listaPaises[],int contadorMascotasPorPais[],int tamPais, char paisConMayorCantidadMascotas[],int *indicePais)
{
    int mayorCantidadMascotas=0;

    for(int j=0;j<tamPais;j++)
    {
        if(razaMascota.idPais==listaPaises[j].idPais)
        {
            contadorMascotasPorPais[j]++;
        }

        if(contadorMascotasPorPais[j]>mayorCantidadMascotas)
        {
            mayorCantidadMascotas=contadorMascotasPorPais[j];
            *indicePais=j;
            strcpy(paisConMayorCantidadMascotas,listaPaises[j].nombreDePais);
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

/*
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
        //unPais=EncontrarPaisDeUnaRaza(unaRaza,listaPaises,tamPais);
        if(listaMasc[i].isEmpty==FALSE && (OrdenarMascotasPorCodigoTelefonico(listaMasc,listaPaises,tamMasc))==1 )
        {
            idRaza=listaMasc[i].idRaza;
            unaRaza=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza);
            unPais=EncontrarPaisDeUnaRaza(unaRaza,listaPaises,tamPais);
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


int OrdenarMascotasPorCodigoTelefonico(eMascotas listaMasc[],ePaisOrigen unPais[],int tamMasc)
{
    eMascotas auxMascota;
    int retorno=0;

    for(int i=0;i<tamMasc-1;i++)
    {
        for(int j=i+1;j<tamMasc;j++)
       {
           if(unPais[i].codigoTelefonico  > unPais[j].codigoTelefonico)
            {
                auxMascota=listaMasc[i];
                listaMasc[i]=listaMasc[j];
                listaMasc[j]=auxMascota;
                //(*codigoTelefonicoMayor) = unPais.codigoTelefonico;
                //printf("\n%d\n",(*codigoTelefonicoMayor));
            }
       }
    retorno=1;
    }
    return retorno;
}
*/

void ListarMascotasOrdenadasPorCodigoTelefonico(eMascotas listaMasc[], int tamMasc, eRazas listaRazas[], int tamRaza,ePaisOrigen listaPaises[],int tamPais)
{
    int idRaza;
    eRazas unaRaza;
    ePaisOrigen unPais;

    printf("\n***************************************************************************************************");
    printf("\n\t Listado de mascotas ordenadas segun codigo telefonico: \n\n");
    printf("  ID\tNOMBRE\t\tTIPO\tEDAD\tSEXO\t\tPESO\tCODIGO TELEFONICO       NOMBRE PAIS\n");
    for(int i=0;i<tamMasc;i++)
    {
        if(listaMasc[i].isEmpty==FALSE && (OrdenarMascotasPorCodigoTelefonico(listaMasc,listaPaises,tamMasc,listaRazas,tamRaza,tamPais))==1 )
        {
            idRaza=listaMasc[i].idRaza;
            unaRaza=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza);
            unPais=EncontrarPaisDeUnaRaza(unaRaza,listaPaises,tamPais);
            ImprimirListadoMascotasCodigoTelefonico(listaMasc[i],unPais);
        }
    }
    printf("\n***************************************************************************************************");
}


void ImprimirListadoMascotasCodigoTelefonico(eMascotas unaMascota,ePaisOrigen unPais)
{
     printf("%4d %10s %12s %5d %7c %17f %10d %25s\n",   unaMascota.idMascota,
                                                        unaMascota.nombreMascota,
                                                        unaMascota.tipoMascota,
                                                        unaMascota.edad,
                                                        unaMascota.sexoMascota,
                                                        unaMascota.peso,
                                                        unPais.codigoTelefonico,
                                                        unPais.nombreDePais);
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


int OrdenarMascotasPorCodigoTelefonico(eMascotas listaMasc[],ePaisOrigen listaPaises[],int tamMasc,eRazas listaRazas[], int tamRaza,int tamPais)
{
    eMascotas auxMascota;
    ePaisOrigen auxPais;
    eRazas unaRaza1,unaRaza2;
    ePaisOrigen unPais1,unPais2;
    int idRaza1,idRaza2;
    int retorno=0;

    for(int i=0;i<tamMasc-1;i++)
    {
        idRaza1=listaMasc[i].idRaza;
        unaRaza1=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza1);
        unPais1=EncontrarPaisDeUnaRaza(unaRaza1,listaPaises,tamPais);

        for(int j=i+1;j<tamMasc;j++)
        {
            idRaza2=listaMasc[j].idRaza;
            unaRaza2=EncontrarRazaDeUnaMascota(listaRazas,tamRaza,idRaza2);
            unPais2=EncontrarPaisDeUnaRaza(unaRaza2,listaPaises,tamPais);

           if(unPais1.codigoTelefonico>unPais2.codigoTelefonico)
           {
                auxMascota=listaMasc[i];
                listaMasc[i]=listaMasc[j];
                listaMasc[j]=auxMascota;

                auxPais=unPais1;
                unPais1=unPais2;
                unPais2=auxPais;
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
    char auxiliarTipoMascota[3][10]={"gato","perro","raro"};

    for(int i=0;i<tamMasc;i++)
    {
        if(listaMasc[i].isEmpty==FALSE)
        {
            for(int j=0;j<3;j++)
            {
                if(strcmp(listaMasc[i].tipoMascota,auxiliarTipoMascota[j])==0)
                {
                    contadorTipo[j]++;
                    acumuladorPesoTipo[j]=acumuladorPesoTipo[j]+ listaMasc[i].peso;
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

//////////////////////////////////////DOBLE ORDENAMIENTO////////////////////////////////////////////////////////////
int OrdenarMascotasPorTipoYPeso (eMascotas listaMascotas[], int tamMasc)
{
    eMascotas auxMascota;
    int retorno=0;

    for(int i=0; i<tamMasc-1; i++)
    {
        if(listaMascotas[i].isEmpty == FALSE)
        {
            for(int j=i+1; j<tamMasc; j++)
            {
                if(listaMascotas[j].isEmpty == FALSE)
                {
                    if(strcmp(listaMascotas[i].tipoMascota, listaMascotas[j].tipoMascota)>0)
                    {
                        auxMascota = listaMascotas[i];
                        listaMascotas[i] = listaMascotas[j];
                        listaMascotas[j] = auxMascota;
                        retorno=1;
                    }else if(strcmp(listaMascotas[i].tipoMascota, listaMascotas[j].tipoMascota)==0)
                    {
                        if(listaMascotas[i].peso > listaMascotas[j].peso)
                        {
                            auxMascota = listaMascotas[i];
                            listaMascotas[i] = listaMascotas[j];
                            listaMascotas[j] = auxMascota;
                            retorno=1;

                        }
                    }
                }
            }
        }
    }
}

