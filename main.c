#include <stdio.h>
#include "banco.c"
#include "giocatore.c"
#include "GestioneUtenti.c"
#include "GestioneStoricoPartite.c"
#include "main.h"

// nel main mettiamo solo le call alle funzioni.
int main(){
    static int ManoBanco[MAXcarte];//mettere static davanti ad una variabile garantisce che i valori non assegnati siano deterministici anziche` numeri a caso presi da un punto a caso della memoria
    static int ManoGiocatore[MAXcarte];

    /*
    per quanto riguarda il calcolo del winrate, bisogna scorrere tutti quanti gli elementi dell'array storico partite
    nel dato risultato (arr.Risultato) e fare una conta con due variabili. una tiene conto delle vittorie
    (vittorie++ if V || B) ed una delle sconfitte (sconfitte++ if S). una volta avute entrambe si fa il calcolo con la
    seguente formula: Winrate = [numVittorie/numVittorie + numSconfitte] * 100.
    */
}