#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main()
{
    int atributo;
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

    char entrada[10];
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
                comparar(c1.populacao, c2.populacao);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 2:
                printf("Area: \n");
                printf("O MAIOAR vence!\n");
                comparar(c1.area, c2.area);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 3:
                printf("Densidade Populacional: \n");
                printf("O MENOR vence!\n");
                compararD(c1.densi, c2.densi);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 4:
                printf("PIB: \n");
                printf("O MAIOR vence!\n");
                comparar(c1.pib, c2.pib);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 5:
                printf("PIB per capita: \n");
                printf("O MAIOR vence!\n");
                comparar(c1.pib, c2.pib);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 6:
                printf("Pontos turisticos: \n");
                printf("O MAIOR vence!\n");
                comparar(c1.turist, c2.turist);
                printf("---------------------------------------------------------------------------------------\n");
                break;
            case 7:
                printf("Poder: \n");
                printf("O MAIOR vence!\n");
                comparar(c1.poder, c2.poder);
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
