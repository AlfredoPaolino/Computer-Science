#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    float somma;
    somma=0;
    i=0;
    do {
        printf("inserire numero: ");
        scanf("%d",&num);
        if (num==0)
            break;
        somma+=num;
        i++;
    }
    while (num!=0);
    printf("media= %f",somma/i);
    return 0;
}
