#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "TDA_Parser.h"


int parserCrear (TDA_Parser *Tda_Parser, char *Archivo, char Separador){
    FILE *P_Archivo;
    int AUX;

    P_Archivo = fopen(Archivo,"r");
    if (P_Archivo){
        rewind(P_Archivo);
        AUX = getc(P_Archivo);
        if (AUX != EOF){
            Tda_Parser->NumLinea = 0;
            Tda_Parser->Archivo = P_Archivo;
            Tda_Parser->Separador = Separador;
            rewind(P_Archivo);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}


/* Esta Funcion sera llamada por por la funcion ObtenersiguienteLinea */

int LeerCampo (char *Cadena, FILE *Arch, char Separador, int *FLinea){
    int J, AUX;

    AUX = getc(Arch);
    for(J = 0;(AUX != Separador) && (AUX != '\0') && (AUX != '\n') && (AUX != EOF); J++){
        Cadena[J] = (int)AUX;
        AUX = getc(Arch);
    }
    if (AUX == Separador)
        Cadena[J] = '\0';
    if ((AUX == '\n') || (AUX == '\0')){
        Cadena[J] = '\0';
        *FLinea = 1;
        return 0;
    }
    if (AUX == EOF)
        return 1;

    return 0;
}


int obtenerSiguienteLinea (TDA_Parser *Tda_Parser){
    char Cadena[MAXCAR];
    int FinLinea, Campo, LC;
    FinLinea = 0;
    Campo = 0;
    while (!FinLinea){
        LC = LeerCampo(Cadena, Tda_Parser->Archivo, Tda_Parser->Separador, &FinLinea);
        if (!LC){ /* SE PUDO LEER CAMPO Y SE CARGA AL PARSER */
            switch (Campo){
                case 0: Cadena[0] = toupper(Cadena[0]); strcpy(Tda_Parser->Campo00, Cadena); break;
                case 1: strcpy(Tda_Parser->Campo01, Cadena); break;
                case 2: strcpy(Tda_Parser->Campo02, Cadena); break;
                case 3: strcpy(Tda_Parser->Campo03, Cadena); break;
                case 4: strcpy(Tda_Parser->Campo04, Cadena); break;
                case 5: strcpy(Tda_Parser->Campo05, Cadena); break;
                case 6: strcpy(Tda_Parser->Campo06, Cadena); break;
                case 7: strcpy(Tda_Parser->Campo07, Cadena); break;
                case 8: strcpy(Tda_Parser->Campo08, Cadena); break;
                case 9: strcpy(Tda_Parser->Campo09, Cadena); break;
                case 10: strcpy(Tda_Parser->Campo10, Cadena); break;
            }
            Campo++;
        }
        if (LC == 1)
            break;
    }
    Tda_Parser->NumLinea += 1;
    if (FinLinea) return 0;
    return 1;
}


int obtenerCampo (TDA_Parser Tda_Parser, int N, char *Valor){
    if (0 <= N && N <= 10 && Tda_Parser.NumLinea){
        switch (N){
        case 0: strcpy(Valor, Tda_Parser.Campo00); break;
        case 1: strcpy(Valor, Tda_Parser.Campo01); break;
        case 2: strcpy(Valor, Tda_Parser.Campo02); break;
        case 3: strcpy(Valor, Tda_Parser.Campo03); break;
        case 4: strcpy(Valor, Tda_Parser.Campo04); break;
        case 5: strcpy(Valor, Tda_Parser.Campo05); break;
        case 6: strcpy(Valor, Tda_Parser.Campo06); break;
        case 7: strcpy(Valor, Tda_Parser.Campo07); break;
        case 8: strcpy(Valor, Tda_Parser.Campo08); break;
        case 9: strcpy(Valor, Tda_Parser.Campo09); break;
        case 10:strcpy(Valor, Tda_Parser.Campo10); break;
        }
        return 1;
    }
    else
        return 0;
}


int DestruirP (TDA_Parser *Tda_Parser){
    fclose(Tda_Parser->Archivo);
    return 0;
}
