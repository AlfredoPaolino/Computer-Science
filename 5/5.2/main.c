#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 10
int main()
{
    int v[N], i, j, max, pos_max[N];
    float media;
    media=0;
    max=INT_MIN;
    j=0;
    for (i=0;i<N;i++){
        printf("inserire valore: ");
        scanf("%d",&v[i]);
        media+= v[i];
        if (v[i]>max)
            max=v[i];
    }
    for (i=0;i<N;i++)
        printf("%d ",v[i]);
    for (i=0;i<N;i++){
        if (v[i]==max){
            pos_max[j]=i;
            j++;
        }
    }
    printf("\n%f",media/N);
    printf("\n%d\n",max);
    for (i=0;i<j;i++)
    printf("\n%d",pos_max[i]);
    return 0;
}
