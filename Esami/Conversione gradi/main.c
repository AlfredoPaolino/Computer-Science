#include <stdio.h>
#include <stdlib.h>

int main()
{
char scala;
float gradi, new_gradi;

printf("inserire la scala di partenza; 'C' per Celsius, 'F' per Farhenheit: ");
scanf("%c", &scala);
printf("inserire i gradi: ");
scanf("%f", &gradi);
if (scala=='C') {
    new_gradi=(gradi*9/5)+32;
    printf("\n%f gradi Celsius corrispondono a %f gradi Farhenheit", gradi, new_gradi);
}
else if (scala=='F'){
    new_gradi=(gradi-32)*5/9;
    printf("\n%f gradi Farhenheit corrispondono a %f gradi Celsius", gradi, new_gradi);
}
    return 0;
}
