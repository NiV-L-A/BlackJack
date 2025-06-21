#include <stdio.h>
#include <string.h>
#include "main.h"

void Dividi(int ManoGiocatore[]) {
    ManoGiocatore[1] = 0;
    ManoGiocatoreDivisa[0] = ManoGiocatore[0];

    PuntataDivisa = Puntata;

    Pesca(ManoGiocatore);
    Pesca(ManoGiocatoreDivisa);
}

//Calcola il tasso di vittoria dell'utente
void AggiornamentoStatistiche(StoricoPartitaT* ArrPartite) {
    float Vittorie = 0;
    float Sconfitte = 0;

    for (int i = 0; i < NumeroRighi; i++) {
        switch (ArrPartite[i].Risultato) {
        case 'V':
        case 'B':
            Vittorie++;
            break;
        case 'S':
            Sconfitte++;
            break;
        default://qui solo per zittire il compilatore
            break;
        }
    }
    UtenteLoggato->percentualeVittoria = (Vittorie / (Vittorie + Sconfitte)) * 100;
}























//FUNZIONI DEBUG

void printMano(int mano[]){//funzione per printare la mano per debuggare
    for (int i = 0; i < MAXcarte; i++) {
        if (mano[i] != 0) {
            printf("%d\n", mano[i]);
        }
    }
}


