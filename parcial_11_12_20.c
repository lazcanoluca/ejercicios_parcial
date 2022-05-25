#include <stdlib.h>
#include "parcial_11_12_20.h"

int agregar_ciudad(mapa_t* mapa, ciudad_t* ciudad_nueva, char ciudad_anterior[MAX_NOMBRE])
{
    if (!mapa || !ciudad_nueva) return -1;
    ciudad_t *ciudad = mapa->origen;

    while (!strcmp(ciudad->nombre, ciudad_anterior)) {
        ciudad = ciudad->proxima;
        if (!ciudad) return -1;
    }

    ciudad_nueva->proxima = ciudad->proxima;
    ciudad_nueva->anterior = ciudad;
    ciudad->proxima->anterior = ciudad_nueva;
    ciudad->proxima = ciudad_nueva;

    return 0;
}

mapa_t* crear_mapa(ciudad_t ciudades[MAX_CIUDADES])
{
    mapa_t *mapa = malloc(sizeof(mapa_t));
    if (!mapa) return NULL;
    mapa->origen = &ciudades[0];
    
    for (int i = 0; i < MAX_CIUDADES; i++) {
        ciudades[i].proxima = (i == MAX_CIUDADES) ? NULL : &ciudades[i+1];
        ciudades[i].anterior = (i == 0) ? NULL : &ciudades[i-1];
    }

    return mapa;
}

int intercambiar_extremos(mapa_t* mapa)
{
    if (!mapa) return -1;

    mapa->final->proxima = mapa->origen->proxima;
    mapa->origen->anterior = mapa->final->anterior;
    mapa->origen->proxima = NULL;
    mapa->final->anterior = NULL;
    mapa->origen->anterior->proxima = mapa->origen;
    mapa->final->proxima->anterior = mapa->final;
    ciudad_t *aux = mapa->origen;
    mapa->origen = mapa->final;
    mapa->final = aux;

    return 0;
}