/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:24:36 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:32:44 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			*d++ = *s++;
			i++;
		}
	}
	else
	{
		while (len-- > i)
			d[len] = s[len];
	}
	return (dst);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	tests;
// static int	failed;

// static void	test_memmove(const char *name, const char *src,
// 		size_t dst_offset, size_t src_offset, size_t len)
// {
// 	char	a[50];
// 	char	b[50];

// 	tests++;

// 	memset(a, 0, sizeof(a));
// 	memset(b, 0, sizeof(b));
// 	strcpy(a, src);
// 	strcpy(b, src);

// 	ft_memmove(a + dst_offset, a + src_offset, len);
// 	memmove(b + dst_offset, b + src_offset, len);

// 	if (memcmp(a, b, sizeof(a)) == 0)
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	else
// 	{
// 		printf(RED "[%02d] FAIL" RESET "  %s\n", tests, name);
// 		printf("     ft_memmove: \"%s\"\n", a);
// 		printf("     memmove:    \"%s\"\n", b);
// 		failed++;
// 	}
// }

// int	main(void)
// {
// 	printf("\n===== ft_memmove TESTS =====\n\n");

// 	/* Basic */
// 	test_memmove("normal copy", "Hello World", 0, 6, 5);
// 	test_memmove("copy to beginning", "Hello World", 0, 2, 5);
// 	test_memmove("copy to middle", "Hello World", 3, 0, 5);

// 	/* No overlap */
// 	test_memmove("no overlap", "abcdefghij", 0, 5, 5);
// 	test_memmove("no overlap reverse", "abcdefghij", 5, 0, 5);

// 	/* Destination overlaps source - destination after source */
// 	test_memmove("overlap right 1", "abcdefghij", 2, 0, 8);
// 	test_memmove("overlap right 2", "abcdefghij", 3, 0, 7);
// 	test_memmove("overlap right 3", "abcdefghij", 5, 0, 5);

// 	/* Destination overlaps source - destination before source */
// 	test_memmove("overlap left 1", "abcdefghij", 0, 2, 8);
// 	test_memmove("overlap left 2", "abcdefghij", 0, 3, 7);
// 	test_memmove("overlap left 3", "abcdefghij", 0, 5, 5);

// 	/* Same address */
// 	test_memmove("same source/destination", "abcdefghij", 3, 3, 5);
// 	test_memmove("same address full", "abcdefghij", 0, 0, 10);

// 	/* Length */
// 	test_memmove("len 0", "abcdefghij", 2, 5, 0);
// 	test_memmove("len 1", "abcdefghij", 2, 5, 1);
// 	test_memmove("len 5", "abcdefghij", 2, 5, 5);

// 	/* Single character */
// 	test_memmove("single char", "a", 0, 0, 1);

// 	/* Binary data including \\0 */
// 	{
// 		char	a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 		char	b[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

// 		tests++;

// 		ft_memmove(a + 2, a, 7);
// 		memmove(b + 2, b, 7);

// 		if (memcmp(a, b, sizeof(a)) == 0)
// 			printf(GREEN "[%02d] PASS" RESET "  binary data\n", tests);
// 		else
// 		{
// 			printf(RED "[%02d] FAIL" RESET "  binary data\n", tests);
// 			failed++;
// 		}
// 	}

// 	printf("\n============================\n");
// 	printf("Total: %d | Failed: %d\n", tests, failed);

// 	if (failed == 0)
// 		printf(GREEN "ALL TESTS PASSED ✓\n" RESET);
// 	else
// 		printf(RED "SOME TESTS FAILED ✗\n" RESET);

// 	return (failed != 0);
// }
