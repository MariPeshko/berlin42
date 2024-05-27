/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:37:00 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/25 11:20:05 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_map *map)
{
	name_check(map);
	size_check(map);
	chrs_checks(map);
	wall_check(map);
	flood_fill(map);
}

void	free_for_finish(t_data *data)
{
	free_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_maps(data->map);
	free(data->mlx_ptr);
	exit(1);
}

void	get_map(t_map *map)
{
	int		j;
	int		fd;
	char	*str;

	j = 0;
	map->m_lines = 0;
	fd = open(map->file, O_RDONLY);
	no_file(fd, map);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->m_lines++;
		free(str);
	}
	close(fd);
	map->m_chrs = ft_calloc(sizeof(char *), map->m_lines);
	fd = open(map->file, O_RDONLY);
	while (j < map->m_lines)
		map->m_chrs[j++] = get_next_line(fd);
	str = get_next_line(fd);
	free(str);
	close(fd);
	map->m_columns = (int)ft_strlen(map->m_chrs[0]) - 1;
}

void	exit_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == 'E')
			{
				map->exit_x = i;
				map->exit_y = j;
			}
			j++;
		}
		i++;
	}
	if (find_chr(map, 'C') && (map->player_x != map->exit_x
			|| map->player_y != map->exit_y))
		map->m_chrs[map->exit_x][map->exit_y] = '0';
	if (!find_chr(map, 'C'))
		map->m_chrs[map->exit_x][map->exit_y] = 'E';
}
