/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:18:53 by gissao-m          #+#    #+#             */
/*   Updated: 2022/08/15 10:27:46 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

char	*ft_strchr(char *str, int found);
char	*ft_strjoin(char *dup_str, char *buffer);
char	*ft_return_line(char *print_str);
char	*ft_initial_position(char *next_str);
char	*get_next_line(int fd);
char	*ft_get_str(int fd, char *read_line_str);

#endif
