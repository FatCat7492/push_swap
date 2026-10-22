/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:43:58 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:34:22 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// void	test_strchr(const char *s, int c)
// {
// 	char	*expected;
// 	char	*result;

// 	expected = strchr(s, c);
// 	result = ft_strchr(s, c);

// 	if (result == expected || 
// 		(result != NULL && expected != NULL &&
// 		result - s == expected - s))
// 	{
// 		printf(GREEN "✓ PASS" RESET " | strchr(\"%s\", '%c')\n", s,
// 			c == '\0' ? '\\' : c);
// 	}
// 	else
// 	{
// 		printf(RED "✗ FAIL" RESET " | strchr(\"%s\", '%c')\n", s,
// 			c == '\0' ? '\\' : c);
// 		printf("    expected: %p\n", (void *)expected);
// 		printf("    got:      %p\n", (void *)result);
// 	}
// }

// int	main(void)
// {
// 	printf("\n=== ft_strchr tests ===\n\n");

// 	test_strchr("Hello World", 'H');
// 	test_strchr("Hello World", 'o');
// 	test_strchr("Hello World", 'W');
// 	test_strchr("Hello World", 'd');
// 	test_strchr("Hello World", 'x');
// 	test_strchr("", 'x');
// 	test_strchr("", '\0');
// 	test_strchr("Hello", '\0');
// 	test_strchr("aaaaa", 'a');
// 	test_strchr("42 School", '4');
// 	test_strchr("42 School", '2');

// 	printf("\n");
// 	return (0);
// }
