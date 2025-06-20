#include <stdlib.h>
#include <time.h>
#include "main.h"

// prendi ogni elemento
// dividi per 10
// ripeti e somma al precedente
/*
il giocatore vince se:
    se la mano ha un valore più alto di quello del dealer, ma meno di 21
    oppure il dealer fa più di 21
    BlackJack = Asso + carta con valore 10 <---------------
        MA se anche il dealer ha BlackJack, allora pareggio

Dal 2 al 9, i valori nominali
10, J, Q, K tutte 10
Assi, 1 o 11

Ogni giocatore riceve 2 carte scoperte
Il dealer riceve una scoperta, e una coperta come ultima

I giocatori partono per primi hanno 4 opzioni
    pescare: voglio un altra carta, per quante volte voglio
        però fino a quando non restono o non sballano
    Raddoppiare: raddoppi la scommessa e ricevi una carta in più
    Dividere: Se nelle prime 2 carte c'è una coppia (valore uguale)
        Gioca 2 mani separate, il giocatore mette un'altra scommessa (uguale), e il dealer separa.

Dopo che tutti i giocatori hanno finito con le loro mani
Il dealer mostra la sua carta e stabilisce se chiamare o stare

Chi ha la mano più alta senza superare il 21, vince
Se vince con il blackjack, la vincita viene moltiplicata per 1.5 (aka +50%)
*/
char ControllaVittoria(int ManoGiocatore[], int ManoBanco[]) {

    unsigned short TotGiocatore = 0;
    unsigned short TotBanco = 0;

    for (int i = 0; i < MAXcarte; i++){
        if (ManoGiocatore[i] < 5 && ManoBanco[i] != 0){
            TotGiocatore += 1;
        }
        if (ManoGiocatore[i] != 0){
            TotGiocatore += (ManoGiocatore[i] / 10);
        }

    }
    for (int i = 0; i < MAXcarte; i++){
        if (ManoBanco[i] < 5 && ManoBanco[i] != 0){
            TotBanco += 1;
        }
        if (ManoBanco[i] != 0){
            TotBanco += (ManoBanco[i] / 10);
        }
    }



    if (TotGiocatore > 21 && TotBanco <= 21) {//Se il giocatore sballa ma il banco no, SCONFITTA
        return 'S';
    }
    if (TotBanco > TotGiocatore && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del banco e` piu` grande di quella del giocatore e nessuno ha sballato SCONFITTA
        return 'S';
    }
    if (ManoGiocatore[0] < 5 || (ManoGiocatore[0] / 10) == 10 && ManoGiocatore[1] < 5 || (ManoGiocatore[1] / 10) == 10 && ManoGiocatore[0] != ManoGiocatore[1]) {//Se il giocatore ha blackjack VITTORIA
        return 'B';
    }
    if (TotBanco > 21 && TotGiocatore <= 21) {//Se il banco sballa ma il giocatore no, VITTORIA
        return 'V';
    }
    if (TotGiocatore > TotBanco && TotGiocatore <= 21 && TotBanco <= 21) {//Se la mano del giocatore e` piu` grande di quella del banco e nessuno sballa, VITTORIA
        return 'V';
    }
    if (TotBanco > 21 && TotGiocatore > 21) {//Se entrambi sballano, PAREGGIO
        return 'P';
    }
    if (TotGiocatore == TotBanco) {//Se la mano di entrambi ha lo stesso valore, PAREGGIO
        return 'P';
    }

    return '-';
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

