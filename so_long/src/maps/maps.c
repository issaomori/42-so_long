/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:55:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/17 16:36:24 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	map_saved_dimensions(t_map *dimensions)
{
	int	lines;
	int	column;

	lines = 0;
	column = 0;
	while (dimensions->map_matrix[0][column] != '\0')
		column++;
	while (dimensions->map_matrix[lines] != NULL)
		lines++;
	dimensions->height = column;
	dimensions->width = lines;
}

void	is_rectangular(t_game *game)
{
	int	count_size;

	count_size = -1;
	while (game->map->map_matrix[++count_size])
	{
		if (ft_strlen(game->map->map_matrix[count_size]) != game->map->height)
		{
			write(1, "Map is not Rectangular\n", 24);
			kill_window(game);
		}
	}
}

	void	verifying_wall(t_game *game)
{
	int	count_size;

	count_size = -1;
	while (game->map->map_matrix[++count_size])
	{
		if (game->map->map_matrix[count_size][0] != '1' \
		|| game->map->map_matrix[count_size][game->map->height - 1] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);
		}
	}
	count_size = -1;
	while (++count_size < game->map->height)
	{
		if (game->map->map_matrix[0][count_size] != '1' \
		|| game->map->map_matrix[game->map->width - 1][count_size] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);
		}
	}
}

void	map_verification(t_game *game)
{
	is_rectangular(game);
	verifying_wall(game);
	valid_characters(game);
	if_there_is_no(game);
	invalid_characters(game);
}
