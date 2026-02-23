#include <stdio.h>
#include <math.h>

// Protótipo
int calcular_moedas(float valor);

int main(void)
{
    float valor;

    do
    {
        printf("Valor: ");
        if (scanf("%f", &valor) != 1)
        {
            // limpa entrada inválida
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            valor = -1;
        }
    }
    while (valor < 0);

    int moedas = calcular_moedas(valor);
    printf("%i\n", moedas);

    return 0;
}

// Função para calcular o número mínimo de moedas
int calcular_moedas(float valor)
{
    int centavos = (int) round(valor * 100);
    int moedas = 0;

    moedas += centavos / 25; centavos %= 25;
    moedas += centavos / 10; centavos %= 10;
    moedas += centavos / 5;  centavos %= 5;
    moedas += centavos / 1;

    return moedas;
}