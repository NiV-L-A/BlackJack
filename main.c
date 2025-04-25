#include <stdio.h>
#include "banco.c"
#include "main.h"

int main(){//nel main mettiamo solo le call alle funzioni.
    static int manoBanco[MAXcarte];//mettere static davanti ad una variabile garantisce che i valori non assegnati siano deterministici anziche` numeri a caso presi da un punto a caso della memoria
    static int manoGiocatore[MAXcarte];

    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);
    pesca(manoBanco);



    for (int i = 0; i < MAXcarte; i++) {//funzione per printare la mano per debuggare
        if (manoBanco[i] != 0) {
            printf("%d\n", manoBanco[i]);
        }
    }
}