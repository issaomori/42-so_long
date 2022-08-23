/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:23:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/23 12:58:47 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf(INV_ARG));
	game = ft_calloc(sizeof(t_game), 1);
	game->map = ft_calloc(sizeof(t_map), 1);
	game->map->map_matrix = reading_the_map(argv[1]);
	if (game->map->map_matrix == NULL)
		kill_window(game);
	map_saved_dimensions(game->map);
	map_verification(game);
	init_struct(game);
	run(game);
	return (0);
}
