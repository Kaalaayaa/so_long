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
#include "so_long.h"
#include "./libft/libft.h"

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

int *get_map_size(int map)
{
	int	*size;

	size = malloc(2 * sizeof(int)); // [rows, cols]
	if(!size)
		return(NULL);
	
	size[0] = map; // rows
	size[1] = 0; // cols

	return (size);
}

int main()
{
	int map = open_file("./maps/map.ber");
	printf("fd map: %d\n", map);
	int *size = get_map_size(map);
	printf("size %d", size[1]);

	close(map);
	return (0);
}