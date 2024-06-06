/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:27:33 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/26 14:42:39 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_check(int keysym, t_data *data, t_map *map)
{
	t_frame	frame;

	find_player(map);
	frame.x = map->player_x;
	frame.y = map->player_y;
	frame.i = map->player_x;
	frame.j = map->player_y;
	if ((keysym == 119 || keysym == 65362) && (map->m_chrs[frame.x
				- 1][frame.y] != '1'))
		frame.i -= 1;
	else if ((keysym == 97 || keysym == 65361) && (map->m_chrs[frame.x][frame.y
			- 1] != '1'))
		frame.j -= 1;
	else if ((keysym == 115 || keysym == 65364) && (map->m_chrs[frame.x
				+ 1][frame.y] != '1'))
		frame.i += 1;
	else if ((keysym == 100 || keysym == 65363) && (map->m_chrs[frame.x][frame.y
			+ 1] != '1'))
		frame.j += 1;
	if (frame.i != map->player_x || frame.j != map->player_y)
		new_frame(data, &frame);
}

void	new_frame(t_data *data, t_frame *frame)
{
	data->map->moves += 1;
	ft_printf("Moves: %d\n", data->map->moves);
	if (data->map->m_chrs[frame->i][frame->j] == 'X'
		|| data->map->m_chrs[frame->i][frame->j] == 'E')
	{
		if (data->map->m_chrs[frame->i][frame->j] == 'X')
			ft_printf("Game Over.\n");
		else
			ft_printf("You Win.\n");
		free_for_finish(data);
	}
	player_sides(data, frame);
	data->map->m_chrs[frame->x][frame->y] = '0';
	data->map->m_chrs[frame->i][frame->j] = data->map->player_side;
	put_images(data->map, data);
}

int	find_chr(t_map *map, char ch)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == ch)
				flag++;
			j++;
		}
		i++;
	}
	return (flag);
}

void	player_sides(t_data *data, t_frame *frame)
{
	char	ch;

	if (frame->x < frame->i)
		ch = 'F';
	if (frame->y < frame->j)
		ch = 'R';
	if (frame->x > frame->i)
		ch = 'B';
	if (frame->y > frame->j)
		ch = 'L';
	data->map->player_side = ch;
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == 'P' || map->m_chrs[i][j] == 'B'
				|| map->m_chrs[i][j] == 'F' || map->m_chrs[i][j] == 'L'
				|| map->m_chrs[i][j] == 'R')
			{
				map->player_x = i;
				map->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
