/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:52 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/25 16:28:38 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_libx(t_data *data, t_map *map)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("Error in max_init function.\n");
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, (map->m_columns * 64),
			(map->m_lines * 64), "so_long");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error in max_new_window function.\n");
		free(data->win_ptr);
		exit(1);
	}
}

void	get_images(t_map *map, t_data *data)
{
	map->moves = 0;
	data->img->img1 = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->img->x,
			&data->img->y);
	data->img->img2 = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER, \
		&data->img->x, &data->img->y);
	data->img->img3 = mlx_xpm_file_to_image(data->mlx_ptr, COWBOY, \
		&data->img->x, &data->img->y);
	data->img->img4 = mlx_xpm_file_to_image(data->mlx_ptr, HEART, &data->img->x,
			&data->img->y);
	data->img->img5 = mlx_xpm_file_to_image(data->mlx_ptr, STAR, &data->img->x, \
		&data->img->y);
	data->img->img6 = mlx_xpm_file_to_image(data->mlx_ptr, CACTUS, \
		&data->img->x, &data->img->y);
	get_other_images(data);
	if (data->img->img1 == NULL || data->img->img2 == NULL
		|| data->img->img3 == NULL || data->img->img4 == NULL
		|| data->img->img5 == NULL || data->img->img6 == NULL
		|| data->img->img7 == NULL || data->img->img8 == NULL
		|| data->img->img9 == NULL || data->img->img10 == NULL)
		free_for_finish(data);
	find_player(map);
	exit_check(map);
	put_images(map, data);
}

void	put_images(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	find_player(map);
	exit_check(map);
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
						data->img->img1, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
						data->img->img6, (64 * j), (64 * i));
			mlx_put_images(map, data, i, j);
			j++;
		}
		i++;
	}
}

void	mlx_put_images(t_map *map, t_data *data, int i, int j)
{
	if (map->m_chrs[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img4,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img5,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img3,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'X')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img2,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'F')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img7,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'B')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img8,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'L')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img9,
			(64 * j), (64 * i));
	else if (map->m_chrs[i][j] == 'R')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img10,
			(64 * j), (64 * i));
}

void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, &handle_x_press, data);
	mlx_loop(data->mlx_ptr);
}
