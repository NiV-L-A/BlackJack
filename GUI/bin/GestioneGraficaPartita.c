#include <gtk/gtk.h>
#include <string.h>
#include "../../main.h"

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


//Funzione che estrae i dati del widget immagine che gli viene passato per poter validare la texture in esso contenuta
gchar* PrendiNomeTextureDaImmagine(GtkImage* immagine) {
    GValue ValoreTemp = G_VALUE_INIT;//In primis va creata una variabile contenitore per i dati GOobject del widget

    //Poi da quel widget vado a prendere la proprieta` file, la formatto in una stringa e la ritorno
    g_object_get_property(G_OBJECT(immagine), "file", &ValoreTemp);
    gchar* ControllaTexture = g_value_get_string(&ValoreTemp);

    return ControllaTexture;
}


//Funzione generica che si occupa di fare il draw di una singola immagine sullo schermo
void RenderizzaCarta(GtkImage *immagine, unsigned short idCarta, unsigned short SaltaControllo) {//Se lo slot nell'array mano e` vuoto, rimuove la sprite da quello slot nel programma
    //Controllo se la carta abbia l'id di un asso speciale dal valore 11
    if (idCarta > 134) {//Se si, tolgo 130 da quel valore per farlo tornare un asso normale ai fini di prendere la giusta texture
        idCarta -= 130;
    }
    //Controllo se lo slot nell'array mano sia vuoto
    if (idCarta == SlotVuoto) {//Se lo e`, inseriamo una texture vuota per non avere le icone default missingImage di glade al loro posto.
        gtk_image_set_from_file(immagine, "GUI/SpriteMenu/ImmagineVuota.png");
        return;
    }
    //Questo controllo e` per la carta coperta
    //Se il filename della texture della carta attuale e` quella della carta coperta e SaltaControllo e` uguale a 0, la lascia cosi` com'e`
    if (strcmp(PrendiNomeTextureDaImmagine(immagine), CartaCoperta) == 0 && SaltaControllo == 0) {
        //Altrimenti se SaltaControllo ha un qualsiasi altro valore, salta questa sezione e sostituisce la
        //texture coperta con quella effettiva della carta
        return;
    }

    //Setta la sprite con il percorso in cui trovarla
    char PercorsoSprite[256];
    snprintf(PercorsoSprite, sizeof(PercorsoSprite), "GUI/SpriteCarte/%d.png", idCarta);
    gtk_image_set_from_file(immagine, PercorsoSprite);
    PercorsoSprite[0] = '\0';//Una volta fatto svuoto la variabile temporanea per evitare problemi con caratteri rimasti
}


//Funzioni principali per aggiornare individualmente la mano del giocatore o del dealer
void AggiornaManoGiocatore() {
    for (int i = 0; i < MAXcarteGiocatore; i++) {
        RenderizzaCarta(ArrImmaginiGiocatore[i], ManoGiocatore[i],0);
    }
}
void AggiornaManoBanco() {
    for (int i = 0; i < MAXcarteBanco; i++) {
        RenderizzaCarta(ArrImmaginiBanco[i], ManoBanco[i],0);
    }
}

//Funzione aggiuntiva per aggiornarle entrambe
void AggiornaAmbiMani() {
    AggiornaManoGiocatore();
    AggiornaManoBanco();
}


//Funzione che inizializza il processo di rendering prendendo le reference dai widget immagini
void InitRenderingCarte(GtkBuilder *Builder) {
    char NomeWidget[BufferSnprintf];
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


//Funzione che copre e scopre la seconda carta del dealer
void LogicaCartaCoperta() {
    //Se la texture presente nel secondo slot dell'array e` gia` quella della carta coperta
    if (strcmp(PrendiNomeTextureDaImmagine(ArrImmaginiBanco[1]), CartaCoperta) == 0) {
        //Chiama la funzione RenderizzaCarta e passa il valore di 1 a SaltaControllo, scoprendola
        RenderizzaCarta(ArrImmaginiBanco[1], ManoBanco[1],1);
    }else {//Altrimenti, coprila
        gtk_image_set_from_file(ArrImmaginiBanco[1], CartaCoperta);
    }
}