#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

//----------Definicion de la estructura del jugador y su tipo----------

struct JugadorE;

typedef struct JugadorE * Jugador;

//----------Definicion de las funciones----------

//PRE: No se necesita ningun parametro
//POST: Se inicializa al jugador en 0
Jugador jugadorCero();

//PRE: Se pide el nombre del jugador
//POST: Se devuelve la cantidad de cartones elegida
int pedirCantidadCartones(char nombre[15]);

//PRE: No se necesita ningun parametro
//POST: Se devuelven los datos del usuario
Jugador pedirDatos();

//PRE: Se pide el jugador a mostrar
//POST: Se muestra su info
void mostrarInfo(Jugador j);

//PRE: Se pide el jugador y su oponente
//POST: Se muestran ambos
void mostrarCartones(Jugador j, Jugador c);

//PRE: Se pide la cantidad de cartones elegida por el usuario
//POST: Se le dan datos falsos a la computadora
Jugador datosComputadora(int cant);

//PRE: Se pide el jugador, su contrincante, el numero a buscar y el numero de carton
//POST: Se verifica si el numero esta en el carton o no
void busquedaEnCartones(Jugador j, Jugador pc, int b, int pos);

//PRE: Se pide el jugador y su contrincante
//POST: Se verifica que se haya hecho fila, columna o bingo
void verificarFilaColumnaBingo(Jugador j, Jugador c);

//PRE: Se pide la cantidad de numeros cantados y los jugadores
//POST: Se calculan y mustran sus puntajes
void mostrarPuntajes(int numerosCantados, Jugador j, Jugador c);

//PRE: Se pide el jugador y los numeros cantados
//POST: Se calcula y devuelve su puntaje
Jugador calcularPuntajeJugador (Jugador j, int cant);

//PRE: Se pide la computadora y los numeros cantados
//POST: Se calcula y devuelve su puntaje
Jugador calcularPuntajeComputadora (Jugador c, int cant);

//PRE: Se pide el jugador de la actual partida
//POST: Se guarda en el .txt
void guardarEnArchivo(Jugador j);

//----------Gets y Sets----------

char * getNombreJugador(Jugador j);

char * getApellidoJugador(Jugador j);

char * getDNIJugador(Jugador j);

int getCantidadDeCartones(Jugador j);

int getFilaJugador(Jugador j);

int getColumnaJugador(Jugador j);

int getBingoJugador(Jugador j);

float getPuntajeJugador(Jugador j);

void setNombreJugador(Jugador j, char n[]);

void setApellidoJugador(Jugador j, char ap[]);

void setDNIJugador(Jugador j, char d[]);

void setFilaJugador(Jugador j, int f);

void setColumnaJugador(Jugador j, int c);

void setBingoJugador(Jugador j, int b);

void setPuntajeJugador(Jugador j, float p);

#endif // JUGADOR_H_INCLUDED
