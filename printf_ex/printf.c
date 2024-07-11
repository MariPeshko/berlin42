#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

// ? itoa - for negative number
char	*ft_putnumber(int nbr)
{
	char	*str_nbr;
	int	rozriad;
	int	tmp;
	int	i;

	rozriad = 0;
	if(nbr < 0)
		rozriad++;
	if(nbr < 10 && nbr > -10)
		rozriad++;
	else
		nbr = tmp;
	while (tmp > 10 && tmp < -10)
	{
		tmp / 10;
		rozriad++;
	}
	// + '\0'
	str_nbr = malloc((sizeof(char) * rozriad) + 1);
	if(nbr < 0)
	{
		str_nbr[i] = '-';
		nbr = nbr * -1;
	}
	i++;
	while(nbr >= 10)
	{
		str_nbr[i++] = (nbr % 10) + 48;
		nbr = nbr / 10;	
	}
	if(nbr <= 9)
		str_nbr[i++] = nbr + 48;
	str_nbr[i] = '\0';
	return (str_nbr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	//checking
	//va_list, va_start, va_arg, va_end
	// search and cound valid %
	// in *argv[], starting from " and finishing after "
	// (and avoiding /") counting all %c, %d, %i etc.
	// int amount = amount of formats.
	// compare amount  with the amount of va_args.
	// if the quantity is not equal then free, display error.
	int	i;
	int	amount;
	int	n;
	
	i = 0;
	amount = 0;
	n = 0;
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			if (format[i + 1] == i)
				amount++;
		}
		i++;
	}
	va_list	va;

	va_start(va, format);
	// if %i or %d - it is integer
	n = va_arg(va, int); // n = va_arg(va, char)
	
	va_end(va);

	char *str_nmb;
	str_nmb = ft_putnumber(n);

	//parsing: ft_split, (" char %c, %i, %s")
	// %d - int %f - float 
	//writing: ft_putchar(), ft_putnumber, hexadecimal_to_string
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
	}
	i = 0;
	while (str_nmb[i] != '\0')
	{
		ft_putchar(str_nmb[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("Type %i\n", 5);
	return (0);
}

