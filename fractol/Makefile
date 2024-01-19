# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 12:30:14 by seckhard          #+#    #+#              #
#    Updated: 2024/01/19 21:39:08 by seckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
SOURCES = \
					events.c init.c main.c math_utils.c \
					render.c string_utils.c

OBJECTS = $(SOURCES:.c=.o)

NAME = fractol

INCLUDE = -I fractol.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native
LIBS = -lmlx -lX11 -lXext

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBS) $(CFLAGS)

all: $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
			rm -f $(OBJECTS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re