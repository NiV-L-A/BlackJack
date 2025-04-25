#include <stdio.h>
#include "banco.c"
#include "main.h"

int main(){//nel main mettiamo solo le call alle funzioni.
   static int manoBanco[MAXcarte];
    int manoGiocatore[MAXcarte];

    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);



    for (int i = 0; i < MAXcarte; i++) {
        if (manoBanco[i] != 0) {
            printf("%d\n", manoBanco[i]);
        }
    }
}