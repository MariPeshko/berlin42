/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:34:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 18:14:00 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// verify if a two-dimensional array (map) is rectangular, meaning all rows
// should have the same length.
int	check_rectang(t_mlx *mlx, char **map)
{
	size_t	first_line_row;
	int		i;
	size_t	len;

	first_line_row = ft_strlen(map[0]);
	i = 1;
	while (i < mlx->assets->map_height)
	{
		len = ft_strlen(map[i]);
		if (i == mlx->assets->map_height - 1)
			len++;
		if (len != first_line_row)
		{
			print_error(1);
			cleanup_and_exit(mlx);
		}
		i++;
	}
	return (1);
}

// The map can be composed of only 5 characters
int	check_5_char(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < (mlx->assets->map_width - 1))
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' \
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				print_error(3);
				cleanup_and_exit(mlx);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	components_error(int c, int e, int p, t_mlx *mlx)
{
	if (c >= 1 && e == 1 && p == 1)
		return (1);
	else
	{
		print_error(4);
		cleanup_and_exit(mlx);
		return (0);
	}
}
