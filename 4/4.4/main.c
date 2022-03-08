#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    printf("inserire lato triangolo isoscele: ");
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        for (j=0;j<i+1;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
