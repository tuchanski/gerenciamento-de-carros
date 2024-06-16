#include <stdio.h>
#include <string.h>

typedef struct
{
    char marca[20];
    char modelo[20];
    int anoFabricacao;
    int kilometragem;
    float preco;
} Carro;

int main(void) {

    Carro carro;
    strcpy(carro.marca, "Honda");

    printf("%s\n", carro.marca);

    return 0;
}
