#include "../include/so_long.h"

int is_rectangular(char **map, int rows)
{
    int i;
    size_t first_row_length;

    if (rows == 0)  // Edge case: no rows
        return (0);

    first_row_length = ft_strlen(map[0]);

    i = 0;
    while (i < rows)
    {
        if (ft_strlen(map[i]) != first_row_length) // Compare each row's length to the first row's length
        {
            printf("Row %d is not the same length. Expected: %zu, Got: %zu\n", i, first_row_length, ft_strlen(map[i]));
            return 0;
        }
        i++;
    }
    return (1);
}


int is_enclosed_walls(char **map, int rows, int cols)
{
    char *first_row = map[0];
    char *last_row = map[rows - 1];
    int i = 0;
    int j = 1;

    if (rows < 2 || cols < 2)// check map is at least a 2x2 dimension
        return 0;

    while(i < cols)
    {
        if(first_row[i] != '1' || last_row[i]!= '1')
        {
            return (0);
        }
        i++;
    }

    while(j < rows - 1)
    {
        if(map[j][0] != '1' || map[j][cols -1] != '1')
        {
            return (0);
        }
        j++;
    }
    return (1);
}

int is_valid_characters(char **map, int rows, int cols)
{
    int i;
    int j;

    i = 0;
    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return 1;
}

int has_valid_elements(char **map, int rows, int cols)
{
    int i;
    int j;
    int player;
    int exit;
    int collectibles;

    i = 0;
    player = 0;
    collectibles = 0;
    exit = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if(map[i][j] == 'P')
                player++;
            if(map[i][j] == 'E')
                exit++;
            if(map[i][j] == 'C')
                collectibles++;
            j++;
        }
        i++;
    }
    if (player == 1 && exit == 1 && collectibles > 0)
        return (1);
    else
        return (0);
}

int is_path_valid(char **map, int rows)
{
    char **copy;

    copy = duplicate_map(map, rows);
    if (!copy)
    {
        printf("Failed to copy map.\n");
        return 0;
    }

    int px, py;
    if (find_player(copy, &px, &py))
        printf("Player found at (%d, %d)\n", px, py);
    else
    {
        printf("Player not found\n");
        return 0;
    }

    flood_fill(copy, px, py);

    int i = 0;
    int j;
    while (i < rows)
    {
        j = 0;
        while (copy[i][j])
        {
            if (copy[i][j] == 'E' || copy[i][j] == 'C')
            {
                free_map(copy);
                return (0);
            }
            j++;
        }
        i++;
    }
    free_map(copy);
    return 1;
}


int validate_map(t_game *game)
{
    //printf("VALIDATING MAP...\n");
    if (game->rows == 0 || game->cols == 0)
    {
        perror("Map is empty");
        return (0);
    }
    if (!is_rectangular(game->map, game->rows)) {
        perror("Map is not rectangular");
        return (0);
    }
    if (!is_enclosed_walls(game->map, game->rows, game->cols))
    {
        perror("Map is not fully enclosed by walls");
        return (0);
    }
    if(!is_valid_characters(game->map, game->rows, game->cols))
    {
        perror("Map contains invalid characters");
        return (0);
    }
    if(!has_valid_elements(game->map, game->rows, game->cols))
    {
        perror("Map doesnt contains all the necessary valid elements");
        return (0);
    }
    if(!is_path_valid(game->map, game->rows))
    {
        perror("Map path isnt valid!");
        return (0);
    }
    return 1;
}
