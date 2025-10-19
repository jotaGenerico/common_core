/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jota <jota@student.42sp.org.br>             +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:45:00 by jota              #+#    #+#             */
/*   Updated: 2025/07/27 22:00:00 by jota             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char *storage);
static char	*extract_line(char *storage);
static char	*save_remainder(char *storage);

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_until_newline(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		storage = ft_free(storage, NULL);
		return (NULL);
	}
	storage = save_remainder(storage);
	return (line);
}

static char	*save_remainder(char *storage)
{
	size_t	i;
	size_t	j;
	char	*new_storage;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (ft_free(storage, NULL));
	i++;
	new_storage = malloc(ft_strlen(storage + i) + 1);
	if (!new_storage)
		return (ft_free(storage, NULL));
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

static char	*extract_line(char *storage)
{
	size_t	i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_until_newline(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(storage, NULL));
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(storage, buffer));
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (ft_free(buffer, NULL));
	}
	free(buffer);
	return (storage);
}
