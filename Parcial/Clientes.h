#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int id;//PK
  char nombre[30];
  char apellido[30];
  char localidad[30];
  int telefono;
  int edad;
  char sexo[10];
  int estado;

} cliente;

void inicializarCliente(cliente listadoCliente[], int sizeCliente);
void hardCodearCliente(cliente listadoCliente[], int sizeCliente);


cliente crearCliente (int idCliente);
int cargarCliente(cliente listadoCliente[], int sizeCliente,int index,int idCliente);

int buscarLibreCliente(cliente listadoCliente[], int sizeCliente);
int validarIdCliente(cliente listadoCliente[],int sizeCliente,char mensaje[], char mensajeError []);
int buscarClientePorId(cliente listadoCliente[], int sizeCliente,int id);

int modificarCliente(cliente listadoCliente[], int sizeCliente, int id);
int eliminarCliente(cliente listadoCliente[], int sizeCliente,int id);


void ordenarNombre(int sizeCliente,cliente listadoCliente[]);

void mostrarCliente(cliente miCliente);
void mostrarTodosLosClientes(cliente listadoCliente[], int sizeCliente);

void promedioSexo(cliente listadoCliente[],int sizeCliente);
