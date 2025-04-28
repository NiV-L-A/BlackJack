#include <stdlib.h>
#include <time.h>
#include "main.h"




void raddoppia(int mano[], int *scommessa) {//funzione per la giocata "raddoppio"

    pesca(mano);//invocazione alla pesca per pescare una carta

    *scommessa *= 2;//raddoppio scommessa
}

void pesca(int mano[]){//funzione per pescare una carta
      srand(time(NULL));//seed della funzione rand
      int numElementi = 0;//variabile contatore

      for (int i = 0; i < MAXcarte; i++) {//ciclo for per contare il numero di carte in mano
          if (mano[i] != 0) {
              numElementi++;
          }
      }

      for(int j = 0; j < numElementi + 1; j++){//ciclo for con la logica per pescare
          short temp = rand() % 52;

             if(mano[j] == mazzo[temp]){//check se la carta scelta da rand e` gia` presente
               continue;
             }
            mano[j] = mazzo[temp];
      }

}

