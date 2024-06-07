/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:39:42 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 16:32:07 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_mlx *mlx, int y, int x, t_player_pos *c)
{
	ft_printf("Moves count: %d\n", mlx->assets->moves_count);
	mlx->assets->moves_count++;
	if (mlx->assets->map[c->y + y][c->x + x] == 'C' && \
			mlx->assets->coins-- != -1)
		mlx->assets->map[c->y + y][c->x + x] = '0';
	if (is_open(mlx) && mlx->assets->map[c->y + y][c->x + x] == 'E')
		cleanup_and_exit(mlx);
	if (!is_open(mlx) && mlx->assets->map[c->y + y][c->x + x] == 'E' \
	&& mlx->assets->map[c->y + (y * 2)][c->x + (2 * x)] != '1')
	{
		if (mlx->assets->map[c->y + (y * 2)][c->x + (2 * x)] == 'C')
			mlx->assets->coins--;
		mlx->assets->map[c->y + 2 * y][c->x + 2 * x] = 'P';
		mlx->assets->map[c->y][c->x] = '0';
		return ;
	}
	mlx->assets->map[c->y + y][c->x + x] = 'P';
	mlx->assets->map[c->y][c->x] = '0';
	return ;
}

int	run_player(t_mlx *mlx, int y, int x)
{
	int	i;
	int	j;

	i = mlx->assets->player_pos->y;
	j = mlx->assets->player_pos->x;
	if (!is_open(mlx) && mlx->assets->map[i + y][j + x] == 'E' && \
		(mlx->assets->map[i + (y * 2)][j + (2 * x)] == '1'))
		return (1);
	move(mlx, y, x, mlx->assets->player_pos);
	return (0);
}

// 65362: UP || 119: W; 65364: DOWN || 115: S
// 65361: LEFT || 97: A; 65363: RIGHT || 100: D
// y is an height, x is a width
void	movement_check(int keycode, t_mlx *data, t_player_pos *pl_pos)
{
	int	x;
	int	y;

	x = pl_pos->x;
	y = pl_pos->y;
	if ((keycode == 119 || keycode == 65362) && \
	(data->assets->map[y - 1][x] != '1'))
		run_player(data, -1, 0);
	else if ((keycode == 97 || keycode == 65361) && \
	(data->assets->map[y][x - 1] != '1'))
		run_player(data, 0, -1);
	else if ((keycode == 115 || keycode == 65364) && \
	(data->assets->map[y + 1][x] != '1'))
		run_player(data, 1, 0);
	if ((keycode == 100 || keycode == 65363) && \
	(data->assets->map[y][x + 1] != '1'))
		run_player(data, 0, 1);
}

// If the escape key (65307) is pressed, exit the program
// 65362: UP || 119: W; 65364: DOWN || 115: S
// 65361: LEFT || 97: A; 65363: RIGHT || 100: D
//
int	on_keypress(int keycode, t_mlx *data)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100 \
	|| keycode == 65362 || keycode == 65361 || keycode == 65364 || \
	keycode == 65363)
		movement_check(keycode, data, data->assets->player_pos);
	if (keycode == 65307)
		cleanup_and_exit(data);
	door_condition(data);
	determine_player_position(data->assets);
	render_assets(data);
	return (0);
}
