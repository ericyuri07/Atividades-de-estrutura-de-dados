#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>

typedef int Matricula;

typedef struct
{
    Matricula matricula_aluno;
    char nome[30];
    char diciplina[5][20];
    int qtdDiciplinas;
} Registro;

typedef struct Aux_Elemento
{
    Registro r;
    struct Aux_Elemento *proximo;
} Elemento;

typedef Elemento *PONT; // Ptr ponteiro
typedef struct
{
    PONT inicio;
} Lista;

void Iniciar_Lista(Lista *L)
{
    // iniciando lista
    L->inicio = NULL;
}

int Tamanho_Lista(Lista *L)
{
    int tam = 0; // variável para saber o tamanho da lista
    PONT aux = L->inicio;
    while (aux != NULL)
    {
        tam++;
        aux = L->inicio->proximo;
    }
    printf("\nAlunos na lista: %d", tam);
    return tam;
}

void Imprimir_Lista(Lista *L)
{
    PONT aux = L->inicio;
    printf("\nLista de aluno:\n");

    while (aux != NULL)
    {
        printf("\nMatricula: %d", aux->r.matricula_aluno);
        printf("\nNome:\n %s", aux->r.nome);

        //Percorre a lista e emprime as matérias
        for (int i = 0; i < aux->r.qtdDiciplinas; i++)
        {
            printf("\nMateria: %s", aux->r.diciplina[i]);
        }
        aux = aux->proximo;
    }
}

PONT Busca_Sequencial(Lista *L, Matricula ch)
{
    PONT posicao = L->inicio;
    while (posicao != NULL)
    {
        if (posicao->r.matricula_aluno == ch)
        {
            printf("\nNome: %s", L->inicio->r.nome);
            for (int i = 0; i < L->inicio->r.qtdDiciplinas; i++)
            {
                printf("\nMateria: %s", L->inicio->r.diciplina[i]);
            }
            return posicao;
            posicao = posicao->proximo;
        }
        return NULL;
    }
}

PONT Busca_Sequencial_Aux(Lista *L, Matricula ch, PONT *anterior)
{
    *anterior = NULL;
    PONT atual = L->inicio;
    while (atual != NULL && atual->r.matricula_aluno != ch)
    {
        *anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->r.matricula_aluno == ch)
    {
        return atual;
    }
    return false;
}

bool Inserir_Elemento_Lista(Lista *L, Registro r)
{
    Matricula ch = r.matricula_aluno;
    PONT anterior, i;
    i = Busca_Sequencial_Aux(L, ch, &anterior);

    if (i != NULL)
    {
        return false;
    }

    i = (PONT)malloc(sizeof(Elemento));
    i->r = r;
    if (anterior == NULL)
    {
        i->proximo = L->inicio;
        L->inicio = i;
    }
    else
    {
        i->proximo = anterior->proximo;
        anterior->proximo = i;
    }

    return true;
}

bool Excluir_Elemento_Lista(Lista *L, Matricula ch)
{
    PONT anterior, i;
    i = Busca_Sequencial_Aux(L, ch, &anterior);
    if (i == NULL)
        return false;
    if (anterior == NULL)
        L->inicio = i->proximo;
    else
        anterior->proximo = i->proximo;
    free(i);
    return true;
}

void Reinicializar_Lista(Lista *L)
{
    PONT aux = L->inicio;
    while (aux != NULL)
    {
        PONT limpar = aux;
        aux = aux->proximo;
        free(limpar);
    }
    L->inicio = NULL;
}

int main()
{
    setlocale(LC_ALL, "");
    Lista L;            // Struct Lista
    Matricula m;        // Struct da matricula
    int opcao = 0;      // Para oq o usuário decidir
    Registro a;         // Struct do registro
    int tentativas = 1; // tentativas do case 1

    Iniciar_Lista(&L);
    do
    {
        printf("\n1- Insira um elemento a sua lista: \n");
        printf("2- Imprimir lista: \n");
        printf("3- excluir elemento da lista: \n");
        printf("4- Reinicializar sua lista: \n");
        printf("5- Quantidade de elementos: \n");
        printf("6- Buscar elemento: \n");
        printf("-1- Sair: \n");
        printf("Dgite a opcao que deseja: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            a.qtdDiciplinas = 0;
            printf("Digite a matricula do aluno: ");
            scanf("%d", &a.matricula_aluno);

            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]", a.nome);

            while (a.qtdDiciplinas < 1 || a.qtdDiciplinas > 5)
            {

                printf("\nDigite a quantidade de diciplina do aluno [Max 5]: ");
                scanf("%d", &a.qtdDiciplinas);

                // Verifica se o usuário já teve 3 tentivas
                if (tentativas == 3)
                {
                    printf("\nVoce execeu o numero maximo de tentaivas!\n");
                    break;
                }

                // Serve mais para enviar uma mensagem a cada numero meior que 5
                if (a.qtdDiciplinas > 5)
                    printf("\nTente novamente, maximo de 5 diciplinas!");

                tentativas++;
            }

            int cont = 0; // percorre a lista e verifica a tamanho
            while (cont < a.qtdDiciplinas && a.qtdDiciplinas < 5)
            {
                printf("\nDigite a diciplina %d:", cont + 1);
                scanf(" %[^\n]", &a.diciplina[cont]);
                cont++;
            }

            tentativas = 0;
            Inserir_Elemento_Lista(&L, a);
            break;
        case 2:
            Imprimir_Lista(&L);
            break;
        case 3:
            printf("Digite o numero da matricula que deseja excluir: ");
            scanf("%d", &m);

            Excluir_Elemento_Lista(&L, m);
            break;
        case 4:
            Reinicializar_Lista(&L);
            break;
        case 5:
            Tamanho_Lista(&L);
            break;
        case 6:
            printf("Digite o numero da matricula que deseja buscar: ");
            scanf("%d", &m);
            Busca_Sequencial(&L, m);
            break;
        case -1:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida! Tente Novamente!");
            break;
        }
    } while (opcao != -1);
}
