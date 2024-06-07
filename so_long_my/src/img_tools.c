/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:50:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 17:28:33 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	add_img(t_mlx data, char *path)
{
	t_img	render_img;

	render_img.width = WIDTH;
	render_img.height = HEIGHT;
	render_img.img = mlx_xpm_file_to_image(data.mlx, path, \
		&render_img.width, &render_img.height);
	if (render_img.img == NULL)
	{
		ft_printf("\nFailed to load XPM image:\nCheck the %s\n", path);
		ft_printf("or check the permissions of the %s\n\n", path);
		cleanup_map_and_exit(&data);
	}
	return (render_img);
}

int	load_img(t_mlx *mlx)
{
	mlx->assets->floor = add_img(*mlx, "assets/back120.xpm");
	mlx->assets->wall = add_img(*mlx, "assets/wall120.xpm");
	mlx->assets->coin = add_img(*mlx, "assets/mine120.xpm");
	mlx->assets->player = add_img(*mlx, "assets/dog120.xpm");
	mlx->assets->door_open = add_img(*mlx, "assets/door_op120.xpm");
	mlx->assets->door_closed = add_img(*mlx, "assets/door_cl120.xpm");
	return (0);
}

void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

void	print_door(t_mlx *mlx, int i, int j)
{
	if (!mlx->assets->is_door_open)
		mlx_render_img(mlx, mlx->assets->door_closed, \
			j * WIDTH, i * HEIGHT);
	else if (mlx->assets->is_door_open)
		mlx_render_img(mlx, mlx->assets->door_open, \
			j * WIDTH, i * HEIGHT);
}

int	render_assets(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = -1;
		while (++j < mlx->assets->map_width)
		{
			if (mlx->assets->map[i][j] == '1')
				mlx_render_img(mlx, mlx->assets->wall, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'C')
				mlx_render_img(mlx, mlx->assets->coin, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'P')
				mlx_render_img(mlx, mlx->assets->player, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == '0')
				mlx_render_img(mlx, mlx->assets->floor, j * WIDTH, i * HEIGHT);
			else if (mlx->assets->map[i][j] == 'E')
				print_door(mlx, i, j);
		}
	}
	return (0);
}
