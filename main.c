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

int main(void) {

    FILE *fileRead = fopen("../dados/dados.txt", "r");

    if (fileRead == NULL){
        printf("\nErro: não foi possível efetuar a leitura de dados.txt");
    }
    else{
        printf("Leuu");
        
        Carro carro;
        strcpy(carro.marca, "Honda");
        printf("\n\nMarca: %s", carro.marca);
    }

    return 0;
}

