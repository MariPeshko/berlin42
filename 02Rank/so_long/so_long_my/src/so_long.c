/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:46:45 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/29 19:30:36 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

  if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
  // int offset = (y * line_length + x * (bits_per_pixel / 8));
	{
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
  }
}

int	close_w(int keycode, t_mlx *data)
{
  // 65307 = ESC
  if (keycode == 65307)
      mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int main(int ac, char **av)
{
  t_mlx   data;
  t_data	img;

  if (ac == 2)
  {
    if (!validate_map(av[1], &data))
      return (0);
    data.mlx = mlx_init();
    if (!data.mlx)
      return (0);
    data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, \
			SCREEN_HEIGHT, "so_long");
    if (!data.win)
			return (free(data.mlx), 1);
    load_img(&data);
    //
    img.img = mlx_new_image(data.mlx, 960, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    
    // точка, з якої почнеться малюнок
    mlx_put_image_to_window(data.mlx, data.win, img.img, 500, 200);
    // малювання пікселів
    my_mlx_pixel_put(&img, 0, 1, 0x0066FF00);
    my_mlx_pixel_put(&img, 1, 1, 0x0066FF00);
    my_mlx_pixel_put(&img, 2, 1, 0x0066FF00);
    my_mlx_pixel_put(&img, 3, 1, 0x0066FF00);
    my_mlx_pixel_put(&img, 4, 1, 0x0066FF00);
    my_mlx_pixel_put(&img, 5, 1, 0x0066FF00);
    // Here we register to the KeyPress event with the
    // according KeyPressMask. Now whenever we press a
    // key, the window will be closed.
    mlx_hook(data.win, 2, 1L<<0, close_w, &data);
    mlx_loop(data.mlx);
  }
  else
    print_error(11);
  return (0);
}