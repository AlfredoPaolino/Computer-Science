#include <stdio.h>
#include <stdlib.h>

struct
{
    int cliente;
    int azienda1;
    int azienda2;
    int azienda3;
    int azienda4;
    int azienda5;
} identificativo;

int main(int argc, char *argv[])
{
    struct identificativo;
    FILE *fp_clienti, *fp_aggiornamento;
    if (argc!=7)
    {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
    fp_clienti=fopen(argv[1], "r");
    if (fp_clienti==NULL)
    {
        printf("ERRORE APERTURA FILE clienti.txt");
        return -1;
    }
    fp_aggiornamento=fopen(argv[6], "w");
    if (fp_aggiornamento==NULL)
    {
        printf("ERRORE APERTURA FILE aggiornamento.txt");
        return -1;
    }
    while (fscanf(fp_clienti, "%d %d %d %d %d %d", &identificativo.cliente, &identificativo.azienda1, &identificativo.azienda2, &identificativo.azienda3, &identificativo.azienda4, &identificativo.azienda5)!=EOF)
    {
        switch (argv[4][0])
        {
        case 'A':
            if (identificativo.cliente==atoi(argv[2]) || atoi(argv[2])==0)
            {
                switch (atoi(argv[3]))
                {
                case 1:
                    identificativo.azienda1+=atoi(argv[5]);
                    break;
                case 2:
                    identificativo.azienda2+=atoi(argv[5]);
                    break;
                case 3:
                    identificativo.azienda3+=atoi(argv[5]);
                    break;
                case 4:
                    identificativo.azienda4+=atoi(argv[5]);
                    break;
                case 5:
                    identificativo.azienda5+=atoi(argv[5]);
                    break;
                }
            }
            break;
        case 'V':
            if (identificativo.cliente==atoi(argv[2]) || atoi(argv[2])==0)
            {
                switch (atoi(argv[3]))
                {
                case 1:
                    identificativo.azienda1-=atoi(argv[5]);
                    break;
                case 2:
                    identificativo.azienda2-=atoi(argv[5]);
                    break;
                case 3:
                    identificativo.azienda3-=atoi(argv[5]);
                    break;
                case 4:
                    identificativo.azienda4-=atoi(argv[5]);
                    break;
                case 5:
                    identificativo.azienda5-=atoi(argv[5]);
                    break;
                }
            }
            break;
        case 'G':
            if (identificativo.cliente==atoi(argv[2]) || atoi(argv[2])==0)
            {
                switch (atoi(argv[3]))
                {
                case 1:
                    if (identificativo.azienda1==0)
                        identificativo.azienda1+=atoi(argv[5]);
                    else
                        identificativo.azienda1+=(float)atoi(argv[5])/100*identificativo.azienda1;
                    break;
                case 2:
                     if (identificativo.azienda2==0)
                        identificativo.azienda2+=atoi(argv[5]);
                    else
                        identificativo.azienda2+=(float)atoi(argv[5])/100*identificativo.azienda2;
                    break;
                case 3:
                     if (identificativo.azienda3==0)
                        identificativo.azienda3+=atoi(argv[5]);
                    else
                        identificativo.azienda3+=(float)atoi(argv[5])/100*identificativo.azienda3;
                    break;
                case 4:
                     if (identificativo.azienda4==0)
                        identificativo.azienda4+=atoi(argv[5]);
                    else
                        identificativo.azienda4+=(float)atoi(argv[5])/100*identificativo.azienda4;
                    break;
                case 5:
                     if (identificativo.azienda5==0)
                        identificativo.azienda5+=atoi(argv[5]);
                    else
                        identificativo.azienda5+=(float)atoi(argv[5])/100*identificativo.azienda5;
                    break;
                }
            }
            break;
        default:
            printf("nessuna azione svolta");
            break;
        }
        fprintf(fp_aggiornamento, "%d %d %d %d %d %d\n", identificativo.cliente, identificativo.azienda1, identificativo.azienda2, identificativo.azienda3, identificativo.azienda4, identificativo.azienda5);
    }
    fclose(fp_clienti);
    fclose(fp_aggiornamento);
    return 0;
}
