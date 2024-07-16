#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_putnumber(int nbr)
{
	char *str_nbr;
	int rozriad;
	int tmp;
	int i;

	rozriad = 1;
	i = 0;
	tmp = nbr;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (NULL);
	}
	if (nbr < 0)
		rozriad++;
	while (tmp >= 10 || tmp <= -10)
	{
		rozriad++;
		tmp = tmp / 10;
	}
	str_nbr = malloc((sizeof(char) * rozriad) + 1);
	if (nbr < 0)
	{
		str_nbr[i] = '-';
		nbr = nbr * -1;
		i++;
	}
	if (nbr >= 10)
	{
		i = rozriad - 1;
		while (nbr >= 10)
		{
			str_nbr[i] = (nbr % 10) + 48;
			nbr = nbr / 10;
			i--;
		}
	}
	if (nbr <= 9)
	{
		str_nbr[i] = nbr + 48;
	}
	str_nbr[rozriad] = '\0';
	return (str_nbr);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void string(va_list va)
{
	char *string;

	string = va_arg(va, char *);
	while (*string != '\0')
		ft_putchar(*string++);
}

void character(va_list va)
{
	char c;

	c = va_arg(va, int);
	ft_putchar(c);
}

void integer(va_list va)
{
	int j = 0;
	char *str_nmb;
	int n;

	n = va_arg(va, int);
	str_nmb = ft_putnumber(n);
	j = 0;
	if (!str_nmb)
		return;
	while (str_nmb[j] != '\0')
		ft_putchar(str_nmb[j++]);
	free(str_nmb);
}

void ft_specifier(char spec, va_list va)
{
	if (spec == 'i' || spec == 'd')
		integer(va);
	else if (spec == 'c')
		character(va);
	else if (spec == 's')
		string(va);
	// (spec == 'u')
	// (spec == 'x')
	// (spec == 'X')
	// (spec == 'p')
	else
		ft_putchar(spec);
}

int ft_printf(const char *format, ...)
{
	int i;
	va_list va;

	i = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			i++;
			ft_specifier(format[i], va);
		}
		i++;
	}
	va_end(va);
	return (0);
}

int main(void)
{
	//int nbr = -2147483648;
	//int nbr = -2147483647;
	int nbr = 2147483647;
	char c = 'A';
	char *string;

	string = "it is a string";
	// ft_printf("Type int %d - great job!\n", nbr);
	// ft_printf("Type int %c - great job!\n", c);
	ft_printf("Type int %s - great job!\n", string);
	return (0);
}
