/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:18:47 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/08 14:08:25 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	count_size;

	count_size = 0;
	if (str == NULL)
		return (0);
	while (str[count_size])
		count_size++;
	return (count_size);
}

char	*ft_strchr(char *str, int found)
{
	int	search;

	search = 0;
	if (!str)
		return (0);
	if (found == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[search])
	{
		if (str[search] == (char) found)
			return ((char *)&str[search]);
		search ++;
	}
	return (0);
}

char	*ft_strjoin(char *dup_str, char *buffer)
{
	char			*join;
	size_t			count_s1;
	size_t			count_s2;
	int				len_str;

	len_str = ft_strlen(dup_str);
	count_s1 = 0;
	count_s2 = 0;
	if (!dup_str)
	{
		dup_str = (char *)malloc(1 * sizeof(char));
		dup_str[0] = '\0';
	}
	join = malloc (sizeof(char) * (len_str + ft_strlen(buffer)) + 1);
	if (join == NULL)
		return (NULL);
	while (dup_str[count_s2] != '\0')
		join[count_s2++] = dup_str[count_s1++];
	count_s1 = 0;
	while (buffer[count_s1])
		join[count_s2++] = buffer[count_s1++];
	join[count_s2] = '\0';
	free(dup_str);
	return (join);
}

char	*ft_return_line(char *backup)
{
	int			count_size;
	char		*str;

	count_size = 0;
	if (!backup)
		return (NULL);
	while (backup[count_size] && backup[count_size] != '\n')
		count_size++;
	str = (char *) malloc (sizeof(char) * (count_size + 2));
	if (!str)
		return (NULL);
	count_size = 0;
	while (backup[count_size] && backup[count_size] != '\n')
	{
		str[count_size] = backup[count_size];
		count_size++;
	}
	if (backup[count_size] == '\n')
	{
		str[count_size] = backup[count_size];
		count_size++;
	}
	str[count_size] = '\0';
	return (str);
}

char	*ft_initial_position(char *next_str)
{
	int			count_1;
	int			count_2;
	char		*str;

	count_1 = 0;
	count_2 = 0;
	while (next_str[count_1] && next_str[count_1] != '\n')
		count_1++;
	if (next_str[count_1] == '\0')
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - count_1 + 1));
	if (!str)
		return (NULL);
	count_1++;
	while (next_str[count_1])
		str[count_2++] = next_str[count_1++];
	str[count_2] = '\0';
	free(next_str);
	return (str);
}
