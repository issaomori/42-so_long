/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:25:15 by gissao-m          #+#    #+#             */
/*   Updated: 2022/07/07 14:53:56 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenght_int(unsigned long int number)
{
	int	lenght;

	lenght = 1;
	while (number >= 16)
	{
		lenght++;
		number = number / 16;
	}
	return (lenght);
}

char	conversion_ascii(unsigned long int receptor, char id)
{
	if (receptor <= 9)
		return (receptor + 48);
	else if (id == 'l')
		return (receptor + 87);
	else if (id == 'U')
		return (receptor + 55);
	else if (id == 'p')
		return (receptor + 87);
	return (receptor);
}

int	dcm_for_hxdcm(unsigned long long number, char id)
{
	char				*str;
	int					lenght;
	unsigned long int	mod;

	lenght = lenght_int (number);
	if (id == 'p')
	{
		if (number == 0)
			return (ft_printf("(nil)") - 2);
		ft_printf("0x");
	}
	str = (char *) calloc(sizeof(char), (lenght + 1));
	if (number == 0)
		str[--lenght] = '0';
	while (number != 0)
	{
		mod = (number % 16);
		str[--lenght] = conversion_ascii(mod, id);
		number = number / 16;
	}
	lenght = ft_putstr(str);
	free(str);
	return (lenght);
}

int	types_of_printf(const char *str, int count, va_list arg)
{
	int	lenght;

	lenght = 0;
	if (str[count] == 'c')
		lenght = ft_putchar(va_arg(arg, int));
	if (str[count] == 's')
		lenght = ft_putstr(va_arg(arg, char *));
	if (str[count] == 'p')
		lenght = dcm_for_hxdcm(va_arg(arg, unsigned long long int), 'p') + 2;
	if (str[count] == 'd')
		lenght = ft_putnbr(va_arg(arg, int));
	if (str[count] == 'i')
		lenght = ft_putnbr(va_arg(arg, int));
	if (str[count] == 'u')
		lenght = ft_putnbr(va_arg(arg, unsigned int));
	if (str[count] == 'x')
		lenght = dcm_for_hxdcm(va_arg(arg, unsigned int), 'l');
	if (str[count] == 'X')
		lenght = dcm_for_hxdcm(va_arg(arg, unsigned int), 'U');
	if (str[count] == '%')
		lenght = ft_putchar('%');
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		count_size;
	int		total_lenght;

	total_lenght = 0;
	va_start(argptr, str);
	count_size = 0;
	while (str[count_size] != '\0')
	{
		if (str[count_size] == '%')
		{
			count_size++;
			total_lenght += types_of_printf(str, count_size, argptr);
		}
		else
			total_lenght += ft_putchar(str[count_size]);
		count_size++;
	}
	return (total_lenght);
}
