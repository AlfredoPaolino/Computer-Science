#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define M 4
#define N 11

int main(int argc, char*argv[])
{
    int i, j, count_p, count_lenght, i_c, j_c, flag, count_cercato;
    char matrix[N][N], percorso;
    FILE*fp;
    count_lenght=0;
    count_p=0;
    flag=0;
    count_cercato=0;
    if (argc!=2) {
        printf("ERRORE PARAMETRI");
        return -1;
    }
    fp=fopen("bath.txt","r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return -2;
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
            fscanf(fp,"%c", &matrix[i][j]);
    }
   for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
    printf("%c", matrix[j][j]);
        }
        printf("\n");
    }
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
            if (matrix[i][j]=='+')
                count_lenght++;
            else if (isdigit(matrix[i][j])!=0){
                count_p++;
                count_lenght++;
            }
    }
    printf("la lunghezza media dei percorsi e' %f", (float) count_lenght/count_p);
    sscanf(argv[1],"%c", &percorso);
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            if (matrix[i][j]==percorso) {
                i_c=i;
                j_c=j;
                flag=1;
            }
        }
    }
    if (flag==1) {
        count_cercato=1;
        while (matrix[i_c-1][j_c]=='+' || matrix[i_c+1][j_c]=='+' || matrix[i_c][j_c-1]=='+' || matrix[i_c][j_c+1]=='+') {
                if (matrix[i_c-1][j_c]=='+') {
                    matrix[i_c][j_c]='X';
                    i_c-=1;
                    count_cercato++;
                }
                if (matrix[i_c+1][j_c]=='+') {
                    matrix[i_c][j_c]='X';
                    i_c+=1;
                    count_cercato++;
                }
                if (matrix[i_c][j_c-1]=='+') {
                    matrix[i_c][j_c]='X';
                    j_c-=1;
                    count_cercato++;
                }
                if (matrix[i_c][j_c+1]=='+') {
                    matrix[i_c][j_c]='X';
                    j_c+=1;
                    count_cercato++;
                }
        }
    }
    printf("il percorso %d e' lungo %d unita'", atoi(argv[1]), count_cercato);
    return 0;
}
