#include <stdio.h>
#include <stdlib.h>
#define N 4

int main()
{
    int v1[N], v2[N], num, i, j, x;
    i=0;
    j=0;
    while (i<N&&j<N){
        printf("inserire numero: ");
        scanf("%d",&num);
        if (num%3==0){
            v1[i]=num;
            i++;
        }
        else if (num<0&&num%3!=0&&num%2!=0){
            v2[j]=num;
            j++;
        }
    }
    for (x=0;x<i;x++)
        printf("%d ",v1[x]);
        printf("\n");
    for (x=0;x<j;x++)
        printf("%d ",v2[x]);
    return 0;
}
