#include <stdio.h>
#include "banco.c"
#include "main.h"

int main(){//nel main mettiamo solo le call alle funzioni.
   static int manoBanco[22];
    int manoGiocatore[22];

    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);



    for (int i = 0; i < 22; i++) {
        if (manoBanco[i] != 0) {
            printf("%d\n", manoBanco[i]);
        }
    }
}