#include <string.h>
#define STRINGA_LUNGHEZZA_MASSIMA 21 // 20 + \0
#define LINEA_LUNGHEZZA_MASSIMA 256
#define NOMEFILE_UTENTI "file/utenti"

typedef struct {
    int id;
    char nome[STRINGA_LUNGHEZZA_MASSIMA];
    char password[STRINGA_LUNGHEZZA_MASSIMA];
    int bilancio;
    float percentualeVittoria;
    int partiteGiocate;
} Utente_t;

char* RimuoviNewLine(char line[]) {
    size_t lunghezza = strlen(line);
    if (line[lunghezza - 1] == '\n') {
        line[lunghezza - 1] = '\0';
    }
    return line;
}

char* trim_leading_spaces(char* str) {
    while (*str == ' ') {
        str++;
    }
    return str;
}

int test(char* str) {
    char* trimmed = trim_leading_spaces(str);
    memmove(str, trimmed, strlen(trimmed) + 1);
}

int ScriviUtente(FILE* file, Utente_t utente) {
    fprintf(file, "%5d,%20s,%20s,%10d,%3.0f,%10d\n", utente.id, utente.nome, utente.password, utente.bilancio, utente.percentualeVittoria, utente.partiteGiocate);
}

Utente_t* GetUtentiDalFile(int* outCount) {
    FILE *file = fopen(NOMEFILE_UTENTI, "r");
    if (!file) {
        // Il file non esiste oppure non possiamo aprirlo.

        // Proviamo a creare il file
        FILE *file = fopen(NOMEFILE_UTENTI, "a");
        if (!file) {
            // Non abbiamo i permessi
            return NULL;
        }
    }

    // Il file può essere letto, andiamo quindi a leggere ogni riga
    Utente_t* Utenti = NULL;
    int i = 0;
    char line[LINEA_LUNGHEZZA_MASSIMA];
    while (fgets(line, sizeof(line), file)) {
        //RimuoviNewLine(line);
        Utente_t* user = realloc(Utenti, (i + 1) * sizeof(Utente_t));
        if (!user) {
            // Allocazione memoria non riuscita
            free(Utenti);
            fclose(file);
            return NULL;
        }

        Utenti = user;
        sscanf(line, "%5d,%20[^,],%20[^,],%10d,%f,%10d", &Utenti[i].id, Utenti[i].nome, Utenti[i].password, &Utenti[i].bilancio, &Utenti[i].percentualeVittoria, &Utenti[i].partiteGiocate);
        test(Utenti[i].nome);
        test(Utenti[i].password);
        i++;
    }

    fclose(file);
    *outCount = i;
    return Utenti;
}

int AggiungiUtenteAlFile(Utente_t utente) {
    // "a" serve per appendere
    FILE* file = fopen(NOMEFILE_UTENTI, "a");
    if (!file) {
        return 0;
    }

    ScriviUtente(file, utente);
    fclose(file);
    return 1;
}

int ModificaUtenteAlFile(Utente_t utente) {
    FILE* file = fopen(NOMEFILE_UTENTI, "r+");
    if (!file) {
        return -1;
    }

    char line[LINEA_LUNGHEZZA_MASSIMA];
    long pos;
    while (pos = ftell(file), fgets(line, sizeof(line), file)) {
        RimuoviNewLine(line);
        int id = 0;
        sscanf(line, "%5d", &id);
        if (id == utente.id) {
            fseek(file, pos, SEEK_SET);
            ScriviUtente(file, utente);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int GetIndiceUtenteDaCredenziali(char nome[], char password[], Utente_t* utentiFile, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(nome, utentiFile[i].nome) == 0
            && strcmp(password, utentiFile[i].password) == 0) {
            return i;
            }
    }

    return -1;
}
