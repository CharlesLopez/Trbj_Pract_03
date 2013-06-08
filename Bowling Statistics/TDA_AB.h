#ifndef __AB_H__
    #define __AB_H__
    #include <stdlib.h>
    #ifndef (IZQ)
        #define IZQ 1
    #endif

    #ifndef (DER)
        #define DER 2
    #endif

    #ifndef (PAD)
        #define PAD 3
    #endif

    #ifndef (RAIZ)
        #define RAIZ 4
    #endif

typedef struct TNodoAB{
    void* Elem;
    struct TNodoAB *Izq, *Der;
} TNodoAB;

typedef struct TAB{
    TNodoAB *Raiz,*Cte;
    int TamDato;
} TAB;

void AB_Crear(TAB *Arbol, int TamDatoElem);

void AB_ElemCte(TAB Arbol, void *Elem);

TNodoAB* BuscarPadre(TNodoAB *Padre, TNodoAB *Hijo);

void VaciarSub(TNodoAB *PNodo);

void AB_Vaciar(TAB *Arbol);

void AB_ModifCte(TAB *Arbol, void *Elem);

void AB_Insertar(TAB *Arbol, int Movimiento, void *Elem, int *Error);

int AB_Vacio(TAB Arbol);

void AB_MoverCte(TAB *Arbol, int Movimiento, int *Error);

#endif
