/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:57:23 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 14:45:45 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_map *map)
{
	map->posc_p->posc_x = 0;
	map->posc_p->posc_y = 0;
	map->checker_p = 0;
	map->checker_c = 0;
	map->checker_e = 0;
}

void	valid_characters(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->map->posc_p = malloc(sizeof(t_pp) * 1);
	init_vars(game->map);
	while (++y < game->map->width)
	{
		x = -1;
		while (++x < game->map->height)
		{
			if (game->map->map_matrix[y][x] == 'P')
			{
				game->map->checker_p++;
				game->map->posc_p->posc_x = x;
				game->map->posc_p->posc_y = y;
			}
			if (game->map->map_matrix[y][x] == 'C')
					game->map->checker_c++;
			if (game->map->map_matrix[y][x] == 'E')
					game->map->checker_e++;
		}
	}
}

void	checking_characters(t_game *game)
{
	if (game->map->checker_p != 1)
	{
		ft_printf(ONE_PLAY);
		kill_window(game);
	}
	if (game->map->checker_c == 0)
	{
		ft_printf(ONE_COL);
		kill_window(game);
	}
	if (game->map->checker_e == 0)
	{
		ft_printf(ONE_EXT);
		kill_window(game);
	}
}

int	invalid_characters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->width)
	{
		x = 0;
		while (x < game->map->height)
		{
			if (game->map->map_matrix[y] \
			&& game->map->map_matrix[y][x] != 'P' \
			&& game->map->map_matrix[y][x] != 'E' \
			&& game->map->map_matrix[y][x] != 'C' \
			&& game->map->map_matrix[y][x] != '1' \
			&& game->map->map_matrix[y][x] != '0')
			{
				ft_printf(INV_CHR);
				kill_window(game);
			}
			x++;
		}
		y++;
	}
	return (0);
}
