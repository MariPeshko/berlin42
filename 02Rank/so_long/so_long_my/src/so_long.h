/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:44:48 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/29 19:31:34 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 500
# define WIDTH 56
# define HEIGHT 56

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h> //Macros releated to the event names/masks, e.g. KeyPress
# include <X11/keysym.h> //Macros for key symbols, e.g. XK_Escape
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

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
	int				count_coins;
	int				map_height;
	int				map_width;
	int				is_door_open;
	int				e_r;
	int				e_c;
	char			**map;
	t_player_pos	*player_pos;

}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_relement	*assets;
}	t_mlx;

void	print_error(int type);
int		validate_map(char *map, t_mlx *mlx);
int		check_extention(char *map);

// images
int		load_img(t_mlx *mlx);

#endif
