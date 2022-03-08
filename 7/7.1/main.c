#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

int main()
{
    int i;
    float v_base[N], v_esponente[N], v_res[N];
    for (i=0;i<N;i++){
        printf("inserire base %d: ", i);
        scanf("%f", &v_base[i]);
        }
    for (i=0;i<N;i++){
        printf("inserire esponente %d: ", i);
        scanf("%f", &v_esponente[i]);
        }
    for (i=0;i<N;i++)
        v_res[i]=pow(v_base[i], v_esponente[i]);
    for (i=0;i<N;i++)
        printf("%f^%f=%f\n", v_base[i], v_esponente[i], v_res[i]);
    return 0;
}
