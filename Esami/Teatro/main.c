#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE 5
#define MAX_POSTI 8

int main(int argc, char *argv[])
{
    char mappa[MAX_FILE][MAX_POSTI];
    char alpha, fila;
    int colonna;
    int i, j, count_sx, count_dx;
    FILE *fp;
    if (argc!=2)
    {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
    fp=fopen(argv[1], "r");
    if (fp==NULL)
    {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    i=0;
    j=0;
    while (fscanf(fp, "%c", &alpha)!=EOF)
    {
        if (alpha!='\n')
        {
            mappa[i][j]=alpha;
            j++;
        }
        else if (alpha=='\n')
        {
            i++;
            j=0;
        }
    }
    fclose(fp);
    for (i=0;i<MAX_FILE;i++)
    {
        for (j=0;j<MAX_POSTI;j++)
            printf("%c", mappa[i][j]);
        printf("\n");
    }
    do
    {
        printf("inserisci le coordinate del posto nel formato <carattere> <intero>: ");
        scanf("%c %d", &fila, &colonna);
        if (fila-'A'>MAX_FILE || colonna-1>MAX_POSTI)
            printf("posto non esistente");
    }
    while (fila-'A'>MAX_FILE || colonna-1>MAX_POSTI);
    if (mappa[fila-'A'][colonna-1]=='x')
        printf("posto occupato");
    else if (mappa[fila-'A'][colonna-1]=='o')
    {
        i=1;
        count_sx=0;
        count_dx=0;
        while (mappa[fila-'A'][colonna-1-i]=='o' && i<=colonna)
        {
            count_sx++;
            i++;
        }
        i=1;
        while (mappa[fila-'A'][colonna-1+i]=='o' && i<=MAX_POSTI-colonna)
        {
            count_dx++;
            i++;
        }
        printf("libero, con %d posti liberi a sinistra e %d posti liberi a destra\n", count_sx, count_dx);
        printf("vuoi effetuare la prenotazione? y/n ");
        scanf("%*c %c", &alpha);
        if (alpha=='y')
        {
            mappa[fila-'A'][colonna-1]='x';
            fp=fopen(argv[1], "w");
             if (fp==NULL)
            {
                printf("ERRORE APERTURA FILE");
                return -2;
            }
            for (i=0;i<MAX_FILE;i++)
            {
                for (j=0;j<MAX_POSTI;j++)
                    fprintf(fp, "%c", mappa[i][j]);
                fprintf(fp, "\n");
            }
            fclose(fp);
        }

    }

    return 0;
}
