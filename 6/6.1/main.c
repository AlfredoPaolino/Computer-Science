#include <stdio.h>
#include <stdlib.h>
#define N 8

int main()
{
    int v[N], i, flag;
    flag=0;
    for (i=0;i<N;i++) {
        printf("inserire numero: ");
        scanf("%d",&v[i]);
    }
    for (i=0;i<N/2&&flag==0;i++) {
        if (v[i]!=v[N-1-i])
            flag=1;
    }
    if (flag==0)
        printf("palindroma");
    else
        printf("non palindroma");
    return 0;
}
