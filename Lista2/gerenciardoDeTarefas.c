#include <stdio.h>
#include <string.h>

typedef struct 
{
    int id;
    char nome[20];
    enum {TO_DO, IN_PROGRESS, DONE, BLOCKED} status;
    enum {BAIXA, MEDIA, ALTA} priodade;
} Task;

void criartarefa( Task t)
{
    printf("Digite o id da sua tafera: ");
    scanf("%d", t.id);

    printf("Digite o nome da sua tarefa: ");
    scanf("%c", t.nome);

    printf("Digite o status da sua tarefa: ");

    
}

int main()
{
    Tarefa testes;
    criartarefa(testes);
}
