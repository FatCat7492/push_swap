/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:49:10 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/08 11:22:46 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlen for sl car trop long pour ligne 26..
static int	ft_sl(char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (ft_sl((char *)s1) + ft_sl((char *)s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

static int	ft_sl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	tests;
// static int	failed;

// static void	test_strjoin(const char *name, const char *s1,
// 		const char *s2, const char *expected)
// {
// 	char	*result;

// 	tests++;
// 	result = ft_strjoin(s1, s2);

// 	if (result != NULL && expected != NULL
// 		&& strcmp(result, expected) == 0)
// 	{
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	}
// 	else if (result == NULL && expected == NULL)
// 	{
// 		printf(GREEN "[%02d] PASS" RESET "  %s\n", tests, name);
// 	}
// 	else
// 	{
// 		printf(RED "[%02d] FAIL" RESET "  %s\n", tests, name);
// 		printf("     expected: \"%s\"\n",
// 			expected ? expected : "NULL");
// 		printf("     got:      \"%s\"\n",
// 			result ? result : "NULL");
// 		failed++;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	printf("\n===== ft_strjoin TESTS =====\n\n");

// 	/* Basic */
// 	test_strjoin("basic", "Hello", "World", "HelloWorld");
// 	test_strjoin("with spaces", "Hello ", "World", "Hello World");
// 	test_strjoin("two words", "Hello", " World", "Hello World");

// 	/* Empty strings */
// 	test_strjoin("empty first", "", "Hello", "Hello");
// 	test_strjoin("empty second", "Hello", "", "Hello");
// 	test_strjoin("both empty", "", "", "");

// 	/* One character */
// 	test_strjoin("one char each", "a", "b", "ab");
// 	test_strjoin("one char first", "a", "", "a");
// 	test_strjoin("one char second", "", "b", "b");

// 	/* Spaces */
// 	test_strjoin("spaces first", "   ", "Hello", "   Hello");
// 	test_strjoin("spaces second", "Hello", "   ", "Hello   ");
// 	test_strjoin("only spaces", "   ", "   ", "      ");

// 	/* Special characters */
// 	test_strjoin("special chars", "!@#", "$%^", "!@#$%^");
// 	test_strjoin("numbers", "123", "456", "123456");

// 	/* Newline / tab */
// 	test_strjoin("newline", "Hello\n", "World", "Hello\nWorld");
// 	test_strjoin("tab", "Hello\t", "World", "Hello\tWorld");

// 	/* Same strings */
// 	test_strjoin("same strings", "Hello", "Hello", "HelloHello");
// 	test_strjoin("same char", "a", "a", "aa");

// 	/* Longer strings */
// 	test_strjoin("long strings",
// 		"abcdefghijklmnopqrstuvwxyz",
// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
// 		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

// 	/* Strings containing repeated characters */
// 	test_strjoin("repeated chars", "aaaa", "bbbb", "aaaabbbb");
// 	test_strjoin("repeated words", "abcabc", "abcabc",
// 		"abcabcabcabc");

// 	printf("\n============================\n");
// 	printf("Total: %d | Failed: %d\n", tests, failed);

// 	if (failed == 0)
// 		printf(GREEN "ALL TESTS PASSED ✓\n" RESET);
// 	else
// 		printf(RED "SOME TESTS FAILED ✗\n" RESET);

// 	return (failed != 0);
// }
