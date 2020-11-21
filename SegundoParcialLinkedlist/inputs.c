#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

void inputs_getAndValidateInt(int* input, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit)
{
    char bufferNumStr[200];
    int bufferNum;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", bufferNumStr);

    while(inputs_validateNumber(bufferNumStr)==0)
    {
        printf("%s", eMessage1);
        fflush(stdin);
        scanf("%s", bufferNumStr);
    }

    bufferNum=atoi(bufferNumStr);
    while(inputs_validarRangoEntero(bufferNum,lowLimit,hiLimit)==0)
    {
        printf("%s", eMessage2);
        fflush(stdin);
        scanf("%d", &bufferNum);
    }
    *input=bufferNum;
}

int inputs_validarRangoEntero(int dato,int lowLimit ,int hiLimit)
{
    int valido=1;

    if(dato<lowLimit || dato>hiLimit)
    {
       valido=0;
    }

    return valido;
}


int inputs_validateNumber(char* numberStr)
{
    int valido=1;
    for(int i=0;i<strlen(numberStr);i++)
    {
	  if(numberStr[i] < '0' || numberStr[i] > '9')
	  {
		  valido=0;
	  }
    }
   return valido;
}


int inputs_isValidName(char* cadena,int length)
{
    int retorno=1;
    if(cadena !=NULL && length>0)
    {
        for(int i=0; cadena[i]!='\0' && i<length; i++)
        {
            if( (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != ' ' && cadena[i] != '-' )
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

void inputs_PedirNombre(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(!inputs_isValidName(auxiliar,max)|| strlen(auxiliar)>max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}

int inputs_isValidNameArchive(char* cadena,int length)
{
    int retorno=1;
    if(cadena !=NULL && length>0)
    {
        for(int i=0; cadena[i]!='\0' && i<length; i++)
        {
            if( (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != ' ' && cadena[i] != '.' )
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

void inputs_PedirNombreArchivo(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(!inputs_isValidNameArchive(auxiliar,max)|| strlen(auxiliar)>max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}

