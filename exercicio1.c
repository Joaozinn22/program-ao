#include <stdio.h>

int main() {
    double salario, imposto;
    double aliquota;
    double parcela_deduzir;

    printf("Digite o salário bruto: ");
    scanf("%lf", &salario);

    if (salario <= 2112.00) {
        aliquota = 0.0;
        parcela_deduzir = 0.0;
    } else if (salario <= 2826.65) {
        aliquota = 7.5;
        parcela_deduzir = 158.40;
    } else if (salario <= 3751.05) {
        aliquota = 15.0;
        parcela_deduzir = 370.40;
    } else if (salario <= 4664.68) {
        aliquota = 22.5;
        parcela_deduzir = 651.73;
    } else {
        aliquota = 27.5;
        parcela_deduzir = 884.96;
    }

    imposto = (salario * (aliquota / 100)) - parcela_deduzir;

    if (imposto < 0) {
        imposto = 0.0;
    }

    printf("Alíquota aplicada: %lf%%\n", aliquota);
    printf("Imposto de renda retido na fonte: R$ %lf\n", imposto);

    return 0;
}
