
/////////////////////////////////////////////////ENTRADA DE DATOS//////////////////////////////////////////////////////////
char getChar(char mensaje[] );

void getString(char mensaje[], char* input);
int PedirEntero(char texto[],char textoError[]);

int ValidarNumero(char numero[]);
void PedirString(char texto[],char textoError[],int max, char input[]);

int ValidarLetras(char string[]);

float PedirFlotante(char texto[],char textoError[]);

int ValidarFlotante(char numero[]);

void ObtenerTamanioRazaValido(char texto[],char textoError [],char input[]);
void ObtenerTipoValido(char texto[],char textoError [],char input[]);
char ObtenerSexoValido(char texto[],char textoError []);
int ObtenerIdRazaValido(char texto[],char textoError [], eRazas listaRazas[],int tamRaza);
int VerificarIdRaza(eRazas listaRazas[],int tamRaza, int idRazaIngresada);
int ObtenerIdPaisValido(char texto[],char textoError [], ePaisOrigen listaPais[],int tamPais);

int VerificarIDPais(ePaisOrigen listaPais[],int tamPais, int idPaisIngresado);

int PedirYValidarNuevoIDRaza(char texto[],char textoError[],eRazas listaRazas[], int tamRaza);
