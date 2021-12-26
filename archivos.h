#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

//Definicion de la estructura que usamos para facilitar el trabajo con archivos

struct ArchivosE;

typedef struct ArchivosE * Archivo;

//----------Definicion de las funciones----------

//PRE: No se necesita ningun parametro
//POST: Se devuelve una struct de Archivo inicializada en 0
Archivo rankingVacio();

//PRE: Se envia la estructura de Archivo creada en el main
//POST: Se devuelven todas las posiciones inicializadas en 0
void generarRanking(Archivo r[]);

//PRE: Se envia la estructura de Archivo creada en el main
//POST: Se cargan los puntajes del ranking que hay en el .txt
void cargarPuntajes(Archivo r[]);

//PRE: Se envia el auxiliar que toma los datos y su tamaño
//POST: Se devuelve una posicion del ranking creado/leído
Archivo crearDatos(char a[], int cant);

//PRE: Se pide el ranking completo y la persona a sumar al mismo
//POST: Se agrega dicha persona al ranking
void sumarAlRanking(Archivo a[], Archivo n);

//PRE: Se envia el ranking con el cual se esta trabajando
//POST: Se devuelve una posicion disponible para sumar una persona
int buscarPosicion(Archivo a[]);

//PRE: Se pide el ranking a ordenar
//POST: Se ordena el ranking
void ordenarRanking(Archivo a[]);

//PRE: Se pide el ranking generado en el codigo tras la nueva partida
//POST: Se guarda este nuevo ranking en el .txt
void guardarNuevoRanking(Archivo a[]);

//PRE: Se pide un ranking a mostrar
//POST: Se muestra el ranking
void mostrarRanking(Archivo a[]);

//----------Gets y Sets----------

char * getNombreArchivos(Archivo a);

char * getApellidoArchivos(Archivo a);

char * getDNIArchivos(Archivo a);

float getPuntajeArchivos(Archivo a);

void setNombreArchivos(Archivo a, char n[15]);

void setApellidoArchivos(Archivo a, char ap[15]);

void setDNIArchivos(Archivo a, char d[15]);

void setPuntajeArchivos(Archivo a, float p);

#endif // ARCHIVOS_H_INCLUDED
