#include <stdio.h>

#define N 5


typedef struct {
    char nome[20];
    int veiculos;
    int acidentes;
} Estado;

void carregarDados(Estado v[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Nome do estado: ");
        scanf("%s", v[i].nome);
        printf("Numero de veiculos: ");
        scanf("%d", &v[i].veiculos);
        printf("Numero de acidentes: ");
        scanf("%d", &v[i].acidentes);
        printf("------------------------------\n");
    }
}


void maiorMenor(Estado v[], int *posMaior, int *posMenor) {
    int i;
    *posMaior = 0;
    *posMenor = 0;

    for (i = 1; i < N; i++) {
        if (v[i].acidentes > v[*posMaior].acidentes)
            *posMaior = i;

        if (v[i].acidentes < v[*posMenor].acidentes)
            *posMenor = i;
    }
}


float percentual(Estado e) {
    return ( (float)e.acidentes / e.veiculos ) * 100;
}

float mediaAcidentes(Estado v[]) {
    int i, soma = 0;

    for (i = 0; i < N; i++)
        soma += v[i].acidentes;

    return (float)soma / N;
}

void acimaMedia(Estado v[], float media) {
    int i;
    printf("\nEstados acima da media:\n");

    for (i = 0; i < N; i++) {
        if (v[i].acidentes > media) {
            printf("%s - %d acidentes\n", v[i].nome, v[i].acidentes);
        }
    }
}


int main() {

    Estado estados[N] = {
        {"MG", 5360000, 75000},
        {"RJ", 4780000, 95000},
        {"SP", 14620000, 180000},
        {"ES", 1600000, 25000},
        {"BA", 3200000, 48000}
    };

    int posMaior, posMenor;
    float media;

    maiorMenor(estados, &posMaior, &posMenor);

    printf("Estado com maior numero de acidentes: %s (%d)\n",
           estados[posMaior].nome, estados[posMaior].acidentes);

    printf("Estado com menor numero de acidentes: %s (%d)\n",
           estados[posMenor].nome, estados[posMenor].acidentes);

    printf("\nPercentuais:\n");
    for (int i = 0; i < N; i++) {
        printf("%s: %.2f%%\n", estados[i].nome, percentual(estados[i]));
    }

    media = mediaAcidentes(estados);
    printf("\nMedia de acidentes no pais: %.2f\n", media);

    acimaMedia(estados, media);

    return 0;
}