#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

typedef struct Carta {
    char estado;
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} carta_t;

void cadastrar_carta(carta_t *cartas, int i) {
    carta_t c;
    
    printf("Insira o estado: ");
    scanf("%c", &c.estado);
    getchar(); // Remove \n do stdin

    printf("\n");
    printf("Insira o código: ");
    fgets(c.codigo, 10, stdin);
    c.codigo[strcspn(c.codigo, "\n")] = 0;

    printf("\n");
    printf("Insira o nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    printf("\n");
    printf("Insira a população: ");
    scanf("%d", &c.populacao);

    printf("\n");
    printf("Insira a área: ");
    scanf("%f", &c.area);

    printf("\n");
    printf("Insira o PIB: ");
    scanf("%f", &c.pib);

    printf("\n");
    printf("Insira os pontos turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    cartas[i] = c;
}

void exibir_carta(carta_t carta) {
    printf("Estado:            %c\n", carta.estado);
    printf("Código:            %s\n", carta.codigo);
    printf("Nome:              %s\n", carta.nome);
    printf("População:         %d\n", carta.populacao);
    printf("Área:              %f km²\n", carta.area);
    printf("PIB:               %f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    carta_t cartas[2] = {0};
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("PRIMEIRA CARTA\n");
    cadastrar_carta(cartas, 0);

    printf("SEGUNDA CARTA\n");
    getchar(); // Remove \n do stdin
    cadastrar_carta(cartas, 1);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    printf("\nCARTAS CADASTRADAS\n");
    exibir_carta(cartas[0]);
    printf("\n");
    exibir_carta(cartas[1]);

    return 0;
}
