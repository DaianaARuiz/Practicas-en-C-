/** \brief Imprime todos los empleados que contiene el linked List
 *
 * \param pListeParticipant LinkedList*
 * \return void
 *
 */void eParticipant_showAlleParticipants(LinkedList* );

/** \brief Pide el id que se desea eliminar, verifica que existe y retorna el index de ese id
 *
 * \param pListeParticipant LinkedList*
 * \return int index del id a eliminar
 *
 */int eParticipant_askIdToDelete(LinkedList* );

/** \brief Pide un id al usuario, verifica que exista, muestra mensajes de error en caso de que no y devuelve el indice del ID buscado
 *
 * \param pListeParticipant LinkedList*
 * \param msj[] char Mensaje solicitando el id
 * \param emsj1[] char Mensaje en caso de que se ingresen letras
 * \param emsj2[] char Mensaje en caso de que se ingrese un numero fuera del rango
 * \param int* Parametro de salida, puntero al indexID
 * \return void
 *
 */void eParticipant_AskIdAndGetTheIndex(LinkedList* , char [],char [],char [],int*);

int eParticipant_searchById(LinkedList* pListeParticipant,int idIngresado, int*);

/** \brief Genera un nuevo empleado a partir de los datos ingresados por el asuario
 *
 * \param pArrayListeParticipant LinkedList*
 * \return int Retorna [1] si se pudo generar un nuevo empleado [0] en caso de que no
 *
 */
int eParticipant_registereParticipant(LinkedList* pArrayListeParticipant);


/** \brief Busca el valor del mayor id generado
 *
 * \param pArrayListeParticipant LinkedList*
 * \return int El valor de ese id
 *
 */int eParticipant_lastId(LinkedList* pArrayListeParticipant);


/** \brief Genera el valor de un nuevo id
 *
 * \param LinkedList* pArrayListeParticipant
 * \param puntero a id, parametro de salida
 * \return
 *
 */void eParticipant_calculateNewId(LinkedList* pArrayListeParticipant,int* id);

/** \brief Modifica campos de una entidad de acuerdo a la opcion elegida por el usuario
 *
 * \param empleado eParticipant*
 * \param opcion int El numero de la opcion elegida por el usuario
 * \return int Retorna [1] si se pudo realizar la modificacion [0] en caso de que no
 *
 */int eParticipant_modifyeParticipant(eParticipant* empleado, int opcion);

/** \brief Recorre la lista, obtiene los valores de sus campos y los imprime en un archivo
 *
 * \param pArrayListeParticipant LinkedList*
 * \param pFile FILE*
 * \param len int la longitud de la lista
 * \return int Retorna [1] si se pudo escribir el archivo [0] en caso de que no

 *
 */
int guardarEnTexto(LinkedList* pArrayListeParticipant, FILE* pFile, int len);

