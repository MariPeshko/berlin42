/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:28:32 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/26 15:27:30 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(ssize_t nb, char *base, int *pflen)
{
	int	bslen;

	bslen = ft_strlen(base);
	if (nb == 0)
		*pflen += ft_putchar_mod(base[0]);
	else if (nb > -bslen && nb < bslen)
	{
		if (nb < 0)
		{
			*pflen += ft_putchar_mod('-');
			nb = -nb;
		}
		*pflen += ft_putchar_mod(base[nb]);
	}
	else
	{
		ft_putnbr_base(nb / bslen, base, pflen);
		if (nb < 0)
			*pflen += ft_putchar_mod(base[(nb % bslen) * -1]);
		else
			*pflen += ft_putchar_mod(base[nb % bslen]);
	}
}

void	ft_putszt_base(size_t nb, char *base, int *pflen)
{
	size_t	bslen;

	bslen = ft_strlen(base);
	if (nb == 0)
		*pflen += ft_putchar_mod(base[0]);
	else if (nb < bslen)
		*pflen += ft_putchar_mod(base[nb]);
	else
	{
		ft_putszt_base(nb / bslen, base, pflen);
		*pflen += ft_putchar_mod(base[nb % bslen]);
	}
}

void	handle_ptr(va_list ap, int *len)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		ft_putstr_mod("(nil)", len);
		return ;
	}
	ft_putstr_mod("0x", len);
	ft_putszt_base((uintptr_t)ptr, "0123456789abcdef", len);
}

void	go_print(va_list ap, const char *fmts, int *len)
{
	if (*fmts == '%')
		*len += ft_putchar_mod('%');
	else if (*fmts == 'c')
		*len += ft_putchar_mod(va_arg(ap, int));
	else if (*fmts == 's')
		ft_putstr_mod(va_arg(ap, char *), len);
	else if (*fmts == 'p')
		handle_ptr(ap, len);
	else if (*fmts == 'i' || *fmts == 'd')
		ft_putnbr_base(va_arg(ap, int), "0123456789", len);
	else if (*fmts == 'x')
		ft_putszt_base(va_arg(ap, uint32_t), "0123456789abcdef", len);
	else if (*fmts == 'X')
		ft_putszt_base(va_arg(ap, uint32_t), "0123456789ABCDEF", len);
	else if (*fmts == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", len);
	else
		*len = -1;
}

int	ft_printf(const char *fmts, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = -1;
	len = 0;
	if (!fmts)
		return (-1);
	va_start(ap, fmts);
	while (fmts[++i] && len != -1)
	{
		if (fmts[i] == '%')
			go_print(ap, &fmts[++i], &len);
		else
			len += ft_putchar_mod(fmts[i]);
	}
	va_end(ap);
	return (len);
}
