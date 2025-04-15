NAME = so_long
LIBFT = libft/libft.a
LIBFTDIR = ./libft
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c) # Get all .c files from src/
OBJS := $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra

# MiniLibX
MLX_DIR = mlx # Path to your mlx folder
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)


#(NAME): $(OBJS) $(LIBFT)
#	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#%.o: %.c
#	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -Ilibft -o $@ -c $<

#MAC VERSIONls
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I$(LIBFTDIR) -I$(MLX_DIR) -o $@ -c $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re