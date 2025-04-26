NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

UTILS_SRC = utils/ft_strncmp.c utils/putstr_fd.c utils/malloc_fail.c utils/atoa_double.c

SRCS = srcs/main.c srcs/values_init.c srcs/check_char.c srcs/my_mlx_pixel_put.c \
       srcs/initialisation.c srcs/rendering.c srcs/math_utils.c srcs/events.c \
       srcs/mandelbrot_set.c srcs/julia_set.c srcs/burning_ship.c srcs/closing.c \
       srcs/zoom.c srcs/key_input.c srcs/get_color.c

OBJS = ${UTILS_SRC:.c=.o} ${SRCS:.c=.o}

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(MLX_LIB) ${OBJS}
	@$(CC) ${OBJS} $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation finished!"

%.o:%.c srcs/fractol.h utils/utils.h
	@$(CC) ${CFLAGS} $(MLX_INC) -c $< -o $@

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "🧹 Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Executable removed."

re: fclean all

.PHONY: all clean fclean re