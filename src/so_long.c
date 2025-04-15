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

   // Display original map
   /*printf("Initial map:\n");
   print_map(&game);
   
   printf("\n➡️ Move right\n");
   move_player(&game, 1, 0);
   print_map(&game);
   
   printf("\n⬅️ Move left\n");
   move_player(&game, -1, 0);
   print_map(&game);
   
   printf("\n⬆️ Move up\n");
   move_player(&game, 0, -1);
   print_map(&game);
   
   printf("\n⬇️ Move down\n");
   move_player(&game, 0, 1);  // This one should be denied
   print_map(&game);
       
       // Simulate moving to the exit if all collectibles are collected
       if (game.collected == game.total_collectibles)
       {
           printf("You have collected all items, moving to exit...\n");
           move_player(&game, 1, 0); // Try moving towards exit (or any other direction)
       }
   
       printf("Map is valid!!");*/


// }
#include "../include/so_long.h"

void print_map(t_game *game)
{
    for (int i = 0; i < game->rows; i++)
    printf("%s\n", game->map[i]);
    printf("\n");
}

//int main(int argc, char **argv)
//{


//     t_game game;

//     game.rows = 0;
//     game.cols = 0;
//     game.map = NULL;

//     int map_fd;
    
// 	if (argc != 2)
//     {
//         printf("Usage: ./so_long <map_file>\n");
//         return (1);
//     }
// 	map_fd = open_file(argv[1]);

//     if (!parse_map(&game, map_fd, argv[1]))
//     {
//         perror("Map parsing failed");
//         return (-1);
//     }
//     if(!validate_map(&game))
//     {
//         perror("Map is not valid");
//         return(-1);
//     }

//     // Initialize the game state

//     init_game(&game);
//     printf("HELLOOO\n");
//     game.mlx = mlx_init();
//     if (!game.mlx)
// {
//     perror("mlx_init failed\n");
//     return (1);
// }
//     printf("HELLOOO111\n");
//     game.mlx_win = mlx_new_window(game.mlx, game.cols * TILE_SIZE, game.rows * TILE_SIZE, "Hello world!");
//     printf("HELLOOO222\n");
//     load_images(&game);
//     if (!game.img_wall || !game.img_floor || !game.img_player ||
//         !game.img_collectibles || !game.img_exit)
//     {
//         printf("❌ Error: One or more images failed to load.\n");
//         exit(1);
//     }
//     mlx_put_image_to_window(game.mlx, game.mlx_win, game.img_wall, 0, 0);
//     render_map(&game);

//     //mlx_key_hook();
//     mlx_loop(game.mlx);

//     free_map(game.map);
// 	close(map_fd);
// 	return (0);
//}

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	// Initialize mlx and create a window
	mlx = mlx_init();
	if (!mlx) {
		printf("mlx_init failed\n");
		return 1;
	}

	mlx_win = mlx_new_window(mlx, 1920, 1080, "MLX Test Window");
	if (!mlx_win) {
		printf("mlx_new_window failed\n");
		return 1;
	}

	// Create a new image with a check to make sure it was created successfully
	img.img = mlx_new_image(mlx, 1920, 1080);
	if (!img.img) {
		printf("Error: Failed to create image\n");
		return (1);  // Exit if image creation fails
	}

	// Get the image data (address where we can manipulate pixels)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr) {
		printf("Error: Failed to get image data address\n");
		return (1);  // Exit if image data is not retrievable
	}

	// Fill the entire image with a solid color (let's try red)
	for (int y = 0; y < 1080; y++) {
		for (int x = 0; x < 1920; x++) {
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);  // Red color
		}
	}

	// Put the image into the window at position (0, 0)
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	// Enter the mlx loop to keep the window open
	mlx_loop(mlx);

	// This code won't be reached because mlx_loop runs indefinitely
	return (0);
}
