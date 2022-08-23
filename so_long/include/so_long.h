/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:06 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/23 12:53:57 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

//KEYBOARD:
# define KEY_UP 0x77
# define KEY_DOWN 0x73
# define KEY_RIGHT 0x64
# define KEY_LEFT 0x61
# define KEY_ESC 0xff1b

//SIZE IMAGES:
# define PXL 62

//NAME IMAGES:
# define PLAYER "./assets/comet.xpm"
# define COLLECT "./assets/planet.xpm"
# define EMPTY "./assets/galaxy.xpm"
# define EXIT "./assets/blackhole.xpm"
# define WALL "./assets/smoke.xpm"

//ERRORS WARNINGS:
# define INV_ARG "Error\nThe argument is invalid.\n"
# define EPT_LNE "Error\nLine empty in the map.\n"
# define NOT_RECT "Error\nMap is not Rectangular\n"
# define WALL_GAP "Error\nThe Wall has a gap.\n"
# define ONE_PLAY "Error\nThe map need only one player.\n"
# define ONE_COL "Error\nThe map needs at least one collect.\n"
# define ONE_EXT "Error\nThe map need at least one exit.\n"
# define INV_CHR "Error\nInvalid Character.\n"
# define CLEAN "This Maps is clean.\n"

//TITLE GAME:
# define TITLE "./so_long"

//STRUCTS:
typedef struct s_posc_player
{
	int		posc_x;
	int		posc_y;
}	t_pp;

typedef struct s_imagedata
{
	void	*image;
	int		i;
	int		j;
}	t_imagedata;

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
	void			*mlx;
	void			*window;
	t_imagedata		*player;
	t_imagedata		*collect;
	t_imagedata		*exit;
	t_imagedata		*empty;
	t_imagedata		*wall;
	t_map			*map;
	float			reset;
}	t_game;

//Functions in run:
void	run(t_game *game);
char	**reading_the_map(char *pass_arg);
void	init_struct(t_game *game);
char	**clean_map(t_map *maps);
int		checking_map_file(char *pass_arg);

//Functions in maps/libft_utils.c:
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t number, size_t size);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);

//Functions in maps/maps_characters.c:
void	init_vars(t_map *map);
void	valid_characters(t_game *game);
void	checking_characters(t_game *game);
int		invalid_characters(t_game *game);

//Functions in maps/maps_utils.c:
char	**ft_split(char const *s, char c);

//Functions in maps/maps.c:
void	map_saved_dimensions(t_map *dimensions);
void	is_rectangular(t_game *game);
void	verifying_wall(t_game *game);
void	map_verification(t_game *game);

//Functions in images/clean_images.c:
void	free_matrix(char **matrix);
int		kill_window(t_game *game);
void	free_protect(t_game *game);
int		refresh(t_game *game);

//Functions in images/images.c:
void	open_image(t_game *game);
void	colisions(t_game *game, int p_ty, int p_tx);
int		keys_to_move(int key_press, t_game *game);
void	put_image(t_game *game, t_imagedata *image, int x, int y);
void	render(t_game *game);
#endif