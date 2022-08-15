# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twakrim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 17:33:40 by twakrim           #+#    #+#              #
#    Updated: 2019/11/28 17:33:43 by twakrim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=src
LIBDIR=.
LIBDIRA=libft
HEADDIR=includes

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -L$(LIBDIRA) -lmlx -lft -framework OpenGL -framework AppKit

NAME=fractol

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/events.c\
	$(SRCDIR)/mouse.c\
	$(SRCDIR)/draw.c\
	$(SRCDIR)/fractals.c\
	$(SRCDIR)/mlx.c\

OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/events.o\
	$(LIBDIR)/mouse.o\
	$(LIBDIR)/draw.o\
	$(LIBDIR)/fractals.o\
	$(LIBDIR)/mlx.o\

all: $(NAME)

$(NAME) : $(OBJ)
	make re -C $(LIBDIR)/libft
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	make clean -C $(LIBDIR)/libft
	rm -rf $(LIBDIR)/*.o

fclean: clean
	make fclean -C $(LIBDIR)/libft
	rm -rf $(NAME)

re: fclean all