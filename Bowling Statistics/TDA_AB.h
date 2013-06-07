#include "ab.h"
#include <memory.h>

void AB_Crear(TAB *a,int tdato);

void AB_ElemCte(TAB a,void *elem);

TNodoAB* BuscarPadre(TNodoAB *padre,TNodoAB *hijo);

void VaciarSub(TNodoAB *pnodo);

void AB_Vaciar(TAB *Arbol);

void AB_ModifCte(TAB *Arbol,void *elem);

void AB_Insertar(TAB *Arbol,int Movimiento,void *elem,int *error);

int AB_Vacio(TAB Arbol);

void AB_MoverCte(TAB *Arbol,int Movimiento,int *error);
