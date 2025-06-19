#include <stdio.h>
#include "banco.c"
#include "giocatore.c"
#include "gestioneUtenti.c"
#include "gestioneStoricoPartite.c"
#include "main.h"

int DEBUG_UTENTI() {
    // GetUtentiDalFile
    int count = 0;
    Utente_t* utentiFile = GetUtentiDalFile(&count);
    // Se utentiFile è NULL e count è 0, allora non siamo riusciti a leggere gli utenti
    for (int i = 0; i < count; i++) {
        printf("%d,", utentiFile[i].id);
        printf("%s,", utentiFile[i].nome);
        printf("%s,", utentiFile[i].password);
        printf("%d,", utentiFile[i].bilancio);
        printf("%.0f,", utentiFile[i].percentualeVittoria);
        printf("%d", utentiFile[i].partiteGiocate);
        printf("\n");
    }

    // GetIndiceUtenteDaCredenziali
    char* nomeUtenteDaCercare = "Utente463";
    int indiceUtenteLoggato = GetIndiceUtenteDaCredenziali(nomeUtenteDaCercare,"Password53", utentiFile, count);
    if (indiceUtenteLoggato == -1) {
        printf("Nome utente \"%s\" non trovato", nomeUtenteDaCercare);
    }
    else {
        printf("Nome utente loggato: %s,", utentiFile[indiceUtenteLoggato].nome);
    }

    // AggiungiUtenteAlFile
    srand(time(NULL));
    Utente_t utente;
    utente.id = rand() % 1000;
    snprintf(utente.nome, sizeof(utente.nome), "Utente%d", rand() % 1000);
    snprintf(utente.password, sizeof(utente.password), "Password%d", rand() % 1000);
    utente.bilancio = 500;
    utente.percentualeVittoria = rand() % 100;
    utente.partiteGiocate = rand() % 100;
    AggiungiUtenteAlFile(utente);

    // ModificaUtenteAlFile
    utente.id = 529;
    ModificaUtenteAlFile(utente);
}

int DEBUG_STORICO() {
    int count = 0;
    StoricoPartita_t* partite = GetStoricoPartiteDalFile(&count, "Utente111");
    for (int i = 0; i < count; i++) {
        printf("%s,", partite[i].nomeUtente);
        printf("%s,", partite[i].risultato);
        printf("%d", partite[i].bilancioAllUscita);
        printf("\n");
    }

    StoricoPartita_t partita;
    snprintf(partita.nomeUtente, sizeof(partita.nomeUtente), "Utente%d", rand() % 1000);
    int r = rand() % 3;
    char* result;
    switch (r) {
        case 0:
            result = "S";
            break;
        case 1:
            result = "P";
            break;
        case 2:
            result = "V";
            break;
        case 3:
            result = "B";
            break;
        default:
            result = "-";
            break;
    }
    snprintf(partita.risultato, sizeof(partita.risultato), "%s", result);
    strcpy(partita.risultato, result);
    partita.bilancioAllUscita = rand() % 1000;
    AggiungiPartitaAlFile(partita);
}

// nel main mettiamo solo le call alle funzioni.
int main(){
    DEBUG_UTENTI();
    DEBUG_STORICO();
    return;

    static int manoBanco[MAXcarte];//mettere static davanti ad una variabile garantisce che i valori non assegnati siano deterministici anziche` numeri a caso presi da un punto a caso della memoria
    static int manoGiocatore[MAXcarte];
    int scommessa = 10;
    int portafoglio = 100;
    //TODO: rendere globali gli array delle mani e le variabili che tengono traccia di scommessa e portafoglio del giocatore

    //DEBUG init mano
    banco_init();
    // for(int i = 0; i < 9; i++)
    // {
    //     printf("%d: \n",i);
    //     pesca(manoGiocatore);
    // }
    manoGiocatore[0] = 22;
    manoGiocatore[1] = 22;
    dividi(manoGiocatore,scommessa);

    printMano(manoGiocatore);
    printMano(manoGiocatoreDivisa);

    printf("\nscommessa: %d -- scommessa splittata: %d",scommessa,puntataDivisa);


    //DEBUG sezione
    //printf("prima di raddoppia %d\n", scommessa);
   // printMano(manoGiocatore);
   // raddoppia(manoGiocatore, &scommessa);

    //printf("dopo di raddoppia %d\n", scommessa);
    //printMano(manoGiocatore);
}