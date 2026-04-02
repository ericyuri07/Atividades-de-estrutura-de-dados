#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define max 20
#define inv -1

typedef int Matricula;

typedef struct
{
    Matricula matricula_aluno;
    char nome[50];
    char disciplinas[5][50];
    int qtdDisciplinas;
} Registro;

typedef struct
{
    Registro r;
    int proximo;
} Elemento;

typedef struct
{
    Elemento V[max];
    int inicio;
    int disponivel;
} Lista;

void Inicializar_Lista(Lista *L)
{
    for (int i = 0; i < max - 1; i++)
    {
        L->V[i].proximo = i + 1;
    }

    L->V[max - 1].proximo = inv;
    L->inicio = inv;
    L->disponivel = 0;
}

void Numeros_Elementos(Lista *L)
{
    int i = L->inicio;
    int tamanho = 0;
    while (i != inv)
    {
        tamanho++;
        i = L->V[i].proximo;
    }
}

void Imprimir_lista(Lista *L)
{
    int AlunosNaTurma;
    int i = L->inicio;
    printf("\nLista de alunos:\n");

    while (i != inv)
    {
        printf("\nMatricula: %d", L->V[i].r.matricula_aluno);
        printf("\nNome: %s", L->V[i].r.nome);

        for (int cont = 0; cont < L->V[i].r.qtdDisciplinas; cont++)
        {
            printf("\nDisciplina: %s", L->V[i].r.disciplinas[cont]);
        }

        printf("\n----------------------");

        i = L->V[i].proximo;
    }
}

int Busca_Sequencial_Ordenanda(Lista *L, Matricula ch)
{
    int i = L->inicio;
    while (i != inv && L->V[i].r.matricula_aluno < ch)
    {
        i = L->V[i].proximo;
    }
    if (i != inv && L->V[i].r.matricula_aluno == ch)
        return i;
    else
        return inv;
}

void buscaPorDiciplina(Lista *L, char *nomePorDiciplina)
{

    int i = L->inicio;
    while (i != inv)
    {
        for (int j = 0; j < L->V[i].r.qtdDisciplinas; j++)
        {
            if (strcmp(L->V[i].r.disciplinas[j], nomePorDiciplina) == 0)
            {
                printf("%s\n", L->V[i].r.nome);
            }
        }
        i = L->V[i].proximo;
    }
}

int Obtencao_do_NO(Lista *L)
{
    int resultado = L->disponivel;
    if (L->disponivel != inv)
        L->disponivel = L->V[L->disponivel].proximo;
    return resultado;
}

bool Inserir_Elemento_Ordenado(Lista *L, Registro r)
{
    if (L->disponivel == inv)
        return false;
    int anterior = inv;
    int i = L->inicio;
    Matricula ch = r.matricula_aluno;
    while (i != inv && L->V[i].r.matricula_aluno < ch)
    {
        anterior = i;
        i = L->V[i].proximo;
    }

    if (i != inv && L->V[i].r.matricula_aluno == ch)
        return false;
    i = Obtencao_do_NO(L);
    L->V[i].r = r;
    if (anterior == inv)
    {
        L->V[i].proximo = L->inicio;
        L->inicio = i;
    }
    else
    {
        L->V[i].proximo = L->V[anterior].proximo;
        L->V[anterior].proximo = i;
    }
    return true;
}

void Devolver_No_para_Lista(Lista *L, int i)
{
    L->V[i].proximo = L->disponivel;
    L->disponivel = i;
}

bool Excluir_Elemento_Lista(Lista *L, Matricula ch)
{
    int anterior = inv;
    int i = L->inicio;
    while (i != inv && L->V[i].r.matricula_aluno < ch)
    {
        anterior = i;
        i = L->V[i].proximo;
    }

    if (i == inv || L->V[i].r.matricula_aluno != ch)
        return false;
    if (anterior == inv)
        L->inicio = L->V[i].proximo;
    else
        L->V[anterior].proximo = L->V[i].proximo;
    Devolver_No_para_Lista(L, i);
    return false;
}

void Reinicializar_Lista(Lista *L)
{
    Inicializar_Lista(L);
}

void Imprimir_Por_Turma(Lista *L)
{
    char filtro[50];
    int encontrou = 0;
    int i = L->inicio;
    printf("Digite a diciplina que deseja verificar: ");
    scanf(" %[^\n]", &filtro);

    while (i != inv)
    {
        for (int b = 0; b < L->V[i].r.qtdDisciplinas; b++)
        {
            if (strcmp(L->V[i].r.disciplinas[b], filtro) == 0)
            {
                printf("Matricula: %d | Nome: %s\n",
                       L->V[i].r.matricula_aluno,
                       L->V[i].r.nome);
                encontrou = 1;
                break;
            };
        }
        i = L->V[i].proximo;
    }
    if (encontrou == 0)
        printf("Nenhum aluno matriculado nesta disciplina.\n");
}

void Imprimir_Alunos(Lista *L)
{
    int i = L->inicio;
    while (i != inv)
    {
        printf("Matricula: %d | Nome: %s\n", L->V[i].r.matricula_aluno, L->V[i].r.nome);

        for (int cont = 0; cont < L->V[i].r.qtdDisciplinas; cont++)
        {
            printf("  -> Disciplina: %s\n", L->V[i].r.disciplinas[cont]);
        }

        i = L->V[i].proximo;
    }
}

void Iprimir_informacoes_aluno(Lista *L)
{

    char buscaNome[50];
    int buscaMatricula, opcao, encontrou;
    int i = L->inicio;

    printf("1- Para buscar pelo nome: \n");
    printf("2- Buscar pela matricula: \n");
    scanf(" %d", &opcao);

    if (opcao == 1)
    {
        printf("Digite o nome do aluno que deseja buscar: ");
        scanf(" %[^\n]", buscaNome);

        while (i != inv)
        {
            if (strcmp(L->V[i].r.nome, buscaNome) == 0)
            {
                printf("Matricula: %d\n", L->V[i].r.matricula_aluno);
                printf("Nome:  %s\n", L->V[i].r.nome);
                for (int cont = 0; cont < L->V[i].r.qtdDisciplinas; cont++)
                {
                    printf(" --> Disciplinas: %s\n", L->V[i].r.disciplinas[cont]);
                }
                encontrou = 1;
            }
            i = L->V[i].proximo;
        }
        if (!encontrou)
            printf("Aluno nao encontrado.\n");
    }

    else if (opcao == 2)
    {
        printf("Digite a matricula do aluno que deseja buscar: ");
        scanf(" %d", &buscaMatricula);

        while (i != inv)
        {
            if (L->V[i].r.matricula_aluno == buscaMatricula)
            {
                printf("Matricula: %d\n", L->V[i].r.matricula_aluno);
                printf("Nome:  %s\n", L->V[i].r.nome);
                for (int cont = 0; cont < L->V[i].r.qtdDisciplinas; cont++)
                {
                    printf(" --> Disciplinas: %s\n", L->V[i].r.disciplinas[cont]);
                }
                encontrou = 1;
                break;
            }
            i = L->V[i].proximo;
        }
        if (!encontrou)
            printf("Aluno nao encontrado.\n");
    }
}

int main()
{

    Lista t;
    Inicializar_Lista(&t);
    int opcao = 0;
    Registro r;
    Matricula ch;
    int cont = 0;
    char busca[50];
    int contMateria;
    int p = t.inicio;

    do
    {
        printf("\n1- Insira um elemento a sua lista: \n");
        printf("2- Imprimir lista: \n");
        printf("3- excluir elemento da lista: \n");
        printf("4- Reinicializar sua lista: \n");
        printf("5- Quantidade de elementos: \n");
        printf("6- Buscar elemento: \n");
        printf("7- Ver os alunos da diciplina: \n");
        printf("8- imprimir os aluno por turma: \n");
        printf("9- imprimir todos os alunos: \n");
        printf("10- Buscar Informacoes de um aluno: \n");
        printf("-1- Sair: \n");
        printf("Dgite a opcao que deseja: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Insira a matricula: ");
            scanf(" %d", &r.matricula_aluno);
            printf("Insira o nome: ");
            scanf(" %[^\n]", r.nome);
            printf("Digite a quantidade de disciplinas (max 5): ");
            scanf("%d", &r.qtdDisciplinas);

            cont = 0;
            while (cont < r.qtdDisciplinas)
            {
                char auxDisc[50];
                printf("Digite a disciplina %d: ", cont + 1);
                scanf(" %[^\n]", auxDisc);

                contMateria = 0;
                p = t.inicio;

                while (p != inv)
                {
                    for (int i = 0; i < t.V[p].r.qtdDisciplinas; i++)
                    {
                        if (strcmp(t.V[p].r.disciplinas[i], auxDisc) == 0)
                        {
                            contMateria++;
                        }
                    }
                    p = t.V[p].proximo;
                }

                if (contMateria >= max)
                {
                    printf("Turma lotada! (%d alunos). Escolha outra disciplina.\n", contMateria);
                }
                else
                {
                    strcpy(r.disciplinas[cont], auxDisc);
                    cont++;
                }
            }
            cont = 0;

            if (Inserir_Elemento_Ordenado(&t, r))
            {
                printf("Aluno inserido com sucesso!\n");
            }
            else
            {
                printf("Erro ao inserir: Lista cheia ou matricula duplicada.\n");
            }
            break;

        case 2:
            Imprimir_lista(&t);
            break;

        case 3:
            printf("Digite o numero que deseja excluir: ");
            scanf("%d", &ch);
            Excluir_Elemento_Lista(&t, ch);
            break;

        case 4:
            printf("Reinicializando...");
            Reinicializar_Lista(&t);
            break;

        case 5:
            Numeros_Elementos(&t);
            break;

        case 6:
            printf("Digite o elemento que deseja buscar: ");
            scanf(" %d", &ch);
            Busca_Sequencial_Ordenanda(&t, ch);
            break;
        case 7:
            printf("Digite a diciplina que deseja buscar: ");
            scanf(" %[^\n]", busca);

            buscaPorDiciplina(&t, busca);
            break;
        case 8:
            Imprimir_Por_Turma(&t);
            break;
        case 9:
            Imprimir_Alunos(&t);
            break;
        case 10:
            Iprimir_informacoes_aluno(&t);
            break;
        case -1:
            printf("Saindo...");
            break;

        default:
            printf("numero inválido!!");
            break;
        }

    } while (opcao != -1);
}