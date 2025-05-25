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
    // for(int i = 0; i < 9; i++)
    // {
    //     printf("%d: \n",i);
    //     pesca(manoGiocatore);
    // }
    manoGiocatore[0] = 22;
    manoGiocatore[1] = 22;
    dividi(manoGiocatore,scommessa);

    printMano(manoGiocatore);
    printMano(manoGiocatoreDivisa);

    printf("\nscommessa: %d -- scommessa splittata: %d",scommessa,puntataDivisa);


    //DEBUG sezione
    //printf("prima di raddoppia %d\n", scommessa);
   // printMano(manoGiocatore);
   // raddoppia(manoGiocatore, &scommessa);

    //printf("dopo di raddoppia %d\n", scommessa);
    //printMano(manoGiocatore);
}