#include <stdio.h>
#include <string.h>

typedef struct
{
    char marca[20];
    char modelo[20];
    int ano;
    float preco;
} veiculo;

void preencheVeiculo(veiculo *v)
{
    printf("Digite a marca do modelo: ");
    scanf(" %[^\n]", v->marca);

    printf("Digite o modelo do seu veiculo: ");
    scanf(" %[^\n]", v->modelo);

    printf("Digite o ano do seu veiculo: ");
    scanf("%d", &v->ano);

    printf("Digite o preco do carro: ");
    scanf("%f", &v->preco);
}

void atualizaPreco(veiculo *v, float novoPreco)
{
    v->preco = novoPreco;
}

void mostrarInformacoes(veiculo teste)
{
    printf("Marca: %s\n", teste.marca);

    printf("Modelo: %s\n", teste.modelo);

    printf("Ano: %d\n", teste.ano);

    printf("Preco: %.2f\n", teste.preco);
}

int main()
{
    veiculo t;

    preencheVeiculo(&t);
    mostrarInformacoes(t);
    atualizaPreco(&t, 400000);

    printf(" O novo valor do veiculo e: %.2f", t.preco);

    return 0;
}
