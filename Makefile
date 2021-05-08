# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 05:54:14 by ljerrica          #+#    #+#              #
#    Updated: 2020/06/25 05:54:30 by ljerrica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = libftprintf.h

SRCS =	ft_atoi.c 				ft_ctoa.c 				ft_hex.c\
		ft_itoa.c 				ft_printf.c 			ft_putchar_fd.c\
		ft_putnbr_fd.c 			ft_putstr_fd.c 			ft_strlen.c\
		ft_utoi.c 				isprepros.c 			istype.c\
		ft_strdup.c 			prepros.c 				last_check.c\
		flags.c 				final.c 				ft_lutoa.c\
		str_null.c

OBJS = $(SRCS:.c=.o)

all: $(SRCS) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.c.o:
	@gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
