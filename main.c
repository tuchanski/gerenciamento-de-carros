#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL 20

typedef struct
{
    char marca[TOTAL];
    char modelo[TOTAL];
    int anoFabricacao;
    int kilometragem;
    float preco;
} Carro;

typedef struct No
{
    Carro carro;
    struct No *proximo;
} No;

No *criarNo(Carro carro)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo != NULL)
    {
        novoNo->carro = carro;
        novoNo->proximo = NULL;
    }
    return novoNo;
}

void inserirCarro(No **cabeca, Carro novoCarro)
{
    No *novoNo = criarNo(novoCarro);
    if (novoNo == NULL)
    {
        printf("\nErro: não foi possivel alocar memória.");
        return;
    }

    if (*cabeca == NULL || (*cabeca)->carro.preco > novoCarro.preco)
    {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    }
    else
    {
        No *atual = *cabeca;
        while (atual->proximo != NULL && atual->proximo->carro.preco <= novoCarro.preco)
        {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

void imprimirLista(No *no)
{
    while (no != NULL)
    {
        printf("Marca: %s\n", no->carro.marca);
        printf("Modelo: %s\n", no->carro.modelo);
        printf("Ano de Fabricação: %d\n", no->carro.anoFabricacao);
        printf("Kilometragem: %d\n", no->carro.kilometragem);
        printf("Preço: %.2f\n\n", no->carro.preco);
        no = no->proximo;
    }
}

int main(void)
{
    FILE *dadosArquivo = fopen("../dados/dados.txt", "r");

    if (dadosArquivo == NULL)
    {
        printf("\nErro: não foi possível efetuar a leitura de dados.txt");
        return 1;
    }
    else
    {
        No *cabeca = NULL;
        char linha[256];

        while (fgets(linha, sizeof(linha), dadosArquivo)){
            
            Carro novoCarro;
            strcpy(novoCarro.marca, strtok(linha, "\n"));

            fgets(linha, sizeof(linha), dadosArquivo);
            strcpy(novoCarro.modelo, strtok(linha, "\n"));

            fgets(linha, sizeof(linha), dadosArquivo);
            novoCarro.anoFabricacao = atoi(strtok(linha, "\n"));

            fgets(linha, sizeof(linha), dadosArquivo);
            novoCarro.kilometragem = atoi(strtok(linha, "\n"));

            fgets(linha, sizeof(linha), dadosArquivo);
            novoCarro.preco = atof(strtok(linha, "\n"));

            inserirCarro(&cabeca, novoCarro);
        }

        fclose(dadosArquivo);

        imprimirLista(cabeca);

        return 0;
    }
}
