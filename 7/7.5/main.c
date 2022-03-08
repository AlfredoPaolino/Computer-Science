#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char a, b;
    printf("inserire primo carattere: ");
    scanf("%c%*c", &a);
    printf("inserire secondo carattere: ");
    scanf("%c%*c", &b);
    if (isalpha(a)!=0 && isalpha(b)!=0){
        if (a==b)
            printf("i due caratteri sono uguali");
        else {
            if (a<b){
                printf("%c ", a);
                printf("%c ", b);
            }
            else {
                printf("%c ", b);
                printf("%c ", a);
            }
        }
    }
    else {
        if (isdigit(a)==1 || isdigit(b)==1)
            printf("uno dei caratteri e' una cifra");
    }
    return 0;
}
