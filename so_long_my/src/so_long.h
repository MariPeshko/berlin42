/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:44:48 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 18:14:47 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1000
# define WIDTH 120
# define HEIGHT 120

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h> //Macros releated to the event names/masks, e.g. KeyPress
# include <X11/keysym.h> //Macros for key symbols, e.g. XK_Escape
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct t_player_pos
{
	int		x;
	int		y;
}	t_player_pos;

typedef struct t_relement
{
	t_img			wall;
	t_img			coin;
	t_img			player;
	t_img			door_open;
	t_img			door_closed;
	t_img			floor;
	int				moves_count;
	int				coins;
	int				coins_on_path;
	int				map_height;
	int				map_width;
	int				is_door_open;
	int				exit_row;
	int				exit_clm;
	char			**map;
	t_player_pos	*player_pos;

}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_relement	*assets;
}	t_mlx;

// error handling
void	print_error(int type);
int		ft_init_values(t_mlx *data);

// minilibx
void	init_libx(t_mlx *data);

// map
int		check_map_file(char *map);
int		check_extention(char *map);
void	check_file(char *map);
void	load_map(t_mlx *data, char *map);
int		count_lines(char *map);

// map checking
void  	check_map(t_mlx *data);
int		check_borders(t_mlx *data, char **map, t_relement *assets);
int		check_map_size(t_mlx *data); // char **map, t_relement *assets
void	check_3_components(t_mlx *mlx, char **map);
int		components_error(int c, int e, int p, t_mlx *mlx);
int		check_5_char(t_mlx *mlx, char **map);
int		check_rectang(t_mlx *mlx, char **map);

// map valid path
int		is_valid_path(t_mlx *data);

// images
int		load_img(t_mlx *mlx);
t_img	add_img(t_mlx data, char *path);
int		render_assets(t_mlx *mlx);
void	mlx_render_img(t_mlx *mlx, t_img img, int x, int y);

// time to play
void	determine_player_position(t_relement *game);
int		on_keypress(int keycode, t_mlx *data);
void	movement_check(int keycode, t_mlx *data, t_player_pos *pl_pos);
int		run_player(t_mlx *mlx, int y, int x);
void	move(t_mlx *mlx, int y, int x, t_player_pos *c);
int		is_open(t_mlx *mlx);
void	door_condition(t_mlx *data);

// freeing
int		cleanup_and_exit(t_mlx *data);
void	cleanup_map_and_exit(t_mlx *data);
void	free_passed(int **passed, t_relement *game);

#endif
