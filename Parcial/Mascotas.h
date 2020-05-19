#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int id;//PK
  char nombre[20];
  char tipo[20];
  int idRaza;
  int edad;
  float peso;
  char sexo[20];
  int estado;
  int idCliente;//FK

} mascota;

void inicializarMascota(mascota listadoMascota[], int sizeMascota);
void hardCodearMascota(mascota listadoMascota[], int sizeMascota);


int eliminarMascota(mascota listadoMascota[], int sizeMascota,int id);

int buscarLibreMascota(mascota listadoMascota[], int sizeMascota);

int validarIdMascota(mascota listadoMascota[],int sizeMascota,char mensaje[], char mensajeError []);
int buscarMascotaPorId(mascota listadoMascota[], int sizeMascota,int id);

void ordenarMascotasPorTipo(mascota listadoMascota[], int sizeMascota);

float promedioEdad(mascota listadoMascota[],int sizeMascotas);
float promedioEdadPorTipo(mascota listadoMascota[],int sizeMascotas,char tipoM[]);


