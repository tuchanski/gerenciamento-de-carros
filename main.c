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
    FILE *fileRead = fopen("../dados/dados.txt", "r");

    if (fileRead == NULL)
    {
        printf("\nErro: não foi possível efetuar a leitura de dados.txt");
        return 1;
    }
    else
    {
        No *cabeca = NULL;

        Carro car1 = {"Toyota", "Corolla", 2015, 60000, 50000.00};
        Carro car2 = {"Honda", "Civic", 2018, 30000, 75000.00};
        Carro car3 = {"Ford", "Focus", 2012, 90000, 35000.00};
        Carro car4 = {"Chevrolet", "Cruze", 2020, 15000, 70000.00};

        inserirCarro(&cabeca, car1);
        inserirCarro(&cabeca, car2);
        inserirCarro(&cabeca, car3);
        inserirCarro(&cabeca, car4);

        imprimirLista(cabeca);

        return 0;
    }
}
