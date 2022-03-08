#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int v[N], n, i, j, flag;
    printf("inserire valore: ");
    scanf("%d",&n);
    j=0;
    flag=0;
    for (i=0;i<N&&flag==0;i++) {
        v[i]=n%2;
        n=n/2;
        j++;
        if (n==1) {
            v[i+1]=1;
            j++;
            flag=1;
        }
    }
    for (i=0;i<j;i++)
        printf("%d ",v[j-i-1]);
    return 0;
}
