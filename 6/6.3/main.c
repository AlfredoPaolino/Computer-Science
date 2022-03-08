#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int v[N], i, j, flag, count;
    for (i=0;i<N;i++){
        printf("inserire valori: ");
        scanf("%d",&v[i]);
    }
    for (i=0;i<N;i++){
        count=1;
        flag=0;
        for (j=i-1;j>=0;j--){
            if (v[i]==v[j])
                flag=1;
        }
        for (j=i+1;j<N&&flag==0;j++){
            if (v[i]==v[j])
                count++;
        }
        if (count>1)
            printf("il numero %d compare %d volte\n",v[i],count);
    }
    return 0;
}
