/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:57:23 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:53 by gissao-m         ###   ########.fr       */
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

void	valid_characters(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	map->posc_p = malloc(sizeof(t_pp) * 1);
	init_vars(map);
	while (++y < map->width)
	{
		x = -1;
		while (--x < map->height)
		{
			if (map->map_matrix[y][x] == 'P')
			{
				map->checker_p++;
				map->posc_p->posc_x = x;
				map->posc_p->posc_y = y;
			}
			if (map->map_matrix[y][x] == 'C')
					map->checker_c++;
			if (map->map_matrix[y][x] == 'E')
					map->checker_e++;
		}
	}
}

void	if_there_is_no(t_map *map)
{
	if (map->checker_p != 1)
	{
		printf("Nao tem player");
		exit(0);
	}
	if (map->checker_c == 0)
	{
		printf("Nao tem coletavel");
		exit(0);
	}
	if (map->checker_e == 0)
	{
		printf("Nao tem saida nessa merda");
		exit(0);
	}
}

int	invalid_characters(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->map_matrix[y] && map->map_matrix[y][x] != 'P'
			&& map->map_matrix[y][x] != 'E' && map->map_matrix[y][x] != 'C'
			&& map->map_matrix[y][x] != '1' && map->map_matrix[y][x] != '0')
			{
				printf("Invalid Character\n");
				exit(0);
			}
		y++;
		}
	x++;
	}
	return (0);
}
