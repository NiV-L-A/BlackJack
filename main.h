//-------------------------------------------------OGGETTI GLOBALI------------------------------------------------------
#pragma once//serve per le robe costanti e globali

//===================DEFINIZIONI===================
#define MAXcarte 22 //valore massimo di carte che il gicatore puo` avere in mano
#define LunghezzaMassimaStringa 21
#define LunghezzaMassimaRiga 256
#define NomeFileStoricoPartite "file/storicoPartite"
#define NomeFileUtenti "file/utenti"

//===================TYPEDEF======================
typedef struct {//Definisce il tipo Utente
    int id;
    char nome[LunghezzaMassimaStringa];
    char password[LunghezzaMassimaStringa];
    int bilancio;
    float percentualeVittoria;
    int partiteGiocate;
} UtenteT;

typedef struct {//Definisce il tipo StoricoPartita
    char NomeUtente[LunghezzaMassimaStringa];
    char Risultato[2]; // S = Sconfitta, P = Pareggio, V = Vittoria, B = Vittoria con Blackjack
    int BilancioDiUscita;
} StoricoPartitaT;

//===================VARIABILI====================
int Puntata = 0;
int NumeroPartite = 0;
int ManoGiocatoreDivisa[MAXcarte];
int PuntataDivisa;

//===================ARRAY========================
// TODO: rendere globali le seguenti variabili:
// - Numero di righe nel file storico partite


//mazzo statico con tutte le carte
//si comincia da 1 e non da 0 perche` 0 e` il valore default di un elemento non assegnato dell'array mano
const unsigned short mazzo[52] = {
    // Asso, 2, 3, ... 10, J, Q, K
    1, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131,
    2, 22, 32, 42, 52, 62, 72, 82, 92, 102, 112, 122, 132,
    3, 23, 33, 43, 53, 63, 73, 83, 93, 103, 113, 123, 133,
    4, 24, 34, 44, 54, 64, 74, 84, 94, 104, 114, 124, 134
};

UtenteT UtenteLoggato;

//-------------------------------------------------DICHIARAZIONE FUNZIONI-----------------------------------------------

//===================banco.c======================================================
void BancoInit();//funzione di inizializzazione del banco
void Pesca(int mano[]);//funzione pesca in banco
void Raddoppia(int mano[], int *scommessa);//funzione raddoppia
char ControllaVittoria(int ManoGiocatore[], int ManoBanco[]);//Funzione controllo vittoria

//===================giocatore.c==================================================
void Dividi(int mano[]);//funzione split in giocatore

//===================GestioneUtenti.c=============================================
char* RimuoviNewLine(char line[]);
char* RimuoviSpazi(char* str);
void PulisciStringa(char* str);
void ScriviUtente(FILE* file, UtenteT utente);
int RegistraUtente(UtenteT Utente);
int ModificaUtenteAlFile(UtenteT utente);
UtenteT* GetUtentiDalFile(int* NumeroUtenti);

//===================GestioneStoricoPartite.c=====================================
StoricoPartitaT* GetStoricoPartiteDalFile(char NomeUtente[]);
void ScriviPartita(FILE* file, StoricoPartitaT partita);
int AggiungiPartitaAlFile(StoricoPartitaT partita);





//FUNZIONI DEBUG
void printMano(int mano[]);//printare la mano passata



//non toccare queste
#ifndef MAIN_H
#define MAIN_H

#endif //MAIN_H
