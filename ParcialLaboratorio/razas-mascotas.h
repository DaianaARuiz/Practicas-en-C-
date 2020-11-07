#include "mascotas.h"
#include "razas.h"
#include "pais.h"
#include "inputs.h"


//ALTA MASCOTAS MOSTRANDO ID DE RAZA
eMascotas AltaMascotas(eMascotas [],int , int ,int , eRazas []);

///////////////MODIFICAR MASCOTA//////////////////
 int ModificarUnaMascota( eMascotas [],int ,int , int ,eRazas [],int);

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
