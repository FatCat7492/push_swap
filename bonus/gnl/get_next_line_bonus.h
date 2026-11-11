/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:45:48 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/19 11:50:03 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef CSTOP
#  define CSTOP '\n'
# endif

char	*get_next_line(int fd);
char	*read_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*free_gnl(char *stash, char *buffer);
char	*stralloc(char *buffer, char *stash);
size_t	checker(char *s);
size_t	ft_strlen(char *s);

#endif