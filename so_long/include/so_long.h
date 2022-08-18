/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:06 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 14:13:13 by gissao-m         ###   ########.fr       */
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
# include "ft_printf.h"

typedef struct s_posc_player
{
	int		posc_x;
	int		posc_y;
}	t_pp;

//KEYBOARD:
# define KEY_UP 0x77
# define KEY_DOWN 0x73
# define KEY_RIGHT 0x64
# define KEY_LEFT 0x61
# define KEY_ESC 0xff1b

//SIZE IMAGES:
# define PXL 62

//NAME IMAGES:
# define PLAYER "./sprites/cometa.xpm"
# define COLLECT "./sprites/planeta2.xpm"
# define EMPTY "./sprites/galaxia1.xpm"
# define EXIT "./sprites/buraconegro.xpm"
# define WALL "./sprites/fumaca3.xpm"

//ERRORS WARNINGS:
# define INV_ARG "Error\nThe argument is invalid.\n"
# define EPT_LNE "Error\nLine empty in the map.\n"
# define NOT_RECT "Error\nMap is not Rectangular\n"
# define WALL_GAP "Error\nThe Wall has a gap."
# define ONE_PLAY "Error\nThe map need only one player.\n"
# define ONE_COL "Error\nThe map needs at least one collect.\n"
# define ONE_EXT "Error\nThe map need at least one exit.\n"
# define INV_CHR "Error\nInvalid Character\n"
# define CLEAN "This Maps is clean"

//TITLE GAME:
# define TITLE "./so_long"

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
	int		c_mv;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_imagedata		*player;
	t_imagedata		*collect;
	t_imagedata		*exit;
	t_imagedata		*empty;
	t_imagedata		*wall;
	t_map			*map;
	float			reset;
	
}	t_game;

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
void	ft_bzero(void *str, size_t n);
char	**reading_the_map(char *pass_arg);
void	is_rectangular(t_game *game);
void	verifying_wall(t_game *game);
void	map_saved_dimensions(t_map *dimensions);
int		ft_strlen(char *str);
int		invalid_characters(t_game *game);
void	valid_characters(t_game *game);
void	ft_bzero(void *str, size_t n);
void	if_there_is_no(t_game *game);
void	map_verification(t_game *game);
void	render(t_game *game);
void	open_image(t_game *game);
void	where_are_sprites(t_game *game);
void	init_struct(t_game *game);
int		keys_to_move(int key_press, t_game *game);
void	init_vars(t_map *map);
int		kill_window(t_game *game);
void	free_protect(t_game *game);
void	*ft_calloc(size_t number, size_t size);
#endif