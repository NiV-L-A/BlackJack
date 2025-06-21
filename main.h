//-------------------------------------------------OGGETTI GLOBALI------------------------------------------------------
#pragma once//serve per le robe costanti e globali
#include <stdio.h>
#include <stddef.h>

//===================DEFINIZIONI==================================================
#define MAXcarte 22 //valore massimo di carte che il gicatore puo` avere in mano
#define LunghezzaMassimaStringa 21
#define LunghezzaMassimaRiga 256
#define NomeFileStoricoPartite "file/storicoPartite"
#define NomeFileUtenti "file/utenti"

//===================TYPEDEF======================================================
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
    char Risultato; // S = Sconfitta, P = Pareggio, V = Vittoria, B = Vittoria con Blackjack
    int BilancioDiUscita;
} StoricoPartitaT;

//===================VARIABILI GLOBALI (DICHIARAZIONI)========================
extern int Puntata;
extern int NumeroRighi;
extern int ManoGiocatoreDivisa[MAXcarte];
extern int PuntataDivisa;
extern UtenteT* UtenteLoggato;

//===================ARRAY========================================================
//mazzo statico con tutte le carte
//si comincia da 1 e non da 0 perche` 0 e` il valore default di un elemento non assegnato dell'array mano
extern const unsigned short mazzo[52];

//-------------------------------------------------DICHIARAZIONE FUNZIONI-----------------------------------------------

//===================banco.c======================================================
void BancoInit();//Funzione che seedda rand per il banco
void Pesca(int mano[]);//Funzione che pesca una o piu` carte
void Raddoppia(int mano[], int *scommessa);//Funzione che implementa il 'double'
char ControllaVittoria(int ManoGiocatore[], int ManoBanco[]);//Funzione controllo vittoria
int InitProgramma(int argc, char *argv[]);
//===================giocatore.c==================================================
void Dividi(int mano[]);//Funzione che implementa lo 'split'
void AggiornamentoStatistiche(StoricoPartitaT* ArrPartite);//Funzione per aggiornare le statistiche dell'utente

//===================GestioneUtenti.c=============================================
char* RimuoviNewLine(char line[]);
char* RimuoviSpazi(char* str);
void PulisciStringa(char* str);
void ScriviUtente(FILE* file, UtenteT utente);
int RegistraUtente(UtenteT Utente);
int ModificaUtenteAlFile(UtenteT utente);
UtenteT* GetUtentiDalFile(int* NumeroUtenti);

//===================GestioneStoricoPartite.c=====================================
StoricoPartitaT* PopolaStoricoPartiteDalFile();
void ScriviPartita(FILE* file, StoricoPartitaT partita);
int AggiungiPartitaAlFile(StoricoPartitaT partita);

//FUNZIONI DEBUG
void printMano(int mano[]);//printare la mano passata

#ifndef MAIN_H
#define MAIN_H

#endif //MAIN_H