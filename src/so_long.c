// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);


// }
#include "../so_long.h"

// int open_file(const char *filename)
// {
//     int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if(fd == -1)
// 	{
// 		perror("Error when opening map file");
// 		return(-1);
// 	}
// 	return(fd);
// }

// int *get_map_size(int map)
// {
// 	int	*size;
// 	char *line;
// 	int rows = 0;
// 	int cols = 0;

// 	size = malloc(2 * sizeof(int)); // [rows, cols]
// 	if(!size)
// 		return(NULL);
	
// 	while (1)
// 	{
// 		line = get_next_line(map);
// 		if(line == NULL)
// 			break;
// 		rows++;
// 		cols = ft_strlen(line);
// 		//printf("[%d]: %s\n", rows, line);
//         free(line);
// 	}
// 	size[0] = rows; // rows
// 	size[1] = cols; // cols

// 	return (size);
// }

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

int main(int argc, char **argv)
{
	if (argc != 2)
    {
        printf("Usage: ./so_long <map_file>\n");
        return (1);
    }
	int map_fd = open_file(argv[1]);
	//printf("fd map: %d\n", map);
	//int *size = get_map_size(map);
	//int map_array[size[0]][size[1]];
	char **parsed_map = parse_map(map_fd);
	//free(size);
	//printf("size row:%d, col:%d", size[0], size[1]);
	int i = 0;
	while (parsed_map[i]) // Iterate through rows
	{
    	printf("%s\n", parsed_map[i]); // Print the whole row
		free(parsed_map);
    	i++;
	}
	close(map_fd);
	return (0);
}