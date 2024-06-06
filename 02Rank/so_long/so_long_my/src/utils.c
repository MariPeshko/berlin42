/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:20 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/28 14:53:34 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checking if it is .ber extenstion
int	check_extention(char *map)
{
	int	i;

	i = 0;
	if (ft_strchr(map, '.') == 0)
		return (print_error(7), 0);
	while (map[i])
	{
		if (map[i] == '.')
		{
			if (!(map[i + 1] == 'b' && map[i + 2] == 'e' \
			&& map[i + 3] == 'r' && !(map[i + 4])))
				return (print_error(7), 0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int validate_map(char *map, t_mlx *mlx)
{
  if (!check_extention(map))
    return (0);
  if (!map)
    return (0);
  mlx->assets = (t_relement *)malloc(sizeof(t_relement));
  if (!mlx->assets)
    return (print_error(9), 0);
  mlx->assets->is_door_open = 0;
  mlx->assets->player_pos = NULL;
  return (1);
}