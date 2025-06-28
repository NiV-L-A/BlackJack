#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>

#include "main.h"

//Funzione che si occupa di validare lo stato finale della partita
char ControllaVittoria() {
    //Come prima cosa applico LogicaAssi a entrambe le mani per assicurarsi che il valore disponibile della mano sia
    //quello piu` ottimale
    LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
    LogicaAssi(ManoBanco, MAXcarteBanco);
    //In seguito popolo due variabili per tenere conto del totale dei punti di entrambi
    unsigned short TotGiocatore = CalcolaPunti(ManoGiocatore, MAXcarteGiocatore);
    unsigned short TotBanco = CalcolaPunti(ManoBanco, MAXcarteBanco);

    //Una volta fatto incremento la statistica PartiteGiocate dell'utente loggato in quanto questa funzione venga
    //chiamata una singola volta alla fine di ogni partita
    UtenteLoggato->partiteGiocate++;

    //Poi inizializzo due variabili; una con il valore del bilancio PRIMA di aver scommesso
    //ed una per tenere traccia del risultato finale
    int BilancioPrima = UtenteLoggato->bilancio + Puntata;
    char Risultato = '\0';

    //Poi con questi if else nestati controllo le condizioni di stato della partita

    //Se il giocatore sballa ma il banco no, SCONFITTA
    if (TotGiocatore > 21 && TotBanco <= 21) {
        Risultato = 'S';

    //Se la mano del banco e` piu` grande di quella del giocatore e nessuno ha sballato, SCONFITTA
    }else if (TotBanco > TotGiocatore && TotBanco <= 21) {
        Risultato = 'S';

    //Se il banco ha Blackjack, SCONFITTA (il controllo nel caso lo abbiano entrambi avviene piu` avanti)
    }else if ((ManoBanco[0] > 140 || ManoBanco[0] > 100 && ManoBanco[0] < 140) && (ManoBanco[1] > 140 || ManoBanco[1] > 100 && ManoBanco[1] < 140 ) && ManoBanco[0] RimuoviSeme != ManoBanco[1] RimuoviSeme) {
        Risultato = 'S';

    //Se il giocatore ha blackjack, VITTORIA
    }else if ((ManoGiocatore[0] > 140 || ManoGiocatore[0] > 100 && ManoGiocatore[0] < 140) && (ManoGiocatore[1] > 140 || ManoGiocatore[1] > 100 && ManoGiocatore[1] < 140 ) && ManoGiocatore[0] RimuoviSeme != ManoGiocatore[1] RimuoviSeme) {
        UtenteLoggato->bilancio += Puntata * 2.5;
        Risultato = 'B';

    //Se il banco sballa ma il giocatore no, VITTORIA
    }else if (TotBanco > 21 && TotGiocatore <= 21) {
        UtenteLoggato->bilancio += Puntata * 2;
        Risultato = 'V';

    //Se la mano del giocatore e` piu` grande di quella del banco e nessuno sballa, VITTORIA
    }else if (TotGiocatore > TotBanco && TotGiocatore <= 21 && TotBanco <= 21) {
        UtenteLoggato->bilancio += Puntata * 2;
        Risultato = 'V';

    //Se entrambi sballano, PAREGGIO
    }else if (TotBanco > 21 && TotGiocatore > 21) {
        UtenteLoggato->bilancio += Puntata;
        Risultato = 'P';

    //Se la mano di entrambi ha lo stesso valore, PAREGGIO (controlla anche il caso in cui entrambi abbiano un BlackJack)
    }else if (TotGiocatore == TotBanco) {
        UtenteLoggato->bilancio += Puntata;
        Risultato = 'P';
    }

    //Valutato il risultato della partita viene fatta la somma algebrica per stabilire quanti crediti il giocatore abbia
    //guadagnato o perso
    BilancioPrima = UtenteLoggato->bilancio - BilancioPrima;

    //Poi si salva la partita sul file e si aggiornano le statistiche dell'utente loggato salvandolo sul file
    AggiungiPartitaAlFile(Risultato, BilancioPrima);
    ModificaUtenteAlFile();

    //In fine ritorno il risultato della partita
    return Risultato;
}


//Funzione per seeddare la funzione rand
void InitRand() {
    srand(time(NULL));
}



//Funzione generica per calcolare il valore totale di una mano
int CalcolaPunti(unsigned short Mano[], unsigned short Dimensione) {
    //Comincio col creare due funzioni locali per tenere conto del totale dei punti
    unsigned short TotalePunti = 0;
    unsigned short ValoreCartaAttuale = 0;

    //Poi itero il calcolo dei punti per ogni elemento della mano passata
    for (short i = 0; i < Dimensione; i++) {
        if (Mano[i] == 0) {//Appena trova un'elemento vuoto, esce dal loop
            break;
        }
        //Altrimenti inizializza la variabile "ValorecCartaAttuale" con il valore effettivo della carta
        ValoreCartaAttuale = Mano[i] RimuoviSeme;
        //Per poi controllare che tipo di carta sia ed assegnare i punti relativi
        if (ValoreCartaAttuale > 10 && ValoreCartaAttuale < 14) {//Figure (J, Q, K)
            TotalePunti += 10;
        }else if (ValoreCartaAttuale == 14) {//Asso speciale dal valore di 11
            TotalePunti += 11;
        }else{
            TotalePunti += ValoreCartaAttuale;//Carte nominali ed assi normali
        }
    }
    //In fine ritorna il totale dei punti
    return TotalePunti;
}


//Funzione generica che si occupa della logica dietro ad assegnare il valore degli assi
void LogicaAssi(unsigned short Mano[], unsigned short Dimensione) {
    //Comincio col creare una variabile totale contente il valore della mano attuale
    unsigned short TotalePunti = CalcolaPunti(Mano, Dimensione);

    //In seguito itero la logica per ogni elemento della mano
    for (unsigned short i = 0; i < Dimensione; i++) {
        if (Mano[i] == 0) {//Appena trovo un elemento vuoto esco dal loop
            break;
        }
        //Se il valore della carta attuale una volta rimosso il seme e` di 1 essa e` un asso, pertanto controllo se
        //il totale attuale dei punti sia minore o uguale a 11
        if (Mano[i] RimuoviSeme == 1 && TotalePunti <= 11) {
            //Se si, aggiungo 130 al valore di quella carta facendola diventare un asso speciale
            Mano[i] += 130;
            //Aggiungendo 130 ad una carta dal valore da 11 a 14 essa passa ad essere nella 140ina, quindi, quando viene
            //rimosso il seme rimarra` un valore di 14, permettendo di distinguere facilmente gli assi speciali da quelli
            //normali
            break;
        }
        //Se invece il valore della carta attuale una volta tolto il seme e` di 14, essa e` un'asso speciale dal valore
        //di 11, pertanto controllo se il totale dei punti sia diverso da 21 e se aggiungendo 11 a quel totale si vada
        //a sballare
        if (Mano[i] RimuoviSeme == 14 && TotalePunti != 21 && TotalePunti + 11 > 21) {
            //Se si, rimuovo 130 dal valore di quella carta riportandola ad essere un asso normale
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
        //Poi chiamo la logica assi per assicurarmi che non peschi quando non deva
        LogicaAssi(ManoBanco, MAXcarteBanco);

        //In fine controllo se il totale dei punti e` maggiore di 16
        if (CalcolaPunti(ManoBanco, MAXcarteBanco) > 16) {
            return 0;//Se si non puo` pescare
        }

        //Altrimenti pesca la carta
        ManoBanco[IndiceSlotLibero] = CartaPescata;
        CartePescate++;
    }
    return 1;
}

void BancoPescaRipetuta() {
    //Ho bisogno di fare questa cosa orrenda perche` utilizzare qualsiasi loop con una condizzione di uscita
    //andrebbe a bloccare il thread dell'interfaccia, briccando l'intero programma!
    if (PescaBanco(1)){
        AggiornaManoBanco();
    }
    if (PescaBanco(1)){
        AggiornaManoBanco();
    }
    if (PescaBanco(1)){
        AggiornaManoBanco();
    }
    if (PescaBanco(1)){
        AggiornaManoBanco();
    }

}