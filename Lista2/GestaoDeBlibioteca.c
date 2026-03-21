#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int exemplaresDisponiveis;
} Livro;

Livro CriarLivro()
{
    Livro l;

    printf("Digite o titulo do seu livro: ");
    scanf(" %[^\n]", l.titulo);

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", l.autor);

    printf("Digite o ano de publicacao do livro: ");
    scanf("%d", &l.anoPublicacao);

    printf("Digite os exemplares do livros: ");
    scanf("%d", &l.exemplaresDisponiveis);

    return l;
}

int emprestaLivro(Livro *livro)
{
    int quantidadeLivros = 0;
    printf("Digite quantos livros deseja emprestar: ");
    scanf("%d", &quantidadeLivros);

    bool emprestimo = false;
    if (livro->exemplaresDisponiveis >= 0 && livro->exemplaresDisponiveis > quantidadeLivros)
    {
        emprestimo = true;
        livro->exemplaresDisponiveis -= quantidadeLivros;
        printf("Livro Empretado!");
    }
    else
        printf("Não é possivel emprestar o livros");

    return quantidadeLivros;
}

void devolveLivro(Livro *livro, int quantidade)
{
    int quantidade_devolvida = 0;
    printf("Digite a quantidade de livros que está devolvendo: ");
    scanf("%d", &quantidade_devolvida);

    if (quantidade_devolvida != quantidade)
        printf("Devolva todos os livros!!");
    else
    {
        printf("Livros devolvidos!!");
        livro->exemplaresDisponiveis += quantidade;
    }
}

void exibeLivro(Livro livro)
{
    printf("\nTitulo: %s", livro.titulo);
    printf("\nAutor: %s", livro.autor);
    printf("\nAno de publicacao: %d", livro.anoPublicacao);
    printf("\nExemplares: %d", livro.exemplaresDisponiveis);
}

int main()
{
    Livro t;
    int opcao;
    int qtd;

    do
    {
        printf("\n================MENU===============");
        printf("\n1 - Cadastro de livros");
        printf("\n2 - Emprestrar livros");
        printf("\n3 - Devolver os livros");
        printf("\n4 - ver o livro");
        printf("\n5 - Sair");
        printf("\nDigite a opcao que deseja: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            t = CriarLivro();
            break;
        case 2:
            qtd = emprestaLivro(&t);
            break;
        case 3:
            devolveLivro(&t, qtd);
            break;
        case 4:
            exibeLivro(t);
            break;
        case 5:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida!!");
            break;
        }
    } while (opcao != 5);
}