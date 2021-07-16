NAME = FdF.out
CC = gcc
OBJ = driver.o ft_error.o ft_initialize.o ft_parse_map.o \
ft_utils.o ft_test_utils.o ft_get_next_line.o ft_get_next_line_utils.o
CFLAGS = -Wall -Wextra -Werror
LIBNAME = libFdF.a

$(NAME): $(OBJ)
	cd mlx_linux && $(MAKE) re
	cp ./mlx_linux/libmlx.a .
	mv libmlx.a $(LIBNAME)
	cd libft && $(MAKE) all
	cp ./libft/libft.a .
	ar -x libft.a
	ar -rs $(LIBNAME) *.o
	rm -f libft.a
	mv $(LIBNAME) libr/
	$(CC) -lz -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME) -Llibr -lFdF
	rm -f *.o
%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
ft_get_next_line.o:
	$(CC) -g $(CFLAGS) -c gnl/ft_get_next_line.c
ft_get_next_line_utils.o:
	$(CC) -g $(CFLAGS) -c gnl/ft_get_next_line_utils.c
.PHONY: all clean fclean re bonus
clean:
	cd mlx_linux && rm -f *.o $(NAME)
	rm -f *.o $(NAME)
	cd libft && rm -f *.o $(NAME) 
re:
	make clean
	make all
all: $(NAME)
fclean: clean
	rm -f *.a
	cd libft && rm -f *.a
	cd mlx_linux && rm -f *.a
bonus: clean
bonus: CFLAGS += $(BFLAG)
bonus: test
bonus: all
