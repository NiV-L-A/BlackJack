#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//Legge il file e popola un array della classe StoricoPartite in base all'utente loggato e restituisce il Numero di partite
StoricoPartitaT* PopolaStoricoPartiteDalFile() {
    //Cerchiamo di aprire il file
    FILE *File = fopen(LocationfileStoricoPartite, "r");
    if (!File) {
        //Il file non esiste oppure non possiamo aprirlo. Proviamo a creare il file
        File = fopen(LocationfileStoricoPartite, "a");
        if (!File) {
            //Non abbiamo i permessi
            fprintf(stderr, "Errore apertura file!");
            return NULL;
        }
    }

    //Creazione del puntatore di tipo StoricoPartitaT
    StoricoPartitaT* Partite = NULL;
    int CapacitaCorrente = 0;
    int ContaRighi = 0;
    char Riga[LunghezzaMassimaRiga];

    while (fgets(Riga, sizeof(Riga), File)) {//Scansione di tutte le righe del file
        RimuoviNewLine(Riga);

        StoricoPartitaT tempPartita;
        sscanf(Riga, "%20[^,],%1[^,],%10d", tempPartita.NomeUtente, &tempPartita.Risultato, &tempPartita.BilancioDiUscita);
        PulisciStringa(tempPartita.NomeUtente);

        //Controllo per estrarre solo le partite dell'utente loggato e riallocazione della memoria
        if (strcmp(tempPartita.NomeUtente, UtenteLoggato->nome) == 0) {
            if (ContaRighi >= CapacitaCorrente) {
                CapacitaCorrente = (CapacitaCorrente == 0) ? 5 : CapacitaCorrente * 2;
                StoricoPartitaT* ptrTemp = realloc(Partite, CapacitaCorrente * sizeof(StoricoPartitaT));
                if (!ptrTemp) {
                    free(Partite);
                    fclose(File);
                    fprintf(stderr, "Errore di riallocazione memoria!\n");
                    return NULL;
                }
                Partite = ptrTemp;
            }
            Partite[ContaRighi] = tempPartita;
            ContaRighi++;
        }
    }

    fclose(File);

    //Controllo per ridurre la dimensione di memoria allocata aggiustandola solo alla quantita` di partite giocate
    //dall'utente loggato
    if (ContaRighi > 0) {
        StoricoPartitaT* ptrFinale = realloc(Partite, ContaRighi * sizeof(StoricoPartitaT));
        if (ptrFinale) {
            Partite = ptrFinale;
        }

    } else {
        free(Partite);
        Partite = NULL;
    }

    NumeroRighi = ContaRighi;
    return Partite;
}


//Funzione generica per aggiungere una partita al file
void ScriviPartita(FILE* file, char Risultato, int BilancioInUscita) {
    fprintf(file, "%20s,%c,%10d\n", UtenteLoggato->nome,Risultato, BilancioInUscita);
}


//Funzione che si posiziona al byte giusto e chiamata ScriviPartita
int AggiungiPartitaAlFile(char Risultato, int BilancioInUscita) {
    //Apriamo il file e posizioniamoci alla fine (pronto per aggiungere una nuova riga)
    FILE* File = fopen(LocationfileStoricoPartite, "a");
    if (!File) {//Non siamo riusciti ad aprire il file
        fprintf(stderr, "Errore apertura file\n");
        return 0;
    }
    ScriviPartita(File, Risultato, BilancioInUscita);
    fclose(File);
    return 1;
}


//Funzione generale per resettare i valori delle variabili globali alla fine di una partita
void ResettaValoriGlobali() {
    //Variabili
    Puntata = 0;
    NumeroRighi = 0;
    //Array
    memset(ManoGiocatore, 0, sizeof(ManoGiocatore));
    memset(ManoBanco, 0, sizeof(ManoBanco));
    memset(ControlloRipetizioni, 0, sizeof(ControlloRipetizioni));
}