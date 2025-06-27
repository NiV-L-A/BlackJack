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
GtkWidget* CntOpzioniDifficolta;
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
GtkWidget* BtnConfermaPuntata;
GtkWidget* BtnOpzioni;
//================================MISC============================
GtkWidget* TxtStoricoPartite;
GtkWidget* EntNomeUtente1;
GtkWidget* EntPassword1;
GtkWidget* EntNomeUtente2;
GtkWidget* EntPassword2;
GtkWidget* RdioDiffNormale;
GtkWidget* RdioDiffFacile;
GtkWidget* RdioDiffDifficile;
GtkWidget* TxtStoricoPartite;
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
    CntOpzioniDifficolta = GTK_WIDGET(gtk_builder_get_object(Builder, "cntOpzioniDiff"));
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
    BtnConfermaPuntata = GTK_WIDGET(gtk_builder_get_object(Builder, "pg4BtnConfermaPuntata"));
    BtnOpzioni = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnOpzioni"));
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
    RdioDiffNormale = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffNormale"));
    RdioDiffDifficile = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffDifficile"));
    RdioDiffFacile = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffFacile"));
    TxtStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "txtStoricoPartite"));

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
//---------------------------------------------FUNZIONI GENERICHE-------------------------------------------------------
//Qui ci sono funzioni di utilizzo generale che non potevano esse spostate in un altro file in quanto manipolino oggetti
//                                       e segnali presenti in questo.
//----------------------------------------------------------------------------------------------------------------------

//Funzione generale che aggiorna le statistiche visibili durante la partita
void AggiornaStatistichePartita() {//Si occupa di modificare i valori riportati nei vari label presenti durante la partita
    char StringaFormattata[BufferSnprintf];
    //Bilancio e puntata
    snprintf(StringaFormattata, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioPartita), StringaFormattata);
    StringaFormattata[0] = '\0';//Svuoto la variabile per poterla riutilizzare
    snprintf(StringaFormattata, BufferSnprintf, "%d", Puntata);
    gtk_label_set_text(GTK_LABEL(LblPuntata), StringaFormattata);
    StringaFormattata[0] = '\0';

    //Controllo per accertare che la difficolta' sia impostata su "facile"
    if (NumeroMazziGiocatore == 3) {//Se si, aggiorna anche i label che tengono conto del valore delle mani

        //Chiamo la logica assi per assicurarmi che il punteggio sia attendibile
        LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
        LogicaAssi(ManoBanco, MAXcarteBanco);

        //Sistemati gli assi, Chiamo CalcolaPunti per entrambe le mani e metto il risultato a schermo
        snprintf(StringaFormattata, BufferSnprintf, "Valore mano: %d",CalcolaPunti(ManoGiocatore, MAXcarteGiocatore));
        gtk_label_set_text(GTK_LABEL(LblValoreManoGiocatore), StringaFormattata);
        StringaFormattata[0] = '\0';
        snprintf(StringaFormattata, BufferSnprintf, "Valore mano: %d",CalcolaPunti(ManoBanco, MAXcarteBanco));
        gtk_label_set_text(GTK_LABEL(LblValoreManoBanco), StringaFormattata);
    }
}




//---------------------------------------------FUNZIONI CALLBACK--------------------------------------------------------
//                    Qui vengono gestiti i segnali di ogni widget e vi si assegna un metodo.
//----------------------------------------------------------------------------------------------------------------------
//######################################################################################################################
//##############################################SCHERMATA MENU PRINCIPALE###############################################
//######################################################################################################################
//=====================================================BOTTONI==========================================================


//Segnale che viene triggerato quando viene cliccato il bottone "Storico Partite" sul menu` principale avendo uno stato
//"attivo" e "disattivo"
void on_pg1TBtnStorico_toggled(GtkToggleButton* tb) {//Se l'utente e` loggato ed il bottone e` stato schiacciato, mostra a schermo lo storico partite
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso

        //Controllo lo stato del bottone switchando da uno stato all'altro
        if (gtk_toggle_button_get_active(tb)) {//Se stato = attivo, mostra lo storico partite
            //La logica della popolazione dello storico e` gestita dal segnale "Map" per assicurarsi che venga eseguita
            //Solo quando e` visibile a schermo, non quando viene cliccato il bottone (in quanto potrebbe farlo un
            //utente non loggato occupando memoria senza avere la possibilita` di liberarla)
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntStoricoPartite);
        }
        else {//Altrimenti (se e` disattivo), fai scomparire lo storico partite e libera la memoria ad esso allocata
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
            free(PuntatoreMemoriaAllocata);
            PuntatoreMemoriaAllocata = NULL;
        }
        return;
    }
    //Questa sezione resetta lo stato del bottone ad essere disattivo se un'utente non loggato lo avesse cliccato per
    //poi portarlo alla schermata di registrazione/accesso
    gtk_toggle_button_set_active(tb,0);
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}


//Segnale che viene triggerato quando viene cliccato il bottone "Bilancio" sul menu` principale
void on_pg1BtnBilancio_clicked(GtkButton* b) {//Se l'utente e` loggato, passa alla schermata di gestione del bilancio
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
        return;
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}


//Segnale che viene triggerato cliccando il bottone "Accedi/Registrati" sul menu` principale
void on_pg1BtnAccedi_clicked(GtkButton* b) {//Cambia schermata a quella di registrazione/accesso
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}


//Segnale che viene triggerato quando viene cliccato il bottone "Opzioni" sul menu` principale avendo uno stato "attivo" e "disattivo"
void on_pg1BtnOpzioni_toggled(GtkToggleButton* tb) {
    //Se attivo, mostra le opzioni;
    //Se disattivo, nascondile
    gtk_toggle_button_get_active(tb) ? gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntOpzioniDifficolta) : gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
}

//=====================================================LABEL============================================================

//Segnale che viene attivato appena compare a schermo il label del nome utente nel menu` principale
void on_lblNomeUtente1_map(GtkLabel* lb) {//Aggiorna le statistiche di esso e degli altri label che lo necessitano
    if (UtenteLoggato != NULL) {//Prima di farlo controlla se l'utente sia loggato o meno in maniera tale da lasciare i valori default
        char StringaFormattata[BufferSnprintf];
        //Popola il nome utente
        gtk_label_set_text(lb, UtenteLoggato->nome);
        //Popola le partite giocate
        snprintf(StringaFormattata, BufferSnprintf,"%d", UtenteLoggato->partiteGiocate);
        gtk_label_set_text(GTK_LABEL(LblPartiteGiocate), StringaFormattata);
        StringaFormattata[0] = '\0';//Svuoto il contenuto della variabile per poterla riutilizzare
        //Popola la percentuale di vittoria
        CalcolaTassoVittoria();
        snprintf(StringaFormattata, BufferSnprintf, "%.2f%%", UtenteLoggato->percentualeVittoria);
        gtk_label_set_text(GTK_LABEL(LblTassoVittoria), StringaFormattata);
        free (PuntatoreMemoriaAllocata);
        PuntatoreMemoriaAllocata = NULL;
        StringaFormattata[0] = '\0';
        //Popola il bilancio
        snprintf(StringaFormattata, BufferSnprintf,"%d", UtenteLoggato->bilancio);
        gtk_label_set_text(GTK_LABEL(LblBilancioMenuPrincipale), StringaFormattata);
    }
}

//=====================================================MISC=============================================================

//Questi sono i bottoni che permettono di cambiare la difficolta'
void on_rdDiffNormale_clicked(GtkButton* b) {//Essa e` direttamente collegata al numero di mazzi dal quale pesca l'utente
    NumeroMazziGiocatore = 6;//Il dealer pesca sempre da 6 mazzi
}
void on_rdDiffFacile_clicked(GtkButton* b) {
    NumeroMazziGiocatore = 3;
}
void on_rdDiffDifficile_clicked(GtkButton* b) {
    NumeroMazziGiocatore = 9;
}
//Questo segnale viene triggerato quando appare a schermo la text entry dello storico partite
void on_txtStoricoPartite_map(GtkTextView* tw) {//Popola un array interno con solo le partite fatte dallo stesso utente loggato presenti nel file StoricoPartite

    //Sezione di inizializzazione
    StoricoPartitaT* StructArrayPartite = PopolaStoricoPartiteDalFile();//Crea la struct che conterra` i dati
    PuntatoreMemoriaAllocata = malloc(sizeof(*StructArrayPartite)*NumeroRighi);//Alloca la memoria in base alla dimensione dello struct (ovvero in base al numero di partite che ha estratto dal file)
    //Per poter manipolare le text entry in gtk serve creare un buffer di tipo GtkTextBuffer
    GtkTextBuffer* Buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tw));
    gtk_text_buffer_set_text(Buffer, "", -1);//Inizializza il buffer svuotandolo
    //Sempre per via di gtk va creato un "iteratore" per manipolare il testo. Esso e` come un cursore che scorre per il file
    GtkTextIter Iteratore;
    gtk_text_buffer_get_end_iter(Buffer, &Iteratore);//Bisogna comunicare al buffer da dove estrarre i dati letti

    //Qui imposto del testo per creare delle tab informative in cima all'entry
    gtk_text_buffer_insert(Buffer, &Iteratore, "Nome Utente ┃ Risultato Partita ┃ Crediti +/-\n", -1);
    gtk_text_buffer_insert(Buffer, &Iteratore, "\n", -1);

    //Infine scorro per il numero di righi presenti nel file, estraggo i contenuti in essi e li formatto in una stringa da poter poi far apparire a schermo
    for (int i = 0; i < NumeroRighi; i++) {
        char StringaFormattata[BufferSnprintf];
        //Estrazione e formattazione degli elementi
        snprintf(StringaFormattata, BufferSnprintf, "%s\t\t,\t%c\t,\t%d\n",StructArrayPartite[i].NomeUtente,StructArrayPartite[i].Risultato,StructArrayPartite[i].BilancioDiUscita);
        //Printa la stringa e va accapo
        gtk_text_buffer_insert(Buffer, &Iteratore, StringaFormattata, -1);
    }
}
//######################################################################################################################
//#############################################SCHERMATA GESTIONE BILANCIO##############################################
//######################################################################################################################
//=====================================================BOTTONI==========================================================

//Funzine che gestisce il cambio scena facendo tornare indietro al menu principale dalla pagina di gestione bilancio
void on_pg2BtnEsci_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}
//Questi segnali vengono triggerati quando l'utente clicca sui rispettivi bottoni per aggiungere crediti al proprio bilancio
void on_pg2BtnAgg100_clicked(GtkButton* b) {//Aggiunge direttamente la rispettiva quantita` di crediti al bilancio
    UtenteLoggato->bilancio += 100;//In seguito aggiorna il label per mostrarla in tempo reale
    char StringaConvertita[BufferSnprintf];
    snprintf(StringaConvertita, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), StringaConvertita);
}
void on_pg2BtnAgg200_clicked(GtkButton* b) {
    UtenteLoggato->bilancio += 200;
    char StringaConvertita[BufferSnprintf];
    snprintf(StringaConvertita, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), StringaConvertita);
}
void on_pg2BtnAgg500_clicked(GtkButton* b) {
    UtenteLoggato->bilancio += 500;
    char StringaConvertita[BufferSnprintf];
    snprintf(StringaConvertita, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), StringaConvertita);
}
void on_pg2BtnAgg1000_clicked(GtkButton* b) {
    UtenteLoggato->bilancio += 1000;
    char StringaConvertita[BufferSnprintf];
    snprintf(StringaConvertita, BufferSnprintf, "%d", UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), StringaConvertita);
}

//=====================================================LABEL============================================================

//Questa segue la stessa e identica logica ma per i label nella schermata di gestione del bilancio
void on_lblNomeUtente2_map(GtkLabel* lb) {//Solo che non controlla se l'utente sia loggato o meno in quanto sia impossibile accedere alla schermata se non lo e`
    char StringaFormattata[BufferSnprintf];
    //Popola il nome utente
    gtk_label_set_text(lb, UtenteLoggato->nome);
    //Popola il contatore del bilancio
    snprintf(StringaFormattata, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(lb, StringaFormattata);
}

//######################################################################################################################
//##############################################SCHERMATA MENU` PAUSA###################################################
//######################################################################################################################
//=====================================================BOTTONI==========================================================

void on_pg4BtnPausa_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPausa);
}


void on_pg5BtnRiprendi_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
}

void on_pg5BtnTornaAlMenu_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaHome);
}

void on_pg5BtnAnnulla1_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}

void on_pg5BtnConferma1_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
    gtk_widget_hide(BtnFinePartitaEsci);
    gtk_label_set_text(GTK_LABEL(LblPartitaPersa), NULL);
    gtk_label_set_text(GTK_LABEL(LblPartitaVinta), NULL);
}

void on_pg5BtnChiudiGioco_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaQuit);
}
void on_pg5BtnAnnulla2_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
void on_pg5BtnConferma2_clicked(GtkButton* b){
    gtk_main_quit();
}
//######################################################################################################################
//##############################################SCHERMATA DI GIOCO######################################################
//######################################################################################################################
//=====================================================LABEL============================================================

//Questa invece inizializza i label per il contatore del valore della mano
void on_lblValoreManoGiocatore_map(GtkLabel* lb) {//Controlla se la difficolta` sia impostata su facile
    if (NumeroMazziGiocatore == 3) {//Se si`, inizializza i label
        gtk_label_set_text(lb, "Valore: 0");
        gtk_label_set_text(GTK_LABEL(LblValoreManoBanco), "Valore: 0");
    }else{//Altrimenti li svuota (serve in caso si faccia una partita con una difficolta` diversa dopo aver giocato in facile)
        gtk_label_set_text(lb, NULL);
        gtk_label_set_text(GTK_LABEL(LblValoreManoBanco), NULL);
    }
}

//Questa popola solo il nome utente sulla schermata di gioco in quanto sia l'unico label a necessitarlo
void on_lblNomeUtente3_map(GtkLabel* lb){
    gtk_label_set_text(lb, UtenteLoggato->nome);
}
//######################################################################################################################
//##############################################SCHERMATA DI ACCESSO####################################################
//######################################################################################################################
//=====================================================BOTTONI==========================================================

//Funzione che gestisce il cambio scena facendo tornare indietro al menu principale dalla pagina di registrazione/accesso
void on_pg3BtnEsci_clicked(GtkButton* b) {
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), NULL);
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
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

//=====================================================MISC=============================================================


void MemorizzaDatiAccesso(GtkEntry *e) {
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


//######################################################################################################################
//##############################################GESTIONE COMPLETA PARTITA###############################################
//######################################################################################################################

void on_ConfermaScommessa_clicked(GtkButton* b){
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntVuotoOpzioniPuntata);
    gtk_widget_hide(BtnConfermaPuntata);

    InitRand();
    PescaGiocatore(2);
    PescaBanco(2);

    if (NumeroMazziGiocatore > 3){
        LogicaCartaCoperta();
    }

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
            gtk_widget_show(BtnConfermaPuntata);
            gtk_widget_show(BtnMenuPausa);
            gtk_widget_hide(BtnFinisciTurno);
            ResettaValoriGlobali();
            AggiornaStatistichePartita();
            InitArrImmagini(ImgCartaBanco1,ImgCartaBanco2,ImgCartaBanco3, ImgCartaBanco4, ImgCartaBanco5, ImgCartaBanco6, ImgCartaGiocatore1, ImgCartaGiocatore2, ImgCartaGiocatore3, ImgCartaGiocatore4, ImgCartaGiocatore5, ImgCartaGiocatore6, ImgCartaGiocatore7, ImgCartaGiocatore8);
            AggiornaAmbiMani();
            return;
        }
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
        gtk_label_set_text(GTK_LABEL(LblErroreAggiungiCrediti), "Non hai abbastanza crediti per giocare! \n\t\tAggiungine un po'!");
        return;
    }
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}

void TurnoBanco() {
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);

    if (NumeroMazziGiocatore > 3){
        LogicaCartaCoperta();
    }

    BancoPescaRipetuta();

    AggiornaStatistichePartita();

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
    gtk_widget_hide(BtnMenuPausa);
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
    gtk_widget_show(BtnFinisciTurno);
    PescaGiocatore(1);
    AggiornaManoGiocatore();
    AggiornaStatistichePartita();
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntSecondaPesca);
    //mostra bottone finisci turno

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


