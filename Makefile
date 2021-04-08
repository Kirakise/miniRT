SRCS = $(wildcard src/*.c) $(wildcard src/math/*.c) $(wildcard src/parcer/*.c) $(wildcard src/utils/*.c) $(wildcard src/constructors/*.c) $(wildcard src/mlx/*.c) $(wildcard src/controls/*.c)
OBJS = $(SRCS:%.c=%.o)
LIB = libmlx.a
NAME = miniRT
CC = clang

all: $(LIB) $(NAME)

libmlx.a:
	cd minilibx && make
	cp minilibx/libmlx.a ./

linux: $(OBJS)
	$(CC) -g -lmlx  -lX11 -lXext $^ linux.a -o $(NAME) -lm
$(NAME): $(OBJS)
	$(CC) -g libmlx.a -framework OpenGL -framework AppKit $^ -o $(NAME)
%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -c $^ -o $@
clean:
	rm -f $(OBJS)
	rm -f $(LIB)
fclean: clean
	rm -f miniRT
	cd minilibx && make clean
re: fclean all
