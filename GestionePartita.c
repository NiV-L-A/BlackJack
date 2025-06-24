#include <gtk/gtk.h>
#include <string.h>
#include "main.h"

unsigned short ImpostaScelta(unsigned short Scelta){
     return Scelta;
}

void AvvioPartita(GtkWidget* StkOpzioniPuntata,GtkWidget* CntBtnOpzioniPuntata, GtkWidget* StkOpzioniGiocatore, GtkWidget* CntBtnOpzioniGiocatore, GtkWidget* CntVuotoOpzioniGiocatore, GtkWidget* CntSecondaPesca, GtkWidget* LblNotificaBilancio, GtkWidget* LblPartitaVinta, GtkWidget* LblPartitaPersa) {
     //TODO: gestione dei turni fatta meglio
     //TODO: sistemare le funzioni callback per usare ImpostaScelta
     //Si da al giocatore la possibilita` di puntare
     gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntBtnOpzioniPuntata);
     //Vengono pescate le prime due carte del banco e del giocatore
     PescaGiocatore(2);
     PescaBanco(2);
     //Si mostra sullo schermo le carte pescate
     AggiornaAmbiMani();
     //Si passa al turno del giocatore, gestendo le varie opzioni
     gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntBtnOpzioniGiocatore);

     switch (ImpostaScelta) {
          case 0://Rimani
               gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
               break;
          case 1://Raddoppia
               Raddoppia();
               AggiornaStatistichePartita();
               AggiornaManoGiocatore();
               gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
               break;
          case 2://Pesca
               if (PescaGiocatore(1)) {
                    AggiornaManoGiocatore();
                    gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntSecondaPesca);
                    AggiornaStatistichePartita();
               }
               gtk_label_set_text(GTK_LABEL(LblNotificaBilancio), "Non puoi pescare altre carte!");
          case 3://Finisci il turno
               gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
               break;
          }
     //Una volta finito il turno del giocatore, tocca al dealer
     while (PescaBanco(1)){
          AggiornaManoBanco();
     }
     //Finito il suo turno, E' il momento di controllare il risultato della partita
     char StringaFormattata[BufferSnprintf];
     switch (ControllaVittoria()){
          case 'B'://Blackjack
               snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita con un BlackJack guadagnando \n\t\t %d crediti!", Puntata*2.5);
               gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
               //salvaPartitaSuFile();
               ResettaValoriGlobali();
               break;
          case 'V'://Vittoria semplice
               snprintf(StringaFormattata, BufferSnprintf, "Hai vinto la partita guadagnando \n\t\t %d crediti!", Puntata*2);
               gtk_label_set_text(GTK_LABEL(LblPartitaVinta), StringaFormattata);
               //salvaPartitaSuFile();
               ResettaValoriGlobali();
               break;
          case 'P':
               gtk_label_set_text(GTK_LABEL(LblPartitaVinta), "Hai pareggiato la partita! \n\t Non ci sono conseguenze!");
               //salvaPartitaSuFile();
               ResettaValoriGlobali();
               break;
          case 'S':
               snprintf(StringaFormattata, BufferSnprintf, "Hai perso la partita rimettendoci \n\t\t %d crediti!", Puntata);
               gtk_label_set_text(GTK_LABEL(LblPartitaPersa), StringaFormattata);
               //salvaPartitaSuFile();
               ResettaValoriGlobali();
               break;
     }

}