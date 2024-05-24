/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:28:25 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/26 15:36:22 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *ftms, ...);
void	go_print(va_list ap, const char *ftms, int *len);
void	handle_ptr(va_list ap, int *len);
void	ft_putszt_base(size_t nb, char *base, int *pflen);
void	ft_putnbr_base(ssize_t nb, char *base, int *pflen);
void	ft_putstr_mod(char *s, int *pflen);
int		ft_putchar_mod(char c);
size_t	ft_strlen(const char *s);

#endif
