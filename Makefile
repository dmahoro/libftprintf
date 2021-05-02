# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 23:00:48 by dmahoro-          #+#    #+#              #
#    Updated: 2021/04/18 17:11:48 by dmahoro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror

LIBFT		= libft/libft.a
SRCS_DIR	= srcs
INCLS_DIR	= includes
BUILD_DIR	= build
SRCS_FLS	= ft_printf.c \
		  ft_vdprintf.c \
		  pf_parse.c \
		  pf_parse_cs.c \
		  pf_parse_object_handler.c \
		  pf_parse_pdiux.c \
		  pf_parse_utils.c \
		  pf_print_utils.c \
		  pf_utils.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FLS))
_OBJS		= $(patsubst $(SRCS_DIR)/%.c, %.o, $(SRCS))
OBJS		= $(addprefix $(BUILD_DIR)/, $(_OBJS))
INCLS		= $(addprefix $(INCLS_DIR)/, ft_printf.h)


$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I./$(INCLS_DIR)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
