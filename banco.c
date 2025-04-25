#include <stdlib.h>
#include <time.h>
#include "main.h"

int manoBanco[] = {0};

void pesca(int *mano){
      srand(time(NULL));

      for(int i = 0; i < sizeof(manoBanco) / sizeof(manoBanco[0]); i++){
             if(manoBanco[i] == 0){
               short temp = rand() + 1 % 52;

               *mano[i] = mazzo[temp];
             }
      }



}

