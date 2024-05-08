# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:19:47 by marvin            #+#    #+#              #
#    Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj

SRC_CLI = $(SRC_DIR)/client.c
SRC_SRV = $(SRC_DIR)/server.c

SRC_CLIB = $(SRC_DIR)/client_bonus.c
SRC_SRVB = $(SRC_DIR)/server_bonus.c

LIBFT = libft/libft.a
INC = -I./headers
CC = cc
CFLAGS = -Wall -Wextra #-Werror
RM = rm -rf

NAME = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all : $(NAME) $(CLIENT)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SRV) $(LIBFT) $(INC) -o $(NAME)

$(CLIENT) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLI) $(LIBFT) $(INC) -o $(CLIENT)

$(SERVER_BONUS) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SRVB) $(LIBFT) $(INC) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIB) $(LIBFT) $(INC) -o $(CLIENT_BONUS)

$(LIBFT) :
	make -C libft all

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	$(RM) $(NAME) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)
