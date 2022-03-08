#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int v[N], i, j, n;
    for (i=0;i<N;i++) {
        printf("inserire valore: ");
        scanf("%d",&n);
        if (i==0)
            v[i]=n;
        else {
            for (j=1;j<=i;j++){
                if (n<=v[i-j])
                    v[i-j+1]=v[i-j];
                if ((i-j)==0){
                    v[i-j]=n;
                    break;
                }
                if (n>v[i-j]){
                    v[i-j+1]=n;
                    break;
                }
            }
        }
    }
    for (i=0;i<N;i++)
        printf("%d ",v[i]);
    return 0;
}
