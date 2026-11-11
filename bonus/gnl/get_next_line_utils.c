/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:24:43 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/19 11:46:35 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	checker(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == CSTOP)
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*free_gnl(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

char	*stralloc(char *buffer, char *stash)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (!buffer)
		return (NULL);
	temp = malloc (ft_strlen(buffer) + ft_strlen(stash) + 1);
	if (temp == NULL)
		return (NULL);
	if (stash != NULL)
	{
		while (stash[i])
		{
			temp[i] = stash[i];
			i++;
		}
	}
	while (buffer[++j])
		temp[i + j] = buffer[j];
	temp[i + j] = '\0';
	free(stash);
	return (temp);
}
