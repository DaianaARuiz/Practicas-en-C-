/******************************************************************************

DAIANA AYELEN RUIZ

En una veterinaria , las mascotas pueden tener un solo dueño y un dueño puede tener muchas mascotas.

Parte 1.
Hardcodear las estructuras correspondientes.
En un menu:
1. Alta mascota: Se ingresaran los datos de una mascota en la lista de mascotas, si es que hay lugar. //
4. Listar:
    a. Todas las mascotas //
    b. Todos los dueños //

Parte 2.
 menu:
2. -Baja de mascota(baja logica) //
4. Listar:
    c. Todas las mascotas con sus dueños //

Parte 3.
 menu:
3. -Modificar mascota//
4. Listar:
   d. Los dueños con sus  mascotas//

Parte 4.
 menu:
4. Listar:

   f. Listado de dueños ordenados por cantidad de mascotas de manera ascendente.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_DUE 5
#define TAM_MASC 10
#define TRUE 1
#define FALSE 0

typedef struct{
 int idDuenio;
 char nombreDuenio[10];
 int isEmpty;
}eDuenio;

typedef struct{
    int codigoMascota;
    int idDuenio;
    int edad;
    char tipo[10];
    char nombreMascota[10];
    int isEmpty;
}eMascotas;

///////////////HARCODEO///////////////////////////
void HarcodearMascotas(eMascotas [], int);
void HarcodearDuenios(eDuenio [], int );
void imrpimirMascotasHarcodeo(eMascotas [], int);
void imprimirDueniosHarcodeo(eDuenio [], int);

//////////ENTRADA DE DATOS///////////////////////
void PedirString(char [],char [],int , char []);
int ValidarLetras(char []);
int PedirEntero(char [],char []);
int ValidarNumero(char []);

////////////////ALTA//////////////////////////////
int InicializarArrayMascotas(eMascotas [],int);
int BuscarLibre(eMascotas [], int);
eMascotas AltaMascotas(eMascotas [],int , int );

/////////////INFORMAR////////////////////////////
void ImprimirMascotas(eMascotas [], int);
void imprimirDuenios(eDuenio [], int);
void MostrarTodasMascotasConSuDuenio(eMascotas [], int , eDuenio [],int );
void MostrarDueniosConSusMascotas(eMascotas [], int , eDuenio [],int );
void ListarDueniosOrdenadosPorCantMascotas(eMascotas [], int , eDuenio [],int);

///////////////////BAJA/////////////////////
int BuscarPorID(int , int , eMascotas []);
int eliminarUnaMascota(eMascotas [],int ,int);

///////////////MODIFICAR/////////////////////
 int ModificarUnaMascota( eMascotas [],int,int);

int main()
{
    eDuenio listaDuenios[TAM_DUE];
    eMascotas listaMascotas[TAM_MASC];
    int opcionMenu;
    int contadorMascotasCargadas;
    int indiceLibre;
    int opcionMostrar;
    int idEliminar;
    int idAModificar;
    int opcionModificar;

    contadorMascotasCargadas=0;
    printf("\n*********************************************************************************");
    printf("\n\t\t\tPRIMER PARCIAL DE LABORATORIO 1 \n\n Alumna:Ruiz Daiana Ayelen\n Division:1C \n Pofesores: Octavio Villegas y German Scarafilo\n");
    printf("\n*********************************************************************************\n");

     InicializarArrayMascotas(listaMascotas,TAM_MASC);

     do{
            opcionMenu=PedirEntero("\n1.ALTAS MASCOTAS\n2.MODIFICAR MASCOTAS\n3.BAJA MASCOTAS\n4.INFORMAR\n5.HARCODEAR DATOS(solo para testeo)\n6.SALIR\nEliga una opcion:","Error.No se permiten letras. Reingrese la opcion: ");
            switch(opcionMenu)
            {
                case 1:

                        indiceLibre= BuscarLibre(listaMascotas,TAM_MASC);
                        if(indiceLibre!=-1)
                        {
                            AltaMascotas(listaMascotas,TAM_MASC,indiceLibre);
                            contadorMascotasCargadas++;
                            printf("\nMascota cargado con exito\n");
                        }else
                        {
                            printf("\nNo hay mas espacio de almacenamiento\n");
                        }

                    break;
                case 2:
                            ImprimirMascotas(listaMascotas,TAM_MASC);
                            printf("\nIngrese el ID de la mascota que desea modificar:");
                            scanf("%d", &idAModificar);
                            if(BuscarPorID(idAModificar,contadorMascotasCargadas,listaMascotas)!=-1)
                            {
                                printf("\n1-MODIFICAR NOMBRE\n2-MODIFICAR EDAD\n3-MODIFICAR TIPO\n4-MODIFICAR ID DUEÑO\nSeleccione la accion que desea realizar:");
                                scanf("%d", &opcionModificar);
                                if(ModificarUnaMascota(listaMascotas,idAModificar,opcionModificar)==0)
                                {
                                    printf("\nModificacion cargada con exito\n");
                                }else
                                {
                                    printf("\n No se pudo realizar la modificacion solicitada\n");
                                }

                            }else
                            {
                                printf("\nEl ID ingresado no corresponde a ningun empleado.Por favor, verifique e intente nuevamente\n");
                            }
                break;
                case 3:
                    if(contadorMascotasCargadas!=0)
                    {
                            ImprimirMascotas(listaMascotas,TAM_MASC);
                            //idEliminar=PedirEntero("\nIngrese el ID de la mascota que desea dar de baja:","\nError.No se permiten letras. Reingrese: ");
                            printf("\nIngrese el ID de la mascota que desea dar de baja:");
                            scanf("%d",&idEliminar);
                            if(eliminarUnaMascota(listaMascotas,contadorMascotasCargadas,idEliminar)==0)
                            {
                                printf("\nSe ha eliminado la mascota exitosamente\n");
                            }else
                            {
                                printf("\nEl ID ingresado no corresponde a ninguna mascota.Por favor, verifique e intente nuevamente\n");
                            }
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                    break;

                case 4:
                    if(contadorMascotasCargadas!=0)
                    {
                        do{
                            opcionMostrar=PedirEntero("\n1.MOSTRAR MASCOTAS\n2.MOSTRAR DUENIOS\n3.Todas las mascotas con sus dueños\n4.Los dueños con sus  mascotas\n6.SALIR DE ESTE MENU\nEliga una opcion:","Error.No se permiten letras. Reingrese la opcion: ");
                            switch(opcionMostrar)
                            {
                                case 1:
                                       ImprimirMascotas(listaMascotas,contadorMascotasCargadas);
                                break;
                                case 2:
                                        imprimirDuenios(listaDuenios,TAM_DUE);
                                break;
                                case 3:
                                    MostrarTodasMascotasConSuDuenio(listaMascotas,TAM_MASC,listaDuenios,TAM_DUE);
                                break;
                                case 4:
                                    MostrarDueniosConSusMascotas( listaMascotas,TAM_MASC ,listaDuenios,TAM_DUE );
                                break;
                            }
                        }while(opcionMostrar!=7);
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                  break;
                case 5:
                    HarcodearDuenios(listaDuenios,TAM_DUE);
                    HarcodearMascotas(listaMascotas,TAM_MASC);
                    contadorMascotasCargadas=10;
                    printf("\nLos datos se harcodearon con exito.\n");
                break;
            }

        }while(opcionMenu!=6);
    return 0;
}

///////////////HARCODEO///////////////////////////

void HarcodearMascotas(eMascotas listaMasc[], int tamanioArray)
{
    int codigo[]={100,200,300,400,500,600,700,800,900,1000};
    char nombre[][20]={"Michi","Firulais","Dobby","Bobby","Chatran","Pucky","Michifus","Bolt","Dexter","Ayudante de santa"};
    int edad[]={3,2,4,1,2,3,1,5,6,2};
    char tipo[][10]={"Gato","Perro","Perro","Perro","Gato","Gato","Gato","Perro","Gato","Perro"};
    int duenio[]={1,2,1,1,2,3,5,5,1,2};

    for(int i=0;i<tamanioArray;i++)
    {
        listaMasc[i].codigoMascota=codigo[i];
        strcpy(listaMasc[i].nombreMascota,nombre[i]);
        listaMasc[i].edad=edad[i];

        strcpy(listaMasc[i].tipo,tipo[i]);
        listaMasc[i].idDuenio=duenio[i];

        listaMasc[i].isEmpty=FALSE;
    }

}

void HarcodearDuenios(eDuenio listaDuenios[], int tamanioArray)
{
    int idDuenio[]={1,2,3,4,5};
    char nombre[][30]={"Juan","Maria","Raquel","Jose","Luisa"};

     for(int i=0;i<tamanioArray;i++)
    {
        listaDuenios[i].idDuenio=idDuenio[i];
        strcpy(listaDuenios[i].nombreDuenio,nombre[i]);

        listaDuenios[i].isEmpty=FALSE;
    }
}


/////////////////////////////////////////////////////ALTA/////////////////////////////////////////////////////
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

 int BuscarLibre(eMascotas listaMasc[], int tamanioArray)
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

 eMascotas AltaMascotas(eMascotas listaMasc[],int tamanioArray, int indiceLibre)
 {
    eMascotas unaMascota;

    PedirString("\nIngrese nombre mascota: ","Error. Reingrese nombre: ",51, unaMascota.nombreMascota);
    PedirString("Ingrese el tipo de mascota: ","Error. Reingrese tipo: ",51, unaMascota.tipo);
    //unaMascota.codigoMascota = PedirEntero("Ingrese el codigo de la mascota: ","Error, reingrese codigo valido: ");
    unaMascota.edad= PedirEntero("Ingrese edad de la mascota: ","Error, reingrese edad valida:");
    unaMascota.idDuenio= PedirEntero("Ingrese id del Duenio de la mascota: ","Error, reingrese id valido:");

    unaMascota.isEmpty=FALSE;
    unaMascota.codigoMascota=indiceLibre+100 ;

    listaMasc[indiceLibre]=unaMascota;

    return unaMascota;
 }

//////////////////////////////////////////////////////////INFORMAR///////////////////////////////////////////////////////
void ImprimirMascotas(eMascotas listaMasc[], int tamanioArray)
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de mascotas: \n\n");
    printf("CODIGO \t \tNOMBRE\t\tTIPO\t EDAD\t \tID DUENIO\n");
    for(int i=0;i<tamanioArray;i++)
    {
        if(listaMasc[i].isEmpty==FALSE)
        {
            //listaMasc[i-1].codigoMascota+=100;
             //listaMasc[i].codigoMascota=i;
            printf("%2d %10s %15s %15d %20d \n",listaMasc[i].codigoMascota,
                                                listaMasc[i].nombreMascota,
                                                listaMasc[i].tipo,
                                                listaMasc[i].edad,
                                                listaMasc[i].idDuenio);
        }
    }
    printf("\n*********************************************************************************");
}

void imprimirDuenios(eDuenio listaDuenios[], int tamanioArray)
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de duenios: \n\n");
    printf("ID \tNOMBRE\n");
    for(int i=0;i<tamanioArray;i++)
    {
        if(listaDuenios[i].isEmpty==FALSE)
        {
            printf("%2d %10s  \n", listaDuenios[i].idDuenio,
                                   listaDuenios[i].nombreDuenio );
        }
    }
    printf("\n*********************************************************************************");
}


void MostrarTodasMascotasConSuDuenio(eMascotas listaMascotas[], int tamMasc, eDuenio listaDuenios[],int tamDue)
{
    printf("\n*****************************************************************");
    printf("\n\t Listado de mascotas con su respectivo duenio: \n\n");
    printf("ID MASCOTA\tNOMBRE\t\tTIPO\tEDAD\t\tNOMBRE DUENIO\n");

         for(int i=0;i<tamMasc;i++)
        {
            for(int j=0;j<tamDue;j++)
            {
                if(listaMascotas[i].idDuenio==listaDuenios[j].idDuenio)
                {
                    printf("%4d %15s %18s %11d %15s  \n",   listaMascotas[i].codigoMascota,
                                                            listaMascotas[i].nombreMascota,
                                                            listaMascotas[i].tipo,
                                                            listaMascotas[i].edad,
                                                            listaDuenios[j].nombreDuenio);
                    break;
                }
            }
        }
    printf("*****************************************************************");
}

void MostrarDueniosConSusMascotas(eMascotas listaMascotas[], int tamMasc, eDuenio listaDuenios[],int tamDue)
{
    printf("\n*****************************************************************\n");
    printf("\t Listado de cursos con sus respectivos alumnos\n");
    printf("\nID MASCOTA\tNOMBRE\t\tTIPO\tEDAD\n");
    for(int j=0;j<tamDue;j++)
    {
        printf(" -------------------%s------------------------------------------- \n", listaDuenios[j].nombreDuenio);
        for(int i=0;i<tamMasc;i++)
        {
            if(listaMascotas[i].idDuenio==listaDuenios[j].idDuenio)
            {
                printf("%4d %15s %18s %11d  \n", listaMascotas[i].codigoMascota,
                                                        listaMascotas[i].nombreMascota,
                                                        listaMascotas[i].tipo,
                                                        listaMascotas[i].edad);
            }
        }
    }
    printf("*****************************************************************\n");
}

/*
void ListarDueniosOrdenadosPorCantMascotas(eMascotas [], int , eDuenio [],int)
{







}

*/


/////////////////////////////////////////////////////////////////BAJA/////////////////////////////////////////////////////////
int eliminarUnaMascota(eMascotas listaMasc[],int tamanioArray, int idEliminar)
{
    int retorno=-1;
    if(BuscarPorID(idEliminar,tamanioArray,listaMasc)!=-1)
    {
        retorno=0;
        listaMasc[idEliminar].isEmpty=TRUE;
    }
    return retorno;
}

int BuscarPorID(int idIngresado, int tam, eMascotas listaMasc[])
{
    int idValido=-1;
    for(int i=0;i<tam;i++)
    {
       if(listaMasc[i].codigoMascota==idIngresado)
       {
            idValido=idIngresado;
       }
    }
    return idValido;
}


///////////////////////////////////////////////////////////MODIFICAR//////////////////////////////////////////////////////////
int ModificarUnaMascota( eMascotas listaMasc[],int idAModificar,int opcion)
{
    char nombreModificado[10];
    char tipoModificado[10];
    int retorno=-1;

    switch(opcion)
    {
        case 1:
            PedirString("Ingrese el nuevo nombre:","Error. Reingrese nombre: ",51,nombreModificado);
            strcpy(listaMasc[idAModificar].nombreMascota,nombreModificado);
            retorno=0;
            break;
        case 2:
            PedirString("Ingrese el nuevo tipo:","Error. Reingrese tipo: ",51,tipoModificado);
            strcpy(listaMasc[idAModificar].tipo,tipoModificado);
            retorno=0;
             break;
        case 3:
             listaMasc[idAModificar].edad=PedirEntero("Ingrese nueva edad: ","Error, reingrese edad valida: ");
             retorno=0;
            break;
        case 4:
            listaMasc[idAModificar].idDuenio=PedirEntero("Ingrese nuevo id del duenio: ","Error, reingrese id valido: ");
            retorno=0;
            break;
        default:
                printf("\nOpcion no valida. Intente nuevamente\n");
                break;
    }
    return retorno;
}


/////////////////////////////////////////////////ENTRADA DE DATOS//////////////////////////////////////////////////////////

int PedirEntero(char texto[],char textoError[])
{
    char auxiliar[10];
    int numeroIngresado;

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarNumero(auxiliar)==0)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     numeroIngresado= atoi(auxiliar);

    return numeroIngresado;
}

int ValidarNumero(char numero[])
{
   int valido=1;
   for(int i=0;i<strlen(numero);i++)
   {
	  if(numero[i] < '0' || numero[i] > '9')
	  {
		  valido=0;
	  }
   }
   return valido;
}


void PedirString(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarLetras(auxiliar)==0|| strlen(auxiliar)>max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}

int ValidarLetras(char string[])
{
   int valido;
   valido=1;

  for(int i=0;i<strlen(string);i++)
   {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            valido=0;
        }
    }
   return valido;
}












