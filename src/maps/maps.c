/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:55:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/15 11:03:34 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
// 1- Parsear() o arquivo do mapa:
// Ter parede tudo em volta. (a primeira e a ultima linha 
// deve ser 1 e a primeira e ultima coluna tbm!!!)




void map_saved_dimensions(t_map *dimensions)
{
	int lines;
	int column;

	lines = 0;
	column = 0;
	while(dimensions->map_matrix[0][column] != '\0')
		column++;
	while(dimensions->map_matrix[lines] != NULL)
		lines++;
	dimensions->height = column;
	//tamanho da linha.
	dimensions->width = lines;
	//tamanho da coluna.
	//printf("%d\n", dimensions->width);
	//printf("%d\n", dimensions->height);
	
}


void is_rectangular(t_map map)
{
	//para eu descobrir se ele é retangular, uso a len, pego o tamanho da primeira
	//linha e faço uma comparacao entre a primeira linha e o restando
	//se alguma for diferente da primeira linha, retornar erro.
	int count_size;
	count_size = -1;

	while(map.map_matrix[++count_size])
	{
		if (ft_strlen(map.map_matrix[count_size]) - 1 != map.width)
		
			// printf("%d\n", map.width);
			// printf("%d\n", ft_strlen(map.map_matrix[count_size]) -1);
			{
				write(1, "Map is not Rectangular\n", 24);
				exit(0);
			}
	}
}
// int main(int argc , char **argv[1])
// {
// 	t_map map;
// 	is_rectangular(map.map_matrix);
// }

//ela precisa preencher x(linha, horizontal) e y(coluna, vertical) 
void    verifying_wall(t_map map)
{
	int		count_size;
	// count_size = 0;
	count_size = -1;
	//vou usar o contador pra verificar a primeira e a ultima coluna(x), se é 1,
	//caso nao seja vai me retornar 'error'.
	//preciso pegar os valores da primeira(linha 1) e ultima linha(tamanho total do mapa).
	//preciso pegar os valores da primeira(primeiro carcater de cada linha)e ultima coluna(ultimo caractere de cada
	//linha).
	while(map.map_matrix[++count_size])
	// while(map.map_matrix[count_size] != '\0')
	{
		if (map.map_matrix[count_size][0] != '1' \
		|| map.map_matrix[count_size][map.height - 1] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);	
		}
	}
	// printf("%d\n", map.width);
	count_size = -1;
	
	while(++count_size < map.height)
	{
		if (map.map_matrix[0][count_size] != '1' \
		|| map.map_matrix[map.width - 1][count_size] != '1')
		{
			write(1, "DEU ERRO NESSE CARAIO", 22);
			exit(0);
		}
	}

}

void valid_characters(t_map *map)
{
	int x;
	//vai ser para o width.
	int y;
	//vai ser pro height.
	x = 0;
	y = 0;
	
	while(x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->map_matrix[x][y] == 'P')
					map->checker_p++;
			if (map->map_matrix[x][y] == 'C')
					map->checker_c++;
			if (map->map_matrix[x][y] == 'E')
					map->checker_e++;
			y++;
		}
		x++;
	}
}

void if_there_is_no(t_map *map)
{
	if(map->checker_p != 1)
	{
		printf("Nao tem player");
		exit(0);	
	}
	if(map->checker_c == 0)
	{
		printf("Nao tem coletavel");
		exit(0);
	}
	if(map->checker_e == 0)
	{
		printf("Nao tem saida nessa merda");
		exit(0);
	}
}

int invalid_characters(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if(map->map_matrix[y] && map->map_matrix[y][x] != 'P'
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
	return(0);
}

void map_verification(t_map map)
{
	is_rectangular(map);
	verifying_wall(map);
	valid_characters(&map);
	if_there_is_no(&map);
	invalid_characters(&map);
}
