# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 12:30:14 by seckhard          #+#    #+#              #
#    Updated: 2024/01/15 18:43:43 by seckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
SOURCES = \
					events.c init.c main.c math_utils.c \
					render.c string_utils.c

OBJECTS = $(SOURCES:.c=.o)

NAME = fractol

INCLUDE = -I fractol.h

CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm -Ofast -march=native

all: $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) $(INCLUDE) $?

clean:
			rm -f $(OBJECTS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re