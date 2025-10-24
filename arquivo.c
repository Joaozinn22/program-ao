#include <stdio.h>
#include <stdlib.h>

void criarArquivo();
void listarNumeros();
void buscarNumero();
void substituirNumero();
void excluirNumero();

int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Criar arquivo\n");
        printf("2 - Listar numeros\n");
        printf("3 - Buscar numero\n");
        printf("4 - Substituir numero\n");
        printf("5 - Excluir numero\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: criarArquivo(); break;
            case 2: listarNumeros(); break;
            case 3: buscarNumero(); break;
            case 4: substituirNumero(); break;
            case 5: excluirNumero(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}

void criarArquivo() {
    FILE *fp = fopen("dados.bin", "wb");
    int n, num;
    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);
}

void listarNumeros() {
    FILE *fp = fopen("dados.bin", "rb");
    int num;
    printf("Numeros salvos no arquivo:\n");
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        printf("%d ", num);
    }
    printf("\n");
    fclose(fp);
}

void buscarNumero() {
    FILE *fp = fopen("dados.bin", "rb");
    int num, busca, encontrado = 0;
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &busca);
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        if (num == busca) {
            encontrado = 1;
            break;
        }
    }
    fclose(fp);
    if (encontrado)
        printf("Numero %d encontrado.\n", busca);
    else
        printf("Numero %d NAO encontrado.\n", busca);
}

void substituirNumero() {
    FILE *fp = fopen("dados.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    int num, antigo, novo;
    printf("Digite o numero que deseja substituir: ");
    scanf("%d", &antigo);
    printf("Digite o novo numero: ");
    scanf("%d", &novo);
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        if (num == antigo)
            num = novo;
        fwrite(&num, sizeof(int), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("dados.bin");
    rename("temp.bin", "dados.bin");
}

void excluirNumero() {
    FILE *fp = fopen("dados.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    int num, excluir;
    printf("Digite o numero que deseja excluir: ");
    scanf("%d", &excluir);
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        if (num != excluir)
            fwrite(&num, sizeof(int), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("dados.bin");
    rename("temp.bin", "dados.bin");
}