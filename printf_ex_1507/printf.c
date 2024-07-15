#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ? itoa - for negative number
char	*ft_putnumber(int nbr)
{
	char	*str_nbr;
	int		rozriad;
	int		tmp;
	int		i;

	rozriad = 1;
	i = 0;
	tmp = nbr;
	if (nbr < 0)
		rozriad++;
	while (tmp >= 10 || tmp <= -10)
	{
		rozriad++;
		tmp = tmp / 10;
	}
	printf("rozriad is %i\n", rozriad);
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		amount;
	int		n;
	va_list	va;
	char	*str_nmb;

	// checking
	// va_list, va_start, va_arg, va_end
	// search and cound valid %
	// in *argv[], starting from " and finishing after "
	// (and avoiding /") counting all %c, %d, %i etc.
	// int amount = amount of formats.
	// compare amount  with the amount of va_args.
	// if the quantity is not equal then free, display error.
	i = 0;
	amount = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			amount++;
		i++;
	}
	va_start(va, format);
	// if %i or %d - it is integer
	n = va_arg(va, int); // n = va_arg(va, char)
	printf("Number is %i\n", n);
	va_end(va);
	str_nmb = ft_putnumber(n);
	// parsing: ft_split, (" char %c, %i, %s")
	// %d - int %f - float
	// writing: ft_putchar(), ft_putnumber, hexadecimal_to_string
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
	}
	i = 0;
	while (str_nmb[i] != '\0')
		ft_putchar(str_nmb[i++]);
	free(str_nmb);
	return (0);
}

int	main(void)
{
	ft_printf("Type %i\n", 10);
	// write(1, "\nc\n", 3);
	return (0);
}
