#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jugador.h"
#include "carton.h"
#include "partida.h"
#include "archivos.h"
#define RENGLON "\n------------------------------------------------------------------------------\n"
#define FILASCARTONES 3
#define COLUMNASCARTONES 5

//----------Estructura "PartidaE", con la bolilla y algunas banderas necesarias----------
struct PartidaE{

    int bolilla[90];
    int contadorBolilla;
    int filas;
    int columnas;
    int bingo;
};

//----------Funciones de "Partida"----------

void introduccion(){

    printf("\n----------> Bienvenido al TP del Bingo del Grupo 19! <----------\n\n");
    printf("--> Integrantes:\n\n-Facundo Sierra\n-Rodrigo Zurdo\n-Juan Cruz Vazquez\n\n");
}

Partida partidaCero(){

    Partida p = malloc(sizeof(struct PartidaE));

    p -> contadorBolilla = 0;
    p -> filas = 0;
    p -> columnas = 0;
    p -> bingo = 0;

    return p;
}

void nucleoPartida(Partida p, Jugador j, Jugador c){

  printf("Bueno %s, es hora de jugar!\n", getNombreJugador(j));
  system("pause");

  do{

    printf(RENGLON);

    p = numerosBolillaSinRepetir(p);

    printf("El numero que salio de la bolilla es el %d. Ya salieron %d numeros\n\n", p -> bolilla[p -> contadorBolilla -1], p -> contadorBolilla);

    //Busqueda del numero que salio en el carton

    for (int i = 0; i < getCantidadDeCartones(j); i++){
       busquedaEnCartones(j, c, p -> bolilla[p -> contadorBolilla - 1], i);
    }

    printf("Cartones: \n\n");

    //Se muestran los cartones

    mostrarCartones(j, c);

    verificarFilaColumnaBingo(j, c);

    p = establecerFilaColumnaBingo(p, getFilaJugador(j), getColumnaJugador(j), getBingoJugador(j), getFilaJugador(c), getColumnaJugador(c), getBingoJugador(c));

  }while(getBingoPartida(p) != 1);

}

Partida numerosBolillaSinRepetir(Partida p){

    Partida b = malloc(sizeof(struct PartidaE));

    b = p;

    int numeroAProbar;

    do{
    numeroAProbar = 1+rand()%90;
    }while(repeticionBolilla(b -> bolilla, numeroAProbar) != -1);

    b -> bolilla[b -> contadorBolilla] = numeroAProbar;
    b -> contadorBolilla++;

    return b;
}

int repeticionBolilla(int n[90], int buscar){

    int num = -1;

    for (int i = 0; i < 90; i++){

        if (n[i] == buscar){
            num = 0;
            return num;
        }
    }

    return num;
}

Partida establecerFilaColumnaBingo(Partida p, int f1, int c1, int b1, int f2, int c2, int b2){

    Partida verificada = malloc(sizeof(struct PartidaE));

    verificada = p;

    if (f1 == 1 | f2 == 1){
        verificada -> filas = 1;
    }

    if (c1 == 1 | c2 == 1){
        verificada -> columnas = 1;
    }

    if (b1 == 1 | b2 == 1){
        verificada -> bingo = 1;
    }

    return verificada;
}

//--------------------Gets y Sets--------------------

int getFilasPartida(Partida p){
    return p -> filas;
}

int getColumnasPartida(Partida p){
    return p -> columnas;
}

int getBingoPartida(Partida p){
    return p -> bingo;
}

int getContadorPartida(Partida p){
    return p -> contadorBolilla;
}

void setFilasPartida(Partida p, int num){
    p -> filas = num;
}

void setColumnasPartida(Partida p, int num){
    p -> columnas = num;
}

void setBingoPartida(Partida p, int num){
    p -> bingo = num;
}
