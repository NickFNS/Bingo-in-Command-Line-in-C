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

//----------Estructura "ArchivosE", con algunos datos utiles para la creacion del ranking

struct ArchivosE{

    char nombre[15];
    char apellido[15];
    char dni[9];
    float puntaje;
};

//----------Funciones de "Archivo"----------

Archivo rankingVacio(){

    Archivo v = malloc(sizeof(struct ArchivosE));

    strcpy(v -> nombre, "XXX");
    strcpy(v -> apellido, "XXX");
    strcpy(v -> dni, "XXX");
    v -> puntaje = -1;

    return v;
}

void generarRanking(Archivo r[]){

    for (int i = 0; i < 10; i++){
        r[i] = rankingVacio();
    }
}

void cargarPuntajes(Archivo r[]){

    FILE * ranking;
    ranking = fopen("Puntajes.txt", "r");

    while(!feof(ranking)){

        char aux[50] = " ";
        fgets(aux, 50, ranking);

        Archivo a = crearDatos(aux, 50);
        sumarAlRanking(r, a);
    }

    fclose(ranking);

    ordenarRanking(r);
}

Archivo crearDatos(char a[], int cant){

    Archivo c = malloc(sizeof(struct ArchivosE));

    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    char auxNombre[50] = " ";
    char auxApellido[50] = " ";
    char auxDNI[50] = " ";
    char auxPuntaje[50] = " ";

    for (int i = 0; i < cant; i++){
        if(a[i] == '+'){
            pos1 = i;
            i = 50;
        }
    }

    for (int i = pos1 + 1; i < cant; i++){
        if(a[i] == '+'){
            pos2 = i;
            i = 50;
        }
    }

    for (int i = pos2 + 1; i < cant; i++){
        if(a[i] == '+'){
            pos3 = i;
            i = 50;
        }
    }

    for (int i = 0; i < pos1; i++){
        auxNombre[i] = a[i];
    }

    for (int i = pos1 + 1; i < pos2; i++){
        auxApellido[i - pos1 - 1] = a[i];
    }

    for (int i = pos2 + 1; i < pos3; i++){
        auxDNI[i - pos2 - 1] = a[i];
    }

    for (int i = pos3 + 1; i < cant; i++){
        auxPuntaje[i - pos3 - 1] = a[i];
    }

    strcpy(c -> nombre, auxNombre);
    strcpy(c -> apellido, auxApellido);
    strcpy(c -> dni, auxDNI);
    c -> puntaje = atof(auxPuntaje);

    return c;
};

void sumarAlRanking(Archivo a[], Archivo n){

    int i = buscarPosicion(a);

    if(i != -9){
        a[i] = n;
    }

}

int buscarPosicion(Archivo a[]){

    int posicion = -9;
    int i = 0;

    while(posicion == -9 && i < 10){
        if(a[i] -> puntaje == -1){
            posicion = i;
        }
        i++;
    }

    return posicion;
}

void ordenarRanking(Archivo a[]){

    Archivo aux = malloc(sizeof(struct ArchivosE));

    for(int i = 0; i < 10; i++){
        for(int n = 0; n < 9; n++){
            if(a[n] -> puntaje < a[n + 1] -> puntaje){

                aux = a[n];
                a[n] = a[n + 1];
                a[n + 1] = aux;
            }
        }
    }
}

void guardarNuevoRanking(Archivo a[]){

    FILE * ranking;

    ranking = fopen("Puntajes.txt", "w");

    ordenarRanking(a);

    for(int i = 0; i < 10; i++){
        if(a[i] -> puntaje != -1 && a[i] -> puntaje != 0){
            fprintf(ranking, "%s+%s+%s+%.2f\n", a[i] -> nombre, a[i] -> apellido, a[i] -> dni, a[i] -> puntaje);
        }
    }

    fclose(ranking);
}

void mostrarRanking(Archivo a[]){

    printf("\n---------------> El ranking es: <---------------\n");

    for(int i = 0; i < 10; i++){
        if(a[i] -> puntaje != -1 & a[i] -> puntaje != 0){
            printf("\nNombre: %s\nApellido: %s\nDNI: %s\nPuntuacion: %.2f\n", a[i] -> nombre, a[i] -> apellido, a[i] -> dni, a[i] -> puntaje);
        }
    }

    printf("\n\n---------------> Juego terminado. Hasta la proxima! <---------------\n\n");
}

//--------------------Gets y Sets--------------------

char * getNombreArchivos(Archivo a){
return a -> nombre;}

char * getApellidoArchivos(Archivo a){
return a -> apellido;}

char * getDNIArchivos(Archivo a){
return a -> dni;}

float getPuntajeArchivos(Archivo a){
return a -> puntaje;}

void setNombreArchivos(Archivo a, char n[15]){
strcpy(a -> nombre, n);}

void setApellidoArchivos(Archivo a, char ap[15]){
strcpy(a -> apellido, ap);}

void setDNIArchivos(Archivo a, char d[15]){
strcpy(a -> dni, d);}

void setPuntajeArchivos(Archivo a, float p){
a -> puntaje = p;}
