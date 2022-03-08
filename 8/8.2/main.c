#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 80

int main()
{
    int i, count;
    char stringa[N+1];
    printf("inserire stringa: ");
    gets(stringa);
    for (i=0;i<strlen(stringa);i++){
        stringa[i]=tolower(stringa[i]);
        if (isalnum(stringa[i])==0)
            stringa[i]='_';
        if (isdigit(stringa[i])!=0)
            stringa[i]='*';
    }
    count=0;
    for (i=0;i<strlen(stringa);i++){
        if (stringa[i]=='_')
            count++;
    }
    if (stringa[strlen(stringa)-1]!='_')
        count++;
    printf("nuova stringa: %s", stringa);
    printf("\nnumero parole: %d", count);
    return 0;
}
