#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int i, distanza, dist_max, n1, n2;
    i=0;
    distanza=0;
    dist_max=0;
    while (i<N){
        if (i==0){
            printf("inserire numero: ");
            scanf("%d",&n1);
            i++;
            }
        printf("inserire numero: ");
        scanf("%d",&n2);
        distanza=abs(n2-n1);
        if (distanza>dist_max)
            dist_max=distanza;
            n1=n2;
            i++;
    }
    printf("distanza massima= %d",dist_max);
    return 0;
}
