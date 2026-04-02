#include <string.h>
#include <stdio.h>

typedef struct 
{
    int matricula;
    char nome[50];
    float n1, n2, n3;
    float media;
} AlunoNota;

void maiorPrimeiraProva( AlunoNota a[])
{
    int i;
    int tam;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &tam);

    int pos = 0;

    for(i = 0; i < tam; i++){   
        printf("Digite sua: %d", i + 1);
        printf(" - nota");
        scanf("%f", &a[i].n1);

        if(a[i].n1 > a[pos].n1 ){
            pos = i;
        };
    };

    printf("A maior nota da primeira prova: %.0f\n", a[pos].n1);
}

void mediaGeral(AlunoNota *alunos)
{
    printf("Digite sua primeira nota: ");
    scanf("%f", &alunos->n1);

    printf("Digite sua segunda nota nota: ");
    scanf("%f", &alunos->n2);

    printf("Digite sua terceira nota: ");
    scanf("%f", &alunos->n3);

    alunos->media = (alunos->n1 + alunos->n2 + alunos->n3) / 3;
    printf("Media das notas: %.2f", alunos->media);
    
}

int main()
{
    AlunoNota alunos[10];
    maiorPrimeiraProva(alunos);
    mediaGeral(alunos);
}

