#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "../../main.h"

//-----------------------------------------------SEZIONE PUNTATORI ELEMENTI---------------------------------------------
//        GTK necessita la creazione di dei puntatori globali ai quali piu` avanti verranno associati gli elementi
//                                 dell'interfaccia per tutto cio` che si vuole manipolare.
//----------------------------------------------------------------------------------------------------------------------
//======================================================TOP LEVEL=======================================================
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
//========================================================LABEL=========================================================
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
GtkWidget* LblNumeroVittorie;
//========================================================BOTTONI=======================================================
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
//=====================================================IMMAGINI=========================================================
GtkImage* ImgCartaBanco1, *ImgCartaBanco2, *ImgCartaBanco3, *ImgCartaBanco4, *ImgCartaBanco5, *ImgCartaBanco6;
GtkImage* ImgCartaGiocatore1, *ImgCartaGiocatore2, *ImgCartaGiocatore3, *ImgCartaGiocatore4, *ImgCartaGiocatore5, *ImgCartaGiocatore6, *ImgCartaGiocatore7, *ImgCartaGiocatore8;
//=======================================================MISC===========================================================
GtkBuilder* Builder;
GtkWidget* TxtStoricoPartite;
GtkWidget* EntNomeUtente1;
GtkWidget* EntPassword1;
GtkWidget* EntNomeUtente2;
GtkWidget* EntPassword2;
GtkWidget* RdioDiffNormale;
GtkWidget* RdioDiffFacile;
GtkWidget* RdioDiffDifficile;
GtkWidget* TxtStoricoPartite;


int InitProgramma(int argc, char *argv[]) {//funzione principale che gestisce la creazione della finestra ed i suoi handle

    gtk_init(&argc, &argv); //Funzione che inizializza tutta la parte dell'ui

    Builder = gtk_builder_new_from_file("GUI/bin/GUI.glade");//Dico al builder dove trovare il file GLADE per leggere gli elementi
    //Estraggo dal builder in maniera separata la finestra in quanto sia importante associarle da subito il segnale quit.
    Finestra = GTK_WIDGET(gtk_builder_get_object(Builder, "finestra"));
    g_signal_connect(Finestra, "destroy", G_CALLBACK(gtk_main_quit), NULL);//Associazione del segnale menzionata prima

    //Adesso creo una table di tutti i segnali per le funzioni CallBack
    gtk_builder_connect_signals(Builder, NULL);

//-----------------------------------------SEZIONE COLLEGAMENTO OGGETTI-------------------------------------------------
//  Qui vado ad associare ad ogni puntatore globale il suo rispettivo elemento estraendolo dal builder; Cosi` facendo
//                                         esso diventera` manipolabile.
//----------------------------------------------------------------------------------------------------------------------
//===================================================TOP LEVEL==========================================================
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
//=================================================LABEL================================================================
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
    LblNumeroVittorie = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNumeroVittorie"));
//=================================================BOTTONI==============================================================
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
//=================================================IMMAGINI=============================================================
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
//====================================================MISC==============================================================
    TxtStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "txtStoricoPartite"));
    EntNomeUtente1 = GTK_WIDGET(gtk_builder_get_object(Builder, "entNomeUtente1"));
    EntNomeUtente2 = GTK_WIDGET(gtk_builder_get_object(Builder, "entNomeUtente2"));
    EntPassword1 = GTK_WIDGET(gtk_builder_get_object(Builder, "entPassword1"));
    EntPassword2 = GTK_WIDGET(gtk_builder_get_object(Builder, "entPassword2"));
    RdioDiffNormale = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffNormale"));
    RdioDiffDifficile = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffDifficile"));
    RdioDiffFacile = GTK_WIDGET(gtk_builder_get_object(Builder, "rdDiffFacile"));
    TxtStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "txtStoricoPartite"));

//-------------------------------------------MANIPOLAZIONE E GESTIONE FINESTRA------------------------------------------
//=========================================================COLORE=======================================================
    //Comincio col creare una variabile di tipo GdkRGBA per poi assegnarle dei valori
    GdkRGBA ColoreBG;//per convertire un valore da RGBA a GDKRGBA basta dividere quelli rgb per 255.
    ColoreBG.red = 0.0;
    ColoreBG.green = 0.50196;
    ColoreBG.blue = 0.16471;
    ColoreBG.alpha = 1.0;
    gtk_widget_override_background_color(Finestra, GTK_STATE_FLAG_NORMAL, &ColoreBG);//Con questa setto il colore del bg ai dati inseriti in ColoreBG

//-------------------------------------------------INVOCAZIONE FINESTRA-------------------------------------------------
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


//----------------------------------------------FUNZIONI CALLBACK-------------------------------------------------------
//                      Qui vengono gestiti i segnali di ogni widget e vi si assegna un metodo.
//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                           SCHERMATA MENU PRINCIPALE                                                ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//=====================================================BOTTONI==========================================================


//Segnale che viene triggerato quando viene cliccato il bottone "Storico Partite" sul menu` principale avendo uno stato
//"attivo" e "disattivo"
void on_pg1TBtnStorico_toggled(GtkToggleButton* tb) {//Se l'utente e` loggato ed il bottone e` stato schiacciato, mostra a schermo lo storico partite
    if (UtenteLoggato != NULL) {//Altrimenti, porta l'utente sulla pagina di registrazione/accesso

        //Controllo lo stato del bottone switchando da uno stato all'altro
        if (gtk_toggle_button_get_active(tb)) {//Se stato = attivo, mostra lo storico partite
            //La logica della popolazione dello storico e` gestita dal segnale "Map" per assicurarsi che venga eseguita
            //Solo quando e` visibile a schermo, non quando viene cliccato il bottone (in quanto potrebbe farlo un
            //utente non loggato aggiungendo overhead innecessario)
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntStoricoPartite);
        }
        else {//Altrimenti (se e` disattivo), fai scomparire lo storico partite e libera la memoria ad esso allocata
            gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
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
        StringaFormattata[0] = '\0';
        //Popola il bilancio
        snprintf(StringaFormattata, BufferSnprintf,"%d", UtenteLoggato->bilancio);
        gtk_label_set_text(GTK_LABEL(LblBilancioMenuPrincipale), StringaFormattata);
        StringaFormattata[0] = '\0';
        //Calcola numero di vittorie e popola quello
        float PartiteGiocate = UtenteLoggato->partiteGiocate;
        float TassoVittoria = UtenteLoggato->percentualeVittoria;
        float Risultato = (PartiteGiocate / 100) * TassoVittoria;
        snprintf(StringaFormattata, BufferSnprintf,"%.0f", Risultato);
        gtk_label_set_text(GTK_LABEL(LblNumeroVittorie), StringaFormattata);
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
    free(StructArrayPartite);
    StructArrayPartite = NULL;
}


//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                          SCHERMATA GESTIONE BILANCIO                                               ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//=====================================================BOTTONI==========================================================


//Funzione che gestisce il cambio scena facendo tornare indietro al menu principale dalla pagina di gestione bilancio
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
    gtk_label_set_text(GTK_LABEL(LblBilancioGestioneBilancio), StringaFormattata);
}


//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                             SCHERMATA MENU PAUSA                                                   ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//=====================================================BOTTONI==========================================================


//Segnale del bottone principale per pausare
void on_pg4BtnPausa_clicked(GtkButton* b) {//Cambia la scena al menu pausa
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPausa);
}

//Segnale del bottone "Riprendi" nel menu pausa
void on_pg5BtnRiprendi_clicked(GtkButton* b) {//Riporta il gioco nella partita
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
}

//Segnale del bottone iniziale per tornare al menu principale
void on_pg5BtnTornaAlMenu_clicked(GtkButton* b) {//Cambia la scena in una schermata di conferma informando l'utente che non sia possibile riprenderla
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaHome);
}

//Segnale del bottone "No" nella schermata di conferma per tornare al menu` principale
void on_pg5BtnAnnulla1_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}

//Segnale del bottone "Si' nella schermata di conferma per tornare al menu` principale
void on_pg5BtnConferma1_clicked(GtkButton* b) {
    //Cambia la scena al menu` principlale, nasconde le opzioni giocatore per la seguente partita, nasconde il bottone
    //di fine partita e resetta i label che informano l'utente del risultato della partita
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
    gtk_widget_hide(BtnFinePartitaEsci);
    gtk_label_set_text(GTK_LABEL(LblPartitaPersa), NULL);
    gtk_label_set_text(GTK_LABEL(LblPartitaVinta), NULL);
}

//Segnale del bottone iniziale per chiudere il gioco
void on_pg5BtnChiudiGioco_clicked(GtkButton* b) {//In seguito ad essere cliccato porta l'utente sulla stessa schermata di conferma
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntMenuConfermaQuit);
}

//Queste seguono la stessa logica di quelle per tornare al menu` principale
void on_pg5BtnAnnulla2_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(StkMenuPausa), CntOpzioniPausa);
}
void on_pg5BtnConferma2_clicked(GtkButton* b) {//Solo che questa invoca gtk_main_quit per chiudere il programma
    gtk_main_quit();
}


//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                             SCHERMATA DI GIOCO                                                     ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
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
void on_lblNomeUtente3_map(GtkLabel* lb) {
    gtk_label_set_text(lb, UtenteLoggato->nome);
}

//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                             SCHERMATA DI ACCESSO                                                   ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//=====================================================BOTTONI==========================================================


//Segnale triggerato dal bottone "Esci" nella pagina di registrazione/accesso
void on_pg3BtnEsci_clicked(GtkButton* b) {
    //Fa tornare l'utente al menu` principale e resetta qualsiasi eventuale notifica di errore in essa presente
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), NULL);
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}


//Segnale triggerato dal bottone "Accedi" nella schermata di accesso
void on_pg3BtnAccedi_clicked(GtkButton* b) {
    int Conta = 0;
    //Vengono create e popolate delle variabili temporanee con il testo contenuto nelle loro rispettive entry
    char* NomeUtente = gtk_entry_get_text(GTK_ENTRY(EntNomeUtente1));
    char* Password = gtk_entry_get_text(GTK_ENTRY(EntPassword1));
    //In seguito viene passata come argument a ValidaStringa
    if (ValidaStringa(NomeUtente) == 0) {//Se il nome utente e` valido ed esiste nel file, va avanti nella funzione
        //Altrimenti, metti a schermo un errore informandolo che esso non sia valido
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tNome utente invalido!\n \t\t Riprovare");
        return;
    }

    //Stessa logica della funzione sopra ma per la password
    if (ValidaStringa(Password) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tPassword invalida!\n \t\t Riprovare");
        return;
    }

    //Se sia nome che password sono validi, creiamo un array di tipo UtenteT e lo popoliamo con tutti gli utenti nel file
    UtenteT* UtentiNelFile = GetUtentiDalFile(&Conta);
    //Se UtentiNelFile e` NULL e Conta e` 0, allora non siamo riusciti a leggere gli utenti
    if (UtentiNelFile == NULL && Conta == 0) {//Quindi mettiamo a schermo l'errore
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente inesistente!\n \t\t Riprovare");
        return;
    }

    //Altrimenti se siamo riusciti a leggere gli utenti nel file ma non ne abbiamo trovato nessuno che corrispondesse ai
    //dati inseriti dall'utente, mettiamo a schermo l'errore avvisandolo che esso non esista
    if (LoggaUtente(NomeUtente, Password, UtentiNelFile, Conta) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente inesistente!\n \t\t Riprovare");
        return;
    }

    //Se siamo arrivati qui, l'utente è loggato
    //Quindi riportiamo l'utente al menu` principale
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}


//Segnale triggerato dal bottone "Registrati" nella schermata di accesso
void on_pg3BtnRegistrati_clicked(GtkButton* b) {
    //Come nel caso di Accedi, andiamo a creare delle variabili temporanee e a popolarle con il testo contenuto nelle
    //loro rispettive entry
    char* NomeUtente = gtk_entry_get_text(GTK_ENTRY(EntNomeUtente2));
    char* Password = gtk_entry_get_text(GTK_ENTRY(EntPassword2));
    //Per poi procedere a controllare se siano valide o meno
    if (ValidaStringa(NomeUtente) == 0) {//Riportando un errore nel caso non lo fossero
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tNome utente invalido!\n \t\t Riprovare");
        return;
    }

    if (ValidaStringa(Password) == 0) {
        gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tPassword invalida!\n \t\t Riprovare");
        return;
    }

    //Arrivati qui i dettagli inseriti sono validi, quindi procediamo con la creazione dell'utente
    //generando un ID casuale ed inizializzando le sue statistiche con dei valori default
    UtenteT Utente;
    Utente.id = rand() % 1000;
    snprintf(Utente.nome, sizeof(Utente.nome), NomeUtente);
    snprintf(Utente.password, sizeof(Utente.password), Password);
    Utente.bilancio = 500;
    Utente.percentualeVittoria = 0;
    Utente.partiteGiocate = 0;

    //Infine controlliamo se ci sono stati errori nel registrarlo
    if (RegistraUtente(Utente) == 0) {
        return;
    }

    //Se non ci sono stati problemi, notifichiamo la sua registrazione e portiamo il giocatore sul campo di accesso
    //per effettuare il login
    gtk_label_set_text(GTK_LABEL(LblNotificaErroreAccesso), "\tUtente registrato! \n\t\t Accedere");
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniAccesso), CntAccesso);
}

//=====================================================MISC=============================================================

//Le funzioni qua sotto servono ad estrapolare il testo contenuto nelle text entry e a formattarlo, imponendo un limite
//di caratteri
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


//----------------------------------------------------------------------------------------------------------------------
//┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//┃                                           GESTIONE COMPLETA PARTITA                                                ┃
//┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//----------------------------------------------------------------------------------------------------------------------


//Segnale del bottone "Conferma Puntata"
void on_ConfermaScommessa_clicked(GtkButton* b) {//Agisce come un modo di passare il turno ed inizializza la partita
    //Per prima cosa nasconde le opzioni di puntata solo se essa e` stata gia` fatta
    if (Puntata != 0) {
        gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntVuotoOpzioniPuntata);
        gtk_widget_hide(BtnConfermaPuntata);
    }else {//Altrimenti informa l'utente che debba ancora
        gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Devi ancora puntare!");
        return;
    }

    //Tolte le opzioni per puntare seeddiamo rand e peschiamo le prime due carte per entrambi
    InitRand();
    PescaGiocatore(2);
    PescaBanco(2);
    //In seguito controlliamo la difficolta`
    if (NumeroMazziGiocatore > 3) {//Se e` impostata su normale o difficile, nascondiamo la seconda carta del dealer
        LogicaCartaCoperta();
    }//Altrimenti se e` impostata su facile la lasciamo scoperta

    //Dopo aver pescato aggiorniamo entrambe le mani sullo schermo facendo comparire le loro carte
    //ed aggiorniamo le statistiche a schermo
    AggiornaAmbiMani();
    AggiornaStatistichePartita();

    //Ed in fine diamo la possibilita` al giocatore di scegliere un'opzione
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntBtnOpzioniGiocatore);
}


//Segnale triggerato quando viene premuto il bottone "Gioca" nella schermata principale
void on_pg1BtnGioca_clicked(GtkButton* b) {//Se l'utente e` loggato, controlla se abbia abbastanza crediti per fare almeno una puntata minima
    if (UtenteLoggato != NULL) {//Se esso e` loggato ed ha abbastanza crediti, viene inizializzata la partita
        if (UtenteLoggato->bilancio >= 50) {//Se non ha abbastanza crediti, viene portato sulla pagina di gestione del bilancio e promptato di aggiungerne un po'
            //Come prima cosa cambiamo la scena al tavolo di gioco e tiriamo fuori le opzioni per puntare
            gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
            gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntBtnOpzioniPuntata);
            //Poi facciamo comparire il tasto per confermare la puntata, quello per mettere in pausa e nascondiamo quello per finire il turno
            gtk_widget_show(BtnConfermaPuntata);
            gtk_widget_show(BtnMenuPausa);
            gtk_widget_hide(BtnFinisciTurno);
            //Poi resettiamo il valore delle variabili globali ed aggiorniamo le statistiche della partita
            ResettaValoriGlobali();
            AggiornaStatistichePartita();
            //In fine passo alla funzione InitArrImmagini tutti i contenitori per le sprite delle carte ed aggiorno
            //le mani rimuovendo carte rimaste dalla partita precedente
            InitArrImmagini(ImgCartaBanco1,ImgCartaBanco2,ImgCartaBanco3, ImgCartaBanco4, ImgCartaBanco5, ImgCartaBanco6, ImgCartaGiocatore1, ImgCartaGiocatore2, ImgCartaGiocatore3, ImgCartaGiocatore4, ImgCartaGiocatore5, ImgCartaGiocatore6, ImgCartaGiocatore7, ImgCartaGiocatore8);
            AggiornaAmbiMani();
            return;
        }
        //L'utente e` loggato ma non ha abbastanza crediti quindi lo portiamo alla schermata di gestione del bilancio
        //e lo informiamo della cosa
        gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
        gtk_label_set_text(GTK_LABEL(LblErroreAggiungiCrediti), "Non hai abbastanza crediti per giocare! \n\t\tAggiungine un po'!");
        return;
    }
    //L'utente non e` loggato quindi lo portiamo alla schermata di accesso
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}


//Funzione generica che viene chiamata in seguito alle decisioni del giocatore, passando il turno al banco e terminando la partita
void TurnoBanco() {
    //Come prima cosa nascondiamo le opzioni del giocatore
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);

    //Poi chiamiamo la funzione LogicaCartaCoperta per scoprire la seconda
    if (NumeroMazziGiocatore > 3) {//Tranne nel caso in cui la difficolta` sia impostata su facile in quanto non ce ne sia bisogno
        LogicaCartaCoperta();
    }
    //Poi triggeriamo la pesca multipla del banco per poi aggiornare le statistiche della partita
    BancoPescaRipetuta();
    AggiornaStatistichePartita();


    //Ed una volta fatto, chiamiamo ControllaVittoria e verifichiamo il risultato della partita
    char StringaFormattata[BufferSnprintf];
    switch (ControllaVittoria()) {
    case 'B'://Blackjack
        snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita con un BlackJack \n\t guadagnando  %.0f crediti!", Puntata * 2.5);
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
        break;
    case 'V'://Vittoria semplice
        snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita guadagnando \n\t\t %d crediti!", Puntata*2);
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
        break;
    case 'P'://Pareggio
        gtk_label_set_text(GTK_LABEL(LblPartitaVinta), "Hai pareggiato la partita! \n\t Non ci sono conseguenze!");
        break;
    case 'S'://Sconfitta
        snprintf(StringaFormattata, BufferSnprintf, "Hai perso la partita rimettendoci \n\t\t %d crediti!", Puntata);
        gtk_label_set_text(GTK_LABEL(LblPartitaPersa), StringaFormattata);
        break;
    }
    //Una volta terminata la partita ripuliamo qualsiasi eventuale errore rimasto a schermo,
    //nascondiamo il bottone per mettere in pausa e mostriamo quello per uscire dalla partita
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), NULL);
    gtk_widget_hide(BtnMenuPausa);
    gtk_widget_show(BtnFinePartitaEsci);
}


//Segnale del bottone "Finisci turno" che compare in caso il giocatore faccia un'azione reiterata come il pescare
void on_FinisciTurno_clicked(GtkButton* b) {
    //Una volta cliccato nasconde il bottone stesso, chiama la logica assi per assicurarsi che le carte abbiano il valore
    //piu` ottimale e passa il turno al banco
    gtk_widget_hide(BtnFinisciTurno);
    LogicaAssi(ManoGiocatore, MAXcarteGiocatore);
    TurnoBanco();
}


//Handler opzioni giocatore
void on_pg4BtnRaddoppia_clicked(GtkButton* b) {//Il giocatore ha deciso di raddoppiare
    //Invoca funzione raddoppia e controlla se sia possibile farlo
    if (Raddoppia()) {
        //Se si, aggiorna le statistiche della partita, la mano del giocatore e passa il turno al banco
        AggiornaStatistichePartita();
        AggiornaManoGiocatore();
        TurnoBanco();
    }else {//Altrimenti informa l'utente del fatto che non abbia abbastanza crediti per raddoppiare la sua puntata
        gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
    }
}


//Segnale del primo bottone pesca
void on_pg4BtnPesca_clicked(GtkButton* b) {
    //Ripulisce eventuali errori rimasti a schermo
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), NULL);
    //Per poi mostrare il bottone per finire il turno,
    gtk_widget_show(BtnFinisciTurno);
    PescaGiocatore(1);//Pescare una carta al giocatore,
    AggiornaManoGiocatore();//Aggiornare la sua mano,
    AggiornaStatistichePartita();//Aggiornare le statistiche partita
    //e in fine mostrare il bottone per la seconda pesca (togliendo la possibilita` di fare altre azioni)
    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntSecondaPesca);
}


//Segnale del secondo bottone della pesca
void on_pg4BtnPesca2_clicked(GtkButton* b) {
    //Controlla se il giocatore possa ancora pescare
    if (PescaGiocatore(1)) {//Se si, aggiorna la sua mano e le statistiche partita
        AggiornaManoGiocatore();
        AggiornaStatistichePartita();
    } else {//Altrimenti informa il giocatore di non poter piu` pescare per poi nascondere il bottone finisci turno e passa a quello del banco
        gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Hai raggiunto il limite di carte!");
        gtk_widget_hide(BtnFinisciTurno);
        TurnoBanco();
    }
}


//Queste funzioni gestiscono i bottoni che permettono di fare una puntata durante la partita
void on_pg4BtnP50_clicked(GtkButton* b) {//Se il bilancio dell'utente - la somma puntata e` maggiore o uguale a 0, punta quella somma e aggiorna la statistica "bilancio"
    if (UtenteLoggato->bilancio - 50 >= 0) {//Altrimenti mostra un errore informando l'utente che non abbia abbastanza crediti
        Puntata += 50;
        UtenteLoggato->bilancio -= 50;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP100_clicked(GtkButton* b) {

    if (UtenteLoggato->bilancio - 100 >= 0) {
        Puntata += 100;
        UtenteLoggato->bilancio -= 100;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP250_clicked(GtkButton* b) {

    if (UtenteLoggato->bilancio - 250 >= 0) {
        Puntata += 250;
        UtenteLoggato->bilancio -= 250;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
void on_pg4BtnP500_clicked(GtkButton* b) {

    if (UtenteLoggato->bilancio - 500 >= 0) {
        Puntata += 500;
        UtenteLoggato->bilancio -= 500;
        AggiornaStatistichePartita();
        return;
    }
    gtk_label_set_text(GTK_LABEL(LblErrorePartita), "Non hai abbastanza crediti!");
}
