#include <stdio.h>
#include <stdlib.h>

#define RC 5

int main()
{
    int matrix[RC][RC], i, j, k, val, lunghezza, count, flag;
    for (i=0;i<RC;i++){
        for (j=0;j<RC;j++){
            printf("inserire valore matrix[%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("inserire valore cercato: ");
    scanf("%d", &val);
    printf("inserire lunghezza riga cercata: ");
    scanf("%d", &lunghezza);
    for (i=0;i<RC;i++){
            flag=0;
        for (j=0;j<RC && flag==0 ;j++){
            count=0;
            for (k=0;k<lunghezza;k++){
                if (matrix[i][j+k]==val)
                count++;
                if (count==lunghezza){
                    printf("sequenza trovata nella riga %d\n", i);
                    flag=1;
                }
            }
        }
    }
    printf("\n");
    for (i=0;i<RC;i++){
            flag=0;
        for (j=0;j<RC && flag==0 ;j++){
            count=0;
            for (k=0;k<lunghezza;k++){
                if (matrix[j+k][i]==val)
                count++;
                if (count==lunghezza){
                    printf("sequenza trovata nella colonna %d\n", i);
                    flag=1;
                }
            }
        }
    }
    return 0;
}
