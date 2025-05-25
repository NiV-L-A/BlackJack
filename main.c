#include <stdio.h>
#include "banco.c"
#include "giocatore.c"
#include "main.h"

int main(){//nel main mettiamo solo le call alle funzioni.
    static int manoBanco[MAXcarte];//mettere static davanti ad una variabile garantisce che i valori non assegnati siano deterministici anziche` numeri a caso presi da un punto a caso della memoria
    static int manoGiocatore[MAXcarte];
    int scommessa = 10;
    int portafoglio = 100;
    //TODO: rendere globali gli array delle mani e le variabili che tengono traccia di scommessa e portafoglio del giocatore

    //DEBUG init mano
    banco_init();
    pesca(manoGiocatore);
    pesca(manoGiocatore);
    pesca(manoGiocatore);
    pesca(manoGiocatore);
    pesca(manoGiocatore);
    pesca(manoGiocatore);



    printMano(manoGiocatore);


    //DEBUG sezione
    //printf("prima di raddoppia %d\n", scommessa);
   // printMano(manoGiocatore);
   // raddoppia(manoGiocatore, &scommessa);

    //printf("dopo di raddoppia %d\n", scommessa);
    //printMano(manoGiocatore);
}