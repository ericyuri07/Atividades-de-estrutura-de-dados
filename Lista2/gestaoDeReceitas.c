#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int tempoPreparoMinutos;
    int porcoes;
}Receita;

void preencheReceita(Receita *r)
{
    printf("Digite o nome da sua receita: ");
    scanf(" %[^\n]", &r->nome);

    printf("Digite quantos minutos levam para sua receita ficar pronta: ");
    scanf("%d", &r->tempoPreparoMinutos);

    printf("Digite quantas porcoes seriam: ");
    scanf("%d", &r->porcoes);


} 

void imprimeRecita (Receita r)
{
    printf("Nome: %s\n", r.nome);

    printf("Tempo em Minutos: %d\n", r.tempoPreparoMinutos);

    printf("Porcoes: %d\n", r.porcoes);
}


void  ajustaPorcoes(Receita *r, int novoNumPorcoes)
{
        r->porcoes = novoNumPorcoes;
        printf("Nova quantidade de porcoes: %d\n", r->porcoes);
}

int main (){
    Receita t;

    preencheReceita(&t);
    imprimeRecita(t);

    ajustaPorcoes(&t, 20);

    printf("\nReceita atualizada:\n");
    imprimeRecita(t);
}