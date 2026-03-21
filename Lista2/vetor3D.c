#include <stdio.h>
#include <string.h>

typedef struct 
{
    int x, y, z;
} vetor3D;


void somaVetores(vetor3D a, vetor3D b)
{
    vetor3D resultado;
    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;
    resultado.z = a.z + b.z;

    printf("\n%d", resultado.x);
    printf("\n%d", resultado.y);
    printf("\n%d", resultado.z);
}

void acumulaNoPrimeiro(vetor3D *a, vetor3D b)
{
    printf("Antes de acumular");
    printf("\n%d", a->x);
    printf("\n%d", a->y);
    printf("\n%d", a->z);

    a->x += b.x;
    a->y += b.y;
    a->z += b.z;

    printf("\nApos de acumular");
    printf("\n%d", a->x);
    printf("\n%d", a->y);
    printf("\n%d", a->z);
}

int main(){
    vetor3D teste_a;
    vetor3D teste_b;

    //vetor a
    printf("Digite seu primeiro do vetor a: " );
    scanf("%d", &teste_a.x);

    printf("Digite seu segundo do vetor a: ");
    scanf("%d", &teste_a.y);

    printf("Digite seu terciro do vetor a: ");
    scanf("%d", &teste_a.z);

    //vetor b
    printf("Digite seu primeiro do vetor b: ");
    scanf("%d", &teste_b.x);

    printf("Digite seu segundo do vetor b: ");
    scanf("%d", &teste_b.y);
    
    printf("Digite seu terceiro do vetor a: ");
    scanf("%d", &teste_b.z);

    //somaVetores(teste_a, teste_b);
    acumulaNoPrimeiro(&teste_a, teste_b);
}
