#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_game {
    char **map;
    int rows;
    int cols;
    int player_x;
    int player_y;
    int total_collectibles;
    int collected;
    int move_count;
    void *mlx;
    void *mlx_win;
    void *img_floor;
    void *img_wall;
    void *img_collectibles;
    void *img_exit;
    void *img_player;
    
} t_game;

int parse_map(t_game *game, int map_fd, const char *filename);
int validate_map(t_game *game);
int open_file(const char *filename);
void free_map(char **map);
char ** duplicate_map(char **map, int row);
int find_player(char **map, int *x, int *y);
void flood_fill(char **map, int x, int y);
void remove_newline(char *line);
void init_game(t_game *game);
void move_player(t_game *game, int dir_x, int dir_y);
void load_images(t_game *game);
void render_map(t_game *game);

#endif