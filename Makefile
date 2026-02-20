NAME = miniRT
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MLX_DIR = mlx
LIBFT_DIR = libft
INCLUDE_DIR	= includes
GNL_DIR = gnl
INCLUDES	= -I$(INCLUDE_DIR) \
			  -I$(MLX_DIR) \
			  -I$(LIBFT_DIR) \

SRC = main.c free_file.c utils.c init/init_file.c init/init_vecs.c\
	parse/parse_ambient_light.c parse/parse_light.c parse/parse_sphere.c\
	parse/parse_cylinder.c parse/parse_camera.c parse/parse_plane.c\
	error_file.c append.c parse/parse1.c start.c move/ask.c move/move1.c\
	move/move2.c move/move3.c resize/resize.c math/base_change.c math/cross_product.c\

OBJ_DIR = objs

OBJS = $(SRC:.c=.o)
OBJECTS	= $(addprefix $(OBJ_DIR)/, $(OBJS))

OBJS_BONUS = $(SRC_BONUS:.c=.o)

MLXFLAGS = -Lmlx -lmlx -lX11 -lXext -lm -lbsd -lft -Llibft

MLX = mlx/libmlx.a
LIBFT = libft/libft.a

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MLXFLAGS) $(INCLUDES)

$(NAME): $(MLX) $(LIBFT) $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) $(INCLUDES) -o $@ 

$(MLX):
	$(MAKE) -C mlx
	$(MAKE) -C libft

all: $(NAME) 

$(NAME_BONUS): $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) -o $@

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJECTS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) clean -C mlx
	$(MAKE) fclean -C libft

re: fclean all
