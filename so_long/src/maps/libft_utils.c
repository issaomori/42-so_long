/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:03:00 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 15:45:18 by gissao-m         ###   ########.fr       */
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

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*put_zero;

	put_zero = str;
	while (n > 0)
	{
		*put_zero = 0;
		put_zero++;
		n--;
	}
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		count_size;
	int		i;

	count_size = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (count_size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}