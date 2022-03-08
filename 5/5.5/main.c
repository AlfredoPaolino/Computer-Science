#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int v[N], i;
    for (i=0;i<N;i++){
        printf("inserire numero: ");
        scanf("%d",&v[i]);
    }
    for (i=0;i<N-2;i++){
            if (v[i]==v[i+1]-1){
                if (v[i+1]==v[i+2]-1)
                    printf("serie in posizione: %d %d %d\n",i,i+1,i+2);
            }
            if (v[i]==v[i+1]+1){
                if (v[i+1]==v[i+2]+1)
                    printf("serie in posizione: %d %d %d\n",i,i+1,i+2);
            }
        }
    return 0;
}
