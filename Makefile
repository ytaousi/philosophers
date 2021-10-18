# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:44:24 by ytaousi           #+#    #+#              #
#    Updated: 2021/10/18 16:46:09 by ytaousi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra -g

libft = libft/libft.a

SRCS = main.c parse.c init_philos.c utils.c ft_isdigit.c jobs.c ft_atoi.c ft_strncmp.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(SRCS)
	gcc $(CFLAGS) $(SRCS) -pthread -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJECTS)

re: fclean all