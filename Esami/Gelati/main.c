#include <stdio.h>
#include <stdlib.h>

#define G 100
#define M 40
#define P 10

int main(int argc, char* argv[])
{
    int grandi_disponibili, medie_disponibili, piccole_disponibili;
    int gelati_richiesti, eccesso;
    FILE* fp;
    if (argc!=3) {
        printf("ERRORE NUMERO PARAMETRI");
        return -1;
    }
    fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("ERRORE APERTURA FILE");
        return-1;
    }
    fscanf(fp, "%d %d %d", &grandi_disponibili, &medie_disponibili, &piccole_disponibili);
    fclose(fp);
    gelati_richiesti=atoi(argv[2]);
    if ((grandi_disponibili*G+medie_disponibili*M+piccole_disponibili*P)<gelati_richiesti) {
        printf("Non ci sono abbastanza gelati: solo %.0f%% disponibile", (float)(grandi_disponibili*G+medie_disponibili*M+piccole_disponibili*P)*100/gelati_richiesti);
    }
    else {
        grandi_disponibili-=gelati_richiesti/G;
        gelati_richiesti%=G;
        medie_disponibili-=gelati_richiesti/M;
        gelati_richiesti%=M;
        piccole_disponibili-=gelati_richiesti/P;
        eccesso=gelati_richiesti%P;
        fp=fopen(argv[1], "w");
        fprintf(fp, "%d %d %d", grandi_disponibili, medie_disponibili, piccole_disponibili);
        fclose(fp);
        printf("Le confezioni rimanenti in magazzino sono:\n%d confezioni grandi\n%d confezioni medie\n%d confezioni piccole", grandi_disponibili, medie_disponibili, piccole_disponibili);
        if (eccesso!=0)
            printf("Non e' possibile rispondere in modo esatto alla richiesta, saranno forniti %d gelati extra", gelati_richiesti%P);
    }
    return 0;
}
