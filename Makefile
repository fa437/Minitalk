# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasare <fasare@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 19:47:26 by fasare            #+#    #+#              #
#    Updated: 2023/09/17 19:47:27 by fasare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Werror -Wextra

all: libft server client

libft:
	@make -C libft

server:	server.o
	@gcc $(CFLAGS) server.c libft/libft.a -o server

client: client.o
	@gcc $(CFLAGS) client.c libft/libft.a -o client

clean:
	@make fclean -C libft
	@rm -rf server.o
	@rm -rf client.o


fclean: clean
	@rm -rf server
	@rm -rf client

re: fclean all

libftprintf:
	@make -C libft

.PHONY: all clean fclean re libft

