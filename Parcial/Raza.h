

typedef struct
{
    int id;
    char nombre[20];
    char pais[20];
    char tipo[20];

}eRaza;


void hardCodearRaza(eRaza listadoRaza[], int sizeRaza);
int getRaza(int idRaza,eRaza listadoRaza[],int sizeRaza,char tipoM[]);
void modificarRaza(eRaza listadoRaza[], int sizeRaza,int id);
void mostrarTodasLasRazas(eRaza listadoRaza[], int sizeRaza);
void mostrarRaza(eRaza miRaza);
void mostrarRazaPorTipo(eRaza listadoRaza[], int sizeRaza,char tipo[]);
int validarIdRaza(eRaza listadoRaza[],int sizeRaza,char mensaje[], char mensajeError []);
int buscarRazaPorId(eRaza listadoRaza[], int sizeRaza,int id);
