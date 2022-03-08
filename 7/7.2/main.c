#include <stdio.h>
#include <stdlib.h>
#define L 6

void mult (int v[], int N_f, int x_f);

int main()
{
    int vett[L], i, N, x;
    do {
    printf("inserire numero valori: ");
    scanf("%d", &N);
    }
    while (N>L);
    for (i=0;i<N;i++){
        printf("inserire valore: ");
        scanf("%d", &vett[i]);
    }
    printf("inserire valore moltiplicativo: ");
    scanf("%d", &x);
    mult(vett, N, x);
        for (i=0;i<N;i++){
        printf("%d ", vett[i]);
    }
    return 0;
}

void mult (int v[], int N_f, int x_f)
{
    int i;
    for (i=0;i<N_f;i++)
        v[i]=v[i]*x_f;
    return;
}
