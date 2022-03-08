#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 3
#define L 20

int main()
{
    int i, flag, quantita_desiderata;
    char stringa[C][L+1];
    char prodotto[C][L+1];
    float prezzo[C];
    char desiderio[L+1], prodotto_desiderato[L+1];
    for (i=0;i<C;i++){
    printf("inserire stringa nel formato <prodotto> <prezzo> : ");
    gets(stringa[i]);
    sscanf(stringa[i], "%s %f", prodotto[i], &prezzo[i]);
    }
    flag=0;
    do {
        printf("inserire stringa nel formato <prodotto desiderato> <quantita'> : ");
        gets(desiderio);
        sscanf(desiderio, "%s %d", prodotto_desiderato, &quantita_desiderata);
        for (i=0;i<C;i++){
            if (strcmp(prodotto_desiderato,prodotto[i])==0){
                printf("hai acquistato %d %s al prezzo di %f", quantita_desiderata, prodotto_desiderato, prezzo[i]*quantita_desiderata);
                flag=1;
            }
        }
    }
    while (flag==0);
    return 0;
}
