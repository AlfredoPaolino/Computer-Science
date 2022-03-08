#include <stdio.h>
#include <stdlib.h>

int main()
{
    int giorno, mese, anno;
    printf("inserire giorno: ");
    scanf("%d", &giorno);
    printf("inserire mese: ");
    scanf("%d", &mese);
    printf("inserire anno: ");
    scanf("%d", &anno);
    if (mese<1&&mese>12)
        {
        printf("ERRORE NELLA SELEZIONE DEL MESE");
        return -1;
    }
    switch(mese)
    {
        case 1:
        printf("%d Gennaio %d", giorno, anno);
        break;

        case 2:
        printf("%d Febbraio %d", giorno, anno);
        break;

        case 3:
        printf("%d Marzo %d", giorno, anno);
        break;

        case 4:
        printf("%d Aprile %d", giorno, anno);
        break;

        case 5:
        printf("%d Maggio %d", giorno, anno);
        break;

        case 6:
        printf("%d Giugno %d", giorno, anno);
        break;

        case 7:
        printf("%d Luglio %d", giorno, anno);
        break;

        case 8:
        printf("%d Agosto %d", giorno, anno);
        break;

        case 9:
        printf("%d Settembre %d", giorno, anno);
        break;

        case 10:
        printf("%d Ottobre %d", giorno, anno);
        break;

        case 11:
        printf("%d Novembre %d", giorno, anno);
        break;

        case 12:
        printf("%d Dicembre %d", giorno, anno);
        break;
    }
    return 0;
}
