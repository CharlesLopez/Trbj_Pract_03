#include <stdio.h>
#include <string.h>
#include "TDA_Score.h"


/* Valores de retorno: Falla=0 ; Exito>0 */


int s_crear(TDA_Score *score) {
    strcpy(score->nombre,"Sin_Nombre");
    int i;
    for (i=0;i<10;i++) {
            score->jugada[i][0]=0;
            score->jugada[i][1]=0;
            score->jugada[i][2]=0;
            score->strikes[i]=0;
    }
    score->strikes[10]=0;
    score->stats[0]=0; score->stats[1]=0; score->stats[2]=0; score->stats[3]=0;  /* Inicializo los stats */
    score->creado=1;  /*Asigno el 1 para saber que se creo el tda_score*/
    return 1;
}


int s_agregarTiro(TDA_Score *score,char detalle[3],int posicion) {
    if(score->creado==1){
        int i;
        if(posicion==9){
            for (i=0;i<3;i++){
                switch (detalle[i]){
                    case '0': score->jugada[9][i]=1;  score->stats[2]=score->stats[2]+1; break;
                    case '1': score->jugada[9][i]=1;  score->stats[3]=score->stats[3]+1; break;
                    case '2': score->jugada[9][i]=2;  score->stats[3]=score->stats[3]+1; break;
                    case '3': score->jugada[9][i]=3;  score->stats[3]=score->stats[3]+1; break;
                    case '4': score->jugada[9][i]=4;  score->stats[3]=score->stats[3]+1; break;
                    case '5': score->jugada[9][i]=5;  score->stats[3]=score->stats[3]+1; break;
                    case '6': score->jugada[9][i]=6;  score->stats[3]=score->stats[3]+1; break;
                    case '7': score->jugada[9][i]=7;  score->stats[3]=score->stats[3]+1; break;
                    case '8': score->jugada[9][i]=8;  score->stats[3]=score->stats[3]+1; break;
                    case '9': score->jugada[9][i]=9;  score->stats[3]=score->stats[3]+1; break;
                    case 'x': score->jugada[9][i]=10; score->stats[0]=score->stats[0]+1; break;
                    case '/': score->jugada[9][i]=10-score->jugada[9][i-1]; score->stats[1]=score->stats[1]+1; break;
                }
            }
            if (detalle[0]=='x')score->strikes[9]=1;
            if (detalle[1]=='x')score->strikes[10]=1;
        }
        else{
            for (i=0;i<2;i++){
                if(detalle[0]=='/'){
                    return 0;
                    break;
                }
                switch (detalle[i]){
                    case '0': score->jugada[posicion][i]=1; score->stats[2]=score->stats[2]+1; break;
                    case '1': score->jugada[posicion][i]=1; score->stats[3]=score->stats[3]+1; break;
                    case '2': score->jugada[posicion][i]=2; score->stats[3]=score->stats[3]+1; break;
                    case '3': score->jugada[posicion][i]=3; score->stats[3]=score->stats[3]+1; break;
                    case '4': score->jugada[posicion][i]=4; score->stats[3]=score->stats[3]+1; break;
                    case '5': score->jugada[posicion][i]=5; score->stats[3]=score->stats[3]+1; break;
                    case '6': score->jugada[posicion][i]=6; score->stats[3]=score->stats[3]+1; break;
                    case '7': score->jugada[posicion][i]=7; score->stats[3]=score->stats[3]+1; break;
                    case '8': score->jugada[posicion][i]=8; score->stats[3]=score->stats[3]+1; break;
                    case '9': score->jugada[posicion][i]=9; score->stats[3]=score->stats[3]+1; break;
                    case 'x': score->strikes[posicion]=1;   score->stats[0]=score->stats[0]+1; break;   /* Guardo los tiros que fueron strike con 1 y los spare con 2*/
                    case '/': score->strikes[posicion]=2;   score->stats[1]=score->stats[1]+1; break;
                }
            }
            if ((score->jugada[posicion][0]+score->jugada[posicion][1])>9)
                return (0);
        }
    return 1;
    }
    else return 0;
}


int s_calcularResultado(TDA_Score score){
    if(score.creado==1){
        int j,puntos[10];
        int total;

        for (j=0;j<9;j++){
            if(score.strikes[j]==1){
                score.jugada[j][0]=10+score.jugada[j+1][0]+score.jugada[j+1][1];
                if(score.strikes[j+1]==2){
                   score.jugada[j][0]=20;
                   score.jugada[j][1]=0;
                   if(j==8)score.jugada[j][0]=20;
                }
                if(score.strikes[j+1]==1){
                    if(j==8)score.jugada[8][0]=20+score.jugada[j+1][1];
                        else score.jugada[j][0]=20+score.jugada[j+2][0];
                    if(score.strikes[j+2]==1){
                        score.jugada[j][0]=30;
                    }
                }
            }

            if(score.strikes[j]==2){
                if(score.strikes[j+1]==1)score.jugada[j][0]=20;
                    else {
                        score.jugada[j][1]=0;
                        score.jugada[j][0]=10+score.jugada[j+1][0];
                    }
            }
        }

        for(j=0;j<10;j++){
            if(j==9){
                puntos[j]=0;
                puntos[j]=puntos[j]+score.jugada[j][0];
                puntos[j]=puntos[j]+score.jugada[j][1];
                puntos[j]=puntos[j]+score.jugada[j][2];
            } else {
            puntos[j]=0;
            puntos[j]=puntos[j]+score.jugada[j][0];
            puntos[j]=puntos[j]+score.jugada[j][1];      /*Cargo los puntos por jugada*/
            }
        }

        total=0;
        for (j=0;j<10;j++){
            total=total+puntos[j];
        }
        return total;
    } else return 0;
}


int s_establecerParticipante(TDA_Score *score,char *nombreUsuario) {
    if (score->creado==1){
        strcpy(score->nombre,nombreUsuario);    /*Inserta dentro del tdascore el nombre de usuario que recibio, supuestamente desde el parser*/
        return 1;
    } else return 0;
}


int s_obtenerParticipante(TDA_Score score,char *nombre) {
    if (score.creado==1){
        strcpy(nombre,score.nombre);
        return 1;   /* Devuelve el nombre del jugador, almacenado en el tda_Score*/
    }else return 0;
}


int DestruirS(TDA_Score *score){
    score->creado=0; /*Le asigno 0 y lo dejo inutilizable*/
    return 1;
}

