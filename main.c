#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMITE 20

typedef struct Carro
{
    char marca[LIMITE];
    char modelo[LIMITE];
    int anoFabricacao;
    int kilometragem;
    float preco;
} Carro;

// Operações de Lista Encadeada

typedef struct No
{
    Carro carro;
    struct No *proximo;
} No;

// - Funções -

// Cria um nó com um carro
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

// Insere carro (registro) na Lista Encadeada ordenado por preço
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

// Cria novo carro por prompt do usuário e o insere na Lista Encadeada
void criarNovoCarro(No **cabeca)
{
    Carro novoCarro;

    printf("\nInsira os dados do novo carro:\n");

    printf("Marca: ");
    getchar();
    fgets(novoCarro.marca, sizeof(novoCarro.marca), stdin);
    novoCarro.marca[strcspn(novoCarro.marca, "\n")] = '\0';

    printf("Modelo: ");
    fgets(novoCarro.modelo, sizeof(novoCarro.modelo), stdin);
    novoCarro.modelo[strcspn(novoCarro.modelo, "\n")] = '\0';

    printf("Ano de Fabricação: ");
    scanf("%d", &novoCarro.anoFabricacao);

    printf("Kilometragem: ");
    scanf("%d", &novoCarro.kilometragem);

    printf("Preço: ");
    scanf("%f", &novoCarro.preco);

    inserirCarro(cabeca, novoCarro);
}

// Remove carros acima de uma determinada kilometragem
void removerCarrosPorKilometragem(No **cabeca, int kilometragemMaxima)
{
    No *atual = *cabeca;
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->carro.kilometragem > kilometragemMaxima)
        {
            No *temp = atual;
            if (anterior == NULL)
            {
                *cabeca = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            atual = atual->proximo;
            free(temp);
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

// Printa todos os registros da Lista Encadeada
void imprimirLista(No *no)
{
    printf("\n");
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

// Printa todos os registros da Lista Encadeada filtrada por marca
void imprimirListaPorMarca(No *no, char marca[LIMITE])
{
    printf("\nCarros da marca %s:\n", marca);
    int carrosEncontrados = 0;

    printf("\n");
    while (no != NULL)
    {
        if (strcmp(no->carro.marca, marca) == 0)
        {
            printf("Marca: %s\n", no->carro.marca);
            printf("Modelo: %s\n", no->carro.modelo);
            printf("Ano de Fabricação: %d\n", no->carro.anoFabricacao);
            printf("Kilometragem: %d\n", no->carro.kilometragem);
            printf("Preço: %.2f\n\n", no->carro.preco);
            carrosEncontrados += 1;
        }
        no = no->proximo;
    }

    if (carrosEncontrados == 0)
    {
        printf("Nenhum carro da marca %s registrado.\n\n", marca);
    }
}

// Printa todos os registros da Lista Encadeada filtrado por preço mínimo e máximo
void imprimirListaPorPreco(No *no, float precoMin, float precoMax)
{
    printf("\nCarros na faixa de preço de [%.2f - %.2f]:\n", precoMin, precoMax);
    int carrosEncontrados = 0;

    printf("\n");
    while (no != NULL)
    {
        if (no->carro.preco >= precoMin && no->carro.preco <= precoMax)
        {
            printf("Marca: %s\n", no->carro.marca);
            printf("Modelo: %s\n", no->carro.modelo);
            printf("Ano de Fabricação: %d\n", no->carro.anoFabricacao);
            printf("Kilometragem: %d\n", no->carro.kilometragem);
            printf("Preço: %.2f\n\n", no->carro.preco);
            carrosEncontrados += 1;
        }
        no = no->proximo;
    }

    if (carrosEncontrados == 0)
    {
        printf("Nenhum carro na faixa de preço [%.2f - %.2f] registrado.\n", precoMin, precoMax);
    }
}

// Menu da aplicação
void menu(No **cabeca)
{
    printf("\n- Consultor | Carros -\n");

    int loop = 1;
    do
    {
        int selecao;
        printf("[1] - Exibir lista completa de registros");
        printf("\n[2] - Exibir lista de registros por marca");
        printf("\n[3] - Exibir lista de registros por preço");
        printf("\n[4] - Inserir novo registro de carro");
        printf("\n[5] - Remover registros por kilometragem");
        printf("\n[0] - Encerrar programa");
        printf("\n\nEscolha a sua opção: ");
        scanf("%d", &selecao);

        switch (selecao)
        {
        case 1:
            imprimirLista(*cabeca);
            break;

        case 2:
        {
            char marca[LIMITE];
            printf("\nDigite a marca desejada: ");
            getchar();
            fgets(marca, sizeof(marca), stdin);
            marca[strcspn(marca, "\n")] = '\0';
            imprimirListaPorMarca(*cabeca, marca);
            break;
        }

        case 3:
        {
            float precoMin, precoMax;
            printf("\nDigite o preço mínimo: ");
            scanf("%f", &precoMin);
            printf("Digite o preço máximo: ");
            scanf("%f", &precoMax);
            imprimirListaPorPreco(*cabeca, precoMin, precoMax);
            break;
        }

        case 4:
            criarNovoCarro(cabeca);
            printf("\nCarro inserido com sucesso.\n");
            break;

        case 5:
        {
            int kilometragemMaxima;
            printf("\nDigite a kilometragem máxima: ");
            scanf("%d", &kilometragemMaxima);
            removerCarrosPorKilometragem(cabeca, kilometragemMaxima);
            printf("\nCarros com kilometragem superior a %d removidos com sucesso.\n\n", kilometragemMaxima);
            break;
        }

        case 0:
            loop = 0;
            printf("\nPrograma encerrado com sucesso.");
            break;

        default:
            printf("\nEscolha invalida.\n");
            break;
        }
    } while (loop != 0);
}

// - Programa Principal -

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
        // Cria lista encadeada e atribui valores do arquivo dados.txt
        No *cabeca = NULL;
        char linha[256];

        while (fgets(linha, sizeof(linha), dadosArquivo))
        {
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

        // Chama função do menu para interagir com a lista encadeada criada
        menu(&cabeca);

        // Libera memória alocada 
        while(cabeca != NULL){
            Carro *temp = cabeca;
            cabeca = cabeca->proximo;
            free(temp);
        }

        return 0;
    }
}
