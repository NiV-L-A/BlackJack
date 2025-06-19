//variabili globali
#pragma once//serve per le robe costanti e globali
#define MAXcarte 22 //valore massimo di carte che il gicatore puo` avere in mano
int manoGiocatoreDivisa[MAXcarte];
int puntataDivisa;

// TODO: rendere globali le seguenti variabili:
// - Numero di righe nel file storico partite
// - L'array di utenti letti dal file
// - L'indice dell'utente loggato

//mazzo statico con tutte le carte
//si comincia da 1 e non da 0 perche` 0 e` il valore default di un elemento non assegnato dell'array mano
const unsigned short mazzo[52] = {
    // Asso, 2, 3, ... 10, J, Q, K
    1, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131,
    2, 22, 32, 42, 52, 62, 72, 82, 92, 102, 112, 122, 132,
    3, 23, 33, 43, 53, 63, 73, 83, 93, 103, 113, 123, 133,
    4, 24, 34, 44, 54, 64, 74, 84, 94, 104, 114, 124, 134
};

//dichiarate le funzioni qua sotto
void pesca(int mano[]);//funzione pesca in banco
void raddoppia(int mano[], int *scommessa);//funzione raddoppia in banco
void dividi(int mano[],int puntata);//funzione split in giocatore



//FUNZIONI DEBUG
void printMano(int mano[]);//printare la mano passata



//non toccare queste
#ifndef MAIN_H
#define MAIN_H

#endif //MAIN_H
