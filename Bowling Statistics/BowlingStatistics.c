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
}NodoJugador;

int Comparar (void* Elemento1, void* Elemento2){
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

int Clonar (void* Elemento1, void* Elemento2){
    return 0;
}

int FDestruir(void* Elemento){
    return 0;
}

void Mostrar3PrimerosMundiales(TDA_Lista_Ordenada* ListaOrdenada){
    int K;
    NodoJugador Jugador;
    moverCorrienteListaOrdenada(ListaOrdenada, L_Primero);
    printf("Los 3 Primeros de Mundo son:\n");
    for(K= 1; K<= 3; K++){
        obtenerCorrienteListaOrdenada(*ListaOrdenada, &Jugador);
        printf("\n\t%s; %s; %d\n\n", Jugador.Pais, Jugador.Nombre, Jugador.Puntaje);
        if (!moverCorrienteListaOrdenada(ListaOrdenada, L_Siguiente))
            K=4;
    }
}

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
  	int Comparar (void* Elemento1, void* Elemento2);
  	int Clonar (void* Elemento1, void* Elemento2);
  	int FDestruir (void* Elemento);
  	NodoJugador JugadorLiga;
	TDA_Lista_Ordenada ListaLiga, ListaMejoresMundiales;
    L = 1;
  	crearListaOrdenada(&ListaMejoresMundiales, sizeof(JugadorLiga), Comparar, Clonar, FDestruir);
    while(L < argc){  /* INICIA EL PROCESAMIENTO DE CADA ARCHIVO IN.*/
        crearListaOrdenada(&ListaLiga, sizeof(JugadorLiga), Comparar, Clonar, FDestruir);
        CargarListaOrdenada(&ListaLiga, argv[L]);
        moverCorrienteListaOrdenada(&ListaLiga, L_Primero);
        obtenerCorrienteListaOrdenada(ListaLiga, &JugadorLiga);/*OBTIENE EL PRIMER NODO DE LA LISTA LIGA*/
        insertarElementoOrdenado(&ListaMejoresMundiales, &JugadorLiga);/* CARGA PRIMER NODO A LISTAMEJORESMUNDIALES POR ARCHIVO IN.*/
        CargarArchivoOUT(&ListaLiga, argv[L]);/* PROCESO DE CARGA DE ARCHIVO OUT POR ARCHIVO IN.*/
        L++;
    }
    Mostrar3PrimerosMundiales(&ListaMejoresMundiales);/* MUESTRAR POR PANTALLA LOS 3 PRIMEROS PUESTOS MUNDIALES.*/
    destruirListaOrdenada(&ListaMejoresMundiales);/* DE LIBERACION DE MEMORIA.*/
    system("Pause");
    return 0;
}
