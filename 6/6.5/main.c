#include <stdio.h>
#include <stdlib.h>
int power (int b, int ex);

int main()
{
    int base, esponente, risultato;
    printf("inserire base: ");
    scanf("%d",&base);
    printf("inserire esponente: ");
    scanf("%d",&esponente);
    risultato=power(base, esponente);
    printf("%d^%d=%d", base, esponente, risultato);
    return 0;
}
int power(int b, int ex) {
    int i, temp;
    temp=b;
    for (i=1;i<ex;i++)
        b=b*temp;
    return b;
}


