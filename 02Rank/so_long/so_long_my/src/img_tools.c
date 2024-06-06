/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:50:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/29 19:34:27 by mpeshko          ###   ########.fr       */
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
	return (render_img);
}

int	load_img(t_mlx *mlx)
{
    mlx->assets->floor = add_img(*mlx, "assets/bg.xpm");
    return (0);
}