#include <stdlib.h>
#include <time.h>
#include "main.h"

int manoBanco[] = {0};

void pesca(int mano[]){
      srand(time(NULL));

      for(int i = 0; i < sizeof(mano) / sizeof(mano[0]) + 1; i++){
          short temp = rand() + 1 % 52;

             if(mano[i] == mazzo[temp]){
               continue;
             }

      }



}

