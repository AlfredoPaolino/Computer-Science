#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

int main(int argc, char*argv[])
{
    int scelta;
    char hotel[40+1], zona[5+1], zona_scelta[5+1];
    float prezzo, prezzo_minimo;
    FILE*fp;
    if (argc!=2) {
        printf("ERRORE PARAMETRI");
        return EXIT_FAILURE;
    }
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return EXIT_FAILURE;
    }

    do {
         printf("1) prenotazione di un hotel per una notte\n");
        printf("2) stampa a video hotel disponibili con relativi prezzi\n");
        printf("3) esci\n");
        printf("inserire scelta: ");
        scanf("%d", &scelta);
        if (scelta==1) {
            printf("inserire zona: ");
            scanf("%s", zona_scelta);

            }
        }
        if (scelta==2) {

        }
    }
    while (scelta!=3);
    return 0;
}
