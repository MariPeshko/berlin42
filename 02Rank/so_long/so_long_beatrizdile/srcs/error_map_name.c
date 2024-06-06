/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:20:34 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/05/31 16:42:17 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	name_check(t_map *map)
{
	int	len;
	int	flag;

	flag = 0;
	len = ft_strlen(map->file);
	if (len >= 5)
	{
		if (map->file[len - 1] == 'r' && map->file[len - 2] == 'e'
			&& map->file[len - 3] == 'b' && map->file[len - 4] == '.'
			&& map->file[len - 5] != '.')
			flag = 1;
	}
	if (flag != 1)
	{
		ft_printf("Error in map validation: invalid map name.\n");
		free_maps(map);
		exit(1);
	}
}

void	no_file(int fd, t_map *map)
{
	int		byte;
	char	str[1];

	if (fd == -1)
	{
		ft_printf("Error in map validation: invalid map file.\n");
		exit(1);
	}
	byte = read(fd, str, 1);
	if (byte != 1)
	{
		close(fd);
		ft_printf("Error in map validation: empty map.\n");
		exit(1);
	}
	close(fd);
	fd = open(map->file, O_RDONLY);
}
