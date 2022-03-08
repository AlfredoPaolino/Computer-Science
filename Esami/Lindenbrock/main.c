#include <stdio.h>
#include <stdlib.h>

#define N 10

struct dati {
int riga[N*N];
int colonna[N*N];
int altezza[N*N];
float distanza;
};

int main(int argc, char* argv[])
{
    int matrix[N][N], posizioni;
    int count_riferimento;
    int i, j, k, count;
    struct  dati punto;
    float distanza, distanza_riga, distanza_colonna, distanza_riferimento;
    FILE* fp;
    if (argc!=2) {
        printf("ERRORE NUMERO APRAMETRI");
        return -1;
    }
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -2;
    }
    count=0;
    while (fscanf(fp, "%d %d %d", &punto.riga[count], &punto.colonna[count], &punto.altezza[count])!=EOF)
        count++;
    fclose(fp);

    posizioni=count;
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            distanza_riferimento=N+1;
            for (count=0;count<posizioni;count++) {
                distanza_riga=abs(punto.riga[count]-1-i);
                distanza_colonna=abs(punto.colonna[count]-1-j);
                if (distanza_riga>=distanza_colonna)
                    distanza=distanza_riga;
                else
                    distanza=distanza_colonna;
                if (distanza<distanza_riferimento) {
                        distanza_riferimento=distanza;
                        count_riferimento=count;
                }
                else if (distanza==distanza_riferimento) {
                    if (punto.altezza[count]>punto.altezza[count_riferimento]) {
                        distanza_riferimento=distanza;
                        count_riferimento=count;
                    }
                }
            }
            k=distanza_riferimento;
            if (punto.altezza[count_riferimento]-k>0)
                matrix[i][j]=punto.altezza[count_riferimento]-k;
            else
                matrix[i][j]=0;

        }
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
                printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
