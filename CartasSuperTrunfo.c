#include <stdio.h>
#include <stdlib.h>

typedef struct Carta
{
    char estado[3];
    char codigo[50];
    char cidade[50];
    unsigned long int populacao;
    double area;
    double pib;
    int turist;
    double densi;
    double capita;
    double poder;
} Carta;

/*void comparar(Carta a, Carta b) {
    if (a.populacao > b.populacao) {
    printf("Carta 1 venceu\n");

    } else if (a.populacao < b.populacao) {
    printf("Carta 2 venceu\n");

    } else if (a.populacao == b.populacao) {
    printf("Empate\n");

    }

}*/

void comparar(double a, double b) {

        if (a > b) {
        printf("Carta 1 venceu\n");

        } else if (a < b) {
        printf("Carta 2 venceu\n");

        } else if (a == b) {
        printf("Empate\n");

    }
}

//Função para limpeza de Buffer
void buf()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main()
{
    Carta c1;
    printf("Carta 1 \n");
    printf("Estado: ");
    scanf(" %2s", c1.estado);
    buf();
    printf("Codigo: ");
    fgets(c1.codigo, sizeof(c1.codigo), stdin);
    printf("Cidade: ");
    fgets(c1.cidade, sizeof(c1.cidade), stdin);
    printf("Populacao: ");
    scanf(" %d", &c1.populacao);
    buf();
    printf("Area: ");
    scanf(" %lf", &c1.area);
    buf();

    c1.densi = c1.populacao / c1.area;
    printf("Densidade Populacional: %.2f \n", c1.densi);

    printf("PIB: ");
    scanf(" %lf", &c1.pib);
    buf();

    c1.capita = c1.pib / c1.populacao;
    printf("PIB per capita: %.2f \n", c1.capita);

    printf("Pontos turisticos: ");
    scanf(" %d", &c1.turist);
    buf();
    printf("\n");

    c1.poder = c1.populacao + c1.area + c1.pib + c1.turist + c1.capita - c1.densi;

    Carta c2;
    printf("Carta 2 \n");
    printf("Estado: ");
    scanf(" %2s", c2.estado);
    buf();
    printf("Codigo: ");
    fgets(c2.codigo, sizeof(c2.codigo), stdin);
    printf("Cidade: ");
    fgets(c2.cidade, sizeof(c2.cidade), stdin);
    printf("Populacao: ");
    scanf(" %d", &c2.populacao);
    buf();
    printf("Area: ");
    scanf(" %lf", &c2.area);
    buf();

    c2.densi = c2.populacao / c2.area;
    printf("Densidade Populaciona: %.2f \n", c2.densi);

    printf("PIB: ");
    scanf(" %lf", &c2.pib);
    buf();

    c2.capita = c2.pib / c2.populacao;
    printf("PIB per capita: %.2f \n", c2.capita);

    printf("Pontos turisticos: ");
    scanf(" %d", &c2.turist);
    buf();

    c2.poder = c2.populacao + c2.area + c2.pib + c2.turist + c2.capita - c2.densi;

    printf("\n");

    //Comparação
    printf("                        Super Trunfo\n");
    printf("---------------------------------------------------------------------------------------");
    printf("\n");
    printf("Populacao: ");
    comparar(c1.populacao, c2.populacao);
    printf("Area: ");
    comparar(c1.area, c2.area);
    printf("PIB: ");
    comparar(c1.pib, c2.pib);
    printf("Pontos turisticos: ");
    comparar(c1.turist, c2.turist);
    printf("Densidade Populacional: ");
    comparar(c1.densi, c2.densi);
    printf("PIB per capita: ");
    comparar(c1.pib, c2.pib);
    printf("Poder: ");
    comparar(c1.poder, c2.poder);



    return 0;
}
