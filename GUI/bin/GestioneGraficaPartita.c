#include <gtk/gtk.h>
#include <string.h>
#include "main.h"

//Array di tipo GtkImage che conterranno le reference ai widget immagine usati per il display delle carte
GtkImage* ArrImmaginiGiocatore[MAXcarteGiocatore];
GtkImage* ArrImmaginiBanco[MAXcarteBanco];

//Funzione che inizializza gli array contenenti i puntantori ai widget immagine da manipolare
void InitArrImmagini(GtkImage* ImgCartaBanco1,GtkImage* ImgCartaBanco2,GtkImage* ImgCartaBanco3,GtkImage* ImgCartaBanco4,GtkImage* ImgCartaBanco5,GtkImage* ImgCartaBanco6,GtkImage* ImgCartaGiocatore1,GtkImage* ImgCartaGiocatore2,GtkImage* ImgCartaGiocatore3,GtkImage* ImgCartaGiocatore4,GtkImage* ImgCartaGiocatore5,GtkImage* ImgCartaGiocatore6,GtkImage* ImgCartaGiocatore7,GtkImage* ImgCartaGiocatore8) {
    //Carte giocatore
    ArrImmaginiGiocatore[0] = ImgCartaGiocatore1;
    ArrImmaginiGiocatore[1] = ImgCartaGiocatore2;
    ArrImmaginiGiocatore[2] = ImgCartaGiocatore3;
    ArrImmaginiGiocatore[3] = ImgCartaGiocatore4;
    ArrImmaginiGiocatore[4] = ImgCartaGiocatore5;
    ArrImmaginiGiocatore[5] = ImgCartaGiocatore6;
    ArrImmaginiGiocatore[6] = ImgCartaGiocatore7;
    ArrImmaginiGiocatore[7] = ImgCartaGiocatore8;
    //Carte banco
    ArrImmaginiBanco[0] = ImgCartaBanco1;
    ArrImmaginiBanco[1] = ImgCartaBanco2;
    ArrImmaginiBanco[2] = ImgCartaBanco3;
    ArrImmaginiBanco[3] = ImgCartaBanco4;
    ArrImmaginiBanco[4] = ImgCartaBanco5;
    ArrImmaginiBanco[5] = ImgCartaBanco6;
}

//Funzione generica che si occupa di fare il draw di una singola immagine
void RenderizzaCarta(GtkImage *immagine, unsigned short idCarta) {//Se lo slot nell'array mano e` vuoto, rimuove la sprite da quello slot nel programma
    if (idCarta > 134){
        idCarta -= 130;
    }
    if (idCarta == SlotVuoto) {
        gtk_image_set_from_file(immagine, "GUI/SpriteMenu/ImmagineVuota.png");
        return;
    }
    //Setta il la sprite con il percorso in cui trovarla
    char PercorsoSprite[256];
    snprintf(PercorsoSprite, sizeof(PercorsoSprite), "GUI/SpriteCarte/%d.png", idCarta);
    gtk_image_set_from_file(immagine, PercorsoSprite);

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