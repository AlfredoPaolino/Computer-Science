#include <stdio.h>
#include <stdlib.h>
#define N 5

float avgVect (int v[]);
int upperLimit (int v[], float limit);

int main()
{
    int v[N], i, sopra_soglia;
    float media, soglia;
    for (i=0;i<N;i++){
        printf("inserire valori: ");
        scanf("%d", &v[i]);
    }
    printf("inserire soglia: ");
    scanf("%f", &soglia);
    media=avgVect(v);
    sopra_soglia=upperLimit(v, soglia);
    printf("media: %f   n", media);
    printf("valori sopra la soglia inserita: %d", sopra_soglia);
    return 0;
}

float avgVect (int v[]){
    int i;
    float media;
    media=0;
    for (i=0;i<N;i++)
        media+=v[i];
    media/=N;
    return media;
}
int upperLimit (int v[], float limit){
     int i, count;
     count=0;
    for (i=0;i<N;i++){
        if (v[i]>limit)
            count++;
    }
    return count;
}
