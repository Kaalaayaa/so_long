#include "../so_long.h"

int *get_map_size(int map_fd)
{
	int	*size;
	char *line;
	int rows = 0;
	int cols = 0;

	size = malloc(2 * sizeof(int)); // [rows, cols]
	if(!size)
		return(NULL);
	
	while (1)
	{
		line = get_next_line(map_fd);
		if(line == NULL)
			break;
		rows++;
		cols = ft_strlen(line);
		//printf("[%d]: %s\n", rows, line);
        //if (line[cols - 1] == '\n') // Remove newline for correct column size
            //cols--;
        free(line);
	}
	size[0] = rows; // rows
	size[1] = cols; // cols

	return (size);
}

char **parse_map(int map_fd, const char *filename)
{
	int *size = get_map_size(map_fd);

	if (!size)
		return NULL;

    close(map_fd);
    map_fd = open_file(filename);
    if(map_fd == -1)
    {
        free(size);
        return(NULL);
    }
	char **map_array = malloc((size[0] + 1) * sizeof(char *)); // Allocate rows +1 for NULL
    if (!map_array)
    {
        free(size);
        return NULL;
    }

    int row = 0;

    while(row < size[0])
    {
        map_array[row] = malloc((size[1] + 1) * sizeof(char));
        if(!map_array[row])
        {
            while(--row >= 0)
            {
                free(map_array[row]);
            }
            free(map_array);
            free(size);
            return (NULL);
        }
        row++;
    }

	printf("size row:%d, col:%d\n", size[0], size[1]);
    free(size);
	return (map_array);
}