#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED

//----------Definicion de la estructura de la partida y su tipo----------

struct PartidaE;

typedef struct PartidaE * Partida;

//----------Definicion de las funciones----------

//PRE: No se necesita ningun parametro
//POST: Se muestra una breve introduccion al Trabajo Practico
void introduccion();

//PRE: No se necesita ningun parametro
//POST: Se inicializa la partida en 0
Partida partidaCero();

//PRE: Se pide la variable de partida y los jugadores
//POST: Se lleva a cabo la partida de bingo
void nucleoPartida(Partida p, Jugador j, Jugador c);

//PRE: Se pide la variable de la partida
//POST: Se van generando los numeros de la bolilla
Partida numerosBolillaSinRepetir(Partida p);

//PRE: Se pide un ejemplo de bolilla y el numero a buscar
//POST: Se verifica que ese numero este en el vector de bolilla o no
int repeticionBolilla(int n[90], int buscar);

//PRE: Se pide la variable de partida y la bandera de fila, columna y bingo de los jugadores
//POST: Se establece la bandera correcta en la estructura de partida
Partida establecerFilaColumnaBingo(Partida p, int f1, int c1, int b1, int f2, int c2, int b2);

//----------Gets y Sets----------

int getFilasPartida(Partida p);

int getColumnasPartida(Partida p);

int getBingoPartida(Partida p);

int getContadorPartida(Partida p);

void setFilasPartida(Partida p, int num);

void setColumnasPartida(Partida p, int num);

void setBingoPartida(Partida p, int num);

#endif // PARTIDA_H_INCLUDED
