/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:23:43 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/23 10:38:19 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf(INV_ARG));
		//como eu preciso retornar um inteiro(int), posso colocar para ele retornar o
		//printf, pois o printf retorna inteiro.
	game = ft_calloc(sizeof(t_game), 1);
	//aloco a memoria da minha struct game,para deste modo, conseguir ter os msms valores de variaveis
	//para todas as funcoes que eu chamar a struct game com o calloc, pois dps da malocacao, ele colocará 0 com a func bzero.
	game->map = ft_calloc(sizeof(t_map), 1);
	//tambem faco a alocacao de memoria, mas agora da minha struct map, como eu tenho uma variavel dentro do game
	//que chama a minha struct map, para eu nao precisar duas structs, posso interligá-las.
	game->map->map_matrix = reading_the_map(argv[1]);
	//aqui de fato começará o procedimento para aparecer na tela o meu jogo. esta primeira etapa será para
	//ler meu mapa, declaro uma variavel a partir da minha struct para receber e armazenar esta leitura do mapa. 
	if (game->map->map_matrix == NULL)
		kill_window(game);
	map_saved_dimensions(game->map);
	map_verification(game);
	init_struct(game);
	run(game);
	return (0);
}
