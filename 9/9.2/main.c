#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 50

int insert_product(char warehouse[][M+1], float price[], int n, char new_product[],float price_new_product);

void print_all(char warehouse[][M+1], float price[], int n, float *avg, float *max);

int main()
{
    int i, scelta, ritorno;
    char warehouse[N][M+1], nuovo_prodotto[M+1];
    float price[N], nuovo_prezzo, prezzo_medio, prezzo_massimo;
    for (i=0;i<N;i++)
        price[i]=-2;
    printf("1) inserimento di un nuovo prodotto e relativo prezzo\n");
    printf("2) stampa listino attuale (elenco dei prodotti con i relativi prezzi)\n");
    printf("3) uscita dal programma\n");
    do {
        printf("inserire la propria scelta: ");
        do
            scanf("%d", &scelta);
        while (scelta<1 || scelta>3);
        i=0;
        if (scelta==1) {
            printf("prodotto da inserire: ");
            scanf("%s", nuovo_prodotto);
            printf("prezzo da inserire: ");
            scanf("%f", &nuovo_prezzo);
            ritorno=insert_product(warehouse, price, N, nuovo_prodotto, nuovo_prezzo);
        }
        if (scelta==2)
            print_all(warehouse, price, N, &prezzo_medio, &prezzo_massimo);
    }
    while (scelta!=3);
    return 0;
}

int insert_product(char warehouse[][M+1], float price[], int n, char new_product[],float price_new_product)
{
    int i, flag, count, esito;
    flag=0;
    count=0;
    for (i=0;i<N && flag==0;i++){
        if (strcmp(new_product,warehouse[i])!=0 && price[i]==-2){
            strcpy(warehouse[i],new_product);
            price[i]=price_new_product;
            flag=1;
            esito=1;
        }
        else if (price[i]!=-2){
            count++;
            if (count==N)
                esito=0;
        }
        else if (strcmp(new_product,warehouse[i])==0)
            esito=2;
    }
    return esito;
}
void print_all(char warehouse[][M+1], float price[], int n, float *avg, float *max)
{
    int i, count;
    float somma;
    somma=0;
    *max=0;
    count=0;
    for (i=0;i<N;i++){
        if (price[i]!=-2){
            printf("%s %f\n", warehouse[i], price[i]);
            count++;
            somma+=price[i];
            if (price[i]>*max)
                *max=price[i];
        }
    }
    *avg=somma/count;
    printf("il prezzo medio e' %f\n", *avg);
    printf("il prezzo massimo e'%f\n", *max);
}
