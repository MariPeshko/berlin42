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

// recursively
void ft_put_uint(unsigned int n)
{
	if (n >= 10)
		ft_put_uint(n / 10);
	ft_putchar(n % 10 + '0');
}

// why printf after everything??? with /n is fine?
void u_integer(va_list va)
{
	unsigned int n;

	n = va_arg(va, unsigned int);
	/// what?
	//printf("%u", n);
	//printf("%u\n", n);
	ft_put_uint(n);
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

void pointer(va_list va)
{
	size_t	pointer;

	// size_t - 8 byte on 64-bit system.
	// why size_t is used for pointer?
	// can it be long unsigned int? 
	pointer = va_arg(va, size_t);
	fprintf(stderr, "%p\n", pointer);
	fprintf(stderr, "%ld\n", pointer);
	//deci_to_hexa(pointer);
	// тут ми створюємо стрінгу, в яку перетворимо наш size_t 
	// у аресу. запишемо з кінця на перед.
	// і put_char робимо декрементуючи стрінгу
	// перше число - останнє у стрінзі
}

int ft_specifier(char spec, va_list va)
{
	if (spec == 'i' || spec == 'd')
		integer(va);
	else if (spec == 'c')
		character(va);
	else if (spec == 's')
		string(va);
	else if (spec == 'u')
		u_integer(va);
	else if (spec == 'p')
		pointer(va);
	// (spec == 'u')
	// (spec == 'x')
	// (spec == 'X')
	else
		ft_putchar(spec);
	return (0);
}

int ft_printf(const char *format, ...)
{
	int count;
	int i;
	va_list va;

	i = 0;
	count = 0;
	if (!(*format) || !format)
		return (0);

	va_start(va, format);
	// to count a 'count'
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_specifier(format[i], va);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(va);
	return (count);
}

int main(void)
{
	// int nbr = -2147483648;
	// int nbr = -2147483647;
	int nbr = 2147483647;
	unsigned int ui = 4294967295;
	char c = 'A';
	char *string;
	int *p = &nbr;
	//int *p = NULL;

	string = "it is a string";
	// ft_printf("Type int %d - great job!\n", nbr);
	// ft_printf("Type int %c - great job!\n", c);
	//ft_printf("Type int %s - great %job!%\n", string);
	// printf("Type int %s - great %job!%\n", string);
	//ft_printf("Type int %u - great job!\n", ui);

	ft_printf("Type pointer %p - great job!\n", p);
	printf("pointer %p\n", p);

	return (0);
}
