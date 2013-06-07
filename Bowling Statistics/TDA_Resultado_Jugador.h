#ifndef __Resultado_Jugador__
#define __Resultado_Jugador__

typedef struct {
    char liga[20];
    char nombre[20];
    int puntaje;
    int creado;
}TDA_Resultado_Jugador;

int crearResultadoJugador(TDA_Resultado_Jugador* resultadoJugador);
    /*re-Condicion:Resultado jugador no creado
    Post-Condicion:Crea e inicializa el resultado jugador*/

int destruirResultadoJugador(TDA_Resultado_Jugador* resultadoJugador);
    /*Pre-Condicion:Resultado jugador creado
    Post-Condicion:Resultado jugador destruido e inutilizable*/

int establecerNombre(TDA_Resultado_Jugador* resultadoJugador, char* nombre);

int establecerPuntaje(TDA_Resultado_Jugador* resultadoJugador, int puntaje);

int establecerLiga(TDA_Resultado_Jugador* resultadoJugador, char* liga);

int obtenerNombre(TDA_Resultado_Jugador* resultadoJugador, char* nombre);

int obtenerPuntaje(TDA_Resultado_Jugador* resultadoJugador, int* puntaje);

int obtenerLiga(TDA_Resultado_Jugador* resultadoJugador, char* liga);


#endif /*__Resultado_Jugador__*/
