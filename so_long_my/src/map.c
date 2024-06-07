/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:43:22 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 17:50:19 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This function reads a map from a specified file, allocates memory for
// storing the map data, and initializes the map dimensions in the data
// structure. It also performs several validation checks to ensure the map's
// integrity and consistency.
void	load_map(t_mlx *data, char *map)
{
	int	fd;
	int	i;
	int	lines;

	fd = open(map, O_RDONLY);
	i = 0;
	lines = count_lines(map);
	data->assets->map = ft_calloc(sizeof(char *), (size_t)(lines) + 1);
	data->assets->map[0] = get_next_line(fd);
	data->assets->map_width = (int)ft_strlen(data->assets->map[0]);
	data->assets->map_height = lines;
	while (i++ < data->assets->map_height)
		data->assets->map[i] = get_next_line(fd);
	if (!data->assets->map)
	{
		print_error(6);
		cleanup_and_exit(data);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

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
			if (!(map[i + 1] == 'b' && map[i + 2] == 'e' && \
						map[i + 3] == 'r' && !(map[i + 4])))
				return (print_error(7), 0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	check_file(char *map)
{
	int		fd;
	int		byte;
	char	str[1];

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nNo such file or directory: %s\n", map);
		exit(1);
	}
	byte = read(fd, str, 1);
	if (byte != 1)
	{
		close(fd);
		print_error(10);
		exit(1);
	}
	close(fd);
	fd = open(map, O_RDONLY);
}

int	check_map_file(char *map)
{
	if (!map)
	{
		print_error(11);
		exit(1);
	}
	if (!check_extention(map))
		exit(1);
	check_file(map);
	return (0);
}
