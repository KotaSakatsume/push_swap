# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#              #
#    Updated: 2025/03/18 15:47:51 by kosakats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/main.c \
       src/operations/stack_operations1.c \
       src/operations/stack_operations2.c \
       src/operations/stack_operations3.c \
	   src/sort/small_scale_sort.c \
	   src/sort/small_scale_sort_utils.c \
	   src/sort/big_scale_sort.c \
	   src/sort/big_scale_sort_utils.c \
	   src/node_make.c \
	   src/check.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -Ilibft -Ift_printf
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT_LIB = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
