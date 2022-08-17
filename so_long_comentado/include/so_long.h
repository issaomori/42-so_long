/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:06 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/16 09:29:37 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_posc_player
{
	int		posc_x;
	int		posc_y;
}	t_pp;


# define KEY_UP 0x77
# define KEY_DOWN 0x73
# define KEY_RIGHT 0x64
# define KEY_LEFT 0x61
# define KEY_ESC 0xff1b

typedef struct s_imagedata
{
	void	*image;
	char	*address;
	int		i;
	int		j;
    //i e j sao o tamanho da imagem.
}	t_imagedata;

//vamos fazer uma struct que servirá para colocarmos
//imagem na nossa janela. Para isso colocaremos
//pixeis e vamos precisar do endereço de memoria
//para alterarmos os bytes.

typedef struct s_map
{	
	int		checker_p;
	int		checker_c;
	int		checker_e;
	int		width;
	int		height;
	int		fd;
	char	*buffer;
	char	*readed_map;
	char	**map_matrix;
	t_pp	*posc_p;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_imagedata		*player;
	t_imagedata		*collect;
	t_imagedata		*exit;
	t_imagedata		*empty;
	t_imagedata		*enemy;
	t_imagedata		*wall;
	t_map			*map;
	
}	t_game;

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
void	ft_bzero(void *str, size_t n);
char	**reading_the_map(char *pass_arg);
void	is_rectangular(t_map *map);
void	verifying_wall(t_map *map);
void	map_saved_dimensions(t_map *dimensions);
int		ft_strlen(char *str);
int		invalid_characters(t_map *map);
void	valid_characters(t_map *map);
void	ft_bzero(void *str, size_t n);
void	if_there_is_no(t_map *map);
void	map_verification(t_map *map);
void	render(t_game *game);
void	open_image(t_game *game);
void	where_are_sprites(t_game *game);
void	init_struct(t_game *game);
int		keys_to_move(int key_press, t_game *game);

#endif