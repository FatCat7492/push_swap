/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:11:20 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/06 14:24:13 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (i < len && hay[i] != '\0')
	{
		j = 0;
		while (needle[j] == hay[i + j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static void	t_strnstr(const char *hay, const char *needle, size_t len)
// {
// 	char	*expected;
// 	char	*actual;

// 	expected = strnstr(hay, needle, len);
// 	actual = ft_strnstr(hay, needle, len);

// 	if (expected == actual)
// 		printf(GREEN "[OK]" RESET " hay=\"%s\", needle=\"%s\", len=%zu\n",
// 			hay, needle, len);
// 	else if (expected && actual
// 		&& (actual - hay) == (expected - hay))
// 		printf(GREEN "[OK]" RESET " hay=\"%s\", needle=\"%s\", len=%zu\n",
// 			hay, needle, len);
// 	else
// 	{
// 		printf(RED "[KO]" RESET " hay=\"%s\", needle=\"%s\", len=%zu\n",
// 			hay, needle, len);
// 		printf("     expected: %s\n", expected ? expected : "NULL");
// 		printf("     actual:   %s\n", actual ? actual : "NULL");
// 	}
// }

// int	main(void)
// {
// 	t_strnstr("Hello World", "World", 11);
// 	t_strnstr("Hello World", "World", 5);
// 	t_strnstr("Hello World", "Hello", 5);
// 	t_strnstr("Hello World", "lo", 11);
// 	t_strnstr("Hello World", "lo", 4);
// 	t_strnstr("Hello World", "xyz", 11);
// 	t_strnstr("Hello World", "", 11);
// 	t_strnstr("", "", 0);
// 	t_strnstr("", "a", 10);
// 	t_strnstr("abcdef", "def", 6);
// 	t_strnstr("abcdef", "def", 5);
// 	t_strnstr("aaaaaa", "aaa", 6);
// 	t_strnstr("aaaaaa", "aaaa", 3);

// 	return (0);
// }

//not working anymore !!