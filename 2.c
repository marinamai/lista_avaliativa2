#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[31];
    char posicao;
    int forca;
} Jogador;
double calcularForcaPonderada(Jogador jogadores[]){
    double forca = 8 * jogadores[0].forca;
    for (int i = 1; i < 11; i++) {
        switch (jogadores[i].posicao){
            case 'L':
            case 'Z':
            case 'V':
                forca += 10 * jogadores[i].forca;
                break;
            case 'M':
                forca += 11 * jogadores[i].forca;
                break;
            case 'A':
                forca += 12 * jogadores[i].forca;
                break;
            default:
                break;
        }
    }
    return forca/100;
}
int main(){
    Jogador time1[11], time2[11];
    char nome_time1[31], nome_time2[31];
    for (int i = 0; i < 2; i++){
        scanf("%30s", (i == 0) ? nome_time1:nome_time2);
        for (int j = 0; j < 11; j++){
            scanf("%30s;%c;%d", (i == 0) ? time1[j].nome:time2[j].nome, &time1[j].posicao, &time1[j].forca);
        }
    }
    double forca_time1 = calcularForcaPonderada(time1);
    double forca_time2 = calcularForcaPonderada(time2);
    printf("%s: %.2lf de forca\n", nome_time1, forca_time1);
    printf("%s: %.2lf de forca\n", nome_time2, forca_time2);
    if (forca_time1 > forca_time2) {
        printf("%s eh mais forte\n", nome_time1);
    } else if (forca_time2 > forca_time1) {
        printf("%s eh mais forte\n", nome_time2);
    } else{
        printf("Os times tem a mesma forca\n");
    }
    return 0;
}
