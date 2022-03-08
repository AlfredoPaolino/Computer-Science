#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, x3, i;
    x1=0;
    x2=1;
    printf("%d ",x1);
    printf("%d ",x2);
    for (i=0;i<20;i++)
    {
        x3=x2+x1;
        printf("%d ",x3);
        x1=x2;
        x2=x3;
    }
    return 0;
}
