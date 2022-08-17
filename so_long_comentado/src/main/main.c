/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:23:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/16 12:19:47 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"





char **reading_the_map(char *pass_arg)
{
	int		i;
	t_map	maps;
	
	maps.readed_map = ft_strdup("");
	maps.fd = open(pass_arg, O_RDONLY);
	if (maps.fd < 0)
		exit(1);
	maps.buffer = get_next_line(maps.fd);
	while (maps.buffer)
	{
		maps.readed_map = ft_strjoin(maps.readed_map, maps.buffer);
		free(maps.buffer);
		maps.buffer = get_next_line(maps.fd);
		//printf("%s", buffer);
	}
	i = 0;
	maps.map_matrix = ft_split(maps.readed_map, '\n');
	while(maps.map_matrix[i])
	{
		printf("linha %d: %s\n", i, maps.map_matrix[i]);
		i++;
	}
	free(maps.readed_map);
	close(maps.fd);
	return(maps.map_matrix);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*put_zero;

	put_zero = str;
	while (n > 0)
	{
		*put_zero = 0;
		put_zero++;
		n--;
	}
}

void init_struct(t_game *game)
{
	game->player = malloc((sizeof(t_imagedata)) * 1);
	game->collect = malloc((sizeof(t_imagedata)) * 1);
	game->exit = malloc((sizeof(t_imagedata)) * 1);
	game->enemy = malloc((sizeof(t_imagedata)) * 1);
	game->empty = malloc((sizeof(t_imagedata)) * 1);
	game->wall = malloc((sizeof(t_imagedata)) * 1);
}

int main (int argc, char **argv)
{
	t_game *game;

	//maps.fd = open(argv[1], O_RDONLY);
	// reading_the_map(argv[1]);
	game = malloc(sizeof(t_game) * 1);
	game->map = malloc(sizeof(t_map) * 1);
	ft_bzero(game->map, 1);
	game->map->map_matrix = reading_the_map(argv[1]);
	map_saved_dimensions(game->map);
	map_verification(game->map);
	init_struct(game);
	render(game);
	// fazer uma func que irá receber todas as validações.
	return(0);
}
// preciso criar uma função que seja capaz de armazenar os dados lidos pela gnl
// utilizar a join para salvar o mapa em forma de matriz
//preciso salvar o mapa lido em algum lugar.