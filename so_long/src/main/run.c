/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:20:50 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/29 19:02:47 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_protect(game);
		exit(EXIT_FAILURE);
	}
	game->window = mlx_new_window(game->mlx, game->map->height * PXL, \
	game->map->width * PXL, TITLE);
	open_image(game);
	render(game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_hook(game->window, 2, 1L << 0, keys_to_move, (void *)game);
	mlx_loop_hook(game->mlx, refresh, game);
	mlx_loop(game->mlx);
}

void	init_struct(t_game *game)
{
	game->player = ft_calloc((sizeof(t_imagedata)), 1);
	game->collect = ft_calloc((sizeof(t_imagedata)), 1);
	game->exit = ft_calloc((sizeof(t_imagedata)), 1);
	game->empty = ft_calloc((sizeof(t_imagedata)), 1);
	game->wall = ft_calloc((sizeof(t_imagedata)), 1);
}

char	**reading_the_map(char *pass_arg)
{
	t_map	maps;

	if (checking_map_file(pass_arg) != 0)
		return (NULL);
	maps.fd = open(pass_arg, O_RDONLY);
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

int	checking_map_file(char *pass_arg)
{
	int		count1;
	int		count2;
	char	*comp;

	comp = ft_strdup(".ber");
	count1 = ft_strlen(pass_arg);
	count2 = ft_strlen(comp);
	while (count2 >= 0)
	{
		if (pass_arg[count1] != comp[count2])
		{
			free(comp);
			return (ft_printf(INV_ARG));
		}
		count1--;
		count2--;
	}
	free (comp);
	return (0);
}
