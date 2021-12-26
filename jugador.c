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

//----------Estructura "JugadorE", con los datos del jugador, algunas banderas y el array de cartones

struct JugadorE{

    char nombre[15];
    char apellido[15];
    char dni[9];
    int cantidadDeCartones;
    int fila;
    int columna;
    int bingo;
    float puntaje;
    Carton cartones[3];
};

//----------Funciones de "Jugador"----------

Jugador jugadorCero(){

    Jugador j = malloc(sizeof(struct JugadorE));

    strcpy(j -> nombre, " ");
    strcpy(j -> apellido, " ");
    strcpy(j -> dni, " ");
    j -> cantidadDeCartones = 0;
    j -> fila = 0;
    j -> columna = 0;
    j -> bingo = 0;
    j -> puntaje = 0;

    return j;
}

int pedirCantidadCartones(char nombre[15]){

    int cartAux = 0;
    int cantidad = 0;

    do{
        printf("\nCon cuantos cartones vas a querer jugar %s? (Elegi un numero del 1 al 3): ", nombre);
        scanf("%d", &cartAux);
        }while ((cartAux > 3) || (cartAux <= 0));//Se verifica que el numero de los cartones sea el correcto

        cantidad = cartAux;

        return cantidad;
}

Jugador pedirDatos(){

    Jugador j = malloc(sizeof(struct JugadorE));

    j = jugadorCero();

    char auxNombre[15] = " ";
    char auxApellido[15] = " ";
    char auxDNI[15] = " ";
    int eleccion = 0;

    printf("\nIntroduzca su nombre: ");
    fflush(stdin);
    gets(auxNombre);
    strcpy(j -> nombre, auxNombre);

    printf("Introduzca su apellido: ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(j -> apellido, auxApellido);

    printf("Introduzca su DNI: ");
    fflush(stdin);
    gets(auxDNI);
    strcpy(j -> dni, auxDNI);

    printf(RENGLON);

    j -> cantidadDeCartones = pedirCantidadCartones(j -> nombre);

    printf(RENGLON);

    do{

     printf("\n%s, vas a querer jugar con cartones cargados de manera aleatoria o queres cargarlos vos mismo/a?\n\n", j -> nombre);

     printf("1 - Cartones Aleatorios\n\n");
     printf("2 - Cartones Manuales\n\n");

     scanf("%d", &eleccion);

        switch(eleccion){

            case 1:

                for (int i = 0; i < j -> cantidadDeCartones; i++){
                j -> cartones[i] = cargarCartonAleatorio();
                }

                break;

            case 2:

                for (int i = 0; i < j -> cantidadDeCartones; i++){
                j -> cartones[i] = cargarCartonManual();
                }

                break;

            default: printf("\nOpcion invalida. %s, selecciona alguna de las propuestas.\n\n", j -> nombre);
            break;
            }

    }while ((eleccion > 2) || (eleccion <= 0));//Se verifica que la selección sea la correcta

    printf(RENGLON);

    return j;
}

void mostrarInfo(Jugador j){

    printf("\nTu nombre es: %s\n", j -> nombre);
    printf("Tu apellido es: %s\n", j -> apellido);
    printf("Y tu D.N.I es: %s\n", j -> dni);

    for (int i = 0; i < j -> cantidadDeCartones; i++){
            printf("\n---> Carton %d de %s:\n\n", i + 1, j -> nombre);
            mostrarCarton(j -> cartones[i]);
        }
}

void mostrarCartones(Jugador j, Jugador c){

    for (int i = 0; i < getCantidadDeCartones(j); i++){
        printf("Carton %d de %s: \n", i + 1, j -> nombre);
        mostrarCarton(j -> cartones[i]);
        printf("Carton %d de la computadora \n", i + 1);
        mostrarCarton(c -> cartones[i]);
        printf("\n");
    }
}

Jugador datosComputadora(int cant){

    Jugador c = malloc(sizeof(struct JugadorE));

    c -> fila = 0;
    c -> columna = 0;
    c -> bingo = 0;
    c -> puntaje = 0;
    c -> cantidadDeCartones = cant;

    strcpy (c -> nombre, "Computadora");
    strcpy (c -> apellido, "Malvada");
    strcpy(c -> dni, "0101010");

    for (int i = 0; i < cant; i++){
        c -> cartones[i] = cargarCartonAleatorio();
    }

    return c;
};

void busquedaEnCartones(Jugador j, Jugador pc, int b, int pos){

    for (int i = 0; i < j -> cantidadDeCartones; i++){
        j -> cartones[pos] = buscarNumeroCarton(j -> cartones[pos], b);
        pc -> cartones[pos] = buscarNumeroCarton(pc -> cartones[pos], b);
    }

}

void verificarFilaColumnaBingo(Jugador j, Jugador c){

    //Se verifican las filas
    if (j -> fila == 0 & c -> fila == 0){
        for(int f = 0; f < j -> cantidadDeCartones; f++){
            if ((verificarFilas(j -> cartones[f])) == 1){
                j -> fila = 1;
            } else
            if ((verificarFilas(c -> cartones[f])) == 1){
                c -> fila = 1;
            }
        }
    }

    //Se verifican las columnas
    if (j -> columna == 0 & c -> columna == 0){
        for(int f = 0; f < j -> cantidadDeCartones; f++){
            if ((verificarColumnas(j -> cartones[f])) == 1){
                j -> columna = 1;
            } else
            if ((verificarColumnas(c -> cartones[f])) == 1){
                c -> columna = 1;
            }
        }
    }

    //Se verifica el bingo
    if (j -> bingo == 0 & c -> bingo == 0){
        for(int f = 0; f < j -> cantidadDeCartones; f++){
            if ((verificarBingo(j -> cartones[f])) == 1){
                j -> bingo = 1;
                printf("-----> Bien %s, hiciste bingo! Ganaste!\n", j -> nombre);
                system("pause");
            } else
            if ((verificarBingo(c -> cartones[f])) == 1){
                c -> bingo = 1;
                printf("-----> Uy no! La computadora hizo bingo! Perdiste!\n");
                system("pause");
            }
        }
    }

}

void mostrarPuntajes(int numerosCantados, Jugador j, Jugador c){

    j = calcularPuntajeJugador(j, numerosCantados);
    c = calcularPuntajeComputadora(c, numerosCantados);

    printf("\n\nEl puntaje final de %s es: %.2f", j -> nombre, j -> puntaje);
    printf("\nEl puntaje final de la computadora es: %.2f\n", c -> puntaje);
}

Jugador calcularPuntajeJugador(Jugador j, int cant){

    Jugador p = malloc(sizeof(struct JugadorE));

    p = j;

    p -> puntaje = 0;

    if(p -> fila == 1){
        p -> puntaje = p -> puntaje + 20;
    }

    if (p -> columna == 1){
        p -> puntaje = p -> puntaje + 10;
    }

    if(p -> bingo == 1){
        p -> puntaje = p -> puntaje + 70;
    }

    if (cant < 30){
        p -> puntaje = p -> puntaje * 2;
    } else if ((cant >= 30) && (cant <= 50)){
        p -> puntaje = p -> puntaje * 1.7;
    } else if ((cant > 50) && (cant <= 70)){
        p -> puntaje = p -> puntaje * 1.5;
    }

    return p;
};

Jugador calcularPuntajeComputadora(Jugador c, int cant){

    Jugador pc = malloc(sizeof(struct JugadorE));

    pc = c;

    pc -> puntaje = 0;

    if(pc -> fila == 1){
        pc -> puntaje = pc -> puntaje + 20;
    }

    if (pc -> columna == 1){
        pc -> puntaje = pc -> puntaje + 10;
    }

    if(pc -> bingo == 1){
        pc -> puntaje = pc -> puntaje + 70;
    }

    if (cant < 30){
        pc -> puntaje = pc -> puntaje * 2;
    } else if ((cant > 30) && (cant < 50)){
        pc -> puntaje = pc -> puntaje * 1.7;
    } else if ((cant > 50) && (cant < 70)){
        pc -> puntaje = pc -> puntaje * 1.5;
    }

    return pc;
}

void guardarEnArchivo(Jugador j){

    FILE * puntos;

    puntos = fopen("Puntajes.txt", "a");
    fprintf(puntos, "%s+%s+%s+%.2f\n", j -> nombre, j -> apellido, j -> dni, j -> puntaje);
    fclose(puntos);

}

//--------------------Gets y Sets--------------------

char * getNombreJugador(Jugador j){
return j -> nombre;}

char * getApellidoJugador(Jugador j){
return j -> apellido;}

char * getDNIJugador(Jugador j){
return j -> dni;}

int getCantidadDeCartones(Jugador j){
return j -> cantidadDeCartones;}

int getFilaJugador(Jugador j){
return j -> fila;}

int getColumnaJugador(Jugador j){
return j -> columna;}

int getBingoJugador(Jugador j){
return j -> bingo;}

float getPuntajeJugador(Jugador j){
return j -> puntaje;}

void setNombreJugador(Jugador j, char n[]){
strcpy(j -> nombre, n);}

void setApellidoJugador(Jugador j, char ap[]){
strcpy(j -> nombre, ap);}

void setDNIJugador(Jugador j, char d[]){
strcpy(j -> dni, d);}

void setFilaJugador(Jugador j, int f){
j -> fila = f;}

void setColumnaJugador(Jugador j, int c){
j -> columna = c;}

void setBingoJugador(Jugador j, int b){
j -> bingo = b;}

void setPuntajeJugador(Jugador j, float p){
j -> puntaje = p;}
