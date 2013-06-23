#include <stdio.h>
#include "TDA_Statistics.h"

int FCompararPlayers (void* Elemento1, void* Elemento2){
    NodoJugador Elem1;
    NodoJugador Elem2;
    Elem1 = *(NodoJugador*)Elemento1;
    Elem2 = *(NodoJugador*)Elemento2;
    if (Elem2.Puntaje == Elem1.Puntaje)
        return 0;
    if (Elem2.Puntaje < Elem1.Puntaje)
        return 1;
    return -1;
}

int FCompararSamples (void* Elemento1, void* Elemento2){
    NodoJugador Elem1;
    NodoJugador Elem2;
    Elem1 = *(NodoJugador*)Elemento1;
    Elem2 = *(NodoJugador*)Elemento2;
    if (Elem2.Puntaje == Elem1.Puntaje)
        return 0;
    if (Elem2.Puntaje < Elem1.Puntaje)
        return 1;
    return -1;
}

void FClonarPlayers (void* Elemento1, void* Elemento2){
    return 0;
}

void FClonarSamples (void* Elemento1, void* Elemento2){
    return 0;
}

void FDestruirPlayers (void* Elemento){
    return 0;
}

void FDestruirSamples (void* Elemento){
    return 0;
}

int StatsCrear(TDA_Statistics* Statistics){
    int (*FCompararPlayers)( void *Elemento1, void *Elemento2);
    void (*FClonarPlayers)(void *Elemento1, void *Elemento2);
    void (*FDestruirPlayers)(void *Elemento);
    int (*FCompararSamples)( void *Elemento1, void *Elemento2);
    void (*FClonarSamples)(void *Elemento1, void *Elemento2);
    void (*FDestruirSamples)(void *Elemento);
    ABO_Crear(Statistics->Samples, sizeof(NodoSamples),int (FCompararSamples)(void*, void*), void (FClonarSamples)(void*, void*), void (FDestruirSamples)(void *));
    ABO_Crear(Statistics->Players, sizeof(NodoPlayers),int (FCompararPlayers)(void*, void*), void (FClonarPlayers)(void*, void*), void (FDestruirPlayers)(void *));
    crearListaOrdenada(Statistics->Lista,sizeof(NodoSamples),int (FCompararSamples)(void*, void*), void (FClonarSamples)(void*, void*), void (FDestruirSamples)(void *));
    Statistics->creado = 0;
    return RES_OK;
}

int StatsContarMuestra(TDA_Statistics* Statistics, const TDA_Score * Muestra, const char* Liga){


}

int StatsObtenerEstadisticasJugador(TDA_Statistics* Statistics, const char* Jugador, TDA_Stats* Stats){


}

int StatsObtenerEstadisticasLiga(TDA_Statistics* Statistics, const char* Liga, TDA_Stats* Stats){


}

int DestruirStats(TDA_Statistics* Statistics){
    ABO_Vaciar(Statistics->Samples);
    ABO_Vaciar(Statistics->Players);
    destruirListaOrdenada(Statistics->Lista);
    Statistics->creado = 1;   /* Si creado vale 1, entonces no esta creado y por lo tanto es inutilizable */
    return RES_OK;
}
