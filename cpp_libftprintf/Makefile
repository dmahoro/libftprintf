# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 23:00:48 by dmahoro-          #+#    #+#              #
#    Updated: 2021/05/06 00:55:35 by dmahoro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= g++
NAME		= libftprintfCPP.a
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -g3

LIBFT		= libftCPP.a
SRCS_DIR	= srcs
INCLS_DIR	= includes
BUILD_DIR	= build
INCLS_FLS	= ft_printf.h
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
INCLS		= $(addprefix $(INCLS_DIR)/, $(INCLS_FLS))


$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $@ $^

$(OBJS):
	$(CC) $(DEBUG) $(CFLAGS) -c $(patsubst $(BUILD_DIR)/%.o, $(SRCS_DIR)/%.c \
		, $@) -o $@ -I$(INCLS_DIR)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fcean re
