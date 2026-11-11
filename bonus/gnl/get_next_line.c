/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:05:10 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/19 17:38:33 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		stash[fd] = free_gnl(stash[fd], NULL);
		return (NULL);
	}
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

char	*read_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*new_str;
	char	*buffer;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (free_gnl(stash, buffer));
	while (!checker(stash))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_gnl(stash, buffer));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		new_str = stralloc(buffer, stash);
		if (!new_str)
			return (free_gnl(stash, buffer));
		stash = new_str;
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	j;
	size_t	i;
	char	*extract;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != CSTOP)
		i++;
	if (stash[i] == CSTOP)
		i++;
	extract = malloc (i + 1);
	if (!extract)
		return (NULL);
	while (j < i)
	{
		extract[j] = stash[j];
		j++;
	}
	extract[j] = '\0';
	return (extract);
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	j = ft_strlen(stash);
	while (stash[i] && stash[i] != CSTOP)
		i++;
	if (stash[i] == CSTOP)
		i++;
	if (!stash[i])
		return (free_gnl(stash, NULL));
	new_stash = malloc (j - i + 1);
	if (!new_stash)
		return (free_gnl(stash, NULL));
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
