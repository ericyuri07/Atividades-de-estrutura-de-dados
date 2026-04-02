#include <stdio.h>
#include <string.h>

typedef struct
{
    char nomeDaCompania[30];
    char areaDeAtuacao[20];
    double valorAtualDaAcao;
    double valorAnteriorDaAcao;
    double variacaoDaAcao;

} acao;

void comparar_valores(acao *bolsaDeValores)
{
    if (bolsaDeValores->valorAtualDaAcao > bolsaDeValores->valorAnteriorDaAcao)
    {
        printf("O valor da acao subiu");
    }
    else if (bolsaDeValores->valorAtualDaAcao < bolsaDeValores->valorAnteriorDaAcao)
    {
        printf("O valor da acao caiu");
    }
    else
    {
        printf("Permaneceu igual");
    }
}

void calcular_variacao(acao *bolsaDeValores)
{
    bolsaDeValores->variacaoDaAcao = ((bolsaDeValores->valorAtualDaAcao - bolsaDeValores->valorAnteriorDaAcao) / bolsaDeValores->valorAnteriorDaAcao) * 100;
}

void mostrar_informacoes(acao *bolsaDeValores)
{
    printf("\nnome da compania: %s", bolsaDeValores->nomeDaCompania);

    printf("\nArea de atuacao da empresa: %s", bolsaDeValores->areaDeAtuacao);

    printf("\nValor anterior da acao: %.2lf", bolsaDeValores->valorAnteriorDaAcao);
    
    printf("\nValor atual da acao: %.2lf", bolsaDeValores->valorAtualDaAcao);

    printf("\nVariacao da acao: %.2lf%%", bolsaDeValores->variacaoDaAcao);
}

int main()
{
    acao bolsaDeValores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite o nome da companhia: ");
        scanf(" %[^\n]", bolsaDeValores[i].nomeDaCompania);

        printf("Digite a area de atuacao da empresa: ");
        scanf(" %[^\n]", bolsaDeValores[i].areaDeAtuacao);

        printf("Digite o valor anterior da acao: ");
        scanf("%lf", &bolsaDeValores[i].valorAnteriorDaAcao);

        printf("Digite o valor atual da acao: ");
        scanf("%lf", &bolsaDeValores[i].valorAtualDaAcao);

        comparar_valores(&bolsaDeValores[i]);
        calcular_variacao(&bolsaDeValores[i]);
        mostrar_informacoes(&bolsaDeValores[i]);

        printf("\n==================================================");
    }
};