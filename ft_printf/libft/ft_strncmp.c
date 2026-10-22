/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 10:34:48 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/09 14:18:47 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	ft_strncmp(const char *s1, const char *s2, size_t n);

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// void	test(const char *s1, const char *s2, size_t n)
// {
// 	int	expected;
// 	int	result;

// 	expected = strncmp(s1, s2, n);
// 	result = ft_strncmp(s1, s2, n);

// 	if ((expected < 0 && result < 0)
// 		|| (expected > 0 && result > 0)
// 		|| (expected == 0 && result == 0))
// 		printf(GREEN "✓ OK" RESET "  strncmp(\"%s\", \"%s\", %zu) -> %d\n",
// 			s1, s2, n, result);
// 	else
// 		printf(RED "✗ KO" RESET "  strncmp(\"%s\", \"%s\", %zu)\n"
// 			"       attendu : %d\n"
// 			"       obtenu  : %d\n",
// 			s1, s2, n, expected, result);
// }

// int	main(void)
// {
// 	printf("\n=== Tests ft_strncmp ===\n\n");

// 	test("abc", "abc", 3);
// 	test("abc", "abd", 3);
// 	test("abd", "abc", 3);
// 	test("abc", "abcd", 4);
// 	test("abcd", "abc", 4);
// 	test("abc", "abd", 2);
// 	test("", "", 5);
// 	test("", "abc", 3);
// 	test("abc", "", 3);
// 	test("hello", "hello world", 5);
// 	test("hello", "hello world", 10);
// 	test("Hello", "hello", 5);
// 	test("abc", "abd", 0);
// 	test("12345", "12346", 5);

// 	printf("\n========================\n\n");
// 	return (0);
// }
