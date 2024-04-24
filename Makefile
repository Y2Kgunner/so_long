# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 18:39:30 by ykulkarn          #+#    #+#              #
#    Updated: 2024/04/25 01:30:20 by ykulkarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

MLX		=	mlx/libmlx.a

MLB		=	-Lmlx -lmlx -lXext -lX11

SRCS	=	./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/keybinds.c \
			./srcs/map_parse.c ./srcs/map_verif.c ./srcs/put_elements.c ./srcs/render.c \
			./srcs/so_long.c ./srcs/utils.c ./srcs/endgame.c ./srcs/errors.c

CC		=	gcc

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -Imlx

$(NAME)	:	$(OBJS)
			make -C ./mlx
			$(CC) $(CFLAGS) $(OBJS) $(MLB) -o $(NAME)

all		:	$(NAME)

clean	:
			make clean -C ./mlx
			$(RM) $(OBJS)

fclean:		clean
			make clean -C ./mlx
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
