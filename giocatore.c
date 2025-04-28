#include <stdio.h>
#include "main.h"

//FUNZIONI DEBUG

void printMano(int mano[]){//funzione per printare la mano per debuggare
    for (int i = 0; i < MAXcarte; i++) {
        if (mano[i] != 0) {
            printf("%d\n", mano[i]);
        }
    }
}


