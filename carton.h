#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

//----------Definicion de la estructura del carton y su tipo----------

struct CartonE;

typedef struct CartonE * Carton;

//----------Definicion de las funciones----------

//PRE: No se necesita ningun parametro
//POST: Se devuelve un carton cargado manualmente
Carton cargarCartonManual();

//PRE: No se necesita ningun parametro
//POST: Se devuelve un carton cargado de forma aleatoria
Carton cargarCartonAleatorio();

//PRE: Se pide el carton en cuestion y el numero a buscar
//POST: Se verifica que este numero este en el carton, o no
int verificarRepeticion (Carton c, int buscar);

//PRE: Se pide el numero a verificar
//POST: Se verifica que este en el rango de numeros permitidos (1 a 90)
int verificarRango (int buscar);

//PRE: Se pide el carton a mostrar
//POST: Se muestra el carton
void mostrarCarton(Carton c);

//PRE: Se pide el carton en cuestion y el numero de la bolilla
//POST: Si el numero esta en el carton, se lo establece en -1
Carton buscarNumeroCarton(Carton c, int b);

//PRE: Se pide el carton en cuestion
//POST: Se verifica si se hizo fila o no
int verificarFilas(Carton c);

//PRE: Se pide el carton en cuestion
//POST: Se verifica si se hizo columna o no
int verificarColumnas(Carton c);

//PRE: Se pide el carton en cuestion
//POST: Se verifica si se hizo bingo o no
int verificarBingo(Carton c);

#endif // CARTON_H_INCLUDED
