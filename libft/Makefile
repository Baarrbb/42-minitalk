# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 17:32:46 by marvin            #+#    #+#              #
#    Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_DIR = ft_printf
OBJ_DIR = obj

PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/utils.c \
	$(PRINTF_DIR)/print_num.c

LIBFT_SRC = ft_strchr.c \
	ft_strlen.c \
	ft_atoi.c \
	ft_strlen.c

SRC = $(PRINTF_SRC) $(LIBFT_SRC)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
INC = -I./headers
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	
fclean : clean
	$(RM) $(NAME)
	
re : fclean all