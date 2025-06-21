#include <stdio.h>
#include <stddef.h>
#include "main.h"

//===================DEFINIZIONI VARIABILI GLOBALI===========================
int Puntata = 0;
int NumeroRighi = 0;
int ManoGiocatoreDivisa[MAXcarte] = {0};
int PuntataDivisa = 0;
UtenteT* UtenteLoggato;

//===================DEFINIZIONE ARRAY========================================
const unsigned short mazzo[52] = {
    // Asso, 2, 3, ... 10, J, Q, K
    1, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131,
    2, 22, 32, 42, 52, 62, 72, 82, 92, 102, 112, 122, 132,
    3, 23, 33, 43, 53, 63, 73, 83, 93, 103, 113, 123, 133,
    4, 24, 34, 44, 54, 64, 74, 84, 94, 104, 114, 124, 134
};