#include <stdio.h>
#include <string.h>

typedef struct 
{
    int id;
    char nome[50];
    float preco;
    int quantidadeEstoque;
}Produto;

Produto criarProduto(int id, char *nome, float preco, int estoque)
{
        Produto p;

    p.id = id;
    strcpy(p.nome, nome);
    p.preco = preco;
    p. quantidadeEstoque = estoque;

    return p;
}

void atualizaEstoque(Produto *p, int delta)
{
    int opocao;

    
    printf("\n1 - Adicionar quantidade ao estoque");
    printf("\n2 - retirar quantidade do estoque");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opocao);

    if (opocao == 1)
        p->quantidadeEstoque += delta;
    else 
        p->quantidadeEstoque -= delta;
        
}

void exebiValor(Produto p)
{
    printf("\nId: %d", p.id);
    printf("\nNome: %s", p.nome);
    printf("\nPreco: %.2f", p.preco);
    printf("\nQuantidade em estoque: %d", p.quantidadeEstoque);
    
}

int main()
{
    Produto t;

    int id, estoque;
    char nome[50];
    float preco;
    int qntd;

    // Aqui sim você usa scanf
    printf("ID: ");
    scanf("%d", &id);

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("Preco: ");
    scanf("%f", &preco);

    printf("Estoque: ");
    scanf("%d", &estoque);

    // chama a função
    t = criarProduto(id, nome, preco, estoque);
    exebiValor(t);
    printf("\n================ESTOQUE===============");
    printf("\nDigite a quantidade desejada: ");
    scanf("%d", &qntd);

    atualizaEstoque(&t, qntd);
    printf("\n===============Valor atualizado===============");
    exebiValor(t);

}