/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:46:45 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/04 13:58:59 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
  t_mlx data;

  if (argc != 2)
  {
    print_error(11);
    exit(1);
  }
  check_map_file(argv[1]);
  ft_init_values(&data);
  load_map(&data, argv[1]);
  init_libx(&data);
  load_img(&data);
  check_map(&data);
  determine_player_position(data.assets);
  render_assets(&data);
  mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_keypress, &data);
  mlx_hook(data.win, DestroyNotify, StructureNotifyMask, 
			cleanup_and_exit, &data);
  mlx_loop(data.mlx);
  return (0);
}