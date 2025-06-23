#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
#ifdef DEBUG
    fprintf(stderr, "\n-------------\n");
    fprintf(stderr, "GetUtentiDalFile\n");
#endif
    FILE *file = fopen(NomeFileUtenti, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.
        // Proviamo a creare il file
        FILE *file = fopen(NomeFileUtenti, "a");
        if (!file) {
            // Non abbiamo i permessi
#ifdef DEBUG
            fprintf(stderr, "Errore apertura file %s\n", NomeFileUtenti);
#endif
            return NULL;
        }
    }

    // Il file può essere letto, andiamo quindi a leggere ogni riga
    UtenteT* Utenti = NULL;
    int i = 0;
    char line[LunghezzaMassimaRiga];
    while (fgets(line, sizeof(line), file)) {
        RimuoviNewLine(line);
        UtenteT* Utente = realloc(Utenti, (i + 1) * sizeof(UtenteT));
        if (!Utente) {
            // Allocazione memoria non riuscita
#ifdef DEBUG
            fprintf(stderr, "Allocazione memoria non riuscita\n");
#endif
            free(Utenti);
            fclose(file);
            return NULL;
        }

        Utenti = Utente;
        sscanf(line, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, &Utenti[i].partiteGiocate);
        //snprintf(line, LunghezzaMassimaRiga, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, Utenti[i].partiteGiocate);
        //sscanf(line, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, Utenti[i].partiteGiocate);
        PulisciStringa(Utenti[i].nome);
        PulisciStringa(Utenti[i].password);
#ifdef DEBUG
        fprintf(stderr, "i: %d\n", i);
        fprintf(stderr, "\tid: %d\n", Utenti[i].id);
        fprintf(stderr, "\tnome: %s\n", Utenti[i].nome);
        fprintf(stderr, "\tpassword: %s\n", Utenti[i].password);
        fprintf(stderr, "\tbilancio: %d\n", Utenti[i].bilancio);
        fprintf(stderr, "\tpercentualeVittoria: %.0f\n", Utenti[i].percentualeVittoria);
        fprintf(stderr, "\tpartiteGiocate: %d\n", Utenti[i].partiteGiocate);
        fprintf(stderr, "\n");
#endif DEBUG
        i++;
    }

    fclose(file);
    *NumeroUtenti = i;
#ifdef DEBUG
    fprintf(stderr, "\n-------------\n");
#endif DEBUG
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
#ifdef DEBUG
    fprintf(stderr, "\n-------------\n");
    fprintf(stderr, "RegistraUtente %s\n", utente.nome);
#endif
    FILE* file = fopen(NomeFileUtenti, "a");
    if (!file) {
        return 0;
    }

    ScriviUtente(file, utente);
    fclose(file);
#ifdef DEBUG
    fprintf(stderr, "\n-------------\n");
#endif
    return 1;
}

//Funzione che popola lo struct globale "Utente loggato" con tutti i dettagli dell'utente trovato
int LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta) {
#ifdef DEBUG
    fprintf(stderr, "\n-------------\n");
    fprintf(stderr, "LoggaUtente\n");
#endif
    for (int i = 0; i < Conta; i++){
#ifdef DEBUG
        fprintf(stderr, "id: %d\n", UtentiFile[i].id);
        fprintf(stderr, "nome: %s\n", UtentiFile[i].nome);
        fprintf(stderr, "password: %s\n", UtentiFile[i].password);
        fprintf(stderr, "bilancio: %d\n", UtentiFile[i].bilancio);
        fprintf(stderr, "percentualeVittoria: %.0f\n", UtentiFile[i].percentualeVittoria);
        fprintf(stderr, "partiteGiocate: %d\n", UtentiFile[i].partiteGiocate);
        fprintf(stderr, "\n");
#endif
        if (strcmp(UtentiFile[i].nome, Nome) == 0 && strcmp(UtentiFile[i].password, Password) == 0) {
#ifdef DEBUG
            fprintf(stderr, "TROVATO: %d\n", UtentiFile[i].id);
#endif
            UtenteLoggato = &UtentiFile[i];
            return 1;
        }
    }
#ifdef DEBUG
    fprintf(stderr, "Utente con nome %s non trovato\n",Nome);
#endif
    return 0;
}


