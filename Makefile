NAME = so_long
LIBFT = libft/libft.a
LIBFTDIR = ./libft
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c) # Get all .c files from src/
OBJS := $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -Ilibft -o $@ -c $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re