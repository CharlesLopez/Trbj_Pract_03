#ifndef __TDA_Stats__
#define __TDA_Stats__



typedef struct{
    union{
        char Liga[20];      /* Sirve tanto para mostrar ligas o players, depende como se inicialize*/
        char Player[20];
    };
    int Promedio;
    int Porcentajes[4];
    int Creado;
}TDA_Stats;


int OutStatsCrear(TDA_Stats * Stats);
/* Recibe un TDA Stats, lo inicializa y lo deja listo para ser utilizado*/

int OutStatsCargar(TDA_Stats * Stats, char nombre[20], int promedio, int strikes, int spares, int canaletas, int otros);
/* Recibe un TDA Stats creado, el nombre del jugador o liga, el promedio del puntaje, y el porcentaje de strikes, spares, canaletas y otros
    Carga todo en el TDA Stats y devuelve RES_OK si todo funciono correctamente*/

int OutStatsMostrar(TDA_Stats * Stats);
/* Recibe un TDA Stats Creado y cargado y muestra su informacion */

int OutStatsDestruir(TDA_Stats * Stats);
/* Recibe un TDA Stats, borra todo en su interior y lo deja inutilizable*/




#endif

