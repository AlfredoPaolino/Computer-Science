#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cases
{
    int N;
    int R;
    int M;
};

int main()
{
    int i, j;
    struct cases chess[50];
    long int rice;
    long int bag_left;
    int T=1;
    FILE* fp_in;
    FILE* fp_out;

    fp_in=fopen("input.txt", "r");
    if (fp_in==NULL)
    {
        printf("ERROR");
        return-1;
    }
    fp_out=fopen("output.txt", "w");
    if (fp_out==NULL)
    {
        printf("ERROR");
        return-1;
    }

    fscanf(fp_in, "%d", &T);
    for (j=1; j<=T; j++)
    {
        fscanf(fp_in, "%d %d %d", &chess[j-1].R, &chess[j-1].N, &chess[j-1].M);
    }
    for (j=1; j<=T; j++)
    {
        rice=0;
        for (i=0; i<chess[j-1].N*chess[j-1].N; i++)
        {
            rice+=pow(chess[j-1].R,i);
        }
        bag_left=rice%chess[j-1].M;
        fprintf(fp_out, "Case #%d: %lu\n", j, bag_left);
    }
    return 0;
}
