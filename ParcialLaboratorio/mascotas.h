
typedef struct{
    char nombreMascota[20];
    int edad;
    char tipoMascota[10];
    char sexoMascota;
    int idMascota; //PK
    float peso;
    int idRaza; //FK
    int isEmpty;
}eMascotas;

////////////////////HARCODEO///////////////////
void HarcodearMascotas(eMascotas []);

//////////////////INFORMAR///////////////////
void ListarMascotas(eMascotas [], int);
void imprimirUnaMascota(eMascotas);

////////////////ALTA MASCOTA//////////////////////
int InicializarArrayMascotas(eMascotas [],int);
int BuscarLibreMascota(eMascotas [], int);
//El alta esta en razas-mascota.h
 int BuscarIdMayorMascota(eMascotas listaMascotas[],int tamMascota);
int calcularNuevoIDMascota(eMascotas listaMascotas[],int tamMascota);
///////////////////BAJA MASCOTA///////////////////
int BuscarPorIDMascota(int , int , eMascotas []);
int eliminarUnaMascota(eMascotas [],int ,int);

///////////////MODIFICAR MASCOTA//////////////////
//en  razas-mascotas.h
