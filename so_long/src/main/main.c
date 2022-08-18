/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:23:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 11:57:05 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	invalid_arg(t_map maps)
// {
//     	if (maps.fd < 0)
// 	{
// 		ft_printf(INV_ARG);
// 		return (NULL);
// 	}
// }
char	**clean_map(t_map *maps)
{
	while (maps->buffer)
	{
		free(maps->buffer);
		maps->buffer = get_next_line(maps->fd);
	}
	ft_printf(EPT_LNE);
	free(maps->readed_map);
	close(maps->fd);
	return (NULL);
}

char	**reading_the_map(char *pass_arg)
{
	t_map	maps;

	maps.fd = open(pass_arg, O_RDONLY);
	// printf("%s", clean_map(maps));
	// clean_map(maps);
    if (maps.fd < 0)
	{
		ft_printf(INV_ARG);
		return (NULL);
	}
	maps.readed_map = ft_strdup("");
	maps.buffer = get_next_line(maps.fd);
	while (maps.buffer)
	{
		if (maps.buffer[0] == '\n')
			return (clean_map(&maps));
		maps.readed_map = ft_strjoin(maps.readed_map, maps.buffer);
		free(maps.buffer);
		maps.buffer = get_next_line(maps.fd);
	}
	maps.map_matrix = ft_split(maps.readed_map, '\n');
	free(maps.readed_map);
	close(maps.fd);
	return (maps.map_matrix);
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

void	init_struct(t_game *game)
{
	game->player = ft_calloc((sizeof(t_imagedata)), 1);
	game->collect = ft_calloc((sizeof(t_imagedata)), 1);
	game->exit = ft_calloc((sizeof(t_imagedata)), 1);
	game->empty = ft_calloc((sizeof(t_imagedata)), 1);
	game->wall = ft_calloc((sizeof(t_imagedata)), 1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	game->map = ft_calloc(sizeof(t_map), 1);
	game->map->map_matrix = reading_the_map(argv[1]);
	if(game->map->map_matrix == NULL)
		kill_window(game);
	map_saved_dimensions(game->map);
	map_verification(game);
	init_struct(game);
	render(game);
	return (0);
}
