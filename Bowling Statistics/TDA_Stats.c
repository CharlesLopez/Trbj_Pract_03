#include <stdio.h>
#include <string.h>
#include "TDA_Stats.h"

int OutStatsCrear(TDA_Stats * Stats){
    Liga[0]='\0';
    Player[0]='\0';
    Promedio=0;
    Porcentajes[0]=0;
    Porcentajes[1]=0;
    Porcentajes[2]=0;
    Porcentajes[3]=0;
    Creado=0;

return RES_OK;
}


int OutStatsCargar(TDA_Stats * Stats, int Tipo, char nombre[20], int promedio, int strikes, int spares, int canaletas, int otros){
    if (Stats->Creado!=0) {
        return ERROR;
    }else{
        if (Tipo=1) {
            strcpy(Stats->Liga,nombre);
        }else{
            strcpy(Stats->Player,nombre);}
        Stats->Promedio=promedio;
        Stats->Porcentajes[0]=strikes;
        Stats->Porcentajes[1]=spares;
        Stats->Porcentajes[2]=canaletas;
        Stats->Porcentajes[3]=otros;
        return RES_OK;
    }

}


int OutStatsMostrar(TDA_Stats * Stats){


}


int OutStatsDestruir(TDA_Stats * Stats){
    Liga[0]='\0';
    Player[0]='\0';
    Promedio=0;
    Porcentajes[0]=0;
    Porcentajes[1]=0;
    Porcentajes[2]=0;
    Porcentajes[3]=0;
    Creado=1;     /* Queda inutilizable al dejar en valor 1 */

return RES_OK;

}

