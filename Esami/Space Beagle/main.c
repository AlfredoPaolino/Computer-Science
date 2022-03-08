#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 2

int main(int argc, char* argv[])
{
    float valori[N][N], temperatura, temperatura_massima;
    int numero_misurazioni[N][N], riga, colonna, riga_massima, colonna_massima;
    int ore, minuti, secondi, i, j, ore_massima, minuti_massima, secondi_massima;
    FILE *fp;
    if (argc!=2) {
        printf("ERRORE NUMERO PARAMTRI");
        return -1;
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            valori[i][j]=0;
            numero_misurazioni[i][j]=0;
        }
    }
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    temperatura_massima=INT_MIN;
    while (fscanf(fp, "%d:%d:%d %d %d %f", &ore, &minuti, &secondi, &riga, &colonna, &temperatura)!=EOF) {
        valori[riga][colonna]+=temperatura;
        numero_misurazioni[riga][colonna]++;
        if (temperatura>temperatura_massima) {
            temperatura_massima=temperatura;
            riga_massima=riga;
            colonna_massima=colonna;
            ore_massima=ore;
            minuti_massima=minuti;
            secondi_massima=secondi;
        }
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
            printf("%.1f ", valori[i][j]/numero_misurazioni[i][j]);
        printf("\n");
    }
    printf("Il valore massimo e' stato registrato dal sensore %d %d alle %.2d:%.2d:%.2d", riga_massima, colonna_massima, ore_massima, minuti_massima, secondi_massima);
    return 0;
}
