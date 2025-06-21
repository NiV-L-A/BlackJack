#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
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
//================================LABEL===========================
GtkWidget* LblNomeUtente;
GtkWidget* LblPartiteGiocate;
GtkWidget* LblTassoVittoria;
GtkWidget* LblBilancio;
//================================BOTTONI=========================
GtkWidget* BtnGioca;
GtkWidget* BtnAccedi;
GtkWidget* BtnStorico;
GtkWidget* BtnBilancio;
GtkWidget* BtnEsci;
GtkWidget* BtnEsci2;
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
//====================TOP LEVEL==================
    ControlloScena = GTK_WIDGET(gtk_builder_get_object(Builder, "controlloScena"));
    CntMenuPrincipale = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuPrincipale"));
    StkStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "stkStoricoPartite"));
    CntStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "cntStoricoPartite"));
    CntVuotoStoricoPartite = GTK_WIDGET(gtk_builder_get_object(Builder, "cntVuotoStoricoPartite"));
    CntGestioneBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "cntGestioneBilancio"));
    CntMenuAccesso = GTK_WIDGET(gtk_builder_get_object(Builder, "cntMenuAccesso"));
//=====================LABEL=====================
    LblNomeUtente = GTK_WIDGET(gtk_builder_get_object(Builder, "lblNomeUtente1"));
    LblPartiteGiocate = GTK_WIDGET(gtk_builder_get_object(Builder, "lblPartiteGiocate"));
    LblTassoVittoria = GTK_WIDGET(gtk_builder_get_object(Builder, "lblTassoVittoria"));
    LblBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "lblBilancio"));
//=====================BOTTONI===================
    BtnGioca = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnGioca"));
    BtnAccedi = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnAccedi"));
    BtnStorico = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1TBtnStorico"));
    BtnBilancio = GTK_WIDGET(gtk_builder_get_object(Builder, "pg1BtnBilancio"));
    BtnEsci = GTK_WIDGET(gtk_builder_get_object(Builder, "pg2BtnEsci"));
    BtnEsci2 = GTK_WIDGET(gtk_builder_get_object(Builder, "pg3BtnEsci"));
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
    gtk_widget_override_background_color(Finestra, GTK_STATE_FLAG_NORMAL, &ColoreBG);

//===================INVOCAZIONE===============
    gtk_widget_show(Finestra);//Mostra la finestra

    gtk_main();//Avvia il processo main che rimarra` nel background a controllare gli input ricevuti

    return EXIT_SUCCESS;//Condizione di uscita necessaria per chiudere il programma una volta chiusa l'ui
}
//---------------------------------------------FUNZIONI CALLBACK--------------------------------------------------------
//===================BOTTONI===================
void on_pg1TBtnStorico_toggled(GtkToggleButton* tb) {
    gtk_toggle_button_get_active(tb) ? gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntStoricoPartite) : gtk_stack_set_visible_child(GTK_STACK(StkStoricoPartite), CntVuotoStoricoPartite);
}
void on_pg1BtnBilancio_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntGestioneBilancio);
}
void on_pg1BtnAccedi_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuAccesso);
}
void on_pg2BtnEsci_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
}
void on_pg3BtnEsci_clicked(GtkButton* b) {
    gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
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















