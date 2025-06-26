#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "../../main.h"

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
GtkWidget* StkOpzioniAccesso;
GtkWidget* CntAccesso;
GtkWidget* CntVuotoOpzioniPuntata;
GtkWidget* CntBtnOpzioniPuntata;
GtkWidget* StkOpzioniGiocatore;
GtkWidget* CntVuotoOpzioniGiocatore;
GtkWidget* CntBtnOpzioniGiocatore;
GtkWidget* CntMenuPausa;
GtkWidget* StkMenuPausa;
GtkWidget* CntOpzioniPausa;
GtkWidget* CntMenuConfermaHome;
GtkWidget* CntMenuConfermaQuit;
GtkWidget* CntSecondaPesca;
//================================LABEL===========================
GtkWidget* LblNomeUtenteMenuPrincipale;
GtkWidget* LblPartiteGiocate;
GtkWidget* LblTassoVittoria;
GtkWidget* LblBilancioMenuPrincipale;
GtkWidget* LblNotificaErroreAccesso;
GtkWidget* LblNomeUtenteGestioneBilancio;
GtkWidget* LblNomeUtentePartita;
GtkWidget* LblBilancioGestioneBilancio;
GtkWidget* LblBilancioPartita;
GtkWidget* LblErrorePartita;
GtkWidget* LblErroreAggiungiCrediti;
GtkWidget* LblPuntata;
GtkWidget* LblValoreManoGiocatore;
GtkWidget* LblValoreManoBanco;
GtkWidget* LblPartitaVinta;
GtkWidget* LblPartitaPersa;
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
GtkWidget* BtnPunta50;
GtkWidget* BtnPunta100;
GtkWidget* BtnPunta250;
GtkWidget* BtnPunta500;
GtkWidget* BtnSceltaRimani;
GtkWidget* BtnSceltaRaddoppia;
GtkWidget* BtnSceltaPesca;
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
GtkWidget* BtnFinisciTurno;
GtkWidget* BtnSecondaPesca;
GtkWidget* BtnFinePartitaEsci;
//================================MISC============================
GtkWidget* TxtStoricoPartite;
GtkWidget* EntNomeUtente1;
GtkWidget* EntPassword1;
GtkWidget* EntNomeUtente2;
GtkWidget* EntPassword2;
//================================IMMAGINI========================
GtkImage* ImgCartaBanco1, *ImgCartaBanco2, *ImgCartaBanco3, *ImgCartaBanco4, *ImgCartaBanco5, *ImgCartaBanco6;
GtkImage* ImgCartaGiocatore1, *ImgCartaGiocatore2, *ImgCartaGiocatore3, *ImgCartaGiocatore4, *ImgCartaGiocatore5, *ImgCartaGiocatore6, *ImgCartaGiocatore7, *ImgCartaGiocatore8;
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
    CntMenuConfermaHome = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuConferma1"));
    CntMenuConfermaQuit = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuConferma2"));
    StkOpzioniAccesso = GTK_WIDGET(gtk_builder_get_object(Builder, "stkOpzioniAccesso"));
    CntAccesso = GTK_WIDGET(gtk_builder_get_object(Builder, "cntAccesso"));
    CntSecondaPesca = GTK_WIDGET(gtk_builder_get_object(Builder, "cntSecondaPesca"));
//=====================LABEL=====================
    LblNomeUtenteMenuPrincipale = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNomeUtente1"));
    LblPartiteGiocate = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPartiteGiocate"));
    LblTassoVittoria = GTK_WIDGET(gtk_builder_get_object(Builder, "lblTassoVittoria"));
    LblBilancioMenuPrincipale = GTK_WIDGET(gtk_builder_get_object(Builder, "lblBilancio"));
    LblNotificaErroreAccesso = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNotificaErrore"));
    LblBilancioGestioneBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "lblBilancio2"));
    LblBilancioPartita = GTK_WIDGET(gtk_builder_get_object(Builder, "lblBilancio3"));
    LblNomeUtenteGestioneBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNomeUtente2"));
    LblNomeUtentePartita = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNomeUtente3"));
    LblErrorePartita = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNotificaPartita"));
    LblErroreAggiungiCrediti = GTK_WIDGET(gtk_builder_get_object(Builder,"lblNotificaAggiungiCrediti"));
    LblPuntata = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPuntata"));
    LblValoreManoGiocatore = GTK_WIDGET(gtk_builder_get_object(Builder, "lblValoreManoGiocatore"));
    LblValoreManoBanco = GTK_WIDGET(gtk_builder_get_object(Builder, "lblValoreManoBanco"));
    LblPartitaVinta = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPartitaVinta"));
    LblPartitaPersa = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPartitaPersa"));
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
    BtnAggiungi100 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnAgg100"));
    BtnAggiungi200 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnAgg200"));
    BtnAggiungi500 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnAgg500"));
    BtnAggiungi1000 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnAgg1000"));
    BtnAccedi = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnAccedi"));
    BtnRegistrati = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnRegistrati"));
    BtnPunta50 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnP50"));
    BtnPunta100 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnP100"));
    BtnPunta250 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnP250"));
    BtnPunta500 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnP500"));
    BtnSceltaPesca = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnPesca"));
    BtnSecondaPesca = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnPesca2"));
    BtnSceltaRaddoppia = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnRaddoppia"));
    BtnSceltaRimani = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnRimani"));
    BtnFinisciTurno = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnFinisciTurno"));
    BtnFinePartitaEsci = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnEsci"));
//=====================IMMAGINI==================
    ImgCartaBanco1 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco1"));
    ImgCartaBanco2 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco2"));
    ImgCartaBanco3 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco3"));
    ImgCartaBanco4 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco4"));
    ImgCartaBanco5 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco5"));
    ImgCartaBanco6 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaBanco6"));
    ImgCartaGiocatore1 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore1"));
    ImgCartaGiocatore2 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore2"));
    ImgCartaGiocatore3 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore3"));
    ImgCartaGiocatore4 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore4"));
    ImgCartaGiocatore5 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore5"));
    ImgCartaGiocatore6 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore6"));
    ImgCartaGiocatore7 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore7"));
    ImgCartaGiocatore8 = GTK_IMAGE(gtk_builder_get_object(Builder, "imgCartaGiocatore8"));

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

//---------------------------------------------INVOCAZIONI FILE---------------------------------------------------------
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
        if (gtk_toggle_button_get_active(tb)) {
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntStoricoPartite);
            StoricoPartitaT* partite = PopolaStoricoPartiteDalFile();

            StoricoPartitaT partita;
            snprintf(partita.NomeUtente, sizeof(partita.NomeUtente), UtenteLoggato->nome);
            char* Risultato = "P";
            //snprintf(&partita.Risultato, sizeof(partita.Risultato), "%s", Risultato);
            strcpy(&partita.Risultato, Risultato);
            partita.BilancioDiUscita = 1000;
            AggiungiPartitaAlFile(partita);
            fprintf(stderr, "\n-----\n");
            for (int i = 0; i < NumeroRighi; i++) {
                fprintf(stderr, "%s", partite[i].NomeUtente);
                fprintf(stderr, " %s", &partite[i].Risultato);
                fprintf(stderr, " %d", partite[i].BilancioDiUscita);
                fprintf(stderr, "\n");
            }
        }
        else {
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
        }
        return;
    }
    gtk_toggle_button_set_active(tb,0);
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
//Funzione che gestisce il cambio scena alla pagina di "top-up" del bilancio cliccato il tasto sul menu principale
void on_pg1BtnBilancio_clicked(GtkButton* b) {//Se l'utente e` loggato, cambia scena alla pagina di gestione del bilancio
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
        return;
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
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), NULL);
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
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
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaHome);
}
//Funzione che gestisce l'opzione "No" nella finestra di conferma per tornare al menu principale
void on_pg5BtnAnnulla1_clicked(GtkButton* b){//In caso venga scelta, riporta l'utente al menu pausa
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
//Funzione che gestisce l'opzione "Si" nella finestra di conferma per tornare al menu principale
void on_pg5BtnConferma1_clicked(GtkButton* b){//In caso venga scelta, riporta l'utente all menu principale, liberando la memoria occupata da quella partita
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
    gtk_widget_hide(BtnFinePartitaEsci);
    gtk_label_set_text(GTK_LABEL(LblPartitaPersa), NULL);
    gtk_label_set_text(GTK_LABEL(LblPartitaVinta), NULL);
}
//Funzione che gestisce l'opzione "Chiudi il gioco" del menu di pausa, cambiando la finestra delle opzioni del menu pausa con una di conferma, informando l'utente che non sia possibile riprendere una partita abbandonata.
void on_pg5BtnChiudiGioco_clicked(GtkButton* b){//In caso venga scelta, libera la memoria occupata da quella partita, aggiorna le statistiche contenute nel
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaQuit);
}
void on_pg5BtnAnnulla2_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
void on_pg5BtnConferma2_clicked(GtkButton* b){
    gtk_main_quit();
}
void on_pg2BtnAgg100_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 100;
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), temp);
}
void on_pg2BtnAgg200_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 200;
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), temp);
}
void on_pg2BtnAgg500_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 500;
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), temp);
}
void on_pg2BtnAgg1000_clicked(GtkButton* b){
    UtenteLoggato->bilancio += 1000;
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), temp);
}

//Le seguenti funzioni gestiscono cio` che accade quando il giocatore fa una scelta


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
        snprintf(temp, BufferSnprintf, "%.2f%%", UtenteLoggato->percentualeVittoria);
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
void on_lblBilancio2_map(GtkLabel* lb){
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(lb, temp);
}
void on_lblBilancio3_map(GtkLabel* lb){
    char temp[BufferSnprintf];
    snprintf(temp, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(lb, temp);
}
void on_lblNomeUtente2_map(GtkLabel* lb){
    gtk_label_set_text(lb, UtenteLoggato->nome);
}
void on_lblNomeUtente3_map(GtkLabel* lb){
    gtk_label_set_text(lb, UtenteLoggato->nome);
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

void on_pg3BtnAccedi_clicked(GtkButton* b) {
    char* nomeUtente = gtk_entry_get_text(GTK_ENTRY(EntNomeUtente1));
    if (validaStringa(nomeUtente) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tNome utente invalido!\n \t\t Riprovare");
        return;
    }

    char* password = gtk_entry_get_text(GTK_ENTRY(EntPassword1));
    if (validaStringa(password) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tPassword invalida!\n \t\t Riprovare");
        return;
    }

    int conta = 0;
    UtenteT* utentiFile = GetUtentiDalFile(&conta);
    // Se utentiFile è NULL e conta è 0, allora non siamo riusciti a leggere gli utenti
    if (utentiFile == NULL && conta == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente inesistente!\n \t\t Riprovare");
        return;
    }

    if (LoggaUtente(nomeUtente, password, utentiFile, conta) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente inesistente!\n \t\t Riprovare");
        return;
    }

    // Se siamo arrivati qui, l'utente è loggato
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente autenticato");
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}

void on_pg3BtnRegistrati_clicked(GtkButton* b) {
    char* nomeUtente = gtk_entry_get_text(GTK_ENTRY(EntNomeUtente2));
    if (validaStringa(nomeUtente) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tNome utente invalido!\n \t\t Riprovare");
        return;
    }
    char* password = gtk_entry_get_text(GTK_ENTRY(EntPassword2));
    if (validaStringa(password) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tPassword invalida!\n \t\t Riprovare");
        return;
    }

    UtenteT utente;
    utente.id = rand() % 1000;
    snprintf(utente.nome, sizeof(utente.nome), nomeUtente);
    snprintf(utente.password, sizeof(utente.password), password);
    utente.bilancio = 500;
    utente.percentualeVittoria = 0;
    utente.partiteGiocate = 0;

    if (RegistraUtente(utente) == 0) {
        return;
    }

    // L'utente è stato registrato
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente registrato! \n\t\t Accedere");
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniAccesso), CntAccesso);

}
//Funzione generale che aggiorna le statistiche visibili durante la partita
void AggiornaStatistichePartita() {
    char Temp[BufferSnprintf];
    //Bilancio e puntata
    snprintf(Temp, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioPartita), Temp);
    Temp[0] = '\0';
    snprintf(Temp, BufferSnprintf, "%d", Puntata);
    gtk_label_set_text(GTK_LABEL(LblPuntata), Temp);
    Temp[0] = '\0';

    if (NumeroMazziGiocatore == 3) {//Controllo per accertare che la difficolta' sia impostata su "facile"
        snprintf(Temp, BufferSnprintf, "Valore mano: %d",CalcolaPunti(ManoGiocatore, MAXcarteGiocatore));
        Temp[0] = '\0';
        snprintf(Temp, BufferSnprintf, "Valore mano: %d",CalcolaPunti(ManoBanco, MAXcarteBanco));
    }
}
//-------------------------------------------------SEZIONE GESTIONE PARTITA---------------------------------------------

void on_ConfermaScommessa_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntVuotoOpzioniPuntata);
    gtk_widget_hide(BtnFinisciTurno);

    PescaGiocatore(2);
    PescaBanco(2);
    AggiornaAmbiMani();
    AggiornaStatistichePartita();

    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntBtnOpzioniGiocatore);
}
//Funzione che gestisce il cambio scena al playfield ed inizializza la partita
void on_pg1BtnGioca_clicked(GtkButton* b){//Se l'utente e` loggato, controlla se abbia abbastanza crediti per fare almeno una puntata minima
    if (UtenteLoggato != NULL){//Se esso e` loggato ed ha abbastanza crediti, viene inizializzata la partita
        if (UtenteLoggato->bilancio >= 50){//Se non ha abbastanza crediti, viene portato sulla pagina di gestione del bilancio e promptato di aggiungerne un po'
            gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
            gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntBtnOpzioniPuntata);
            gtk_widget_show(BtnFinisciTurno);
            ResettaValoriGlobali();
            InitArrImmagini(ImgCartaBanco1,ImgCartaBanco2,ImgCartaBanco3, ImgCartaBanco4, ImgCartaBanco5, ImgCartaBanco6, ImgCartaGiocatore1, ImgCartaGiocatore2, ImgCartaGiocatore3, ImgCartaGiocatore4, ImgCartaGiocatore5, ImgCartaGiocatore6, ImgCartaGiocatore7, ImgCartaGiocatore8);
            AggiornaAmbiMani();
            gtk_button_set_label(GTK_BUTTON(BtnFinisciTurno), "Conferma Puntata");
            g_signal_connect(BtnFinisciTurno, "clicked", G_CALLBACK(on_ConfermaScommessa_clicked), NULL);
            return;
        }
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
        gtk_label_set_text(GTK_LABEL(LblErroreAggiungiCrediti), "Non hai abbastanza crediti per giocare! \n\t\tAggiungine un po'!");
        return;
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}

void TurnoBanco() {
    //scropricarta();
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
    while (PescaBanco(1)) {
       AggiornaManoBanco();
    }

    char StringaFormattata[BufferSnprintf];
    switch (ControllaVittoria()) {
    case 'B'://Blackjack
        snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita con un BlackJack \n\t guadagnando  %.0f crediti!", Puntata * 2.5);
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
        //salvaPartitaSuFile();
        break;
    case 'V'://Vittoria semplice
        snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita guadagnando \n\t\t %d crediti!", Puntata*2);
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
        //salvaPartitaSuFile();
        break;
    case 'P':
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), "Hai pareggiato la partita! \n\t Non ci sono conseguenze!");
        //salvaPartitaSuFile();
        break;
    case 'S':
        snprintf(StringaFormattata, BufferSnprintf, "Hai perso la partita rimettendoci \n\t\t %d crediti!", Puntata);
        gtk_label_set_text(GTK_LABEL(LblPartitaPersa), StringaFormattata);
        //salvaPartitaSuFile();
        break;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), NULL);
    gtk_widget_show(BtnFinePartitaEsci);
}

void on_FinisciTurno_clicked(GtkButton* b) {
    gtk_widget_hide(BtnFinisciTurno);
    LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
    TurnoBanco();
}
//Handler opzioni giocatore
void on_pg4BtnRaddoppia_clicked(GtkButton* b) {//Il giocatore ha deciso di raddoppiare//Invoca funzione raddoppia e controlla se sia possibile farlo
    if (Raddoppia()) {
        AggiornaStatistichePartita();
        AggiornaManoGiocatore();
        TurnoBanco();
    }else {
        gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
    }
}

void on_pg4BtnPesca_clicked(GtkButton* b) {
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), NULL);
    PescaGiocatore(1);
    AggiornaManoGiocatore();
    AggiornaStatistichePartita();
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntSecondaPesca);
    gtk_button_set_label(GTK_BUTTON(BtnFinisciTurno), "Finisci turno");
    g_signal_connect(BtnFinisciTurno, "clicked", G_CALLBACK(on_FinisciTurno_clicked), NULL);
    gtk_widget_show(BtnFinisciTurno);
}
void on_pg4BtnPesca2_clicked(GtkButton* b) {
    if (PescaGiocatore(1)) {
        AggiornaManoGiocatore();
        AggiornaStatistichePartita();
    } else {
        gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Hai raggiunto il limite di carte!");
        gtk_widget_hide(BtnFinisciTurno);
        TurnoBanco();
    }
}
//Queste funzioni gestiscono i bottoni che permettono di fare una puntata durante la partita
void on_pg4BtnP50_clicked(GtkButton* b){//Se il bilancio dell'utente - la somma puntata e` maggiore o uguale a 0, punta quella somma e aggiorna la statistica "bilancio"
    if (UtenteLoggato->bilancio - 50 >= 0) {//Altrimenti mostra un errore informando l'utente che non abbia abbastanza crediti
        Puntata += 50;
        UtenteLoggato->bilancio -= 50;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP100_clicked(GtkButton* b) {

    if (UtenteLoggato->bilancio - 100 >= 0){
        Puntata += 100;
        UtenteLoggato->bilancio -= 100;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP250_clicked(GtkButton* b) {

    if (UtenteLoggato->bilancio - 250 >= 0){
        Puntata += 250;
        UtenteLoggato->bilancio -= 250;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP500_clicked(GtkButton* b){

    if (UtenteLoggato->bilancio - 500 >= 0){
        Puntata += 500;
        UtenteLoggato->bilancio -= 500;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}



