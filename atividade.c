#include <stdio.h>

#define MAX 50

void imprimir(int v[], int n);
int buscaBinaria(int v[], int n, int valor);
void remover(int v[], int *n, int valor);
void inserir(int v[], int *n, int valor);

int main() {
    int v[MAX], n, op, valor, qtd;

    do {
        printf("Digite o tamanho inicial do vetor (3 a 50): ");
        scanf("%d", &n);
    } while (n < 3 || n > MAX);

    qtd = 0;
    printf("Digite %d valores inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        inserir(v, &qtd, valor);
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Inserir elemento\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            imprimir(v, qtd);
        }
        else if (op == 2) {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            printf("Posicao: %d\n", buscaBinaria(v, qtd, valor));
        }
        else if (op == 3) {
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            remover(v, &qtd, valor);
        }
        else if (op == 4) {
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            inserir(v, &qtd, valor);
        }
    } while (op != 0);

    return 0;
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int buscaBinaria(int v[], int n, int valor) {
    int esq = 0, dir = n - 1, meio;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (v[meio] == valor) return meio;
        else if (v[meio] < valor) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

void remover(int v[], int *n, int valor) {
    int pos = buscaBinaria(v, *n, valor);
    if (pos != -1) {
        for (int i = pos; i < *n - 1; i++) {
            v[i] = v[i + 1];
        }
        (*n)--;
    }
}

void inserir(int v[], int *n, int valor) {
    if (*n >= MAX) return;
    int i = *n - 1;
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = valor;
    (*n)++;
}
