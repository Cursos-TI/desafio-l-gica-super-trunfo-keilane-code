#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade; // População / Área
} Carta;

// Função para calcular densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir atributos de uma carta
void exibirCarta(Carta carta) {
    printf("País: %s\n", carta.pais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade: %.2f\n\n", carta.densidade);
}

// Função para retornar o valor do atributo escolhido
float valorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
void nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
        default: printf("Atributo Desconhecido"); break;
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 212000000, 8515767.0, 2200000.0, 100, 0};
    Carta carta2 = {"Argentina", 45000000, 2780400.0, 500000.0, 50, 0};

    // Cálculo da densidade demográfica
    carta1.densidade = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidade = calcularDensidade(carta2.populacao, carta2.area);

    // Exibir cartas
    printf("Cartas disponíveis:\n\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    int atributo1, atributo2;

    // Menu para o primeiro atributo
    printf("Escolha o primeiro atributo para comparar (1-5):\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    scanf("%d", &atributo1);

    // Menu dinâmico para o segundo atributo (não pode ser igual ao primeiro)
    do {
        printf("Escolha o segundo atributo para comparar (diferente do primeiro):\n");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Você já escolheu este atributo. Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Obter valores dos atributos
    float val1A1 = valorAtributo(carta1, atributo1);
    float val2A1 = valorAtributo(carta2, atributo1);

    float val1A2 = valorAtributo(carta1, atributo2);
    float val2A2 = valorAtributo(carta2, atributo2);

    // Exibir comparação
    printf("\nComparação dos atributos:\n");

    printf("\nAtributo 1: ");
    nomeAtributo(atributo1);
    printf("\nCarta 1: %.2f\nCarta 2: %.2f\n", val1A1, val2A1);

    printf("\nAtributo 2: ");
    nomeAtributo(atributo2);
    printf("\nCarta 1: %.2f\nCarta 2: %.2f\n", val1A2, val2A2);

    // Determinar vencedor de cada atributo individualmente
    int vencedorA1, vencedorA2;
    if (atributo1 == 5) // Densidade Demográfica -> menor vence
        vencedorA1 = (val1A1 < val2A1) ? 1 : ((val2A1 < val1A1) ? 2 : 0);
    else
        vencedorA1 = (val1A1 > val2A1) ? 1 : ((val2A1 > val1A1) ? 2 : 0);

    if (atributo2 == 5) // Densidade Demográfica -> menor vence
        vencedorA2 = (val1A2 < val2A2) ? 1 : ((val2A2 < val1A2) ? 2 : 0);
    else
        vencedorA2 = (val1A2 > val2A2) ? 1 : ((val2A2 > val1A2) ? 2 : 0);

    // Soma dos valores dos atributos para cada carta
    float somaCarta1 = val1A1 + val1A2;
    float somaCarta2 = val2A1 + val2A2;

    printf("\nSoma dos atributos:\nCarta 1: %.2f\nCarta 2: %.2f\n", somaCarta1, somaCarta2);

    // Determinar vencedor final
    if (somaCarta1 > somaCarta2)
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.pais);
    else if (somaCarta2 > somaCarta1)
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.pais);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
