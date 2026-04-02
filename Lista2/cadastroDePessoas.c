#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    char endereco[50];
} Pessoa;

void recebePessoa(Pessoa *p)
{
    printf("Digite seu nome: ");
    scanf(" %[^\n]", &p->nome);

    printf("Digite sua idade: ");
    scanf("%d\n", &p->idade);

    printf("Digite seu endereco: ");
    scanf(" %[^\n]", &p->endereco);
};

void mostrarPessoa(Pessoa p)
{
    printf("Nome: %s\n", p.nome);

    printf("Idade: %d", p.idade);

    printf("endereco: %s\n", p.endereco);
}

int main () {
    Pessoa teste;

    recebePessoa(&teste);
    mostrarPessoa(teste);
}
