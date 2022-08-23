/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:20 by gissao-m          #+#    #+#             */
/*   Updated: 2022/07/07 14:54:08 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putchar_int(int i)
{
	char	c;

	c = '0';
	c = c + i;
	write(1, &c, 1);
}

int	ft_putnbr(long int n)
{
	long int	i;
	int			length;

	i = 1;
	length = 1;
	if (n == -2147483648)
		return (ft_printf("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		length = length + 1;
	}
	while (i <= n / 10)
	{
		i = i * 10;
		length++;
	}
	while (i >= 1)
	{
		ft_putchar_int(n / i);
		n = n - (n / i) * i;
		i = i / 10;
	}
	return (length);
}

int	ft_putstr(char *s)
{	
	int	count_size;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	count_size = 0;
	while (s[count_size] != '\0')
	{
		write (1, &s[count_size], 1);
		count_size++;
	}
	return (count_size);
}
