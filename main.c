#include <stdio.h>
#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "main.h"


// nel main mettiamo solo le call alle funzioni.
int main(int argc, char *argv[]){
    static int ManoBanco[MAXcarte];//mettere static davanti ad una variabile garantisce che i valori non assegnati siano deterministici anziche` numeri a caso presi da un punto a caso della memoria
    static int ManoGiocatore[MAXcarte];

    BancoInit();


    return InitProgramma(argc, argv);
    /*
    per quanto riguarda il calcolo del winrate, bisogna scorrere tutti quanti gli elementi dell'array storico partite
    nel dato risultato (arr.Risultato) e fare una conta con due variabili. una tiene conto delle vittorie
    (vittorie++ if V || B) ed una delle sconfitte (sconfitte++ if S). una volta avute entrambe si fa il calcolo con la
    seguente formula: Winrate = [numVittorie/numVittorie + numSconfitte] * 100.
    */
}