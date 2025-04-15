#include "../include/so_long.h"

int open_file(const char *filename)
{
    int	fd;

	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("Error when opening map file");
		return(-1);
	}
	return(fd);
}

void remove_newline(char *line)
{
    size_t len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}

void free_map(char **map)
{
    int	i;

	i = 0;
	while (map[i])  // Iterate until NULL (if you NULL-terminated)
		{
			//printf("%s\n", map[i]);
			free(map[i]);
			i++;
		}
	free(map);

}

char **duplicate_map(char **map, int row)
{
    char **copy;
    int i;

    i = 0;
    copy = malloc((row + 1) * sizeof(char *));
    if(!copy)
    {
        return NULL;
    }
    while(i < row)
    {
        copy[i] = ft_strdup(map[i]);
        i++;
    }
    copy[row] = NULL;
    return (copy);
}

int find_player(char **map, int *x, int *y)
{
    int i = 0;
    int j;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

void flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;

    map[y][x] = 'V';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

