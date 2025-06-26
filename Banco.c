#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>

#include "main.h"

char ControllaVittoria() {
    LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
    LogicaAssi(ManoBanco, MAXcarteBanco);
    unsigned short TotGiocatore = CalcolaPunti(ManoGiocatore, MAXcarteGiocatore);
    unsigned short TotBanco = CalcolaPunti(ManoBanco, MAXcarteBanco);

    UtenteLoggato->partiteGiocate++;//Incrementa il contatore partitegiocate dato che la funzione va chiamata a prescindere ogni volta alla fine di una partita
    int BilancioPrima = UtenteLoggato->bilancio + Puntata;
    char Risultato = '\0';

    //Controllo condizioni di vittoria + gestione della puntata
    if (TotGiocatore > 21 && TotBanco <= 21) {//Se il giocatore sballa ma il banco no, SCONFITTA
        //UtenteLoggato->bilancio -= Puntata;
        Risultato = 'S';
    }else if (TotBanco > TotGiocatore && TotBanco <= 21) {//Se la mano del banco e` piu` grande di quella del giocatore e nessuno ha sballato SCONFITTA
        //UtenteLoggato->bilancio -= Puntata;
        Risultato = 'S';
    }else if ((ManoBanco[0] > 140 || ManoBanco[0] > 100 && ManoBanco[0] < 140) && (ManoBanco[1] > 140 || ManoBanco[1] > 100 && ManoBanco[1] < 140 ) && ManoBanco[0] RimuoviSeme != ManoBanco[1] RimuoviSeme) {//Se il giocatore ha blackjack VITTORIA
        //UtenteLoggato->bilancio -= Puntata;
        Risultato = 'S';
    }else if ((ManoGiocatore[0] > 140 || ManoGiocatore[0] > 100 && ManoGiocatore[0] < 140) && (ManoGiocatore[1] > 140 || ManoGiocatore[1] > 100 && ManoGiocatore[1] < 140 ) && ManoGiocatore[0] RimuoviSeme != ManoGiocatore[1] RimuoviSeme) {//Se il giocatore ha blackjack VITTORIA
        UtenteLoggato->bilancio += Puntata * 2.5;
        Risultato = 'B';
    }else if (TotBanco > 21 && TotGiocatore <= 21) {//Se il banco sballa ma il giocatore no, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        Risultato = 'V';
    }else if (TotGiocatore > TotBanco && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del giocatore e` piu` grande di quella del banco e nessuno sballa, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        Risultato = 'V';
    }else if (TotBanco > 21 && TotGiocatore > 21) {//Se entrambi sballano, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        Risultato = 'P';
    }else if (TotGiocatore == TotBanco) {//Se la mano di entrambi ha lo stesso valore, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        Risultato = 'P';
    }

    BilancioPrima = UtenteLoggato->bilancio - BilancioPrima;

    AggiungiPartitaAlFile(Risultato, BilancioPrima);

    ModificaUtenteAlFile();

    return Risultato;//qui solo per zittire il compilatore
}

void RandInit() {//seed della funzione rand
    srand(time(NULL));
}

int CalcolaPunti(unsigned short Mano[], unsigned short Dimensione) {

    unsigned short TotalePunti = 0;
    unsigned short ValoreCartaAttuale = 0;

    for (short i = 0; i < Dimensione; i++){
        if (Mano[i] == 0){
            break;
        }
        ValoreCartaAttuale = Mano[i] RimuoviSeme;
        if (ValoreCartaAttuale > 10 && ValoreCartaAttuale < 14) {//Figure (J, Q, K)
            TotalePunti += 10;
        }else if (ValoreCartaAttuale == 14) {
            TotalePunti += 11;
        }else{
            TotalePunti += ValoreCartaAttuale;
        }

    }
    return TotalePunti;
}

void LogicaAssi(unsigned short Mano[], unsigned short Dimensione) {
    unsigned short TotalePunti = CalcolaPunti(Mano, Dimensione);

    for (unsigned short i = 0; i < Dimensione; i++){
        if (Mano[i] == 0){
            break;
        }
        if (Mano[i] RimuoviSeme == 1 && TotalePunti <= 11){
            Mano[i] += 130;
            break;
        }
        if (Mano[i] RimuoviSeme == 14 && TotalePunti + 11 > 21) {
            Mano[i] -= 130;
            break;
        }
    }
}

int PescaBanco(short CarteDaPescare) {
    short CartePescate = 0;//Ogni volta che pesca una carta con successo incrementa CartePescate fino a quando non equivale al numero richiesto
    short IndiceSlotLibero = -1;
    while (CartePescate < CarteDaPescare) {
        //Scorre la mano fino a trovare uno slot libero, se ci riesce esce dal loop
        for (short i = 0; i < MAXcarteBanco; i++) {
            if (ManoBanco[i] == SlotVuoto) {
                IndiceSlotLibero = i;
                break;
            }
        }

        if (IndiceSlotLibero == -1) {//Se non c'e` uno slot libero, non pescare
            return 0;
        }

        //Loop che prova a pescare una carta all'infinito
        short CartaPescata = 0;
        while (1) {
            unsigned short IndiceMazzo = rand() % DimensioneMazzo;

            if (ControlloRipetizioni[IndiceMazzo] < MAXmazziBanco) {//Controllo ripetizioni
                ControlloRipetizioni[IndiceMazzo]++;
                CartaPescata = Mazzo[IndiceMazzo];
                break;
            }
        }

        LogicaAssi(ManoBanco, MAXcarteBanco);

        if (CalcolaPunti(ManoBanco, MAXcarteBanco) > 16) {
            return 0;
        }

        //Pesca la carta
        ManoBanco[IndiceSlotLibero] = CartaPescata;
        CartePescate++;
    }
    return 1;
}