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

int main()
{
    //Introduccion al juego
    introduccion();

    srand(time(0));

    Jugador usuario;
    Jugador computadora;
    Partida juego;
    Archivo rank[10];

    //Empieza el juego!

    usuario = pedirDatos();

    computadora = datosComputadora(getCantidadDeCartones(usuario));

    mostrarInfo(usuario);

    juego = partidaCero();

    nucleoPartida(juego, usuario, computadora);

    printf(RENGLON);

    mostrarPuntajes(getContadorPartida(juego), usuario, computadora);

    guardarEnArchivo(usuario);

    generarRanking(rank);

    cargarPuntajes(rank);

    guardarNuevoRanking(rank);

    mostrarRanking(rank);

    return 0;
}
