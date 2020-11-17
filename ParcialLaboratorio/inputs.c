#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20

#define TRUE 1
#define FALSE 0

/////////////////////////////////////////////////ENTRADA DE DATOS//////////////////////////////////////////////////////////
char getChar(char mensaje[] )
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

void getString(char mensaje[], char* input)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]",input);
}

int PedirEntero(char texto[],char textoError[])
{
    char auxiliar[10];
    int numeroIngresado;

    getString(texto,auxiliar);
    while(ValidarNumero(auxiliar)==0)
    {
        getString(textoError,auxiliar);
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

   getString(texto,auxiliar);

    while(ValidarLetras(auxiliar)==0|| strlen(auxiliar)>max-1)
    {
        getString(textoError,auxiliar);
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

float PedirFlotante(char texto[],char textoError[])
{
    char auxiliar[10];
    float numeroIngresado;

    getString(texto,auxiliar);

    while(ValidarFlotante(auxiliar)==0)
    {
        getString(textoError,auxiliar);
    }
     numeroIngresado=atof(auxiliar);

    return numeroIngresado;
}

int ValidarFlotante(char numero[])
{
   int valido=1;
   for(int i=0;i<strlen(numero);i++)
   {
	  if( (numero[i] < '0' || numero[i] > '9') && numero[i] !='.')
	  {
		  valido=0;
	  }
   }
   return valido;
}

void ObtenerTamanioRazaValido(char texto[],char textoError [],char input[])
{
    char auxiliar[100];

    getString(texto,auxiliar);

    strlwr(auxiliar);
    while( (strcmp(auxiliar,"chico"))!=0 && (strcmp(auxiliar,"mediano"))!=0 && (strcmp(auxiliar,"grande"))!=0)
    {
        getString(textoError,auxiliar);
    }
    strcpy(input,auxiliar);
}

void ObtenerTipoValido(char texto[],char textoError [],char input[])
{
    char auxiliar[100];

    getString(texto,auxiliar);
    strlwr(auxiliar);
    while( (strcmp(auxiliar,"perro"))!=0 && (strcmp(auxiliar,"gato"))!=0 && (strcmp(auxiliar,"raro"))!=0)
    {
        getString(textoError,auxiliar);
    }
    strcpy(input,auxiliar);
}

char ObtenerSexoValido(char texto[],char textoError [])
{
    char auxiliar;
    auxiliar=getChar(texto);

    while( (auxiliar!='f') && (auxiliar!='F') && (auxiliar!='M') && (auxiliar!='m')  )
    {
        auxiliar=getChar(textoError);
    }
    return auxiliar;
}

int ObtenerIdRazaValido(char texto[],char textoError [], eRazas listaRazas[],int tamRaza)
{
    int idRazaIngresada;
    idRazaIngresada=PedirEntero(texto,textoError);
    while( VerificarIdRaza(listaRazas,tamRaza,idRazaIngresada))
    {
        idRazaIngresada=PedirEntero(textoError,textoError);
    }
    return idRazaIngresada;
}

int VerificarIdRaza(eRazas listaRazas[],int tamRaza, int idRazaIngresada)
{
    int retorno=1;

     for(int i=0;i<tamRaza;i++)
    {
        if(idRazaIngresada==listaRazas[i].idRaza)
        {
            retorno=0;
        }
    }

    return retorno;
}

int ObtenerIdPaisValido(char texto[],char textoError [], ePaisOrigen listaPais[],int tamPais)
{
    int idPaisIngresado;
    idPaisIngresado=PedirEntero(texto,textoError);

    while( VerificarIDPais(listaPais,tamPais,idPaisIngresado))
    {
        idPaisIngresado =PedirEntero(textoError,textoError);
    }
    return idPaisIngresado;
}

int VerificarIDPais(ePaisOrigen listaPais[],int tamPais, int idPaisIngresado)
{
    int retorno=1;

     for(int i=0;i<tamPais;i++)
    {
        if(idPaisIngresado==listaPais[i].idPais)
        {
            retorno=0;
        }
    }

    return retorno;
}


int PedirYValidarNuevoIDRaza(char texto[],char textoError[],eRazas listaRazas[], int tamRaza)
{
    int idIngresado;
    idIngresado=PedirEntero(texto,"Error. Este campo no admite letras");

    for(int i=0;i<tamRaza;i++)
    {
        while(listaRazas[i].idRaza ==idIngresado)
        {
           idIngresado=PedirEntero(textoError,textoError);
        }
    }

    return idIngresado;
}
