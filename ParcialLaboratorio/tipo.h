
typedef struct{
 char descripcionRaza[15];
 char tamanioRaza[8];
 char paisOrigenRaza[15];
 int idRaza; //PK
 int idPais; //FK
 int isEmpty;
}eTipo;
