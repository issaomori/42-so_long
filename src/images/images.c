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


int refresh(t_game *game)
{
	//mlx_clear_window(game->mlx, game->window);
	where_are_sprites(game);
}

void render(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->height * 50, game->map->width * 50, "TITULO DO JOGO");
    open_image(game);
    where_are_sprites(game);
	mlx_hook(game->window, 17, 0L, kill_window, (void *)game);
	mlx_hook(game->window, 2, 1L << 0, keys_to_move, (void *)game);
	mlx_loop_hook(game->mlx, refresh, &game);
	mlx_loop(game->mlx);
}


void open_image(t_game *game)
{
    game->player->image = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &game->player->i, &game->player->j);
    game->collect->image = mlx_xpm_file_to_image(game->mlx, "./sprites/collect.xpm", &game->collect->i, &game->collect->j);
    game->empty->image = mlx_xpm_file_to_image(game->mlx, "./sprites/empty.xpm", &game->empty->i, &game->empty->j);
    game->enemy->image = mlx_xpm_file_to_image(game->mlx, "./sprites/enemy.xpm", &game->enemy->i, &game->enemy->j);
    game->exit->image = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &game->exit->i, &game->exit->j);
	game->wall->image = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->wall->i, &game->wall->j);
	//deste modo fará com que o i e j tenham valores diferentes.
}

int keys_to_move(int key_press, t_game *game)
{
	//preciso usar os botões w,a,s,d para andar.
	if(key_press == KEY_ESC)
		exit(0);
	if(key_press == KEY_UP)
		game->map->posc_p->posc_y--;
	if(key_press == KEY_DOWN)
		game->map->posc_p->posc_y++;
	if(key_press == KEY_LEFT)
		game->map->posc_p->posc_x--;
	if(key_press == KEY_RIGHT)
		game->map->posc_p->posc_x++;
	return(0);
	
}


void where_are_sprites(t_game *game)
{
	int x;
	//vai ser para o width.
	int y;
	//vai ser pro height.
	x = 0;
	y = 0;

	while(y < game->map->width)
	{
		x = 0;
		while (x < game->map->height)
		{
			// if (game->map->map_matrix[y][x] == 'P')
			//     mlx_put_image_to_window(game->mlx, game->window, game->player->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collect->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall->image, x * 50, y * 50);
			if (game->map->map_matrix[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->empty->image, x * 50, y * 50);
			x++;
		}
		y++;
	mlx_put_image_to_window(game->mlx, game->window, game->player->image, game->map->posc_p->posc_x * 50, game->map->posc_p->posc_y * 50);
	}
	printf("x:%d\n", game->map->posc_p->posc_x);
	printf("y:%d\n", game->map->posc_p->posc_y);
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
