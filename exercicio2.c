#include <stdio.h> 

int main(){
    double peso, altura, imc;
    imc = 0;

    printf("Digite seu peso: \n");
    scanf("%lf", &peso);

    printf("Digite sua altura: \n");
    scanf("%lf", &altura);

    imc = peso / (altura * altura);

    if (imc < 18.5){
        printf("Abaixo do peso\n");
    }else if (imc <= 24.9){
        printf("Peso normal\n");
    }else if (imc <= 29.9){
        printf("Sobrepeso\n");
    }else {
        printf("OBESIDADE\n");
    }

    return 0;
}
