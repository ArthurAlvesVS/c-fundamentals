#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Verificar se o número de argumentos é igual a 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifica se a chave é composta apenas por dígitos
    for (int i = 0, n = (int) strlen(argv[1]); i < n; i++)
    {
        if (!isdigit((unsigned char) argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;

    // Ler plaintext (linha inteira)
    char plaintext[1024];
    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin))
    {
        return 1;
    }

    // Remove o \n do final (se existir)
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("ciphertext: ");

    for (int i = 0, n = (int) strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper((unsigned char) c))
        {
            printf("%c", (char) ((c - 'A' + key) % 26 + 'A'));
        }
        else if (islower((unsigned char) c))
        {
            printf("%c", (char) ((c - 'a' + key) % 26 + 'a'));
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}