// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "get_next_line.h"  // Include your get_next_line header

// // Function to open the file
// int open_file(const char *filename) {
//     int fd = open(filename, O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         exit(1);  // Exit if file can't be opened
//     }
//     return fd;
// }

// // Function to parse the map with a while loop
// void parse_map(const char *filename) {
//     int fd = open_file(filename);  // Open the map file
//     char *line;
//     int row = 0;
//     char **map = malloc(sizeof(char*) * 100);  // Allocate memory for 100 rows (adjust as needed)

//     // Use while loop to read lines until EOF
//     while ((line = get_next_line(fd)) != NULL) {
//         map[row] = malloc(strlen(line) + 1);  // Allocate memory for each line (including null terminator)
//         strcpy(map[row], line);  // Copy the line into the 2D array
//         free(line);  // Free the memory returned by get_next_line
//         row++;
//     }

//     close(fd);  // Close the file after reading

//     // Print the map to verify it was parsed correctly
//     for (int i = 0; i < row; i++) {
//         printf("%s\n", map[i]);
//     }

//     // Free the allocated memory for the map
//     for (int i = 0; i < row; i++) {
//         free(map[i]);
//     }
//     free(map);
// }

// int main() {
//     parse_map("map.ber");  // Replace with your map filename
//     return 0;
// }

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int open_file(const char *filename)
{
    int	fd;

	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("Error when opening map file");
		return(-1);
	}
	close(fd);
	return(fd);
}

int main()
{
	printf("file descriptor: %d", open_file("./maps/map.ber"));
	return (0);
}