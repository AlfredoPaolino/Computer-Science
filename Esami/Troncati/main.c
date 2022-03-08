#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char numero_stringa[strlen(argv[3])];
    int numero_intero[strlen(argv[3])], i, j, flag, lunghezza;
    FILE* fp_numeri;
    FILE* fp_numeri_filtrati;
    if (argc!=4) {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
    fp_numeri=fopen(argv[1], "r");
    if (fp_numeri==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    fp_numeri_filtrati=fopen("numeri_filtrati.txt", "w");
    if (fp_numeri_filtrati==NULL) {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    while (fscanf(fp_numeri, "%s", numero_stringa)!=EOF) {
            if (atoi(numero_stringa)>=atoi(argv[2]) && atoi(numero_stringa)<=atoi(argv[3])) {
                flag=0;
                lunghezza=0;
                for (i=0;i<strlen(argv[3]) && flag==0;i++) {
                    numero_intero[i]=atoi(numero_stringa);
                    numero_stringa[strlen(numero_stringa)-1]=numero_stringa[strlen(numero_stringa)];
                    lunghezza++;
                    if (numero_stringa[0]=='\0')
                        flag=1;
                }
                if (numero_intero[lunghezza-1]!=1){
                    flag=0;
                    for (i=0;i<lunghezza && flag==0;i++) {
                        for (j=2;j<numero_intero[i]/2 && flag==0;i++) {
                            if (numero_intero[i]%j==0)
                                flag=1;
                        }
                    }
                }
                else
                    flag=1;
                if (flag==0)
                    fprintf(fp_numeri_filtrati, "%d ", numero_intero[0]);
            }
    }
    fclose(fp_numeri);
    fclose(fp_numeri_filtrati);
    return 0;
}
