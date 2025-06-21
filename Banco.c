#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"

char ControllaVittoria(int ManoGiocatore[], int ManoBanco[]) {

    unsigned short TotGiocatore = 0;
    unsigned short TotBanco = 0;

    for (int i = 0; i < MAXcarte; i++){//Somma delle carte della mano Giocatore
        if (ManoGiocatore[i] < 5 && ManoGiocatore[i] != 0){
            TotGiocatore += 1;
        }else if (ManoGiocatore[i] != 0 && ManoGiocatore[i] < 105){
            TotGiocatore += (ManoGiocatore[i] / 10);
        }else if (ManoGiocatore[i] != 0 && ManoGiocatore[i] > 105){
            TotGiocatore += 10;
        }
    }
    for (int i = 0; i < MAXcarte; i++){//Somma delle carte della mano Banco
        if (ManoBanco[i] < 5 && ManoBanco[i] != 0){
            TotBanco += 1;
        }else if (ManoBanco[i] != 0 && ManoBanco[i] < 105){
            TotBanco += (ManoBanco[i] / 10);
        }else if (ManoBanco[i] != 0 && ManoBanco[i] > 105){
            TotBanco += 10;
        }
    }

    UtenteLoggato->partiteGiocate++;//Incrementa il contatore partitegiocate dato che la funzione va chiamata a prescindere ogni volta alla fine di una partita

    //Controllo condizioni di vittoria + gestione della puntata
    if (TotGiocatore > 21 && TotBanco <= 21) {//Se il giocatore sballa ma il banco no, SCONFITTA
        UtenteLoggato->bilancio -= Puntata;
        return 'S';
    }
    if (TotBanco > TotGiocatore && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del banco e` piu` grande di quella del giocatore e nessuno ha sballato SCONFITTA
        UtenteLoggato->bilancio -= Puntata;
        return 'S';
    }
    if (ManoGiocatore[0] < 5 || (ManoGiocatore[0] / 10) >= 10 && ManoGiocatore[1] < 5 || (ManoGiocatore[1] / 10) >= 10 && ManoGiocatore[0] != ManoGiocatore[1]) {//Se il giocatore ha blackjack VITTORIA
        UtenteLoggato->bilancio += Puntata * 2.5;
        return 'B';
    }
    if (TotBanco > 21 && TotGiocatore <= 21) {//Se il banco sballa ma il giocatore no, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        return 'V';
    }
    if (TotGiocatore > TotBanco && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del giocatore e` piu` grande di quella del banco e nessuno sballa, VITTORIA
        UtenteLoggato->bilancio += Puntata * 2;
        return 'V';
    }
    if (TotBanco > 21 && TotGiocatore > 21) {//Se entrambi sballano, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        return 'P';
    }
    if (TotGiocatore == TotBanco) {//Se la mano di entrambi ha lo stesso valore, PAREGGIO
        UtenteLoggato->bilancio += Puntata;
        return 'P';
    }

    return '-';//qui solo per zittire il compilatore
}

void BancoInit() {//seed della funzione rand
    srand(time(NULL));
}

void Raddoppia(int mano[], int *scommessa) {//funzione per la giocata "raddoppio"

    Pesca(mano);//invocazione alla pesca per pescare una carta

    *scommessa *= 2;//raddoppio scommessa
}

void Pesca(int mano[]){//funzione per pescare una carta
      int pescaRiuscita = 0;
      static short ControlloRipetizioni[52];

      do
      {
          for(int i = 0; i < MAXcarte; i++){
              if (mano[i] != 0) {
                  // Posizione nella mano già occupata
                  continue;
              }


              // Genera carta
              short temp = rand() % 52;
              printf("temp: %d \n", temp);
              ControlloRipetizioni[temp]++;
              if(ControlloRipetizioni[temp] > 5 && mano[i] != temp){//check se la carta scelta da rand e` gia` presente
                  continue;
              }

              // Carta libera, inseriscila nella mano alla posizione libera
              mano[i] = mazzo[temp];
              pescaRiuscita = 1;
              break;
          }
      } while(pescaRiuscita == 0);
}

