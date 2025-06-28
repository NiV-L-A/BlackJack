//-------------------------------------------------OGGETTI GLOBALI------------------------------------------------------
//                      Tutte le variabili e gli array globali si trovano in Globali.c
//----------------------------------------------------------------------------------------------------------------------
#pragma once//serve per le robe costanti e globali
#include <stdio.h>
#include <gtk/gtk.h>

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
#define CartaCoperta "GUI/SpriteCarte/coperta.png"
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
//===================InterfacciaGrafica.c=========================================
int InitProgramma(int argc, char *argv[]);
void InitArrImmagini(GtkImage* ImgCartaBanco1,GtkImage* ImgCartaBanco2,GtkImage* ImgCartaBanco3,GtkImage* ImgCartaBanco4,GtkImage* ImgCartaBanco5,GtkImage* ImgCartaBanco6,GtkImage* ImgCartaGiocatore1,GtkImage* ImgCartaGiocatore2,GtkImage* ImgCartaGiocatore3,GtkImage* ImgCartaGiocatore4,GtkImage* ImgCartaGiocatore5,GtkImage* ImgCartaGiocatore6,GtkImage* ImgCartaGiocatore7,GtkImage* ImgCartaGiocatore8);
void AggiornaStatistichePartita();
//===================Banco.c======================================================
void InitRand();//Funzione che seedda rand
char ControllaVittoria();//Funzione controllo vittoria
int CalcolaPunti(unsigned short Mano[], unsigned short Dimensione);
int PescaBanco(short CarteDaPescare);
void BancoPescaRipetuta();
//===================Giocatore.c==================================================
void CalcolaTassoVittoria();//Funzione per aggiornare le statistiche dell'utente
int PescaGiocatore(unsigned short CarteDaPescare);
int Raddoppia();
void LogicaAssi(unsigned short Mano[], unsigned short Dimensione);
//===================GestioneUtenti.c=============================================
char* RimuoviNewLine(char line[]);
char* RimuoviSpazi(char* str);
void PulisciStringa(char* str);
void ScriviUtente(FILE* file, UtenteT utente);
int RegistraUtente(UtenteT Utente);
int ModificaUtenteAlFile();
UtenteT* GetUtentiDalFile(int* NumeroUtenti);
int LoggaUtente(char Nome[], char Password[], UtenteT* UtentiFile, int Conta);
int ValidaStringa(char* str);
//===================GestioneStoricoPartite.c=====================================
StoricoPartitaT* PopolaStoricoPartiteDalFile();
void ScriviPartita(FILE* file, char Risultato, int BilancioInUscita);
int AggiungiPartitaAlFile(char Risultato, int BilancioInUscita);
void ResettaValoriGlobali();
//===================GestioneGraficaPartita.c=====================================
void AggiornaManoGiocatore();
void AggiornaManoBanco();
void AggiornaAmbiMani();
void LogicaCartaCoperta();



#ifndef MAIN_H
#define MAIN_H

#endif //MAIN_H