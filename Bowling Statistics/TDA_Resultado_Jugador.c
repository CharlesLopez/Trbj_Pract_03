#include "TDA_Resultado_Jugador.h"
#include <string.h>



int crearResultadoJugador(TDA_Resultado_Jugador* resultadoJugador){
    if (resultadoJugador->creado==1)
        return 0;
    resultadoJugador->puntaje=0;
    resultadoJugador->creado=1;
    return 1;
}

int establecerNombre(TDA_Resultado_Jugador* resultadoJugador, char* Nombre){
    strcpy(resultadoJugador->nombre,Nombre);
    return 1;
}

int establecerPuntaje(TDA_Resultado_Jugador* resultadoJugador, int puntaje){
    resultadoJugador->puntaje=puntaje;
    return 1;
}

int establecerLiga(TDA_Resultado_Jugador* resultadoJugador, char* liga){
    strcpy(resultadoJugador->liga,liga);
    return 1;
}

int obtenerNombre(TDA_Resultado_Jugador* resultadoJugador, char* Nombre){
    strcpy(Nombre,resultadoJugador->nombre);
    return 1;
}

int obtenerPuntaje(TDA_Resultado_Jugador* resultadoJugador, int* puntaje){
    puntaje=&resultadoJugador->puntaje;
    return 1;
}

int obtenerLiga(TDA_Resultado_Jugador* resultadoJugador, char* liga){
    strcpy(liga,resultadoJugador->liga);
    return 1;
}
