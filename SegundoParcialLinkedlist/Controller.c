#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesAuxiliares.h"
#include "parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListeParticipant)
{
    FILE* pFile;
    int retorno=0;

    if(pArrayListeParticipant!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            retorno = parser_eParticipantFromText(pFile,pArrayListeParticipant);
            fclose(pFile);
        }
    }
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListeParticipant)
{
    FILE *pFile;
    int retorno=0;

    if(path!=NULL && pArrayListeParticipant!=NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            printf("\nEl archivo no existe. Realize la carga desde el archivo en modo binario(opcion 1)\n");
        }else{
            retorno=  parser_eParticipantFromBinary( pFile , pArrayListeParticipant);
        }
        fclose(pFile);
    }
    return retorno;
}


/*
int controller_addeParticipant(LinkedList* pArrayListeParticipant)
{
     return eParticipant_registereParticipant(pArrayListeParticipant);
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_editeParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;
    return retorno;
}


int controller_removeParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;
    return retorno;
}


int controller_ListParticipant(LinkedList* pListeParticipant)
{
    int retorno=0;

    if(pListeParticipant!=NULL)
    {
        participants_showAllParticipants(pListeParticipant);
        retorno = 1;
    }
    return retorno;
}

int controller_sortParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeParticipant)
{
   int retorno=1;
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListeParticipant)
{
    FILE* pFile = fopen(path,"wb");
    eParticipant* participante;
    int len;
    int retorno = 0;

    if(pFile!=NULL && pArrayListeParticipant!=NULL)
    {
        len = ll_len(pArrayListeParticipant);

        for(int i=0;i<len;i++)
        {
            participante = ll_get(pArrayListeParticipant,i);
            fwrite(participante,sizeof(participante),1,pFile);
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}

