#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 5

int main()
{
    int matrix [M][N], i, j;
    for (i=0;i<M;i++) {
        for (j=0;j<N;j++) {
            printf("inserire valore matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix [i][j]);
        }
    }
    for (i=0;i<M;i++) {
        for (j=0;j<N;j++)
            printf("%d", matrix [i][j]);
    }
    return 0;
}
