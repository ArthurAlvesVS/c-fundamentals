#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool only_digits(const char *s);
static int luhn_checksum(const char *number);
static void print_brand_if_valid(const char *number);

int main(void)
{
    char numero[128];

    do
    {
        printf("Number: ");
        if (!fgets(numero, sizeof(numero), stdin))
        {
            return 1;
        }
        numero[strcspn(numero, "\n")] = '\0';
    }
    while (!only_digits(numero));

    print_brand_if_valid(numero);
    return 0;
}

static bool only_digits(const char *s)
{
    if (s[0] == '\0')
    {
        return false;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)s[i]))
        {
            return false;
        }
    }
    return true;
}

static int luhn_checksum(const char *number)
{
    int sum = 0;
    int len = (int)strlen(number);

    // percorre da direita pra esquerda
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
    {
        int digit = number[i] - '0';

        if (j % 2 == 1) // dobra a cada segundo dígito (contando do final)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
    }

    return sum % 10;
}

static void print_brand_if_valid(const char *number)
{
    int len = (int)strlen(number);

    // Primeiro: valida Luhn
    if (luhn_checksum(number) != 0)
    {
        printf("INVALID\n");
        return;
    }

    // Depois: identifica bandeira
    if (len == 15 && number[0] == '3' && (number[1] == '4' || number[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && number[0] == '5' && (number[1] >= '1' && number[1] <= '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 || len == 16) && number[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}