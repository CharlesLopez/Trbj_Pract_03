# include <stdio.h>
# include "TDA_Statistics.h"

int StatsCrear(TDA_Statistics* Statistics){
    AB_Crear(Statistics->Samples, sizeof(NodoSamples));
    AB_Crear(Statistics->Players, sizeof(NodoPlayers));

    /* hay que ver que carajo metemos en la lista, por ahora le mando el nodosamples */
        crearListaOrdenada(Statistics->Lista,sizeof(NodoSamples),int (*comparar)(void*, void*), int (*clonar)(void*, void*), int (*destruir)(void *));

    Statistics->creado=0;

    return RES_OK;
}


int StatsContarMuestra(TDA_Statistics* Statistics, const TDA_Score * Muestra, const char* Liga){


}


int StatsObtenerEstadisticasJugador(TDA_Statistics* Statistics, const char* Jugador, TDA_Stats* Stats){


}


int StatsObtenerEstadisticasLiga(TDA_Statistics* Statistics, const char* Liga, TDA_Stats* Stats){


}

int DestruirStats(TDA_Statistics* Statistics){
    AB_Vaciar(Statistics->Samples);
    AB_Vaciar(Statistics->Players);
    destruirListaOrdenada(Statistics->Lista);
    Statistics->creado=1;   /* Si creado vale 1, entonces no esta creado y por lo tanto es inutilizable */

return RES_OK;
}
