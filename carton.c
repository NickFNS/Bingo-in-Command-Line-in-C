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

//----------Estructura "CartonE", con la matriz del carton
struct CartonE{

    int carton[FILASCARTONES][COLUMNASCARTONES];
};

//----------Funciones de "Carton"----------

Carton cargarCartonManual(){

    Carton c = malloc(sizeof(struct CartonE));

    int pos = 1, ncarton = 1, auxiliar = 0;
    int verifDis;
    int verifRang;

    for(int i = 0; i < FILASCARTONES; i++){
        for(int n = 0; n < COLUMNASCARTONES; n++){
            c -> carton[i][n] = -1;
        }
    }

          for (int j = 0; j < FILASCARTONES; j++){
            for (int a = 0; a < COLUMNASCARTONES; a++){
                    do{
                    printf("\n\nIngrese el numero de la posicion %d del carton %d: \n", pos, ncarton);
                    scanf("%d", &auxiliar);
                    verifDis = verificarRepeticion(c, auxiliar);
                    verifRang = verificarRango(auxiliar);
                    }while ((verifDis != -1) || (verifRang != -1));

                    c -> carton[j][a] = auxiliar;
                    pos++;

                     }
                    }
         pos = 1;
         ncarton++;

    return c;
}

Carton cargarCartonAleatorio(){

    Carton c = malloc(sizeof(struct CartonE));

    int numeroaCargar = 0;
    int busqueda = 0;

        for (int j = 0; j < FILASCARTONES; j++){
            for (int a = 0; a < COLUMNASCARTONES; a++){
                do{
                 numeroaCargar = 1+rand()%90;
                 busqueda = verificarRepeticion(c, numeroaCargar);
                }while(busqueda != -1);
                c -> carton[j][a] = numeroaCargar;
            }
        }

    return c;
}

int verificarRepeticion (Carton c, int buscar){

    int resultado = -1;

        for (int j = 0; j < FILASCARTONES; j++){
            for (int a = 0; a < COLUMNASCARTONES; a++){
                 if (c -> carton[j][a] == buscar){
                    resultado = 0;
                }
            }
        }

    return resultado;

}

int verificarRango (int buscar){

    int resultado = -1;

    if ((buscar > 90) || (buscar < 1)){
        printf("--ERROR: El numero ingresado se encuentra fuera del rango permitido--");
        resultado = 1;
    }

 return resultado;
}

void mostrarCarton(Carton c){

    for (int j = 0; j < FILASCARTONES; j++){
        for (int a = 0; a < COLUMNASCARTONES; a++){
            if (c -> carton[j][a] < 0){
                printf("[X] ");
            }else printf("[%d] ", c -> carton[j][a]);
        }
         printf("\n");
    }
     printf("\n");
}

Carton buscarNumeroCarton(Carton c, int b){

    Carton busqueda = malloc(sizeof(struct CartonE));

    busqueda = c;

    for (int i = 0; i < FILASCARTONES; i++){
        for (int n = 0; n < COLUMNASCARTONES; n++){
            if (busqueda -> carton[i][n] == b){
                busqueda -> carton[i][n] = b * -1;
            }
        }
    }

    return busqueda;
}

int verificarFilas(Carton c){

    int filas = 0;
    int hizoFila = 0;

    for (int v = 0; v < FILASCARTONES; v++){
        for (int F = 0; F < COLUMNASCARTONES; F++){
            if (c -> carton[v][F] < 0){
                filas++;
            }
            if (filas == 5){
                hizoFila = 1;
                return hizoFila;
            }
        }
    }

    return hizoFila;
}

int verificarColumnas(Carton c){

    int columnas = 0;
    int hizoColumna = 0;

    for (int v = 0; v < FILASCARTONES; v++){
        for (int C = 0; C < COLUMNASCARTONES; C++){
            if (c -> carton[C][v] < 0){
                columnas++;
            }
            if (columnas == 3){
                hizoColumna = 1;
                return hizoColumna;
            }
        }
    }

    return hizoColumna;
}

int verificarBingo(Carton c){

    int bingo = 0;
    int hizoBingo = 0;

    for (int h = 0; h < FILASCARTONES; h++){
        for (int b = 0; b < COLUMNASCARTONES; b++){
            if (c -> carton[h][b] < 0){
                bingo++;
            }
            if (bingo == 15){
                hizoBingo = 1;
            }
        }
    }

    return hizoBingo;
}
