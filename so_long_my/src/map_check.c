/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:20 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 17:34:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// The map must contain - 1 E, 1 P and some C.
// It counts a number of coins.
void	check_3_components(t_mlx *mlx, char **map)
{
	int	exit;
	int	player;
	int	i;
	int	j;

	i = -1;
	exit = 0;
	player = 0;
	while (++i < mlx->assets->map_height)
	{
		j = -1;
		while (++j < mlx->assets->map_width)
		{
			if (map[i][j] == 'C')
				mlx->assets->coins++;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				player++;
		}
	}
	components_error(mlx->assets->coins, exit, player, mlx);
}

// check if a map fits into the screen
int	check_map_size(t_mlx *data)
{
	if ((data->assets->map_width - 1) * WIDTH > SCREEN_WIDTH || \
		(data->assets->map_height * HEIGHT) > SCREEN_HEIGHT)
	{
		print_error(5);
		cleanup_and_exit(data);
	}
	return (1);
}

// Counting the number of map lines using the get_next_line
int	count_lines(char *map)
{
	int		file;
	int		lines;
	char	*temp;

	lines = 0;
	file = open(map, O_RDONLY);
	temp = get_next_line(file);
	while (temp)
	{
		lines++;
		free(temp);
		temp = get_next_line(file);
	}
	close(file);
	return (lines);
}

// The first and last lines must be identical - checking with strncmp
// If the string is empty, i.e. starts with ‘\n’, then the map is incorrect
// In each line, the first and last characters must be identical
int	check_borders(t_mlx *data, char **map, t_relement *assets)
{
	int	i;

	i = 0;
	if (ft_strncmp(map[0], map[assets->map_height - 1], \
	assets->map_width) != 0)
		return (0);
	while (i < assets->map_height)
	{
		if (map[i][0] == '\n')
			return (0);
		if (map[i][0] != '1' || map[i][assets->map_width - 1] != '1')
		{
			print_error(2);
			cleanup_and_exit(data);
			return (0);
		}
		i++;
	}
	return (1);
}

// is_valid_path - To ensure that the player can access all collectibles
// of the map
void	check_map(t_mlx *data)
{
	check_borders(data, data->assets->map, data->assets);
	check_map_size(data);
	check_3_components(data, data->assets->map);
	check_5_char(data, data->assets->map);
	check_rectang(data, data->assets->map);
	is_valid_path(data);
}
