#include <stdio.h>
#include "main.h"

void Dividi(int Mano[]) {
    Mano[1] = 0;
    ManoGiocatoreDivisa[0] = Mano[0];

    PuntataDivisa = Puntata;

    Pesca(Mano);
    Pesca(ManoGiocatoreDivisa);
}

























//FUNZIONI DEBUG

void printMano(int mano[]){//funzione per printare la mano per debuggare
    for (int i = 0; i < MAXcarte; i++) {
        if (mano[i] != 0) {
            printf("%d\n", mano[i]);
        }
    }
}


