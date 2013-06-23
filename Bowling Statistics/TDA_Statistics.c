#include <stdio.h>
#include "TDA_Statistics.h"

typedef struct{
    char Score[22];
    int Peso;
}TScore;        /* aca se almacenara los scores y su peso */

typedef struct Nodo1{
    char Nombre[20];       /* Nombre del jugador */
    TScore Frecuencia[10];
    int Tiros[4];          /* Cantidad de tiros por tipo. En 0 los strikes, 1 los spares, 2 las canaletas y 3 los demas */
}NodoSamples;

typedef struct Nodo2{
    char NombreLiga[20];         /* Nombre de la liga */
    char NombreJugador[20];       /* Nombre del jugador */
}NodoPlayers;

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
