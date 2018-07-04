# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zyuan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 19:48:50 by zyuan             #+#    #+#              #
#    Updated: 2018/06/28 20:03:52 by zyuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#src / obj files
SRC = main.c \
      read.c \
	  set_up_image.c \
	  draw_line.c \
	  matrices.c \
	  key_functions.c \
	  render_image.c \
	  init_matrices.c \
	  change_altitude.c \
	  error_and_free.c \

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC  = gcc
CFLAGS  = -Wall -Wextra -g3

# mlx library
MLX  = ./minilibx/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC = -I ./minilibx
MLX_LNK = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

# ft library
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

#directories
SRCDIR  = ./src/
INCDIR  = ./includes/
OBJDIR  = ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
