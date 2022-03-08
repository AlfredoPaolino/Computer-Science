#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dati1 {
char numero_tessera[5+1];
char data_visita[10+1];
char ora_ingresso[8+1];
char ora_uscita[8+1];
char data_nascita[10+1];
};

struct dati2 {
int giorno;
int mese;
int anno;
};

struct dati3 {
int giorno;
int mese;
int anno;
};

struct dati4 {
int ore;
int minuti;
int secondi;
};

struct dati5 {
int ore;
int minuti;
int secondi;
};

int main(int argc, char* argv[])
{
    struct dati1 profilo;
    struct dati2 visita;
    struct dati3 nascita;
    struct dati4 ingresso;
    struct dati5 uscita;
    int count_visite=0;
    int tempo_ingresso, tempo_uscita, max_tempo=0, mese_confronto, giorno_confronto, count_assidui=0;
    int i, confronto[argc-3], flag_assiduo[argc-3];
    float count_prezzo=0;
    float prezzo_bambini, prezzo_giovani, prezzo_adulti;
    char path;
    FILE* fp_visite;
    FILE* fp_prezzi;
    fp_prezzi=fopen("prezzi.txt","r");
    fscanf(fp_prezzi,"%f", &prezzo_bambini);
    fscanf(fp_prezzi,"%f", &prezzo_giovani);
    fscanf(fp_prezzi,"%f", &prezzo_adulti);
    fclose(fp_prezzi);
    for (i=0;i<argc-3;i++) {
        confronto[i]=0;
        flag_assiduo[i]=0;
    }
    fp_visite=fopen("visite.txt","r");
    sscanf(argv[2],"%c", &path);
    if (path=='S') {
        while (fscanf(fp_visite,"%s %s %s %s %s", profilo.numero_tessera, profilo.data_visita, profilo.ora_ingresso, profilo.ora_uscita, profilo.data_nascita)!=EOF) {
            sscanf(profilo.data_visita,"%d/%d/%d", &visita.giorno, &visita.mese, &visita.anno);
            if (visita.anno==(atoi(argv[1]))) {
                count_visite++;
                sscanf(profilo.data_nascita,"%d/%d/%d", &nascita.giorno, &nascita.mese, &nascita.anno);
                if ((atoi(argv[1]))-nascita.anno<11)
                    count_prezzo+=prezzo_bambini;
                else if ((atoi(argv[1]))-nascita.anno>=11 && ((atoi(argv[1]))-nascita.anno<=17))
                    count_prezzo+=prezzo_giovani;
                else if ((atoi(argv[1]))-nascita.anno>=18)
                    count_prezzo+=prezzo_adulti;
                sscanf(profilo.ora_ingresso,"%d:%d%d", &ingresso.ore, &ingresso.minuti, &ingresso.secondi);
                sscanf(profilo.ora_uscita,"%d:%d%d", &uscita.ore, &uscita.minuti, &uscita.secondi);
                ingresso.ore*=60;
                uscita.ore*=60;
                tempo_ingresso=ingresso.ore+ingresso.minuti;
                tempo_uscita=uscita.ore+uscita.minuti;
                if ((tempo_uscita-tempo_ingresso)>max_tempo)
                    max_tempo=tempo_uscita-tempo_ingresso;
            }
        }
        printf("%d\n", count_visite);
        printf("%f\n", count_prezzo);
        printf("%d minuti", max_tempo);
    }
    else if (path=='G') {
        while (fscanf(fp_visite,"%s %s %s %s %s", profilo.numero_tessera, profilo.data_visita, profilo.ora_ingresso, profilo.ora_uscita, profilo.data_nascita)!=EOF) {
                sscanf(profilo.data_visita,"%d/%d/%d", &visita.giorno, &visita.mese, &visita.anno);
                if (visita.anno==(atoi(argv[1]))) {
                        for (i=3;i<argc;i++) {
                            if (atoi(profilo.numero_tessera)==(atoi(argv[i]))) {
                                if (confronto[i-3]==0) {
                                    confronto[i-3]=1;
                                    mese_confronto=visita.mese;
                                    giorno_confronto=visita.giorno;
                                }
                                else if (confronto[i-3]==1 && flag_assiduo[i-3]==0) {
                                    if (mese_confronto==visita.mese && giorno_confronto-visita.giorno<=3) {
                                        count_assidui++;
                                        flag_assiduo[i-3]=1;
                                    }
                                }

                            }
                        }
                    }
                }
            printf("%d assidui", count_assidui);
    }
    return 0;
}
