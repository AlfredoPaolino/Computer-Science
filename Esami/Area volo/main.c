#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define R 50
#define C 50
#define XY 100

int main(int argc, char *argv[])
{
    char area[R][C], controllo[C];
    int ascissa[XY], ordinata[XY];
    int i, j, k, righe, colonne, numero_coordinate, flag=0;
    int errore_piano=0, errore_area=0, spostamento_dx, spostamento_sx;
    FILE *fp_area;
    FILE *fp_piano;
    if (argc!=3)
    {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
    fp_area=fopen(argv[1], "r");
    if (fp_area==NULL)
    {
        printf("ERRORE APERTRUTA FILE");
        return -1;
    }
    fp_piano=fopen(argv[2], "r");
    if (fp_piano==NULL)
    {
        printf("ERRORE APERTURA FILE");
        return -1;
    }
    i=0;
    while (fscanf(fp_area, "%s", controllo)!=EOF)
    {
        strcpy(area[i], controllo);
        i++;
    }
    fclose(fp_area);
    righe=i;
        colonne=strlen(area[0]);
    printf(" %d %d\n", righe, colonne);

    i=0;
    while (!feof(fp_piano))
    {
        fscanf(fp_piano, "%d %d", &ordinata[i], &ascissa[i]);
        fgetc(fp_piano);
        i++;
    }
    fclose(fp_piano);
    numero_coordinate=i-1;
    for (i=0;i<righe;i++)
    {
        for (j=0;j<colonne;j++)
            if (!(area[i][j]=='*' || isalpha(area[i][j])!=0))
            {
                printf("errore area di volo in %d %d", i, j);
                errore_area=1;
            }
    }
    for (i=0;i<numero_coordinate;i++)
    {
        if (ascissa[i]>righe-1 || ordinata[i]>colonne-1 || ascissa[i]<0 || ordinata[i]<0)
        {
             printf("errore piano di volo %d %d\n", ascissa[i], ordinata[i]);
             errore_piano=1;
        }
    }
    if (errore_area==0 && errore_piano==0)
    {
        printf("sequenza della rotta: ");
        for (i=0;i<numero_coordinate;i++)
            printf("%c", area[ascissa[i]][ordinata[i]]);
        printf("\n");
        for (i=0;i<numero_coordinate && flag==0;i++)
        {
            if (area[ascissa[i]][ordinata[i]]=='*')
            {
                printf("rotta ricalcolata: ");
                flag=1;
            }
            for (j=0;j<numero_coordinate && flag==1;j++)
            {
                k=0;
                while (area[ascissa[j]][ordinata[j]+k]=='*')
                {
                    k++;
                }
                spostamento_dx=k;
                k=0;
                while (area[ascissa[j]][ordinata[j]-k]=='*')
                {
                    k++;
                }
                spostamento_sx=k;
                if (spostamento_dx<spostamento_sx)
                    printf("%c", area[ascissa[j]][ordinata[j]+spostamento_dx]);
                else
                    printf("%c", area[ascissa[j]][ordinata[j]-spostamento_sx]);
            }
        }
    }
    return 0;
}
