#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 80

int main()
{
    int i, j, count_alpha, count_num, count, flag;
    char stringa[N+1], stringa2[N+1];
    printf("inserire stringa: ");
    gets(stringa);
    printf("la stringa e' lunga %d caratteri\n", strlen(stringa));
    count_alpha=0;
    count_num=0;
    for (i=0;i<strlen(stringa);i++){
        if (isalpha(stringa[i])!=0)
            count_alpha++;
        if (isdigit(stringa[i])!=0)
            count_num++;
    }
    printf("numero caratteri alfabetici: %d\n", count_alpha);
    printf("numero caratteri numerici: %d\n", count_num);
    printf("inserire stringa da verificare: ");
    scanf("%s", stringa2);
    flag=0;
    for (i=0;i<=strlen(stringa)-strlen(stringa2) && flag==0;i++){
        count=0;
        for (j=0;j<strlen(stringa2);j++){
            if (stringa[i+j]==stringa2[j])
                count++;
        }
        if (count==strlen(stringa2)){
            printf("la seconda stringa e' contenuta nella prima");
            flag=1;
        }
    }
    return 0;
}
