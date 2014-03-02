#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 15:51:24 by jmery             #+#    #+#              #
#    Updated: 2014/02/28 17:00:45 by cochin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

FLAG = -Wall -Wextra -Werror

SRCS = 	srcs/42sh.c \
		srcs/42sh_tools.c \
		srcs/42sh_fork.c \
		srcs/42sh_error.c \
		srcs/42sh_env.c \
		srcs/42sh_tabletools.c \
		srcs/42sh_cmdtools.c \
		srcs/ft_strsplit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	gcc $(FLAG) -o $(NAME) $(OBJS)

%.o:%.c
	gcc $(FLAG) -o $@ -c $< -I includes

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
