#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int v[N], pos_max[N], i, j, n, flag;
    flag=0;
    for (i=0;i<N&&flag==0;i++){
        printf("inserire valore: ");
        scanf("%d",&n);
        if (n>=0)
            v[i]=n;
        else
            flag=1;
    }
    do {
        printf("\ninserire valore da cercare: ");
        scanf("%d",&n);
        if (n<0)
            break;
        j=0;
        for (i=0;i<N;i++){
            if (v[i]==n){
                pos_max[j]=i;
                j++;
            }
        }
        for (i=0;i<j;i++)
            printf("\nvalore trovato in posizione: %d",pos_max[i]);
            printf("\n");
    }
    while (n>=0);
    return 0;
}
