#include <stdio.h>
#include <string.h>
#include "TDA_Statistics.h"

int FCompararPlayers (void* Elemento1, void* Elemento2){
    NodoPlayers Elem1 = *(NodoPlayers*)Elemento1;
    NodoPlayers Elem2 = *(NodoPlayers*)Elemento2;
    return strcmp(Elem2.NombreJugador, Elem1.NombreJugador);
}

int FCompararSamples (void* Elemento1, void* Elemento2){
    NodoSamples Elem1 = *(NodoSamples*)Elemento1;
    NodoSamples Elem2 = *(NodoSamples*)Elemento2;
    return strcmp(Elem2.Frecuencia.Score, Elem1.Frecuencia.Score);
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
