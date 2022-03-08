#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct accesso
{
    char data[10+1];
    char ora[8+1];
    char username[10+1];
    char corretto;
} accesso;

int elapsed_time(char entrata1[], char entrata2[]);

int main(int argc, char *argv[])
{
    struct accesso;
    int flag_uno=0, flag_due=0, flag_tre=0, i;
    int tempo, count_falliti[argc-1], count_maggiore=0;
    char primo_accesso [6][8+1];
    char nome[10+1];
    FILE *fp;
    if (argc!=4)
    {
        printf("errore numero parametri");
        return -1;
    }
    fp=fopen("accessi.txt", "r");
    if (fp==NULL)
    {
        printf("errore apertura file");
        return -1;
    }
    printf("anomalie rilveate:\n");
    for (i=0;i<argc-1;i++)
        count_falliti[i]=0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %c", accesso.data, accesso.ora, accesso.username, &accesso.corretto);
        fgetc(fp);
        if (strcmp(accesso.username, argv[1])==0)
        {
            if (accesso.corretto=='F')
            {
               if (flag_uno==0)
               {
                   strcpy(primo_accesso[0], accesso.ora);
                    flag_uno=1;
               }
               else
               {
                   strcpy(primo_accesso[1], accesso.ora);
                   tempo=elapsed_time(primo_accesso[0], primo_accesso[1]);
                   if (tempo<=60)
                   {
                       count_falliti[0]++;
                       printf("%s   %s  %s  %s\n", accesso.username, accesso.data, primo_accesso[0], primo_accesso[1]);
                       flag_uno=0;
                   }
                   else
                   {
                       strcpy(primo_accesso[0], primo_accesso[1]);
                   }
               }
            }
        }
        if (strcmp(accesso.username, argv[2])==0)
        {
            if (accesso.corretto=='F')
            {
               if (flag_due==0)
               {
                   strcpy(primo_accesso[2], accesso.ora);
                                  flag_due=1;
               }
               else
               {
                   strcpy(primo_accesso[3], accesso.ora);
                   tempo=elapsed_time(primo_accesso[2], primo_accesso[3]);
                   if (tempo<=60)
                   {
                       count_falliti[1]++;
                       printf("%s   %s  %s  %s\n", accesso.username, accesso.data, primo_accesso[2], primo_accesso[3]);
                       flag_due=0;
                   }
                   else
                   {
                       strcpy(primo_accesso[2], primo_accesso[3]);
                   }
               }
            }
        }
        if (strcmp(accesso.username, argv[3])==0)
        {
            if (accesso.corretto=='F')
            {
               if (flag_tre==0)
               {
                   strcpy(primo_accesso[4], accesso.ora);
                   flag_tre=1;
               }
               else
               {
                   strcpy(primo_accesso[5], accesso.ora);
                   tempo=elapsed_time(primo_accesso[4], primo_accesso[5]);
                   if (tempo<=60)
                   {
                       count_falliti[2]++;
                       printf("%s   %s  %s  %s\n", accesso.username, accesso.data, primo_accesso[4], primo_accesso[5]);
                       flag_tre=0;
                   }
                   else
                   {
                       strcpy(primo_accesso[4], primo_accesso[5]);
                   }
               }
            }
        }
    }
    fclose(fp);
    for (i=0;i<argc;i++)
    {
        if (count_falliti[i]>count_maggiore)
        {
            count_maggiore=count_falliti[i];
            strcpy(nome,argv[i]);
        }
    }
    printf("numero totale anomalie: %d\n", count_falliti[0]+count_falliti[1]+count_falliti[2]);
    printf("utente con il maggior numero di anomalie: %s", nome);
    return 0;
}

int elapsed_time(char entrata1[], char entrata2[])
{
    int ora1, minuto1, secondo1;
    int ora2, minuto2, secondo2;
    int time;
    sscanf(entrata1, "%d:%d:%d", &ora1, &minuto1, &secondo1);
    sscanf(entrata2, "%d:%d:%d", &ora2, &minuto2, &secondo2);
    ora1=ora1*3600;
    minuto1=minuto1*60;
    ora2=ora2*3600;
    minuto2=minuto2*60;
    time=ora2+minuto2+secondo2-(ora1+minuto1+secondo1);
    return time;
}
