# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 18:36:41 by rmander           #+#    #+#              #
#    Updated: 2021/02/01 22:59:28 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCLUDES_DIR = ./include
INCLUDES = ./include/libftprintf.h 
LIBFT_DIR = ./libft
LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)
SRCS = ./src/ft_parse_utils.c ./src/ft_printf_utils.c ./src/ft_put_utils.c \
	   ./src/ft_put_x.c ./src/ft_put_u.c ./src/ft_put_d.c ./src/ft_put_s.c \
	   ./src/ft_put_c.c ./src/ft_put_p.c ./src/ft_putnbr_base.c \
	   ./src/ft_parse.c ./src/ft_put.c ./src/ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) ./$@
	ar rcs $@ $(OBJS) 

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
