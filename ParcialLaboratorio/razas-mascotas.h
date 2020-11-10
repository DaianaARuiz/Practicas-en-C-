#include "mascotas.h"
#include "razas.h"
#include "pais.h"
#include "inputs.h"


//ALTA MASCOTAS MOSTRANDO ID DE RAZA
eMascotas AltaMascotas(eMascotas [],int , int ,int , eRazas []);

///////////////MODIFICAR MASCOTA//////////////////
 int ModificarUnaMascota( eMascotas [],int ,int , int ,eRazas [],int);

 ///////////////ALTA  RAZA//////////////////
 eRazas AltaRaza(eRazas listaRaza[],int tamanioArray, int indiceLibre,ePaisOrigen listaPais[],int tamPais);

 ///////////////MODIFICAR RAZA//////////////////





void ListarMascotasConRazaYCodigoTelefonico(eMascotas [], int , eRazas [], int ,ePaisOrigen [],int );
void ImprimirListadoMascotasPais(eMascotas ,eRazas ,ePaisOrigen);
ePaisOrigen EncontrarPaisDeUnaRaza(eRazas ,ePaisOrigen [],int);
int OrdenarMascotasPorCodigoTelefonico(eMascotas [],ePaisOrigen ,int );


//listado de mascotas con sus razas y países de origen:
void ListarMascotasConRaza(eMascotas [], int , eRazas [], int);
eRazas EncontrarRazaDeUnaMascota(eRazas [],int , int );
void ImprimirMascotaConRaza(eMascotas,eRazas);

//listado de RAZAS con las mascotas que pertenecen a esa raza:
void ListarPorCadaRazaLasMascotas(eMascotas [], int , eRazas [], int );
void ImprimirMascotasDeUnaRaza(eMascotas [],int,int);

//listado de mascotas ordenadas por peso:
int OrdenarMascotasPorPeso(eMascotas [], int);

//mostrar el país de origen que tenga más mascotas:
void MostrarPaisConMasMascotas(eMascotas [], int  , eRazas [], int);
void ContarMascotasRazas(eMascotas [],int ,int ,int [],int);

void ImprimirListadoMascotasRazaPais(eMascotas,eRazas,ePaisOrigen);
void ImprimirListadoMascotasCodigoTelefonico(eMascotas ,ePaisOrigen );

void ListarMascotasOrdenadasPorCodigoTelefonico(eMascotas [], int , eRazas [], int ,ePaisOrigen [],int );


void EliminarMascotasDeUnaRaza(eMascotas listaMasc[],int tamMasc,int idRaza);



///////////////////////////////////////////PARTE 6/////////////////////////////////////////////////////////
void RecogerDatosDeCadaTipo(eMascotas listaMasc[], int tamMasc);
void CalcularPromedioDeCadaTipo(float totalPesoTipo[],int contadorTipo[],float promedioDeCadaTipo[]);
void ImprimirDatosDeCadaTipo(float acumuladorPesoTipo[],int contadorTipo[], float promedioDeCadaTipo[]);

///////////////////////////////////////////PARTE 7/////////////////////////////////////////////////////////
void ListarPorTamanioYPeso(eMascotas listaMascotas[],int tamMascotas,eRazas listaRazas[],int tamRaza,ePaisOrigen listaPaises[],int tamPais, char tamanioIngresado[]);
void BuscarEimprimirMascotasDeUnaRaza(eMascotas listaMasc[],int tamMasc,int idRaza,eRazas unaRaza,ePaisOrigen unPais);
void SumarPesoTotalDelMismoTamanio(eMascotas listaMasc[],int tamMasc,int idRaza,float *acumuladorPeso);
void ImprimirUnaMascotaConRazaYPais(eMascotas unaMascota,eRazas unaRaza,ePaisOrigen unPais);
