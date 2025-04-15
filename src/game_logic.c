#include "../include/so_long.h"

void init_game(t_game *game)
{
    int i;
    int j;

    game->collected = 0;
    game->total_collectibles = 0;
    game->move_count = 0;

    if(!find_player(game->map, &game->player_x, &game->player_y))
    {
        perror("Player position not found");
        return;
    }

    i = 0;
    while(i < game->rows)
    {
        j = 0;
        while(j < game->cols)
        {
            if(game->map[i][j] == 'C')
                game->total_collectibles++;
            j++;
        }
        i++;
    }
    printf("Player starts at (%d, %d)\n", game->player_x, game->player_y);
    printf("Total collectibles: %d\n", game->total_collectibles);
}

void exit_game(t_game *game)
{
    free_map(game->map);
    exit(0);
}

int is_move_valid(t_game *game, int x, int y)
{
    if(x < 0 || x >= game->cols || y < 0 || y >= game->rows)
        return 0;
    if(game->map[y][x] == '1')
        return 0;

    return 1;
}

void move_player(t_game *game, int dir_x, int dir_y)
{
    int new_pos_x;
    int new_pos_y;

    new_pos_x = game->player_x + dir_x;
    new_pos_y = game->player_y + dir_y;

    //if (!is_move_valid(game, dir_x, dir_y))
    //    return;
    if (!is_move_valid(game, new_pos_x, new_pos_y))
    return;
    
    if (game->map[new_pos_y][new_pos_x] == 'C')
    {
        game->collected++;
        game->map[new_pos_y][new_pos_x] = '0';
    }

    if (game->map[new_pos_y][new_pos_x] == 'E')
    {
        if(game->collected == game->total_collectibles)
        {
            printf("You win! Total moves: %d\n", game->move_count + 1);
            exit_game(game);
        }
        else
        {
            printf("Collect all items first!\n");
            return;
        }
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_pos_y][new_pos_x] = 'P';
    game->player_x = new_pos_x;
    game->player_y = new_pos_y;
    game->move_count++;
    printf("Moved: %d steps\n", game->move_count);
}
