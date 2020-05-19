#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int id;//PK
  char tipo[20];
  char descripcion[50];
  int estado;

} eTipo;


void inicializarTipo(eTipo listadoTipo[], int sizeTipo);
void hardCodearTipo(eTipo listadoTipo[], int sizeTipo);
