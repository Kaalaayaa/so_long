#include "../include/so_long.h"

void load_images(t_game *game)
{
    int img_w;
    int img_h;

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "./assets/black.xpm", &img_w, &img_h);
    if(!game->img_floor)
        printf("FAILED TO LOAD IMAGE!!!");
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_w, &img_h);
    game->img_collectibles = mlx_xpm_file_to_image(game->mlx, "assets/pacdot_food.xpm", &img_w, &img_h);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/portal.xpm", &img_w, &img_h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/pac_open_right.xpm", &img_w, &img_h);
}

void render_map(t_game *game)
{
    int y = 0;
    int x;

    while(y < game->rows)
    {
        x = 0;
        while(x < game->cols)
        {
            char tile = game->map[y][x];
            if(tile == '0'|| tile == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
            if(tile == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}