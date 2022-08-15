/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:23:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/15 12:25:31 by gissao-m         ###   ########.fr       */
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
	t_map	maps;
	t_game game;
	t_imagedata image;

	//maps.fd = open(argv[1], O_RDONLY);
	// reading_the_map(argv[1]);
	ft_bzero(&maps, sizeof(t_map));
	maps.map_matrix = reading_the_map(argv[1]);
	map_saved_dimensions(&maps);
	map_verification(maps);
	init_struct(&game);
	render(&image, &maps, &game);
	// fazer uma func que irá receber todas as validações.
	return(0);
}
// preciso criar uma função que seja capaz de armazenar os dados lidos pela gnl
// utilizar a join para salvar o mapa em forma de matriz
//preciso salvar o mapa lido em algum lugar.