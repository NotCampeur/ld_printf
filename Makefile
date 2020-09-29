# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 12:51:12 by ldutriez          #+#    #+#              #
#    Updated: 2020/09/29 16:43:26 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_reset_flags.c \
converters/ft_addrtos.c converters/ft_basetos.c converters/ft_ctos.c \
converters/ft_itos.c converters/ft_stos.c converters/ft_utos.c \
converters/ft_atoi.c \
checker/ft_check.c checker/ft_isdigit.c \
checker/ft_strlen.c checker/ft_get_padding.c\
printer/ft_print_arg.c printer/ft_print_arg_addr.c \
printer/ft_print_left_padding.c printer/ft_print_right_padding.c \
printer/ft_print_precise.c printer/ft_print_zero.c printer/ft_print_arg_str.c

OBJ = $(SRC:.c=.o)

%.o : %.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
