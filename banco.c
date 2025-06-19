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
char controllaVittoria() {
    return 'S';
    return 'P';
    return 'V';
    return 'B';
}

void banco_init()
{
    //seed della funzione rand
    srand(time(NULL));
}

void raddoppia(int mano[], int *scommessa) {//funzione per la giocata "raddoppio"

    pesca(mano);//invocazione alla pesca per pescare una carta

    *scommessa *= 2;//raddoppio scommessa
}

void pesca(int mano[]){//funzione per pescare una carta
      int pescaRiuscita = 0;
      static short controlloRipetizioni[52];

      do
      {
          for(int i = 0; i < MAXcarte; i++){
              if (mano[i] != 0) {
                  // Posizione nella mano già occupata
                  continue;
              }

              // Posizione libera
              // Genera carta
              short temp = rand() % 52;
              printf("temp: %d \n", temp);
              controlloRipetizioni[temp]++;
              if(controlloRipetizioni[temp] > 5 && mano[i] != temp){//check se la carta scelta da rand e` gia` presente
                  continue;
              }

              // Carta libera, inseriscila nella mano alla posizione libera
              mano[i] = mazzo[temp];
              pescaRiuscita = 1;
              break;
          }
      } while(pescaRiuscita == 0);
}

