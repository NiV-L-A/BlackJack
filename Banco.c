#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>

#include "main.h"

char ControllaVittoria() {
    LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
    LogicaAssi(ManoGiocatore, MAXcarteBanco);
    unsigned short TotGiocatore = CalcolaPunti(ManoGiocatore, MAXcarteGiocatore);
    unsigned short TotBanco = CalcolaPunti(ManoBanco, MAXcarteBanco);

    UtenteLoggato->partiteGiocate++;//Incrementa il contatore partitegiocate dato che la funzione va chiamata a prescindere ogni volta alla fine di una partita

    //Controllo condizioni di vittoria + gestione della puntata
    if (TotGiocatore > 21 && TotBanco <= 21) {//Se il giocatore sballa ma il banco no, SCONFITTA
        return 'S';
    }
    if (TotBanco > TotGiocatore && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del banco e` piu` grande di quella del giocatore e nessuno ha sballato SCONFITTA
        return 'S';
    }
    if (ManoGiocatore[0] < 5 || (ManoGiocatore[0] / 10) >= 10 && ManoGiocatore[1] < 5 || (ManoGiocatore[1] / 10) >= 10 && ManoGiocatore[0] != ManoGiocatore[1]) {//Se il giocatore ha blackjack VITTORIA
        UtenteLoggato->bilancio += Puntata * 2.5;
        return 'B';
    }
    if (TotBanco > 21 && TotGiocatore <= 21) {//Se il banco sballa ma il giocatore no, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        return 'V';
    }
    if (TotGiocatore > TotBanco && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del giocatore e` piu` grande di quella del banco e nessuno sballa, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        return 'V';
    }
    if (TotBanco > 21 && TotGiocatore > 21) {//Se entrambi sballano, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        return 'P';
    }
    if (TotGiocatore == TotBanco) {//Se la mano di entrambi ha lo stesso valore, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        return 'P';
    }

    return '-';//qui solo per zittire il compilatore
}

void RandInit() {//seed della funzione rand
    srand(time(NULL));
}

int CalcolaPunti(unsigned short Mano[], unsigned short Dimensione) {

    unsigned short TotalePunti = 0;
    unsigned short IndiceVuoto = 0;
    unsigned short ValoreCartaAttuale = 0;

    for (short i = 0; i < Dimensione; i++){
        if (Mano[i] == SlotVuoto){
            IndiceVuoto = i;
            break;
        }
    }

    for (short i = IndiceVuoto; i != 0; i--){
            ValoreCartaAttuale = Mano[i] RimuoviSeme;
        if (ValoreCartaAttuale > 10 && ValoreCartaAttuale < 14) {
            TotalePunti += 10;
        }else if (ValoreCartaAttuale == 14) {
            TotalePunti += 11;
        }
        TotalePunti += ValoreCartaAttuale;
    }
    return TotalePunti;
}

void LogicaAssi(unsigned short Mano[], unsigned short Dimensione) {
    unsigned short TotalePunti = CalcolaPunti(Mano, Dimensione);

    for (short i = 0; i < Dimensione; i++){
        if (Mano[i] RimuoviSeme == 1 && TotalePunti <= 10){
            Mano[i] += 130;
            break;
        }
        if (Mano[i] RimuoviSeme == 14 && TotalePunti > 10) {
            Mano[i] -= 130;
            break;
        }
    }
}

int PescaBanco(short CarteDaPescare) {
    short CartePescate = 0;//Ogni volta che pesca una carta con successo incrementa CartePescate fino a quando non equivale al numero richiesto

    while (CartePescate < CarteDaPescare) {
        int IndiceSlotLibero = -1;//Scorre la mano fino a trovare uno slot libero, se ci riesce esce dal loop
        for (int i = 0; i < MAXcarteBanco; i++) {
            if (ManoBanco[i] == SlotVuoto) {
                IndiceSlotLibero = i;
                break;
            }
        }

        if (IndiceSlotLibero == -1) {//Se non c'e` uno slot libero, non pescare
            return 0;
        }

        //Loop che prova a pescare una carta all'infinito
        short CartaPescata;
        while (1) {
            unsigned short IndiceMazzo = rand() % DimensioneMazzo;

            if (ControlloRipetizioni[IndiceMazzo] < MAXmazziBanco) {//Controllo ripetizioni
                ControlloRipetizioni[IndiceMazzo]++;
                CartaPescata = Mazzo[IndiceMazzo];
                break;
            }
        }

        LogicaAssi(ManoBanco, MAXcarteBanco);

        if (CalcolaPunti(ManoBanco, MAXcarteBanco) >= 17) {
            return 0;
        }

        //Pesca la carta
        ManoBanco[IndiceSlotLibero] = CartaPescata;
        CartePescate++;
    }
    return 1;
}