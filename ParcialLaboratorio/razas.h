
typedef struct{
 char descripcionRaza[15];
 char tamanioRaza[8];
 char paisOrigenRaza[15];
 int idRaza; //PK
 int idPais; //FK
 int isEmpty;
}eRazas;


////////////////////HARCODEO///////////////////
void HarcodearRazas(eRazas [] );

//////////////////INFORMAR///////////////////
void ListarRazas(eRazas [], int);
void ImprimirUnaRaza(eRazas);
//void MostrarIDRazas(eRazas [], int );

////////////////ALTA RAZA//////////////////////
int InicializarArrayRaza(eRazas [],int);
int BuscarLibreRaza(eRazas [],int);
int BuscarIdMayorRaza(eRazas listaRazas[],int tamRazas);
int calcularNuevoIDRaza(eRazas listaRazas[],int tamRazas);

////////////////BAJA RAZA//////////////////////
int EliminarUnaRaza(eRazas listaRaza[],int tamRaza, int idEliminar, eMascotas listaMascotas[],int tamMasc);
int BuscarRazaPorID(int idIngresado, int tam, eRazas listaRaza[]);
