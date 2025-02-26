#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

typedef struct Carta {
    char codigo_cidade[4];
    char nome[100];
    int populacao;
    int area;
    int pib;
    int pontos_turisticos;
} carta_t;

/**
 * @param {cartas} Lista de cartas
 * @param {quant} Quantidade de cartas cadastradas
 */
void exibir_cartas(carta_t *cartas, int quant) {
    printf("CARTAS CADASTRADAS\n");
    for (int i = 0; i < quant; i++) {
        carta_t carta = cartas[i];

        printf("Código da Cidade: %s\n", carta.codigo_cidade);
        printf("Nome da Cidade: %s\n", carta.nome);
        printf("População da Cidade: %d\n", carta.populacao);
        printf("Área da Cidade: %d\n", carta.area);
        printf("PIB da Cidade: %d\n", carta.pib);
        printf("Pontos Turísticos da Cidade: %d\n\n", carta.pontos_turisticos);
    }
}

/**
 * @param {cartas} Lista de cartas
 * @param {quant} Quantidade de cartas cadastradas
 * @returns 0 em caso de sucesso.
 */
int op_cadastro(carta_t *cartas, int quant) {
    carta_t carta = {0};

    printf("Informe o código da cidade: ");
    if (scanf("%s", carta.codigo_cidade) < 1) {
        printf("Código inválido.\n");
        return -1;
    }
    
    printf("Informe o nome da cidade: ");
    if (scanf("%s", carta.nome) < 1) {
        printf("Nome inválido.\n");
        return -1;
    }

    printf("Informe a população da cidade: ");
    if (scanf("%d", &carta.populacao) < 1) {
        printf("Inteiro inválido.\n");
        return -1;
    }

    printf("Informe a área da cidade: ");
    if (scanf("%d", &(carta.area)) < 1) {
        printf("Inteiro inválido.\n");
        return -1;
    }

    printf("Informe o PIB da cidade: ");
    if (scanf("%d", &carta.pib) < 1) {
        printf("Inteiro inválido.\n");
        return -1;
    }

    printf("Informe o número de pontos turísticos da cidade: ");
    if (scanf("%d", &carta.pontos_turisticos) < 1) {
        printf("Inteiro inválido.\n");
        return -1;
    }

    cartas[quant] = carta;

    return 0;
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int quant_cartas = 0;
    carta_t cartas[20] = {0};
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    int operacao;
    printf("Digite o número da operação a ser efetuada:\n");
    printf("1. Exibir cartas\n");
    printf("2. Cadastrar carta\n\n");

    // Escaneia a entrada do usuário e valida seu formato.
    if (scanf("%d", &operacao) < 1) {
        printf("Operação inválida.\n");
        return 1;
    }

    // Aqui é feito uma checagem da operação requerida pelo usuário.
    // Caso inválida, é retornado um erro.
    switch (operacao) {
        case 1:
            if (quant_cartas < 1) {
                printf("Não há cartas cadastradas.\n");
                return 1;
            }

            exibir_cartas(cartas, quant_cartas);

            // Encerrar programa para que não seja exibido pela segunda vez abaixo.
            return 0;

        
        case 2:
            if (op_cadastro(cartas, quant_cartas) != 0) {
                return 1;
            }

            quant_cartas++;

            break;

        default:
            printf("Operação inválida.\n");
    }
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    printf("\n");
    exibir_cartas(cartas, quant_cartas);

    return 0;
}
