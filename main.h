//-------------------------------------------------OGGETTI GLOBALI------------------------------------------------------
//                      Tutte le variabili e gli array globali si trovano in Globali.c
//----------------------------------------------------------------------------------------------------------------------
#pragma once//serve per le robe costanti e globali
#include <stdio.h>

//===================DEFINIZIONI==================================================
#define MAXcarteGiocatore 8 //valore massimo di carte che il gicatore puo` avere in mano
#define MAXcarteBanco 6
#define MAXmazziBanco 6
#define SlotVuoto 0
#define RimuoviSeme / 10
#define DimensioneMazzo 52
#define LunghezzaMassimaStringa 21
#define LunghezzaMassimaRiga 256
#define BufferSnprintf 200
#define NomeFileStoricoPartite "File/StoricoPartite"
#define NomeFileUtenti "File/Utenti"

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
extern short NumeroMazziGiocatore;
extern UtenteT* UtenteLoggato;

//===================ARRAY GLOBALI (DICHIARAZIONI)============================
//mazzo statico con tutte le carte
//si comincia da 1 e non da 0 perche` 0 e` il valore default di un elemento non assegnato dell'array mano
extern const unsigned short Mazzo[DimensioneMazzo];
extern unsigned short ControlloRipetizioni[DimensioneMazzo];
extern unsigned short ManoGiocatore[MAXcarteGiocatore];
extern unsigned short ManoBanco[MAXcarteBanco];


//-------------------------------------------------DICHIARAZIONE FUNZIONI-----------------------------------------------
//Accanto ad ogni funzione vi e` una spiegazione rapida del suo funzionamento. Usando il "jump-to" dell'IDE potete
//              andare direttamente dove e` stata dichiarata, trovando una spiegazione piu` estesa.
//----------------------------------------------------------------------------------------------------------------------
int InitProgramma(int argc, char *argv[]);
//===================Banco.c======================================================
void RandInit();//Funzione che seedda rand
char ControllaVittoria();//Funzione controllo vittoria
int CalcolaPunti(unsigned short Mano[], unsigned short Dimensione);
int PescaBanco(short CarteDaPescare);
//===================Giocatore.c==================================================
void AggiornamentoStatistiche(StoricoPartitaT* ArrPartite);//Funzione per aggiornare le statistiche dell'utente
int PescaGiocatore(unsigned short CarteDaPescare);
void Raddoppia();
//===================GestioneUtenti.c=============================================
char* RimuoviNewLine(char line[]);
char* RimuoviSpazi(char* str);
void PulisciStringa(char* str);
void ScriviUtente(FILE* file, UtenteT utente);
int RegistraUtente(UtenteT Utente);
int ModificaUtenteAlFile(UtenteT utente);
UtenteT* GetUtentiDalFile(int* NumeroUtenti);
int LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta);
int validaStringa(char* str);
//===================GestioneStoricoPartite.c=====================================
StoricoPartitaT* PopolaStoricoPartiteDalFile();
void ScriviPartita(FILE* file, StoricoPartitaT partita);
int AggiungiPartitaAlFile(StoricoPartitaT partita);
void ResettaValoriGlobali();
//===================GestioneGraficaPartita.c=====================================
void RenderizzaCarta(GtkImage *immagine, int idCarta);
void AggiornaManoGiocatore();
void AggiornaManoBanco();
void AggiornaAmbiMani();
void InitRenderingCarte(GtkBuilder *Builder);
void AggiornaStatistichePartita();


#ifndef MAIN_H
#define MAIN_H

#endif //MAIN_H