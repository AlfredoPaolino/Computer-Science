#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char testo;
    i=0;
    do {
        testo=getchar();

        putchar(testo);
    }
    while (testo!=EOF);

    return 0;
}
