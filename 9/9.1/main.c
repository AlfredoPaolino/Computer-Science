#include <stdio.h>
#include <stdlib.h>

#define R 5
#define C 11

int main()
{
    FILE*fp;
    int i, j, flag;
    char matrix[R][C];
    fp=fopen("mappa.txt","r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    for (i=0;i<R;i++) {
        for (j=0;j<C;j++)
            fscanf(fp,"%c", &matrix[i][j]);
            fgetc(fp);
    }
    for (i=0;i<R;i++) {
        for (j=0;j<C;j++)
            printf("%c", matrix[i][j]);
            printf("\n");
    }
    for (i=0;i<R;i++) {
         j=0;
         flag=0;
         if (matrix[i][j]=='*')
            printf("%d ", i);
         while (matrix[i][j]=='*' && flag==0){
             if (matrix[i-1][j+1]=='*') {
                i--;
                j++;
             }
             else if (matrix[i][j+1]=='*')
                j++;
             else if (matrix[i+1][j+1]=='*') {
                i++;
                j++;
            }
            else
                flag=1;
            if (flag==0)
            printf("%d ", i);
            if (flag==0 && j==C-1)
            printf("percorso valido!");
         }
         printf("\n");
    }
    return 0;
}
