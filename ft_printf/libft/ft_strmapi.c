/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:35:19 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/09 15:26:23 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// static char	fonction(unsigned int i, char s)
// {
// 	printf("index:[%u] - char :[%c] \n", i, s);
// 	if (s >= 'a' && s <= 'z')
// 		s -= 32;
// 	else if (s >= 'A' && s <= 'Z')
// 		s += 32;
// 	return (s);
// }

// int	main(void)
// {
// 	char	s[] = "42SCHOOL";

// 	printf("before : %s\n", s);
// 	char *res = ft_strmapi(s, fonction);
// 	printf ("   res : %s\n", res);
// }
