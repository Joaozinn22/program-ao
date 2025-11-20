#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[20];
    char telefone[20];
    float saldo;
} Conta;

int busca(Conta c[], int tam, int numero) {
    if (tam == 0) return -1;
    for (int i = 0; i < tam; i++) {
        if (c[i].numero == numero) return i;
    }
    return -2;
}

void cadastrarConta(Conta c[], int *tam, int numero) {
    int pos = busca(c, *tam, numero);

    if (pos >= 0) {
        printf("Numero de conta repetido.\n");
        return;
    }

    printf("Nome do titular: ");
    scanf(" %49[^\n]", c[*tam].nome);

    printf("CPF: ");
    scanf(" %19s", c[*tam].cpf);

    printf("Telefone: ");
    scanf(" %19s", c[*tam].telefone);

    c[*tam].numero = numero;
    c[*tam].saldo = 0;

    (*tam)++;
}

void consultarSaldo(Conta c[], int tam, int numero) {
    int pos = busca(c, tam, numero);
    if (pos < 0) {
        printf("Conta nao encontrada.\n");
        return;
    }
    printf("Saldo: %.2f\n", c[pos].saldo);
}

void deposito(Conta c[], int tam, int numero, float valor) {
    int pos = busca(c, tam, numero);
    if (pos < 0) {
        printf("Conta nao cadastrada.\n");
        return;
    }
    c[pos].saldo += valor;
    printf("Deposito realizado.\n");
}

void saque(Conta c[], int tam, int numero, float valor) {
    int pos = busca(c, tam, numero);
    if (pos < 0) {
        printf("Conta nao cadastrada.\n");
        return;
    }
    if (c[pos].saldo >= valor) {
        c[pos].saldo -= valor;
        printf("Saque efetuado.\n");
    } else {
        printf("Saldo insuficiente.\n");
    }
}

void exibirContas(Conta c[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Conta: %d\n", c[i].numero);
        printf("Titular: %s\n", c[i].nome);
        printf("Telefone: %s\n\n", c[i].telefone);
    }
}

int main() {
    Conta cadastroCC[MAX], cadastroCP[MAX];
    int tamCC = 0, tamCP = 0;
    int opcao, tipo, numero;
    float valor;

    do {
        printf("1-Cadastrar conta\n2-Consultar saldo\n3-Deposito\n4-Saque\n5-Exibir contas\n0-Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("1-Conta Corrente\n2-Conta Poupanca\n");
        scanf("%d", &tipo);

        printf("Numero da conta: ");
        scanf("%d", &numero);

        if (tipo == 1) {
            switch (opcao) {
                case 1: cadastrarConta(cadastroCC, &tamCC, numero); break;
                case 2: consultarSaldo(cadastroCC, tamCC, numero); break;
                case 3: printf("Valor: "); scanf("%f", &valor); deposito(cadastroCC, tamCC, numero, valor); break;
                case 4: printf("Valor: "); scanf("%f", &valor); saque(cadastroCC, tamCC, numero, valor); break;
                case 5: exibirContas(cadastroCC, tamCC); break;
            }
        } else {
            switch (opcao) {
                case 1: cadastrarConta(cadastroCP, &tamCP, numero); break;
                case 2: consultarSaldo(cadastroCP, tamCP, numero); break;
                case 3: printf("Valor: "); scanf("%f", &valor); deposito(cadastroCP, tamCP, numero, valor); break;
                case 4: printf("Valor: "); scanf("%f", &valor); saque(cadastroCP, tamCP, numero, valor); break;
                case 5: exibirContas(cadastroCP, tamCP); break;
            }
        }

    } while (1);

    return 0;
}