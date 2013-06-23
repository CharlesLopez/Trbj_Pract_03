# ifndef __TDA_Statistics_H__
    #define __TDA_Statistics_H__
    #include "Lista_Simple.h"
    #include "TDA_Score.h"
    #include "TDA_Parcer.h"
    #include "TDA_ABO.h"
    #if !defined(RES_OK)
        #define RES_OK 0
    #endif

    #if !defined(MAYOR)
        #define MAYOR 1
    #endif

    #if !defined(MENOR)
        #define MENOR -1
    #endif

    #if !defined(IGUAL)
        #define IGUAL 0
    #endif

    #if !defined(RES_ERROR_REGISTRAR_JUGADOR)
        #define RES_ERROR_REGISTRAR_JUGADOR 1
    #endif

    #if !defined(RES_ERROR_REGISTRAR_MUESTRA)
        #define RES_ERROR_REGISTRAR_MUESTRA 2
    #endif

typedef struct{
    TABO Samples;
    TABO Players;
    TDA_Lista_Ordenada Lista;
    int Creado;
}TDA_Statistics;

int StatsCrear(TDA_Statistics* Statistics);
/* Recibe un TDA_Statistics, inicializa la estructura dejándola lista para utilizarse.
Devuelve un número entero como código de error o de exito.
En caso de que todo resulte como es esperado, se deberá devolver RES_OK definido como 0.
*/

int StatsContarMuestra(TDA_Statistics* Statistics, const TDA_Score * Muestra, const char* Liga);
/* Recibe el TDA_Statistics previamente creado, un TDA_Score para contabilizar y la liga a la que corresponde dicho score.
Los valores de retorno para esta primitiva deberán ser:
RES_OK: (0) Se agregó la nueva muestra correctamente al tda.
RES_ERROR_REGISTRAR_JUGADOR: (1) No se pudo contabilizar la muestra porque no fue posible registrar el jugador en el tda
                                (en caso de que falle la inserción en el AB players).
RES_ERROR_REGISTRAR_MUESTRA: (2) No se pudo contabilizar la muestra porque no fue posible registrar el score para el jugador indicado en el tda
                                (en caso de que falle la inserción en el AB samples)
*/

int StatsObtenerEstadisticasJugador(TDA_Statistics* Statistics, const char* Jugador, TDA_Stats* Stats);
/* Recibe el TDA_Statistics creado y cargado, el jugador cuyas estadísticas se desean, y un parámetro de salida stats,
donde se pondrá el resultado del cálculo de estadísticas. Calcula las estadísticas correspondientes al jugador indicado por parámetro y carga los valores en stats.
El valor de retorno de la primitiva deberá indicar si pudo obtener las estadísticas (en caso de que existan datos del jugador en el tda) o,
en caso de errores, cuál fue el problema. Queda a cargo del grupo definir los errores posibles y sus valores de retorno definidos,
pero se requiere que los errores se indiquen con valores enteros negativos.
*/

int StatsObtenerEstadisticasLiga(TDA_Statistics* Statistics, const char* Liga, TDA_Stats* Stats);
/* Recibe el TDA_Statistics creado y cargado, la liga cuyas estadísticas se desean, y un parámetro de salida stats,
donde se pondrá el resultado del cálculo de estadísticas.
Calcula las estadísticas correspondientes a la liga indicada por parámetro y carga los valores en stats.
El valor de retorno de la primitiva deberá indicar si pudo obtener las estadísticas (en caso de que existan datos de dicha liga en el tda) o,
en caso de errores, cuál fue el problema.
Queda a cargo del grupo definir los errores posibles y sus valores de retorno definidos, pero se requiere que los
errores se indiquen con valores enteros negativos.
*/

int DestruirStats(TDA_Statistics* Statistics);
/* libera los recursos utilizados por el Statistics y deja inutilizable el TDA */
#endif
