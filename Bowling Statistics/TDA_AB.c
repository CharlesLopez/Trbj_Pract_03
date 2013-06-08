#include "TDA_AB.h"

void AB_Crear(TAB *Arbol, int TamDatoElem){
    Arbol->TamDato = TamDatoElem;
    Arbol->Raiz = NULL;
    Arbol->Cte = NULL;
}

void AB_ElemCte(TAB Arbol, void *Elem){
    memcpy(Elem, Arbol.Cte->Elem, Arbol.TamDato);
}

TNodoAB* BuscarPadre(TNodoAB *Padre, TNodoAB *Hijo){
    TNodoAB *PAux = NULL;
    if ((Padre->Izq == Hijo) || (Padre->Der == Hijo))
        return Padre;
    else{
        if (Padre->Izq != NULL)
            PAux = BuscarPadre(Padre->Izq, Hijo);
        if ((Padre->Der != NULL) && (PAux == NULL))
            PAux = BuscarPadre(Padre->Der, Hijo);
        return PAux;
    }
}

void VaciarSub(TNodoAB *PNodo){
    if (PNodo != NULL){
        if ((PNodo->Izq == NULL) && (PNodo->Der == NULL)){
            free(PNodo->Elem);
            free(PNodo);
        }
        else{
            VaciarSub(PNodo->Izq);
            VaciarSub(PNodo->Der);
            free(PNodo->Elem);
            free(PNodo);
        }
    }
}

void AB_Vaciar(TAB *Arbol){
    VaciarSub(Arbol->Raiz);
    Arbol->Raiz = NULL;
    Arbol->Cte = NULL;
}

void AB_ModifCte(TAB *Arbol, void *Elem){
    memcpy(Arbol->Cte->Elem, Elem, Arbol->TamDato);
}

void AB_Insertar(TAB *Arbol, int Movimiento, void *Elem, int *Error){
    TNodoAB *PAux;
    *Error = 0;
    PAux = (TNodoAB*) malloc(sizeof(TNodoAB));
    PAux->Izq = NULL;
    paux->Der = NULL;
    if (PAux){
        PAux->Elem = malloc(Arbol->TamDato);
        if (PAux->Elem){
            memcpy(PAux->Elem, Elem, Arbol->TamDato);
            switch(Movimiento){
                case IZQ :  if (Arbol->Cte->Izq == NULL)
                                Arbol->Cte->Izq = PAux;
                            else
                                *Error = 1;
                            break;
                case DER :  if (Arbol->Cte->Der == NULL)
                                Arbol->Cte->Der = PAux;
                            else
                                *Error = 1;
                            break;
                case RAIZ : if (Arbol->Raiz == NULL)
                                Arbol->Raiz = PAux;
                            else
                                *Error = 1;
                            break;
                default :   *Error = 1;
            } /* switch.*/
            if (*Error){
                free(PAux->Elem);
                free(PAux);
            }
            else
                Arbol->Cte = PAux;
        }/* if(PAux->Elem). */
        else{
            *Error = 1;
            free(PAux);
        }
    }/* if(PAux).*/
    else
        *Error = 1;
}

int AB_Vacio(TAB Arbol){
    if (Arbol.Raiz == NULL)
        return 1;
    else
        return 0;
}

void AB_MoverCte(TAB *Arbol, int Movimiento, int *Error){
    *Error = 0;
    switch (Movimiento){
        case IZQ :  if (Arbol->Cte->Izq != NULL)
                        Arbol->Cte = Arbol->Cte->Izq;
                    else
                        *Error = 1;
                    break;
        case DER :  if (Arbol->Cte->Der != NULL)
                        Arbol->Cte = Arbol->Cte->Der;
                    else
                        *Error = 1;
                    break;
        case PAD :  if (Arbol->Cte != Arbol->Raiz)
                        Arbol->Cte = BuscarPadre(Arbol->Raiz, Arbol->Cte);
                    else
                        *Error = 1;
                    break;
        case RAIZ : if (Arbol->Raiz != NULL)
                        Arbol->Cte = Arbol->Raiz;
                    else
                        *Error = 1;
                    break;
        default :   *Error = 1;
    }
}
