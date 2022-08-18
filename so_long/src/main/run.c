/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:20:50 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 15:21:14 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->height * PXL, \
	game->map->width * PXL, TITLE);
	open_image(game);
	render(game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_hook(game->window, 2, 1L << 0, keys_to_move, (void *)game);
	mlx_loop_hook(game->mlx, refresh, game);
	mlx_loop(game->mlx);
}
