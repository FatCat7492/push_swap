/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:50:35 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/10 18:14:03 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	bytes = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (bytes[i] == (unsigned char)c)
			return ((void *)&bytes[i]);
		i++;
	}
	return (NULL);
}

// #include <stddef.h>

// void	*ft_memchr(const void *s, int c, size_t n);

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// void	test(const void *s, int c, size_t n)
// {
// 	void	*expected;
// 	void	*result;
// 	long	expected_pos;
// 	long	result_pos;

// 	expected = memchr(s, c, n);
// 	result = ft_memchr(s, c, n);

// 	if (expected == NULL)
// 		expected_pos = -1;
// 	else
// 		expected_pos = (const char *)expected - (const char *)s;

// 	if (result == NULL)
// 		result_pos = -1;
// 	else
// 		result_pos = (const char *)result - (const char *)s;

// 	if (expected_pos == result_pos)
// 		printf(GREEN "✓ OK" RESET
// 			"  memchr(\"%s\", '%c', %zu) -> position %ld\n",
// 			(const char *)s, c, n, result_pos);
// 	else
// 		printf(RED "✗ KO" RESET
// 			"  memchr(\"%s\", '%c', %zu)\n"
// 			"       attendu : position %ld\n"
// 			"       obtenu  : position %ld\n",
// 			(const char *)s, c, n, expected_pos, result_pos);
// }

// int	main(void)
// {
// 	printf("\n=== Tests ft_memchr ===\n\n");

// 	/* Basic tests */
// 	test("hello", 'h', 5);
// 	test("hello", 'e', 5);
// 	test("hello", 'l', 5);
// 	test("hello", 'o', 5);
// 	test("hello", 'x', 5);

// 	/* Character not found */
// 	test("abcdef", 'z', 6);

// 	/* n limits the search */
// 	test("abcdef", 'd', 2);
// 	test("abcdef", 'd', 4);
// 	test("abcdef", 'f', 5);
// 	test("abcdef", 'f', 6);

// 	/* n == 0 */
// 	test("hello", 'h', 0);

// 	/* Empty string */
// 	test("", 'a', 0);

// 	/* Character value outside unsigned char range */
// 	test("hello", 256 + 'h', 5);
// 	test("hello", -256 + 'h', 5);

// 	/* Repeated characters */
// 	test("aaaabaaa", 'b', 8);
// 	test("aaaabaaa", 'a', 8);

// 	/* Numbers as bytes */
// 	{
// 		unsigned char data[] = {0, 1, 2, 3, 4, 5, 0};

// 		test(data, 0, 7);
// 		test(data, 3, 7);
// 		test(data, 5, 7);
// 		test(data, 6, 7);
// 	}

// 	printf("\n========================\n\n");

// 	return (0);
// }
