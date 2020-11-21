/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage1 Es el mensaje a ser mostrado en caso de que no sea un numero
* \param eMessage2 Es el mensaje a ser mostrado en caso de que no este dentro del rango
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* */
void inputs_getAndValidateInt(int* valor, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit);


/** \brief valida que lo que se ingresa sea un  numero
 *
 * \param input a validar
 * \return int si solo se ingreseo una numero [0] si no [-1]
 *
 */
int inputs_validateNumber(char* numeroChar);



/** \brief Verifica si la cadena ingresada es un nombre valido
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param longitud int Longitud maxima que debe tener la cadena
 * \return int [1] si la cadena es valida,  [0] si no lo es
 *
 */
int inputs_isValidName(char* cadena,int longitud);


/** \brief Valida que un numero esté dentro de determinado rango
 *
 * \param dato int Numero a ser analizado
 * \param lowLimit int Valor minimo aceptado
 * \param hiLimit int Valor maximo aceptado
 * \return int [1] si esta dentro del rango,  [0] si no lo esta
 *
 */
int inputs_validarRangoEntero(int dato,int lowLimit ,int hiLimit);


/** \brief Pide un nombre al usuario y valida que cumpla con las caracteristicas que debe tener un nombre
 *
 * \param [] char El mensaje para pedirle un nombre al usuario
 * \param [] char El mensaje en caso de error
 * \param int El valor maximo que soporta el array de caracteres que albergara el nombre
 * \param [] char El array donde se guardara el array de caracteres
 * \return void
 *
 */
void inputs_PedirNombre(char [],char [],int , char []);


/** \brief Pide un numero al usuario, valida y notifica en caso de que no sea un numero, o no este dentro del rango establecido
 *
 * \param input int* Donde se guardará el numero solicitado
 * \param message[] char El mensaje solicitando el numero
 * \param eMessage1[] char  El mensaje de error en caso de que se ingrese alguna letra
 * \param lowLimit int El valor minimo que puede tener el numero ingresado
 * \param hiLimit int El valor maximo que puede tener el numero ingresado
 * \return void
 *
 */
void inputs_getAndValidateInt(int* input, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit);

