#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */

int parser_eParticipantFromText(FILE* pFile , LinkedList* pArrayListeParticipant)
{
    eParticipant* participante;
    char numConcursanteAux[5];
    char nombreAux[51];
    char anioNacimientoAux[5];
    char dniAux[10];
    char fechaPresentacion[15];
    char temaPresentacionAux[30];
    char puntajePimeraRondaAux[4];

    int retorno = 0;


    if(pFile!=NULL)
    {
        printf("Entre a parser");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numConcursanteAux,anioNacimientoAux,nombreAux,dniAux,fechaPresentacion,temaPresentacionAux,puntajePimeraRondaAux);
        printf("pase primer fscanf del parser");
        do{
            printf("entre al do del parser");
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numConcursanteAux,anioNacimientoAux,nombreAux,dniAux,fechaPresentacion,temaPresentacionAux,puntajePimeraRondaAux);
            participante = eParticipant_newParametros(numConcursanteAux,anioNacimientoAux,nombreAux,dniAux,fechaPresentacion,temaPresentacionAux,puntajePimeraRondaAux);
            ll_add(pArrayListeParticipant,participante);
        }while(!feof(pFile));
        retorno = 1;
    }
    return retorno;
}


int parser_eParticipantFromBinary(FILE* pFile , LinkedList* pArrayListeParticipant)
{
    eParticipant* auxParticipant;
    int retorno = 0;
    int flag;

    if(pFile!=NULL)
    {
        do{
            auxParticipant = eParticipant_new();
            flag = fread(auxParticipant,sizeof(eParticipant),1,pFile);
            if( flag == 1)
            {
                ll_add(pArrayListeParticipant,auxParticipant);
            }
        }while(!feof(pFile));
        retorno = 1;
    }
    return retorno;

}

