#include <stdio.h>
#include <stdlib.h>

typedef struct Carta {
    char estado[3];
    char codigo[50];
    char cidade[50];
    int populacao;
    int area;
    double pib;
    int turist;
    };

//Função para limpeza de Buffer
void buf() {
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    Carta c1;
    printf("Carta 1 \n");
    buf();
    printf("Estado: ");
    scanf(" %c", &c1.estado);
    buf();
    printf("Codigo: ");
    fgets(c1.codigo, sizeof(c1.codigo), stdin);
    printf("Cidade: ");
    fgets(c1.cidade, sizeof(c1.cidade), stdin);
    printf("Populacao: ");
    scanf(" %d", &c1.populacao);
    buf();
    printf("Area: ");
    scanf(" %.2f", &c1.area);
    buf();
    printf("PIB: ");
    scanf(" %.2f", &c1.pib);
    buf();
    printf("Pontos turisticos: ");
    scanf(" %d", &c1.turist);
    printf("\n");
    buf();

    Carta c2;
    printf("Carta 2 \n");
    buf();
    printf("Estado: ");
    scanf(" %c", &c2.estado);
    buf();
    printf("Codigo: ");
    fgets(c1.codigo, sizeof(c2.codigo), stdin);
    printf("Cidade: ");
    fgets(c1.cidade, sizeof(c2.cidade), stdin);
    printf("Populacao: ");
    scanf(" %d", &c2.populacao);
    buf();
    printf("Area: ");
    scanf(" %.2f", &c2.area);
    buf();
    printf("PIB: ");
    scanf(" %.2f", &c2.pib);
    buf();
    printf("Pontos turisticos: ");
    scanf(" %d", &c2.turist);
    printf("\n");
    buf();
    
    return 0;
}
