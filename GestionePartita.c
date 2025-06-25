// #include <gtk/gtk.h>
// #include <string.h>
// #include "main.h"
//
// void AvvioPartita(GtkWidget* StkOpzioniPuntata,GtkWidget* CntBtnOpzioniPuntata, GtkWidget* StkOpzioniGiocatore, GtkWidget* CntBtnOpzioniGiocatore, GtkWidget* CntVuotoOpzioniGiocatore, GtkWidget* CntSecondaPesca, GtkWidget* LblNotifica, GtkWidget* LblPartitaVinta, GtkWidget* LblPartitaPersa, GtkWidget* CntVuotoOpzioniPuntata, GtkWidget* ControlloScena, GtkWidget* CntMenuPrincipale, GtkWidget* CntTavoloDaGioco) {
//      //Si da al giocatore la possibilita` di puntare
//      gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntTavoloDaGioco);
//      gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntBtnOpzioniPuntata);
//      // while (Turno == -1 || Puntata == 0) {
//      //      if (UtenteLoggato->bilancio < 50){
//      //           break;
//      //      }
//      // }
//      gtk_label_set_text(GTK_LABEL(LblNotifica), NULL);
//      gtk_stack_set_visible_child(GTK_STACK(StkOpzioniPuntata), CntVuotoOpzioniPuntata);
//
//      //Vengono pescate le prime due carte del banco e del giocatore
//      PescaGiocatore(2);
//      PescaBanco(2);
//      //Si mostra sullo schermo le carte pescate
//      AggiornaAmbiMani();
//      //Si passa al turno del giocatore, gestendo le varie opzioni
//      Turno = -1;
//      gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntBtnOpzioniGiocatore);
//      while (Turno == -1) {
//           while (SceltaUtente == -1){
//                switch (SceltaUtente) {
//                     case 0://Rimani
//                          gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
//                          Turno = 0;
//                          break;
//                     case 1://Raddoppia
//                          if (Raddoppia()) {
//                               AggiornaStatistichePartita();
//                               AggiornaManoGiocatore();
//                               gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntVuotoOpzioniGiocatore);
//                               Turno = 0;
//                          }else {
//                               gtk_label_set_text(GTK_LABEL(LblNotifica), "Non hai abbastanza crediti!");
//                               break;
//                          }
//                          break;
//                     case 2://Pesca
//                          gtk_stack_set_visible_child(GTK_STACK(StkOpzioniGiocatore), CntSecondaPesca);
//                          do {
//                               if (PescaGiocatore(1)) {
//                                    AggiornaManoGiocatore();
//                                    AggiornaStatistichePartita();
//                               }else {
//                                    gtk_label_set_text(GTK_LABEL(LblNotifica), "Non puoi pescare altre carte!");
//                                    Turno = 0;
//                               }
//                          } while (Turno == -1);
//                          break;
//                }
//           }
//      }
//      //Una volta finito il turno del giocatore, tocca al dealer
//      while (PescaBanco(1)){
//           AggiornaManoBanco();
//      }
//      //Finito il suo turno, E' il momento di controllare il risultato della partita
//
//
//      gtk_stack_set_visible_child(GTK_STACK(ControlloScena), CntMenuPrincipale);
// }