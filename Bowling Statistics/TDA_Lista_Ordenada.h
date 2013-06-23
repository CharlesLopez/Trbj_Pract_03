#ifndef __Lista_Ordenada__
#define __Lista_Ordenada__
#include "Lista_Simple.h"

typedef struct listaordenada{
    int (*FComparar)(void* E1, void* E2);
    void (*FClonar)(void* E1, void* E2);
    void (*FDestruir)(void* E);
    int tamanio;
    TListaSimple LS;
} TDA_Lista_Ordenada;

int crearListaOrdenada(TDA_Lista_Ordenada* listaOrdenada,int tamaniodato,int (*comparar)(void*, void*), int (*clonar)(void*, void*), int (*destruir)(void *));
    /*Pre-Condicion: Lista no creada
    Post-Condicion: Lista creada*/

int insertarElementoOrdenado(TDA_Lista_Ordenada* listaOrdenada, void* elem);
    /*Pre-Condicion: Lista creada
    Post-Condicion: Elemento Insertado de forma ordenada en la lista
    Aclaracion: La lista esta ordenada de menor a mayor, por ende el primer elemento va a ser el menor de la lista*/

int vaciarListaOrdenada(TDA_Lista_Ordenada* listaOrdenada);
    /* Pre-Condicion: Lista creada.
     Post-Condicion: Lista vacia. */

int moverCorrienteListaOrdenada(TDA_Lista_Ordenada* listaOrdenada, int movimiento);
/*	  Pre-condiciones: Lista creada y no vacia.
	  Post-Condiciones: Si la lista esta vacia, devuelve FALSE. Sino:
            Si movimiento = L_Primero, el nuevo elemento Corriente es el Primero. Devuelve TRUE
            Si movimiento = L_Siguiente, el nuevo elemento Corriente es el Siguiente al Anterior. Si estaba en el ultimo elemento, devuelve FALSE, sino TRUE.
            Si movimiento = L_Anterior, devuelve FALSE.                      */

int obtenerCorrienteListaOrdenada(TDA_Lista_Ordenada listaOrdenada,void* elem);
	 /*Pre-condiciones: Lista creada y no vacia.
	 Post-condicion: Se devuelve en elem el elemento Corriente de la lista.*/

int destruirListaOrdenada(TDA_Lista_Ordenada* listaOrdenada);
    /*Pre-Condicion:Lista Creada
     Post-Condicion:Lista destruida, recursos liberados */

#endif // __Lista_Ordenada__
