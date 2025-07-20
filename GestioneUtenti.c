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
    
    //Cerchiamo di aprire il file in lettura
    FILE *File = fopen(LocationFileUtenti, "r");
    if (!File) {
        //Il file non esiste oppure non possiamo aprirlo. 
        //Proviamo a creare il file vuoto e poi chiuderlo
        File = fopen(LocationFileUtenti, "a");
        if (!File) {
            //Non abbiamo i permessi
            fprintf(stderr, "Errore apertura file!");
            *NumeroUtenti = 0;
            return NULL;
        }
        //Chiudiamo il file appena creato
        fclose(File);
        
        //Il file ora esiste ma è vuoto, quindi restituiamo array vuoto
        *NumeroUtenti = 0;
        return NULL; // Oppure return malloc(0); se preferisci un puntatore valido
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
            *NumeroUtenti = 0;
            return NULL;
        }

        //Assegnamo i dati della riga letta alla struct
        Utenti = Utente;
        int result = sscanf(Riga, "%5d,%20[^,],%20[^,],%10d,%f,%10d", 
                           &Utenti[i].id, Utenti[i].nome, Utenti[i].password, 
                           &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, 
                           &Utenti[i].partiteGiocate);
        
        //Verifica che sscanf abbia letto tutti i campi correttamente
        if (result != 6) {
            //Riga malformata, skippiamo
            continue;
        }
        
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

//Rimuove l'ultimo utente loggato eliminando i contenuti del file UltimoLogin.txt
void RimuoviUltimoLogin() {
    unlink(LocationFileUltimoLogin);
}

//Libera la memoria occupata da UtenteLoggato
void FreeUtenteLoggato() {
    if (UtenteLoggato) {
        free(UtenteLoggato);
        UtenteLoggato = NULL;
    }
}

//Funzione che popola lo struct globale "UtenteLoggato" con tutti i dettagli dell'utente trovato
int SalvaUltimoLogin(UtenteT* Utente) {
    FILE* file = fopen(LocationFileUltimoLogin, "w");
    if (!file) {
        return 0;
    }

    fprintf(file, "%d\n%s\n", Utente->id, Utente->nome);
    fclose(file);
    return 1;
}

//Logga l'utente e salva il suo login in ultimo login
int LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta) {
    //Libera memoria eventualmente rimasta occupata in precedenza
    FreeUtenteLoggato();

    for (int i = 0; i < Conta; i++) {
        if (strcmp(UtentiFile[i].nome, Nome) == 0 && strcmp(UtentiFile[i].password, Password) == 0) {

            //Allocazione memoria per avere una copia persistente dei dati dell'utente loggato
            UtenteLoggato = malloc(sizeof(UtenteT));
            if (!UtenteLoggato) {
                return 0;
            }

            //Copia dei dati dell'utente nella memoria persistente
            *UtenteLoggato = UtentiFile[i];


            SalvaUltimoLogin(UtenteLoggato);

            return 1;
        }
    }
    return 0;
}

//Carica i dati dell'ultimo utente loggato
int CaricaUltimoLogin() {
    //Controllo se ci sono gia` dati login salvati
    FILE* file = fopen(LocationFileUltimoLogin, "r");
    if (!file) {
        return 0;
    }

    //legge il login
    UltimoLoggatoT UltimoLogin;
    if (fscanf(file, "%d\n%20s\n", &UltimoLogin.IDUtente, UltimoLogin.NomeUtente) != 2) {
        fclose(file);
        return 0;
    }
    fclose(file);

    //Carica gli utenti per trovare quello loggato
    int numeroUtenti;
    UtenteT* utenti = GetUtentiDalFile(&numeroUtenti);
    if (!utenti) {
        return 0;
    }

    //Loop per cercarlo controllando nome utente ed ID
    for (int i = 0; i < numeroUtenti; i++) {
        if (utenti[i].id == UltimoLogin.IDUtente &&
            strcmp(utenti[i].nome, UltimoLogin.NomeUtente) == 0) {

            //Altra allocazione di memoria per copia persistente dei dati
            UtenteLoggato = malloc(sizeof(UtenteT));
            if (!UtenteLoggato) {
                free(utenti);
                return 0;
            }

            *UtenteLoggato = utenti[i];

            //Libera gli array ormai inutili e chiude
            free(utenti);
            return 1;
        }
    }

    free(utenti);
    return 0;
}

//Funzione che prende l'home directory dell'utente attualmente loggato e imposta i filepath dove salvare i file
void InitFileLocation() {
    char* HomeDir = getenv("HOME");
    StringaFormattata[0] = '0';
    snprintf(StringaFormattata, BufferSnprintf, "%s/Documents/BlackJack", HomeDir);

    mkdir(StringaFormattata, 0755);
    StringaFormattata[0] = '0';

    snprintf(LocationFileUtenti, BufferSnprintf, "%s/Documents/BlackJack/Utenti.txt", HomeDir);
    snprintf(LocationFileStoricoPartite, BufferSnprintf, "%s/Documents/BlackJack/Partite.txt", HomeDir);
    snprintf(LocationFileUltimoLogin, BufferSnprintf, "%s/Documents/BlackJack/UltimoLogin.txt", HomeDir);
}

//Funzione per loggare in automatico l'utente precedente
int AutoLogin() {
    return CaricaUltimoLogin();
}

//Funzione per sloggare l'utente e liberare la memoria da lui occupata
void SloggaUtente() {
    RimuoviUltimoLogin();
    FreeUtenteLoggato();
}