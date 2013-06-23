#ifndef __TDA_ABO_H__
    #define __TDA_ABO_H__
    #include <stdlib.h>
    #define IZQ 1
    #define DER 2
    #define PAD 3
    #define RAIZ 4

typedef struct TNodoABO{
    void* Elem;
    struct TNodoABO *Izq;
    struct TNodoABO *Der;
} TNodoABO;

typedef struct TAB{
    TNodoABO *Raiz;
    TNodoABO *Cte;
    int TamDato;
    int (*FComparar)(void *, void *);
    void (*FClonar)(void *, void *);
    void (*FDestruir)(void *);
}TABO;

void ABO_Crear(TABO *Arbol, int tDato, int (*Comparar)(void *, void *), void (*Clonar)(void *, void *), void (*Destruir)(void *));

void ABO_Elemento_Cte(TABO Arbol, void *Elem);

TNodoABO* BuscarPadre(TNodoABO *Padre, TNodoABO *Hijo);

void VaciarSub(TNodoABO *PNodoABO);

void ABO_Vaciar(TABO *Arbol);

void ABO_Modificar_Cte(TABO *Arbol, void *Elem);

void ABO_Insertar(TABO *Arbol, void *Elem, int *Error);

int ABO_Vacio(TABO Arbol);

void ABO_Mover_Cte(TABO *Arbol, int Movimiento, int *Error);

#endif // __TDA_ABO_H__
