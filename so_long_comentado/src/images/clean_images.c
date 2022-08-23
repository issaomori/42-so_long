/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:49:39 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 15:35:46 by gissao-m         ###   ########.fr       */
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
	if (game->mlx && game->collect->image != 0)
		mlx_destroy_image(game->mlx, game->collect->image);
	if (game->mlx && game->player->image != 0)
		mlx_destroy_image(game->mlx, game->player->image);
	if (game->mlx && game->wall->image != 0)
		mlx_destroy_image(game->mlx, game->wall->image);
	if (game->mlx && game->exit->image != 0)
		mlx_destroy_image(game->mlx, game->exit->image);
	if (game->mlx && game->empty->image != 0)
		mlx_destroy_image(game->mlx, game->empty->image);
	if (game->mlx && game->window != 0)
		mlx_clear_window(game->mlx, game->window);
	if (game->mlx && game->window != 0)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != 0)
		mlx_destroy_display(game->mlx);
	if (game->mlx != 0)
		mlx_loop_end(game->mlx);
	free_protect(game);
	exit(0);
}

void	free_protect(t_game *game)
{
	if (game->mlx != 0)
		free (game->mlx);
	if (game->player != 0)
		free (game->player);
	if (game->collect != 0)
		free (game->collect);
	if (game->exit != 0)
		free (game->exit);
	if (game->empty != 0)
		free (game->empty);
	if (game->wall != 0)
		free (game->wall);
	if (game->map->posc_p != 0)
		free (game->map->posc_p);
	if (game->map->map_matrix != 0)
		free_matrix (game->map->map_matrix);
	if (game->map != 0)
		free (game->map);
	if (game != 0)
		free (game);
}

int	refresh(t_game *game)
{
	if (game->reset < 20)
		game->reset += 0.0001;
	else
	{
		mlx_clear_window(game->mlx, game->window);
		game->reset = 0;
	}
	render(game);
	return (0);
}
