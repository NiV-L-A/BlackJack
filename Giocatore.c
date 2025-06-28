#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "main.h"

//Calcola il tasso di vittoria dell'utente
void CalcolaTassoVittoria() {
    //Come prima cosa creiamo un'array di tipo StoricoPartitaT e lo popoliamo con tutte le partite svolte dall'utente attuale
    StoricoPartitaT* ArrPartite = PopolaStoricoPartiteDalFile();
    //Poi creo due funzioni temporanee per contare il numero di vittorie e quello di sconfitte
    float Vittorie = 0;
    float Sconfitte = 0;

    //In seguito scorro per l'array di partite del giocatore ed uso uno switch per verificare i casi Risultato
    for (int i = 0; i < NumeroRighi; i++) {
        switch (ArrPartite[i].Risultato) {
        case 'V'://Se vittoria standard o con BlackJack incrementa vittorie
        case 'B':
            Vittorie++;
            break;
        case 'S'://Se sconfitta incrementa sconfitte (i pareggi sono esclusi completamente)
            Sconfitte++;
            break;
        default://Qui solo per zittire il compilatore
            break;
        }
    }
    //Poi verifico se almeno uno dei due e` diverso da zero per evitare di ricevere NaN come risultato dal calcolo
    if (Vittorie != 0 || Sconfitte != 0) {
    UtenteLoggato->percentualeVittoria = (Vittorie / (Vittorie + Sconfitte)) * 100;
    }
    //In fine libero la memoria occupata da ArrPartite e libero il suo puntatore
    free(ArrPartite);
    ArrPartite = NULL;
}


//Funzione che gestisce la pesca per il giocatore
int PescaGiocatore(unsigned short CarteDaPescare) {//Prende come argument il numero di carte da pescare
    unsigned short CartePescate = 0;
    short IndiceSlotLibero = -1;
    //Ogni volta che pesca una carta con successo incrementa CartePescate fino a quando non equivale al numero richiesto
    while (CartePescate < CarteDaPescare) {
        //Scorre la mano fino a trovare uno slot libero, se ci riesce esce dal loop
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
        unsigned short CartaPescata = 0;
        while (1) {
            unsigned short IndiceMazzo = rand() % DimensioneMazzo;

            if (ControlloRipetizioni[IndiceMazzo] < NumeroMazziGiocatore) {//Controllo ripetizioni nonche' impostazione della difficolta`
                ControlloRipetizioni[IndiceMazzo]++;
                CartaPescata = Mazzo[IndiceMazzo];
                break;
            }
        }
        //Se e` riuscito a pescare una carta, chiamo la logica assi per avere il contatore valore carte consistente
        //quando si gioca in difficolta` facile
        LogicaAssi(ManoGiocatore, MAXcarteGiocatore);

        //Pesca la carta
        ManoGiocatore[IndiceSlotLibero] = CartaPescata;
        CartePescate++;
    }
    return 1;
}


//Funzione che implementa il raddoppio
int Raddoppia() {
    //Controllo se raddoppiando la puntata attuale l'utente abbia comunque abbastanza crediti
    if (UtenteLoggato->bilancio - (Puntata * 2) >= 0) {
        PescaGiocatore(1);//Se si pesco una carta e raddoppio la puntata
        UtenteLoggato->bilancio -= Puntata;
        Puntata *= 2;
        return 1;
    }
    return 0;
}



