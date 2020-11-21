//#include "funcionesAuxiliares.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
/*
numeroConcursante (int)
● año de nacimiento
● nombre (string, 50)
● dni (string, 8, valor entre 9.000.000 y 45.000.000)
● fechaPresentacion (Date)
● temaPresentacion (string, 30)
● puntajePrimeraRonda(int)
*/
typedef struct
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    char fechaPresentacion[15];
    char temaPresentacion[51];
    int puntajePrimeraRonda;
}eParticipant;

/** \brief Reserva espacio en memoria dinamica para una estructura del tipo eParticipant
 *
 * \return eParticipant*
 *
 */eParticipant* eParticipant_new();


/** \brief
 *
 * \param numConcursanteAux char*
 * \param nombreAux char*
 * \param anioNacimientoAux char*
 * \param dniAux char*
 * \param temaPresentacionAux char*
 * \param puntajePimeraRondaAux char*
 * \return eParticipant*
 *
 */eParticipant* eParticipant_newParametros(char* ,char* ,char* ,char* , char* ,char*,char*);



void eParticipant_delete();

/** \brief  Setea el valor del atributo id de la entidad eParticipant
 *
 * \param  eParticipant*
 * \param id int Valor a asignar al id.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int eParticipant_setId(eParticipant* ,int);


/** \brief Obtiene el valor del atributo  ID de la entidad eParticipant.
 *
 * \param this eParticipant*
 * \param id int* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int eParticipant_getId(eParticipant* this,int* id);

/** \brief   Setea el valor del atributo nombre de la entidad eParticipant
 *
 * \param this eParticipant*
 * \param nombre char* Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int eParticipant_setNombre(eParticipant* ,char* );

/** \brief  Obtiene el valor del atributo NOMBRE de la entidad eParticipant.
 *
 * \param this eParticipant*
 * \param nombre char* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int eParticipant_getNombre(eParticipant*,char*);


/** \brief Setea el valor del atributo "horas trabajadas" de la entidad eParticipant
 *
 *
 * \param this eParticipant*
 * \param horasTrabajadas int Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */ int eParticipant_setHorasTrabajadas(eParticipant* this,int horasTrabajadas);


/** \brief  Obtiene el valor del atributo "horasTrabajadas" de la entidad eParticipant.
 *
 * \param this eParticipant*
 * \param horasTrabajadas int* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int eParticipant_getHorasTrabajadas(eParticipant* this,int* horasTrabajadas);


/** \brief Setea el valor del atributo "sueldo" de la entidad eParticipant
 *
 * \param this eParticipant*
 * \param sueldo int Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int eParticipant_setSueldo(eParticipant* this,int sueldo);


/** \brief Obtiene el valor del atributo "sueldo" de la entidad eParticipant.
 *
 * \param this eParticipant*
 * \param sueldo int* Parametro de salida
 * \return int  Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int eParticipant_getSueldo(eParticipant* this,int* sueldo);

/** \brief Imprime UNA entidad del tipo eParticipant con sus respectivos campos.
 *
 * \param empleado eParticipant*
 * \return void
 *
 */void  eParticipant_showOneeParticipant(eParticipant* empleado);

/** \brief Compara los sueldos de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int Retorna  [1] si item1>item2
                        [0] si item1=item2
                        [-1] si item1<item2
 *
 */int eParticipant_CompareBySueldo(void* , void* );

/** \brief Compara las horas trabajadas de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int  [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int eParticipant_CompareByHoras(void* , void*);

/** \brief  Compara los nombres de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int  [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int eParticipant_compareByName(void* , void*);

/** \brief  Compara los nombres de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int eParticipant_CompareById(void* , void*);

#endif // employee_H_INCLUDED
