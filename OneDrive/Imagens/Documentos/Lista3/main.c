#include <stdio.h>
#include <string.h>

#define max 50
#define inv -1

typedef int Tipo_chave;

typedef struct 
{
    Tipo_chave chave;
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

