#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "main.h"

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
//Funzione che gestisce la pesca per il giocatore
int PescaGiocatore(unsigned short CarteDaPescare) {//Prende come argument il numero di carte da pescare
    unsigned short CartePescate = 0;//Ogni volta che pesca una carta con successo incrementa CartePescate fino a quando non equivale al numero richiesto

    while (CartePescate < CarteDaPescare) {
        short IndiceSlotLibero = -1;//Scorre la mano fino a trovare uno slot libero, se ci riesce esce dal loop
        for (short i = 0; i < MAXcarteGiocatore; i++) {
            if (ManoGiocatore[i] == SlotVuoto) {
                IndiceSlotLibero = i;
                break;
            }
        }

        if (IndiceSlotLibero == -1) {//Altrimenti la mano e` piena, quindi ritorno un errore
            return 0;
        }

        //Sezione che prova a pescare una carta all'infinito
        unsigned short CartaPescata;
        while (1) {
            unsigned short IndiceMazzo = rand() % DimensioneMazzo;

            if (ControlloRipetizioni[IndiceMazzo] < NumeroMazziGiocatore) {//Controllo ripetizioni nonche' impostazione della difficolta`
                ControlloRipetizioni[IndiceMazzo]++;
                CartaPescata = Mazzo[IndiceMazzo];
                break;
            }
        }

        if (CartaPescata RimuoviSeme == 1 && CalcolaPunti(ManoGiocatore, MAXcarteGiocatore) + 11 < 21) {
            CartaPescata += 130;
        }

        //Pesca la carta
        ManoGiocatore[IndiceSlotLibero] = CartaPescata;
        CartePescate++;
    }
    return 1;
}
void Raddoppia() {//funzione per la giocata "raddoppio"
    if (UtenteLoggato->bilancio - (Puntata * 2) >= 0){
        PescaGiocatore(1);
    }
    gtk_label_set_text(GTK_LABEL(LblNotificaBilancio), "Non hai abbastanza crediti!");
}



