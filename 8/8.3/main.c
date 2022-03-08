#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main()
{
    char orario_uno[N+1], orario_due[N+1];
    int ore_uno, ore_due, minuti_uno, minuti_due, intervallo_calcolato;
    do {
        printf("inserire primo orario in formato hh:mm : ");
        gets(orario_uno);
        if (orario_uno[2]!=':')
            printf("formato non valido");
    }
    while (orario_uno[2]!=':');

    do {
        printf("inserire secondo orario in formato hh:mm : ");
        gets(orario_due);
        if (orario_due[2]!=':')
            printf("formato non valido");
    }
    while (orario_uno[2]!=':');
    if (strcmp(orario_uno, orario_due)<0){
        sscanf(orario_uno,"%d:%d", &ore_uno, &minuti_uno);
        sscanf(orario_due,"%d:%d", &ore_due, &minuti_due);
        intervallo_calcolato=(ore_due*60+minuti_due)-(ore_uno*60+minuti_uno);
        printf("delay: %d minuti", intervallo_calcolato);
    }


    return 0;
}
