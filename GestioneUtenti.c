#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <locale.h>
#include "main.h"

//Funzione che verifica se una stringa inserita nella registrazione utente sia valida o meno
int ValidaStringa(char* str) {
    //Se il primo carattere e` uno spazio o e` vuoto, la stringa non e` valida
    if (*str == ' ' || *str == '\0') {
        return 0;
    }
    return 1;
}


//Rimuove il newline character dalla fine di una riga
char* RimuoviNewLine(char line[]) {
    size_t Lunghezza = strlen(line);
    if (Lunghezza > 2) {
        if (line[Lunghezza - 1] == '\n') {
            line[Lunghezza - 1] = '\0';
        }//Questo check non e` necessario su linux ma lo abbiamo messo comunque perche` intendiamo portarlo su windows
         //piu` avanti come sideproject
        //if (line[lunghezza - 2] == '\r') {
        //    line[lunghezza - 2] = '\0';
        //}
    }
    return line;
}


//Rimuove gli spazi usati per il formatting piu` leggibile all'interno della riga
char* RimuoviSpazi(char* str) {
    while (*str == ' ') {
        str++;
    }
    return str;
}


//Rimuove gli spazi e sposta la nuova stringa dov'era prima in maniera tale che il puntatore rimanga lo stesso
void PulisciStringa(char* str) {
    char* Tagliata = RimuoviSpazi(str);
    memmove(str, Tagliata, strlen(Tagliata) + 1);
}


//Legge il file e popola un array della classe Utente e restituisce la lunghezza dell'array
UtenteT* GetUtentiDalFile(int* NumeroUtenti) {
    //Necessario per considerare il simbolo "." come separatore decimale invece che ","
    setlocale(LC_ALL,"C");
    //Cerchiamo di aprire il file
    FILE *File = fopen(LocationFileUtenti, "r");
    if (!File) {
        //Il file non esiste oppure non possiamo aprirlo. Proviamo a creare il file
        File = fopen(LocationFileUtenti, "a");
        if (!File) {
            //Non abbiamo i permessi
            fprintf(stderr, "Errore apertura file!");
            return NULL;
        }
    }

    //Il file può essere letto, andiamo quindi a leggere ogni riga
    UtenteT* Utenti = NULL;
    int i = 0;
    char Riga[LunghezzaMassimaRiga];
    while (fgets(Riga, sizeof(Riga), File)) {
        RimuoviNewLine(Riga);
        UtenteT* Utente = realloc(Utenti, (i + 1) * sizeof(UtenteT));
        if (!Utente) {
            //Allocazione memoria non riuscita
            free(Utenti);
            fclose(File);
            return NULL;
        }

        //Assegnamo i dati della riga letta alla struct
        Utenti = Utente;
        sscanf(Riga, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, &Utenti[i].partiteGiocate);
        PulisciStringa(Utenti[i].nome);
        PulisciStringa(Utenti[i].password);
        i++;
    }

    fclose(File);
    *NumeroUtenti = i;
    return Utenti;
}


//Funzione generica per scrivere i dati di un utente al file
void ScriviUtente(FILE* file, UtenteT utente) {//Aggiunge un utente al file
    fprintf(file, "%5d,%20s,%20s,%10d,%3.0f,%10d\n", utente.id, utente.nome, utente.password, utente.bilancio, utente.percentualeVittoria, utente.partiteGiocate);
}


//Funzione per modificare i dati dell'utente loggato nel file
int ModificaUtenteAlFile() {
    FILE* File = fopen(LocationFileUtenti, "r+");
    if (!File) {
        //Non siamo riusciti ad aprire il file
        return -1;
    }

    char Riga[LunghezzaMassimaRiga];
    long Posizione;
    while (Posizione = ftell(File), fgets(Riga, sizeof(Riga), File)) {
        RimuoviNewLine(Riga);
        //Andiamo in riga in riga per posizionare il cursore sulla riga giusta,
        //quindi quella dove il primo campo (l'id) e' uguale a quella dell'utente loggato
        int ID = 0;
        sscanf(Riga, "%5d", &ID);
        if (ID == UtenteLoggato->id) {
            //Abbiamo trovato l'utente giusto, posizioniamo il cursore all'inizio della riga
            fseek(File, Posizione, SEEK_SET);
            ScriviUtente(File, *UtenteLoggato);
            fclose(File);
            return 1;
        }
    }

    //Non siamo riusciti a trovare l'utente loggato.
    fclose(File);
    return 0;
}


//Aggiunge un utente al file registrandolo
int RegistraUtente(UtenteT utente) {
    //Apriamo il file e posizioniamoci alla fine (pronto per aggiungere una nuova riga)
    FILE* File = fopen(LocationFileUtenti, "a");
    if (!File) {//Non siamo riusciti ad aprire il file
        fprintf(stderr, "Errore apertura file\n");
        return 0;
    }
    ScriviUtente(File, utente);
    fclose(File);
    return 1;
}

//Funzione che popola lo struct globale "UtenteLoggato" con tutti i dettagli dell'utente trovato
int LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta) {
    //Cicliamo nell'array UtentiFile e vediamo se l'elemento corrente ha le stesse credenziali di quelle inserite dall'utente a schermo
    for (int i = 0; i < Conta; i++) {
        if (strcmp(UtentiFile[i].nome, Nome) == 0 && strcmp(UtentiFile[i].password, Password) == 0) {
            UtenteLoggato = &UtentiFile[i];
            return 1;
        }
    }
    return 0;
}

//Funzione che prende l'home directory dell'utente attualmente loggato e imposta i filepath dove salvare i file
void InitFileLocation() {
    char* HomeDir = getenv("HOME");
    char PathDaCreare[BufferSnprintf];
    snprintf(PathDaCreare, BufferSnprintf, "%s/Documents/BlackJack", HomeDir);

    mkdir(PathDaCreare, 0755);

    snprintf(LocationFileUtenti, BufferSnprintf, "%s/Documents/BlackJack/Utenti.txt", HomeDir);
    snprintf(LocationfileStoricoPartite, BufferSnprintf, "%s/Documents/BlackJack/Partite.txt", HomeDir);
}

