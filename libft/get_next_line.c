/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:56:35 by kchatela          #+#    #+#             */
/*   Updated: 2025/03/21 18:16:51 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Concatenates static_buffer and read_buffer, frees the old static_buffer
char	*append_buffer(char *static_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(static_buffer, read_buffer);
	free(static_buffer);
	return (temp);
}

// read until it encounters a newline or reaches the end of the file
static char	*read_from_file(char *static_buffer, int fd)
{
	int			bytes_read;
	char		*read_buffer;

	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		static_buffer = append_buffer(static_buffer, read_buffer);
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (static_buffer);
}

//takes everything up to and including the first \n
char	*extract_line(char *static_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] && static_buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//keeps everything after the first \n
char	*obtain_remaining(char *static_buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(static_buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (static_buffer[i])
		line[j++] = static_buffer[i++];
	free(static_buffer);
	return (line);
}

//to get next line form the file descriptor
char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_buffer)
		static_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(static_buffer, '\n'))
		static_buffer = read_from_file(static_buffer, fd);
	if (!static_buffer)
		return (free(static_buffer), NULL);
	line = extract_line(static_buffer);
	static_buffer = obtain_remaining(static_buffer);
	return (line);
}
