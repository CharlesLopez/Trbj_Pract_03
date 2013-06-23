#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_Parser.h"
#include "TDA_Score.h"
#include "TDA_Lista_Ordenada.h"
#include "TDA_Statistics.h"
#include "TDA_Resultado_Jugador.h"
#include "TDA_Stats.h"
# define MAXDIR 255
# define MAXCAR 20
# define MINCAR 3

typedef struct {
    char Pais[MAXCAR];
    char Nombre[MAXCAR];
    int Puntaje;
}NodoProcesar;

void CargarListaOrdenada(TDA_Lista_Ordenada* Lista, char* argv){
    char CampoLargo[MAXCAR], CampoCorto[MINCAR], Separador;
	char* ArchivoIN;
	int Prox, J;
    NodoJugador JugadorLiga;
  	TDA_Parser Parser;
	TDA_Score Score;
    Prox = 0;
  	Separador = '|';
    ArchivoIN = argv;
    if (parserCrear(&Parser, ArchivoIN, Separador)){
        if (!obtenerSiguienteLinea(&Parser))
            obtenerCampo(Parser, 0, JugadorLiga.Pais);/* CARGA PAIS AL NODO DE LA LISTA POR ARCHIVO.*/
        Prox = obtenerSiguienteLinea(&Parser);
        while(!Prox){
            if (s_crear(&Score)){
                obtenerCampo(Parser, 0, CampoLargo);
                strcpy(JugadorLiga.Nombre, CampoLargo);/* CARGA NOMBRE AL NODO DE LA LISTA POR LINEA.*/
                for(J= 0; J < 10; ++J){
                    obtenerCampo(Parser, (J+1), CampoCorto);
                    s_agregarTiro(&Score, CampoCorto, J);
                }
                JugadorLiga.Puntaje = s_calcularResultado(Score);/* CARGA PUNTAJE AL NODO DE LA LISTA POR LINEA.*/
            }
            if (strlen(JugadorLiga.Nombre))
                insertarElementoOrdenado(Lista,&JugadorLiga);/* CARGA NODO A LA LISTALIGA POR CADA LINEA.*/
            Prox = obtenerSiguienteLinea(&Parser);/* VA POR LA OTRA LINEA DEL ARCHIVO*/
        }
    }
    if (Prox == 1){ /* FINALIZADA LAS LINEAS DEL ARCHIVO*/
        DestruirS(&Score);
        DestruirP(&Parser);
    }
}

void CargarArchivoOUT(TDA_Lista_Ordenada* Lista1, char* argv){
    int W = strlen(argv) - 4;
    char ArchivoOUT[MAXDIR];
    NodoJugador Jugador;
	FILE *ArchOUT;
	argv[W] = '\0'; /* TRUNCA EL NOMBRE DEL ARCHIVO SIN LA EXTENCION .TXT.*/
    strcpy(ArchivoOUT, argv);
    strcat(ArchivoOUT,"_Resultados.txt");
    ArchOUT = fopen (ArchivoOUT,"w+");
    moverCorrienteListaOrdenada(Lista1, L_Primero);
    obtenerCorrienteListaOrdenada(*Lista1, &Jugador);
    fprintf(ArchOUT, "%s\n",Jugador.Pais);
    fprintf(ArchOUT, "%s;%d\n", Jugador.Nombre, Jugador.Puntaje);
    while(moverCorrienteListaOrdenada(Lista1, L_Siguiente)){
        obtenerCorrienteListaOrdenada(*Lista1, &Jugador);
        fprintf(ArchOUT, "%s;%d\n", Jugador.Nombre, Jugador.Puntaje);
    }
    fclose(ArchOUT); /* FIN DEL PROCESAMIENTO DE CADA ARCHIVO IN - OUT.*/
    destruirListaOrdenada(Lista1); /* DE LIBERACION DE MEMORIA.*/
}


/* LOS ARCHIVOS DEBERAN SER INGRESADOS POR CONSOLA LISTADOS UNO A UNO*/
int main(int argc, char *argv[]){
  	int L;
  	NodoProcesar JugadorLiga;
	TDA_Lista_Ordenada ListaJugadores;
    L = 1;
    while(L < argc){  /* INICIA EL PROCESAMIENTO DE CADA ARCHIVO IN.*/
        /*OBTIENE EL PRIMER NODO DE LA LISTA LIGA*/
        /* PROCESO DE CARGA DE ARCHIVO OUT POR ARCHIVO IN.*/
        L++;
    }
    /* DE LIBERACION DE MEMORIA.*/
    system("Pause");
    return 0;
}
