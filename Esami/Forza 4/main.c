#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(int argc, char *argv[])
{
    int x, y;
    int i, j, count_R, count_G, vincente;
    char colore;
    char scacchiera[N][N];
    FILE *fp;
    if (argc!=3)
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
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            scacchiera[i][j]='X';
    }
    count_G=0;
    count_R=0;
    while (fscanf(fp, "%d %d %c", &x, &y, &colore)!=EOF)
    {
        fgetc(fp);
        if (scacchiera[N-y][x-1]=='X')
            scacchiera[N-y][x-1]=colore;
        else
            printf("ERRORE: %d %d sono coordinate ripetute", x, y);
        if (x<1 || x>N || y<1 || y>N)
            printf("ERRORE: %d %d non sono coordinate valide", x, y);
        if (colore=='G')
            count_G++;
        if (colore=='R')
            count_R++;
    }
    fclose(fp);
    if (argv[2][0]=='G')
        {
            if (!(count_G==count_R || count_G==count_R+1))
                printf("ERRORE: partita non coerente con la regola 3 del gioco");
        }
    if (argv[2][0]=='R')
        {
            if (!(count_R==count_G || count_R==count_G+1))
                printf("ERRORE: partita non coerente con la regola 3 del gioco");
        }
        vincente=0;
        for (i=1;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                if (scacchiera[i][j]==scacchiera[i+1][j] && scacchiera[i+1][j]==scacchiera[i+2][j] && scacchiera[i][j]!='X')
                {
                    if (scacchiera[i-1][j]==scacchiera[i][j])
                    {
                        printf("ATTENZIONE: configurazione vincente da %d %d in verticale", N-i, j);
                        vincente=1;
                    }
                }
            }
        }
        for (i=0;i<N;i++)
        {
            for (j=1;j<N;j++)
            {
                if (scacchiera[i][j]==scacchiera[i][j+1] && scacchiera[i][j+1]==scacchiera[i][j+2] && scacchiera[i][j]!='X')
                {
                    if (scacchiera[i][j-1]==scacchiera[i][j])
                    {
                        printf("ATTENZIONE: configurazione vincente da %d %d in orizzontale", N-i, j);
                        vincente=1;
                    }
                }
            }
        }
        if (!vincente)
        {

        }
    return 0;
}
