#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

char **parse_map(int map_fd, const char *filename);
int open_file(const char *filename);

#endif