#include "ab.h"
#include <memory.h>

void AB_Crear(TAB *a,int tdato){
    a->tamdato = tdato;
    a->raiz = NULL;
    a->cte = NULL;
}


void AB_ElemCte(TAB a,void *elem){
    memcpy(elem, Arbol.cte->elem, Arbol.tamdato);
}


TNodoAB* BuscarPadre(TNodoAB *padre,TNodoAB *hijo){
    TNodoAB *paux = NULL;
    if ((padre->izq == hijo) || (padre->der == hijo))
        return padre;
    else{
        if (padre->izq != NULL)
            paux = BuscarPadre(padre->izq,hijo);
        if ((padre->der != NULL) && (paux == NULL))
            paux = BuscarPadre(padre->der,hijo);
        return paux;
    }
}


void VaciarSub(TNodoAB *pnodo){
    if (pnodo != NULL){
        if ((pnodo->izq == NULL) && (pnodo->der == NULL)){
            free(pnodo->elem);
            free(pnodo);
        }
        else{
            VaciarSub(pnodo->izq);
            VaciarSub(pnodo->der);
            free(pnodo->elem);
            free(pnodo);
        }
    }
}


void AB_Vaciar(TAB *Arbol){
    VaciarSub(a->raiz);
    Arbol->raiz = NULL;
    Arbol->cte = NULL;
}


void AB_ModifCte(TAB *Arbol,void *elem){
memcpy(Arbol->cte->elem, elem, Arbol->tamdato);
}


void AB_Insertar(TAB *Arbol,int Movimiento,void *elem,int *error){
    TNodoAB *paux;
    *error = 0;
    paux = (TNodoAB*) malloc(sizeof(TNodoAB));
    paux->izq = NULL;
    paux->der = NULL;
    if (paux){
        paux->elem = malloc(Arbol->tamdato);
        if (paux->elem){
            memcpy(paux->elem,elem, Arbol->tamdato);
            switch(Movimiento){
                case IZQ :  if (Arbol->cte->izq == NULL)
                                Arbol->cte->izq = paux;
                            else
                                *error = 1;
                            break;
                case DER :  if (Arbol->cte->der == NULL)
                                Arbol->cte->der = paux;
                            else
                                *error = 1;
                            break;
                case RAIZ : if (Arbol->raiz == NULL)
                                Arbol->raiz = paux;
                            else
                                *error = 1;
                            break;
                default :   *error = 1;
            } /* switch.*/
            if (*error){
                free(paux->elem);
                free(paux);
            }
            else
                Arbol->cte = paux;
        }
        Else{ /* if(paux->elem). */
            *error = 1;
            free(paux);
        }
    }
    else /* if(paux).*/
    *error = 1;
}


int AB_Vacio(TAB Arbol){
    if (Arbol.raiz == NULL)
        return 1;
    else
        return 0;
}


void AB_MoverCte(TAB *Arbol,int Movimiento,int *error){
    *error = 0;
    switch (Movimiento){
        case IZQ :  if (Arbol->cte->izq != NULL)
                        Arbol->cte = Arbol->cte->izq;
                    else
                        *error = 1;
                    break;
        case DER :  if (Arbol->cte->der != NULL)
                        Arbol->cte = Arbol->cte->der;
                    else
                        *error = 1;
                    break;
        case PAD :  if (Arbol->cte != Arbol->raiz)
                        Arbol->cte=BuscarPadre(Arbol->raiz,Arbol->cte);
                    else
                        *error = 1;
                    break;
        case RAIZ : if (Arbol->raiz != NULL)
                        Arbol->cte = Arbol->raiz;
                    else
                        *error = 1;
                    break;
        default :   *error = 1;
    }
}
