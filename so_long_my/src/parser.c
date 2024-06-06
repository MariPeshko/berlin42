/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:59 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/28 14:52:49 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_error(int type)
{
  ft_printf("Error: ");
  if (type == 7)
		ft_printf("Wrong map format\n");
  else if (type == 9)
    ft_printf("Malloc error\n");
  else if (type == 11)
    ft_printf("Wrong path to the map\nTo run a program: /so_long [name_of_map].ber\n");
}