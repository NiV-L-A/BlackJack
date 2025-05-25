#include <stdio.h>
#include "main.h"

void dividi(int mano[],int puntata)
{
    mano[1] = 0;
    manoGiocatoreDivisa[0] = mano[0];

    puntataDivisa = puntata;

    pesca(mano);
    pesca(manoGiocatoreDivisa);

}

























//FUNZIONI DEBUG

void printMano(int mano[]){//funzione per printare la mano per debuggare
    for (int i = 0; i < MAXcarte; i++) {
        if (mano[i] != 0) {
            printf("%d\n", mano[i]);
        }
    }
}


