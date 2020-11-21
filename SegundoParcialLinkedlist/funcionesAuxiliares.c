#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<time.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "funcionesAuxiliares.h"

void participants_showAllParticipants(LinkedList* pListeParticipant)
{
    eParticipant* participante;
    int lengthListeParticipant = ll_len(pListeParticipant);

    printf("\n*********************************************************************************************************************\n");
    printf("\nID \tANIO\tNOMBRE\t\tDNI\tFECHA PRESENTACION\t\tTEMA PRESENTACION\tPUNTAJE 1ER RONDA\n");

    for(int i=0;i<lengthListeParticipant;i++)
    {
        participante =(eParticipant*)ll_get(pListeParticipant,i);
        eParticipant_showOneeParticipant(participante);
    }
    printf("*****************************************************************************************************************************\n");
}

void GenerarPuntajeAleatorio(int* num)
{
    srand(time(NULL));
    (*num )= 1+rand()%(101-1);

}
/*
int participants_askIdToDelete(LinkedList* pListeParticipant)
{
    int retorno=-1;
    int idIngresado;
    int indexIdAEliminar;
    int lengthListeParticipant=ll_len(pListeParticipant);

    inputs_getAndValidateInt(&idIngresado,"\nIngrese el id del empleado que quiere dar de baja: ","\nError.Por favor Ingrese un numero: ","\nError.Ingrese un id existente:",0,lengthListeParticipant);
    eParticipant_searchById(pListeParticipant,idIngresado,&indexIdAEliminar );
    if(indexIdAEliminar!=-1)
    {
       retorno= indexIdAEliminar;
    }
    return retorno;
}

void eParticipant_AskIdAndGetTheIndex(LinkedList* pListeParticipant, char msj[],char emsj1[],char emsj2[],int* indexId)
{
    int idIngresado;
    int lengthListeParticipant=ll_len(pListeParticipant);

    inputs_getAndValidateInt(&idIngresado,msj,emsj1,emsj2,0,lengthListeParticipant);
    eParticipant_searchById(pListeParticipant,idIngresado,indexId);
}

int eParticipant_searchById(LinkedList* pListeParticipant,int idIngresado, int* indexIdBuscado)
{
    eParticipant* AuxEmpleado;
    int idAux;

    int retorno=0;
    int lengthListeParticipant = ll_len(pListeParticipant);
    *indexIdBuscado=-1;

    for(int i=0;i<lengthListeParticipant;i++)
    {
        AuxEmpleado=(eParticipant*)ll_get(pListeParticipant,i);
        eParticipant_getId(AuxEmpleado,&idAux);
        if(idAux==idIngresado)
        {
            *indexIdBuscado=i;
            retorno=1;
            break;
        }
    }
    return retorno;
}

int eParticipant_registereParticipant(LinkedList* pArrayListeParticipant)
{
    eParticipant* nuevoEmpleado;
    char nombreIngresado[51] ;
    int horasIngresadas;
    int sueldoIngresado;
    int retorno=0;
    int id;

    nuevoEmpleado=eParticipant_new();

    inputs_PedirNombre("Ingrese nombre: ","Nombre no valido. Reeingrese: ",51,nombreIngresado);
    inputs_getAndValidateInt(&horasIngresadas,"Ingrese horas trabajadas: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [400]hs. Reingrese: ",0,400);
    inputs_getAndValidateInt(&sueldoIngresado,"Ingrese sueldo: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [100000]. Reingrese: ",0,100000);
    eParticipant_calculateNewId(pArrayListeParticipant,&id);

    if(nuevoEmpleado!=NULL)
    {
        eParticipant_setNombre(nuevoEmpleado,nombreIngresado);
        eParticipant_setHorasTrabajadas(nuevoEmpleado,horasIngresadas);
        eParticipant_setSueldo(nuevoEmpleado,sueldoIngresado);
        eParticipant_setId(nuevoEmpleado,id);

        ll_add(pArrayListeParticipant,nuevoEmpleado);
        retorno=1;
    }
    return retorno;
}


int eParticipant_lastId(LinkedList* pArrayListeParticipant)
{
    eParticipant* peParticipant;
    int IdAux;
    int IdMax=0;
    int lengthListeParticipant = ll_len(pArrayListeParticipant);

    for(int i=0 ; i<lengthListeParticipant; i++)
    {
        peParticipant = ll_get(pArrayListeParticipant, i);
        if(peParticipant != NULL)
        {
            eParticipant_getId(peParticipant, &IdAux);
            if(IdAux > IdMax)
            {
                IdMax = IdAux;
            }
        }
    }
    return IdMax;
}


void eParticipant_calculateNewId(LinkedList* pArrayListeParticipant,int* id)
{
    *id = eParticipant_lastId(pArrayListeParticipant)+1;
}

int eParticipant_modifyeParticipant(eParticipant* empleado, int opcion)
{
    char nombreModificado[51];
    int horasModificadas;
    int sueldoModificado;
    int retorno=0;

        switch(opcion)
        {
            case 1:
                inputs_PedirNombre("\nIngrese nuevo nombre: ","Nombre no valido. Reeingrese: ",51,nombreModificado);
                if(eParticipant_setNombre(empleado,nombreModificado))
                {
                    retorno=1;
                }
                break;
            case 2:
                inputs_getAndValidateInt(&horasModificadas,"\nIngrese nueva horas trabajadas: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [400]hs. Reingrese: ",0,400);
                if(eParticipant_setHorasTrabajadas(empleado,horasModificadas))
                {
                    retorno=1;
                }
                break;
            case 3:
                inputs_getAndValidateInt(&sueldoModificado,"\nIngrese nuevo sueldo: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [100000]. Reingrese: ",0,100000);
                if(eParticipant_setSueldo(empleado,sueldoModificado))
                {
                    retorno=1;
                }
                break;
        }

    return retorno;
}

int guardarEnTexto(LinkedList* pArrayListeParticipant, FILE* pFile, int len)
{
    eParticipant* empleado;
    int retorno = 0;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    for(int i=0;i<len;i++)
    {
        empleado = ll_get(pArrayListeParticipant,i);
        eParticipant_getId(empleado,&id);
        eParticipant_getNombre(empleado,nombre);
        eParticipant_getHorasTrabajadas(empleado,&horasTrabajadas);
        eParticipant_getSueldo(empleado,&sueldo);
        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        retorno=1;
    }
    fclose(pFile);

    return retorno;
}
*/



