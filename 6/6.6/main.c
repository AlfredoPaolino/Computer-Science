#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30

int sommatoria (int numero_f, int base_f, int vettore_cifre_f[], int*lunghezza_f);

int main()
{
    int numero, parametro, base, somma, vettore_cifre[N], i, lunghezza;

    printf("inserire parametro: ");
    scanf("%d", &parametro);

    for (numero=3;numero<=parametro;numero++){

        for (base=2;base<numero;base++){

            somma=sommatoria(numero,base,vettore_cifre,&lunghezza);

            if (somma==numero) {
            printf("\nil numero %d e' palindromo in base %d \n",numero,base);
                for (i=0;i<lunghezza;i++)
                    printf("%d", vettore_cifre[i]);
            }
        }
    }
    return 0;
}

int sommatoria(int numero_f, int base_f, int vettore_cifre_f[], int*lunghezza_f) {

    int i, j, valore, somma_f, flag;
    valore=numero_f;
    flag=0;

    for (i=0;flag==0;i++){
        vettore_cifre_f[i]=(valore%base_f);
        valore/=base_f;
        if (valore==0)
            flag=1;
    }
    *lunghezza_f=i;
    somma_f=0;

    for (j=i-1;j>=0;j--)
        somma_f+=vettore_cifre_f[j]*pow(base_f,i-1-j);

    return somma_f;
}
