/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:37:48 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/25 15:50:48 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define FLOOR "sprites/floor_desert_2_64.xpm"
# define MONSTER "sprites/zombie_64.xpm"
# define COWBOY "sprites/cowboy_front_64.xpm"
# define COWBOY_FORWARD "sprites/cowboy_forward_64.xpm"
# define COWBOY_BACK "sprites/cowboy_back_64.xpm"
# define COWBOY_LEFT "sprites/cowboy_left_64.xpm"
# define COWBOY_RIGHT "sprites/cowboy_right_64.xpm"
# define HEART "sprites/coin_64.xpm"
# define STAR "sprites/star_64.xpm"
# define CACTUS "sprites/cactus_64.xpm"

typedef struct s_frame
{
	int				x;
	int				y;
	int				i;
	int				j;
}					t_frame;

typedef struct s_map
{
	unsigned int	moves;
	char			**m_chrs;
	char			**c_chrs;
	char			*file;
	int				player_side;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				m_columns;
	int				m_lines;
}					t_map;

typedef struct s_img
{
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
	void			*img5;
	void			*img6;
	void			*img7;
	void			*img8;
	void			*img9;
	void			*img10;
	int				x;
	int				y;
}					t_img;

typedef struct s_data
{
	t_map			*map;
	t_img			*img;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_data;

void				init_libx(t_data *data, t_map *map);
void				get_map(t_map *map);
void				get_images(t_map *map, t_data *data);
void				put_images(t_map *map, t_data *data);
void				hooks(t_data *data);
void				free_for_finish(t_data *data);
int					handle_no_event(void *data);
int					handle_keypress(int keysym, t_data *data);
int					handle_x_press(t_data *data);
void				free_maps(t_map *map);
void				free_images(t_data *data);
void				valid_map(t_map *map);
void				chrs_checks(t_map *map);
void				chr_error(int exited, int player, int collect, t_map *map);
void				chr_error_two(int player, t_map *map);
void				name_check(t_map *map);
void				no_file(int fd, t_map *map);
void				wall_check(t_map *map);
void				wall_error(t_map *map);
void				invalid_chrs_check(t_map *map);
void				invalid_chrs_error(t_map *map);
void				size_check(t_map *map);
void				size_error(t_map *map);
void				flood_fill(t_map *map);
void				fill(t_map *map, int x, int y);
void				map_dup(t_map *map);
void				path_error(t_map *map, int flag);
void				path_check(t_map *map);
void				movement_check(int keysym, t_data *data, t_map *map);
int					find_chr(t_map *map, char ch);
void				new_frame(t_data *data, t_frame *frame);
void				exit_check(t_map *map);
void				mlx_put_images(t_map *map, t_data *data, int i, int j);
void				player_sides(t_data *data, t_frame *frame);
void				find_player(t_map *map);
void				get_other_images(t_data *data);

#endif
