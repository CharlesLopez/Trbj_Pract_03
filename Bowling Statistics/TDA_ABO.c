#include "TDA_ABO.h"

void ABO_Crear(TABO *Arbol, int tDato, int (*Comparar)(void *, void *), void (*Clonar)(void *, void *), void (*Destruir)(void *)){
    Arbol->TamDato = tDato;
    Arbol->Raiz = NULL;
    Arbol->Cte = NULL;
    Arbol->FComparar = Comparar;
    Arbol->FClonar = Clonar;
    Arbol->FDestruir = Destruir;
}

void ABO_Elemento_Cte(TABO Arbol, void *Elem){
    Arbol.FClonar(Elem, Arbol.Cte->Elem);
}

void VaciarSub(TNodoABO *PNodoABO){
    if (PNodoABO != NULL){
        if ((PNodoABO->Izq == NULL) && (PNodoABO->Der == NULL)){
            free(PNodoABO->Elem);
            free(PNodoABO);
        }
        else{
            VaciarSub(PNodoABO->Izq);
            VaciarSub(PNodoABO->Der);
            free(PNodoABO->Elem);
            free(PNodoABO);
        }
    }
}

void ABO_Vaciar(TABO *Arbol){
    VaciarSub(Arbol->Raiz);
    Arbol->Raiz = NULL;
    Arbol->Cte = NULL;
}

void ABO_Modificar_Cte(TABO *Arbol, void *Elem){
    Arbol->FClonar(Arbol->Cte->Elem, Elem);
}

int Buscar_Lugar(TABO *Arbol, TNodoABO **PNodoABO, void *Elem){
    int C;
    if (*PNodoABO != NULL){
        C = (*(Arbol->FComp))((*PNodoABO)->Elem, Elem);
        if (C == 1)
            Buscar_Lugar(Arbol, &((*PNodoABO)->Izq), Elem);
        else if (C == -1)
            Buscar_Lugar(Arbol, &((*PNodoABO)->Der), Elem);
        else
            return 1;
    }
    else{
        *PNodoABO = (TNodoABO*) malloc(sizeof(TNodoABO));
        (*PNodoABO)->Izq = NULL;
        (*PNodoABO)->Der = NULL;
        if(*PNodoABO){
            (*PNodoABO)->Elem = malloc(Arbol->TamDato);
            if((*PNodoABO)->Elem){
                Arbol->FClonar((*PNodoABO)->Elem, Elem);
                return 0;
            }
            free(*PNodoABO);
            return 1;
        }
        return 1;
    }
    return 1;
}

void ABO_Insertar(TABO *Arbol, void *Elem, int *Error){
    *Error = Buscar_Lugar(Arbol, &(Arbol->Raiz), Elem);
}

int ABO_Vacio(TABO Arbol){
    if (Arbol.Raiz == NULL)
        return 1;
    else
        return 0;
}

TNodoABO* BuscarPadre(TNodoABO *Padre, TNodoABO *Hijo){
    TNodoABO *PAux = NULL;
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

void ABO_Mover_Cte(TABO *Arbol, int Movimiento, int *Error){
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
