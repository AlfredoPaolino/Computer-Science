#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 4
#define C 100

int main(int argc, char* argv[])
{
    char attuale;
    int count, i, istogramma[C], riga, max_righe;
    FILE*fp;
    if (argc!=3) {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
     for (i=0;i<C;i++)
        istogramma[i]=0;
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -2;
    }
    count=0;
    riga=1;
    max_righe=0;
    while (fscanf(fp, "%c", &attuale)!=EOF) {
        if (attuale=='\n') {
            if (count>max_righe)
            max_righe=count;
            count=0;
            riga++;
        }
        else if (isspace(attuale)!=0)
            count++;
        else if (isspace(attuale)==0) {
            if (riga<=N)
                istogramma[count]++;
            else if (riga>N)
                istogramma[count]--;
            count++;
        }
    }
    fclose(fp);
    fp=fopen(argv[2], "w");
    for (i=0;i<max_righe;i++)
        fprintf(fp, "%d ", istogramma[i]);
    return 0;
}
