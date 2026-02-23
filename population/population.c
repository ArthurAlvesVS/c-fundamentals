#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

static int read_line(char *buffer, size_t size)
{
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0'; // remove o \n
    return 1;
}

static int read_int(const char *prompt, int *out)
{
    char buffer[100];

    while (1)
    {
        printf("%s", prompt);

        if (!read_line(buffer, sizeof(buffer)))
            return 0;

        errno = 0;
        char *endptr;
        long value = strtol(buffer, &endptr, 10);

        if (errno != 0 || endptr == buffer || *endptr != '\0')
            continue;

        if (value < INT_MIN || value > INT_MAX)
            continue;

        *out = (int)value;
        return 1;
    }
}

int main(void)
{
    int n; // população inicial
    int e; // população final

    // População inicial (mínimo 9)
    do
    {
        read_int("Start size: ", &n);
    }
    while (n < 9);

    // População final (maior que inicial)
    do
    {
        read_int("End size: ", &e);
    }
    while (e <= n);

    int t = 0;

    while (n < e)
    {
        n = n + (n / 3) - (n / 4);
        t++;
    }

    printf("Years: %i\n", t);

    return 0;
}