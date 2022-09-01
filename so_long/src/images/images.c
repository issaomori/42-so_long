/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:00:42 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/24 15:49:07 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(t_game *game)
{
	game->player->image = mlx_xpm_file_to_image(game->mlx, \
	PLAYER, &game->player->i, &game->player->j);
	game->collect->image = mlx_xpm_file_to_image(game->mlx, \
	COLLECT, &game->collect->i, &game->collect->j);
	game->empty->image = mlx_xpm_file_to_image(game->mlx, \
	EMPTY, &game->empty->i, &game->empty->j);
	game->exit->image = mlx_xpm_file_to_image(game->mlx, \
	EXIT, &game->exit->i, &game->exit->j);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, \
	WALL, &game->wall->i, &game->wall->j);
}

void	colisions(t_game *game, int p_ty, int p_tx)
{
	if (game->map->map_matrix[p_ty] && game->map->map_matrix[p_ty][p_tx] != '1')
	{
		if (game->map->map_matrix[p_ty][p_tx] == 'C')
		{
			game->map->map_matrix[game->map->posc_p->posc_y] \
			[game->map->posc_p->posc_x] = '0';
			game->map->map_matrix[p_ty][p_tx] = 'P';
			game->map->checker_c--;
		}
		if (game->map->map_matrix[p_ty][p_tx] == 'E')
		{
			if (game->map->checker_c == 0)
				kill_window(game);
		}
		else
		{
			game->map->map_matrix[game->map->posc_p->posc_y] \
			[game->map->posc_p->posc_x] = '0';
			game->map->posc_p->posc_x = p_tx;
			game->map->posc_p->posc_y = p_ty;
			game->map->c_mv++;
		}
	}
}

int	keys_to_move(int key_press, t_game *game)
{
	int	p_tx;
	int	p_ty;

	p_tx = game->map->posc_p->posc_x;
	p_ty = game->map->posc_p->posc_y;
	if (key_press == KEY_ESC)
		kill_window(game);
	if (key_press == KEY_UP)
		p_ty--;
	if (key_press == KEY_DOWN)
		p_ty++;
	if (key_press == KEY_LEFT)
		p_tx--;
	if (key_press == KEY_RIGHT)
		p_tx++;
	colisions (game, p_ty, p_tx);
	render (game);
	return (0);
}

void	put_image(t_game *game, t_imagedata *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, \
	image->image, x * PXL, y * PXL);
}

void	render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->width)
	{
		x = -1;
		while (++x < game->map->height)
		{
			if (game->map->map_matrix[y][x] == 'C')
				put_image(game, game->collect, x, y);
			if (game->map->map_matrix[y][x] == 'E')
				put_image(game, game->exit, x, y);
			if (game->map->map_matrix[y][x] == '1')
				put_image(game, game->wall, x, y);
			if (game->map->map_matrix[y][x] == '0')
				put_image(game, game->empty, x, y);
		}
		mlx_put_image_to_window(game->mlx, game->window, game->player->image, \
		game->map->posc_p->posc_x * PXL, game->map->posc_p->posc_y * PXL);
	}
	ft_printf("\e[1;1H\e[2J Move: %d\n", game->map->c_mv);
}
