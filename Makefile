# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilips <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 17:05:11 by gphilips          #+#    #+#              #
#    Updated: 2017/04/13 18:56:15 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC = init.c fractals.c draw.c event.c mouse_event.c create_win.c main.c
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft/
LIB = libft.a
LIBPATH = $(addprefix $(LIBDIR), $(LIB))
OBJ = $(SRC:.c=.o)

all: $(NAME)

.PHONY: all clean fclean re

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $@ $(OBJ) $(LIBPATH) $(MLX)
	@echo "$@ created"

clean:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from fractol"

fclean:
	@make fclean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from fractol"
	@rm -f $(NAME)
	@echo "Erasing $(NAME)"

re: fclean all
