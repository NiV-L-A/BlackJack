#include <stdlib.h>
#include <time.h>
#include "main.h"

void banco_init()
{
    srand(time(NULL));
}


void raddoppia(int mano[], int *scommessa) {//funzione per la giocata "raddoppio"

    pesca(mano);//invocazione alla pesca per pescare una carta

    *scommessa *= 2;//raddoppio scommessa
}

void pesca(int mano[]){//funzione per pescare una carta
      //seed della funzione rand
      int numElementi = 0;//variabile contatore
      int pescaRiuscita = 0;
      static short controlloRipetizioni[52];

      //si e` deciso di mettere questo ciclo for per individuare il primo spazio libero.
      //cosi` facendo non e` necessario andarlo a trovare nel ciclo for successivo, risparmiando chiamate inutili a rand
      for (int i = 0; i < MAXcarte; i++) {
          if (mano[i] != 0) {
              numElementi++;
          }
      }
      do
      {
          for(int j = numElementi + 1; j < MAXcarte; j++){//
              short temp = rand() % 52;
              printf("temp: %d \n", temp);
              controlloRipetizioni[temp]++;
              if(controlloRipetizioni[temp] > 5 && mano[j] != temp){//check se la carta scelta da rand e` gia` presente
                  continue;
              }
              mano[j] = mazzo[temp];
              pescaRiuscita++;
              break;
          }
      }while(pescaRiuscita == 0);
}

