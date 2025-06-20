#include <string.h>
#include "main.h"

//Legge il file e popola un array della classe StoricoPartite in base all'utente loggato e restituisce il Numero di partite
StoricoPartitaT* GetStoricoPartiteDalFile(char NomeUtente[]) {

    FILE *file = fopen(NomeFileStoricoPartite, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.

        // Proviamo a creare il file
        FILE *file = fopen(NomeFileStoricoPartite, "a");
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
        sscanf(line, "%20[^,],%1[^,],%10d", &Partite[i].NomeUtente, Partite[i].Risultato, &Partite[i].BilancioDiUscita);
        PulisciStringa(Partite[i].NomeUtente);
        if (strcmp(Partite[i].NomeUtente, NomeUtente) == 0) {
            i++;
        }
    }

    fclose(file);
    NumeroPartite = i;
    return Partite;
}

void ScriviPartita(FILE* file, StoricoPartitaT partita) {//Aggiunge una partita al file
    fprintf(file, "%20s,%1s,%10d\n", partita.NomeUtente, partita.Risultato, partita.BilancioDiUscita);
}

int AggiungiPartitaAlFile(StoricoPartitaT partita) {
    // "a" serve per appendere
    FILE* file = fopen(NomeFileStoricoPartite, "a");
    if (!file) {
        fprintf(stderr, "Errore apertura file\n");
        return 0;
    }

    ScriviPartita(file, partita);
    fclose(file);
    return 1;
}