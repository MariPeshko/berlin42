/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:26 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/03 23:56:08 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_passed(int **passed, t_relement *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(passed[i]);
		i++;
	}
	free(passed);
}

// The is_move_valid function checks if a move is possible (the cell is not a
// wall and has not been visited).
int	is_move_valid(t_relement *game, int **passed, int row, int col)
{
    if (game->map[row][col] == '1')
        return (0); 
    if (passed[row][col])
        return (0); 
    return (1);
}

// int row, int col is a player's position on the map
// The function checks if the current position is valid for a move using
// is_move_valid(). If the position is valid It marks the current position as
// visited. By the wat the function counts coins. It recursively calls itself
// for the neighboring positions.
void	floodfill(t_relement *game, int row, int col, int **passed)
{
    if (!is_move_valid(game, passed, row, col))// || passed[row][col])
	 	return ;
	if (game->map[row][col] == 'C')
		game->coins_on_path++;
	passed[row][col] = 1;
	floodfill(game, row - 1, col, passed);
	floodfill(game, row + 1, col, passed);
	floodfill(game, row, col - 1, passed);
	floodfill(game, row, col + 1, passed);
}

int	find_escape_position(t_relement *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_row = i;
				game->exit_clm = j;
                return (0);
			}
			j++;
		}
		i++;
	}
    return (1);
}

int find_player_pos(t_relement *game, int *col, int *row)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (i < (game->map_height))
    {
        while (game->map[i][j] != '\n')
        {
            if (game->map[i][j] == 'P')
            {
                *row = i;
                *col = j;
                return (0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

// We use array of integers, filled by '\0' and floodfill apgorithm
// to check the way to all coins and the exit.
// i = passed[row][col] && passed[data->assets->exit_row][data->assets->exit_clm];
// This checks if the current cell at position (row, col) has been visited.
// If it has, passed[row][col] is 1; otherwise, it's 0.
// passed[data->assets->e_r][data->assets->e_c]
// This checks if the exit cell at position (data->assets->e_r,
// data->assets->e_c) has been visited.
int is_valid_path(t_mlx *data)
{
    int i;
    int row;
    int col;
    int **passed;

    passed = ft_calloc(data->assets->map_height, sizeof(int *));
    i = -1;
    while (++i < data->assets->map_height)
        passed[i] = ft_calloc(data->assets->map_width, sizeof(int *));
    find_player_pos(data->assets, &col, &row);
    find_escape_position(data->assets);
    floodfill(data->assets, row, col, passed);
    i = passed[row][col] && passed[data->assets->exit_row][data->assets->exit_clm];
	free_passed(passed, data->assets);  
    if (!passed || !i || data->assets->coins_on_path != data->assets->coins)
	{
		print_error(8);
		cleanup_and_exit(data);
		return (0);
	}
    return (1);
}