#include <stdio.h>
#include <stdlib.h>

#define N 10
int main()
{
    int x, y;
    char Q[N][N];
    FILE*fp;
    fp=fopen("mappa.txt","r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    printf("inserisci coordinata x: ");
    scanf("%d", &x);
    printf("inserisci coordinata y: ");
    scanf("%d", &y);

    return 0;
}
