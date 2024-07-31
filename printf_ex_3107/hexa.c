#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void deci_to_hexa(size_t number)
{
    write(1, "0x", 2);

    char *hex = "0123456789abcdef";
    char result[25];
    int i = 0;
    int j = 0;

    while (number > 15)
    {
        j = number % 16;
        number = number / 16;
        result[i] = hex[j];
        i++;
    }
    if (number <= 15)
    {
        result[i] = hex[number];
        i++;
    }
    i--;
    while (i >= 0)
    {
        ft_putchar(result[i]);
        i--;
    }
    ft_putchar('\n');
}

int main(void)
{
    size_t test = 105406;
    deci_to_hexa(test);
    return (0);
}