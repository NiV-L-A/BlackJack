#include <stdio.h>
#include <gtk/gtk.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[]) {


    InitRand();

    return InitProgramma(argc, argv);


}