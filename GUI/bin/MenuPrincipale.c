#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//-----------------------------------------------SEZIONE PUNTATORI ELEMENTI---------------------------------------------
//================================TOP LEVEL=======================
GtkWidget* Finestra;
GtkWidget* ControlloScena;
GtkWidget* CntMenuPrincipale;
GtkWidget* StkStoricoPartite;
GtkWidget* CntStoricoPartite;
GtkWidget* CntVuotoStoricoPartite;
GtkWidget* CntGestioneBilancio;
GtkWidget* CntMenuAccesso;
GtkWidget* CntTavoloDaGioco;
GtkWidget* CntManoGiocatore;
GtkWidget* CntManoBanco;
GtkWidget* StkOpzioniPuntata;
GtkWidget* CntVuotoOpzioniPuntata;
GtkWidget* CntBtnOpzioniPuntata;
GtkWidget* StkOpzioniGiocatore;
GtkWidget* CntVuotoOpzioniGiocatore;
GtkWidget* CntBtnOpzioniGiocatore;
GtkWidget* CntMenuPausa;
GtkWidget* StkMenuPausa;
GtkWidget* CntOpzioniPausa;
GtkWidget* CntMenuConferma1;
GtkWidget* CntMenuConferma2;
//================================LABEL===========================
GtkWidget* LblNomeUtente;
GtkWidget* LblPartiteGiocate;
GtkWidget* LblTassoVittoria;
GtkWidget* LblBilancio;
//================================BOTTONI=========================
GtkWidget* BtnGioca;
GtkWidget* BtnAccediRegistrati;
GtkWidget* BtnStorico;
GtkWidget* BtnBilancio;
GtkWidget* BtnEsci;
GtkWidget* BtnEsci2;
GtkWidget* BtnGioca;
GtkWidget* BtnMenuPausa;
GtkWidget* BtnAccedi;
GtkWidget* BtnRegistrati;
// GtkWidget* BtnPunta50;
// GtkWidget* BtnPunta100;
// GtkWidget* BtnPunta250;
// GtkWidget* BtnPunta500;
// GtkWidget* BtnSceltaDividi;
// GtkWidget* BtnSceltaRimani;
// GtkWidget* BtnSceltaRaddoppia;
// GtkWidget* BtnSceltaPesca;
GtkWidget* BtnAggiungi100;
GtkWidget* BtnAggiungi200;
GtkWidget* BtnAggiungi500;
GtkWidget* BtnAggiungi1000;
GtkWidget* BtnPausaRiprendi;
GtkWidget* BtnPausaTornaAlMenu;
GtkWidget* BtnPausaChiudiGioco;
GtkWidget* BtnPausaAnnulla1;
GtkWidget* BtnPausaConferma1;
GtkWidget* BtnPausaAnnulla2;
GtkWidget* BtnPausaConferma2;

//================================MISC============================
GtkWidget* TxtStoricoPartite;
GtkWidget* EntNomeUtente1;
GtkWidget* EntPassword1;
GtkWidget* EntNomeUtente2;
GtkWidget* EntPassword2;
//================================BUILDER=========================
GtkBuilder* Builder;

int InitProgramma(int argc, char *argv[]){//funzione principale che gestisce la creazione della finestra ed i suoi handle

    gtk_init(&argc, &argv); //Funzione che inizializza tutta la parte dell'ui

    Builder = gtk_builder_new_from_file("GUI/bin/GUI.glade");//Dico al builder dove trovare il file GLADE per leggere gli elementi
    //Estraggo dal builder in maniera separata la finestra in quanto sia importante associarle da subito il segnale quit.
    Finestra = GTK_WIDGET(gtk_builder_get_object(Builder, "finestra"));
    g_signal_connect(Finestra, "destroy", G_CALLBACK(gtk_main_quit), NULL);//Associazione del segnale menzionata prima

    //Adesso creo una table di tutti i segnali per le funzioni CallBack
    gtk_builder_connect_signals(Builder, NULL);

//-----------------------------------------------SEZIONE COLLEGAMENTO OGGETTI-------------------------------------------
//Qui vado ad estrarre dal builder gli elementi che andro` a manipolare nel codice
//====================TOP LEVEL==================
    ControlloScena = GTK_WIDGET(gtk_builder_get_object(Builder, "controlloScena"));
    CntMenuPrincipale = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuPrincipale"));
    StkStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "stkStoricoPartite"));
    CntStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "cntStoricoPartite"));
    CntVuotoStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "cntVuotoStoricoPartite"));
    CntGestioneBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "cntGestioneBilancio"));
    CntMenuAccesso = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuAccesso"));
    CntTavoloDaGioco = GTK_WIDGET(gtk_builder_get_object(Builder, "cntTavoloGioco"));
    CntManoGiocatore = GTK_WIDGET(gtk_builder_get_object(Builder, "cntManoGiocatore"));
    CntManoBanco = GTK_WIDGET(gtk_builder_get_object(Builder, "cntManoBanco"));
    StkOpzioniPuntata = GTK_WIDGET(gtk_builder_get_object(Builder, "stkOpzioniPuntata"));
    CntVuotoOpzioniPuntata = GTK_WIDGET(gtk_builder_get_object(Builder, "cntVuotoOpzioniPuntata"));
    CntBtnOpzioniPuntata = GTK_WIDGET(gtk_builder_get_object(Builder, "cntBottoniOpzioniPuntata"));
    StkOpzioniGiocatore = GTK_WIDGET(gtk_builder_get_object(Builder, "stkOpzioniGiocatore"));
    CntVuotoOpzioniGiocatore = GTK_WIDGET(gtk_builder_get_object(Builder, "cntVuotoOpzioniGiocatore"));
    CntBtnOpzioniGiocatore = GTK_WIDGET(gtk_builder_get_object(Builder, "cntBottoniOpzioniGiocatore"));
    CntMenuPausa = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuPausa"));
    StkMenuPausa = GTK_WIDGET(gtk_builder_get_object(Builder, "stkMenuPausa"));
    CntOpzioniPausa = GTK_WIDGET(gtk_builder_get_object(Builder, "cntOpzioniPausa"));
    CntMenuConferma1 = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuConferma1"));
    CntMenuConferma2 = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuConferma2"));
//=====================LABEL=====================
    LblNomeUtente = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNomeUtente1"));
    LblPartiteGiocate = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPartiteGiocate"));
    LblTassoVittoria = GTK_WIDGET(gtk_builder_get_object(Builder, "lblTassoVittoria"));
    LblBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "lblBilancio"));
//=====================BOTTONI===================
    BtnGioca = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnGioca"));
    BtnAccediRegistrati = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnAccedi"));
    BtnStorico = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1TBtnStorico"));
    BtnBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnBilancio"));
    BtnEsci = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnEsci"));
    BtnEsci2 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnEsci"));
    BtnGioca = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnGioca"));
    BtnMenuPausa = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnPausa"));
    BtnPausaRiprendi = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnRiprendi"));
    BtnPausaTornaAlMenu = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnTornaAlMenu"));
    BtnPausaChiudiGioco = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnChiudiGioco"));
    BtnPausaAnnulla1 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnAnnulla1"));
    BtnPausaConferma1 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnConferma1"));
    BtnPausaAnnulla2 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnAnnulla2"));
    BtnPausaConferma2 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg5BtnConferma2"));
    BtnAggiungi100 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnP100"));
    BtnAggiungi200 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnP200"));
    BtnAggiungi500 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnP500"));
    BtnAggiungi1000 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnP1000"));
    BtnAccedi = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnAccedi"));
    BtnRegistrati = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnRegistrati"));
//=====================MISC======================
    TxtStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "txtStoricoPartite"));
    EntNomeUtente1 = GTK_WIDGET(gtk_builder_get_object(Builder, "entNomeUtente1"));
    EntNomeUtente2 = GTK_WIDGET(gtk_builder_get_object(Builder, "entNomeUtente2"));
    EntPassword1 = GTK_WIDGET(gtk_builder_get_object(Builder, "entPassword1"));
    EntPassword2 = GTK_WIDGET(gtk_builder_get_object(Builder, "entPassword2"));



//---------------------------------------------MANIPOLAZIONE E GESTIONE FINESTRA----------------------------------------
//===================COLORE====================
    //Comincio col creare una variabile di tipo GdkRGBA per poi assegnarle dei valori
    GdkRGBA ColoreBG;//per convertire un valore da RGBA a GDKRGBA basta divide quelli rgb per 255.
    ColoreBG.red = 0.0;
    ColoreBG.green = 0.50196;
    ColoreBG.blue = 0.16471;
    ColoreBG.alpha = 1.0;
    gtk_widget_override_background_color(Finestra, GTK_STATE_FLAG_NORMAL, &ColoreBG);//Con questa setto il colore del bg ai dati inseriti in ColoreBG

//===================INVOCAZIONE===============
    gtk_widget_show(Finestra);//Mostra la finestra

    gtk_main();//Avvia il processo main che rimarra` nel background a controllare gli input ricevuti

    return EXIT_SUCCESS;//Condizione di uscita necessaria per chiudere il programma una volta chiusa l'ui
}
//---------------------------------------------FUNZIONI CALLBACK--------------------------------------------------------
//Qui vengono gestiti i segnali di ogni widget e vi si assegna un metodo.
//===================BOTTONI===================
//Funzione che gestisce il caricamento a schermo dello storico partite
void on_pg1TBtnStorico_toggled(GtkToggleButton* tb) {//Se L'utente e` loggato ed il bottone e` in stato "schiacciato", mostra lo storico partite
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso
        gtk_toggle_button_get_active(tb) ? gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntStoricoPartite) : gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
//Funzione che gestisce il cambio scena alla pagina di "top-up" del bilancio cliccato il tasto sul menu principale
void on_pg1BtnBilancio_clicked(GtkButton* b) {//Se l'utente e` loggato, cambia scena alla pagina di gestione del bilancio
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
//Funzione che gestisce il cambio scena alla pagina di registrazione/accesso premuto il bottone "accedi" nel menu principale
void on_pg1BtnAccedi_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
//Funzine che gestisce il cambio scena facendo tornare indietro al menu principale dalla pagina di gestione bilancio
void on_pg2BtnEsci_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}
//Funzione che gestisce il cambio scena facendo tornare indietro al menu principale dalla pagina di registrazione/accesso
void on_pg3BtnEsci_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}
//Funzione che gestisce il cambio scena al playfield ed inizializza la partita
void on_pg1BtnGioca_clicked(GtkButton* b){//Se l'utente e` loggato, invoca "InitPartita" e cambia scena al tavolo di gioco
    if (UtenteLoggato != NULL){//Altrimenti, porta l'utente sulla pagina di registrazione/accesso
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
//Funzione che gestisce il cambio scena al menu di pausa durante una partita
void on_pg4BtnPausa_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPausa);
}
//Funzione che gestisce l'opzione "Riprendi" del menu pausa, facendo ritornare il giocatore alla partita
void on_pg5BtnRiprendi_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
}
//Funzione che gestisce l'opzione "Torna al menu", cambiando la finestra delle opzioni del menu pausa con una di conferma, informando l'utente che non sia possibile riprendere una partita abbandonata
void on_pg5BtnTornaAlMenu_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConferma1);
}
//Funzione che gestisce l'opzione "No" nella finestra di conferma per tornare al menu principale
void on_pg5BtnAnnulla1_clicked(GtkButton* b){//In caso venga scelta, riporta l'utente al menu pausa
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
//Funzione che gestisce l'opzione "Si" nella finestra di conferma per tornare al menu principale
void on_pg5BtnConferma1_clicked(GtkButton* b){//In caso venga scelta, riporta l'utente all menu principale, liberando la memoria occupata da quella partita
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}
//Funzione che gestisce l'opzione "Chiudi il gioco" del menu di pausa, cambiando la finestra delle opzioni del menu pausa con una di conferma, informando l'utente che non sia possibile riprendere una partita abbandonata.
void on_pg5BtnChiudiGioco_clicked(GtkButton* b){//In caso venga scelta, libera la memoria occupata da quella partita, aggiorna le statistiche contenute nel
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConferma2);
}
void on_pg5BtnAnnulla2_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
void on_pg5BtnConferma2_clicked(GtkButton* b){
    gtk_main_quit();
}
void on_pg2BtnP100_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 100;
}
void on_pg2BtnP200_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 200;
}
void on_pg2BtnP500_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 500;
}
void on_pg2BtnP1000_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 1000;
}
//===================LABEL=====================
void on_lblNomeUtente1_map(GtkLabel* lb){
    if (UtenteLoggato != NULL){
        gtk_label_set_text(lb, UtenteLoggato->nome);
    }
}
void on_lblPartiteGiocate_map(GtkLabel* lb){
    if (UtenteLoggato != NULL){
        char temp[BufferSnprintf];
        snprintf(temp, BufferSnprintf,"%d", UtenteLoggato->partiteGiocate);
        gtk_label_set_text(lb, temp);
    }
}
void on_lblTassoVittoria_map(GtkLabel* lb){
    if (UtenteLoggato != NULL){
        char temp[BufferSnprintf];
        snprintf(temp, BufferSnprintf, "%f", UtenteLoggato->percentualeVittoria);
        gtk_label_set_text(lb, temp);
    }
}
void on_lblBilancio_map(GtkLabel* lb){
    if (UtenteLoggato != NULL){
        char temp[BufferSnprintf];
        snprintf(temp, BufferSnprintf,"%d", UtenteLoggato->bilancio);
        gtk_label_set_text(lb, temp);
    }
}
//===================MISC======================
void MemorizzaDatiAccesso(GtkEntry *e){
    char Buffer[21];
    sprintf(Buffer, "%s\0", gtk_entry_get_text(e));

}
void on_entNomeUtente1_changed(GtkEntry* e) {
    MemorizzaDatiAccesso(e);
}
void on_entPassword1_changed(GtkEntry* e) {
    MemorizzaDatiAccesso(e);
}
void on_entNomeUtente2_changed(GtkEntry* e) {
    MemorizzaDatiAccesso(e);
}
void on_entPassword2_changed(GtkEntry* e) {
    MemorizzaDatiAccesso(e);
}

// Pagina di login
int validaStringa(char* str) {
    if (*str == ' ') {
        return 0;
    }
    return 1;
}

void on_pg3BtnAccedi_clicked(GtkButton* b) {
    int conta = 0;
    UtenteT* utentiFile = GetUtentiDalFile(&conta);

    // Se utentiFile è NULL e conta è 0, allora non siamo riusciti a leggere gli utenti
    if (utentiFile == NULL && conta == 0) {
        return;
    }

    fprintf(stderr, "1\n");
    char* nomeUtente = gtk_entry_get_text(EntNomeUtente1);
    if (validaStringa(nomeUtente) == 0) {
        fprintf(stderr, "2\n");
        // TODO: Far apparire un messaggio: "Nome utente inserito non valido"
        return;
    }

    char* password = gtk_entry_get_text(EntPassword1);
    fprintf(stderr, "3\n");

    if (validaStringa(password) == 0) {
        fprintf(stderr, "4\n");
        // TODO: Far apparire un messaggio: "Password inserita non valida"
        return;
    }

    fprintf(stderr, "5\n");
    if (LoggaUtente(nomeUtente, password, utentiFile, conta) == 0) {
        fprintf(stderr, "6\n");
        // TODO: Far apparire un messaggio: "Combinazione utente/password non trovato"
        return;
    }

    fprintf(stderr, "7\n");
    // Se siamo arrivati qui, l'utente è loggato
    fprintf(stderr, "Loggato\n");
}

void on_pg3BtnRegistrati_clicked(GtkButton* b) {
    char* nomeUtente = gtk_entry_get_text(EntNomeUtente2);
    if (validaStringa(nomeUtente) == 0) {
        // TODO: Far apparire un messaggio: "Nome utente inserito non valido"
        return;
    }
    char* password = gtk_entry_get_text(EntPassword2);
    if (validaStringa(password) == 0) {
        // TODO: Far apparire un messaggio: "Password inserita non valida"
        return;
    }

    UtenteT utente;
    utente.id = rand() % 1000;
    snprintf(utente.nome, sizeof(utente.nome), nomeUtente);
    snprintf(utente.password, sizeof(utente.password), password);
    utente.bilancio = 500;
    utente.percentualeVittoria = rand() % 100;
    utente.partiteGiocate = rand() % 100;

    if (RegistraUtente(utente) == 0) {
        return;
    }

    // L'utente è stato registrato
}












