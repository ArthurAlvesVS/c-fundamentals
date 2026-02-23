#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[1000];

    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin))
    {
        return 1;
    }

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = (int) strlen(text); i < n; i++)
    {
        if (isalpha((unsigned char) text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    int grade = (int) round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}