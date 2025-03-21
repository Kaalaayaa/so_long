NAME = so_long.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft
SRC = so_long.c
OBJS := $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME) : makelibft $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -O3 -o $@ -c $<

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
