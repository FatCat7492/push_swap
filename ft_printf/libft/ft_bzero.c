/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 09:23:55 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/06 20:55:34 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	temp = s;
	i = -1;
	while (++i < n)
		*temp++ = '\0';
}

// int	main(void)
// {
// 	char s1[] = "bonsoir";
// 	char s2[] = "bonsoir";
// 	int n = 3;
// 	printf("      str b4:%s\n", s1);
// 	ft_bzero(s1, n);
// 	printf("str ft_after:%s\n", s1 + 3);
// 	bzero(s2, n);
// 	printf("str rl_after:%s\n", s2 + 3);
// }
