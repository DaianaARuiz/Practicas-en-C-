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

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

float PedirFlotante(char texto[],char textoError[])
{
    char auxiliar[10];
    float numeroIngresado;

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarFlotante(auxiliar)==0)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
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

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);

    strlwr(auxiliar);
    while( (strcmp(auxiliar,"chico"))!=0 && (strcmp(auxiliar,"mediano"))!=0 && (strcmp(auxiliar,"grande"))!=0)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
    strcpy(input,auxiliar);
}

void ObtenerTipoValido(char texto[],char textoError [],char input[])
{
    char auxiliar[100];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);

    strlwr(auxiliar);
    while( (strcmp(auxiliar,"perro"))!=0 && (strcmp(auxiliar,"gato"))!=0 && (strcmp(auxiliar,"raro"))!=0)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
    strcpy(input,auxiliar);
}
