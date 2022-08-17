/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:00:42 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/16 15:40:13 by gissao-m         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx, game->collect->image);
	mlx_destroy_image(game->mlx, game->player->image);
	mlx_destroy_image(game->mlx, game->enemy->image);
	mlx_destroy_image(game->mlx, game->wall->image);
	mlx_destroy_image(game->mlx, game->exit->image);
	mlx_destroy_image(game->mlx, game->empty->image);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free (game->mlx);
	free (game->player);
	free (game->collect);
	free (game->exit);
	free (game->enemy);
	free (game->empty);
	free (game->wall);
	free (game->map->posc_p);
	free_matrix (game->map->map_matrix);
	free (game->map);
	free (game);
	exit(0);
}

void	render(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->height * 50, \
	game->map->width * 50, "TITULO DO JOGO");
	open_image(game);
	where_are_sprites(game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_hook(game->window, 2, 1L << 0, keys_to_move, (void *)game);
	mlx_loop(game->mlx);
}

void	open_image(t_game *game)
{
	game->player->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player.xpm", &game->player->i, &game->player->j);
	game->collect->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/collect.xpm", &game->collect->i, &game->collect->j);
	game->empty->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/empty.xpm", &game->empty->i, &game->empty->j);
	game->enemy->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/enemy.xpm", &game->enemy->i, &game->enemy->j);
	game->exit->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/exit.xpm", &game->exit->i, &game->exit->j);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/wall.xpm", &game->wall->i, &game->wall->j);
}

void	colisions(t_game *game, int p_ty, int p_tx)
{
	if(game->map->map_matrix[p_ty] && game->map->map_matrix[p_ty][p_tx] != '1')
	{
		if(game->map->map_matrix[p_ty][p_tx] == 'C')
			game->map->checker_c--;
		if(game->map->map_matrix[p_ty][p_tx] == 'E')
		{
			if(game->map->checker_c == 0)
				kill_window(game);
		}
		else
		{
			game->map->map_matrix[game->map->posc_p->posc_y][game->map->posc_p->posc_x] = '0';
			game->map->posc_p->posc_x = p_tx;
			game->map->posc_p->posc_y = p_ty;
		}
	}
}

int keys_to_move(int key_press, t_game *game)
{
	//fazer uma variavel para receber o valor da poscicao do player.
	int	p_tx;
	int	p_ty;

	p_tx = game->map->posc_p->posc_x;
	p_ty = game->map->posc_p->posc_y;
	//preciso usar os botões w,a,s,d para andar.
	if(key_press == KEY_ESC)
		exit(0);
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

	x = 0;
	y = 0;
	while (++y < game->map->width)
	{
		x = 0;
		while (++x < game->map->height)
		{
			if (game->map->map_matrix[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->collect->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->exit->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->wall->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->empty->image, x * 50, y * 50);
			// x++;
		}
		// y++;
	mlx_put_image_to_window(game->mlx, game->window, game->player->image, \
	game->map->posc_p->posc_x * 50, game->map->posc_p->posc_y * 50);
	}
}
