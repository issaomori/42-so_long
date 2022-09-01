# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:09:18 by gissao-m          #+#    #+#              #
#    Updated: 2022/08/25 17:36:11 by gissao-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
INCLUDE = -I ./include/
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDE)
MLXFLAGS = -lmlx -Ilmlx -lXext -lX11


RM = rm -rf

PATH_SRC = ./src/
PATH_MAIN = $(PATH_SRC)main/
PATH_GNL = $(PATH_SRC)gnl/
PATH_MAPS = $(PATH_SRC)maps/
PATH_IMAGES = $(PATH_SRC)images/
PATH_PRINTF = $(PATH_SRC)printf/
PATH_OBJS = ./objs/

SRC =	$(PATH_MAIN)main.c\
		$(PATH_MAIN)run.c\
		$(PATH_MAPS)maps.c\
		$(PATH_MAPS)maps_utils.c\
		$(PATH_MAPS)libft_utils.c\
		$(PATH_MAPS)maps_characters.c\
		$(PATH_IMAGES)images.c\
		$(PATH_IMAGES)clean_images.c\
		$(PATH_GNL)get_next_line.c\
		$(PATH_GNL)get_next_line_utils.c\
		$(PATH_PRINTF)ft_printf.c\
		$(PATH_PRINTF)ft_printf_utils.c\


OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)gnl/
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)maps/
	@mkdir -p $(PATH_OBJS)images/
	@mkdir -p $(PATH_OBJS)printf/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(PATH_OBJS) clean fclean re