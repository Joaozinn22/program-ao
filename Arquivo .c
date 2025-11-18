#include <stdio.h>
#include <string.h>

#define TAM 100

// Structs
typedef struct {
    int codigo;
    char nome[50];
} Categoria;

typedef struct {
    char titulo[100];
    char descricao[256];
    int codCategoria; 
    double preco;    
} Produto;

// Q1 - Cadastrar categorias
void cadastrarCategorias(Categoria v[], int *qt) {
    int op = 1;
    while (*qt < TAM && op == 1) {
        printf("\nCategoria %d:\n", *qt + 1);
        printf("Código: ");
        scanf("%d", &v[*qt].codigo);
        printf("Nome: ");
        getchar(); // limpa buffer
        fgets(v[*qt].nome, 50, stdin);
        v[*qt].nome[strcspn(v[*qt].nome, "\n")] = 0; // remove \n
        (*qt)++;
        if (*qt < TAM) {
            printf("Deseja cadastrar outra categoria? (1-Sim / 0-Não): ");
            scanf("%d", &op);
        } else {
            printf("Limite máximo atingido.\n");
        }
    }
}

// Q2 - Imprimir categorias
void imprimirCategorias(Categoria v[], int qt) {
    printf("\n--- Lista de Categorias ---\n");
    for (int i = 0; i < qt; i++) {
        printf("Código: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

// Q3 - Imprimir produtos com descrição e valor formatado
void imprimirProdutos(Produto v[], int qtd, Categoria cat[], int qtCat) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Título: %s\n", v[i].titulo);
        printf("Descrição: %s\n", v[i].descricao);
        printf("Preço: R$ %.2lf\n", v[i].preco);
        // Procurar nome da categoria
        for (int j = 0; j < qtCat; j++) {
            if (v[i].codCategoria == cat[j].codigo) {
                printf("Categoria: %s\n", cat[j].nome);
                break;
            }
        }
        printf("--------------------------\n");
    }
}

// Q4 - Selection sort por descrição
void selectionSortPorDescricao(Produto v[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(v[j].descricao, v[menor].descricao) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            Produto temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

// Q5 - Busca binária por descrição
int buscaBinariaPorDescricao(Produto v[], int qtd, char chave[]) {
    int ini = 0, fim = qtd - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(chave, v[meio].descricao);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return -1; 
}

int main() {
    Categoria categorias[TAM];
    Produto produtos[TAM];
    int qtCat = 0, qtProd = 0;

    cadastrarCategorias(categorias, &qtCat);
    imprimirCategorias(categorias, qtCat);

    return 0;
}
