#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//Legge il file e popola un array della classe StoricoPartite in base all'utente loggato e restituisce il Numero di partite
StoricoPartitaT* PopolaStoricoPartiteDalFile() {

    FILE *file = fopen(NomeFileStoricoPartite, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.

        // Proviamo a creare il file
        file = fopen(NomeFileStoricoPartite, "a");
        if (!file) {
            // Non abbiamo i permessi
            fprintf(stderr, "Impossibile aprire file\n");
            return NULL;
        }
    }

    // Il file esiste, andiamo quindi a leggere ogni riga
    StoricoPartitaT* Partite = NULL;
    int i = 0;
    char line[LunghezzaMassimaRiga];
    while (fgets(line, sizeof(line), file)) {
        RimuoviNewLine(line);
        StoricoPartitaT* partita = realloc(Partite, (i + 1) * sizeof(StoricoPartitaT));
        if (!partita) {
            // Allocazione memoria non riuscita
            free(Partite);
            fclose(file);
            return NULL;
        }

        Partite = partita;
        sscanf(line, "%20[^,],%1[^,],%10d", &Partite[i].NomeUtente, &Partite[i].Risultato, &Partite[i].BilancioDiUscita);
        PulisciStringa(Partite[i].NomeUtente);
        if (strcmp(Partite[i].NomeUtente, UtenteLoggato->nome) == 0) {
            i++;
        }
    }

    fclose(file);
    NumeroRighi = i;
    return Partite;
}

void ScriviPartita(FILE* file, char Risultato, int BilancioInUscita) {//Aggiunge una partita al file
    fprintf(file, "%20s,%c,%10d\n", UtenteLoggato->nome,Risultato, BilancioInUscita);
}

int AggiungiPartitaAlFile(char Risultato, int BilancioInUscita) {
    // "a" serve per appendere
    FILE* file = fopen(NomeFileStoricoPartite, "a");
    if (!file) {
        fprintf(stderr, "Errore apertura file\n");
        return 0;
    }

    ScriviPartita(file, Risultato, BilancioInUscita);
    fclose(file);
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