#include <stdio.h>
#include <stdlib.h>
#include "TDA_Lista_Ordenada.h"

/* Lo = Lista Ordenada*/

int crearListaOrdenada(TDA_Lista_Ordenada* listaOrdenada, int tamaniodato, int (*Comparar)(void*, void*), int (*Clonar)(void*, void*), int (*Destruir)(void *)){
    listaOrdenada->FComparar = Comparar;
    listaOrdenada->FClonar = Clonar;
    listaOrdenada->FDestruir = Destruir;
    listaOrdenada->tamanio=tamaniodato;
    L_Crear(&listaOrdenada->LS,tamaniodato);
	return 1;
}

int insertarElementoOrdenado(TDA_Lista_Ordenada* listaOrdenada, void* elem){
    void* aux = malloc(listaOrdenada->tamanio); /*Defino una variable auxiliar, donde guardo el nodo que saco para comparar*/
    if (L_Vacia(listaOrdenada->LS)){
        free(aux);
        return(L_Insertar_Cte(&listaOrdenada->LS, L_Primero, elem)); /*Si la lista esta vacia, inserto el elemento como el primero*/
    }
    L_Mover_Cte(&listaOrdenada->LS, L_Primero);
    L_Elem_Cte(listaOrdenada->LS, aux);
    if (listaOrdenada->FComparar(elem,aux)==1){ /*Si aux es menor, entonces inserta el elemento antes*/
        free(aux);
        return(L_Insertar_Cte(&listaOrdenada->LS, L_Anterior, elem));
    }
    if (listaOrdenada->FComparar(elem,aux)==0){ /*Si aux es igual a elem lo inserta antes.*/
        free(aux);
        return(L_Insertar_Cte(&listaOrdenada->LS, L_Anterior, elem));
    }

    while(L_Mover_Cte(&listaOrdenada->LS, L_Siguiente)){  /*Recorra la lista hasta encontrar un elemnto menor (en aux), e inserta elem antes del mismo.*/
        L_Elem_Cte(listaOrdenada->LS, aux);
        if (listaOrdenada->FComparar(elem,aux)==1){
            free(aux);
            return(L_Insertar_Cte(&listaOrdenada->LS, L_Anterior, elem));
        }
        if (listaOrdenada->FComparar(elem,aux)==0){   /*Si esta repetido, lo inserta antes.*/
            free(aux);
            return(L_Insertar_Cte(&listaOrdenada->LS, L_Anterior, elem));
        }
    }

    L_Insertar_Cte(&listaOrdenada->LS, L_Siguiente, elem); /*Si llego al final y ningun elemento fue menor, lo inserta luego del ultimo*/
    free(aux);
    return 1;
}

int vaciarListaOrdenada(TDA_Lista_Ordenada* listaOrdenada){
    L_Vaciar(&listaOrdenada->LS);
    return 1;
}

int moverCorrienteListaOrdenada(TDA_Lista_Ordenada* listaOrdenada, int movimiento){
	return(L_Mover_Cte(&listaOrdenada->LS, movimiento));
}

int obtenerCorrienteListaOrdenada(TDA_Lista_Ordenada listaOrdenada,void* elem){
	L_Elem_Cte(listaOrdenada.LS, elem);
	return 1;
}

int destruirListaOrdenada(TDA_Lista_Ordenada* listaOrdenada){
    L_Vaciar(&listaOrdenada->LS);
    return 1;
}
