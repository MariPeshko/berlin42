/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:37:50 by mpeshko           #+#    #+#             */
/*   Updated: 2024/02/08 17:37:53 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printf_format(char specif, va_list *args, int *len, int *i)
{
	if (specif == 's')
		ft_string(va_arg(*args, char *), len);
	else if (specif == 'd' || specif == 'i')
		ft_number(va_arg(*args, int), len);
	else if (specif == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (specif == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (specif == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (specif == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (specif == 'c')
		ft_putcharacter_length(va_arg(*args, int), len);
	else if (specif == '%')
		ft_putcharacter_length('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		number;

	i = 0;
	number = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_format(format[i], &args, &number, &i);
			i++;
		}
		else
		{
			ft_putcharacter_length((char)format[i], &number);
			i++;
		}
	}
	va_end(args);
	return (number);
}

// int main(void)
// {
// 	ft_printf("Type %i!\n", -10);
// 	return (0);
// }
