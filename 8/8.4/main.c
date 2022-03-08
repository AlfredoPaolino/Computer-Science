#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 60
#define P 5

int main()
{
    char stringa[MAX+1];
    int i, j, k, v[P], temp;
    float count_parole, count_lunghezza, count_caratteri, media;
    count_parole=0;
    gets(stringa);
    if (strlen(stringa)>MAX) {
        printf("ERRORE! LUNGHEZZA STRINGA NON CONSENTITA");
        return -1;
    }
    for (i=0;i<MAX;i++) {
        if (isspace(stringa[i])!=0) {
            if (isalpha(stringa[i+1])!=0)
                count_parole++;
        }
    }
    if (count_parole>P) {
        printf("ERRORE! NUMERO DI PAROLE SUPERIORE A 5");
        return -2;
    }
    else
        printf("la stringa contiene %f parole\n", count_parole);
    count_caratteri=0;
    for (i=0;i<strlen(stringa);i++) {
        if (isalpha(stringa[i])!=0)
            count_caratteri++;
        }
    media=count_caratteri/count_parole;
    printf("la lunghezza media delle parole e' %f\n", media);
    j=0;
    for (i=0;i<strlen(stringa);i++){
        if (isalpha(stringa[i])!=0)
            count_lunghezza++;
        if (isspace(stringa[i])!=0){
            v[j]=count_lunghezza;
            count_lunghezza=0;
            j++;
        }
    }
    v[j]=count_lunghezza;
    for (i=0;i<=j;i++) {
        for (k=0;k<=j;k++) {
            if (v[k]>v[k+1]) {
                temp=v[k];
                v[k+1]=v[k];
                v[k+1]=temp;
            }
        }
    }
    for (i=0;i<=j;i++)
        printf("%d ", v[i]);
    return 0;
}
