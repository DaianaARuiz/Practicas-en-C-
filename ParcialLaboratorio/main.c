/*
Soy un veterinario que necesita atender a las mascotas de sus clientes, para tener el
control vamos a tener un sistema ....el sistema debe realizar las siguientes
funcionalidades.(los datos deben ser hardcodeados).

******************************** 1era parte ********************************

#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ​pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)

listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica

las 5 mascotas están formadas por los siguientes datos:
a- 3 gatos
b- 2 perros
c- los demás datos deben ser hardcodeados por el alumno.

1-Se debe mostrar un listado de mascotas con sus razas y países de origen //


******************************** 2da parte ********************************

#-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de //
razas disponibles, teniendo en cuenta que ya tengo 5 mascotas cargadas y que el
máximo es 10
#-Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa
raza //

******************************** 3era parte ********************************

#Borrado lógico de una mascota del listado //
#-Se debe mostrar un listado de mascotas ordenadas por peso //

******************************** 4ta parte ********************************

#Modificación de una mascotas(todo menos el id). //
#Menú de opciones
#-Alta de RAZA
#-Se debe mostrar el país de origen que tenga más mascotas en nuestra
veterinaria.

******************************** 5ta parte ********************************
excluyente :
#Menú de opciones
Se nos agregaron dos mascotas más , un dogo argentino y un pastor alemán,

Vamos a tener que realizar la estructura pais,
con:(nombreDePais,continente,CodigoTelefonico)argentina =54 , alemania= 49,
belgica =32, tailandia=66,persia=98
debemos tener hardcodeado los datos de las 7 mascotas
incluyendo los países y la relación con la raza y el atributo peso

#Opción Alta de RAZA:
dar de alta una raza, mostrando el listado de países disponibles.

#-Opción Listar por Código telefónico:
a-ordenar mascotas por el CodigoTelefonico del continente, de mayor a menor.
b-Se debe mostrar un listado de mascotas con las razas y los países de
esas razas

******************************** 6ta parte ********************************
#Opción borrar RAZA:
borrado en cascada de una raza, al borrar una raza,se borran todas las
mascotas de esa raza


#-Opción Listar por TIPO y PESO:
Sabiendo que solo hay tres tipos de mascotas (tipo{gato ,perro o raro}),
informar el peso total de cada tipo, la cantidad de mascotas por tipo y el promedio de
peso por tipo. Estos tres datos en una tabla bien hecha.


******************************** 7ma parte ********************************

#-Opción Listar por TAMAÑO y PESO:
-Sabiendo que solo hay tres tamaños(tamaño{chico ,mediano o grande}),pedir
el ingreso al usuario de un tamaño válido y mostrar el listado de mascotas de este
tamaño con sus países de origen peso y la suma total del peso entre estas mascotas.

******************************** ******************************** ******************

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "razas-mascotas.h"

#define TAM_RAZA 10
#define TAM_MASC 20
#define TAM_PAIS 5

#define TRUE 1
#define FALSE 0

int main()
{
    printf("\n**********************************************************************************************************************\n");
    printf("\n\t\t\t\t\t\tPRIMER PARCIAL DE LABORATORIO 1 \n\n  Alumna:Ruiz Daiana Ayelen\n  Division:1C \n  Pofesores: Octavio Villegas y German Scarafilo\n");
    printf("\n**********************************************************************************************************************\n");

    eRazas listaRazas[TAM_RAZA];
    eMascotas listaMascotas[TAM_MASC];
    ePaisOrigen listaPaises[TAM_PAIS];


    int contadorMascotasCargadas;
    int contadorRazasCargadas;
    int contadorPaisesCargados;

    int opcionMenu;
    int opcionMostrar;
    int opcionModificar;

    int indiceLibreRaza;
    int indiceLibreMascota;
    int idEliminar;
    int idAModificar;

    char tamanioIngresado[8];
    contadorMascotasCargadas=0;
    contadorRazasCargadas=0;
    contadorPaisesCargados=0;

    InicializarArrayMascotas(listaMascotas,TAM_MASC);
    InicializarArrayRaza(listaRazas,TAM_RAZA);
     do{
            opcionMenu=PedirEntero("\nMASCOTAS:\n1.Alta\n2.Baja\n3.Modificacion\n4.Informar\n5.Harcodear datos(solo para testeo)\n\nRAZA:\n6.Alta\n7.Baja\n10.SALIR\n\nEliga una opcion:","Error.No se permiten letras. Reingrese la opcion: ");

            switch(opcionMenu)
            {
                case 1:
                     indiceLibreMascota= BuscarLibreMascota(listaMascotas,TAM_MASC);
                        if(indiceLibreMascota!=-1)
                        {
                            AltaMascotas(listaMascotas,TAM_MASC,indiceLibreMascota,contadorRazasCargadas,listaRazas);
                            contadorMascotasCargadas++;
                            printf("\nMascota cargado con exito\n");
                        }else
                        {
                            printf("\nNo hay mas espacio de almacenamiento\n");
                        }
                    break;
                case 2:
                   if(contadorMascotasCargadas!=0)
                    {
                            ListarMascotas(listaMascotas,TAM_MASC);
                            printf("\nIngrese el ID de la mascota que desea dar de baja:");
                            scanf("%d",&idEliminar);
                            if(eliminarUnaMascota(listaMascotas,contadorMascotasCargadas,idEliminar))
                            {
                                printf("\nSe ha eliminado la mascota exitosamente\n");
                            }else
                            {
                                printf("\nEl ID ingresado no corresponde a ninguna mascota.Por favor, verifique e intente nuevamente\n");
                            }
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                break;
                case 3:
                     if(contadorMascotasCargadas!=0)
                     {
                            ListarMascotas(listaMascotas,contadorMascotasCargadas);
                            printf("\nIngrese el ID de la mascota que desea modificar:");
                            scanf("%d", &idAModificar);
                            if(BuscarPorIDMascota(idAModificar,contadorMascotasCargadas,listaMascotas)!=-1)
                            {
                                printf("\n1-MODIFICAR NOMBRE\n2-MODIFICAR EDAD\n3-MODIFICAR TIPO\n4-MODIFICAR SEXO\n5-MODIFICAR PESO\n6-MODIFICAR ID RAZA\nSeleccione la accion que desea realizar:");
                                scanf("%d", &opcionModificar);
                                if(ModificarUnaMascota(listaMascotas,idAModificar,opcionModificar,contadorMascotasCargadas,listaRazas,contadorRazasCargadas)==0)
                                {
                                    printf("\nModificacion cargada con exito\n");
                                }else
                                {
                                    printf("\n No se pudo realizar la modificacion solicitada\n");
                                }

                            }else
                            {
                                printf("\nEl ID ingresado no corresponde a ningun mascota.Por favor, verifique e intente nuevamente\n");
                            }
                     }else
                     {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                     }
                    break;

                case 4:
                    if(contadorMascotasCargadas!=0)
                    {
                        do{
                            printf("\nINFORMAR:\n\n1.Mostrar Mascotas\n2.Mostrar Razas\n3.Mostrar paises\n4.Mostrar listado de mascotas con sus razas y paises de origen");
                            printf("\n5.Listar por cada raza las mascotas\n6.Mostrar mascotas ordenadas segun el peso\n7.Mostrar pais con mas mascotas\n8.Listado mascotas con raza y codigo telefonico");
                            printf("\n9.Mostrar mascotas ordenadas por codigo telefonico\n10.Listar por tamanio y peso\n11.Mostar listado de un tamanio a ingresar\n17.SALIR DE ESTE MENU\n");
                            opcionMostrar=PedirEntero("\nEliga una opcion: ","Error.No se permiten letras. Reingrese la opcion: ");
                            switch(opcionMostrar)
                            {
                                case 1:
                                    ListarMascotas(listaMascotas,contadorMascotasCargadas);
                                    break;
                                case 2:
                                    ListarRazas(listaRazas,contadorRazasCargadas);
                                    break;
                                case 3:
                                    MostrarListadoPaisesDisponibles(listaPaises,TAM_PAIS);
                                    break;
                                case 4:
                                    ListarMascotasConRaza(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas);
                                    break;
                                case 5:
                                    ListarPorCadaRazaLasMascotas(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas);
                                    break;
                                case 6:
                                    if(OrdenarMascotasPorPeso(listaMascotas,contadorMascotasCargadas))
                                    {
                                        ListarMascotas(listaMascotas,contadorMascotasCargadas);
                                    }
                                    break;
                                case 7:
                                    //MostrarPaisConMasMascotas(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas);
                                    MostrarPaisConMasMascotas(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas,listaPaises,TAM_PAIS);
                                    break;
                                case 8:
                                    ListarMascotasConRazaYCodigoTelefonico(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas,listaPaises,contadorPaisesCargados);
                                    break;
                                case 9:
                                     ListarMascotasOrdenadasPorCodigoTelefonico(listaMascotas,contadorMascotasCargadas,listaRazas,contadorRazasCargadas,listaPaises,contadorPaisesCargados);
                                    break;
                                case 10:
                                    RecogerDatosDeCadaTipo(listaMascotas,TAM_MASC);
                                    break;
                                case 11:
                                    ObtenerTamanioRazaValido("\nIngrese el tamanio de las mascotas que desea listar: ","Error.Los tamanios validos son 'chico','mediano,', 'grande'.Reingrese: ",tamanioIngresado);
                                    ListarPorTamanioYPeso(listaMascotas,TAM_MASC,listaRazas,TAM_RAZA,listaPaises,TAM_PAIS,tamanioIngresado);
                                    break;
                            }
                        }while(opcionMostrar!=17);
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                  break;
                case 5:
                    HarcodearRazas(listaRazas);
                    HarcodearMascotas(listaMascotas);
                    HarcodearPaises(listaPaises);
                    contadorMascotasCargadas=7;
                    contadorRazasCargadas=6;
                    contadorPaisesCargados=5;
                    printf("\nLos datos se harcodearon con exito.\n");
                break;

                case 6:
                    if(contadorMascotasCargadas!=0)
                    {
                        indiceLibreRaza= BuscarLibreRaza(listaRazas,TAM_RAZA);
                        if(indiceLibreRaza!=-1)
                        {
                            AltaRaza(listaRazas,TAM_RAZA,indiceLibreRaza,listaPaises,TAM_PAIS);
                            contadorRazasCargadas++;
                            printf("\nRaza cargada con exito\n");
                        }else{
                        printf("\nNo hay mas espacio de almacenamiento\n");
                        }
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                    break;
                case 7:
                    if(contadorMascotasCargadas!=0 && contadorRazasCargadas!=0)
                    {
                            ListarRazas(listaRazas,contadorRazasCargadas);
                            printf("\nIngrese el ID de la raza que desea dar de baja:");
                            scanf("%d",&idEliminar);
                            if(EliminarUnaRaza(listaRazas,contadorRazasCargadas,idEliminar,listaMascotas,contadorMascotasCargadas) )
                            {
                                printf("\nSe ha eliminado la raza exitosamente\n");
                            }else
                            {
                                printf("\nEl ID ingresado no corresponde a ninguna raza.Por favor, verifique e intente nuevamente\n");
                            }
                    }else
                    {
                        printf("\nPor favor, primero realice la carga de los datos.\n");
                    }
                    break;
            }
        }while(opcionMenu!=10);
    return 0;
}


