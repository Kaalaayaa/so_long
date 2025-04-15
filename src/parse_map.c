#include "../include/so_long.h"

int get_map_size(int map_fd, t_game *game)
{
	char *line;
	int rows = 0;
	int cols = 0;
	
	while (1)
	{
		line = get_next_line(map_fd);
		if(line == NULL)
			break;
        remove_newline(line);
		rows++;
		cols = ft_strlen(line);

        free(line);
	}
	game->rows = rows;
	game->cols = cols;

	return (1);
}

int parse_map(t_game *game, int map_fd, const char *filename)
{
	if (!get_map_size(map_fd, game))
		return (0);

    close(map_fd);
    map_fd = open_file(filename);
    if(map_fd == -1)
    {
        return(0);
    }
	game->map = malloc((game->rows + 1) * sizeof(char *)); // Allocate rows +1 for NULL
    if (!game->map)
    {
        return (0);
    }

    int row = 0;

    while(row < game->rows)
    {
        game->map[row] = get_next_line(map_fd);
        if(!game->map[row])
        {
            while(--row >= 0)
            {
                free(game->map[row]);
            }
            free(game->map);
            return (0);
        }
        remove_newline(game->map[row]);
        row++;
    }
    game->map[row] = NULL;
	printf("size row:%d, col:%d\n", game->rows, game->cols);
	return (1);
}