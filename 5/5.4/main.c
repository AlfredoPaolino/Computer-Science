#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int v[N], i, j, flag;
    flag=0;
    for (i=0;i<2;i++){
        printf("inserire numero: ");
        scanf("%d",&v[i]);
    }
        if (v[1]>v[0]) {
            while (i<N&&flag==0) {
                printf("inserire numero: ");
                scanf("%d",&v[i]);
            if (v[i]<v[i-1])
                 flag=1;
                 i++;
            }
        }
        if (v[1]<v[0]) {
            while (i<N&&flag==0) {
                printf("inserire numero: ");
                scanf("%d",&v[i]);
            if (v[i]>v[i-1])
                 flag=1;
            i++;
            }
        }
        for (j=0;j<i;j++)
            printf("%d ",v[j]);
    return 0;
}
