#include <stdio.h>
#include <string.h>

typedef struct Carta {
    char estado;
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float densidade_populacional;
    float area;
    float pib;
    float pib_per_capita;
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
    scanf("%ld", &c.populacao);

    printf("\n");
    printf("Insira a área: ");
    scanf("%f", &c.area);

    c.densidade_populacional = c.populacao / c.area;

    printf("\n");
    printf("Insira o PIB: ");
    scanf("%f", &c.pib);

    c.pib_per_capita = c.pib / c.populacao;

    printf("\n");
    printf("Insira os pontos turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    cartas[i] = c;
}

void exibir_carta(carta_t carta) {
    printf("Estado:                 %c\n", carta.estado);
    printf("Código:                 %s\n", carta.codigo);
    printf("Nome:                   %s\n", carta.nome);
    printf("População:              %ld\n", carta.populacao);
    printf("Área:                   %f km²\n", carta.area);
    printf("Densidade Populacional: %f hab/km²\n", carta.densidade_populacional);
    printf("PIB:                    %f\n", carta.pib);
    printf("PIB per capta:          %f reais\n", carta.pib_per_capita);
    printf("Pontos Turísticos:      %d\n", carta.pontos_turisticos);
}

int main() {
    carta_t cartas[2] = {0};
    
    printf("PRIMEIRA CARTA\n");
    cadastrar_carta(cartas, 0);

    printf("SEGUNDA CARTA\n");
    getchar(); // Remove \n do stdin
    cadastrar_carta(cartas, 1);

    printf("\nCOMPARAÇÃO DAS CARTAS (atributo PIB)\n");
    printf("Carta 1 - %s: %f\n", cartas[0].nome, cartas[0].pib);
    printf("Carta 2 - %s: %f\n", cartas[1].nome, cartas[1].pib);
    if (cartas[0].pib > cartas[1].pib) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cartas[0].nome);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", cartas[1].nome);
    }

    return 0;
}
