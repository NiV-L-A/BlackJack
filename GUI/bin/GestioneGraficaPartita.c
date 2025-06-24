#include <gtk/gtk.h>
#include <string.h>
#include "main.h"

//Array di tipo GtkImage che conterranno le reference ai widget immagine usati per il display delle carte
GtkImage* ArrImmaginiGiocatore[MAXcarteGiocatore];
GtkImage* ArrImmaginiBanco[MAXcarteBanco];


//Funzione generica che si occupa di fare il draw di una singola immagine
void RenderizzaCarta(GtkImage *immagine, int idCarta) {//Se lo slot nell'array mano e` vuoto, rimuove la sprite da quello slot nel programma
    if (idCarta == SlotVuoto) {
        gtk_image_clear(immagine);
    } else {
        //Setta il la sprite con il percorso in cui trovarla
        char PercorsoSprite[256];
        snprintf(PercorsoSprite, sizeof(PercorsoSprite), "GUI/SpriteCarte/%d.png", idCarta);
        gtk_image_set_from_file(immagine, PercorsoSprite);
    }
}

//Funzioni principali per aggiornare individualmente la mano del giocatore o del dealer
void AggiornaManoGiocatore() {
    for (int i = 0; i < MAXcarteGiocatore; i++) {
        RenderizzaCarta(ArrImmaginiGiocatore[i], ManoGiocatore[i]);
    }
}
void AggiornaManoBanco() {
    for (int i = 0; i < MAXcarteBanco; i++) {
        RenderizzaCarta(ArrImmaginiBanco[i], ManoBanco[i]);
    }
}
//Funzione aggiuntiva per aggiornarle entrambe
void AggiornaAmbiMani() {
    AggiornaManoGiocatore();
    AggiornaManoBanco();
}

//Funzione che inizializza il processo di rendering prendendo le reference dai widget immagini
void InitRenderingCarte(GtkBuilder *Builder) {
    char NomeWidget[32];
    for (int i = 0; i < MAXcarteGiocatore; i++) {//Sezione che prende quelle del giocatore
        snprintf(NomeWidget, sizeof(NomeWidget), "imgCartaGiocatore%d", i + 1);
        ArrImmaginiGiocatore[i] = GTK_IMAGE(gtk_builder_get_object(Builder, NomeWidget));
    }
    NomeWidget[0] = '\0';//Clear di nomewdiget per poterla riutilizzare

    for (int i = 0; i < MAXcarteBanco; i++) {//Sezione che prende quelle del banco
        snprintf(NomeWidget, sizeof(NomeWidget), "imgCartaBanco%d", i + 1);
        ArrImmaginiBanco[i] = GTK_IMAGE(gtk_builder_get_object(Builder, NomeWidget));
    }
}

//Funzione generale che aggiorna le statistiche visibili durante la partita
void AggiornaStatistichePartita() {
    char Temp[BufferSnprintf];
    //Bilancio e puntata
    snprintf(Temp, BufferSnprintf, "%d",UtenteLoggato->bilancio);
    gtk_label_set_text(GTK_LABEL(LblBilancio3), Temp);
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