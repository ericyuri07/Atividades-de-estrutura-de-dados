#include <stdio.h>
#include <math.h>

typedef struct
{
    float x, y;
} ponto2D;


ponto2D criaPonto(float x, float y)
{
    ponto2D p;
    p.x = x;
    p.y = y;
    return p;
}


void movePonto(ponto2D *p, float dx, float dy)
{
    p->x += dx;
    p->y += dy;
}


float distanciaEntrePontos(ponto2D p1, ponto2D p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    return sqrt(dx * dx + dy * dy);
}

int main()
{
    ponto2D p1, p2;

    p1 = criaPonto(2.0, 3.0);
    p2 = criaPonto(5.0, 7.0);

    printf("Ponto 1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("Ponto 2: (%.2f, %.2f)\n", p2.x, p2.y);

    
    movePonto(&p1, 1.0, -1.0);

    printf("Ponto 1 apos mover: (%.2f, %.2f)\n", p1.x, p1.y);

    float dist = distanciaEntrePontos(p1, p2);

    printf("Distancia entre os pontos: %.2f\n", dist);

    return 0;
}