#include <stdio.h>
#include <stdlib.h>

    //Struct Carta 
    typedef struct Carta {
        char estado[3];
        char codigo[50];
        char cidade[50];
        int populacao;
        double area;
        double pib;
        int turist;
        double densi;
        double capita;
        double poder;
    } Carta;

    //Alvo de comparacao
    int alvo1, alvo2;

    //Funcao para comparara as structs
    void comparar(Carta c1, Carta c2, int alvo1, int alvo2) {
        if (c1.populacao > c2.populacao) {
            printf("Populacao: Carta %d venceu\n", alvo1);
        } else if (c1.populacao < c2.populacao) {
            printf("Populacao: Carta %d venceu\n", alvo2);
        } else if (c1.populacao == c2.populacao) {
            printf("Populacao: Empate\n");
        }
        if (c1.populacao > c2.populacao) {
            printf("Area: Carta %d venceu\n", alvo1);
        } else if (c1.area < c2.area) {
            printf("Area: Carta %d venceu\n", alvo2);
        } else if (c1.area == c2.area) {
            printf("Area: Empate\n");
        }
                if (c1.densi > c2.densi) {
            printf("Densidade Populacional: Carta %d venceu\n", alvo1);
        } else if (c1.densi < c2.densi) {
            printf("Densidade Populacional: Carta %d venceu\n", alvo2);
        } else if (c1.densi == c2.densi) {
            printf("Densidade Populacional: Empate\n");
        }
        if (c1.pib > c2.pib) {
            printf("PIB: Carta %d venceu\n", alvo1);
        } else if (c1.pib < c2.pib) {
            printf("PIB: Carta %d venceu\n", alvo2);
        } else if (c1.pib == c2.pib) {
            printf("PIB: Empate\n");
        }
        if (c1.capita > c2.capita) {
            printf("PIB per capita: Carta %d venceu\n", alvo1);
        } else if (c1.capita < c2.capita) {
            printf("PIB per capita: Carta %d venceu\n", alvo2);
        } else if (c1.capita == c2.capita) {
            printf("PIB per capita: Empate\n");
        }
        if (c1.turist > c2.turist) {
            printf("Pontos turisticos: Carta %d venceu\n", alvo1);
        } else if (c1.turist < c2.turist) {
            printf("Pontos turisticos: Carta %d venceu\n", alvo2);
        } else if (c1.turist == c2.turist) {
            printf("Pontos turisticos: Empate\n");
        }
        if (c1.poder > c2.poder) {
            printf("Poder: Carta %d venceu\n", alvo1);
        } else if (c1.poder < c2.poder) {
            printf("Poder: Carta %d venceu\n", alvo2);
        } else if (c1.poder == c2.poder) {
            printf("Poder: Empate\n");
        }


    }

    //Função para limpeza de Buffer
void buf()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
//Codigo principal
int main()
{

    int quant;
    int carta1, carta2;

    //Repeticao para o numero de cartas desejadas
    printf("Quantas cartas? \n");
    scanf(" %d", &quant);
    buf();

        Carta c[quant];

    for(int i = 0; i < quant; i++) {

    //Definicao de cada carta
    printf("Carta %d: \n", i + 1);

    printf("Estado: ");
    scanf(" %c", &c[i].estado);
    buf();

    printf("Codigo: ");
    fgets(c[i].codigo, sizeof(c[i].codigo), stdin);
    printf("Cidade: ");

    fgets(c[i].cidade, sizeof(c[i].cidade), stdin);
    printf("Populacao: ");
    scanf(" %d", &c[i].populacao);
    buf();

    printf("Area: ");
    scanf(" %lf", &c[i].area);
    buf();

    //Obter densidade populacional
    c[i].densi = c[i].populacao / c[i].area;
    printf("Densidade Populacional: %.2f \n", c[i].densi);

    printf("PIB: ");
    scanf(" %lf", &c[i].pib);
    buf();

    //Obter PIB per capita
    c[i].capita = c[i].pib / c[i].populacao;
    printf("PIB per capita: %.2f \n", c[i].capita);

    printf("Pontos turisticos: ");
    scanf(" %d", &c[i].turist);
    buf();

    //Poder da carta
    c[i].poder = c[i].populacao + c[i].area + c[i].pib +

     c[i].turist + c[i].capita - c[i].densi;
    printf("Poder: %.2f", c[i].poder);
    printf("\n");

    }

    //Exibir nomes das cartas (Opcional)
    /*for (int i = 0; i < quant; i++) {
        printf("%s", c[i].cidade);
    }*/

    //Uma unica carta
    if (quant == 1) {
        printf("Estado: %s\n", c[0].estado);
        printf("Codigo: %s", c[0].codigo);
        printf("Cidade: %s", c[0].cidade);
        printf("Populacao: %d\n", c[0].populacao);
        printf("Area: %.2f\n", c[0].area);
        printf("Densidade Populacional: %.2f\n", c[0].densi);
        printf("PIB: %.2f\n", c[0].pib);
        printf("PIB per capita: %.2f\n", c[0].capita);
        printf("Pontos turisticos: %d\n", c[0].turist);
        printf("Poder: %.2f\n", c[0].poder);
        return 0;

    //Sem necessidade de escolha das cartas
    } else if (quant == 2) {

        comparar(c[0], c[1], 1, 2);
        return 0;

    //Escolha das cartas a serem comparadas
    } else if (quant > 2) {

        printf("Digite o numero da primeira carta ");
        scanf("%d", &carta1);
        buf();

        printf("Digite o numero da segunda carta ");
        scanf("%d", &carta2);
        buf();
        //Atribuicao para parametros da funcao (Escopo global)
        alvo1 = carta1;
        alvo2 = carta2;

        //Ajuste de valores para o indice do array
        carta1--;
        carta2--;

        //Validando a resposta
        if (carta1 >= 0 && carta1 < quant && carta1 != carta2 && carta2 >=0 && carta2 < quant) {
            printf("Comparando carta %d e carta %d\n", carta1 + 1, carta2 + 1);
            printf("\n");
            comparar(c[carta1], c[carta2], alvo1, alvo2);
            return 0;
        } else {
            printf("\n");
            printf("Resposta invalida");
            return 0;
        }
    }

    return 0;
}


