/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:03:00 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/17 17:17:35 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	count_size;

	count_size = 0;
	if (str == NULL)
		return (0);
	while (str[count_size])
		count_size++;
	return (count_size);
}

void	*ft_calloc(size_t number, size_t size)
{
	size_t	m_sizes;
	void	*receptor;

	if (number > 2147483647 || size > 2147483647)
		return (NULL);
	m_sizes = number * size;
	receptor = malloc(m_sizes);
	if (!receptor)
		return (0);
	ft_bzero(receptor, m_sizes);
	return (receptor);
}
