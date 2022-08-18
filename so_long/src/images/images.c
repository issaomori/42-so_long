/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:00:42 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 14:11:26 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	count_size;

	count_size = 0;
	if (matrix == NULL)
		return ;
	while (matrix[count_size])
	{
		free(matrix[count_size]);
		count_size++;
	}
	free(matrix);
}

int	kill_window(t_game *game)
{
	if(game->mlx && game->collect->image != 0)
		mlx_destroy_image(game->mlx, game->collect->image);
	if(game->mlx && game->player->image != 0)
		mlx_destroy_image(game->mlx, game->player->image);
	if(game->mlx && game->wall->image != 0)
		mlx_destroy_image(game->mlx, game->wall->image);
	if(game->mlx && game->exit->image != 0)
		mlx_destroy_image(game->mlx, game->exit->image);
	if(game->mlx && game->empty->image != 0)
		mlx_destroy_image(game->mlx, game->empty->image);
	if(game->mlx && game->window != 0)
		mlx_clear_window(game->mlx, game->window);
	if(game->mlx && game->window != 0)
		mlx_destroy_window(game->mlx, game->window);
	if(game->mlx != 0)
		mlx_destroy_display(game->mlx);
	if(game->mlx != 0)
		mlx_loop_end(game->mlx);
	free_protect(game);
	exit(0);
}

void free_protect(t_game *game)
{
	if(game->mlx != 0)
		free (game->mlx);
	if(game->player != 0)
		free (game->player);
	if(game->collect != 0)
		free (game->collect);
	if(game->exit != 0)
		free (game->exit);
	if(game->empty != 0)
		free (game->empty);
	if(game->wall != 0)
		free (game->wall);
	if(game->map->posc_p != 0)
		free (game->map->posc_p);
	if(game->map->map_matrix != 0)
		free_matrix (game->map->map_matrix);
	if(game->map != 0)
		free (game->map);
	if(game != 0)
		free (game);
}

int    refresh(t_game *game)
{
    if (game->reset < 20)
        game->reset += 0.0001;
    else
    {
        mlx_clear_window(game->mlx, game->window);
        game->reset = 0;
    }
    where_are_sprites(game);
    return (0);
}

void	render(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->height * 	PXL, \
	game->map->width * 	PXL, TITLE);
	open_image(game);
	where_are_sprites(game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_hook(game->window, 2, 1L << 0, keys_to_move, (void *)game);
	mlx_loop_hook(game->mlx, refresh, game);
	mlx_loop(game->mlx);
}



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
			if(game->map->checker_c == 0)
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

int keys_to_move(int key_press, t_game *game)
{
	int	p_tx;
	int	p_ty;

	p_tx = game->map->posc_p->posc_x;
	p_ty = game->map->posc_p->posc_y;
	if(key_press == KEY_ESC)
		kill_window(game);
	if(key_press == KEY_UP)
		p_ty--;
	if(key_press == KEY_DOWN)
		p_ty++;
	if(key_press == KEY_LEFT)
		p_tx--;
	if(key_press == KEY_RIGHT)
		p_tx++;
	colisions(game, p_ty, p_tx);
	where_are_sprites(game);
	return(0);
}

void	where_are_sprites(t_game *game)
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
				mlx_put_image_to_window(game->mlx, game->window, \
				game->collect->image, x * PXL, y * PXL);
			if (game->map->map_matrix[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->exit->image, x * PXL, y * PXL);
			if (game->map->map_matrix[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->wall->image, x * PXL, y * PXL);
			if (game->map->map_matrix[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->empty->image, x * PXL, y * PXL);
		}
		mlx_put_image_to_window(game->mlx, game->window, game->player->image, \
		game->map->posc_p->posc_x * PXL, game->map->posc_p->posc_y * PXL);
	}
	printf("\e[1;1H\e[2J Move: %d\n", game->map->c_mv);
}
