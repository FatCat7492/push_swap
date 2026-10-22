/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 23:21:46 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/06 20:02:03 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (dstsize == 0)
		return (s_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	tests;
// static int	failed;

// static void	test_strlcpy(const char *name, const char *src, size_t size)
// {
// 	char	ft_dst[100];
// 	char	std_dst[100];
// 	size_t	ft_ret;
// 	size_t	std_ret;

// 	tests++;

// 	memset(ft_dst, 'X', sizeof(ft_dst));
// 	memset(std_dst, 'X', sizeof(std_dst));

// 	ft_ret = ft_strlcpy(ft_dst, src, size);
// 	std_ret = strlcpy(std_dst, src, size);

// 	if (ft_ret == std_ret
// 		&& memcmp(ft_dst, std_dst, sizeof(ft_dst)) == 0)
// 	{
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	}
// 	else
// 	{
// 		printf(RED "[%02d] FAIL" RESET "  %s\n", tests, name);
// 		printf("     ft_strlcpy: \"%s\" (ret = %zu)\n",
// 			ft_dst, ft_ret);
// 		printf("     strlcpy:    \"%s\" (ret = %zu)\n",
// 			std_dst, std_ret);
// 		failed++;
// 	}
// }

// int	main(void)
// {
// 	printf("\n===== ft_strlcpy TESTS =====\n\n");

// 	/* Basic */
// 	test_strlcpy("basic", "Hello", 10);
// 	test_strlcpy("exact size", "Hello", 6);
// 	test_strlcpy("truncate", "Hello World", 6);
// 	test_strlcpy("heavy truncate", "Hello World", 3);

// 	/* Empty source */
// 	test_strlcpy("empty source", "", 10);
// 	test_strlcpy("empty source size 1", "", 1);
// 	test_strlcpy("empty source size 0", "", 0);

// 	/* Size */
// 	test_strlcpy("size 0", "Hello", 0);
// 	test_strlcpy("size 1", "Hello", 1);
// 	test_strlcpy("size 2", "Hello", 2);
// 	test_strlcpy("size 5", "Hello", 5);
// 	test_strlcpy("size 6", "Hello", 6);
// 	test_strlcpy("size bigger", "Hello", 100);

// 	/* One character */
// 	test_strlcpy("one char", "A", 10);
// 	test_strlcpy("one char size 1", "A", 1);
// 	test_strlcpy("one char size 0", "A", 0);

// 	/* Spaces / special characters */
// 	test_strlcpy("spaces", "Hello   World", 20);
// 	test_strlcpy("special chars", "!@#$%^&*", 20);
// 	test_strlcpy("special truncate", "!@#$%^&*", 5);

// 	/* Longer strings */
// 	test_strlcpy("long string",
// 		"abcdefghijklmnopqrstuvwxyz", 30);
// 	test_strlcpy("long truncation",
// 		"abcdefghijklmnopqrstuvwxyz", 10);

// 	printf("\n============================\n");
// 	printf("Total: %d | Failed: %d\n", tests, failed);

// 	if (failed == 0)
// 		printf(GREEN "ALL TESTS PASSED ✓\n" RESET);
// 	else
// 		printf(RED "SOME TESTS FAILED ✗\n" RESET);

// 	return (failed != 0);
// }
