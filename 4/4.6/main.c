#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, somma, media, i;
    float N;
    somma=0;
    printf("inserire soglia: ");
    scanf("%f",&N);
    for (i=1;i<=10;i++)
    {
        printf("inserire numero: ");
        scanf("%d",&n);
        somma+=n;
        media=somma/i;
        if (media<N)
            break;
    }

    return 0;
}
