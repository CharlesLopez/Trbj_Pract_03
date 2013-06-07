# ifndef __TDA_Parser_h__
# define __TDA_Parser_h__
# define MAXCAR 20
# define MINCAR 3

typedef struct{
    char Campo00[MAXCAR];
    char Campo01[MINCAR];
    char Campo02[MINCAR];
    char Campo03[MINCAR];
    char Campo04[MINCAR];
    char Campo05[MINCAR];
    char Campo06[MINCAR];
    char Campo07[MINCAR];
    char Campo08[MINCAR];
    char Campo09[MINCAR];
    char Campo10[MINCAR+1];
    int NumLinea;
    FILE *Archivo;
    char Separador;
} TDA_Parser;

/* Primitivas para TDA_Parser: */

int parserCrear(TDA_Parser *Tda_Parser, char *Archivo, char Separador);

/* PRECONDICIONES: ParserCrear recibe un TDA_PArser declarado, una ruta de archivo y un caracter separador.
   POSTCONDICIONES: Devuelve 1 si el archivo fue abierto y si el Parser fue Inicalizado correctamente. */


int obtenerSiguienteLinea(TDA_Parser *Tda_Parser);

/*PRECONDICIONES: ObtenerSiguienteLinea recibe un parser Inicializado Correctamnete.
  POSTCONDICIONES: Devuelve 1 si la linea del archivo pudo ser cargado correctamente al Parser. */


int obtenerCampo(TDA_Parser Tda_Parser, int N, char *Valor);

/* PRECONDICIONES: ObtenerCampo Recibe un numero N entre 0 y 10 inclusive.
 0 para el campo del Nombre y del 1 al 10 para los campos de las jugadas.
 POSTCONDICIONES: Devuelve 1 si se puedo realizar sin error. */


int DestruirP(TDA_Parser *Tda_Parser);

/* PRECONDICIONES: Destruir Recibe un Parcer que fue Inicializado y Usado correctamente.
 POSTCONDICION: Retorna 1 despues de cerrar el Archivo y liberado la memoria que usaba.*/

# endif
