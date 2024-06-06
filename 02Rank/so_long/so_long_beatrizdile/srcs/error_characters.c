/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:29 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:55 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	chrs_checks(t_map *map)
{
	int	collect;
	int	exited;
	int	player;
	int	i;
	int	j;

	i = 0;
	collect = 0;
	exited = 0;
	player = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j++ < map->m_columns)
		{
			if (map->m_chrs[i][j] == 'E')
				exited++;
			else if (map->m_chrs[i][j] == 'P')
				player++;
			else if (map->m_chrs[i][j] == 'C')
				collect++;
		}
		i++;
	}
	chr_error(exited, player, collect, map);
}

void	chr_error(int exited, int player, int collect, t_map *map)
{
	if (exited == 0)
	{
		ft_printf("Error in map validation: missing an exit.\n");
		free_maps(map);
		exit(1);
	}
	else if (exited > 1)
	{
		ft_printf("Error in map validation: more than one exit.\n");
		free_maps(map);
		exit(1);
	}
	else if (collect == 0)
	{
		ft_printf("Error in map validation: missing a collectible.\n");
		free_maps(map);
		exit(1);
	}
	chr_error_two(player, map);
	invalid_chrs_check(map);
}

void	chr_error_two(int player, t_map *map)
{
	if (player == 0)
	{
		ft_printf("Error in map validation: missing a player.\n");
		free_maps(map);
		exit(1);
	}
	else if (player > 1)
	{
		ft_printf("Error in map validation: more than one player.\n");
		free_maps(map);
		exit(1);
	}
}

void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->m_columns)
	{
		if (map->m_chrs[0][i] != '1')
			wall_error(map);
		if (map->m_chrs[map->m_lines - 1][i] != '1')
			wall_error(map);
		i++;
	}
	i = 0;
	while (i < map->m_lines)
	{
		if (map->m_chrs[i][0] != '1')
			wall_error(map);
		if (map->m_chrs[i][map->m_columns - 1] != '1')
			wall_error(map);
		i++;
	}
}

void	wall_error(t_map *map)
{
	ft_printf("Error in map validation: not surrounded by walls.\n");
	free_maps(map);
	exit(1);
}
