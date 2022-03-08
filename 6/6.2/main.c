#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int v1[N]={1,2,0,2,3}, v2[N]={1,2,0,2,3}, i, j, flag;
    flag=0;
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            if (v1[i]==v2[j]){
                flag+=1;
                break;
            }
        }
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            if (v2[i]==v1[j]){
                flag+=1;
                break;
            }
        }
    }

    if (flag==2*N)
        printf("uguali");
    else
        printf("diversi");
    return 0;
}
