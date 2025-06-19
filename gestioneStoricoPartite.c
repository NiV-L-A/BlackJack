#include <string.h>
#define STRINGA_LUNGHEZZA_MASSIMA 21 // 20 + \0
#define LINEA_LUNGHEZZA_MASSIMA 256
#define NOMEFILE_STORICOPARTITE "file/storicoPartite"

typedef struct {
    char nomeUtente[STRINGA_LUNGHEZZA_MASSIMA];
    char risultato[1]; // S = Sconfitta, P = Pareggio, V = Vittoria, B = Vittoria con Blackjack
    int bilancioAllUscita;
} StoricoPartita_t;

StoricoPartita_t* GetStoricoPartiteDalFile(int* outCount, char nomeUtente[]) {
    FILE *file = fopen(NOMEFILE_STORICOPARTITE, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.

        // Proviamo a creare il file
        FILE *file = fopen(NOMEFILE_STORICOPARTITE, "a");
        if (!file) {
            // Non abbiamo i permessi
            return NULL;
        }
    }

    // Il file esiste, andiamo quindi a leggere ogni riga
    StoricoPartita_t* Partite = NULL;
    int i = 0;
    char line[LINEA_LUNGHEZZA_MASSIMA];
    while (fgets(line, sizeof(line), file)) {
        RimuoviNewLine(line);
        StoricoPartita_t* partita = realloc(Partite, (i + 1) * sizeof(StoricoPartita_t));
        if (!partita) {
            // Allocazione memoria non riuscita
            free(Partite);
            fclose(file);
            return NULL;
        }

        Partite = partita;
        sscanf(line, "%20[^,],%1[^,],%10d", &Partite[i].nomeUtente, Partite[i].risultato, &Partite[i].bilancioAllUscita);
        test(Partite[i].nomeUtente);
        if (strcmp(Partite[i].nomeUtente, nomeUtente) == 0) {
            i++;
        }
    }

    fclose(file);
    *outCount = i;
    return Partite;
}

int ScriviPartita(FILE* file, StoricoPartita_t partita) {
    fprintf(file, "%20s,%1s,%10d\n", partita.nomeUtente, partita.risultato, partita.bilancioAllUscita);
}

int AggiungiPartitaAlFile(StoricoPartita_t partita) {
    // "a" serve per appendere
    FILE* file = fopen(NOMEFILE_STORICOPARTITE, "a");
    if (!file) {
        return 0;
    }

    ScriviPartita(file, partita);
    fclose(file);
    return 1;
}