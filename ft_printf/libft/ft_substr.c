/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 10:30:53 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/12 23:07:40 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	sub = malloc (sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	tests = 0;
// static int	failed = 0;

// static void	test(const char *name, const char *s,
// 		unsigned int start, size_t len, const char *expected)
// {
// 	char	*result;

// 	tests++;
// 	result = ft_substr(s, start, len);

// 	if ((result && expected && strcmp(result, expected) == 0)
// 		|| (!result && !expected))
// 	{
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	}
// 	else
// 	{
// 		printf(RED "[%02d] FAIL" RESET "  %s\n", tests, name);
// 		printf("     expected: %s\n", expected ? expected : "NULL");
// 		printf("     got:      %s\n", result ? result : "NULL");
// 		failed++;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	printf("\n===== ft_substr TESTS =====\n\n");

// 	test("basic", "Hello World", 0, 5, "Hello");
// 	test("middle", "Hello World", 6, 5, "World");
// 	test("middle part", "Hello World", 2, 5, "llo W");

// 	test("start 0", "abcdef", 0, 3, "abc");
// 	test("start 0 full", "abcdef", 0, 6, "abcdef");
// 	test("start 0 too long", "abcdef", 0, 100, "abcdef");

// 	test("start 1", "abcdef", 1, 3, "bcd");
// 	test("start 3", "abcdef", 3, 3, "def");
// 	test("last character", "abcdef", 5, 1, "f");

// 	test("len 0", "abcdef", 2, 0, "");
// 	test("len 1", "abcdef", 2, 1, "c");
// 	test("len smaller", "abcdef", 1, 2, "bc");
// 	test("len exactly remaining", "abcdef", 2, 4, "cdef");
// 	test("len bigger than remaining", "abcdef", 2, 100, "cdef");

// 	test("start at length", "abcdef", 6, 5, "");
// 	test("start beyond", "abcdef", 10, 5, "");
// 	test("start far beyond", "abcdef", 999, 999, "");

// 	test("empty string", "", 0, 0, "");
// 	test("empty string len", "", 0, 5, "");
// 	test("empty string start", "", 5, 5, "");

// 	test("one char", "a", 0, 1, "a");
// 	test("one char len 0", "a", 0, 0, "");
// 	test("one char start beyond", "a", 1, 1, "");

// 	test("spaces", "Hello World", 5, 1, " ");
// 	test("multiple spaces", "   abc", 0, 3, "   ");

// 	test("special chars", "!@#$%^&*", 2, 4, "#$%^");
// 	test("newline", "abc\ndef", 3, 4, "\ndef");
// 	test("tab", "abc\tdef", 3, 4, "\tdef");

// 	test("huge len", "Hello", 0, 10000, "Hello");

// 	printf("\n===========================\n");

// 	printf("Total: %d | ", tests);

// 	if (failed == 0)
// 		printf(GREEN "Failed: %d | ALL PASSED ✓\n" RESET, failed);
// 	else
// 		printf(RED "Failed: %d\n" RESET, failed);

// 	return (failed != 0);
// }
