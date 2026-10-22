/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:20:15 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/23 19:04:55 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	fonction(unsigned int i, char *s)
// {
// 	printf("index:[%u] - char :[%c] \n", i, *s);
// 	if (*s >= 'a' && *s <= 'z')
// 		*s -= 32;
// 	else if (*s >= 'A' && *s <= 'Z')
// 		*s += 32;
// }

// int	main(void)
// {
// 	char	s[] = "42school";

// 	printf ("before : %s\n", s);
// 	ft_striteri((void *)s, (void *)fonction);
// 	printf (" after : %s\n", s);
// }