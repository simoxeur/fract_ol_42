NAME	= fractol

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

UTILS_SRC = 	utils/ft_strncmp.c		utils/putstr_fd.c	utils/malloc_fail.c		utils/atoa_double.c 

SRCS		=	srcs/main.c	srcs/values_init.c	srcs/check_char.c	srcs/my_mlx_pixel_put.c\
				srcs/initialisation.c	srcs/rendering.c	srcs/math_utils.c 	 srcs/events.c \
				srcs/mandelbrot_set.c	srcs/julia_set.c	srcs/burning_ship.c	srcs/closing.c	\
				srcs/zoom.c		srcs/key_input.c		srcs/get_color.c

OBJS	=		${UTILS_SRC:.c=.o}	${SRCS:.c=.o}

all: $(NAME)

# on mac Os
# %.o:%.c srcs/fractol.h utils/utils.h
# 	$(CC) ${CFLAGS} -Imlx -c $< -o $@

# on linux
%.o:%.c srcs/fractol.h utils/utils.h
	$(CC) ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o $@

# on linux
$(NAME): 		${OBJS}
	$(CC) ${OBJS}  -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# on mac Os
# $(NAME): 		${OBJS}
# 	$(CC) ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: 	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean