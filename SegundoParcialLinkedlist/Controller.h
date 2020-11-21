/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* El nombre del archivo
 * \param pArrayListEmployee LinkedList* La lista donde se cargaran los datos del archivo
 * \return int  [0] en caso de que no se hayan podido cargar los datos
                [1] si se cargaron con exito
 *
 */int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* El nombre del archivo
 * \param pArrayListEmployee LinkedList* La lista donde se cargaran los datos del archivo
 * \return int  [0] en caso de que no se hayan podido cargar los datos
                [1] si se cargaron con exito
 *
 */int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


 /** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*  La lista donde se cargaran el nuevo empleado
 * \return int [0] en caso de que no se haya podido cargar nuevo empleado
                [1] si se cargo con exito
 *
 */int controller_addEmployee(LinkedList* pArrayListEmployee);


 /** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int [0] en caso de que no se haya podido editar uno o más campos de la entidad empleado
                [1] si se edito con exito
 *
 */int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  [0] en caso de que no se haya podido dar de baja
                [1] si se elimino con exito
 *
 */int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Lista todos los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int [0] en caso de que no se hayan podido listar
                [1] si se listo con exito
 *
 */int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena los empleados de acuerdo al criterio que establezca el usuario
 *
 * \param pArrayListEmployee LinkedList*
 * \return int [0] en caso de que no se haya podido ordenar
                [1] si se ordeno con exito
 *
 *
 */int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda en al archivo las modificaciones realizadas en la ejecucion del programa(en modo de texto)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [0] en caso de que no haya podido escribir en el archivo
                [1] si se escribio con exito
 *
 */int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda en al archivo las modificaciones realizadas en la ejecucion del programa(en modo de binario)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0] en caso de que no haya podido escribir en el archivo
                [1] si se escribio con exito
 *
 */int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



