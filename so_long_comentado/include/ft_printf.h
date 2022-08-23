/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:27:01 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/18 10:49:31 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		types_of_printf(const char *str, int count, va_list arg);
int		ft_putchar(char c);
int		ft_putnbr(long int n);
int		ft_putstr(char *s);
int		dcm_for_hxdcm(unsigned long long number, char id);
char	conversion_ascii(unsigned long int receptor, char id);
int		lenght_int(unsigned long int number);
#endif