#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define N 4

struct coordinate
{
    int x;
    int y;
}coordinate[N];

int main(int argc, char *argv[])
{
    struct coordinate;
    int i;
    float lunghezza, lunghezza_minima;
    if (!(argc==2))
    {
        printf("errore numero parametri");
        return -1;
    }
    for (i=0;i<N;i++)
    {
        printf("inserire ascissa %d: ", i+1);
        scanf("%d", &coordinate[i].x);
        printf("inserire ordinata %d: ", i+1);
        scanf("%d", &coordinate[i].y);
    }
    if (argv[1][1]=='m')
    {
        lunghezza=0;
        for (i=0;i<N-1;i++)
            lunghezza+=sqrt(pow(coordinate[i+1].x-coordinate[i].x, 2)+pow(coordinate[i+1].y-coordinate[i].y, 2));
        printf("%f ", lunghezza);
    }
    if (argv[1][1]=='a')
    {
        lunghezza_minima=INT_MAX;
        for (i=0;i<N-1;i++)
        {
            lunghezza=sqrt(pow(coordinate[i+1].x-coordinate[i].x, 2)+pow(coordinate[i+1].y-coordinate[i].y, 2));
            if (lunghezza<lunghezza_minima)
                lunghezza_minima=lunghezza;
        }
        printf("%f", lunghezza_minima);
    }
    return 0;
}
