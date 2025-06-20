#include <string.h>
#include "main.h"


char* RimuoviNewLine(char line[]) {//Rimuove il newline character dalla fine di una riga
    size_t lunghezza = strlen(line);
    if (line[lunghezza - 1] == '\n') {
        line[lunghezza - 1] = '\0';
    }
    return line;
}


char* RimuoviSpazi(char* str) {//Rimuove gli spazi all'inizio della riga
    while (*str == ' ') {
        str++;
    }
    return str;
}


void PulisciStringa(char* str) {//Rimuove gli spazi e sposta la nuova stringa dov'era prima in maniera tale che il puntatore rimanga lo stesso
    char* Tagliata = RimuoviSpazi(str);
    memmove(str, Tagliata, strlen(Tagliata) + 1);
}


UtenteT* GetUtentiDalFile(int* NumeroUtenti) {//Legge il file e popola un array della classe Utente e restituisce la lunghezza dell'array
    FILE *file = fopen(NomeFileUtenti, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.

        // Proviamo a creare il file
        FILE *file = fopen(NomeFileUtenti, "a");
        if (!file) {
            // Non abbiamo i permessi
            fprintf(stderr, "Errore apertura file\n");
            return NULL;
        }
    }

    // Il file può essere letto, andiamo quindi a leggere ogni riga
    UtenteT* Utenti = NULL;
    int i = 0;
    char line[LunghezzaMassimaRiga];
    while (fgets(line, sizeof(line), file)) {
        //RimuoviNewLine(line);
        UtenteT* Utente = realloc(Utenti, (i + 1) * sizeof(UtenteT));
        if (!Utente) {
            // Allocazione memoria non riuscita
            free(Utenti);
            fclose(file);
            return NULL;
        }

        Utenti = Utente;
        sscanf(line, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, &Utenti[i].partiteGiocate);
        PulisciStringa(Utenti[i].nome);
        PulisciStringa(Utenti[i].password);
        i++;
    }

    fclose(file);
    *NumeroUtenti = i;
    return Utenti;
}


void ScriviUtente(FILE* file, UtenteT utente) {//Aggiunge un utente al file
    fprintf(file, "%5d,%20s,%20s,%10d,%3.0f,%10d\n", utente.id, utente.nome, utente.password, utente.bilancio, utente.percentualeVittoria, utente.partiteGiocate);
}


int ModificaUtenteAlFile(UtenteT utente) {//Modifica i dati di un utente nel file
    FILE* file = fopen(NomeFileUtenti, "r+");
    if (!file) {
        return -1;
    }

    char Riga[LunghezzaMassimaRiga];
    long Posizione;
    while (Posizione = ftell(file), fgets(Riga, sizeof(Riga), file)) {
        RimuoviNewLine(Riga);
        int ID = 0;
        sscanf(Riga, "%5d", &ID);
        if (ID == utente.id) {
            fseek(file, Posizione, SEEK_SET);
            ScriviUtente(file, utente);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


int RegistraUtente(UtenteT utente){//Appende un utente alla fine del file
    FILE* file = fopen(NomeFileUtenti, "a");
    if (!file) {
        return 0;
    }

    ScriviUtente(file, utente);
    fclose(file);
    return 1;
}

void LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta) {//Funzione che popola lo struct globale "Utente loggato" con tutti i dettagli dell'utente trovato
    for (int i = 0; i < Conta; i++){
        if (strcmp(UtentiFile[i].nome, Nome) == 0 && strcmp(UtentiFile[i].password, Password) == 0) {
            UtenteLoggato = UtentiFile[i];
            break;
        }
    }
    fprintf(stderr, "Utente con nome %s non trovato\n",Nome);
}


