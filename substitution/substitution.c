#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Verificar se o número de argumentos é igual a 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    // Verificar se a chave tem 26 caracteres
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Verificar se a chave contém apenas letras e não tem repetição
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower((unsigned char) key[i]) == tolower((unsigned char) key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Ler plaintext (linha inteira)
    char plaintext[1024];
    printf("plaintext: ");
    if (!fgets(plaintext, sizeof(plaintext), stdin))
    {
        return 1;
    }
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Cifrar e imprimir
    printf("ciphertext: ");
    for (int i = 0, n = (int) strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper((unsigned char) c))
        {
            putchar(toupper((unsigned char) key[c - 'A']));
        }
        else if (islower((unsigned char) c))
        {
            putchar(tolower((unsigned char) key[c - 'a']));
        }
        else
        {
            putchar(c);
        }
    }
    printf("\n");

    return 0;
}