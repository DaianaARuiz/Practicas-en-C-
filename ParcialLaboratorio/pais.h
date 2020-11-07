typedef struct{
 char nombreDePais[15];
 char continente[8];
 int codigoTelefonico;
 int idPais; //PK
 int isEmpty;
}ePaisOrigen;

///////HARCODEO////////////////
void HarcodearPaises(ePaisOrigen listaPaises[]);

//////////PAIS
void MostrarListadoPaisesDisponibles(ePaisOrigen [], int );
void ImprimirUnPais(ePaisOrigen);

