#include <stdlib.h>
#include <time.h>
#include "main.h"

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

