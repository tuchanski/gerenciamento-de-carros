## Projeto de Programação Imperativa - Gerenciamento de Carros

Este repositório contém um programa desenvolvido como projeto bônus da disciplina de Programação Imperativa da PUCPR. O objetivo do programa é gerenciar uma lista encadeada de registros de carros a partir de um arquivo de entrada e permitir ao usuário realizar diversas operações sobre essa lista.

## Funcionalidades do Programa

1. **Leitura e Organização dos Dados**

   - O programa lê os registros de carros a partir de um arquivo texto chamado `dados.txt`.
   - Cada registro de carro contém:
     - Marca
     - Modelo
     - Ano de fabricação
     - Kilometragem
     - Preço

2. **Estrutura de Dados**

   - Os registros de carros são armazenados em uma lista encadeada em ordem crescente com base no preço dos carros.

3. **Operações Disponíveis**

   - **Exibir a lista completa de registros:** Mostra todos os carros presentes na lista, ordenados por preço.
   - **Filtrar por marca:** Exibe todos os carros de uma marca específica fornecida pelo usuário.
   - **Filtrar por faixa de preço:** Mostra todos os carros cujo preço esteja dentro de uma faixa especificada pelo usuário.
   - **Inserir novo registro:** Permite ao usuário inserir um novo registro de carro na lista, garantindo que a ordem crescente por preço seja mantida.
   - **Remover carros por kilometragem:** Remove todos os carros da lista cuja kilometragem seja superior a um valor fornecido pelo usuário.
   - **Sair do programa:** Encerra a execução do programa.

4. **Requisitos Técnicos**
   - Utilização de memória dinamicamente alocada (heap) para a lista encadeada, com funções `malloc` e `free`.
   - O arquivo `dados.txt` contém pelo menos 10 registros de carros.

## Exemplo de Uso

Para executar o programa, compile o código-fonte em C e execute o arquivo compilado. Durante a execução, siga as instruções no terminal para interagir com as operações disponíveis.

## Estrutura do Repositório

- **`main.c`**: Implementação do programa principal em C.
- **`../dados/dados.txt`**: Arquivo de entrada com os registros de carros.

## Exemplo de Dados e Lista Encadeada Gerada

Considerando um exemplo simplificado do arquivo `dados.txt`:

Honda<br>
HRV EX<br>
2022<br>
15000<br>
95000.00<br>
Renault<br>
Sandero Stepway<br>
2023<br>
20000<br>
60000.00<br>
Toyota<br>
Yaris XLS<br>
2020<br>
60000<br>
80000.00<br>
Ford<br>
Focus SE<br>
1.6<br>
2024<br>
0<br>
100000.00<br>

A lista encadeada correspondente, mantida em ordem crescente pelo preço, seria visualizada no programa da seguinte forma:

Renault<br>
Sandero Stepway<br>
2023<br>
20000<br>
60000.00<br>
Toyota<br>
Yaris XLS<br>
2020<br>
60000<br>
80000.00<br>
Honda<br>
HRV EX<br>
2022<br>
15000<br>
95000.00<br>
Ford<br>
Focus SE<br>
1.6<br>
2024<br>
0<br>
100000.00<br>

## Instruções de Compilação e Execução

Para compilar o programa em C (supondo que o arquivo principal se chame `main.c` e o compilador seja `gcc`):

```bash
gcc main.c -o programa
```

Para executar o programa compilado:

```bash
./programa
```

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para enviar sugestões e melhorias através de pull requests.

## Autor

- [Guilherme Tuchanski Rocha | GitHub](https://github.com/tuchanski)

