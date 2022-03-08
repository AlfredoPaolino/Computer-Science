#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int count_char, count_alpha, count_upper, count_digit, count_space;
    char carattere;
    count_char=0;
    count_alpha=0;
    count_upper=0;
    count_digit=0;
    count_space=0;
    do {
        carattere=getchar();
        if (carattere!='\n'){
            count_char++;
            if (isalpha(carattere)==1)
                count_alpha++;
            if (isupper(carattere)==1)
                count_upper++;
            if (isdigit(carattere)==1)
                count_digit++;
            if (carattere==' ')
                count_space++;
        }
    }
    while (carattere!='\n');
    printf("caratter introdotti: %d\n", count_char);
    printf("caratteri alfabetici introdotti: %d\n", count_alpha);
    printf("caratteri maiuscoli introdotti: %d\n", count_upper);
    printf("cifre decimali introdotte: %d\n", count_digit);
    printf("caratteri di spaziatura introdotti: %d", count_space);
    return 0;
}
