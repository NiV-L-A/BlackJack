#include <stdio.h>
#include "main.h"

//===================DEFINIZIONI VARIABILI GLOBALI===========================
int Puntata = 0;
int NumeroRighi = 0;
short NumeroMazziGiocatore = 6;
UtenteT* UtenteLoggato;

//===================DEFINIZIONE ARRAY========================================
const unsigned short Mazzo[DimensioneMazzo] = {
    // Asso, 2, 3, ... 10, J, Q, K
    11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131,
    12, 22, 32, 42, 52, 62, 72, 82, 92, 102, 112, 122, 132,
    13, 23, 33, 43, 53, 63, 73, 83, 93, 103, 113, 123, 133,
    14, 24, 34, 44, 54, 64, 74, 84, 94, 104, 114, 124, 134
};
unsigned short ControlloRipetizioni[DimensioneMazzo];
unsigned short ManoGiocatore[MAXcarteGiocatore];
unsigned short ManoBanco[MAXcarteBanco];

char LocationfileStoricoPartite[BufferSnprintf];
char LocationFileUtenti[BufferSnprintf];