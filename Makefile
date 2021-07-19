NAME = FdF.out
CC = gcc
OBJ = driver.o ft_error.o ft_initialize.o ft_parse_map.o \
ft_test_utils.o ft_get_next_line.o ft_get_next_line_utils.o \
ft_utils.o ft_display.o ft_colors.o ft_hooks.o ft_view_port.o \
ft_draw_shapes.o
CFLAGS = -Wall -Wextra -Werror
LIBNAME = libFdF.a
MLX_DIR_NAME = mlx
FdFLibPath = /Users/edavid/Desktop/Repo/MyProjects/fdf/42-FdF/libFdF.a

$(NAME): $(OBJ)
	cd $(MLX_DIR_NAME) && $(MAKE) re
	cp ./$(MLX_DIR_NAME)/libmlx.a .
	mv libmlx.a $(LIBNAME)
	cd libft && $(MAKE) re
	cp ./libft/libft.a .
	ar -x libft.a
	ar -rs $(LIBNAME) *.o
	rm -f libft.a *.o
	$(CC) -lm -lz -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FdFLibPath)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
ft_get_next_line.o:
	$(CC) -g $(CFLAGS) -c gnl/ft_get_next_line.c
ft_get_next_line_utils.o:
	$(CC) -g $(CFLAGS) -c gnl/ft_get_next_line_utils.c
.PHONY: all clean fclean re bonus
clean:
	cd $(MLX_DIR_NAME) && rm -f *.o $(NAME)
	rm -f *.o $(NAME)
	cd libft && rm -f *.o $(NAME) 
re:
	make clean
	make all
all: $(NAME)
fclean: clean
	rm -f *.a
	cd libft && rm -f *.a
	cd $(MLX_DIR_NAME) && rm -f *.a
bonus: clean
bonus: CFLAGS += $(BFLAG)
bonus: test
bonus: all
