#include "../so_long.h"

int *get_map_size(int map)
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
		line = get_next_line(map);
		if(line == NULL)
			break;
		rows++;
		cols = ft_strlen(line);
		//printf("[%d]: %s\n", rows, line);
        free(line);
	}
	size[0] = rows; // rows
	size[1] = cols; // cols

	return (size);
}

char **parse_map(int map_fd)
{
	int *size = get_map_size(map_fd);
	if (!size)
		return NULL;

	char **map_array = malloc(sizeof(char *) * (size[0] + 1)); // Allocate rows +1 for NULL
    if (!map_array)
    {
        free(size);
        return NULL;
    }

    int i = 0;
    while (i < size[0])
    {
        map_array[i] = malloc(sizeof(char) * (size[1] + 1)); // Allocate cols +1 for '\0'
        if (!map_array[i])
        {
            // Free previously allocated rows if allocation fails
            int j = 0;
            while (j < i)
            {
                free(map_array[j]);
                j++;
            }
            free(map_array);
            free(size);
            return NULL;
        }

        // Fill row with 'X' and add '\0'
        int j = 0;
        while (j < size[1] - 1)  // Fill all but last position
        {
            map_array[i][j] = 'X';
            j++;
        }
        map_array[i][j] = '\0'; // Null-terminate each row
        i++;
    }
	map_array[i] = NULL; // Null-terminate the array of pointers

	printf("size row:%d, col:%d\n", size[0], size[1]);
    free(size);
	return (map_array);
}