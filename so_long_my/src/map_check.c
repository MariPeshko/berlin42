/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:20 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/04 15:07:03 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// verify if a two-dimensional array (map) is rectangular, meaning all rows
// should have the same length.
int check_rectang(t_mlx *mlx, char **map)
{
	size_t first_line_row;
	int i;
	size_t len;

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
int check_5_char(t_mlx *mlx, char **map)
{
	int i;
	int j;

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

int components_error(int c, int e, int p, t_mlx *mlx) // char **map
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

// The map must contain - 1 E, 1 P and some C.
// It counts a number of coins.
void check_3_components(t_mlx *mlx, char **map)
{
	int exit;
	int player;
	int i;
	int j;

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
int check_map_size(t_mlx *data)
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
int count_lines(char *map)
{
	int file;
	int lines;
	char *temp;

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

// Перший і останній рядки мають бути ідентичними - strncmp
// Якщо рядок пустий, тобто починається із '\n', то мапа неправильна
// У кожному рядку перший та останній карактери мають бути ідентичні
// 1 for a wall
// прибрала звідси assets->moves_count = 0;
int check_borders(t_mlx *data, char **map, t_relement *assets)
{
	int i;

	i = 0;
	if (ft_strncmp(map[0], map[assets->map_height - 1],
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
void check_map(t_mlx *data)
{
	check_borders(data, data->assets->map, data->assets);
	check_map_size(data);
	check_3_components(data, data->assets->map);
	check_5_char(data, data->assets->map);
	check_rectang(data, data->assets->map);
	is_valid_path(data);
}