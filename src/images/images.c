#include "so_long.h"

// essa func void serve para fundir o endereço da imagem com os pixels.
// devemos entender que os meus bytes eles nao estao alinhados com a largura 
// real da janela. Para fazermos isso, deveremos calcular o deslocamento da
// memória usando o comprimento da linha que é definido pelo mlx_get_data_addr.
// void my_mlx_pixel_put(t_imagedata *data, int x, int y, int color)
// {
// 	char	*dest;
	
// 	dest = data->address + ( y * data->line_lenght + x * (data->bits_per_pixels / 8));
// 	*(unsigned int*)dest = color; 
// }

int kill_window(t_game *game)
{
	exit(0);
}



void render(t_imagedata *image, t_map *map, t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, map->width * 50, map->height * 50, "TITULO DO JOGO");
    open_image(image, game);
    where_are_sprites(map, image, game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_loop(game->mlx);
}


void open_image(t_imagedata *image, t_game *game)
{
    game->player->image = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &game->player->i, &game->player->j);
    game->collect->image = mlx_xpm_file_to_image(game->mlx, "./sprites/collect.xpm", &game->collect->i, &game->collect->j);
    game->empty->image = mlx_xpm_file_to_image(game->mlx, "./sprites/empty.xpm", &game->empty->i, &game->empty->j);
    game->enemy->image = mlx_xpm_file_to_image(game->mlx, "./sprites/enemy.xpm", &game->enemy->i, &game->enemy->j);
    game->exit->image = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &game->exit->i, &game->exit->j);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->wall->i, &game->wall->j);
	//deste modo fará com que o i e j tenham valores diferentes.

}


void where_are_sprites(t_map *map, t_imagedata *image, t_game *game)
{
	int x;
	//vai ser para o width.
	int y;
	//vai ser pro height.
	x = 0;
	y = 0;

	while(x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->map_matrix[x][y] == 'P')
			    mlx_put_image_to_window(game->mlx, game->window, game->player->image, x * 50, y * 50);
			if (map->map_matrix[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collect->image, x * 50, y * 50);
			if (map->map_matrix[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit->image, x * 50, y * 50);
			if (map->map_matrix[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall->image, x * 50, y * 50);
			if (map->map_matrix[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->empty->image, x * 50, y * 50);
			y++;
		}
		x++;
	}
}

// 	// image.address = mlx_get_data_addr(image.image, &image.bits_per_pixels, &image.line_lenght, &image.endian);
// //Se tentarmos representar uma imagem em tempo rela numa janela, alterá-la causará vários bugs de tela,
// //Então iremos criar duas ou mais imagens, assim gravaremos em uma imagem temporária para que nao seja
// //necessario gravar na imagem apresentada no momento.
// 	// my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);
// 	//o inteiro 0x00FF0000 representa ARGB(alphaRGB)(0,255,0,0) em hexadecimal.
// Imprima quadrados, círculos, triângulos e hexágonos na tela escrevendo os pixels de acordo.
// Tente adicionar gradientes, fazer arco-íris e se sentir confortável usando as cores rgb.
// Tente fazer texturas gerando a imagem em loops.
