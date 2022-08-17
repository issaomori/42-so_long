/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:55:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/16 12:58:39 by gissao-m         ###   ########.fr       */
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

void	is_rectangular(t_map *map)
{
	int	count_size;

	count_size = -1;
	while (map->map_matrix[++count_size])
	{
		if (ft_strlen(map->map_matrix[count_size]) - 1 != map->width)
		{
			write(1, "Map is not Rectangular\n", 24);
			exit(0);
		}
	}
}

void	verifying_wall(t_map *map)
{
	int	count_size;

	count_size = -1;
	while (map->map_matrix[++count_size])
	{
		if (map->map_matrix[count_size][0] != '1' \
		|| map->map_matrix[count_size][map->height - 1] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);
		}
	}
	count_size = -1;
	while (++count_size < map->height)
	{
		if (map->map_matrix[0][count_size] != '1' \
		|| map->map_matrix[map->width - 1][count_size] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);
		}
	}
}

void	map_verification(t_map *map)
{
	is_rectangular(map);
	verifying_wall(map);
	valid_characters(map);
	if_there_is_no(map);
	invalid_characters(map);
}
