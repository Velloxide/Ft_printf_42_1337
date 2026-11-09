# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 16:44:58 by saboutay          #+#    #+#              #
#    Updated: 2026/11/07 20:09:54 by saboutay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/
AR = ar rcs
RM = rm -f
CC = cc

SRCS_M = src/mandatory/ft_printf.c\
	 src/mandatory/ft_format.c\
	 src/mandatory/print_char_str.c\
	 src/mandatory/print_hex.c\
	 src/mandatory/print_nbr.c

SRCS_B = src/bonus/ft_printf_bonus.c\
	 src/bonus/pad_bonus.c\
	 src/bonus/parse_bonus.c\
	 src/bonus/print_char_str_bonus.c\
	 src/bonus/print_hex_bonus.c\
	 src/bonus/print_nbr_bonus.c\
	 src/bonus/utils_bonus.c

OBJS_B = $(SRCS_B:.c=.o)
OBJS_M = $(SRCS_M:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
	HEADERS = includes/ft_printf_bonus.h
	OTHER_MODE = $(OBJS_M)
else
	OBJS = $(OBJS_M)
	HEADERS = includes/ft_printf.h
	OTHER_MODE = $(OBJS_B)
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)
	$(RM) $(OTHER_MODE)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(LIBFT_A):
	$(MAKE) -C libft
bonus:
	$(MAKE) WITH_BONUS=ON all
clean:
	$(RM) $(OBJS_M) $(OBJS_B)
	$(MAKE) -C libft clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
re: fclean all

.PHONY: all clean fclean re bonus
