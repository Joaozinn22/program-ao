#include <stdio.h>

int main() {
    double nota1[30], nota2[30], media[30];
    double soma = 0, mediaTurma;
    int i;

    for(i = 0; i < 30; i++) {
        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%lf", &nota1[i]);
        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%lf", &nota2[i]);

        media[i] = (nota1[i]*2 + nota2[i]*3) / 5;
        soma += media[i];
    }

    mediaTurma = soma / 30;
    printf("\nMedia da turma: %.2lf\n", mediaTurma);

    printf("\nAlunos acima da media da turma:\n");
    for(i = 0; i < 30; i++) {
        if(media[i] > mediaTurma) {
            printf("Aluno %d - Nota1: %.2lf, Nota2: %.2lf, Media: %.2lf\n", i+1, nota1[i], nota2[i], media[i]);
        }
    }

    return 0;
}