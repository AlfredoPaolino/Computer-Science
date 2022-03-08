#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int main()
{
    char stazione_partenza[MAX+1];
    char ora_partenza[MAX+1];
    char stazione_arrivo[MAX+1];
    char ora_arrivo[MAX+1];
    char citta[MAX+1];
    int count_partenze, count_arrivi;
    count_partenze=0;
    count_arrivi=0;
    FILE*fp;
    fp=fopen("schedule.txt","r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    printf("inserire citta' desiderata: ");
    scanf("%s", citta);
    while (fscanf(fp,"%s %s %s %s", stazione_partenza, ora_partenza, stazione_arrivo, ora_arrivo)!=EOF) {
        if (strcmp(stazione_partenza,citta)==0)
            count_partenze++;
        if (strcmp(stazione_arrivo,citta)==0)
            count_arrivi++;
    }
    printf("%d treni in partenza da %s\n", count_partenze, citta);
    printf("%d treni in arrivo a %s\n", count_arrivi, citta);
    return 0;
}
