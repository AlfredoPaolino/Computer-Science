#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80

int main()
{
    int i, j, flag=0;
    char stringa[MAX+1];
    while (flag==0){
    gets(stringa);
    if (stringa[0]==EOF)
        flag=1;
    for (i=0;i<strlen(stringa) && flag==0;i++){
        if (stringa[i]=='c' && stringa[i+1]=='h') {
            stringa[i]='k';
            for (j=i+1;j<strlen(stringa);j++) {
                stringa[j]=stringa[j+1];
            }
        }
    }
    for (i=0;i<strlen(stringa);i++){
        if (stringa[i]==stringa[i+1]) {
            for (j=i+1;j<strlen(stringa);j++) {
                stringa[j]=stringa[j+1];
            }
        }
    }
    printf("%s\n", stringa);
    }
    return 0;
}
