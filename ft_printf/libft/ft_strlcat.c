/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:21:18 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:36:59 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (i < dstsize)
	{
		while ((i + j) < (dstsize - 1) && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	while (src[j] != '\0')
		j++;
	return (i + j);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	tests;
// static int	failed;

// static void	test_strlcat(const char *name, const char *dst_init,
// 		const char *src, size_t size)
// {
// 	char	ft_dst[100];
// 	char	std_dst[100];
// 	size_t	ft_ret;
// 	size_t	std_ret;

// 	tests++;

// 	memset(ft_dst, 0, sizeof(ft_dst));
// 	memset(std_dst, 0, sizeof(std_dst));

// 	strcpy(ft_dst, dst_init);
// 	strcpy(std_dst, dst_init);

// 	ft_ret = ft_strlcat(ft_dst, src, size);
// 	std_ret = strlcat(std_dst, src, size);

// 	if (ft_ret == std_ret && strcmp(ft_dst, std_dst) == 0)
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	else
// 	{
// 		printf(RED "[%02d] FAIL" RESET "  %s\n", tests, name);
// 		printf("     ft_strlcat: \"%s\" (ret = %zu)\n",
// 			ft_dst, ft_ret);
// 		printf("     strlcat:    \"%s\" (ret = %zu)\n",
// 			std_dst, std_ret);
// 		failed++;
// 	}
// }

// int	main(void)
// {
// 	printf("\n===== ft_strlcat TESTS =====\n\n");

// 	/* Basic */
// 	test_strlcat("basic", "Hello", " World", 20);
// 	test_strlcat("empty src", "Hello", "", 20);
// 	test_strlcat("empty dst", "", "Hello", 20);

// 	/* Exact fits */
// 	test_strlcat("exact fit", "Hello", "World", 11);
// 	test_strlcat("exact fit + null", "Hello", "World", 12);

// 	/* Truncation */
// 	test_strlcat("truncate 1", "Hello", " World", 8);
// 	test_strlcat("truncate 2", "Hello", " World", 7);
// 	test_strlcat("truncate heavily", "Hello", " World", 3);

// 	/* Size = 0 / 1 */
// 	test_strlcat("size 0", "Hello", "World", 0);
// 	test_strlcat("size 1", "Hello", "World", 1);

// 	/* Size smaller than destination */
// 	test_strlcat("size < dst length", "Hello", "World", 3);
// 	test_strlcat("size == dst length", "Hello", "World", 5);

// 	/* Large size */
// 	test_strlcat("large size", "Hello", " World", 100);

// 	/* One character */
// 	test_strlcat("one char dst", "A", "B", 10);
// 	test_strlcat("one char src", "A", "B", 2);

// 	/* Spaces / special characters */
// 	test_strlcat("spaces", "Hello", "   World", 20);
// 	test_strlcat("special chars", "!@#", "$%^&*", 20);

// 	/* Longer strings */
// 	test_strlcat("long string", "abcdefghij",
// 		"klmnopqrst", 30);
// 	test_strlcat("long truncation", "abcdefghij",
// 		"klmnopqrst", 15);

// 	printf("\n============================\n");
// 	printf("Total: %d | Failed: %d\n", tests, failed);

// 	if (failed == 0)
// 		printf(GREEN "ALL TESTS PASSED ✓\n" RESET);
// 	else
// 		printf(RED "SOME TESTS FAILED ✗\n" RESET);

// 	return (failed != 0);
// }

// // a refaire !