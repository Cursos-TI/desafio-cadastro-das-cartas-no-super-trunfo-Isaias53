#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struct Carta
typedef struct Carta
{
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

//Funcao para comparar as structs
void comparar(double a, double b)
{
    printf("\n");
    if (a > b)
    {
        printf("CARTA 1 VENCEU\n");

    }
    else if (a < b)
    {
        printf("CARTA 2 VENCEU\n");

    }
    else if (a == b)
    {
        printf("EMPATE\n");

    }
}
void compararD(double a, double b)
{
    printf("\n");
    if (a > b)
    {
        printf("CARTA 2 VENCEU\n");
    }
    else if (a < b)
    {
        printf("CARTA 1 VENCEU\n");
    }
    else if (a == b)
    {
        printf("EMPATE\n");
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

    for(int i = 0; i < quant; i++)
    {

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
    int atributo;
    char entrada[10];

    //Exibir nomes das cartas (Opcional)
    /*for (int i = 0; i < quant; i++) {
        printf("%s", c[i].cidade);
    }*/

    //Uma unica carta
    if (quant == 1)
    {
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
    }
    else if (quant == 2)
    {

        //Opcoes para o usuario
        do
        {
            printf("                        Super Trunfo\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("Escolha um atributo: \n");
            printf("\n");
            printf("1. Populacao\n");
            printf("2. Area\n");
            printf("3. Densidade Populacional\n");
            printf("4. PIB\n");
            printf("5. PIB per capita\n");
            printf("6. Pontos Turisticos\n");
            printf("7. Poder da carta\n");
            printf("\n");
            printf("Selecione a opcao: ");
            fgets(entrada, sizeof(entrada), stdin);

            //Forca o usuario a digitar algo valido (int) para continuar
            if (sscanf(entrada, "%d", &atributo) == 1)
            {

                //Escolha do atributo (numero)
                switch(atributo)
                {
                case 1:
                    printf("Populacao: \n");
                    printf("O MAIOR vence!\n");
                    comparar(c[0].populacao, c[1].populacao);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 2:
                    printf("Area: \n");
                    printf("O MAIOAR vence!\n");
                    comparar(c[0].area, c[1].area);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 3:
                    printf("Densidade Populacional: \n");
                    printf("O MENOR vence!\n");
                    compararD(c[0].densi, c[1].densi);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 4:
                    printf("PIB: \n");
                    printf("O MAIOR vence!\n");
                    comparar(c[0].pib, c[1].pib);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 5:
                    printf("PIB per capita: \n");
                    printf("O MAIOR vence!\n");
                    comparar(c[0].pib, c[1].pib);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 6:
                    printf("Pontos turisticos: \n");
                    printf("O MAIOR vence!\n");
                    comparar(c[0].turist, c[1].turist);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                case 7:
                    printf("Poder: \n");
                    printf("O MAIOR vence!\n");
                    comparar(c[0].poder, c[1].poder);
                    printf("---------------------------------------------------------------------------------------\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    printf("\n");
                    printf("---------------------------------------------------------------------------------------\n");
                }
            }
        }
        while (atributo < 1 || atributo > 7);
        return 0;

        //Escolha das cartas a serem comparadas
    }
    else if (quant > 2)
    {

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
        if (carta1 >= 0 && carta1 < quant && carta1 != carta2 && carta2 >=0 && carta2 < quant)
        {
            printf("\n");
            printf("COMPARANDO CARTA %d E CARTA %d\n", carta1 + 1, carta2 + 1);
            printf("\n");

            //Opcoes para o usuario
            do
            {
                printf("                        Super Trunfo\n");
                printf("---------------------------------------------------------------------------------------\n");
                printf("Escolha um atributo: \n");
                printf("\n");
                printf("1. Populacao\n");
                printf("2. Area\n");
                printf("3. Densidade Populacional\n");
                printf("4. PIB\n");
                printf("5. PIB per capita\n");
                printf("6. Pontos Turisticos\n");
                printf("7. Poder da carta\n");
                printf("\n");
                printf("Selecione a opcao: ");
                fgets(entrada, sizeof(entrada), stdin);

                //Forca o usuario a digitar algo valido (int) para continuar
                if (sscanf(entrada, "%d", &atributo) == 1)
                {

                    //Escolha do atributo (numero)
                    switch(atributo)
                    {
                    case 1:
                        printf("Populacao: \n");
                        printf("O MAIOR vence!\n");
                        comparar(c[carta1].populacao, c[carta2].populacao);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 2:
                        printf("Area: \n");
                        printf("O MAIOAR vence!\n");
                        comparar(c[carta1].area, c[carta2].area);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 3:
                        printf("Densidade Populacional: \n");
                        printf("O MENOR vence!\n");
                        compararD(c[carta1].densi, c[carta2].densi);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 4:
                        printf("PIB: \n");
                        printf("O MAIOR vence!\n");
                        comparar(c[carta1].pib, c[carta2].pib);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 5:
                        printf("PIB per capita: \n");
                        printf("O MAIOR vence!\n");
                        comparar(c[carta1].pib, c[carta2].pib);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 6:
                        printf("Pontos turisticos: \n");
                        printf("O MAIOR vence!\n");
                        comparar(c[carta1].turist, c[carta2].turist);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    case 7:
                        printf("Poder: \n");
                        printf("O MAIOR vence!\n");
                        comparar(c[carta1].poder, c[carta2].poder);
                        printf("---------------------------------------------------------------------------------------\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                        printf("\n");
                        printf("---------------------------------------------------------------------------------------\n");
                    }
                }
            }
            while (atributo < 1 || atributo > 7);
            return 0;
        }
    }
    return 0;
}

