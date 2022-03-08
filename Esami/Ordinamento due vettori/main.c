#include <stdio.h>
#include <stdlib.h>
#define N 4
int main()
{
    int v1[N], v2[N], v_ordinato[2*N], i, j, k;
    for (i=0;i<N;i++) {
        printf("inserire valori v1: ");
        scanf("%d", &v1[i]);
    }
    for (i=0;i<N;i++) {
        printf("inserire valori v2: ");
        scanf("%d", &v2[i]);
    }
    i=0;
    j=0;
    k=0;
    do {
            if (v1[i]<=v2[j]) {
                v_ordinato[k]=v1[i];
                i++;
            }
            else{
                v_ordinato[k]=v2[j];
                j++;
            }
            k++;
            if (i==N){
                while (k<2*N){
                v_ordinato[k]=v2[j];
                j++;
                k++;
                }

            }
            if (j==N){
                while (k<2*N){
                v_ordinato[k]=v1[i];
                i++;
                k++;
                }
            }
    }
    while (k<2*N);
        for (k=0;k<2*N;k++)
            printf("%d ", v_ordinato[k]);
    return 0;
}
