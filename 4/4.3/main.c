#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, somma;
    somma=0;
    do
    {
        printf("inserisci numero: ");
        scanf("%d",&numero);
        somma+=numero;
    }
    while (numero!=0);
    printf("la somma dei numeri inseriti e' %d",somma);
    return 0;
}
