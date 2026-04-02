#include <stdio.h>
#include <string.h>

typedef struct
{
    int hora;
    int minutos;
    int segudos;
} horario;

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    horario horarioCompromisso;
    data dataCompromisso;
    char descricao[100];

} compromisso;

void imprime_compromisso(compromisso *c)
{
    
    printf("Data: %04d/%02d/%d\n", c->dataCompromisso.ano, c->dataCompromisso.mes, c->dataCompromisso.dia);
    printf("Hora: %02d:%02d:%02d\n", c->horarioCompromisso.hora, c->horarioCompromisso.minutos, c->horarioCompromisso.segudos);
    printf("%s\n", c->descricao);
}

void informacoes_compromisso(compromisso *compromissoInformacoes)
{
    printf("Digite a hora do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->horarioCompromisso.hora);

    printf("Digite os minutos do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->horarioCompromisso.minutos);

    printf("Digite os segundos do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->horarioCompromisso.segudos);

    // recebendo informações da strtuct de data

    printf("Digite o ano do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->dataCompromisso.ano);

    printf("Digite o mes do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->dataCompromisso.mes);

    printf("Digite o dia do seu compromisso: ");
    scanf("%d", &compromissoInformacoes->dataCompromisso.dia);

    printf("Digite a descricao do seu compromisso: ");
    scanf(" %[^\n]", &compromissoInformacoes->descricao);

    if (compromissoInformacoes->horarioCompromisso.hora == 23 && compromissoInformacoes->horarioCompromisso.minutos == 59 && compromissoInformacoes->horarioCompromisso.segudos == 59)
    {
        compromissoInformacoes->dataCompromisso.dia += 1;
        compromissoInformacoes->horarioCompromisso.hora = 00;
        compromissoInformacoes->horarioCompromisso.minutos = 00;
        compromissoInformacoes->horarioCompromisso.segudos = 00;
    }

    

}


int main(){
    compromisso teste;
    

    informacoes_compromisso(&teste);
    imprime_compromisso(&teste);
    
}
    